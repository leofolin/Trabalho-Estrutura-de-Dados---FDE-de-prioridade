#include "generica_FDE.c"

#if RANDOM 
void randomiza() {
	system("sort -R" ARQUIVO "> Dataset2.csv");
}
#undef ARQUIVO
#define ARQUIVO "Dataset2.csv"
#endif

bool gerarFila(desc *fila, int n) {
	FILE *file = fopen(ARQUIVO, "r");
	if(file == NULL) {
		printf("Arquivo %s não encontrado", ARQUIVO);
		return false;
	}

	info dados;
	unsigned int soma = 0, qtd;
	for(int i = 0; i < n; i++) {
		fscanf(file, "%s,%i,%i,%s \n",  dados.nome,
										&dados.matricula,
										&dados.ranking,
										dados.curso);
	qtd = insere(&dados,fila);
	if(!qtd) {
		return false;
	}
	soma += qtd;
	}
	return true;
}
