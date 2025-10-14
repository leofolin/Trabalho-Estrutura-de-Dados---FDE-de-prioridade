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
    printf("Comparação de desempenho entre as filas com e sem referencial móvel:\n");
    unsigned int qtd;
    float media;
    struct desc *fila = cria(sizeof(info));
    for(int i = 500; i <= 9000; i+=500) {
        int numIter_sem = 0;
        insere = insereSemRefMovel;
        qtd = gerarFila(fila, i);
        media = (float) qtd/i;

        reinicia(fila);

        int numIter_com = 0;
        insere = insereComRefMovel;

        qtd = gerarFila(fila, i);
        media = (float) qtd/i;
        
    }
}
void menu() {
    printf("Gerar fila com ou sem referencial móvel? Digite 0 para sem 1 para com");
    int temRefMovel;
    scanf("%i", &temRefMovel);
    if(temRefMovel) {
        insere = insereComRefMovel;
    } else {
        insere = insereSemRefMovel;
    }
    printf("Deseja que a fila tenha quantos elementos?");
    int n;
    scanf("%i", &n);

    struct desc *fila = cria(sizeof(info));
    unsigned int qtd = gerarFila(fila, n);
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
