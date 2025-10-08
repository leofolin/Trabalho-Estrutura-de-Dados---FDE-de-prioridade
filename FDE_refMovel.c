#include "generica_FDE.c"

bool insere(info *nodoInfo, desc *p){

	bool ok = false;
	struct nodo *novoNodo = NULL;
	novoNodo = malloc(sizeof(struct nodo));
	if(novoNodo == NULL) return false;
	memcpy(&(novoNodo->dados), nodoInfo, p->tamInfo);

	if(p->frente == NULL && p->cauda == NULL){
		novoNodo->defronte = NULL;
		novoNodo->atras = NULL;
		p->frente = novoNodo;
		p->cauda = novoNodo;
		ok = true;
	}
	else {
		if(novoNodo->dados.ranking < p->cauda->dados.ranking){
			novoNodo->defronte = p->cauda;
			novoNodo->atras = NULL;
			p->cauda->atras = novoNodo;
			p->cauda = novoNodo;
			ok = true;
		}
		else if(novoNodo->dados.ranking > p->frente->dados.ranking){
			novoNodo->atras = p->frente;
			novoNodo->defronte = NULL;
			p->frente->defronte = novoNodo;
			p->frente = novoNodo;
			ok = true;
		}
		else{

		}
	}
}
