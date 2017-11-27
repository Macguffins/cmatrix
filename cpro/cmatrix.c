/*
 * =====================================================================================
 *
 *       Filename:  cmatrix.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年11月21日 18时54分24秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cz (mn), 13613283216@msn.cn
 *        Company:  None
 *
 * =====================================================================================
 */

#include"cmatrix.h"

#define err_quit(fmt,args...) \
				do{										\
					printf(fmt, ##args);  \
					exit(0);						\
				}while(0);


inline void* Malloc(size_t sz){
	void *ptr;
	if((ptr = malloc(sz))==NULL){
		err_quit("malloc err!!\n");
	}
	return ptr;
}

void mfree(struct matrix* A){
	int i;
	if(A!= NULL){
		for(i=0;i!=A->row;++i){
			free(*(A->mtx+i));
			*(A->mtx+i)=NULL;
		}
		free(A->mtx);
		A->mtx=NULL;
	}
}

int mproduct(struct matrix *A, struct matrix *B, struct matrix *m){
	int **ptr, i, j, k, sum=0;
	if(A->col != B->row){
		m_errno=-2;
		return 1;
	}
	mfree(m);
	m=Malloc(sizeof(struct matrix)); 
	m->row=A->row,m->col=B->col;
	m->mtx=Malloc(sizeof(int*)*A->row);
	for(i=0;i!=B->col;++i){
		*(m->mtx+i)=Malloc(sizeof(int)*B->col);
	}
	ptr=m->mtx;
	for(i=0;i!=A->row;++i){
		for(j=0;j!=B->col;++j){
			for(k=0;k!=A->col;++k){
				sum+=(*(*(A->mtx+i)+k))*(*(*(B->mtx+k)+j));
			}
			*(j+*(ptr+i))=sum;
			sum=0;
		}
	}
	return 1;

}

int mequal(struct matrix *A, struct matrix *B){
	int i,j;
	if(A==NULL || B==NULL){
		m_errno = -3;
		return -3;
	}else if(A->row!= B->row|| A->col != B-> col){
		m_errno = -4;
		return -4;
	}
	for(i=0;i!=A->row;++i){
		for(j=0;j!=B->col;++j){
			if(*(*(A->mtx+i)+j) != *(*(B->mtx+i)+j)){
				return 0;
			}
		}
	}
	return 1;
}

int missym(struct matrix *A){
	int i,j, **m = A->mtx;
	if(A==NULL){
		return -1;
	}
	for(i=0;i!=A->row;++i){
		for(j=i;j!=A->col;++j){
			if(*(*(m+i)+j) != *(*(m+j)+i)){
				return 0;
			}
		}
	}
	return 1;
}

int mplus(struct matrix *A, struct matrix *B, struct matrix *R){
	int i,j;
	if(A->row != B->row || A->col != B->col){
		return 0;
	}
	mfree(R);
	R->row=A->row,R->col=A->col;
	R->mtx=Malloc(sizeof(int*)*A->row);
	for(i=0;i!=A->row;++i){
		*(R->mtx+i)=Malloc(sizeof(int)*R->col);
	}
	for(i=0;i!=R->row;++i){
		for(j=0;j!=R->col;++j){
			*(*(R->mtx+i)+j)=*(*(A->mtx+i)+j)+*(*(B->mtx+i)+j);
		}
	}
	return 1;
}

int mjoin(struct matrix *A, struct matrix *B, struct matrix *R){
	int i,j;
	if(A->row != B->row || A->col != B->col){
		return 0;
	}
	mfree(R);
	R->row=A->row,R->col=A->col;
	R->mtx=Malloc(sizeof(int*)*A->row);
	for(i=0;i!=A->row;++i){
		*(R->mtx+i)=Malloc(sizeof(int)*R->col);
	}
	for(i=0;i!=R->row;++i){
		for(j=0;j!=R->col;++j){
			*(*(R->mtx+i)+j)=*(*(A->mtx+i)+j)+*(*(B->mtx+i)+j)?1:0;
		}
	}
	return 1;
}

int mbproduct(struct matrix *A, struct matrix *B, struct matrix *R){
	int i,j,k,b=0;
	if(A->col != B->row){
		return -1;
	}
	mfree(R);
	R->mtx=Malloc(sizeof(int *)*A->row);
	for(i=0;i!=A->row;++i){
		*(R->mtx+i)=Malloc(sizeof(int)*B->col);
	}
	R->row=A->row,R->col=B->col;
	for(i=0;i!=R->row;++i){
		for(j=0;j!=R->col;++j){
			for(k=0;k!=A->col;++k){
				b|=*(*(A->mtx+i)+k)&&*(*(B->mtx+k)+j)?1:0;
			}
			*(*(R->mtx+i)+j)=b?1:0;
			b=0x00;
		}
	}
	return 0;
}

int *mget(int i, int j, struct matrix *A ){
	return *(A->mtx+i)+j;
}

int mcreate(int r, int c, struct matrix *m){
	int i;
	if(m == NULL){
		m=Malloc(sizeof(struct matrix));
	}
	memset(m, 0x00, sizeof(struct matrix));
	m->row=r,m->col=c;
	m->mtx=Malloc(sizeof(int*)*r);
	for(i=0;i!=r;++i){
		*(m->mtx+i)=Malloc(sizeof(int)*c);
		memset(*(m->mtx+i),0x00,sizeof(int)*c);
	}
	return r*c*sizeof(int);
		
}

void mprint(struct matrix *m){
	int i,j;
	if(m==NULL){
		return ;
	}
	for(i=0;i!=m->row;++i){
		for(j=0;j!=m->col;++j){
			printf("%-3d ",*(*(m->mtx+i)+j));
		}
		printf("\n");
	}
}

void minverse(struct matrix *A, struct matrix *R){
	int i,j;
	if(A == NULL){
		return ;
	}
	mfree(R);
	R->col=A->row,R->row=A->col;
	R->mtx=Malloc(sizeof(int *)*R->row);
	for(i=0;i!-R->row;++i){
		*(R->mtx+i)=Malloc(sizeof(int)*R->col);
	}
	for(i=0;i!=R->row;++i){
		for(j=0;j!=R->col;++j){
			*(*(R->mtx+i)+j)=*(*(A->mtx+j)+i);
		}
	}
	return ;
}
