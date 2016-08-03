BOOST_INCLUDES ?= -I /usr/include
BOOST_LIBDIR   ?=  -L /usr/lib/x86-64-linux-gnu

INCDIRS := -I. -I../Primitives -I../DataStructures $(BOOST_INCLUDES)

all:
	g++ -DBOOST_TEST_DYN_LINK $(INCDIRS) $(BOOST_LIBDIR) -lboost_unit_test_framework -o test test.cxx
	./test

.PHONY : clean
clean:
	-rm test >& /dev/null
