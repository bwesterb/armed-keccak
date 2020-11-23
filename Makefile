CFLAGS := $(CFLAGS) -O3 -mcpu=apple-a13
#-mcpu=apple-a13 -O2


.PHONY: default

default: test

impl.o: impl.c
	$(CC) -c $< -o $@ $(CFLAGS)
feat.o: feat.s
	$(CC) -c $< -o $@ $(CFLAGS)
test: impl.o feat.o test.c
	$(CC) test.c impl.o feat.o -o $@ $(LDFLAGS)
benchmark: benchmark.cxx impl.o feat.o
	$(CXX) $< impl.o feat.o -o $@ `pkg-config benchmark --cflags --libs` -std=c++11 $(CFLAGS)
