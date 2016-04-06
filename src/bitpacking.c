
/**
* This is conventional bit packing using portable C
*/


/***
The strategy we pursue is simple and inspired by https://github.com/powturbo/TurboPFor
We take as inputs 64-bit words and we always unpack them fully.
*/

#include "bitpacking.h"
/**
* this code mimicks the way TurboPFor packs short arrays of integers.
* We pack and unpack always at least a full 64-bit word, plus whatever
* is necessary to get to an even number of bytes.
*/
typedef void (*packblockfnc)(const uint32_t ** pin, uint8_t ** pw);
typedef void (*unpackblockfnc)(const uint8_t ** pw, uint32_t ** pout);

/* we are going to pack 64 1-bit values, touching 1 64-bit words, using 8 bytes */
static void packblock1(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 1;
  w0 |= (uint64_t)  in[2] << 2;
  w0 |= (uint64_t)  in[3] << 3;
  w0 |= (uint64_t)  in[4] << 4;
  w0 |= (uint64_t)  in[5] << 5;
  w0 |= (uint64_t)  in[6] << 6;
  w0 |= (uint64_t)  in[7] << 7;
  w0 |= (uint64_t)  in[8] << 8;
  w0 |= (uint64_t)  in[9] << 9;
  w0 |= (uint64_t)  in[10] << 10;
  w0 |= (uint64_t)  in[11] << 11;
  w0 |= (uint64_t)  in[12] << 12;
  w0 |= (uint64_t)  in[13] << 13;
  w0 |= (uint64_t)  in[14] << 14;
  w0 |= (uint64_t)  in[15] << 15;
  w0 |= (uint64_t)  in[16] << 16;
  w0 |= (uint64_t)  in[17] << 17;
  w0 |= (uint64_t)  in[18] << 18;
  w0 |= (uint64_t)  in[19] << 19;
  w0 |= (uint64_t)  in[20] << 20;
  w0 |= (uint64_t)  in[21] << 21;
  w0 |= (uint64_t)  in[22] << 22;
  w0 |= (uint64_t)  in[23] << 23;
  w0 |= (uint64_t)  in[24] << 24;
  w0 |= (uint64_t)  in[25] << 25;
  w0 |= (uint64_t)  in[26] << 26;
  w0 |= (uint64_t)  in[27] << 27;
  w0 |= (uint64_t)  in[28] << 28;
  w0 |= (uint64_t)  in[29] << 29;
  w0 |= (uint64_t)  in[30] << 30;
  w0 |= (uint64_t)  in[31] << 31;
  w0 |= (uint64_t)  in[32] << 32;
  w0 |= (uint64_t)  in[33] << 33;
  w0 |= (uint64_t)  in[34] << 34;
  w0 |= (uint64_t)  in[35] << 35;
  w0 |= (uint64_t)  in[36] << 36;
  w0 |= (uint64_t)  in[37] << 37;
  w0 |= (uint64_t)  in[38] << 38;
  w0 |= (uint64_t)  in[39] << 39;
  w0 |= (uint64_t)  in[40] << 40;
  w0 |= (uint64_t)  in[41] << 41;
  w0 |= (uint64_t)  in[42] << 42;
  w0 |= (uint64_t)  in[43] << 43;
  w0 |= (uint64_t)  in[44] << 44;
  w0 |= (uint64_t)  in[45] << 45;
  w0 |= (uint64_t)  in[46] << 46;
  w0 |= (uint64_t)  in[47] << 47;
  w0 |= (uint64_t)  in[48] << 48;
  w0 |= (uint64_t)  in[49] << 49;
  w0 |= (uint64_t)  in[50] << 50;
  w0 |= (uint64_t)  in[51] << 51;
  w0 |= (uint64_t)  in[52] << 52;
  w0 |= (uint64_t)  in[53] << 53;
  w0 |= (uint64_t)  in[54] << 54;
  w0 |= (uint64_t)  in[55] << 55;
  w0 |= (uint64_t)  in[56] << 56;
  w0 |= (uint64_t)  in[57] << 57;
  w0 |= (uint64_t)  in[58] << 58;
  w0 |= (uint64_t)  in[59] << 59;
  w0 |= (uint64_t)  in[60] << 60;
  w0 |= (uint64_t)  in[61] << 61;
  w0 |= (uint64_t)  in[62] << 62;
  w0 |= (uint64_t)  in[63] << 63;
  pw64[0] = w0;
  *pin += 64; /* we consumed 64 32-bit integers */
  *pw += 8; /* we used up 8 output bytes */
}


/* we are going to pack 32 2-bit values, touching 1 64-bit words, using 8 bytes */
static void packblock2(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 2;
  w0 |= (uint64_t)  in[2] << 4;
  w0 |= (uint64_t)  in[3] << 6;
  w0 |= (uint64_t)  in[4] << 8;
  w0 |= (uint64_t)  in[5] << 10;
  w0 |= (uint64_t)  in[6] << 12;
  w0 |= (uint64_t)  in[7] << 14;
  w0 |= (uint64_t)  in[8] << 16;
  w0 |= (uint64_t)  in[9] << 18;
  w0 |= (uint64_t)  in[10] << 20;
  w0 |= (uint64_t)  in[11] << 22;
  w0 |= (uint64_t)  in[12] << 24;
  w0 |= (uint64_t)  in[13] << 26;
  w0 |= (uint64_t)  in[14] << 28;
  w0 |= (uint64_t)  in[15] << 30;
  w0 |= (uint64_t)  in[16] << 32;
  w0 |= (uint64_t)  in[17] << 34;
  w0 |= (uint64_t)  in[18] << 36;
  w0 |= (uint64_t)  in[19] << 38;
  w0 |= (uint64_t)  in[20] << 40;
  w0 |= (uint64_t)  in[21] << 42;
  w0 |= (uint64_t)  in[22] << 44;
  w0 |= (uint64_t)  in[23] << 46;
  w0 |= (uint64_t)  in[24] << 48;
  w0 |= (uint64_t)  in[25] << 50;
  w0 |= (uint64_t)  in[26] << 52;
  w0 |= (uint64_t)  in[27] << 54;
  w0 |= (uint64_t)  in[28] << 56;
  w0 |= (uint64_t)  in[29] << 58;
  w0 |= (uint64_t)  in[30] << 60;
  w0 |= (uint64_t)  in[31] << 62;
  pw64[0] = w0;
  *pin += 32; /* we consumed 32 32-bit integers */
  *pw += 8; /* we used up 8 output bytes */
}


