/*O programa ficou um pouco maior do que o convencional, porém é importante
implementar boas práticas de programação a fim de testar todas as probabilidades
possíveis, sobretudo numa linguagem tão estática e pobre de recursos, tais como
funções nativas dos tipos add e remove, como C*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 900

struct Produto
{
    char nome[tam];
    float peso;
    float preco;
};

struct Empresa
{
    char nomeEmpresa[tam];
    struct Produto produtos[tam];
};

void menu();
void cadastrarItens();
void listarMaisCaros();
void listarMaisBaratos();
void listarGeral();

int quantidadeProdutos = 0, quantidadeEmpresas = 0;

struct Produto produtos[tam];
struct Empresa empresas[tam];

int main()
{
    menu();
    return 0;
}

void menu()
{
    int opcao;

    printf("===================================================================\n");
    printf("Bem-vindo(a) ao nosso sistema de cotação de produtos alimentícios;\n");
    printf("====================================================================\n");
    printf("Digite uma opção:\n");
    printf("Opção 1: cadastrar itens.\n");
    printf("Opção 2: listar empresas com valor mais caro:\n");
    printf("Opção 3: listar empresas com valor mais barato:\n");
    printf("Opção 4: listar empresas de modo geral:\n");
    printf("Opção 5: Encerrar programa.\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        cadastrarItens();
        break;
    case 2:
        listarMaisCaros();
        break;
    case 3:
        listarMaisBaratos();
        break;
    case 4:
        listarGeral();
        break;
    case 5:
        printf("Agradeço sua interação comigo!\n");
        exit(0);

    default:
        printf("Opção inexistente!\n");
        break;
    }
}

void cadastrarItens()
{
    printf("Digite a quantidade de empresas que desejas registrar: ");
    scanf("%d", &quantidadeEmpresas);

    for (int i = 0; i < quantidadeEmpresas; i++)
    {
        getchar();

        printf("Digite o nome da empresa %d: ", i + 1);
        fgets(empresas[i].nomeEmpresa, tam, stdin);

        printf("Digite a quantidade de produtos que desejas registrar para a empresa %d: ", i + 1);
        scanf("%d", &quantidadeProdutos);

        for (int j = 0; j < quantidadeProdutos; j++)
        {
            getchar();

            printf("Nome do produto %d: ", j + 1);
            fgets(empresas[i].produtos[j].nome, tam, stdin);

            printf("Peso do produto (gramas): ");
            scanf("%f", &empresas[i].produtos[j].peso);

            printf("Preço do produto: ");
            scanf("%f", &empresas[i].produtos[j].preco);
        }
        printf("Registro de dados realizado com sucesso!\n");
    }
    menu();
}

void listarMaisCaros()
{
    if (quantidadeEmpresas != 0)
    {
        printf("Empresas com produtos mais caros:\n");

        for (int i = 0; i < quantidadeEmpresas; i++)
        {
            float maiorPreco = -1;
            int indiceProdutoMaisCaro = 0;

            for (int j = 0; j < quantidadeProdutos; j++)
            {
                if (empresas[i].produtos[j].preco > maiorPreco)
                {
                    maiorPreco = empresas[i].produtos[j].preco;
                    indiceProdutoMaisCaro = j;
                }
            }

            printf("Empresa: %s", empresas[i].nomeEmpresa);
            printf("Produto mais caro: %s", empresas[i].produtos[indiceProdutoMaisCaro].nome);
            printf("Preço: %.2f\n", empresas[i].produtos[indiceProdutoMaisCaro].preco);
            printf("=============================\n");
        }
    }
    else
    {
        printf("Nenhum dado registrado.\n");
    }
    menu();
}

void listarMaisBaratos()
{
    if (quantidadeEmpresas != 0)
    {
        printf("Empresas com produtos mais baratos:\n");

        for (int i = 0; i < quantidadeEmpresas; i++)
        {
            float menorPreco = 1000000;
            int indiceProdutoMaisBarato = 0;

            for (int j = 0; j < quantidadeProdutos; j++)
            {
                if (empresas[i].produtos[j].preco < menorPreco)
                {
                    menorPreco = empresas[i].produtos[j].preco;
                    indiceProdutoMaisBarato = j;
                }
            }

            printf("Empresa: %s\n", empresas[i].nomeEmpresa);
            printf("Produto mais barato: %s\n", empresas[i].produtos[indiceProdutoMaisBarato].nome);
            printf("Preço: %.2f\n", empresas[i].produtos[indiceProdutoMaisBarato].preco);
            printf("=============================\n");
        }
    }
    else
    {
        printf("Nenhum dado registrado.\n");
    }
    menu();
}

void listarGeral()
{
    if (quantidadeEmpresas != 0)
    {
        printf("Lista geral de empresas e produtos:\n");

        for (int i = 0; i < quantidadeEmpresas; i++)
        {
            printf("Empresa: %s\n", empresas[i].nomeEmpresa);

            for (int j = 0; j < quantidadeProdutos; j++)
            {
                printf("Produto %d: %s\n", j + 1, empresas[i].produtos[j].nome);
                printf("Peso: %.2fg\n", empresas[i].produtos[j].peso);
                printf("Preço: %.2f\n", empresas[i].produtos[j].preco);
                printf("-----------------------------\n");
            }
        }
    }
    else
    {
        printf("Nenhum dado registrado.\n");
    }
    menu();
}

