all: Primitives DataStructures
	make -C Primitives
	make -C DataStructures
	make -C Utils
	make -C Voronoi
	make -C utest

clean:
	make clean -C Primitives
	make clean -C DataStructures
	make clean -C Utils
	make clean -C Voronoi
	make clean -C utest
