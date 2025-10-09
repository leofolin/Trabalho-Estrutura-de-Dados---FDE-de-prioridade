#include "generica_FDE.c"

unsigned int insere(info *nodoInfo, desc *p) {
//    if(testaVazia(p)) return 0;

    struct nodo *novoNodo = malloc(sizeof(struct nodo));
    if(novoNodo == NULL) return 0;
    novoNodo->dados = *nodoInfo;

    if(p->frente == NULL && p->cauda == NULL) {
        novoNodo->atras = novoNodo->defronte = NULL;
        p->frente = p->cauda = novoNodo;
        return 1;
    }
    if(novoNodo->dados.ranking < p->cauda->dados.ranking) {
        novoNodo->atras = NULL;
        novoNodo->defronte = p->cauda;
        p->cauda->atras = novoNodo;
        p->cauda = novoNodo;
        return 2;
    }
    if(novoNodo->dados.ranking >= p->frente->dados.ranking) {
        novoNodo->defronte = NULL;
        novoNodo->atras = p->frente;
        p->frente->defronte = novoNodo;
        p->frente = novoNodo;
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
    return i;
}
    
