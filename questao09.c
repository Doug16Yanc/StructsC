/*Utilizando uma estrutura, faça um programa que permita a entrada de nome, endereço e
telefone de 5 pessoas e os imprima em ordem alfabetica. */

#include <stdio.h>
#include <string.h>

#define tam 900
#define tm 5

int compararNomes(const void *p, const void *q);


typedef struct{
    char nome[tam];
    char endereco[tam];
    char telefone[tam];
} Individuo;
Individuo individuo[tm];

int main(){
    
    for (int i = 0; i < tm; i++){
        printf("Nome do %d indivíduo: ", i + 1);
        fflush(stdin);
        fgets(individuo[i].nome, tam, stdin);

        printf("Endereço desse indivíduo:");
        fflush(stdin);
        fgets(individuo[i].endereco, tam, stdin);

        printf("Telefone desse indivíduo:");
        fflush(stdin);
        fgets(individuo[i].telefone, tam, stdin);
    }
    qsort(individuo, tm, sizeof(Individuo), compararNomes);

    printf("Dados em ordem alfabética por nomes:\n");

    for (int i = 0; i < tm; i++){
        printf("Nome: %s\n", individuo[i].nome);
        printf("Endereço: %s\n", individuo[i].endereco);
        printf("Telefone: %s\n", individuo[i].telefone);
    }
    return 0;
}

int compararNomes(const void *p, const void *q){
    Individuo *individuo1 = (Individuo*)p;
    Individuo *individuo2 = (Individuo*)q;
    return strcmp(individuo1->nome, individuo2->nome);
}