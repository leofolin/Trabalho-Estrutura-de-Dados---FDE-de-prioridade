#include "generica_FDE.c"
#if REF_MOVEL
bool insere(info *nodoInfo, desc *p){
    bool ok = false;
    struct nodo *novoNodo = NULL;
    novoNodo = malloc(sizeof(struct nodo));
    if(novoNodo == NULL) return false;
    memcpy(&(novoNodo->dados), nodoInfo, p->tamInfo);
    
    //verifica fila vazia, se sim, só adiciona
    if(p->frente == NULL && p->cauda == NULL){
        novoNodo->defronte = NULL;
        novoNodo->atras = NULL;
        p->frente = novoNodo;
        p->cauda = novoNodo;
        ok = true;
    }
    else {
        //verifica se o ranking do novo aluno é menor que o da cauda
        //se for, adiciona ele na cauda
        if(novoNodo->dados.ranking < p->cauda->dados.ranking){
            novoNodo->defronte = p->cauda;
            novoNodo->atras = NULL;
            p->cauda->atras = novoNodo;
            p->cauda = novoNodo;
            ok = true;
        }
        //verifica se o ranking do novo aluno é maior que o da frente da fila
        //se for, adiciona ele na frente da fila, vira o novo frente
        else if(novoNodo->dados.ranking > p->frente->dados.ranking){
            novoNodo->atras = p->frente;
            novoNodo->defronte = NULL;
            p->frente->defronte = novoNodo;
            p->frente = novoNodo;
            ok = true;
        }
        //se estiver no meio da fila, verifica se o ranking é menor do que do
        //refMovel, se for, vai indo pra tras até achar o lugar certo
        //se for maior, vai indo pra frente até achar o lugar certo
        //se os rankings forem iguais, o mais novo fica atras
        else{
            if(novoNodo->dados.ranking == p->refMovel->dados.ranking){
                novoNodo->defronte = p->refMovel;
                novoNodo->atras = p->refMovel->atras;
                p->refMovel->atras->defronte = novoNodo;
                p->refMovel->atras = novoNodo;
                //nao precisa atualizar refMovel
                ok = true;
            }
            else if(novoNodo->dados.ranking < p->refMovel->dados.ranking){
                while(novoNodo->dados.ranking <= p->refMovel->atras->dados.ranking){
                    p->refMovel = p->refMovel->atras;
                    //ref vai para tras ate novoNodo.ranking ser maior que refMovel->atras
                }
                //coloca novoNodo atras do refMovel
                novoNodo->defronte = p->refMovel;
                novoNodo->atras = p->refMovel->atras;
                p->refMovel->atras->defronte = novoNodo;
                p->refMovel->atras = novoNodo;
                p->refMovel = novoNodo; //atualiza refMovel para o novo nodo
                ok = true;
            }
            else if(novoNodo->dados.ranking > p->refMovel->dados.ranking){
                while(novoNodo->dados.ranking > p->refMovel->dados.ranking){
                    p->refMovel = p->refMovel->defronte;
                    //ref vai para frente ate ser maior que novoNodo.ranking
                }
                //coloca novoNodo atras do refMovel
                novoNodo->defronte = p->refMovel;
                novoNodo->atras = p->refMovel->atras;
                p->refMovel->atras->defronte = novoNodo;
                p->refMovel->atras = novoNodo;
                p->refMovel = novoNodo; //atualiza refMovel para o novo nodo
                ok = true;
            }
        }
    }
    return ok;
}
#endif
