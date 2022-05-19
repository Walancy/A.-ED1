#include "pilha.h"

#define TAM_INICIAL 5

///////////////////// DADOS //////////////////////

struct pilha
{
    TipoElemento *vetor; // endereço do bloco do vetor

    int tamVetor;      // tamanho do vetor
    int qtdeElementos; // quantidade de elementos da pilha
};

///////////////// IMPLEMENTAÇÃO //////////////////
///////////// Desenvolva as funções //////////////

/////////////////////////////////////// CRIAR PILHA
//// - alocar espaço na memoria
//// - declarar elementos da struct

Pilha *pilha_criar()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));

    p->vetor = (int *)malloc(TAM_INICIAL * sizeof(int));
    p->tamVetor = TAM_INICIAL;
    p->qtdeElementos = 0; // quantidade inicial sempre 0

    return p;
}

/////////////////////////////////////// DESTRUIR PILHA
//// - acessar o endereço
//// - apagar o endereço que contêm a pilha

void pilha_destruir(Pilha **endereco)
{
    Pilha *b = *endereco; // cria uma variavel para acessar o endereço desejado

    free(b->vetor);  // free no endereço do vetor
    b->vetor = NULL; // deixa o espaço vazio

    free(b); // apaga a variavel
    b = NULL;
}

/////////////////////////////////////// EMPILHAR
//// - Inserir o elemento
//// - qtdeElementos ++

bool pilha_empilhar(Pilha *p, TipoElemento elemento)
{

    p->vetor[p->qtdeElementos] = elemento;
    p->qtdeElementos++;

    return true;
}

/////////////////////////////////////// DESEMPILHAR
//// -

bool pilha_desempilhar(Pilha *p, TipoElemento *saida)
{
    for (int i = 0; i < p->qtdeElementos; i++)
    {
        if (i == p->qtdeElementos - 1)
        {
            *saida = p->vetor[i]; // posição a ser desempilhada
            p->vetor[i] = NULL;   // limpa
            p->qtdeElementos--;   // desempilha
        }
    }
}

///////////////////////////////////////IMPRIMIR O TOPO

bool pilha_topo(Pilha *p, TipoElemento *saida)
{
    *saida = p->vetor[p->qtdeElementos - 1];

    return true;
}

///////////////////////////////////////SABER SE A PILHA ESTÁ VAZIA

bool pilha_vazia(Pilha *p)
{
    if (!p->vetor[0])
    {
        return true;
    }
    else
    {
        return false;
    }
}

///////////////////////////////////////IMPRIMIR A PILHA

void pilha_imprimir(Pilha *p)
{

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        printf("%i ", p->vetor[i]);
    }

    printf("\n");
}

///////////////////////////////////////SABER O TAMANHO DA PILHA

int pilha_tamanho(Pilha *p)
{
    return p->qtdeElementos;
}

///////////////////////////////////////CLONAR A PILHA

Pilha *pilha_clone(Pilha *p)
{
    Pilha *aux;
    aux = (Pilha *)malloc(sizeof(Pilha));
    aux->vetor = (int *)malloc(p->tamVetor * sizeof(int));
    aux->qtdeElementos = p->qtdeElementos;

    for (int i = 0; i < p->qtdeElementos; i++)
    {
        aux->vetor[i] = p->vetor[i];
    }

    return aux;
}

///////////////////////////////////////INVERTER A PILHA

void pilha_inverter(Pilha *p)
{
    Pilha *clone;

    clone = pilha_clone(p);

    int j = pilha_tamanho(p) - 1;

    for (int i = 0; i < clone->qtdeElementos; i++)
    {
        p->vetor[i] = clone->vetor[j];

        j--;
    }
}

///////////////////////////////////////EMPILHAR

bool pilha_empilharTodos(Pilha *p, TipoElemento *vetor, int tamVetor)
{
    for (int i = 0; i < tamVetor; i++)
    {
        pilha_empilhar(p, vetor[i]);
    }
}

///////////////////////////////////////TRANSFORMAR A PILHA EM STRING

bool pilha_toString(Pilha *f, char *str)
{
    if (f == NULL)
    {
        return false;
    }

    str[0] = '\0';

    strcat(str, "["); // insere na string o valor passado

    for (int i = 0; i < f->qtdeElementos; i++)
    {
        char casting[50];

        sprintf(casting, "%d", f->vetor[i]);
        strcat(str, casting);

        if (i < (f->qtdeElementos) - 1)
        {
            strcat(str, ",");
        }
    }

    strcat(str, "]\n");

    return true;
}