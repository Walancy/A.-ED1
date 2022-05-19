#include "pilha.h"

///////////////////// DADOS //////////////////////

#define TAM_INICIAL 5 // tamanho do vetor

struct pilha
{
    TipoElemento *vetor;
    int tamVetor;
    int qtdeElementos;
};

///////////////// IMPLEMENTAÇÃO //////////////////

////////////// FUNÇÕES AUXILIARES ////////////////

bool pilha_cheia(Pilha *p)
{
    if (p->tamVetor == TAM_INICIAL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool pilha_vazia(Pilha *p)
{
    if (p->tamVetor == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/////////////////// FUNÇÕES //////////////////////

Pilha *pilha_criar()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    p->vetor = (int *)malloc(TAM_INICIAL * sizeof(int));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0;

    return p;
}

void pilha_destruir(Pilha **endereco)
{
    Pilha *dell = *endereco;

    free(dell->vetor);
    dell->vetor = NULL;

    free(dell);
    dell = NULL;
}

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{
    if (pilha_cheia)
    {
        return false;
    }
    else
    {
        p->vetor[p->qtdeElementos] = elemento;
        p->qtdeElementos++;
        return true;
    }
    
}

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
    if (pilha_vazia)
    {
        return false;
    }
    else
    {
        
    }
    

}
bool pilha_topo(Pilha *p, TipoElemento *saida)
{

    if (p->vetor[p->qtdeElementos] == -1)
    {
        return true;
    }

    return false;
}
bool pilha_vazia(Pilha *p)
{
    if (p->vetor[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}
void pilha_imprimir(Pilha *p)
{
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        printf("%d \n", p->vetor[i]);
    }
}
int pilha_tamanho(Pilha *p)
{
    p->qtdeElementos;

    return p;
}
Pilha *pilha_clone(Pilha *p)
{
    Pilha *Clone = (Pilha *)malloc(sizeof(Pilha));
    Clone->vetor = (int *)malloc(Clone->tamVetor * sizeof(int));
    Clone->qtdeElementos = p->qtdeElementos;

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        Clone->vetor[i] = p->vetor[i];
    }

    return Clone;
}
void pilha_inverter(Pilha *p)
{
}
bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor);
bool pilha_toString(Pilha *f, char *str);
