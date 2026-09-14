#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lista.h"

Lista *cria_lista() {
    Lista *p = malloc(sizeof(Lista));
    p->primeiro = NULL;
    return p;
}

No *busca_lista(Lista *lista, char *s) {
    No *p = lista->primeiro;
    while (p) {
        if (strcasecmp(p->palavra, s) == 0) return p;
        p = p->proximo;
    }
    return NULL;
}

void adiciona_linha_nodo(No *nodo, int linha) {
    Ocorrencia *novo = malloc(sizeof(Ocorrencia));
    if (!novo) return;
    novo->linha = linha;
    novo->proximo = NULL;

    if (!nodo->ocorrencias)
        nodo->ocorrencias = novo;
    else {
        Ocorrencia *p = nodo->ocorrencias;
        Ocorrencia *tmp;
        while (p) {
            if (p->linha == linha) {
                nodo->n++;
                free(novo);
                return;
            }
            tmp = p;
            p = p->proximo;
        }
        tmp->proximo = novo;
        nodo->n++;
    }
}

bool insere_lista(Lista *lista, char *s, int l) {
    No *p = busca_lista(lista, s);
    if (p) {
        adiciona_linha_nodo(p, l);
        return false;
    }

    No *novo = malloc(sizeof(No));
    if (!novo) return false;

    novo->proximo = NULL;
    novo->ocorrencias = NULL;
    novo->n = 1;
    strcpy(novo->palavra, s);
    adiciona_linha_nodo(novo, l);

    if (!lista->primeiro) {
        lista->primeiro = novo;
    } else {
        No *q = lista->primeiro;
        while (q->proximo)
            q = q->proximo;
        q->proximo = novo;
    }
    return true;
}

int tamanho(Lista *lista) {
    No *p = lista->primeiro;
    int n = 0;
    while (p) {
        n++;
        p = p->proximo;
    }
    return n;
}

void destroi_lista(Lista *lista) {
    No *p = lista->primeiro;
    No *tmp;
    while (p) {
        tmp = p;
        p = p->proximo;

        destroi_ocorrencias(tmp->ocorrencias);
        free(tmp);
    }
}
