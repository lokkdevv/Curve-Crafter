CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

main = ./src/main.c
pong = ./src/games/pong.c

win_input = ./src/input/win_input.c
win_renderer = ./src/renderer/win_renderer.c

unix_input = ./src/input/linux_input.c
unix_renderer = ./src/renderer/linux_renderer.c

math = ./src/core/math/math.c

out = ./bin/main

.PHONY: run win linux win_pong unix_pong clean

win: ${main} ${math} ${win_input} ${win_renderer}
	${CC}  ${CFLAGS}  ${main} ${math} ${win_input} ${win_renderer}  -o ${out}

linux: ${main} ${math} ${unix_input} ${unix_renderer}
	# ${CC}  ${CFLAGS}  ${main} ${math} ${unix_input} ${unix_renderer}  -o ${out}
	echo "Error: Linux not supported yet."
	echo "Note: It would be much appreciated if You contribute by adding support to linux."

win_pong: ${pong} ${win_input} ${win_renderer}
	${CC}  ${CFLAGS}  ${pong} ${win_input} ${win_renderer}  -o ${out}

linux_pong: ${pong} ${unix_input} ${unix_renderer}
	${CC}  ${CFLAGS}  ${pong} ${unix_input} ${unix_renderer}  -o ${out}

run:
	${out}