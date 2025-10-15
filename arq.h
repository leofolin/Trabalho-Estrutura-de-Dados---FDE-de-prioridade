#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define ARQUIVO "dataset_v1.csv"

typedef struct {
    char nome[50];
    int matricula;
    int ranking;
    char curso[20];
} info;

struct nodo {
    info dados;
    struct nodo *atras;
    struct nodo *defronte;
};

typedef struct desc {
    struct nodo *frente;
    struct nodo *cauda;
    struct nodo *refMovel;
    int tamInfo;
} desc;

//================FUNCOES===================
struct desc *cria(int tam);
int insereSemRefMovel(info *novo, desc *p, int prior);
int insereComRefMovel(info *novo, desc *p, int prior);
extern int (*insere)(info *novo, desc *p, int prior);
unsigned int tamanhoDaFila(desc *p);
bool reinicia(desc *p);
struct desc *destroi(desc *p);
bool buscaNaCauda(desc *p, info *alvo);
bool buscaNaFrente(desc *p, info *alvo);
bool removeFrente(desc *p, info *alvo);
bool testaVazia(desc *p);
bool inverte(desc *p);
void printaNodo(info dados);

// CSV
unsigned int gerarFila(desc *fila, int n, int prior);
void randomiza();

// main
void menu();
void estatisticas(int prior);
