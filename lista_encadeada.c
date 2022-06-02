#include "lista.h"
#include <string.h>

////////////// ESPECIFICAÇÃO DOS DADOS

typedef struct no
{
    TipoElemento dado;
    struct no *ant;
    struct no *prox;
} No;

struct lista
{
    No *inicio;
    No *fim;
    int qtde;
};

////////////// FUNÇÕES AUXILIARES

No *criaNo(TipoElemento elemento)
{
    No *N = (No *)malloc(sizeof(No));

    N->ant = NULL;
    N->prox = NULL;
    N->dado = elemento;

    return N;
}

////////////// DESENVOLVIMENTO

Lista *lista_criar()
{
    Lista *cria = (Lista *)malloc(sizeof(Lista));

    cria->fim = NULL;
    cria->inicio = NULL;
    cria->qtde = 0;
    return cria;
}
void lista_destruir(Lista **endLista)
{
    Lista *l = *endLista;

    No *avanca = l->inicio;
    No *aux = l->inicio->prox;

    while (avanca != NULL)
    {
        free(avanca);
        avanca = aux;
        aux = avanca->prox;
    }
    free(l);
}
bool lista_anexar(Lista *l, TipoElemento elemento)
{
    No *novoNo = criaNo(elemento);

    if (l->inicio == NULL)
    {
        l->inicio = novoNo;
    }
    else
    {
        l->fim->prox = novoNo;
    }

    l->fim = novoNo;
    l->qtde++;

    return true;
}
bool lista_inserir(Lista *l, TipoElemento elemento, int posicao)
{
    No *novoNo = criaNo(elemento);

    if (l->fim == NULL)
    {
        l->fim = novoNo;
    }
}
bool lista_removerPosicao(Lista *l, int posicao, TipoElemento *endereco);
int lista_removerElemento(Lista *l, TipoElemento elemento);
bool lista_substituir(Lista *l, int posicao, TipoElemento novoElemento);
bool lista_vazia(Lista *l);
int lista_posicao(Lista *l, TipoElemento elemento);
bool lista_buscar(Lista *l, int posicao, TipoElemento *endereco);
bool lista_contem(Lista *l, TipoElemento elemento);
int lista_tamanho(Lista *l);
bool lista_toString(Lista *l, char *str);
void lista_imprimir(Lista *l);
