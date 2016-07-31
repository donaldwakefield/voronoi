all:
	g++ -v -DBOOST_TEST_DYN_LINK -I. -I../DataStructures -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.8.sdk/usr/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/c++/v1 -I/usr/local/Cellar/boost/1.60.0_2/include/boost -L/usr/local/Cellar/boost/1.60.0_2/lib -lboost_unit_test_framework-mt -o test test.cxx

clean:
	@rm test
