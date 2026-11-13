#!/usr/bin/env python3
"""
make_test_images.py — build a scorpion test set from one source image.

From a single image (ideally a JPEG carrying EXIF/GPS), generate PNG, GIF, BMP,
and TIFF copies. EXIF metadata is preserved in the formats that can hold it
(PNG, TIFF) and necessarily dropped in the ones that can't (GIF, BMP) — giving
you, from one picture, both the "rich metadata" path and the graceful
"no EXIF" path to test scorpion against. Fully offline.

Usage:
    python make_test_images.py SOURCE [-o OUTDIR]

Example:
    python make_test_images.py berlin.jpg -o testset/
"""
import argparse
import os
from PIL import Image, UnidentifiedImageError
from PIL.ExifTags import GPSTAGS


def gps_report(path):
    """Short description of GPS presence in a file, for the summary line."""
    try:
        ex = Image.open(path).getexif()
        gps = ex.get_ifd(0x8825)              # GPS sub-IFD, {} if absent
        if gps:
            g = {GPSTAGS.get(k, k): v for k, v in gps.items()}
            lat = tuple(float(x) for x in g.get("GPSLatitude", ()))
            return f"GPS present {lat} {g.get('GPSLatitudeRef', '')}"
        return f"no EXIF/GPS ({len(ex)} top-level tags)"
    except Exception as e:
        return f"unreadable ({type(e).__name__})"


# (extension, does the format support an EXIF container?)
TARGETS = [("png", True), ("tiff", True), ("gif", False), ("bmp", False)]


def main():
    parser = argparse.ArgumentParser(description="Generate format variants from one image.")
    parser.add_argument("source", help="source image (ideally a JPEG with EXIF/GPS)")
    parser.add_argument("-o", "--outdir", default=".", help="output directory (default: current)")
    args = parser.parse_args()

    try:
        src = Image.open(args.source)
    except (FileNotFoundError, UnidentifiedImageError) as e:
        parser.error(f"cannot open {args.source}: {e}")

    os.makedirs(args.outdir, exist_ok=True)
    exif = src.info.get("exif")               # raw EXIF bytes, or None if the source has none
    base = os.path.splitext(os.path.basename(args.source))[0]

    print(f"source: {args.source}  ->  {gps_report(args.source)}\n")
    if not exif:
        print("  (note: source has no EXIF — PNG/TIFF copies will also be empty)\n")

    for ext, supports_exif in TARGETS:
        out = os.path.join(args.outdir, f"{base}.{ext}")
        img = src.convert("RGB")              # normalize mode so every format saves cleanly
        try:
            if supports_exif and exif:
                img.save(out, exif=exif)
            else:
                img.save(out)
        except Exception as e:
            print(f"  {ext.upper():4} -> FAILED ({type(e).__name__}: {e})")
            continue
        print(f"  {ext.upper():4} -> {out}   [{gps_report(out)}]")


if __name__ == "__main__":
    main()