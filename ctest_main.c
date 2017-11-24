/*
 * =====================================================================================
 *
 *       Filename:  ctest_main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年11月24日 14时18分11秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cz (mn), 13613283216@msn.cn
 *        Company:  None
 *
 * =====================================================================================
 */

#include"ctest.h"

int main(){
	int i;
	struct mgraph graph;
	graph=init(5);
	for(i=0;i<5;++i){
		set(i,i,&graph);
	}
	printg(&graph);
	return 1;
}
