# makefile
.PHONY: help

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'

test-setup: ## Ensure test server & package dependencies
	cd test && sampctl server ensure
	sampctl package ensure

test-native: ## Run test package in local environment
	sampctl package build
	cd test && sampctl server run

test-container: ## Run test package in container
	sampctl package build
	cd test && sampctl server run --container

build-container: ## Build plugin in container
	rm -rf build
	docker build -t mrucznik/mruvapi-build .
	docker run -v $(shell pwd)/test/plugins:/root/test/plugins mrucznik/mruvapi-build

build-inside: ## This make target is only run inside the container
	cd build && cmake .. && make
