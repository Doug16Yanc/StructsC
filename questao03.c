/*Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
conter a matr´ıcula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
da terceira prova.
(a) Permita ao usuario entrar com os dados de 5 alunos. ´
(b) Encontre o aluno com maior nota da primeira prova.
(c) Encontre o aluno com maior media geral. ´
(d) Encontre o aluno com menor media geral ´
(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
aprovação.*/

#include <stdio.h>
#include <string.h>

#define tam 900



void recebeDados();

void calculaMedia();

void calculaMaiorMedia();

void calculaMenorMedia();

void determinaSituacao();

struct Estudante
{
    char nome[tam];
    int numeroMatricula;
    double nota1;
    double nota2;
    double nota3;
    double media;
};

struct Estudante estudante;


int main(void)
{
    #define tamanho 5

    struct Estudante estudante[tamanho];

    
    recebeDados();

    calculaMedia();

    calculaMaiorMedia();

    calculaMenorMedia();

    determinaSituacao();

    return 0;

}

void recebeDados()
{
    #define tamanho 5
    struct Estudante estudante[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        printf("\nNome do estudante %d:\n", i + 1);
        scanf("%s", &estudante[i].nome);

        printf("Número de matrícula:\n");
        scanf("%d", &estudante[i].numeroMatricula);

        printf("\nNota da primeira prova:\n");
        scanf("%lf", &estudante[i].nota1);

        printf("\nNota da segunda prova:\n");
        scanf("%lf", &estudante[i].nota2);
        
        printf("\nNota da terceira prova:\n");
        scanf("%lf", &estudante[i].nota3);
        
    }
    
    
}
void calculaMedia()
{
    #define tamanho 5

    struct Estudante estudante[tamanho];

    double soma = 0;


    for (int i = 0; i < 5; i++)
    {
        soma = estudante[i].nota1 + estudante[i].nota2 + estudante[i].nota3;
        estudante[i].media = soma/3;

        printf("\nNome:\t%s\nMédia geral:\t%.2f\n", estudante[i].nome, estudante[i].media);
    }
    
}

void calculaMaiorMedia()
{
    #define tamanho 5

    struct Estudante estudante[tamanho];

    int posicaoMaior = 0;
    double maior = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (estudante[i].media > maior)
        {
            maior = estudante[i].media;
            posicaoMaior = i;
        }
    }
    printf("O estudante com maior média é %s e ela é igual a %.2f.\n", estudante[posicaoMaior].nome, maior);
}

void calculaMenorMedia()
{
    #define tamanho 5

    struct Estudante estudante[tamanho];

    int posicaoMenor = 0;
    double menor = 1000000;

    for (int i = 0; i < tamanho; i++)
    {
        if (estudante[i].media < menor)
        {
            menor = estudante[i].media;
            posicaoMenor = i;
        }
    }
    printf("O estudante com maior média é %s e ela é igual a %.2f.\n", estudante[posicaoMenor].nome, menor);

}

void determinaSituacao()
{
    #define tamanho 5

    struct Estudante estudante[tamanho];

    for(int i = 0; i < tamanho; i++)
    {
        printf("\nNome: %s     \nMatrícula: %d     \n", estudante[i].nome, estudante[i].numeroMatricula);

        if(estudante[i].media >= 6)
        {
            printf("Aprovado!\n");
        }
        else
        {
            printf("Reprovado!\n");
        }
     }
}




