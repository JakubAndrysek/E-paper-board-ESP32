python-wrapper:
	python3 main.py

docker-build:
	docker build --tag python-docker .

docker-build-x64:
	docker buildx build --tag python-docker -o type=image --platform=linux/amd64 .

docker-run:
	docker run -it -p 5000:5000 python-docker
docker-run-rm:
	docker run --rm -it -p 5000:5000 python-docker

python-requirements:
	pip install -r requirements.txt