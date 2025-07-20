
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