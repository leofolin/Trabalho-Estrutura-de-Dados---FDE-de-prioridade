#include "arq.h"

desc *cria(int tam) {
	desc *descricao = malloc(sizeof(struct desc));
	if(descricao != NULL) {
		descricao->cauda = NULL;
		descricao->frente = NULL;
		descricao->tam = tam;
	}
	return descricao;
}
