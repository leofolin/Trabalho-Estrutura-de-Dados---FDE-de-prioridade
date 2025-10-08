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
