.DEFAULT_GOAL = help
.PHONY: help run build test clean push-all

help: ## (@main) Show this help
	@echo "Usage: make [target]"
	@echo ""
	@echo "Available targets:"
	@echo ""
	@awk -F ':|##' '/^[^\t].+?:.*?##/ { \
		tag = match($$NF, /\(@[^)]+\)/); \
		category = substr($$NF, RSTART+2, RLENGTH-3); \
		description = substr($$NF, RSTART+RLENGTH+1); \
		targets[category] = targets[category] sprintf("  \033[36m%-30s\033[0m %s\n", $$1, description); \
	} \
	END { \
		for (cat in targets) { \
			printf "%s:\n%s\n", cat, targets[cat]; \
		} \
	}' $(MAKEFILE_LIST)


## Main
run: ## (@main) Run the binary
	bazelisk run //src:main

build: ## (@main) Build the binary
	bazelisk build //src/...

test: ## (@main) Run unit tests
	bazelisk test //src/...

clean: ## (@main) Clean local build artifacts
	rm -f compile_commands.json
	bazelisk clean

push-all: ## (@main) Push main to multiple places
	git push origin
	git push codeberg
	git push gitlab
	git push bitbucket

## Targets
compile_commands.json:
	bazel run @hedron_compile_commands//:refresh_all
