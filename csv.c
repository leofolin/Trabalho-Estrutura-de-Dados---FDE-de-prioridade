#include "arq.h"

#if RANDOM
void randomiza() {
    system("sort -R " ARQUIVO "> Dataset2.csv");
}
#undef ARQUIVO
#define ARQUIVO "Dataset2.csv"
#endif

unsigned int gerarFila(desc *fila, int n) {
    FILE *file = fopen(ARQUIVO, "r");
    if(file == NULL) {
        printf("Arquivo %s não encontrado", ARQUIVO);
        return 0;
    }

    info dados;
    unsigned int soma = 0, qtd;
    fscanf(file, "Nome,Matrícula,Ranking,Curso");
    for(int i = 0; i < n; i++) {
        fscanf(file, "%49[^,],%i,%i,%49[^\n]\n",  dados.nome,
               &dados.matricula,
               &dados.ranking,
               dados.curso);
        qtd = insere(&dados,fila);
        if(qtd == -1) {
            fclose(file);
            return 0;
        }
        soma += qtd;
    }
    fclose(file);
    return soma;
}
