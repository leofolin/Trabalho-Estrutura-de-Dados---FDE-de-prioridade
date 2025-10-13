#include "arq.h"
// Funções genéricas usadas nas duas implementações de fila

#if REF_MOVEL == 0
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
#elif REF_MOVEL == 1
unsigned int insere(info *nodo, desc *p) {
    return 0;
}
#endif
struct desc *cria(int tam) {
    desc *descricao = malloc(sizeof(desc));
    if(descricao != NULL) {
        descricao->cauda = NULL;
        descricao->frente = NULL;
        descricao->tamInfo = tam;
#if REF_MOVEL
        descricao->refMovel = NULL;
#endif
    }
    return descricao;
}

bool removeFrente(desc *p, info *alvo) {
    if(testaVazia(p)) {
        return false;
    }
    memcpy(alvo, &(p->frente->dados), p->tamInfo);

    struct nodo *aux = p->frente->atras;
    if(aux == p->cauda) {
        p->frente = p->cauda = NULL;
    } else {
        free(p->frente);
        p->frente = aux;
        p->frente->defronte = NULL;
    }
    free(aux);
    return true;
}
unsigned int tamanhoDaFila(desc *p) {
    struct nodo *aux = p->cauda;
    int i = 0;
    while(aux->defronte != NULL) {
        aux = aux->defronte;
        i++;
    }
    return i;
}

bool reinicia(desc *p) {
    if(testaVazia(p)) {
        return false;
    }
    struct nodo *aux = p->cauda->defronte;
    while(aux != NULL) {
        free(p->cauda);
        p->cauda = aux;
        aux = aux->defronte;
    }
    free(p->cauda);
    p->frente = NULL;
    p->cauda = NULL;
    return true;
}

struct desc *destroi(desc *p) {
    reinicia(p);
    free(p);
    return NULL;
}
bool buscaNaCauda(desc *p, info *alvo) {
    if(testaVazia(p)) {
        return false;
    }
    *alvo = p->cauda->dados;
    return true;
}

bool buscaNaFrente(desc *p, info *alvo) {
    if(testaVazia(p)) {
        return false;
    }
    *alvo = p->frente->dados;
    return true;
}
bool testaVazia(desc *p) {
    return p->cauda == NULL || p->frente == NULL;
}

void printaNodo(info dados) {
    printf("Nome: %s, Matrícula: %i, Ranking: %i, Curso: %s"
           ,dados.nome, dados.matricula, dados.ranking, dados.curso);

}

