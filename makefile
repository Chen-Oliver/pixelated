compile:
	gcc makepic.c
create:compile
	./a.out
show:create
	display image.ppm