/* we are going to pack 24 3-bit values, touching 2 64-bit words, using 9 bytes */
static void packblock3(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 3;
  w0 |= (uint64_t)  in[2] << 6;
  w0 |= (uint64_t)  in[3] << 9;
  w0 |= (uint64_t)  in[4] << 12;
  w0 |= (uint64_t)  in[5] << 15;
  w0 |= (uint64_t)  in[6] << 18;
  w0 |= (uint64_t)  in[7] << 21;
  w0 |= (uint64_t)  in[8] << 24;
  w0 |= (uint64_t)  in[9] << 27;
  w0 |= (uint64_t)  in[10] << 30;
  w0 |= (uint64_t)  in[11] << 33;
  w0 |= (uint64_t)  in[12] << 36;
  w0 |= (uint64_t)  in[13] << 39;
  w0 |= (uint64_t)  in[14] << 42;
  w0 |= (uint64_t)  in[15] << 45;
  w0 |= (uint64_t)  in[16] << 48;
  w0 |= (uint64_t)  in[17] << 51;
  w0 |= (uint64_t)  in[18] << 54;
  w0 |= (uint64_t)  in[19] << 57;
  w0 |= (uint64_t)  in[20] << 60;
  w0 |= (uint64_t) in[21] << 63;
  w1 = (uint64_t) in[21] >> 2;
  w1 |= (uint64_t)  in[22] << 2;
  w1 |= (uint64_t)  in[23] << 5;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 24; /* we consumed 24 32-bit integers */
  *pw += 9; /* we used up 9 output bytes */
}


/* we are going to pack 16 4-bit values, touching 1 64-bit words, using 8 bytes */
static void packblock4(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 4;
  w0 |= (uint64_t)  in[2] << 8;
  w0 |= (uint64_t)  in[3] << 12;
  w0 |= (uint64_t)  in[4] << 16;
  w0 |= (uint64_t)  in[5] << 20;
  w0 |= (uint64_t)  in[6] << 24;
  w0 |= (uint64_t)  in[7] << 28;
  w0 |= (uint64_t)  in[8] << 32;
  w0 |= (uint64_t)  in[9] << 36;
  w0 |= (uint64_t)  in[10] << 40;
  w0 |= (uint64_t)  in[11] << 44;
  w0 |= (uint64_t)  in[12] << 48;
  w0 |= (uint64_t)  in[13] << 52;
  w0 |= (uint64_t)  in[14] << 56;
  w0 |= (uint64_t)  in[15] << 60;
  pw64[0] = w0;
  *pin += 16; /* we consumed 16 32-bit integers */
  *pw += 8; /* we used up 8 output bytes */
}


/* we are going to pack 16 5-bit values, touching 2 64-bit words, using 10 bytes */
static void packblock5(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 5;
  w0 |= (uint64_t)  in[2] << 10;
  w0 |= (uint64_t)  in[3] << 15;
  w0 |= (uint64_t)  in[4] << 20;
  w0 |= (uint64_t)  in[5] << 25;
  w0 |= (uint64_t)  in[6] << 30;
  w0 |= (uint64_t)  in[7] << 35;
  w0 |= (uint64_t)  in[8] << 40;
  w0 |= (uint64_t)  in[9] << 45;
  w0 |= (uint64_t)  in[10] << 50;
  w0 |= (uint64_t)  in[11] << 55;
  w0 |= (uint64_t) in[12] << 60;
  w1 = (uint64_t) in[12] >> 1;
  w1 |= (uint64_t)  in[13] << 1;
  w1 |= (uint64_t)  in[14] << 6;
  w1 |= (uint64_t)  in[15] << 11;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 16; /* we consumed 16 32-bit integers */
  *pw += 10; /* we used up 10 output bytes */
}


/* we are going to pack 12 6-bit values, touching 2 64-bit words, using 9 bytes */
static void packblock6(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 6;
  w0 |= (uint64_t)  in[2] << 12;
  w0 |= (uint64_t)  in[3] << 18;
  w0 |= (uint64_t)  in[4] << 24;
  w0 |= (uint64_t)  in[5] << 30;
  w0 |= (uint64_t)  in[6] << 36;
  w0 |= (uint64_t)  in[7] << 42;
  w0 |= (uint64_t)  in[8] << 48;
  w0 |= (uint64_t)  in[9] << 54;
  w0 |= (uint64_t) in[10] << 60;
  w1 = (uint64_t) in[10] >> 2;
  w1 |= (uint64_t)  in[11] << 2;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 12; /* we consumed 12 32-bit integers */
  *pw += 9; /* we used up 9 output bytes */
}


/* we are going to pack 16 7-bit values, touching 2 64-bit words, using 14 bytes */
static void packblock7(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 7;
  w0 |= (uint64_t)  in[2] << 14;
  w0 |= (uint64_t)  in[3] << 21;
  w0 |= (uint64_t)  in[4] << 28;
  w0 |= (uint64_t)  in[5] << 35;
  w0 |= (uint64_t)  in[6] << 42;
  w0 |= (uint64_t)  in[7] << 49;
  w0 |= (uint64_t)  in[8] << 56;
  w0 |= (uint64_t) in[9] << 63;
  w1 = (uint64_t) in[9] >> 6;
  w1 |= (uint64_t)  in[10] << 6;
  w1 |= (uint64_t)  in[11] << 13;
  w1 |= (uint64_t)  in[12] << 20;
  w1 |= (uint64_t)  in[13] << 27;
  w1 |= (uint64_t)  in[14] << 34;
  w1 |= (uint64_t)  in[15] << 41;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 16; /* we consumed 16 32-bit integers */
  *pw += 14; /* we used up 14 output bytes */
}


/* we are going to pack 8 8-bit values, touching 1 64-bit words, using 8 bytes */
static void packblock8(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 8;
  w0 |= (uint64_t)  in[2] << 16;
  w0 |= (uint64_t)  in[3] << 24;
  w0 |= (uint64_t)  in[4] << 32;
  w0 |= (uint64_t)  in[5] << 40;
  w0 |= (uint64_t)  in[6] << 48;
  w0 |= (uint64_t)  in[7] << 56;
  pw64[0] = w0;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 8; /* we used up 8 output bytes */
}


