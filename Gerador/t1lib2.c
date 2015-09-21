/* Matheus Henrique Trichez
 * Estrutura de Dados II - task 2 of checkpoint 1
 * code library
 */

//-------------------

#include "t1lib2.h"

//------- begin gerador functions ---------

char getCharAlNum(){
	/*function: returns a simple char a-z or A-Z
	 * */
	int x;
	
	do{	
		x=rand() % MAXALNUM;
		if(x>96 || (x>64 && x<91))
			break;
	}while(1);
	
	return (char) x;
}

char getCharNotAlNum(){
	/*function: returns some char of ASCII
	 * */
	
	int x;
	
	x=rand() % MAXNOTALNUM + 1;
	return (char) x;
}

char *getWord(int med){	
		/*param: length of the word 
		 * ------------------------
		 * function: returns a word with some separator char 
		 * in the last byte
		 * */
		int i;
		char *w= (char*) malloc(sizeof(char)*med);
		
		if (med > 1){
			for(i=0; i<(med-1);i++)
				w[i]=getCharAlNum();
			w[med-1]=getCharNotAlNum();
		}else
			w[0]=getCharAlNum();
			
	return w;
}

char *nextCharacter(char *p, int wordLen){
	/* param1: pointer to the first letter of some word in a string/block of memory;
	 * param2: length of that  word/substring 
	 * ------------------------------------------------------
	 * Function: returns a pointer to the first char
	 * after some word(substring), found in the string
	 */
	if(p == NULL || wordLen < 3) return NULL;
	int i=0; 
	
	while(i<wordLen){
		p++;
		i++;
	}
	return p;
}

/*
 ------- end gerador functions -------
 ---------------------------------------
 ------- begin indexador functions --------
*/

FILE *isWord(FILE *f){

	while(isalnum(fgetc(f)))
		f++;
		
	return f;
}

char *cpyWordFile(FILE *f, unsigned int n){
		if(f==NULL) return NULL;
		
		int i;
		char *buff=NULL;	
		buff = (char*) malloc(sizeof(char) * n);

		for(i=0;i < n; i++){
			buff[i]= fgetc(f) ;
			f++;
		}

	return buff;
}

TpList criaLista(){
	TpList *new = (TpList*) malloc(sizeof(TpList));
	return *new;
}

void insert(TpList *l, TpOccurrence *oc){//poe a ocorrencia no nodo
	
	TpNode *pNew = (TpNode*) malloc(sizeof(TpNode));
	if(l->first == NULL){
		l->first = pNew;
		l->last = pNew;
	}else{		
		pNew->occ = *oc;
		l->last->next = pNew;
		l->last = pNew;
	}
	pNew->next = NULL;

}

TpOccurrence *setOccurrence(char *file, unsigned int byte){
	TpOccurrence *pNew = (TpOccurrence *) malloc(sizeof(TpOccurrence));

	strcpy(pNew->arq, file);// **
	pNew->byteOcc = byte;

	return pNew;
}

int ondeInserir(TpList *v[], char *c, int n){
	TpList **vet;
	int i;
	vet=v;
	
	for(i=0;i<n;i++){
		if(strcmp(vet[i]->word, c) > 0)
			break;
	}
	return i;
}

int insertOrdenado(TpList *v[], TpList new, int menma, int tam){// menma: menor inteiro maior q a chave
	TpList **vet;
	int i;
	
	vet=v;
	i=menma;
	while(vet[i] != NULL){// parte do menma e vai até achar um espaço livre no vetor
		i++;
		if(i>tam)
			return i;
	}
	for(;i > menma;i--){//dps de achar um espaço livre no vetor, desloca todos de menma p frente, para a direita 
		vet[i]= vet[i-1];
	}
	vet[i]= &new; // por fim insere entre menma e maior inteiro menor que a chave

	return i;
}

int estaNoCatalogo(TpList *v[],int tam, char *c){//devolve 0 caso esta palavra ainda nao esteja no catalogo, caso ja estiver devolve o indice de onde esta
	int ret = 0;
	TpList **vet;
	int i;
	vet=v;
	
	for(i=0;i<tam;i++){
		if(!strcmp(vet[i]->word,c))
			ret = i;
			break;
	}
	return ret;
}

//------- end indexador functions ---------
