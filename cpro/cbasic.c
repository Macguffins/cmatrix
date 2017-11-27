/*
 * =====================================================================================
 *
 *       Filename:  cbasic.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年11月24日 10时23分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cz (mn), 13613283216@msn.cn
 *        Company:  None
 *
 * =====================================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

typedef unsigned long long u64;
typedef unsigned int u32;

#define NUM 999999ULL

u64 r,a1,a2,b1,b2;
u32 rmask=0x0000FFFF;
u32 lmask=0xFFFF0000;

int main(){
	unsigned int cnt ;
	struct timeval tv1,tv2;
	gettimeofday(&tv1, NULL);
	for(cnt=0;cnt!=100000;++cnt){
		r=NUM*NUM;
	}
	gettimeofday(&tv2, NULL);
	printf("%ld   \n", (tv2.tv_sec-tv1.tv_sec)*1000000+(tv2.tv_usec-tv1.tv_usec));
	gettimeofday(&tv1, NULL);
	for(cnt=0;cnt!=100000;++cnt){
		a1=NUM&rmask,b1=NUM&rmask; 
		a2=(NUM&lmask)>>16,b2=(NUM&lmask)>>16;
		r=a1*b1+(b1*b2<<16)+(a2*b1<<16)+(a2*b2<<32);
	}
	gettimeofday(&tv2, NULL);
	printf("%ld   \n", (tv2.tv_sec-tv1.tv_sec)*1000000+(tv2.tv_usec-tv1.tv_usec));
	return 0;
}
