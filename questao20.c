/*. Faça um programa que armazena filmes produzidos por vários diretores e:
crie e leia um vetor de 5 diretores, cada um contendo nome, quantidade de filmes
e filmes. O membro filmes é um vetor, que deve ser criado após ter lido quantidade
de filmes. Cada filme é composto por nome, ano e duração. Procure um diretor por nome,
mostrando todos os filmes que ele já produziu. Repita o processo até digitar uma string vazia.*/

#include <stdio.h>
#include <string.h>

#define tamanho 900

struct Diretor
{
    char nome[tamanho];
    int quantFilmes;
};
struct Filme  
{
    char filme[tamanho];
    int ano;
    int duracao;
};

void criaRegistros()
{
    #define tam 5
    struct Diretor diretor[tam];

    printf("Criando registros de diretores...\n");

    for (int i = 0; i < tam; i++)
    {
        printf("Nome do %dº diretor:\n", i + 1);
        fflush(stdin);
        fgets(diretor[i].nome, tamanho, stdin);

        printf("Quantidade de filmes que dirigiu:\n");
        scanf("%d", &diretor[i].quantFilmes);

        struct Filme film[diretor[i].quantFilmes];

        for (int j = 0; j < diretor[i].quantFilmes; j++)
        {
            printf("Nome do %d filme:\n", j + 1);
            fflush(stdin);
            fgets(film[j].filme, tamanho, stdin);

            printf("Ano de lançamento:\n");
            scanf("%d", &film[j].ano);

            printf("Duração em minutos:\n");
            scanf("%d", &film[j].duracao);
        }
    }
}

void procuraDiretores()
{
    #define tam 5
    #define tm 900

    struct Diretor diretor[tam];
    struct Filme film[tm];

    int i, j;
    char nomeDiretor[tam];

    printf("Digite o nome de um diretor:\n");
    fflush(stdin);
    fgets(nomeDiretor, tm, stdin);
    nomeDiretor[strcspn(nomeDiretor, "\n")] = '\0';

    for (i = 0; i < tam; i++)
    {
        if (strcmp(nomeDiretor, diretor[i].nome) == 1)
        {
            printf("Diretor encontrado com sucesso.\n");
            printf("Nome: %s\n", diretor[i].nome);
            printf("Quantidade de filmes que dirigiu: %d\n", diretor[i].quantFilmes);
            printf("Filmes que ele dirigiu.\n");
        
            struct Filme film[diretor[i].quantFilmes];

            for (j = 0; j < diretor[i].quantFilmes; j++)
            {
                printf("Nome do filme: %s\n", film[i].filme);
                printf("Ano de lançamento: %d\n", film[i].ano);
                printf("Duração do filme: %d\n", film[i].duracao);
            }
        }
        else
        {
            printf("Diretor não encontrado.\n");
        }
    }
    return;
}

int main()
{
    int escolha;

    printf("Bem-vindo ao nosso sistema online de diretores hollywoodianos.\n");

    while(1)
    {
        printf("Digite uma opção.\n");
        printf("  | 1 - registrar diretores e filmes.\n");
        printf("  | 2 - procurar diretores.\n");
        printf("  | 3 - encerrar programa.\n");
        scanf("%d", &escolha);

        switch (escolha)
        {
            case 1:
                criaRegistros();
                break;
            case 2:
                procuraDiretores();
                break;
            case 3:
                break;
            default:
                printf("Até logo!");
                break;
        }
    }
    return 0;
}