/* Nome: Lucas Rezende de Paula Silva */

#include <stdio.h>
#include <stdlib.h>

void criaTabuleiro(char tabuleiro[3][3]) { /* Função que cria um tabuleiro vazio */
	
	int i, j;
	
	for (i = 0; i<3; i++){
		for (j = 0; j<3; j++){
			tabuleiro[i][j] = 'V';
		}
	}
	
}


int recebeMatriz(char tabuleiro[3][3], int linha, int coluna, char cod){ /* Função que faz a jogada determinada pelo jogador */

	if(linha<0 || linha>3 || coluna<0 || coluna>3){
		
		printf("\n\nJogada invalida!");
		return 0;
		
	} else{
		
		if(tabuleiro[linha][coluna]=='V'){
		
		tabuleiro[linha][coluna] = cod;
		return 1;
		
	} else {
		
		printf("\n\nJogada invalida!");
		return 0;
		
	}
	
	}
	
}


int verifEstadoJogo(char tabuleiro[3][3]){ /* Função que verifica o estado do jogo */
	
	int i, j;
	int cont = 0;
	
	if (tabuleiro[0][0] == 'O' && tabuleiro[0][1] == 'O' && tabuleiro[0][2] == 'O'){
		return 1;
	}
	else if(tabuleiro[0][0] == 'X' && tabuleiro[0][1] == 'X' && tabuleiro[0][2] == 'X'){
		return 2;
	}
	else if(tabuleiro[1][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[1][2] == 'O'){
		return 1;
	}
	else if(tabuleiro[1][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[1][2] == 'X'){
		return 2;
	}
	else if(tabuleiro[2][0] == 'O' && tabuleiro[2][1] == 'O' && tabuleiro[2][2] == 'O'){
		return 1;
	}
	else if(tabuleiro[2][0] == 'X' && tabuleiro[2][1] == 'X' && tabuleiro[2][2] == 'X'){
		return 2;
	}
	else if(tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O'){
		return 1;
	}
	else if(tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X'){
		return 2;
	}
	else if(tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O'){
		return 1;
	}
	else if(tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X'){
		return 2;
	}
	else if(tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O'){
		return 1;
	}
	else if(tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X'){
		return 2;
	}
	else if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
		return 1;
	}
	else if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
		return 2;
	}
	else if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'){
		return 1;
	}
	else if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'){
		return 2;
	}
	
	else {
		
		for (i = 0; i<3; i++){
			for (j = 0; j<3; j++){
				if (tabuleiro[i][j] == 'O' || tabuleiro[i][j] == 'X'){
					cont += 1;
				}
			}
		}
		
		if (cont==9){
			return 0;
		} else{
			return -1;
		}
		
	}
	
}


int main (void){ /* Main */
	
	char tabuleiro[3][3]; /* Cria o tabuleiro */
	char cod = 'O'; /* Código do jogador */
	int i, j; /* Iteradores */
	int linha, coluna; /* Linha e coluna do tabuleiro */
	int fimJogo = -1; /* Define se o jogo acabou ou não */
	int jogadaAceita = 0; /* Define se a jogada é aceita ou não */
	
	criaTabuleiro(tabuleiro); /* Cria um tabuleiro vazio */
	
	do{ /* Faça enquanto o jogo não estiver acabado */
	
		for (i = 0; i<3; i++){ /* Imprime o tabuleiro */
			for (j = 0; j<3; j++){
				printf("%c", tabuleiro[i][j]);
			}
			printf("\n");
		}
	
		do { /* Faça enquanto a jogada não for aceita */
			
			printf("\n\nVez do %c ", cod); /* Pede que o usuário informe sua jogada */
			printf("\nEscolha a linha: ");
			scanf("%i", &linha);
			printf("\nEscolha a coluna: ");
			scanf("%i", &coluna);
			printf("\n\n");
			jogadaAceita = recebeMatriz(tabuleiro, linha-1, coluna-1, cod); /* Faz a alteração no tabuleiro */
			
		} while(jogadaAceita == 0);
		
		if (cod == 'O'){ /* Troca a vez do jogador */
			cod = 'X';
		} else{
			cod = 'O';
		}
	
		fimJogo = verifEstadoJogo(tabuleiro); /* Verifica o estado do jogo */
	
	} while(fimJogo == -1);
		
	if (fimJogo == 1){ /* Declara o vencedor */
		for (i = 0; i<3; i++){ /* Imprime o tabuleiro */
			for (j = 0; j<3; j++){
				printf("%c", tabuleiro[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\nO venceu!");
	} else if (fimJogo == 2){
		for (i = 0; i<3; i++){ /* Imprime o tabuleiro */
			for (j = 0; j<3; j++){
				printf("%c", tabuleiro[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\nX venceu!");
	} else{
		for (i = 0; i<3; i++){ /* Imprime o tabuleiro */
			for (j = 0; j<3; j++){
				printf("%c", tabuleiro[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\nEmpate!");
	}
	
	return 0; /* Fim */
	
}

