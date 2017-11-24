/*
 * =====================================================================================
 *
 *       Filename:  ctest.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年11月24日 14时12分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cz (mn), 13613283216@msn.cn
 *        Company:  None
 *
 * =====================================================================================
 */

#include"ctest.h"

void test1(){
	int i,j;
	int *ptr = malloc(sizeof(int)*5*5);
	int (*sptr)[][5];
	for(i=0;i!=5*5;++i){
		*ptr++=i;
	}
	sptr=&ptr;
	for(i=0;i!=5;++i){
		for(j=0;j!=5;++j){
			printf("%d ",sptr[i][j]);
		}
		printf("\n");
	}
	return ;
}
