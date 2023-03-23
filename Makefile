# Docs
docs-preinstall-linux:
	sudo apt install doxygen
	pip install -r requirements.txt

docs-preinstall-mac:
	brew install python3 doxygen pango libffi
	pip install -r requirements.txt

docs-build:
	@echo "Building docs..."
	mkdocs build

docs-serve:
	@echo "Serving docs..."
	mkdocs serve

docs-deploy:
	@echo "Deploying docs..."
	mkdocs gh-deploy --force



python-wrapper:
	make -C sw/python-wrapper/ python-wrapper



server-json:
	make -C sw/e-paper-board/json-server/ serve-departures-rotex



world-count:
	find ./docs -iname "*.md" | xargs pandoc --strip-comments -t plain | wc -w