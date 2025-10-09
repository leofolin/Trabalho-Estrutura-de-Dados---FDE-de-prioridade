#include "arq.h"
// Funções genéricas usadas nas duas implementações de fila

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
