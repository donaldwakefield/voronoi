all: Primitives DataStructures
	make -C Primitives
	make -C DataStructures

clean:
	make clean -C Primitives
	make clean -C DataStructures
