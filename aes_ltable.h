#include "aes.h"

void subbyte_ltable(byte *a, int n);
void lookup_table(byte T[][20], int m, int n, byte *a, byte *b);
void shift_table(byte T[][20], int m, int n, byte *a, byte Tp[][20]);
