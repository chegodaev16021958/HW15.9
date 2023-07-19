#pragma once

#include <iostream>

typedef unsigned int uint;

constexpr auto one_block_size_bytes = 64;
constexpr auto one_block_size_uints = 16;
constexpr auto block_expend_size_uints = 80;

constexpr auto SHA1HASHLENGTHBYTES = 20;
constexpr auto SHA1HASHLENGTHUINTS = 5;

typedef uint* Block;
typedef uint ExpendBlock[block_expend_size_uints];

const uint H[5] = {
	0x67452301,
	0xEFCDAB89,
	0x98BADCFE,
	0x10325476,
	0xC3D2E1F0
};

uint cycle_shift_left(uint val, int bit_count);
uint bring_to_human_view(uint val);
uint* sha1(const char* message, uint msize_bytes);

