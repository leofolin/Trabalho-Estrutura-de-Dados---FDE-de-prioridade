#include "arq.h"

int main() {
    struct desc *fila = cria(sizeof(info));
    unsigned int qtd = gerarFila(fila, NUMERO);
    printf("Criada fila com %i elementos, com %u iterações", NUMERO, qtd);
    int opcao = -1;
    do {
        menu();
        scanf("%i", &opcao);
        info dados;
        switch(opcao) {
        case(0):
            printf("Saindo...");
            break;
        case(1):
            removeFrente(fila, &dados);
            printf("Nodo removido:");
            printaNodo(dados);
        case(2):
            printf("Tamanho: %u", tamanhoDaFila(fila));
            break;
        case(3):
            buscaNaCauda(fila, &dados);
            printf("Nodo encontrado:");
            printaNodo(dados);
            break;
        case(4):
            buscaNaFrente(fila, &dados);
            printf("Nodo encontrado:");
            printaNodo(dados);
            break;
        default:
            printf("Opção inválida. Tente novamente");
        }
    } while(opcao != 0);
}

void menu() {
    printf("Escolha uma das opções:\n");
    printf("0 - Sair\n"
           "1 - Remover nodo da frente\n"
           "2 - Mostrar tamanho da fila\n"
           "3 - Mostrar elemento da cauda\n"
           "4 - Mostrar elemento da frente\n");
}
