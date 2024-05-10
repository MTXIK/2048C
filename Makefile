all: main2048

main2048: main2048.o libUI.a libleaderboard.a libfirst.a
	gcc -o main2048 main2048.o -L./UI -lUI -L./leaderboard -lleaderboard -L./first -lfirst

main2048.o: main2048.c
	gcc -c main2048.c

libUI.a:
	$(MAKE) -C UI

libLeaderboard.a:
	$(MAKE) -C leaderboard

libFirst.a:
	$(MAKE) -C first

clean:
	rm -f main2048 main2048.o
	$(MAKE) -C UI clean
	$(MAKE) -C leaderboard clean
	$(MAKE) -C first clean

.PHONY: all clean libUI.a libleaderboard.a libfirst.a