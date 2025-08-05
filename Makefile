
.PHONY: build
build:
	rm -rf ./bin
	mkdir -p ./bin
	cc -W -Wall -o bin/main \
		handbook/main.c \
		handbook/vars.c \
		handbook/flow_control.c \
		handbook/types_base.c \
		handbook/types_array.c \
		handbook/pointers.c

.PHONY: run
run: build
	./bin/main

.PHONY: push
push:
	git add .
	git commit -m "update"
	git push


################ toy projects
.PHONY: build-life
build-life:
	mkdir -p ./bin
	rm -f ./bin/life
	cc -W -Wall -o bin/life \
		projects/conway_game_life/main.c

.PHONY: run-life
run-life: build-life
	./bin/life