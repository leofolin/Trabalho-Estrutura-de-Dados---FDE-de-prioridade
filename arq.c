#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define True 1
#define False 0
#define sim 1
#define nao 0

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

struct desc{
    struct nodo *frente;
    struct nodo *cauda;
    struct nodo *refMovel;
    int tam;
};

//================FUNCOES===================
struct desc *cria(int tam);
int insere(info *novo, struct desc *p);
int tamanhoDaFila(struct desc *p);
int reinicia(struct desc *p);
struct desc *destroi(struct desc *p);
int buscaNaCauda(struct desc *p, info *alvo);
int buscaNaFrente(struct desc *p, info *alvo);
int remove(struct desc *p, info *alvo);
int testa_vazia(struct desc *p);
int inverte(struct desc *p);