/* we are going to pack 8 9-bit values, touching 2 64-bit words, using 9 bytes */
static void packblock9(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 9;
  w0 |= (uint64_t)  in[2] << 18;
  w0 |= (uint64_t)  in[3] << 27;
  w0 |= (uint64_t)  in[4] << 36;
  w0 |= (uint64_t)  in[5] << 45;
  w0 |= (uint64_t)  in[6] << 54;
  w0 |= (uint64_t) in[7] << 63;
  w1 = (uint64_t) in[7] >> 8;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 9; /* we used up 9 output bytes */
}


/* we are going to pack 8 10-bit values, touching 2 64-bit words, using 10 bytes */
static void packblock10(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 10;
  w0 |= (uint64_t)  in[2] << 20;
  w0 |= (uint64_t)  in[3] << 30;
  w0 |= (uint64_t)  in[4] << 40;
  w0 |= (uint64_t)  in[5] << 50;
  w0 |= (uint64_t) in[6] << 60;
  w1 = (uint64_t) in[6] >> 6;
  w1 |= (uint64_t)  in[7] << 6;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 10; /* we used up 10 output bytes */
}


/* we are going to pack 8 11-bit values, touching 2 64-bit words, using 11 bytes */
static void packblock11(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 11;
  w0 |= (uint64_t)  in[2] << 22;
  w0 |= (uint64_t)  in[3] << 33;
  w0 |= (uint64_t)  in[4] << 44;
  w0 |= (uint64_t) in[5] << 55;
  w1 = (uint64_t) in[5] >> 2;
  w1 |= (uint64_t)  in[6] << 2;
  w1 |= (uint64_t)  in[7] << 13;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 11; /* we used up 11 output bytes */
}


/* we are going to pack 6 12-bit values, touching 2 64-bit words, using 9 bytes */
static void packblock12(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 12;
  w0 |= (uint64_t)  in[2] << 24;
  w0 |= (uint64_t)  in[3] << 36;
  w0 |= (uint64_t)  in[4] << 48;
  w0 |= (uint64_t) in[5] << 60;
  w1 = (uint64_t) in[5] >> 8;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 6; /* we consumed 6 32-bit integers */
  *pw += 9; /* we used up 9 output bytes */
}


/* we are going to pack 8 13-bit values, touching 2 64-bit words, using 13 bytes */
static void packblock13(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 13;
  w0 |= (uint64_t)  in[2] << 26;
  w0 |= (uint64_t)  in[3] << 39;
  w0 |= (uint64_t) in[4] << 52;
  w1 = (uint64_t) in[4] >> 1;
  w1 |= (uint64_t)  in[5] << 1;
  w1 |= (uint64_t)  in[6] << 14;
  w1 |= (uint64_t)  in[7] << 27;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 13; /* we used up 13 output bytes */
}


/* we are going to pack 8 14-bit values, touching 2 64-bit words, using 14 bytes */
static void packblock14(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 14;
  w0 |= (uint64_t)  in[2] << 28;
  w0 |= (uint64_t)  in[3] << 42;
  w0 |= (uint64_t) in[4] << 56;
  w1 = (uint64_t) in[4] >> 6;
  w1 |= (uint64_t)  in[5] << 6;
  w1 |= (uint64_t)  in[6] << 20;
  w1 |= (uint64_t)  in[7] << 34;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 14; /* we used up 14 output bytes */
}


/* we are going to pack 8 15-bit values, touching 2 64-bit words, using 15 bytes */
static void packblock15(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 15;
  w0 |= (uint64_t)  in[2] << 30;
  w0 |= (uint64_t)  in[3] << 45;
  w0 |= (uint64_t) in[4] << 60;
  w1 = (uint64_t) in[4] >> 11;
  w1 |= (uint64_t)  in[5] << 11;
  w1 |= (uint64_t)  in[6] << 26;
  w1 |= (uint64_t)  in[7] << 41;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 15; /* we used up 15 output bytes */
}


/* we are going to pack 4 16-bit values, touching 1 64-bit words, using 8 bytes */
static void packblock16(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 16;
  w0 |= (uint64_t)  in[2] << 32;
  w0 |= (uint64_t)  in[3] << 48;
  pw64[0] = w0;
  *pin += 4; /* we consumed 4 32-bit integers */
  *pw += 8; /* we used up 8 output bytes */
}


/* we are going to pack 8 17-bit values, touching 3 64-bit words, using 17 bytes */
static void packblock17(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  3 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 17;
  w0 |= (uint64_t)  in[2] << 34;
  w0 |= (uint64_t) in[3] << 51;
  w1 = (uint64_t) in[3] >> 4;
  w1 |= (uint64_t)  in[4] << 4;
  w1 |= (uint64_t)  in[5] << 21;
  w1 |= (uint64_t)  in[6] << 38;
  w1 |= (uint64_t) in[7] << 55;
  w2 = (uint64_t) in[7] >> 8;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 17; /* we used up 17 output bytes */
}


/* we are going to pack 4 18-bit values, touching 2 64-bit words, using 9 bytes */
static void packblock18(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 18;
  w0 |= (uint64_t)  in[2] << 36;
  w0 |= (uint64_t) in[3] << 54;
  w1 = (uint64_t) in[3] >> 8;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 4; /* we consumed 4 32-bit integers */
  *pw += 9; /* we used up 9 output bytes */
}


/* we are going to pack 8 19-bit values, touching 3 64-bit words, using 19 bytes */
static void packblock19(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  3 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 19;
  w0 |= (uint64_t)  in[2] << 38;
  w0 |= (uint64_t) in[3] << 57;
  w1 = (uint64_t) in[3] >> 12;
  w1 |= (uint64_t)  in[4] << 12;
  w1 |= (uint64_t)  in[5] << 31;
  w1 |= (uint64_t) in[6] << 50;
  w2 = (uint64_t) in[6] >> 5;
  w2 |= (uint64_t)  in[7] << 5;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 19; /* we used up 19 output bytes */
}


/* we are going to pack 4 20-bit values, touching 2 64-bit words, using 10 bytes */
static void packblock20(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 20;
  w0 |= (uint64_t)  in[2] << 40;
  w0 |= (uint64_t) in[3] << 60;
  w1 = (uint64_t) in[3] >> 16;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 4; /* we consumed 4 32-bit integers */
  *pw += 10; /* we used up 10 output bytes */
}


