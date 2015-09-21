#include "indice_invertido.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	
	char **arquivos; // para armazenar o nome dos arquivos
	
	int op;
	do{
		menu();
		scanf("%d", &op);
		switch(op){
			case 0: return 0;
				break;
			case 1: arquivos = verifica_arquivos_entrada(argc,argv);
					if(!arquivos) return 0;
				break;
			case 2 : 
						puts("Nome d arquivo que deseja indexar");//Indexar arquivo
				break;
			case 3 : // adicionar palavra em arquivo
				break;
			
		}		
	}while(op != 0);
	
	
	
	
	
	
	
	
	
	
	
		

return 0;
}
