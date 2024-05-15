#include <stdio.h>
#include <stdlib.h>

 int qtd_jogadas;
 
char tabela[3][3]= {
		{' ',' ',' '},
		{' ',' ',' '},
		{' ',' ',' '},
	};
void menu(){
	
}
int vencer(char tabela[3][3]){
	

	if(qtd_jogadas == 3){
		
	   for(int i=0; i<3; i++){
		   if(tabela[i][2] == tabela[i][1] and tabela[i][2] == tabela[i][0] and tabela[i][2] != ' '){
			return 1;
			} else if (tabela[2][i] == tabela[1][i] and tabela[2][i] == tabela[0][i] and tabela[2][i] != ' '){
			return 1;
			}
		}
	
	
		if(tabela[0][0] == tabela[1][1] and tabela[1][1] == tabela[2][2] and tabela[2][2] != ' ' ){
		return 1;
		} else if (tabela[0][2] == tabela[1][1] and tabela[0][2] == tabela[2][0] and tabela[2][0] != ' '){
		return 1;
		}
	} else{
		return 0;
	}
}

void imprime_tabela(char tabela[3][3]){
	int d=1;
	
	system("cls");
	
	for(int i=0; i<3; i++){
		printf("	%d  %c | %c | %c \n", d, tabela[i][0], tabela[i][1], tabela[i][2]);
		
		if(i < 2){
			printf("	 ----|---|----\n");
		}
		d++;
	}
	printf("\n\n");
}


void code(){
	int coluna, linha;
	int jogador;
	int i=0;


	do{
		jogador = i%2;
		if(jogador == 0 ){
			printf(" jogador 1 faça sua jogada linha 1 3 coluna 1 3 ! ");
		} else{
			printf(" jogador 2 faça sua jogada linha 1 3 coluna 1 3 ! ");
		}
		
		scanf("%d %d", &linha, &coluna);
		if(jogador == 0){
			imprime_tabela(tabela);
		}
		
		linha--;
		coluna--;
		
		
        if (linha < 0 or linha > 2 or coluna < 0 or coluna > 2 or tabela[linha][coluna] != ' ') {
            printf("Posição incorreta !\n");
        }
		if(i%2 == 0 ){
			tabela[linha][coluna] = 'X';
			imprime_tabela(tabela);
			qtd_jogadas++;
		} else{
			tabela[linha][coluna] = 'O';
			imprime_tabela(tabela);
		}
	 i++;	
	
	}while( i<9 and vencer(tabela) == 0   );
	
	if(vencer(tabela)){
		printf("Parabéns jogador %d Você ganhou", i%2);
	} else {
		printf("Empate !");
	}
}




int main (){
	imprime_tabela(tabela);
	code();
}
