BOOST_HOME=/project/dsm/cicd/icf_wg_server/fw_ic/boost/exports.v1-43_0-0-1_engr-$(VCO)/mgc_home
BOOST_INCDIRS := $(BOOST_HOME)/shared/pkgs/boost_inhouse.$(VCO)/boost_ext/include/boost
BOOST_INCLUDES := -isystem$(BOOST_INCDIRS)
BOOST_LIBDIR =  -L$(BOOST_HOME)/pkgs/boost.$(VCO)/lib

INCDIRS := -I. -I../DataStructures $(BOOST_INCLUDES)

all:
	g++ -DBOOST_TEST_DYN_LINK $(INCDIRS) $(BOOST_LIBDIR) -lboost_unit_test_framework-mt -o test test.cxx
	test

clean:
	@rm test
