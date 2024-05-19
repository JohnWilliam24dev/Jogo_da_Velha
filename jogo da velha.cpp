#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>

int qtd_jogadas;
wchar_t tabela[3][3] = {
    { L' ', L' ', L' ' },
    { L' ', L' ', L' ' },
    { L' ', L' ', L' ' },
};

int vencer(wchar_t tabela[3][3]) {
    if (qtd_jogadas >= 5) {
        for (int i = 0; i < 3; i++) {
            if (tabela[i][0] == tabela[i][1] && tabela[i][1] == tabela[i][2] && tabela[i][0] != L' ') {
                return 1;
            } else if (tabela[0][i] == tabela[1][i] && tabela[1][i] == tabela[2][i] && tabela[0][i] != L' ') {
                return 1;
            }
        }

        if ((tabela[0][0] == tabela[1][1] && tabela[1][1] == tabela[2][2] && tabela[0][0] != L' ') ||
            (tabela[0][2] == tabela[1][1] && tabela[1][1] == tabela[2][0] && tabela[0][2] != L' ')) {
            return 1;
        }
    }

    if (qtd_jogadas == 8) {
        return 2;
    }

    return 0;
}

void imprime_tabela(wchar_t tabela[3][3]) {
    int d = 1;
    system("cls");

    for (int i = 0; i < 3; i++) {
        wprintf(L" %d %lc | %lc | %lc \n", d, tabela[i][0], tabela[i][1], tabela[i][2]);
        if (i < 2) {
            wprintf(L" ----|---|----\n");
        }
        d++;
    }
    wprintf(L"\n\n");
}

void desejaContinuar() {
    char jogarDeNovo;

    while (true) {
        wprintf(L"Deseja jogar novamente? S/N\n");
        scanf(" %c", &jogarDeNovo);
        fflush(stdin);

        if (jogarDeNovo == 'S' || jogarDeNovo == 's') {
            printf("Você escolheu jogar novamente.\n");
            qtd_jogadas = 0;
            memset(tabela, L' ', sizeof(tabela));
            break;
        } else if (jogarDeNovo == 'N' || jogarDeNovo == 'n') {
            system("cls");
            exit(0);
            break;
        } else {
            printf("Opção inválida, por favor escolha uma opção entre S e N.\n");
        }
    }
    system("cls");
}

void botMove(wchar_t tabela[3][3]) {
    int x, y;
    do {
        x = rand() % 3;
        y = rand() % 3;
    } while (tabela[x][y] != L' ');

    tabela[x][y] = L'O';
    printf("Bot (O) fez sua jogada na posição (%d-%d)\n", x + 1, y + 1);
    getchar();
}

void code(bool contraBot) {
    int jogador;
    int i = 0;
    char validarJogada[4];
    int coluna, linha;

    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios

    do {
        jogador = i % 2;
        if (jogador == 0 || (jogador == 1 && !contraBot)) {
            if (jogador == 0) {
                printf("Jogador 1, faça sua jogada (linha-coluna, 1-1): \n");
            } else {
                printf("Jogador 2, faça sua jogada (linha-coluna, 1-1): \n");
            }
            scanf("%s", validarJogada);
            fflush(stdin);

            if (isdigit(validarJogada[0]) && validarJogada[1] == '-' && isdigit(validarJogada[2])) {
                sscanf(validarJogada, "%d-%d", &linha, &coluna);
                linha--;
                coluna--;

                if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 || tabela[linha][coluna] != L' ') {
                    printf("Jogada inválida!\n\n");
                    getchar();
                    system("cls");
                    imprime_tabela(tabela);
                } else {
                    tabela[linha][coluna] = (jogador == 0) ? L'X' : L'O';
                    imprime_tabela(tabela);
                    qtd_jogadas++;
                    if (vencer(tabela) == 0) {
                        i++;
                    }
                }
            } else {
                system("cls");
                imprime_tabela(tabela);
            }
        } else {
            printf("Jogador 2 (Bot) está fazendo sua jogada...\n");
            botMove(tabela);
            imprime_tabela(tabela);
            qtd_jogadas++;
            if (vencer(tabela) == 0) {
                i++;
            }
        }
    } while (qtd_jogadas < 9 && vencer(tabela) == 0);

    int resultado = vencer(tabela);
    if (resultado == 1) {
        printf("Parabéns, Jogador %d, você ganhou!\n", i % 2 + 1);
    } else if (resultado == 2) {
        wprintf(L"Empate!\n");
    }

    desejaContinuar();
}

void credito() {
    printf("\n");
    printf("* Créditos: *\n");
    printf("\n");
    printf("* - Pedro Ferreira *\n");
    printf("* - João Saturino *\n");
    printf("* - Daniel Santos *\n");
    printf("* - Matheus Alcantara *\n");
    printf("* - Sayd Aires *\n");
    printf("\n");
    getchar();
}

bool escolha(int opcao) {
    switch (opcao) {
    case 1:
        imprime_tabela(tabela);
        code(false); 
        return true;
    case 2:
        imprime_tabela(tabela);
        code(true); 
        return true;
    case 3:
        credito();
        system("cls");
        return true;
    case 4:
        wprintf(L"Saindo do jogo...\n");
        getchar();
        return false;
    default:
        printf("Opção inválida, tente novamente!\n");
        getchar();
        system("cls");
        return true;
    }
}

bool verifOpcao(char* entradaOpcao) {
    if (isdigit(*entradaOpcao)) {
        int opcao = atoi(entradaOpcao);
        system("cls");
        return escolha(opcao);
    } else {
        printf("Opção inválida, tente novamente somente com números inteiros.\n");
        getchar();
        system("cls");
        return true;
    }
}

bool menu() {
    char entradaOpcao;

    printf("*\n");
    printf("* Menu: *\n");
    printf("*\n");
    printf("* 1. Começar o jogo (Dois jogadores) *\n");
    printf("* 2. Começar o jogo (Jogar contra bot) *\n");
    printf("* 3. Créditos *\n");
    printf("* 4. Sair *\n");
    printf("*\n");
    scanf(" %c", &entradaOpcao);
    fflush(stdin);

    system("cls");

    return verifOpcao(&entradaOpcao);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    bool continuar = true;
    do {
        continuar = menu();
    } while (continuar);

    return 0;
}
