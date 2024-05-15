#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>
#include "global.c"
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

    if (qtd_jogadas == 8){
        return 2; 
    }

    return 0; 
}

void imprime_tabela(wchar_t tabela[3][3]) {
    int d = 1;

    system("cls");

    for (int i = 0; i < 3; i++) {
        wprintf(L"    %d  %lc | %lc | %lc \n", d, tabela[i][0], tabela[i][1], tabela[i][2]);

        if (i < 2) {
            wprintf(L"     ----|---|----\n");
        }
        d++;
    }
    wprintf(L"\n\n");
}