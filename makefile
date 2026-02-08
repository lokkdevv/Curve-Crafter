CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g

main = ./src/main.c
pong = ./src/games/pong.c

win_input = ./src/input/win_input.c
win_renderer = ./src/renderer/win_renderer.c

unix_input = ./src/input/linux_input.c
unix_renderer = ./src/renderer/linux_renderer.c

math = ./src/core/math/math.c

pong_out = ./bin/Pong
out = ./bin/CurveCrafter

.PHONY: run win linux win_pong linux_pong

win: ${main} ${math} ${win_input} ${win_renderer}
	${CC}  ${CFLAGS}  ${main} ${math} ${win_input} ${win_renderer}  -o ${out}

linux: ${main} ${math} ${unix_input} ${unix_renderer}
	${CC}  ${CFLAGS}  ${main} ${math} ${unix_input} ${unix_renderer}  -o ${out}

win_pong: ${pong} ${win_input} ${win_renderer}
	${CC}  ${CFLAGS}  ${pong} ${win_input} ${win_renderer}  -o ${pong_out}

linux_pong: ${pong} ${unix_input} ${unix_renderer}
	${CC}  ${CFLAGS}  ${pong} ${unix_input} ${unix_renderer}  -o ${pong_out}

run:
	${pong_out}