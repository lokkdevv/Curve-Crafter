default:
	gcc ./src/main.c ./src/input.c ./src/win_cli.c -o ./bin/main

run:
	./bin/main