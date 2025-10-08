#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define ARQUIVO "dataset_v1.csv"
#define REF_MOVEL 0

typedef struct{
    char nome[50];
    int matricula;
    int ranking;
    char curso[20];
}info;

struct nodo{
    info dados;
    struct nodo *atras;
    struct nodo *defronte;
};

typedef struct desc{
    struct nodo *frente;
    struct nodo *cauda;
    #if REF_MOVEL
        struct nodo *refMovel;
    #endif
    int tamInfo;
} desc;

//================FUNCOES===================
struct desc *cria(int tam);
bool insere(info *novo, desc *p);
int tamanhoDaFila(desc *p);
bool reinicia(desc *p);
struct desc *destroi(desc *p);
bool buscaNaCauda(desc *p, info *alvo);
bool buscaNaFrente(desc *p, info *alvo);
bool removeFrente(desc *p, info *alvo);
bool testaVazia(desc *p);
bool inverte(desc *p);
