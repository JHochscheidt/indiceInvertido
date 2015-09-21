/* Matheus Henrique Trichez
 * Estrutura de Dados II - task 2 of checkpoint 1
 * prototypes library
 */

#ifndef _T1LIB_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <wchar.h>

#define MAXALNUM 122
#define MAXNOTALNUM 45
#define THEANSWEAR 42
#define WMINLEN 3
#define MAXW 100010
//----------------------
typedef struct _occurrence{
	char *arq;
	unsigned int byteOcc;
	
}TpOccurrence;

typedef struct _node{
	TpOccurrence occ;
	struct _node *next;
}TpNode;

typedef struct _list{
	char *word;
	TpNode *first;
	TpNode *last;
}TpList;

//----------------------
char getCharAlNum();

char getCharNotAlNum();

char *getWord(int med);

char *nextCharacter(char *p, int wordLen);

FILE *isWord(FILE *f);

char *cpyWordFile(FILE *f, unsigned int n);

void insert(TpList *l, TpOccurrence *oc);

TpOccurrence *setOccurrence(char *file, unsigned int byte);

TpList criaLista();

void insert(TpList *l, TpOccurrence *oc);

TpOccurrence *setOccurrence(char *file, unsigned int byte);

int ondeInserir(TpList *v[], char *c, int n);

int insertOrdenado(TpList *v[], TpList new, int menma, int tam);// menma: menor inteiro maior q a chave

int estaNoCatalogo(TpList *v[],int tam, char *c);//devolve 0 caso esta palavra ainda nao esteja no catalogo, caso ja estiver devolve o indice de onde esta


#endif
