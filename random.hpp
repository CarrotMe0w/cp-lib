#pragma once

#include "types.hpp"

static u64 rnd_seed = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
std::mt19937 rnd32(rnd_seed);
std::mt19937_64 rnd64(rnd_seed);

static u32 FIXED_RND32 = rnd32();
static u64 FIXED_RND64 = rnd64();

u64 rnd(const u64 l, const u64 r) { return std::uniform_int_distribution<u64>(l, r)(rnd64); }