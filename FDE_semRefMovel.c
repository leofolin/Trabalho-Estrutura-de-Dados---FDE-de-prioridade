#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "arq.h"

desc *cria(int tam) {
	desc *descricao = malloc(sizeof(desc));
	if(descricao != NULL) {
		descricao->cauda = NULL;
		descricao->frente = NULL;
		descricao->tam = tam;
	}
	return descricao;
}

bool insere(info *nodoInfo, desc *p){

    if (p == NULL || nodoInfo == NULL) return false;

    bool ok = false;
	struct nodo *novoNodo = NULL;
    novoNodo = malloc(sizeof(struct nodo));
    if (novoNodo == NULL) return false;
    memcpy(&(novoNodo->dados), nodoInfo, p->tam);
    if(p->frente == NULL && p->cauda == NULL){ //caso fila vazia
        novoNodo->defronte = NULL;
        novoNodo->atras = NULL;
        p->frente = novoNodo;
        p->cauda = novoNodo;
        ok = true;
    }
    else{
        //verifica se o novo elemento é o de menor prioridade
        //se for, vira a nova cauda
        if(novoNodo->dados.ranking <= p->cauda->dados.ranking){
            novoNodo->atras = NULL;
            novoNodo->defronte = p->cauda;
            p->cauda->atras = novoNodo;
            p->cauda = novoNodo;
            ok = true;
        }
        //verifica se o novo elemento é o de maior prioridade
        //se for, vira a nova frente da fila
        else if(novoNodo->dados.ranking >= p->frente->dados.ranking){
            novoNodo->defronte = NULL;
            novoNodo->atras = p->frente;
            p->frente->atras = novoNodo;
            p->frente = novoNodo;
            ok = true;
        }
        else{ //se nao for maior nem menor, vai estar no meio
            struct nodo *aux = p->cauda;
            //while só para quando o novoNodo tem ranking < que aux
            //a partir disso, posicionar o novoNodo atras do aux
            while(novoNodo->dados.ranking >= aux->dados.ranking){
                aux = aux->defronte;
            }
            novoNodo->atras = aux->atras;
            novoNodo->defronte = aux;
            aux->atras->defronte = novoNodo;
            aux->atras = novoNodo;
            ok = true;
        }
    }
    return ok;
}

int tamanhoDaFila(desc *p) {
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
bool removeFrente(desc *p, info *alvo) {
	if(testaVazia(p)) {
		return false;
	}
	memcpy(alvo, &(p->frente->dados), p->tam);

	struct nodo *aux = p->frente;
	if(aux == p->cauda) {
		p->frente = p->cauda = NULL;
	} else {
		p->frente = aux->defronte;
		p->frente->atras = NULL;
	}
	free(aux);
	return true;
}

bool testaVazia(desc *p) {
	return p->cauda == NULL || p->frente == NULL;
}
