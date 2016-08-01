BOOST_INCLUDES := -I /usr/include/boost
BOOST_LIBDIR =  -L /usr/lib/x86-64-linux-gnu

INCDIRS := -I. -I../DataStructures $(BOOST_INCLUDES)

all:
	g++ -DBOOST_TEST_DYN_LINK $(INCDIRS) $(BOOST_LIBDIR) -lboost_unit_test_framework -o test test.cxx
	./test

clean:
	@rm test
