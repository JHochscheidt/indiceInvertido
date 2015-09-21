gerador: programa não-interativo por linha de comando.
	compilar:  gcc gerador.c t1lib.c t1lib.h -o gerador -Wall -pedantic -std=c99
	executar: ./gerador tamanhoDoArquivo numeroDePalavras minimoDeLetras maximoDeLetras nome_do_arquivo.txt
	p.s: o arquivo precisa ser do tipo '.txt'; 
	    para o funcionamento do programa é necessário compilar a biblioteca t1lib tal como mostra o exemplo na linha 'compilar';
	

