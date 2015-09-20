#include "indice_invertido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ler_arquivo(FILE *arq){
	char c;
	while(c != EOF){
		c = getc(arq);
		printf("%c", c);
	}
}

FILE* gerar_texto(char* nome_arquivo, char* diretorio){
	char* caminho = strcat(diretorio,nome_arquivo);
	FILE *arq;
	arq = fopen(caminho,"r");
	return arq;
}

