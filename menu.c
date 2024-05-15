#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "codegame.c"

void credito() {
    wprintf(L"******************************\n");
    wprintf(L"*          Créditos:          *\n");
    wprintf(L"******************************\n");
    wprintf(L"*  - Pedro Ferreira           *\n");
    wprintf(L"*  - João Saturino            *\n");
    wprintf(L"*  - Daniel Santos            *\n");
    wprintf(L"*  - Matheus                  *\n");
    wprintf(L"*  - Sayd Aires               *\n");
    wprintf(L"******************************\n");

    getchar();
}

bool escolha(int opcao) {
    switch (opcao) {
    case 1:
        jogo=true;
        imprime_tabela(tabela);   
        code();
        return true;
    case 2:
        credito();
        system("cls");
        return true;
    case 3:
        wprintf(L"Saindo do jogo...\n");
        getchar();
        return false;
    default:
        wprintf(L"Opção inválida, tente novamente!\n");
        getchar();
        system("cls");
        return true;
    }
}

bool verifOpcao(char* entradaOpcao) {
    if (isdigit(*entradaOpcao)) {
        int opcao = atoi(entradaOpcao);
        system("cls");
        escolha(opcao);
    } else {
        wprintf(L"Opção inválida, tente novamente somente com números inteiros.\n");
        getchar();
        system("cls");
        return true;
    }
}

bool menu() {
    char entradaOpcao;

    wprintf(L"*****************************\n");
    wprintf(L"*          Menu:            *\n");
    wprintf(L"*****************************\n");
    wprintf(L"*  1. Começar o jogo        *\n");
    wprintf(L"*  2. Créditos              *\n");
    wprintf(L"*  3. Sair                  *\n");
    wprintf(L"*****************************\n");
    scanf(" %c", &entradaOpcao);
    fflush(stdin);

    system("cls");

    return verifOpcao(&entradaOpcao);
}