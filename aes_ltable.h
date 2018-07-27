#include "aes.h"
#define N 50
void subbyte_ltable(byte *a, int n);
void lookup_table(byte T[][N], int m, int n, byte *a, byte *b);
void shift_table(byte T[][N], int m, int n, byte *a, byte Tp[][N]);