/* we are going to pack 8 21-bit values, touching 3 64-bit words, using 21 bytes */
static void packblock21(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  3 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 21;
  w0 |= (uint64_t)  in[2] << 42;
  w0 |= (uint64_t) in[3] << 63;
  w1 = (uint64_t) in[3] >> 20;
  w1 |= (uint64_t)  in[4] << 20;
  w1 |= (uint64_t)  in[5] << 41;
  w1 |= (uint64_t) in[6] << 62;
  w2 = (uint64_t) in[6] >> 19;
  w2 |= (uint64_t)  in[7] << 19;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 21; /* we used up 21 output bytes */
}


/* we are going to pack 4 22-bit values, touching 2 64-bit words, using 11 bytes */
static void packblock22(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 22;
  w0 |= (uint64_t) in[2] << 44;
  w1 = (uint64_t) in[2] >> 2;
  w1 |= (uint64_t)  in[3] << 2;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 4; /* we consumed 4 32-bit integers */
  *pw += 11; /* we used up 11 output bytes */
}


/* we are going to pack 8 23-bit values, touching 3 64-bit words, using 23 bytes */
static void packblock23(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  3 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 23;
  w0 |= (uint64_t) in[2] << 46;
  w1 = (uint64_t) in[2] >> 5;
  w1 |= (uint64_t)  in[3] << 5;
  w1 |= (uint64_t)  in[4] << 28;
  w1 |= (uint64_t) in[5] << 51;
  w2 = (uint64_t) in[5] >> 10;
  w2 |= (uint64_t)  in[6] << 10;
  w2 |= (uint64_t)  in[7] << 33;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 23; /* we used up 23 output bytes */
}


/* we are going to pack 3 24-bit values, touching 2 64-bit words, using 9 bytes */
static void packblock24(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 24;
  w0 |= (uint64_t) in[2] << 48;
  w1 = (uint64_t) in[2] >> 8;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 3; /* we consumed 3 32-bit integers */
  *pw += 9; /* we used up 9 output bytes */
}


/* we are going to pack 8 25-bit values, touching 4 64-bit words, using 25 bytes */
static void packblock25(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  4 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 25;
  w0 |= (uint64_t) in[2] << 50;
  w1 = (uint64_t) in[2] >> 11;
  w1 |= (uint64_t)  in[3] << 11;
  w1 |= (uint64_t)  in[4] << 36;
  w1 |= (uint64_t) in[5] << 61;
  w2 = (uint64_t) in[5] >> 22;
  w2 |= (uint64_t)  in[6] << 22;
  w2 |= (uint64_t) in[7] << 47;
  w3 = (uint64_t) in[7] >> 8;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 25; /* we used up 25 output bytes */
}


/* we are going to pack 4 26-bit values, touching 2 64-bit words, using 13 bytes */
static void packblock26(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 26;
  w0 |= (uint64_t) in[2] << 52;
  w1 = (uint64_t) in[2] >> 14;
  w1 |= (uint64_t)  in[3] << 14;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 4; /* we consumed 4 32-bit integers */
  *pw += 13; /* we used up 13 output bytes */
}


/* we are going to pack 8 27-bit values, touching 4 64-bit words, using 27 bytes */
static void packblock27(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  4 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 27;
  w0 |= (uint64_t) in[2] << 54;
  w1 = (uint64_t) in[2] >> 17;
  w1 |= (uint64_t)  in[3] << 17;
  w1 |= (uint64_t) in[4] << 44;
  w2 = (uint64_t) in[4] >> 7;
  w2 |= (uint64_t)  in[5] << 7;
  w2 |= (uint64_t)  in[6] << 34;
  w2 |= (uint64_t) in[7] << 61;
  w3 = (uint64_t) in[7] >> 24;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 27; /* we used up 27 output bytes */
}


/* we are going to pack 4 28-bit values, touching 2 64-bit words, using 14 bytes */
static void packblock28(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 28;
  w0 |= (uint64_t) in[2] << 56;
  w1 = (uint64_t) in[2] >> 20;
  w1 |= (uint64_t)  in[3] << 20;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 4; /* we consumed 4 32-bit integers */
  *pw += 14; /* we used up 14 output bytes */
}


/* we are going to pack 8 29-bit values, touching 4 64-bit words, using 29 bytes */
static void packblock29(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  4 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 29;
  w0 |= (uint64_t) in[2] << 58;
  w1 = (uint64_t) in[2] >> 23;
  w1 |= (uint64_t)  in[3] << 23;
  w1 |= (uint64_t) in[4] << 52;
  w2 = (uint64_t) in[4] >> 17;
  w2 |= (uint64_t)  in[5] << 17;
  w2 |= (uint64_t) in[6] << 46;
  w3 = (uint64_t) in[6] >> 11;
  w3 |= (uint64_t)  in[7] << 11;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 29; /* we used up 29 output bytes */
}


/* we are going to pack 4 30-bit values, touching 2 64-bit words, using 15 bytes */
static void packblock30(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  2 64-bit words */
  uint64_t w0;
  uint64_t w1;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 30;
  w0 |= (uint64_t) in[2] << 60;
  w1 = (uint64_t) in[2] >> 26;
  w1 |= (uint64_t)  in[3] << 26;
  pw64[0] = w0;
  pw64[1] = w1;
  *pin += 4; /* we consumed 4 32-bit integers */
  *pw += 15; /* we used up 15 output bytes */
}


/* we are going to pack 8 31-bit values, touching 4 64-bit words, using 31 bytes */
static void packblock31(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  4 64-bit words */
  uint64_t w0;
  uint64_t w1;
  uint64_t w2;
  uint64_t w3;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 31;
  w0 |= (uint64_t) in[2] << 62;
  w1 = (uint64_t) in[2] >> 29;
  w1 |= (uint64_t)  in[3] << 29;
  w1 |= (uint64_t) in[4] << 60;
  w2 = (uint64_t) in[4] >> 27;
  w2 |= (uint64_t)  in[5] << 27;
  w2 |= (uint64_t) in[6] << 58;
  w3 = (uint64_t) in[6] >> 25;
  w3 |= (uint64_t)  in[7] << 25;
  pw64[0] = w0;
  pw64[1] = w1;
  pw64[2] = w2;
  pw64[3] = w3;
  *pin += 8; /* we consumed 8 32-bit integers */
  *pw += 31; /* we used up 31 output bytes */
}


/* we are going to pack 2 32-bit values, touching 1 64-bit words, using 8 bytes */
static void packblock32(const uint32_t ** pin, uint8_t ** pw) {
  uint64_t * pw64 = *(uint64_t **) pw;
  const uint32_t * in = *pin;
  /* we are going to touch  1 64-bit word */
  uint64_t w0;
  w0 = (uint64_t) in[0];
  w0 |= (uint64_t)  in[1] << 32;
  pw64[0] = w0;
  *pin += 2; /* we consumed 2 32-bit integers */
  *pw += 8; /* we used up 8 output bytes */
}


