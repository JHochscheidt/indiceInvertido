#include "indice_invertido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	int i;
	//for(i = 0; i < argc; i++) printf("argv[%d] %s\n", i, argv[i]);
	
	FILE *arq = NULL;
	char *buffer;
	// lendo arquivo entrada
	for(i = 1; i < argc; i++){
		arq = fopen(argv[i], "r");
		if(!arq){
			printf("arquivo %s não existe\n", argv[i]);
			return 0;
		}else{
			buffer = (char*) malloc(sizeof(char));
			fgets(buffer, 100,arq); // para pegar a primeira linha do arquivo ( quant Arquivos )
			int quantArquivos = atoi(buffer);
			int j;
			FILE *testeArq;
			for(j = 0; j < quantArquivos; j++){
				fgets(buffer, 100,arq);
				//puts(buffer);
				int tamBuffer = strlen(buffer);
				//printf("%d\n", tamBuffer);
				// gambiarra
				char *aux = (char*) malloc (sizeof(char));
				strncpy(aux, buffer, tamBuffer-1);
				tamBuffer = strlen(aux);
				//printf("%d\n", tamBuffer);
				// fim gambiarra	
				testeArq = fopen(aux, "r");
				// verificacao se arquivo existe
				if(!testeArq){
					printf("Arquivo %s nao existe!!!\n", aux);
					return 0;
				}
				//printf("Arquivo %s existe!!!\n", aux);
				fclose(testeArq);
			}		
			// apenas para verificar se os parametros estao corretos
			if(fgets(buffer, 100,arq)){
				printf("\nNumero de arquivos diferente que o numero passado por parametro!!!\n");
				return 0;
			}
			fclose(arq);
		}
	}

return 0;
}
