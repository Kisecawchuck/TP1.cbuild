#ifndef OCORRENCIA_H
#define OCORRENCIA_H

typedef struct _OCORRENCIA {
    int linha;
    struct _OCORRENCIA *proximo;
} Ocorrencia;

void destroi_ocorrencias(Ocorrencia *o);

#endif
