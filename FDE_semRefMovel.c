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
	if(p->cauda == NULL || p->frente == NULL) {
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

bool removeFrente(desc *p, info *alvo) {
	if(p->cauda == NULL || p->frente == NULL) {
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