/* we packed 64 1-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackblock1(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(1);
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 1 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 2 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 3 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 4 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 5 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 6 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 7 )  % mask  );
  out[8] = (uint32_t)  ( ( w0 >> 8 )  % mask  );
  out[9] = (uint32_t)  ( ( w0 >> 9 )  % mask  );
  out[10] = (uint32_t)  ( ( w0 >> 10 )  % mask  );
  out[11] = (uint32_t)  ( ( w0 >> 11 )  % mask  );
  out[12] = (uint32_t)  ( ( w0 >> 12 )  % mask  );
  out[13] = (uint32_t)  ( ( w0 >> 13 )  % mask  );
  out[14] = (uint32_t)  ( ( w0 >> 14 )  % mask  );
  out[15] = (uint32_t)  ( ( w0 >> 15 )  % mask  );
  out[16] = (uint32_t)  ( ( w0 >> 16 )  % mask  );
  out[17] = (uint32_t)  ( ( w0 >> 17 )  % mask  );
  out[18] = (uint32_t)  ( ( w0 >> 18 )  % mask  );
  out[19] = (uint32_t)  ( ( w0 >> 19 )  % mask  );
  out[20] = (uint32_t)  ( ( w0 >> 20 )  % mask  );
  out[21] = (uint32_t)  ( ( w0 >> 21 )  % mask  );
  out[22] = (uint32_t)  ( ( w0 >> 22 )  % mask  );
  out[23] = (uint32_t)  ( ( w0 >> 23 )  % mask  );
  out[24] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[25] = (uint32_t)  ( ( w0 >> 25 )  % mask  );
  out[26] = (uint32_t)  ( ( w0 >> 26 )  % mask  );
  out[27] = (uint32_t)  ( ( w0 >> 27 )  % mask  );
  out[28] = (uint32_t)  ( ( w0 >> 28 )  % mask  );
  out[29] = (uint32_t)  ( ( w0 >> 29 )  % mask  );
  out[30] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[31] = (uint32_t)  ( ( w0 >> 31 )  % mask  );
  out[32] = (uint32_t)  ( ( w0 >> 32 )  % mask  );
  out[33] = (uint32_t)  ( ( w0 >> 33 )  % mask  );
  out[34] = (uint32_t)  ( ( w0 >> 34 )  % mask  );
  out[35] = (uint32_t)  ( ( w0 >> 35 )  % mask  );
  out[36] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[37] = (uint32_t)  ( ( w0 >> 37 )  % mask  );
  out[38] = (uint32_t)  ( ( w0 >> 38 )  % mask  );
  out[39] = (uint32_t)  ( ( w0 >> 39 )  % mask  );
  out[40] = (uint32_t)  ( ( w0 >> 40 )  % mask  );
  out[41] = (uint32_t)  ( ( w0 >> 41 )  % mask  );
  out[42] = (uint32_t)  ( ( w0 >> 42 )  % mask  );
  out[43] = (uint32_t)  ( ( w0 >> 43 )  % mask  );
  out[44] = (uint32_t)  ( ( w0 >> 44 )  % mask  );
  out[45] = (uint32_t)  ( ( w0 >> 45 )  % mask  );
  out[46] = (uint32_t)  ( ( w0 >> 46 )  % mask  );
  out[47] = (uint32_t)  ( ( w0 >> 47 )  % mask  );
  out[48] = (uint32_t)  ( ( w0 >> 48 )  % mask  );
  out[49] = (uint32_t)  ( ( w0 >> 49 )  % mask  );
  out[50] = (uint32_t)  ( ( w0 >> 50 )  % mask  );
  out[51] = (uint32_t)  ( ( w0 >> 51 )  % mask  );
  out[52] = (uint32_t)  ( ( w0 >> 52 )  % mask  );
  out[53] = (uint32_t)  ( ( w0 >> 53 )  % mask  );
  out[54] = (uint32_t)  ( ( w0 >> 54 )  % mask  );
  out[55] = (uint32_t)  ( ( w0 >> 55 )  % mask  );
  out[56] = (uint32_t)  ( ( w0 >> 56 )  % mask  );
  out[57] = (uint32_t)  ( ( w0 >> 57 )  % mask  );
  out[58] = (uint32_t)  ( ( w0 >> 58 )  % mask  );
  out[59] = (uint32_t)  ( ( w0 >> 59 )  % mask  );
  out[60] = (uint32_t)  ( ( w0 >> 60 )  % mask  );
  out[61] = (uint32_t)  ( ( w0 >> 61 )  % mask  );
  out[62] = (uint32_t)  ( ( w0 >> 62 )  % mask  );
  out[63] = (uint32_t) ( w0  >> 63  );
  *pout += 64; /* we wrote 64 32-bit integers */
  *pw += 8; /* we used up 8 input bytes */
}


/* we packed 32 2-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackblock2(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(3);
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 2 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 4 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 6 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 8 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 10 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 12 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 14 )  % mask  );
  out[8] = (uint32_t)  ( ( w0 >> 16 )  % mask  );
  out[9] = (uint32_t)  ( ( w0 >> 18 )  % mask  );
  out[10] = (uint32_t)  ( ( w0 >> 20 )  % mask  );
  out[11] = (uint32_t)  ( ( w0 >> 22 )  % mask  );
  out[12] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[13] = (uint32_t)  ( ( w0 >> 26 )  % mask  );
  out[14] = (uint32_t)  ( ( w0 >> 28 )  % mask  );
  out[15] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[16] = (uint32_t)  ( ( w0 >> 32 )  % mask  );
  out[17] = (uint32_t)  ( ( w0 >> 34 )  % mask  );
  out[18] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[19] = (uint32_t)  ( ( w0 >> 38 )  % mask  );
  out[20] = (uint32_t)  ( ( w0 >> 40 )  % mask  );
  out[21] = (uint32_t)  ( ( w0 >> 42 )  % mask  );
  out[22] = (uint32_t)  ( ( w0 >> 44 )  % mask  );
  out[23] = (uint32_t)  ( ( w0 >> 46 )  % mask  );
  out[24] = (uint32_t)  ( ( w0 >> 48 )  % mask  );
  out[25] = (uint32_t)  ( ( w0 >> 50 )  % mask  );
  out[26] = (uint32_t)  ( ( w0 >> 52 )  % mask  );
  out[27] = (uint32_t)  ( ( w0 >> 54 )  % mask  );
  out[28] = (uint32_t)  ( ( w0 >> 56 )  % mask  );
  out[29] = (uint32_t)  ( ( w0 >> 58 )  % mask  );
  out[30] = (uint32_t)  ( ( w0 >> 60 )  % mask  );
  out[31] = (uint32_t) ( w0  >> 62  );
  *pout += 32; /* we wrote 32 32-bit integers */
  *pw += 8; /* we used up 8 input bytes */
}


