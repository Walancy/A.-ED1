#include <stdio.h>
#include "pilha.h"

int main()
{
    Pilha *p1 = pilha_criar();

    pilha_criar(p1, 1);
    pilha_criar(p1, 2);
    pilha_criar(p1, 3);
    pilha_criar(p1, 4);
    pilha_criar(p1, 5);

    pilha_imprimir(p1);
}