/*Construa uma estrutura aluno com nome, numero de matrícula e curso. Leia do usuario ´
a informac¸ao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na ˜
tela.*/

#include <stdio.h>
#include <string.h>

#define tam 900

struct Aluno
{
    char nome[tam]; 
    char nomeCurso[tam];
    int numeroMatricula;
   
};


int main(void)
{
    #define tamanho 5

    struct Aluno aluno[tamanho];


    int contador;

    printf("Inicialização dos registros...\n");

    for (contador = 0; contador < tamanho; contador++)
    {
        printf("Digite o nome do aluno %d:\n ", contador + 1);
        fflush(stdin);
        fgets(aluno[contador].nome, tam, stdin);


        printf("Digite o nome do curso do aluno:\n");
        fflush(stdin);
        fgets(aluno[contador].nomeCurso, tam, stdin);
        
        printf("Digite o número de matrícula do aluno (0-99):\n");
        scanf("%d", &aluno[contador].numeroMatricula);

    }
        
   

    printf("\n");

    printf("Calculando registros...\n");

    for (contador = 0; contador < 5; contador++)
    {
        printf("\nNome:\t %s\nCurso:\t %s\nNúmero de matrícula:\t %d\n\n", aluno[contador].nome, aluno[contador].nomeCurso, aluno[contador].numeroMatricula);
    }
    return 0;
}
