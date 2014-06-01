all:libgtest.a

libgtest.a:gtest-all.o
	ar -rv $@ $^ 

GTEST-DIR=.
gtest-all.o:src/gtest-all.cc
	g++ -DGTEST_USE_OWN_TR1_TUPLE=1 -I${GTEST-DIR}/include -I${GTEST-DIR} -c $^ -o $@ 

#g++ -DGTEST_USE_OWN_TR1_TUPLE=1 -I/Users/gaoxinbo/Desktop/github/logger/gtest/include src/gtest-all.cc -I/Users/gaoxinbo/Desktop/github/logger/gtest/ -c

.PHONY:clean

clean:
	rm -rf *.o
	rm -rf *.a
