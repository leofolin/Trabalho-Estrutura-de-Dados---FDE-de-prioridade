#include "arq.h"
// Funções genéricas usadas nas duas implementações de fila
unsigned int insereSemRefMovel(info *nodoInfo, desc *p) {
    struct nodo *novoNodo = malloc(sizeof(struct nodo));
    if(novoNodo == NULL) return 0;
    memcpy(&(novoNodo->dados), nodoInfo, p->tamInfo);

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

unsigned int insereComRefMovel(info *nodoInfo, desc *p){
    struct nodo *novoNodo = NULL;
    novoNodo = malloc(sizeof(struct nodo));
    if(novoNodo == NULL) return 0;
    memcpy(&(novoNodo->dados), nodoInfo, p->tamInfo);
    
    //verifica fila vazia, se sim, só adiciona
    if(p->frente == p->cauda == NULL){
        novoNodo->defronte = NULL;
        novoNodo->atras = NULL;
        p->frente = novoNodo;
        p->cauda = novoNodo;
        return 1;
    }
    else {
        //verifica se o ranking do novo aluno é menor que o da cauda
        //se for, adiciona ele na cauda
        if(novoNodo->dados.ranking < p->cauda->dados.ranking){
            novoNodo->defronte = p->cauda;
            novoNodo->atras = NULL;
            p->cauda->atras = novoNodo;
            p->cauda = novoNodo;
            return 2;
        }
        //verifica se o ranking do novo aluno é maior que o da frente da fila
        //se for, adiciona ele na frente da fila, vira o novo frente
        else if(novoNodo->dados.ranking > p->frente->dados.ranking){
            novoNodo->atras = p->frente;
            novoNodo->defronte = NULL;
            p->frente->defronte = novoNodo;
            p->frente = novoNodo;
            return 3;
        }
        //se estiver no meio da fila, verifica se o ranking é menor do que do
        //refMovel, se for, vai indo pra tras até achar o lugar certo
        //se for maior, vai indo pra frente até achar o lugar certo
        //se os rankings forem iguais, o mais novo fica atras
        else{
            int i = 4;
            if(novoNodo->dados.ranking == p->refMovel->dados.ranking){
                novoNodo->defronte = p->refMovel;
                novoNodo->atras = p->refMovel->atras;
                p->refMovel->atras->defronte = novoNodo;
                p->refMovel->atras = novoNodo;
                //nao precisa atualizar refMovel
                return i;
            }
            else if(novoNodo->dados.ranking < p->refMovel->dados.ranking){
                while(novoNodo->dados.ranking < p->refMovel->dados.ranking){
                    p->refMovel = p->refMovel->atras;
                    i++;
                    //ref vai para tras ate novoNodo.ranking ser maior
                }
                //coloca novoNodo na frente de refMovel
                novoNodo->atras = p->refMovel;
                novoNodo->defronte = p->refMovel->defronte;
                p->refMovel->defronte->atras = novoNodo;
                p->refMovel->defronte = novoNodo;
                p->refMovel = novoNodo; //atualiza refMovel para o novo nodo
                return i;
            }
            else if(novoNodo->dados.ranking > p->refMovel->dados.ranking){
                while(novoNodo->dados.ranking > p->refMovel->dados.ranking){
                    p->refMovel = p->refMovel->defronte;
                    i++;
                    //ref vai para frente ate ser maior que novoNodo.ranking
                }
                //coloca novoNodo atras do refMovel
                novoNodo->defronte = p->refMovel;
                novoNodo->atras = p->refMovel->atras;
                p->refMovel->atras->defronte = novoNodo;
                p->refMovel->atras = novoNodo;
                p->refMovel = novoNodo; //atualiza refMovel para o novo nodo
                return i;
            }
        }
    }
    return 0;
}

struct desc *cria(int tam) {
    desc *descricao = malloc(sizeof(desc));
    if(descricao != NULL) {
        descricao->cauda = NULL;
        descricao->frente = NULL;
        descricao->tamInfo = tam;
        descricao->refMovel = NULL;
    }
    return descricao;
}

bool removeFrente(desc *p, info *alvo) {
    if(testaVazia(p)) {
        return false;
    }
    memcpy(alvo, &(p->frente->dados), p->tamInfo);

    struct nodo *aux = p->frente;
    if(aux == p->cauda) {
        p->frente = p->cauda = NULL;
    } else {
        p->frente = aux->atras;
        p->frente->defronte = NULL;
    }
    free(aux);
    return true;
}
unsigned int tamanhoDaFila(desc *p) {
    struct nodo *aux = p->cauda;
    int i = 0;
    while(aux->defronte != NULL) {
        i++;
        aux = aux->defronte;
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

