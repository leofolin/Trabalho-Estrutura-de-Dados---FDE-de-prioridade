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
            return 0;
        case(1):
            estatisticas(1);
            //primeiro, o parâmetro vai começar com 1, depois ela muda para 0
            break;
        case(2):
            menu();
            return 2;
        default:
            printf("Opção inválida. Tente novamente\n");
        }
    } while(o != 0);
}

void estatisticas(int prior) {
    printf("Comparação de desempenho entre as filas com e sem referencial móvel:\n");
    printf("| Tamanho | Tipo de Fila | Qtd. Iterações | Média | Melhoria (%%) | \n");
    unsigned int qtd_semRefMovel, qtd_comRefMovel;
    float media;
    struct desc *fila;
    fila = cria(sizeof(info));
    for(int i = 500; i <= 9000; i+=500) {
        insere = insereSemRefMovel;
        qtd_semRefMovel = gerarFila(fila, i, prior);
        media = (float) qtd_semRefMovel/i;
        printf("| %-7i |   %-10s | %-14u | %-9.4f | %-12s |\n",
               i, "Sem Ref.", qtd_semRefMovel, media, "");

        reinicia(fila);

        insere = insereComRefMovel;
        qtd_comRefMovel = gerarFila(fila, i, prior);
        media = (float) qtd_comRefMovel/i;
        printf("| %-7i |   %-10s | %-14u | %-9.4f |   %-9.2f%% |\n",
               i, "Com Ref.", qtd_comRefMovel, media, (float) (qtd_semRefMovel - qtd_comRefMovel)/qtd_semRefMovel * 100);

        reinicia(fila);
    }
    destroi(fila);
    if(prior == 1)
        estatisticas(1);
}
void menu() {
        printf("Gerar fila com ou sem referencial móvel? Digite 0 para sem 1 para com\n");
    int temRefMovel;
    scanf("%i", &temRefMovel);
    if(temRefMovel) {
        insere = insereComRefMovel;
    } else {
        insere = insereSemRefMovel;
    }
    printf("Deseja que a fila tenha quantos elementos?\n");
    int n;
    scanf("%i", &n);

    struct desc *fila = cria(sizeof(info));
    unsigned int qtd = gerarFila(fila, n, 1);
    printf("Criada fila com %i elementos, através de %i iterações\n", n, qtd);

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
            destroi(fila);
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
