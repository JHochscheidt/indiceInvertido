#ifndef _INDICE_INVERTIDO_H
#define INDICE_INVERTIDO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0


void menu();

// funcao que guarda o nome dos arquivos a serem processados
char* nomeArquivo();

// funcao que verifica o arquivo de entrada e se os arquivos existem
char **verifica_arquivos_entrada(int argc, char **argv);

void ler_arquivo(FILE *arq);

FILE* gerar_texto(char* nome_arquivo, char* diretorio);







#endif
