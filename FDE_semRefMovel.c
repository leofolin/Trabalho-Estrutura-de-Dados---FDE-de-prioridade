#include "arq.h"

unsigned int insere(info *nodoInfo, desc *p) {
    struct nodo *novoNodo = malloc(sizeof(struct nodo));
    if(novoNodo == NULL) return 0;
    memcpy(&(novoNodo->dados), nodoInfo, p->tamInfo);

    if(p->frente == NULL && p->cauda == NULL) {
        novoNodo->atras = novoNodo->defronte = NULL;
        p->frente = p->cauda = novoNodo;
        free(novoNodo);
        return 1;
    }
    if(novoNodo->dados.ranking < p->cauda->dados.ranking) {
        novoNodo->atras = NULL;
        novoNodo->defronte = p->cauda;
        p->cauda->atras = novoNodo;
        p->cauda = novoNodo;
        free(novoNodo);
        return 2;
    }
    if(novoNodo->dados.ranking >= p->frente->dados.ranking) {
        novoNodo->defronte = NULL;
        novoNodo->atras = p->frente;
        p->frente->defronte = novoNodo;
        p->frente = novoNodo;
        free(novoNodo);
        return 3;
    }

    struct nodo *aux = p->cauda;
    unsigned int i;
    for(i = 3; novoNodo->dados.ranking >= aux->dados.ranking; i++) {
        aux = aux->defronte;
    }
    novoNodo->atras = aux->atras;
    novoNodo->defronte = aux;
    aux->atras->defronte = novoNodo;
    aux->atras = novoNodo;
    free(novoNodo);
    return i;
}

