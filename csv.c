#include "arq.h"

void randomiza() {
    system("echo \"Nome,Matrícula,Ranking,Curso\" > tmp.csv;"
           "tail --lines=+2 " ARQUIVO " | sort --random-sort >> tmp.csv;"
           "mv --force tmp.csv " ARQUIVO);
}

unsigned int gerarFila(desc *fila, int n, int prior) {
    FILE *file = fopen(ARQUIVO, "r");
    if(file == NULL) {
        printf("Arquivo %s não encontrado\n", ARQUIVO);
        return 0;
    }

    info dados;
    unsigned int soma = 0;
    int qtd;
    fscanf(file, "Nome,Matrícula,Ranking,Curso\n");
    for(int i = 0; i < n; i++) {
        fscanf(file, "%49[^,],%i,%i,%19[^\n]",  dados.nome,
               &dados.matricula,
               &dados.ranking,
               dados.curso);
        qtd = insere(&dados, fila, prior);
        if(qtd == -1) {
            fclose(file);
            return 0;
        }
        soma += qtd;
    }
    fclose(file);
    return soma;
}
