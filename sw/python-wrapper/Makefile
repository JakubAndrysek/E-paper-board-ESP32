python-wrapper:
	python main.py

docker-build:
	docker build --tag python-docker .

docker-run:
	docker run -it -p 5000:5000 python-docker
docker-run-rm:
	docker run --rm -it -p 5000:5000 python-docker

python-requirements:
	pip install -r requirements.txt