/*
*
*   Desenvolvido por Victor Hugo Braguim Canto
*
*/
#include <stdio.h>
#include <stdlib.h>

struct TipoLista{
	struct TipoLista *prox;
	int k;
};
typedef struct TipoLista TipoLista;

struct TipoHash{
	TipoLista *primeiro;
};
typedef struct TipoHash TipoHash;

TipoHash *alocaHash(int M){
	int i=0;
	TipoHash *v = (TipoHash *)(malloc(sizeof(TipoHash)*M));
	while(i<M){
		(v[i].primeiro) = NULL;
		i++;
	}
	return v;
}
void alocaNoHash(TipoHash *v, int mod, int dado){
	TipoLista *p;
	if((v[mod].primeiro)==NULL){
		(v[mod].primeiro) = (TipoLista *)(malloc(sizeof(TipoLista)));
		((v[mod].primeiro)->k) = dado;
	}
	else{
		p = (v[mod].primeiro);
		while((p->prox)!=NULL){
			p = p->prox;
		}
		(p->prox) = (TipoLista *)(malloc(sizeof(TipoLista)));
		p = p->prox;
		(p->k) = dado;
	}
}
void imprimeLista(TipoLista *p){
	TipoLista *aux = p;
	while(aux!=NULL){
		printf("%d -> ", (aux->k));
		aux = aux->prox;
	}

}
void imprimeHash(TipoHash *v, int M){
	int i;
	while(i<M){
		printf("%d -> ", i);
		imprimeLista(v[i].primeiro);
		printf("\\\n");
		i++;
	}
}

int main(void)
{
	int N, i=0, M, C, dado, mod, j=0;
	TipoHash *v;
	scanf("%d", &N);
	while(i<N){
		scanf("%d %d", &M, &C);
		v = alocaHash(M);
		while(j<C){
			scanf("%d", &dado);
			mod = dado % M;
			alocaNoHash(v,mod,dado);
			j++;
		}
		j=0;
		imprimeHash(v,M);
		if(i!=(N-1))
			printf("\n");
		i++;
	}
	return 0;
}
