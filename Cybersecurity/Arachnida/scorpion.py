import argparse
import json
from PIL import Image, UnidentifiedImageError
from PIL.ExifTags import TAGS, GPSTAGS
import os
from datetime import datetime

def main ():
	parser = argparse.ArgumentParser()
	parser.add_argument("file", nargs="+")
	args = parser.parse_args()

	for f in args.file:
		if not f.lower().endswith((".jpg", ".jpeg", ".png", ".gif", ".bmp")):
			print(f'FILE must end with ".jpg", ".jpeg", ".png", ".gif", ".bmp" : \n\t {f} --> not a supported image, skipping \n')
			continue

		date_from_file = ""
		try:

			with Image.open(f) as img:

				exif = img.getexif()           # dict {int_tag: value}, or None if no EXIF
				exif_text = {}
				if exif:
					# 1) top-level tags (Make, DateTime, ...)
					for tag_id, value in exif.items():
						exif_text[TAGS.get(tag_id, tag_id)] = value
					# 2) Exif sub-IFD — this is where DateTimeOriginal/Digitized live
					for tag_id, value in exif.get_ifd(0x8769).items():
						exif_text[TAGS.get(tag_id, tag_id)] = value
					# 3) GPS sub-IFD — follow the pointer with get_ifd, NOT get(34853)
					gps_info = exif.get_ifd(0x8825)
					if gps_info:
						gps = {GPSTAGS.get(k, k): v for k, v in gps_info.items()}
						exif_text["lat"] = round(float(gps["GPSLatitude"][0] + gps["GPSLatitude"][1]/60 + gps["GPSLatitude"][2]/3600), 6)
						exif_text["lon"] = round(float(gps["GPSLongitude"][0] + gps["GPSLongitude"][1]/60 + gps["GPSLongitude"][2]/3600), 6)
						exif_text["lat"] *= (-1 if gps["GPSLatitudeRef"] == 'S' else 1) 
						exif_text["lon"] *= (-1 if gps["GPSLongitudeRef"] == 'W' else 1) 

					date_from_file = (
						exif_text.get("DateTimeOriginal")
						or exif_text.get("DateTimeDigitized")
						or exif_text.get("DateTime")
					)

				st = os.stat(f)
				sys_date = datetime.fromtimestamp(st.st_mtime)   # human-readable timestamp
				print(f"\n### {f}")
				print(f"\t {sys_date} // {date_from_file}")
				print(json.dumps(exif_text, indent=2, default=str))

		except FileNotFoundError:
			print(f"{f}: file not found"); continue
		except UnidentifiedImageError:
			print(f"{f}: not a valid image"); continue


if __name__ == "__main__":
    main()