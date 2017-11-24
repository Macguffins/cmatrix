/*
 * =====================================================================================
 *
 *       Filename:  cgragh.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年11月24日 13时40分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cz (mn), 13613283216@msn.cn
 *        Company:  None
 *
 * =====================================================================================
 */


#include"cgraph.h"

struct mgraph init(size_t size){
	struct mgraph grp;	
	grp.size=size;
	grp.ptr=malloc(sizeof(char)*size*size);
	memset(grp.ptr, 0x00, size*size);
	return grp;
}

void clean(struct mgraph* g){
	free(g->ptr);
	return ;
}

int set(int a, int b, struct mgraph *g){
	if(a>=g->size || b>=g->size){
		return -1;
	}
	*(g->ptr+a*g->size+b)=1; 
	return 0;
}

char get(int a, int b, struct mgraph *g){
	if(a>=g->size || b>=g->size){
		return -1;
	}
	return *(g->ptr+a*g->size+b);
}

int clear(int a, int b, struct mgraph *g){
	if(a>=g->size || b>=g->size){
		return -1;
	}
	*(g->ptr+a*g->size+b)=0; 
	return 0;
}

void printg(struct mgraph *g){
	int i,j;
	for(i=0;i<g->size;i++){
		for(j=0;j<g->size;++j){
			printf("%d ", get(i,j,g));
		}
		printf("\n");
	}

}


int isbipart(struct mgraph *g){
	int *v1,*v2,i,j,k,flag;
	int *ptr1,*ptr2, s1, s2;
	s1=s2=0;
	flag = 0;
	v1=malloc(sizeof(int)*g->size);
	v2=malloc(sizeof(int)*g->size);
	memset(v1,-1,g->size);
	memset(v2,-1,g->size);
	ptr1=v1,ptr2=v2;
	for(i=0;i<g->size;++i){
		if()
	}
	
}

int rtraverse(struct mgrapg *g, int row, int *s1, int *s2, int *ptr1, int *ptr2){
	int i,j;
	for(i=0;i<g->size;++i){
		if(get(row,i,g) == 1){
			clear(row,i,g);
			for(j=0;j<*s1;++j){
				if(*(ptr1+j) == i){
					return -1;
				}
			}
			*(ptr2+*s2)=i;
			++*s2;
		}
	}
	return 0;
}

int ctraverse(struct mgrapg *g, int col, int *s1, int *s2, int *ptr1, int *ptr2){
	int i,j;
	for(i=0;i<g->size;++i){
		if(get(i,col,g) == 1){
			clear(i,col,g);
			for(j=0;j<*s1;++j){
				if(*(ptr1+j) == i){
					return -1;
				}
			}
			*(ptr2+*s2)=i;
			++*s2;
		}
	}
	return 0;
}

