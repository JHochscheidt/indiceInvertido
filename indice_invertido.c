#include "indice_invertido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void menu(){
	// menu
	puts(
			"\n###############          MENU         ###############"
			"\n##############                        ###############"
			"\n#####                                           #####"
			"\n#####          0. Sair                          #####"
			"\n#####          1. Verificar arquivos            #####"
			"\n#####          2. Indexar arquivo               #####"
			"\n#####          3. Adicionar palavra em arquivo  #####"
			"\n#####                                           #####"
			"\n##############                        ###############"
			"\n#####################################################\n"
		);
	
	}


char **verifica_arquivos_entrada(int argc, char **argv){
	//for(i = 0; i < argc; i++) printf("argv[%d] %s\n", i, argv[i]);
	FILE *arq = NULL;
	char *buffer;
	// lendo arquivo entrada
	int i;
	for(i = 1; i < argc; i++){
		arq = fopen(argv[i], "r");
		if(!arq){
			printf("arquivo %s não existe\n", argv[i]);
			return NULL;
		}else{
			buffer = (char*) malloc(sizeof(char));
			fgets(buffer, 100,arq); // para pegar a primeira linha do arquivo ( quant Arquivos )
			int quantArquivos = atoi(buffer); // casting do numero de arquivos para um inteiro
			char **arquivos = malloc(sizeof(char) * quantArquivos);
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
					return NULL;
				}
				//printf("Arquivo %s existe!!!\n", aux);
				fclose(testeArq);
				arquivos[j] = aux;
			}		
			
			/* verifica se o vetor possui os nomes dos arquivos
			 * int cont;
			 * for(cont = 0; cont < quantArquivos; cont++){
			 * 	puts(arquivos[cont]);
			 * }
			 */			
			// apenas para verificar se os parametros estao corretos
			if(fgets(buffer, 100,arq)){
				printf("\nNumero de arquivos diferente que o numero passado por parametro!!!\n");
				return NULL;
			}else{
				printf("Arquivo de entrada verificado com sucesso!!!\n");
			}
			fclose(arq);
			return arquivos;
		}
	}
	return NULL;
}


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

