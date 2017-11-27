/*
 * =====================================================================================
 *
 *       Filename:  cgraph.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年11月24日 13时40分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cz (mn), 13613283216@msn.cn
 *        Company:  None
 *
 * =====================================================================================
 */


#ifndef __CGRAPH
#define __CGRAPH

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<memory.h>

struct mgraph{
	char *ptr;
	int size;
	int (*get)(int, int, struct mgraph *);
};

struct mgraph init(size_t);
void clean(struct mgraph*);
int set(int, int, struct mgraph*);
char get(int , int , struct mgraph*);
int clear(int, int , struct mgraph*);
void printg(struct mgraph*);
int isbipart(struct mgraph *);


#endif
