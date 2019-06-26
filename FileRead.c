#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>


int main(){


    // Declara��es:
	bool condition = true, firstTry = true;      // Controla se executa ou sai do programa e "primeira tentativa" para melhor otimiza��o do c�digo
	char teste;                  		             // Testa se executa ou sai do programa
	char sequencia[100];                         // Sequ�ncia do arquivo .txt (casos de teste)
	char *deliString = "#", *deliNum = "@";      // Delimitadores constantes da sequ�ncia de strings e num�rica
	char *sequenciaString, *sequenciaNum;			   // Sequ�ncias de strings e num�rica
	int sequenciaNumerica;                      // A sequ�ncia de n�meros inteiros, convertidos da sequ�ncia de caracteres 
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
				arquivo = fopen("myData.txt", "r");             // Abre o arquivo myData.txt em modo leitura (read) somente se o usu�rio entrar com 's'. N�o h� a necessidade de abri-lo caso o usu�rio digite 'n'.

				if(firstTry == true){           // Depois de uma vez verificado se o arquivo est� correto, n�o h� a necessidade de conferir novamente.

					if(arquivo == NULL){              
                		printf("\nNao foi possivel abrir o arquivo. Verifique se ele esta na mesma pasta do programa ou se o nome dele eh o mesmo inserido no programa.\n\n");      // Caso o arquivo n�o esteja na pasta ou tenha sido nomeado errado.
                		exit(-1);

					}
					else{
               			printf("\nArquivo aberto corretamente.\n");

					}

					firstTry = false;                 // N�o � mais a primeira vez

				}

            	printf("\nLista:\n");

            	while(fgets(sequencia, 100, arquivo) != NULL){            // L� uma linha inteira por vez. Enquanto ainda houver dados (n�o for == NULL) faz a varredura no arquivo

              	  sequenciaString = strtok(sequencia, deliString);            // A sequ�ncia de caracteres (string) ser� a sequ�ncia at� encontrar o delimitador constante (nesse caso, "#")
              	  sequenciaNum = strtok (NULL, deliNum);                // A sequ�ncia de n�meros ser� o restante da sequ�ncia (NULL) at� encontrar o delimitador constante (nesse caso, "@")
              	  sequenciaNumerica = atoi(sequenciaNum);
			  
              	  printf("\nPalavra: %s - Numero: %i\n", sequenciaString, sequenciaNumerica);
        		  
				}

            	printf("\n\nListagem finalizada. Gostaria de listar novamente?\n\n");
        		break;

        	case 'n':
        		condition = false;

            	if(firstTry == false){
              	  fclose(arquivo);                  // Se o usu�rio digitar 'n' de primeira, n�o h� a necessidade de fechar um arquivo que n�o foi aberto

				}

            	break;
            
          	default:             // Qualquer outro caso de teste que n�o seja 's' ou 'n' pede uma op��o v�lida.
            	printf("\nOpcao invalida. Por favor, tente novamente.\n\n");

		}
        
	}
    
    // Sa�da de Dados:
    printf("\nObrigado por usar o nosso programa!\n");

    return 0;

}
