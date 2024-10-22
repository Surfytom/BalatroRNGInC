CC=gcc
SOURCE=src/filters.c src/instance.c src/packs.c src/randomutils.c src/searcher.c src/temp.c src/VectorLib/vector.c src/HashMapLib/hashmap.c
INCLUDE=

all:
	$(CC) $(SOURCE) main.c -o main