/* we packed 24 3-bit values, touching 2 64-bit words, using 9 bytes */
static void unpackblock3(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(7);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 3 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 6 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 9 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 12 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 15 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 18 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 21 )  % mask  );
  out[8] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[9] = (uint32_t)  ( ( w0 >> 27 )  % mask  );
  out[10] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[11] = (uint32_t)  ( ( w0 >> 33 )  % mask  );
  out[12] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[13] = (uint32_t)  ( ( w0 >> 39 )  % mask  );
  out[14] = (uint32_t)  ( ( w0 >> 42 )  % mask  );
  out[15] = (uint32_t)  ( ( w0 >> 45 )  % mask  );
  out[16] = (uint32_t)  ( ( w0 >> 48 )  % mask  );
  out[17] = (uint32_t)  ( ( w0 >> 51 )  % mask  );
  out[18] = (uint32_t)  ( ( w0 >> 54 )  % mask  );
  out[19] = (uint32_t)  ( ( w0 >> 57 )  % mask  );
  out[20] = (uint32_t)  ( ( w0 >> 60 )  % mask  );
  out[21] = (uint32_t)  ( ( w0 >> 63  ) | ( w1 << 2 )  % mask  );
  out[22] = (uint32_t)  ( ( w1 >> 2 )  % mask  );
  out[23] = (uint32_t)  ( ( w1 >> 5 )  % mask  );
  *pout += 24; /* we wrote 24 32-bit integers */
  *pw += 9; /* we used up 9 input bytes */
}


/* we packed 16 4-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackblock4(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(15);
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 4 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 8 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 12 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 16 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 20 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 28 )  % mask  );
  out[8] = (uint32_t)  ( ( w0 >> 32 )  % mask  );
  out[9] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[10] = (uint32_t)  ( ( w0 >> 40 )  % mask  );
  out[11] = (uint32_t)  ( ( w0 >> 44 )  % mask  );
  out[12] = (uint32_t)  ( ( w0 >> 48 )  % mask  );
  out[13] = (uint32_t)  ( ( w0 >> 52 )  % mask  );
  out[14] = (uint32_t)  ( ( w0 >> 56 )  % mask  );
  out[15] = (uint32_t) ( w0  >> 60  );
  *pout += 16; /* we wrote 16 32-bit integers */
  *pw += 8; /* we used up 8 input bytes */
}


/* we packed 16 5-bit values, touching 2 64-bit words, using 10 bytes */
static void unpackblock5(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(31);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 5 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 10 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 15 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 20 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 25 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 35 )  % mask  );
  out[8] = (uint32_t)  ( ( w0 >> 40 )  % mask  );
  out[9] = (uint32_t)  ( ( w0 >> 45 )  % mask  );
  out[10] = (uint32_t)  ( ( w0 >> 50 )  % mask  );
  out[11] = (uint32_t)  ( ( w0 >> 55 )  % mask  );
  out[12] = (uint32_t)  ( ( w0 >> 60  ) | ( w1 << 1 )  % mask  );
  out[13] = (uint32_t)  ( ( w1 >> 1 )  % mask  );
  out[14] = (uint32_t)  ( ( w1 >> 6 )  % mask  );
  out[15] = (uint32_t)  ( ( w1 >> 11 )  % mask  );
  *pout += 16; /* we wrote 16 32-bit integers */
  *pw += 10; /* we used up 10 input bytes */
}


/* we packed 12 6-bit values, touching 2 64-bit words, using 9 bytes */
static void unpackblock6(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(63);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 6 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 12 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 18 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 42 )  % mask  );
  out[8] = (uint32_t)  ( ( w0 >> 48 )  % mask  );
  out[9] = (uint32_t)  ( ( w0 >> 54 )  % mask  );
  out[10] = (uint32_t)  ( ( w0 >> 60  ) | ( w1 << 2 )  % mask  );
  out[11] = (uint32_t)  ( ( w1 >> 2 )  % mask  );
  *pout += 12; /* we wrote 12 32-bit integers */
  *pw += 9; /* we used up 9 input bytes */
}


/* we packed 16 7-bit values, touching 2 64-bit words, using 14 bytes */
static void unpackblock7(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(127);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 7 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 14 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 21 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 28 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 35 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 42 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 49 )  % mask  );
  out[8] = (uint32_t)  ( ( w0 >> 56 )  % mask  );
  out[9] = (uint32_t)  ( ( w0 >> 63  ) | ( w1 << 6 )  % mask  );
  out[10] = (uint32_t)  ( ( w1 >> 6 )  % mask  );
  out[11] = (uint32_t)  ( ( w1 >> 13 )  % mask  );
  out[12] = (uint32_t)  ( ( w1 >> 20 )  % mask  );
  out[13] = (uint32_t)  ( ( w1 >> 27 )  % mask  );
  out[14] = (uint32_t)  ( ( w1 >> 34 )  % mask  );
  out[15] = (uint32_t)  ( ( w1 >> 41 )  % mask  );
  *pout += 16; /* we wrote 16 32-bit integers */
  *pw += 14; /* we used up 14 input bytes */
}


/* we packed 8 8-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackblock8(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(255);
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 8 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 16 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 32 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 40 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 48 )  % mask  );
  out[7] = (uint32_t) ( w0  >> 56  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 8; /* we used up 8 input bytes */
}


