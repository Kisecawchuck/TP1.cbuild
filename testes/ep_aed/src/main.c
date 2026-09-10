#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "../include/arvore.h"
#include "../include/lista.h"

enum { LISTA, ARVORE };

#define MAX_INPUT 100

const char *delimitadores = " -,./!?;\"\'()[]{}/\n";

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <nome_do_arquivo>.txt <tipo_de_índice>\n", argv[0]);
        return 1;
    } 
    printf("Arquivo: \'%s\'\n", argv[1]);
    printf("Tipo de indice: \'%s\'\n", argv[2]);
    FILE *ENTRADA = fopen(argv[1], "r");
    if (!ENTRADA) {
        printf("Erro! Impossível abrir o arquivo de entrada!\n");
        return 2;
    }
    int indice;
    if (strcmp(argv[2], "arvore") == 0) indice = ARVORE;
    else if (strcmp(argv[2], "lista") == 0) indice = LISTA;
    else {
        printf("Erro! Tipo de índice inválido!\n");
        fclose(ENTRADA);
        return 3;
    }
    char *linha = NULL;
    size_t len = 0;
    int lidos;
    char **linhas = NULL;
    int n_linhas = 0;
    while ((lidos = getline(&linha, &len, ENTRADA)) != -1) {
        linhas = realloc(linhas, (n_linhas + 1) * sizeof(char *));
        linhas[n_linhas] = strdup(linha);
        n_linhas++;
    }
    free(linha);
    fclose(ENTRADA);
    Arvore *arvore = NULL;
    Lista *lista = NULL;
    if (indice == ARVORE)
        arvore = cria_arvore();
    else
        lista = cria_lista();
    for (int i = 0; i < n_linhas; i++) {
        char *tmp = strdup(linhas[i]);
        char *token = strtok(tmp, delimitadores);
        while (token) {
            if (indice == ARVORE)
                insere_ord(arvore, token, i);
            else
                insere_lista(lista, token, i);
            token = strtok(NULL, delimitadores);
        }
        free(tmp);
    }
    int n, h;
    if (indice == ARVORE)
        n = contar(arvore);
    else
        n = tamanho(lista);
    printf("Total de palavras unicas indexadas: %05d\n", n);
    printf("Numero de linhas no arquivo: %d\n", n_linhas);
    if (indice == ARVORE) {
        h = altura(arvore->raiz);
        printf("Altura da arvore: %05d\n", h); 
    }
    char opt[MAX_INPUT];
    bool fim = false;
    while (!fim) {
        printf("> ");
        fgets(opt, sizeof(opt), stdin);
        char *cmd;
        if ((cmd = strtok(opt, " \n")) && cmd) {
            if (strcmp(cmd, "fim") == 0) fim = true;
            else if (strcmp(cmd, "busca") == 0) {
                cmd = strtok(NULL, " \n");
                if (!cmd) {
                    printf("Uso: busca <palavra>\n");
                    continue;
                }
                No *p;
                if (indice == ARVORE)
                    p = busca_arvore(arvore, cmd);
                else
                    p = busca_lista(lista, cmd);
                if (p) {
                    printf("Existem %d ocorrências da palavra \'%s\' na(s) seguinte(s) linha(s):\n", p->n, cmd);
                    Ocorrencia *o = p->ocorrencias;
                    while (o) {
                        printf("%05d: %s", o->linha + 1, linhas[o->linha]);
                        o = o->proximo;
                    }
                    if (indice == ARVORE) {
                        printf("Numero de comparacoes: %05d\n", h - altura(p) + 1);
                    } else {
                        No *q = lista->primeiro;
                        int idx;
                        for (idx = 1; strcasecmp(p->palavra, q->palavra) != 0; idx++) q = q->proximo;
                        printf("Numero de comparacoes: %05d\n", idx);
                    }
                } else {
                    printf("Palavra \'%s\' nao encontrada.\n", cmd);
                    int cnt = indice == ARVORE ? h + 1 : n + 1;
                    printf("Numero de comparacoes: %05d\n", cnt);
                }
            } else printf("Opcao invalida!\n");
        }
    }
    if (indice == ARVORE) {
        destroi_arvore(arvore);
        free(arvore);
    }
    else {
        destroi_lista(lista);
        free(lista);
    }
    for (int i = 0; i < n_linhas; i++) free(linhas[i]);
    free(linhas);
    return 0;
}
