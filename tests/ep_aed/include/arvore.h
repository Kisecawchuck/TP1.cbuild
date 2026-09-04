#ifndef ARVORE_H
#define ARVORE_H

#include "ocorrencia.h"
#include "no.h"

typedef struct {
    No *raiz;
} Arvore;

Arvore *cria_arvore();
No *insere_ord_rec(No *raiz, No *novo);
bool insere_ord(Arvore *arvore, char *e, int l);
No *busca_rec(No *no, char *e);
No *busca_arvore(Arvore *arvore, char *e);
int contar_rec(No *no);
int contar(Arvore *arvore);
int max(int a, int b);
int altura(No *no);
void destroi_arvore_rec(No *no);
void destroi_arvore(Arvore *arvore);
void adiciona_linha( No *no, int linha);

#endif
