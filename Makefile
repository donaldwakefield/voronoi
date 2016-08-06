all: Primitives DataStructures
	make -C Primitives
	make -C DataStructures
	make -C Utils
	make -C utest

clean:
	make clean -C Primitives
	make clean -C DataStructures
	make clean -C Utils
	make clean -C utest
