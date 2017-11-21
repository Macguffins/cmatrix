/*
 * =====================================================================================
 *
 *       Filename:  cmatrix.h
 *
 *    Description:  Header file
 *
 *        Version:  1.0
 *        Created:  2017年11月21日 14时29分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cz (mn), 13613283216@msn.cn
 *        Company:  None
 *
 * =====================================================================================
 */

#ifndef __CMATRIX
#define __CMATRIX

#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<memory.h>

typedef long long s64;
typedef unsigned long long u64;
typedef int s32;
typedef unsigned int u32;
typedef signed long long LL;

struct matrix{
	int row;       //number of rows
	int col;		   //number of cols
	int **mtx;	   //pointer to data
	int type;
	int max;
};

int m_errno;

#define EOVERFLOW -1

int mcreate(int r, int c, struct matrix *m);
void mfree(struct matrix *);
int *mget(int , int , struct matrix *);
void mprint(struct matrix *);
int mproduct(struct matrix *A, struct matrix *B, struct matrix *m);
int mequal(struct matrix *A, struct matrix *B);
int missym(struct matrix *A);
int mplus(struct matrix *A, struct matrix *B, struct matrix *R);
int mjoin(struct matrix *A, struct matrix *B, struct matrix *R);
int mbproduct(struct matrix *A, struct matrix *B, struct matrix *R);

#endif
