CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

main = ./src/main.c

win_input = ./src/input/win_input.c
win_renderer = ./src/renderer/win_renderer.c

unix_input = ./src/input/unix_input.c
unix_renderer = ./src/renderer/unix_renderer.c

out = ./bin/main

.PHONY: run win unix clean

win: ${main} ${win_input} ${win_renderer}
	${CC}  ${CFLAGS}  ${main} ${win_input} ${win_renderer}  -o ${out}

unix: ${main} ${unix_input} ${unix_renderer}
	# ${CC}  ${CFLAGS}  ${main} ${unix_input} ${unix_renderer}  -o ${out}
	echo "Error: Unix not supported yet."
	echo "Note: It would be much appreciated if You contribute by adding support to unix systems."

run:
	${out}