
.PHONY: build
build:
	rm -rf ./bin
	mkdir -p ./bin
	cc -W -Wall -o bin/main \
		main.c \
		vars.c \
		types_base.c \
		types_array.c \
		flow_control.c

.PHONY: run
run: build
	./bin/main


.PHONY: build-life
build-life:
	mkdir -p ./bin
	rm -f ./bin/life
	cc -W -Wall -o bin/life \
		projects/conway_game_life/main.c

.PHONY: run-life
run-life: build-life
	./bin/life