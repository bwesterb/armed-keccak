#pragma once

#include <stdint.h>

void f1600(uint64_t a[25]);

extern uint64_t RC[24];

extern void f1600x2(uint64_t* a, uint64_t* rc);
extern void f1600x2b(uint64_t* a, uint64_t* rc);
