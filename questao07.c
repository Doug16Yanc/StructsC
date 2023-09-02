/*Faça um programa que armazene em um registro de dados (estrutura composta) os dados de um funcionario de uma empresa, compostos de: Nome, Idade, Sexo (M/F), CPF, ´
Data de Nascimento, Codigo do Setor onde trabalha (0-99), Cargo que ocupa (string de ate 30 caracteres) e Sal ´ ario. Os dados devem ser digitados pelo usu ´ ario, armazenados ´
na estrutura e exibidos na tela.*/

#include <stdio.h>
#include <string.h>

#define tam 900

struct Funcionario
{
    char nome[tam];
    char sexo[tam];
    char CPF[tam];
    char dataDeNascimento[tam];
    char cargo[tam];
    int codigoSetor;
    int idade;
    double salario;
};

int main(void)
{
    struct Funcionario funcionario;

    printf("Digite o nome do funcionário:");
    fflush(stdin);
    fgets(funcionario.nome, tam, stdin);

    printf("Digite o sexo do funcionário[M-masculino/F-feminino]:");
    fflush(stdin);
    fgets(funcionario.sexo, tam, stdin);

    printf("Digite o CPF do funcionário (formato brasileiro):");
    fflush(stdin);
    fgets(funcionario.CPF, tam, stdin);

    printf("Digite a data de nascimento (formato padrão = _dd_/_mm/__aaaa_):");
    fflush(stdin);
    fgets(funcionario.dataDeNascimento, tam, stdin);

    printf("Qual cargo ocupas aqui?");
    fflush(stdin);
    fgets(funcionario.cargo, tam, stdin);

    printf("Código do setor (0-99):");
    scanf("%d", &funcionario.codigoSetor);

    printf("Qual a idade?");
    scanf("%d", &funcionario.idade);

    printf("Salário: ");
    scanf("%lf", &funcionario.salario);

    printf("\n");

    printf("Determinando registros...\n");

    printf("\n");

    printf("Nome : %s\nSexo : %s\nCPF : %s\nData de nascimento : %s\nDescrição de cargo : %s\nCódigo do setor : %d\nIdade : %d\nSalário (R$) : %.2f", funcionario.nome, funcionario.sexo, funcionario.CPF, funcionario.dataDeNascimento, funcionario.cargo, funcionario.codigoSetor, funcionario.idade, funcionario.salario);

    return 0;

}