/* we packed 8 9-bit values, touching 2 64-bit words, using 9 bytes */
static void unpackblock9(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(511);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 9 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 18 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 27 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 45 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 54 )  % mask  );
  out[7] = (uint32_t)  ( ( w0 >> 63  ) | ( w1 << 8 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 9; /* we used up 9 input bytes */
}


/* we packed 8 10-bit values, touching 2 64-bit words, using 10 bytes */
static void unpackblock10(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(1023);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 10 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 20 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 40 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 50 )  % mask  );
  out[6] = (uint32_t)  ( ( w0 >> 60  ) | ( w1 << 6 )  % mask  );
  out[7] = (uint32_t)  ( ( w1 >> 6 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 10; /* we used up 10 input bytes */
}


/* we packed 8 11-bit values, touching 2 64-bit words, using 11 bytes */
static void unpackblock11(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(2047);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 11 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 22 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 33 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 44 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 55  ) | ( w1 << 2 )  % mask  );
  out[6] = (uint32_t)  ( ( w1 >> 2 )  % mask  );
  out[7] = (uint32_t)  ( ( w1 >> 13 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 11; /* we used up 11 input bytes */
}


/* we packed 6 12-bit values, touching 2 64-bit words, using 9 bytes */
static void unpackblock12(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(4095);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 12 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 48 )  % mask  );
  out[5] = (uint32_t)  ( ( w0 >> 60  ) | ( w1 << 8 )  % mask  );
  *pout += 6; /* we wrote 6 32-bit integers */
  *pw += 9; /* we used up 9 input bytes */
}


/* we packed 8 13-bit values, touching 2 64-bit words, using 13 bytes */
static void unpackblock13(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(8191);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 13 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 26 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 39 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 52  ) | ( w1 << 1 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 1 )  % mask  );
  out[6] = (uint32_t)  ( ( w1 >> 14 )  % mask  );
  out[7] = (uint32_t)  ( ( w1 >> 27 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 13; /* we used up 13 input bytes */
}


/* we packed 8 14-bit values, touching 2 64-bit words, using 14 bytes */
static void unpackblock14(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(16383);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 14 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 28 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 42 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 56  ) | ( w1 << 6 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 6 )  % mask  );
  out[6] = (uint32_t)  ( ( w1 >> 20 )  % mask  );
  out[7] = (uint32_t)  ( ( w1 >> 34 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 14; /* we used up 14 input bytes */
}


/* we packed 8 15-bit values, touching 2 64-bit words, using 15 bytes */
static void unpackblock15(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(32767);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 15 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 45 )  % mask  );
  out[4] = (uint32_t)  ( ( w0 >> 60  ) | ( w1 << 11 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 11 )  % mask  );
  out[6] = (uint32_t)  ( ( w1 >> 26 )  % mask  );
  out[7] = (uint32_t)  ( ( w1 >> 41 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 15; /* we used up 15 input bytes */
}


/* we packed 4 16-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackblock16(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(65535);
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 16 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 32 )  % mask  );
  out[3] = (uint32_t) ( w0  >> 48  );
  *pout += 4; /* we wrote 4 32-bit integers */
  *pw += 8; /* we used up 8 input bytes */
}


/* we packed 8 17-bit values, touching 3 64-bit words, using 17 bytes */
static void unpackblock17(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(131071);
  /* we are going to access  3 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 17 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 34 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 51  ) | ( w1 << 4 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 4 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 21 )  % mask  );
  out[6] = (uint32_t)  ( ( w1 >> 38 )  % mask  );
  out[7] = (uint32_t)  ( ( w1 >> 55  ) | ( w2 << 8 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 17; /* we used up 17 input bytes */
}


/* we packed 4 18-bit values, touching 2 64-bit words, using 9 bytes */
static void unpackblock18(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(262143);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 18 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 36 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 54  ) | ( w1 << 8 )  % mask  );
  *pout += 4; /* we wrote 4 32-bit integers */
  *pw += 9; /* we used up 9 input bytes */
}


/* we packed 8 19-bit values, touching 3 64-bit words, using 19 bytes */
static void unpackblock19(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(524287);
  /* we are going to access  3 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 19 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 38 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 57  ) | ( w1 << 12 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 12 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 31 )  % mask  );
  out[6] = (uint32_t)  ( ( w1 >> 50  ) | ( w2 << 5 )  % mask  );
  out[7] = (uint32_t)  ( ( w2 >> 5 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 19; /* we used up 19 input bytes */
}


/* we packed 4 20-bit values, touching 2 64-bit words, using 10 bytes */
static void unpackblock20(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(1048575);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 20 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 40 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 60  ) | ( w1 << 16 )  % mask  );
  *pout += 4; /* we wrote 4 32-bit integers */
  *pw += 10; /* we used up 10 input bytes */
}


/* we packed 8 21-bit values, touching 3 64-bit words, using 21 bytes */
static void unpackblock21(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(2097151);
  /* we are going to access  3 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 21 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 42 )  % mask  );
  out[3] = (uint32_t)  ( ( w0 >> 63  ) | ( w1 << 20 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 20 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 41 )  % mask  );
  out[6] = (uint32_t)  ( ( w1 >> 62  ) | ( w2 << 19 )  % mask  );
  out[7] = (uint32_t)  ( ( w2 >> 19 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 21; /* we used up 21 input bytes */
}


/* we packed 4 22-bit values, touching 2 64-bit words, using 11 bytes */
static void unpackblock22(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(4194303);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 22 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 44  ) | ( w1 << 2 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 2 )  % mask  );
  *pout += 4; /* we wrote 4 32-bit integers */
  *pw += 11; /* we used up 11 input bytes */
}


/* we packed 8 23-bit values, touching 3 64-bit words, using 23 bytes */
static void unpackblock23(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(8388607);
  /* we are going to access  3 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 23 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 46  ) | ( w1 << 5 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 5 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 28 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 51  ) | ( w2 << 10 )  % mask  );
  out[6] = (uint32_t)  ( ( w2 >> 10 )  % mask  );
  out[7] = (uint32_t)  ( ( w2 >> 33 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 23; /* we used up 23 input bytes */
}


/* we packed 3 24-bit values, touching 2 64-bit words, using 9 bytes */
static void unpackblock24(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(16777215);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 24 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 48  ) | ( w1 << 8 )  % mask  );
  *pout += 3; /* we wrote 3 32-bit integers */
  *pw += 9; /* we used up 9 input bytes */
}


/* we packed 8 25-bit values, touching 4 64-bit words, using 25 bytes */
static void unpackblock25(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(33554431);
  /* we are going to access  4 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 25 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 50  ) | ( w1 << 11 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 11 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 36 )  % mask  );
  out[5] = (uint32_t)  ( ( w1 >> 61  ) | ( w2 << 22 )  % mask  );
  out[6] = (uint32_t)  ( ( w2 >> 22 )  % mask  );
  out[7] = (uint32_t)  ( ( w2 >> 47  ) | ( w3 << 8 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 25; /* we used up 25 input bytes */
}


