#include <benchmark/benchmark.h>

extern "C" {
#include "impl.h"
}

static void BM_F1600x2(benchmark::State& state) {
    for (auto _ : state) {
        uint64_t a[50] = {0};
        f1600x2(&a[0], &RC[0]);
        benchmark::DoNotOptimize(a);
    }
}

static void BM_F1600(benchmark::State& state) {
    for (auto _ : state) {
        uint64_t a[25] = {0};
        f1600(a);
        benchmark::DoNotOptimize(a);
    }
}

BENCHMARK(BM_F1600x2);
BENCHMARK(BM_F1600);
BENCHMARK_MAIN();
