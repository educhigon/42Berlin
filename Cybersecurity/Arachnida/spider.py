import argparse
import requests
from pathlib import Path
from urllib.parse import urljoin, urlparse
from bs4 import BeautifulSoup

def download(url, folder):
	if url.lower().endswith((".jpg", ".jpeg", ".png", ".gif", ".bmp")):
		p = urlparse(url)
		name = (p.netloc + p.path).replace("/", "_")   # 'cdn.site.com_header_logo.png'
		save_path = Path(folder/name)
		try:
			response = requests.get(url, timeout=30)
			response.raise_for_status()
		except requests.RequestException:
			return                            # skip this URL, keep crawling
		save_path.write_bytes(response.content)
		print(f"  [save]  {name}")


def fetch(URL, domain, depth_lim, folder, url_visited):
	host = urlparse(URL).netloc
	if host != domain:
		return
	if depth_lim < 0:
		return
	if URL in url_visited:
		return
	url_visited.add(URL)
	print(f"[crawl] depth={depth_lim}  {URL}")
	try:
		response = requests.get(URL, timeout=30)
		response.raise_for_status()
	except requests.RequestException:
		return                            # skip this URL, keep crawling
	soup = BeautifulSoup(response.text, "html.parser")
	for tag in soup.find_all("img"):
		src = tag.get("src")   # check if it's absolute or not
		if src is not None:
			img_path = urljoin(URL, src)
			download(img_path, folder)
	for tag in soup.find_all("a"):
		href = tag.get("href") # check if it's absolute or not
		if href is not None:
			next_path = urljoin(URL, href)  # relative → absolute
			if href.lower().endswith((".jpg", ".jpeg", ".png", ".gif", ".bmp")):
				download(next_path, folder)
			else:
				fetch(next_path, domain, depth_lim-1, folder, url_visited)

def main ():
	depth_lim = 0
	url_visited = set()

	parser = argparse.ArgumentParser()
	parser.add_argument("URL")                 # required positional argument
	parser.add_argument("-r", action="store_true")
	parser.add_argument("-l", type=int)
	parser.add_argument("-p", type=str)

	args = parser.parse_args()

	if not args.URL.startswith(("https://", "http://")):
		parser.error("URL needs to start with \"https://\" ")

	if args.r:
		depth_lim = 5
		if args.l is not None:
			if 0 < args.l <= 100:
				depth_lim = args.l
			else:
				parser.error("-l must be a positive number less than 100")

	folder = Path(args.p) if args.p else Path("./data/")
	folder.mkdir(parents=True, exist_ok=True)

	host = urlparse(args.URL).netloc
	fetch(args.URL, host, depth_lim, folder, url_visited)


if __name__ == "__main__":
    main()