all : main.o id3_frame.o id3_tagheader.o util.o repertoire.o
	gcc main.o id3_frame.o id3_tagheader.o util.o repertoire.o -o id3

util.o : util.c util.h
	gcc -c util.c

main.o : main.c
	gcc -c main.c

id3_frame.o : id3_frame.c id3_frame.h
	gcc -c id3_frame.c

id3_tagheader.o : id3_tagheader.c id3_tagheader.h
	gcc -c id3_tagheader.c	

repertoire.o : repertoire.c repertoire.h
	gcc -c repertoire.c

clean:
	rm *.o id3

run :
	./id3 track1.mp3
