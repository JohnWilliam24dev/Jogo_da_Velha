#include <locale.h>
#include <stdbool.h>
#include "menu.c"
int main() {
    setlocale(LC_ALL, "Portuguese");
    bool continuar = true;
    do {
        continuar = menu();
    } while (continuar);

    return 0;
}        