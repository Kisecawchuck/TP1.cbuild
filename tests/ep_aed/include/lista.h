#ifndef LISTA_H
#define LISTA_H

#include "ocorrencia.h"
#include "no.h"

typedef struct {
    No *primeiro;
} Lista;

Lista *cria_lista();
bool insere_lista(Lista *lista, char *s, int l);
void destroi_lista(Lista *lista);
int tamanho(Lista *lista);
No *busca_lista(Lista *lista, char *s);

#endif
