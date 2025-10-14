#include "arq.h"

int main() {
    randomiza();
    printf("Escolha:\n"
           "0 - Sair\n"
           "1 - Mostrar estatísticas\n"
           "2 - Mostrar menu\n");
    int o;
    do {
        scanf("%i", &o);
        switch(o) {
        case(0):
            printf("Saindo..");
            break;
        case(1):
            estatisticas();
            break;
        case(2):
            menu();
            break;
        default:
            printf("Opção inválida. Tente novamente\n");
        }
    } while(o != 0);
}

void estatisticas() {
    for(int i = 500; i <= 9000; i+=500) {

    }
}
void menu() {
    struct desc *fila = cria(sizeof(info));
    unsigned int qtd = gerarFila(fila, NUMERO);
    printf("Criada fila com %i elementos, através de %i iterações\n", NUMERO, qtd);
    int opcao = -1;
    do {
        printf("Escolha uma das opções:\n");
        printf("0 - Sair\n"
               "1 - Remover nodo da frente\n"
               "2 - Mostrar tamanho da fila\n"
               "3 - Mostrar elemento da cauda\n"
               "4 - Mostrar elemento da frente\n");
        scanf("%i", &opcao);
        info dados;
        switch(opcao) {
        case(0):
            main();
            return;
        case(1):
            removeFrente(fila, &dados);
            printf("Nodo removido:\n");
            printaNodo(dados);
            break;
        case(2):
            printf("Tamanho: %u\n", tamanhoDaFila(fila));
            break;
        case(3):
            buscaNaCauda(fila, &dados);
            printf("Nodo encontrado:\n");
            printaNodo(dados);
            break;
        case(4):
            buscaNaFrente(fila, &dados);
            printf("Nodo encontrado:\n");
            printaNodo(dados);
            break;
        default:
            printf("Opção inválida. Tente novamente\n");
        }
    } while(opcao != 0);
}
