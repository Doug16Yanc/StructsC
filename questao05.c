/*Faça um programa que realize a leitura dos seguintes dados relativos a um conjunto de
alunos: Matricula, Nome, Codigo da Disciplina, Nota1 e Nota2. Considere uma turma de ´
ate 10 alunos. Após ler todos os dados digitados, e depois de armazená-los em um vetor ´
de estrutura, exibir na tela a listagem final dos alunos com as suas respectivas medias ´
finais (use uma media ponderada: Nota1 com peso=1.0 e Nota2 com peso=2.0).*/

#include <stdio.h>
#include <string.h>

#define tam 900

void recebeDados();

void calculaMedia();

void mostraNaTela();

struct Estudante
{
    char nome[tam];
    int matricula;
    int codigoDisciplina;
    double nota1;
    double nota2;
    double media;
};

int main(void)
{
    recebeDados();

    calculaMedia();

    mostraNaTela();

    return 0;
}

void recebeDados()
{
    #define tamanho 10
    struct Estudante estudante[tamanho];

    printf("Recebendo registros:\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("Nome do estudante %d:", i + 1);
        scanf("%s", &estudante[i].nome);

        printf("número de matrícula: ");
        scanf("%d", &estudante[i].matricula);

        printf("Código da disciplina:");
        scanf("%d", &estudante[i].codigoDisciplina);

        printf("Primeira nota:");
        scanf("%lf", &estudante[i].nota1);

        printf("Segunda nota:");
        scanf("%lf", &estudante[i].nota2);
    }
}

void calculaMedia()
{
    #define tamanho 10
    struct Estudante estudante[tamanho];

    int i = 0;
    estudante[i].media = 0;

    for (i = 0; i < tamanho; i++)
    {
        estudante[i].media += (2*(estudante[i].nota1) + 3*estudante[i].nota2)/5;
    }
}

void mostraNaTela()
{
    #define tamanho 10
    struct Estudante estudante[tamanho];

    printf("\n");

    printf("Calculando registros...\n");
    
    printf("Nome:\tmatrícula\tcódigo da disciplina\tnota 1\tnota 2\tmédia ponderada\n");

    for (int i = 0; i < tamanho; i++)
    {
        printf("%s\t\t%d\t%d\t\t\t%.2f\t%.2f\t%.2f\n", estudante[i].nome, estudante[i].matricula, estudante[i].codigoDisciplina, estudante[i].nota1, estudante[i].nota2, estudante[i].media);
    }

}