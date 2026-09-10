#ifndef NO_H
#define NO_H

#include "ocorrencia.h"

typedef struct _NO {
    char palavra[46];
    int n;
    Ocorrencia *ocorrencias;
    struct _NO *proximo;
    struct _NO *esq;
    struct _NO *dir;
} No;

#endif
