#include "aes_ltable.h"
#include "share.h"
#include <stdio.h>
#include <string.h>

#define K 256
#define N 50

//void subbyte_ltable(byte *a, int n)
//{
//	byte T[K][20];
//	byte b[20];
//	int i;
//
//	for (i = 0; i < K; i++)
//	{
//		share(sbox[i], T[i], n);
//		refresh(T[i], n);
//	}
//	for (i = 0; i < n; i++) b[i] = a[i];
//
//	lookup_table(T, K, n, a, b);
//	
//	refresh(b, n);
//	for (i = 0; i < n; i++) a[i] = b[i];
//}

void subbyte_ltable(byte *a, int n)
{
	//K*n + 2*n + n*n + n + 12
	byte T[K][N];
	byte Temp[2][N];
	byte b[N][N];
	byte y[N];
	int i, j, m, h;
	int table_num[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };

	for (i = 0; i < K; i++)
	{
		share(sbox[i], T[i], n);
		refresh_1(T[i], n);
	}

	for (m = 0; m < 8; m++)
	{
		for (h = 0; h < 2 * table_num[m]; h += 2)
		{
			for (j = 0; j < n; j++)
			{
				refresh_1(a, n);
				for (i = 0; i < n; i++)
				{
					b[i][j] = (a[i] >> m) & 1;
				}
			}
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					Temp[0][j] = T[h ^ b[i][j]][j];
					Temp[1][j] = T[(h + 1) ^ b[i][j]][j];
					T[h][j] = Temp[0][j];
					T[h + 1][j] = Temp[1][j];
				}
				refresh_table_1(T[h], T[h+1], n);
				
			}
		}

		for (h = 0; h < table_num[m]; h++)
		{
			for (j = 0; j < n; j++)
			{
				T[h][j] = T[2 * h][j];
			}
			//memcpy(T[h], T[2 * h], n * sizeof(byte));
			refresh_1(T[h], n);
		}
	}

	refresh_1(T[0], n);
	for (i = 0; i < n; i++) a[i] = T[0][i];
}

void lookup_table(byte T[][N], int m, int n, byte *a, byte *b)
{
	byte Tp[K][N];
	int i;

//	printf("%d", m);
	shift_table(T, m, n, a, Tp);
	if (m == 2)
	{
//		refresh(Tp[0], n);
		for (i = 0; i < n; i++)
			b[i] = Tp[0][i];
		return;
	}
	else
	{
		lookup_table(Tp, m/2, n, a, b);
	}
}

void shift_table(byte T[][N], int m, int n, byte *a, byte Tp[][N])
{
	byte Temp[K][N];
	byte b[N][N];
//	byte x[20][20];
	int h, i, j;

	for (h = 0; h < m; h+=2)
	{
		for (j = 0; j < n; j++)
		{
			refresh(a, n);
			for (i = 0; i < n; i++)
			{
				b[i][j] = (a[i] & (K / m)) / (K / m);
			}			
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				Temp[h][j] = T[h ^ b[i][j]][j];
				Temp[h + 1][j] = T[(h + 1) ^ b[i][j]][j];
				T[h][j] = Temp[h][j];
				T[h + 1][j] = Temp[h + 1][j];
			}
			refresh_table(Temp[h], Temp[h + 1], n);
		}
	}

	for (h = 0; h < m / 2; h++)
	{
		memcpy(Tp[h], T[2 * h], n * sizeof(byte));
		refresh(Tp[h], n);
	}
}
