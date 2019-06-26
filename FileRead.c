#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>


int main(){


    // Declarações:
	bool condition = true, firstTry = true;      // Controla se executa ou sai do programa e "primeira tentativa" para melhor otimização do código
	char teste;                  		             // Testa se executa ou sai do programa
	char sequencia[100];                         // Sequência do arquivo .txt (casos de teste)
	char *deliString = "#", *deliNum = "@";      // Delimitadores constantes da sequência de strings e numérica
	char *sequenciaString, *sequenciaNum;			   // Sequências de strings e numérica
	int sequenciaNumerica;                      // A sequência de números inteiros, convertidos da sequência de caracteres 
	FILE *arquivo;                               // Para abrir o arquivo .txt

	
    // Entrada e Processamento de Dados:
	printf("Deseja listar os parametros lidos do arquivo?\n\n");

	while(condition){

		printf("Digite 's' para a listagem ou 'n' para sair do programa: \n");
		teste = getchar();
		getchar();
		
		 /*  Maneiras de evitar que o enter atrapalhe:
		 
		scanf(" %c", &teste);
		getchar();
        fflush(stdin);                        // Para limpar o Buffer no Windows
        __fpurge(stdin);                      // Para limpar o Buffer no Linux
        
         */

		switch(teste){			       	
			case 's':
				arquivo = fopen("myData.txt", "r");             // Abre o arquivo myData.txt em modo leitura (read) somente se o usuário entrar com 's'. Não há a necessidade de abri-lo caso o usuário digite 'n'.

				if(firstTry == true){           // Depois de uma vez verificado se o arquivo está correto, não há a necessidade de conferir novamente.

					if(arquivo == NULL){              
                		printf("\nNao foi possivel abrir o arquivo. Verifique se ele esta na mesma pasta do programa ou se o nome dele eh o mesmo inserido no programa.\n\n");      // Caso o arquivo não esteja na pasta ou tenha sido nomeado errado.
                		exit(-1);

					}
					else{
               			printf("\nArquivo aberto corretamente.\n");

					}

					firstTry = false;                 // Não é mais a primeira vez

				}

            	printf("\nLista:\n");

            	while(fgets(sequencia, 100, arquivo) != NULL){            // Lê uma linha inteira por vez. Enquanto ainda houver dados (não for == NULL) faz a varredura no arquivo

              	  sequenciaString = strtok(sequencia, deliString);            // A sequência de caracteres (string) será a sequência até encontrar o delimitador constante (nesse caso, "#")
              	  sequenciaNum = strtok (NULL, deliNum);                // A sequência de números será o restante da sequência (NULL) até encontrar o delimitador constante (nesse caso, "@")
              	  sequenciaNumerica = atoi(sequenciaNum);
			  
              	  printf("\nPalavra: %s - Numero: %i\n", sequenciaString, sequenciaNumerica);
        		  
				}

            	printf("\n\nListagem finalizada. Gostaria de listar novamente?\n\n");
        		break;

        	case 'n':
        		condition = false;

            	if(firstTry == false){
              	  fclose(arquivo);                  // Se o usuário digitar 'n' de primeira, não há a necessidade de fechar um arquivo que não foi aberto

				}

            	break;
            
          	default:             // Qualquer outro caso de teste que não seja 's' ou 'n' pede uma opção válida.
            	printf("\nOpcao invalida. Por favor, tente novamente.\n\n");

		}
        
	}
    
    // Saída de Dados:
    printf("\nObrigado por usar o nosso programa!\n");

    return 0;

}
