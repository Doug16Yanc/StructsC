/*Escreva um trecho de codigo para fazer a criac¸ ´ ao dos novos tipos de dados conforme ˜
solicitado abaixo:
• Horario: composto de hora, minutos e segundos. ´
• Data: composto de dia, mes e ano. ˆ
• Compromisso: composto de uma data, horario e texto que descreve o compromisso.*/

#include <stdio.h>
#include <string.h>

#define tam 900

struct Horario
{
    int hora;
    int minuto;
    int segundo;
};

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Compromisso
{
    char data[tam];
    char horario[tam];
    char descricao[tam];
};

int main(void)
{
    struct Horario horario;
    struct Data data;
    struct Compromisso compromisso;

    printf("Recebendo registros...\n");

    printf("Digite hora, minutos e segundos:");
    scanf("%d%d%d", &horario.hora, &horario.minuto, &horario.segundo);

    printf("Digite dia, mês e ano:");
    scanf("%d%d%d", &data.dia, &data.mes, &data.ano);

    printf("Digite a data do compromisso:");
    fflush(stdin);
    fgets(compromisso.data, tam, stdin);

    printf("Digite o horário do compromisso:");
    fflush(stdin);
    fgets(compromisso.horario, tam, stdin);

    printf("Dê uma descrição breve acerca do compromisso:");
    fflush(stdin);
    fgets(compromisso.descricao, tam, stdin);


    printf("\nImprimindo registros...\n");

    printf("\nDa estrutura de horário:\n");

    printf("hora : %d\nminutos : %d\nsegundos : %d\n", horario.hora, horario.minuto, horario.segundo);

    printf("\nDa estrutura de data:\n");

    printf("dia : %d\nmês : %d\nano : %d\n", data.dia, data.mes, data.ano);

    printf("\nDa estrutura de compromisso:\n");

    printf("data do compromisso\n:%s\nhorário do compromisso :\n%s\ndescrição :\n%s\n", compromisso.data, compromisso.horario, compromisso.descricao);



    return 0;
}