/* we packed 4 26-bit values, touching 2 64-bit words, using 13 bytes */
static void unpackblock26(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(67108863);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 26 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 52  ) | ( w1 << 14 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 14 )  % mask  );
  *pout += 4; /* we wrote 4 32-bit integers */
  *pw += 13; /* we used up 13 input bytes */
}


/* we packed 8 27-bit values, touching 4 64-bit words, using 27 bytes */
static void unpackblock27(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(134217727);
  /* we are going to access  4 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 27 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 54  ) | ( w1 << 17 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 17 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 44  ) | ( w2 << 7 )  % mask  );
  out[5] = (uint32_t)  ( ( w2 >> 7 )  % mask  );
  out[6] = (uint32_t)  ( ( w2 >> 34 )  % mask  );
  out[7] = (uint32_t)  ( ( w2 >> 61  ) | ( w3 << 24 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 27; /* we used up 27 input bytes */
}


/* we packed 4 28-bit values, touching 2 64-bit words, using 14 bytes */
static void unpackblock28(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(268435455);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 28 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 56  ) | ( w1 << 20 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 20 )  % mask  );
  *pout += 4; /* we wrote 4 32-bit integers */
  *pw += 14; /* we used up 14 input bytes */
}


/* we packed 8 29-bit values, touching 4 64-bit words, using 29 bytes */
static void unpackblock29(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(536870911);
  /* we are going to access  4 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 29 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 58  ) | ( w1 << 23 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 23 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 52  ) | ( w2 << 17 )  % mask  );
  out[5] = (uint32_t)  ( ( w2 >> 17 )  % mask  );
  out[6] = (uint32_t)  ( ( w2 >> 46  ) | ( w3 << 11 )  % mask  );
  out[7] = (uint32_t)  ( ( w3 >> 11 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 29; /* we used up 29 input bytes */
}


/* we packed 4 30-bit values, touching 2 64-bit words, using 15 bytes */
static void unpackblock30(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(1073741823);
  /* we are going to access  2 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 30 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 60  ) | ( w1 << 26 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 26 )  % mask  );
  *pout += 4; /* we wrote 4 32-bit integers */
  *pw += 15; /* we used up 15 input bytes */
}


/* we packed 8 31-bit values, touching 4 64-bit words, using 31 bytes */
static void unpackblock31(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  const uint64_t mask = UINT64_C(2147483647);
  /* we are going to access  4 64-bit words */
  uint64_t w0 = pw64[0];
  uint64_t w1 = pw64[1];
  uint64_t w2 = pw64[2];
  uint64_t w3 = pw64[3];
  out[0] = (uint32_t)  ( ( w0 )  % mask  );
  out[1] = (uint32_t)  ( ( w0 >> 31 )  % mask  );
  out[2] = (uint32_t)  ( ( w0 >> 62  ) | ( w1 << 29 )  % mask  );
  out[3] = (uint32_t)  ( ( w1 >> 29 )  % mask  );
  out[4] = (uint32_t)  ( ( w1 >> 60  ) | ( w2 << 27 )  % mask  );
  out[5] = (uint32_t)  ( ( w2 >> 27 )  % mask  );
  out[6] = (uint32_t)  ( ( w2 >> 58  ) | ( w3 << 25 )  % mask  );
  out[7] = (uint32_t)  ( ( w3 >> 25 )  % mask  );
  *pout += 8; /* we wrote 8 32-bit integers */
  *pw += 31; /* we used up 31 input bytes */
}


/* we packed 2 32-bit values, touching 1 64-bit words, using 8 bytes */
static void unpackblock32(const uint8_t ** pw, uint32_t ** pout) {
  const uint64_t * pw64 = *(const uint64_t **) pw;
  uint32_t * out = *pout;
  /* we are going to access  1 64-bit word */
  uint64_t w0 = pw64[0];
  out[0] = (uint32_t)  ( ( w0 )  );
  out[1] = (uint32_t) ( w0  >> 32  );
  *pout += 2; /* we wrote 2 32-bit integers */
  *pw += 8; /* we used up 8 input bytes */
}

static packblockfnc funcPackArr[] = {
NULL,
&packblock1,
&packblock2,
&packblock3,
&packblock4,
&packblock5,
&packblock6,
&packblock7,
&packblock8,
&packblock9,
&packblock10,
&packblock11,
&packblock12,
&packblock13,
&packblock14,
&packblock15,
&packblock16,
&packblock17,
&packblock18,
&packblock19,
&packblock20,
&packblock21,
&packblock22,
&packblock23,
&packblock24,
&packblock25,
&packblock26,
&packblock27,
&packblock28,
&packblock29,
&packblock30,
&packblock31,
&packblock32
};
static unpackblockfnc funcUnpackArr[] = {
NULL,
&unpackblock1,
&unpackblock2,
&unpackblock3,
&unpackblock4,
&unpackblock5,
&unpackblock6,
&unpackblock7,
&unpackblock8,
&unpackblock9,
&unpackblock10,
&unpackblock11,
&unpackblock12,
&unpackblock13,
&unpackblock14,
&unpackblock15,
&unpackblock16,
&unpackblock17,
&unpackblock18,
&unpackblock19,
&unpackblock20,
&unpackblock21,
&unpackblock22,
&unpackblock23,
&unpackblock24,
&unpackblock25,
&unpackblock26,
&unpackblock27,
&unpackblock28,
&unpackblock29,
&unpackblock30,
&unpackblock31,
&unpackblock32
};


/* write number 32-bit values from in bit bits per value to out. */
void pack32(const uint32_t *  in,  uint32_t number, const uint32_t bit, uint8_t *  out) {
  if(bit == 0) {
    return;// nothing to do
  }
  packblockfnc bitpack = funcPackArr[bit];
  const uint32_t * finalin = in + number;
  while(in < finalin) {
    bitpack(&in,&out);
  }
}

/* reads  number 32-bit values from "in" as packed bit bits values, and write to "out" */
void unpack32(const uint8_t * in, uint32_t number, const uint32_t bit, uint32_t *  out) {
  if(bit == 0) {
    memset(out,0,sizeof(uint32_t)*number);
    return;
  }
  unpackblockfnc bitunpack = funcUnpackArr[bit];
  uint32_t * finalout = out + number;
  while(out < finalout) {
    bitunpack(&in,&out);
  }
}

