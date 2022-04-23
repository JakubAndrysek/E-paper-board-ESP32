
doc-preinstall:
	sudo apt install doxygen
	pip install mkdocs-material
	pip install git+https://github.com/JakubAndrysek/mkdoxy.git
	pip install git+https://github.com/it-novum/mkdocs-featherlight.git
	pip install mkdocs-awesome-pages-plugin

doc:
	python3.9 -m mkdocs serve

doc-static:
	python3.9 -m mkdocs serve --no-livereload

python-wrapper:
	make -C sw/python-wrapper/ python-wrapper 

# server-json:
# 	make -C sw/e-paper-board/json-server/ serve-departures-rotex