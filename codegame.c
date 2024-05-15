#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include "global.c"
#include "tabelas.c"



void desejaContinuar() {
    char jogarDeNovo;

    
        wprintf(L"Deseja jogar novamente? S/N\n");
        scanf(" %c", &jogarDeNovo);
        fflush(stdin);

        if (jogarDeNovo == 'S' || jogarDeNovo == 's') {
            wprintf(L"Você escolheu jogar novamente.\n");
            jogo=true;
            fflush(stdin);
            

        } else if (jogarDeNovo == 'N' || jogarDeNovo == 'n') {
            system("cls");
            jogo=false;
            
        } else {
            wprintf(L"Opção inválida, por favor escolha uma opção entre S e N.\n");
        }
    
    system("cls");
}		  

void code() {
while (jogo==true){
    int jogador;
    int i = 0;
    char validarJogada[4];
    int coluna, linha;
    qtd_jogadas = 0;
    for(int l=0; l<3; l++){
            	for(int c=0; c<3; c++){
            		tabela[l][c] = L' ';
                    fflush(stdin);
				}
			}
    imprime_tabela(tabela);
    do {
        
        jogador = i % 2;
        if (jogador == 0) {
            wprintf(L"Jogador 1, faça sua jogada (linha-coluna, 1-1): \n");
        } else {
            wprintf(L"Jogador 2, faça sua jogada (linha-coluna, 1-1): \n");
        }

        scanf("%s", validarJogada);
        fflush(stdin);

        if (isdigit(validarJogada[0]) && validarJogada[1] == '-' && isdigit(validarJogada[2])) {
            fflush(stdin);
			sscanf(validarJogada, "%d-%d", &linha, &coluna);
            linha--;
            coluna--;

            if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabela[linha][coluna] != L' ') {
                wprintf(L"Jogada inválida!\n\n");
                
                getchar();
                system("cls");

                imprime_tabela(tabela);

            } else {
                if (jogador == 0) {
                    tabela[linha][coluna] = L'X';
                } else {
                    tabela[linha][coluna] = L'O';
                }
                imprime_tabela(tabela);
                qtd_jogadas++;
                if(vencer(tabela)==0){
                    i++;
                }
            }
        } else {
            system("cls");
             imprime_tabela(tabela);
        }
    } while (qtd_jogadas < 9 && vencer(tabela) == 0);

    int resultado = vencer(tabela);
    if (resultado == 1) {
        wprintf(L"Parabéns, Jogador %d, você ganhou!\n", i % 2 + 1);
    } else if (resultado == 2) {
        wprintf(L"Empate!\n");
    } 
	for(int cont=0; cont<3; cont++){
		tabela[cont][0] == L' ';
		tabela[cont][1] == L' ';
		tabela[cont][2] == L' ';
}  
desejaContinuar();
}
    
}
       