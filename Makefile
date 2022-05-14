
doc-preinstall-linux:
	sudo apt install doxygen
	pip install -r requirements.txt

doc-preinstall-mac:
	brew install python@3.10 doxygen pango libffi
	pip install -r requirements.txt

doc:
	python3 -m mkdocs serve

doc-static:
	python3 -m mkdocs serve --no-livereload

python-wrapper:
	make -C sw/python-wrapper/ python-wrapper 

server-json:
	make -C sw/e-paper-board/json-server/ serve-departures-rotex

world-count:
	find ./docs -iname "*.md" | xargs pandoc --strip-comments -t plain | wc -w