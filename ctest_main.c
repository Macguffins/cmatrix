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
	graph=init(6);
	set(0,1,&graph);
	set(1,2,&graph);
	set(2,3,&graph);
	set(3,4,&graph);
	set(4,5,&graph);
	set(0,5,&graph);
	printg(&graph);
	printf("%s bipartite\n",isbipart(&graph) == -1?"It's not":"It's");
	return 1;
}
