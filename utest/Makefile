BOOST_INCLUDES ?= -I /usr/include
BOOST_LIBDIR   ?=  -L /usr/lib/x86-64-linux-gnu

INCDIRS := -I. -I../Primitives -I../DataStructures -I../Utils -I../Voronoi $(BOOST_INCLUDES)

all:
	g++ -DBOOST_TEST_DYN_LINK $(INCDIRS) $(BOOST_LIBDIR) -lboost_unit_test_framework ../Primitives/Circle.o ../Utils/SiteVec.o ../Voronoi/Voronoi.o -o uTest test.cxx
	./uTest

.PHONY : clean
clean:
	-rm uTest
