SHEL=/bin/bash
MD := mkdir
RM := rm

UID := $(shell id -u)
GID := $(shell id -g)

COMPOSE=docker compose
BUILDFILE=compose.yml

REGISTRY := $(shell grep REGISTRY .env | cut -d '=' -f2)
CONTAINER_NAME := $(shell grep CONTAINER_NAME .env | cut -d '=' -f2)
VERSION := $(shell grep VERSION .env | cut -d '=' -f2)
ORG := $(shell grep ORG .env | cut -d '=' -f2)



build:
	$(COMPOSE) -f $(BUILDFILE) build
#	docker build -f Dockerfile -t $(REGISTRY)/$(ORG)/$(CONTAINER_NAME):$(VERSION) .
	
run:
	$(COMPOSE) -f $(BUILDFILE) up --detach
debug:
	$(COMPOSE) -f $(BUILDFILE) up
stop:
	$(COMPOSE) -f $(BUILDFILE) stop
down:
	$(COMPOSE) -f $(BUILDFILE) down
#	docker run -i -d -p 80:80 --name $(CONTAINER_NAME) $(REGISTRY)/$(ORG)/$(CONTAINER_NAME):$(VERSION)
exec:
	docker exec -it $(CONTAINER_NAME) /bin/bash
rmi:
	docker rmi -f $(shell docker images $(REGISTRY)/$(ORG)/$(CONTAINER_NAME) -a -q)

#push
#    later comes
#stop:
#	docker kill $(CONTAINER_NAME)
