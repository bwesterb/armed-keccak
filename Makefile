CFLAGS := $(CFLAGS) -O3 -march=armv8.4-a+sha3

.PHONY: default clean

default: test
clean:
	rm -f impl.o feat.o test benchmark

impl.o: impl.c
	$(CC) -c $< -o $@ $(CFLAGS)
feat.o: feat.S
	$(CC) -c $< -o $@ $(CFLAGS)
test: impl.o feat.o test.c
	$(CC) test.c impl.o feat.o -o $@ $(LDFLAGS)

# Prerequisites: `brew install google-benchmark` or `apt-get install libbenchmark-dev`
benchmark: benchmark.cxx impl.o feat.o
	$(CXX) $< impl.o feat.o -o $@ `pkg-config benchmark --cflags --libs` -std=c++11 $(CFLAGS)
