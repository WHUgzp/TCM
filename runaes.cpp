#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "aes.h"
#include "aes_rp.h"
#include "aes_ltable.h"
#include "aes_htable.h"
#include "share.h"
#include "aes_share.h"
#include "common.h"  

void printMes(char *s,byte *m)
{
  printf("%s=",s);
  int i;
  for(i=0;i<16;i++) printf("%02x",m[i]);
  printf("\n");
}

int main()
{
  int n;
  int nt=100;
  int i;
  byte keyex[16]={0x2b,0x7e,0x15,0x16,0x28,0xae,0xd2,0xa6,0xab,0xf7,0x15,0x88,0x09,0xcf,0x4f,0x3c};

//  byte keyex[16] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };

  byte inex[16]={0x32,0x43,0xf6,0xa8,0x88,0x5a,0x30,0x8d,0x31,0x31,0x98,0xa2,0xe0,0x37,0x07,0x34};

  byte outex[16]={0x39,0x25,0x84,0x1d,0x02,0xdc,0x09,0xfb,0xdc,0x11,0x85,0x97,0x19,0x6a,0x0b,0x32};

  byte in[16],out[16];
  byte key[16];

  //printMes("in",inex);
  //printMes("key",keyex);

  for(i=0;i<16;i++) key[i]=keyex[i];
  for(i=0;i<16;i++) in[i]=inex[i];

  int dt,base=1;

  //printf("Without countermeasure, plain: \n");
  //dt=run_aes(in,out,key,nt);
  //base=dt;
  //check_ciphertext(out,outex,16);
  //report_time(dt,nt,base,0);
  /*
  printf("Without countermeasure, RP: ");
  runalgo(&aes_rp,in,out,key,outex,16,nt,base);  
  */

  for(n=2;n<=9;n++)
  {
    printf("n=%d\n",n);

	//if (n == 2 || n == 4 || n == 8)
	//{
	//	printf("  With RP countermeasure: ");
	//	init_randcount();
	//	dt = run_aes_share(in, out, key, n, &subbyte_rp_share, nt);
	//	report_time(dt, nt, base, get_randcount());
	//	check_ciphertext(out, outex, 16);
	//}
    
	

	//printf("  With Coron14 countermeasure : ");
	//init_randcount();
	//dt = run_aes_share(in, out, key, n, &subbyte_htable, nt);
	//report_time(dt, nt, base, get_randcount());
	//check_ciphertext(out, outex, 16);


	printf("  With Coron14 countermeasure-v : ");
	init_randcount();
	dt = run_aes_share(in, out, key, n, &subbyte_htable_word, nt);
	report_time(dt, nt, base, get_randcount());
	check_ciphertext(out, outex, 16);

	printf("  With Coron14-HA countermeasure : ");
	init_randcount();
	dt = run_aes_share(in, out, key, n, &subbyte_ltable, nt);
	report_time(dt, nt, base, get_randcount());
	check_ciphertext(out, outex, 16);

  }
  
  printf("\n");
}


/*
int main()
{
	conf a = {0};
	conf b = { 0 };
	conf c = { 0 };
	randConf(a);
	randConf(b);
	xorConfig(c, a);
	xorConfig(a, b);
	printf("\n");
}
*/



