/*Faça um programa que leia um vetor com dados de 5 livros: título, 
autor e ano. Procure um livro por ano, perguntando ao usuário qual 
ano deseja buscar os livros publicados. Mostre os dados de todos os 
livros encontrados.*/

#include <stdio.h>
#include <string.h>

#define tam 900

struct Livro  
{
    char titulo[tam];
    char autor[tam];
    int ano;
};

int main(void)
{
    #define tamanho 5
    struct Livro livro[tamanho];

    char busca;

    printf("Iniciando operação para criar registros...\n");

    printf("Entre com título, autor e ano de publicação de cinco livros.\n");

    for (int i = 0; i < tamanho; i++)
    {
         printf(" Informe o Título do %dº livro: ", i+1);
        scanf("%[^\n]s",&livro[i].titulo);
        setbuf(stdin, NULL);
        printf(" Informe o Autor do %dº livro: ", i+1);
        scanf("%[^\n]s",&livro[i].autor);
        setbuf(stdin, NULL);
        printf(" Informe o Ano do %dº livro: ", i+1);
        scanf("%d", &livro[i].ano);
        setbuf(stdin, NULL)
    }
    
    printf("\n");

    printf("Iniciando operação para procura de livros:\n");

    do
    {
        printf("\nInforme o título do Livro que deseja pesquisar: ");
        scanf("%[^\n]s",&busca);
        setbuf(stdin, NULL);

        int x = 0;

        for(int i = 0; i < tamanho; i++)
        {
            if(strcmp(livro[i].titulo, busca) == 0)
            {
                indice[x] = i;
                x++;
            }
        }

        printf("\nLivros encontrados:\n");

        for(int i = 0; i <= x; i++)
        {
            if(index[0] != -1)
            {
                printf(" Título: %s\n", livro[indice[i]].titulo);
                printf(" Autor: %s\n", livro[indice[i]].autor);
                printf(" Ano: %d\n", livro[indice[i]].ano);
            }
            else
            {
            printf("Nenhum livro foi encontrado.\n");
            break;
            }
        }
    }
    while(year != -1);

    return 0;
}