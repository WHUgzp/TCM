#include "aes.h"

void aes_rp(byte in[16],byte out[16],byte key[16]);
void subbyte_rp_share(byte *a,int n);
void matMult(byte *a, byte *b, byte M[][20], int n);
