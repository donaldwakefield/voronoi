all: Primitives DataStructures
	make -C Primitives
	make -C DataStructures
	make -C utest

clean:
	make clean -C Primitives
	make clean -C DataStructures
	make clean -C utest
