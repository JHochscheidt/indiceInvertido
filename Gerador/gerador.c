/* Matheus Henrique Trichez 
 * Estrutura de Dados II - task of checkpoint 1
 * 
 * Function: file generator. Generates a file with (nonsense) words, and separator chars.
 * p.s: check the args 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "t1lib2.h"

int main(int argc, char **argv){
	if(argc != 6){
		perror("FORMAT INPUT ERROR\n");
		return 1;
	}
	unsigned int SIZE = atoi(argv[1]); 						//file length
	unsigned int NW = atoi(argv[2]);						//number of words which the file will contain
	unsigned int minW = atoi(argv[3]);						//maximum number of letters for all words  
	unsigned int maxW = atoi(argv[4]);						//minimum number of letters for all words 
	unsigned int med = (minW + maxW)/2;						//word length 
	
	if(minW > maxW || minW < 0 || maxW < 0 || SIZE < (NW * med) +NW || !strstr(argv[5], ".txt")){
		perror("INVALID INPUT\n");
		return 1;
	}
	unsigned int n=0;
	unsigned int byteCount = 0;
	unsigned int check=0;
	FILE *f=NULL;
	char *buffer=NULL;
	
	srand(time(NULL));
	f=fopen(argv[5], "w+");							//argv[5] is the name of file to generate
	while(n < NW && f!=NULL){
		if(byteCount + (med + 1)  <= SIZE){
			buffer=getWord(med);	
			byteCount += strlen(buffer);
			fputs(buffer, f);
		}
		n++;
		if(n >= NW){
			check = SIZE - byteCount;
			while(check > 0){
				if(check - 1 >= 0){
					putc(getCharNotAlNum(), f);
					check--;
				}
			}
		}	
	}
	fclose(f);	
	return 0;
}

