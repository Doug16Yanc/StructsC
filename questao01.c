/*Implemente um programa que leia o nome, a idade e o enderec¸o de uma pessoa e
armazene os dados em uma estrutura.*/

#include <stdio.h>
#include <string.h>

#define tam 900

struct Dados
{
    char nome[tam];
    int idade;
    int numeroCasa;
    char rua[tam];
    char cidade[tam];
};

int main(void)
{
    struct Dados dados;
    
    printf("Digite o nome da pessoa:");
    fflush(stdin);
    fgets(dados.nome, tam, stdin);

    printf("Digite a idade da pessoa:");
    scanf("%d", &dados.idade);

    printf("Digite o numero da casa:");
    scanf("%d", &dados.numeroCasa);

    printf("Digite o nome da rua em que essa pessoa mora:");
    fflush(stdin);
    fgets(dados.rua, tam, stdin);


    printf("Digite o nome da cidade em que essa pessoa mora:");
    fflush(stdin);
    fgets(dados.cidade, tam, stdin);
    

    printf("\n");

    printf("Registros:\n");

    printf("%s\n%d\n\n%d\n\n%s\n%s\n", dados.nome, dados.idade, dados.numeroCasa, dados.rua, dados.cidade);

    return 0;
}