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

typedef struct desc{
    struct nodo *frente;
    struct nodo *cauda;
    struct nodo *refMovel;
    int tam;
} desc;

//================FUNCOES===================
struct desc *cria(int tam);
int insere(info *novo, desc *p);
int tamanhoDaFila(desc *p);
int reinicia(desc *p);
struct desc *destroi(desc *p);
int buscaNaCauda(desc *p, info *alvo);
int buscaNaFrente(desc *p, info *alvo);
int remove(desc *p, info *alvo);
int testa_vazia(desc *p);
int inverte(desc *p);
