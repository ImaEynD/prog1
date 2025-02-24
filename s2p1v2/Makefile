all:
	gcc struct.c main.c -o prstr
	valgrind --leak-check=full --show-leak-kinds=all ./prstr

timetry:
	time ./prstr