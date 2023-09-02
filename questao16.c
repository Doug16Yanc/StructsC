/*Faça um programa que controla o consumo de energia dos eletrodomesticos de uma ´
casa e: Crie e leia 5 eletrodomesticos que contém nome (máximo 15 letras), potência (real, ˆ
em kW) e tempo ativo por dia (real, em horas). Leia um tempo t (em dias), calcule e mostre
os consumos absoluto e relativo de cada eletrodomestico e o consumo total na casa 
nesse período de tempo. Apresente este último dado em porcentagem.*/

#include <stdio.h>
#include <string.h>

#define tamanho 15

struct Eletrodomestico
{
    char dispositivo[tamanho];
    float potencia;
    float tempoAtivo;
    float consumo;
};

int main()
{
    #define tam 5
    struct Eletrodomestico eletrodomestico[tam];

    int dias, i;
    float somaConsumo = 0, consumoPercentual = 0;

    for(i = 0; i < tam; i++)
    {
        printf("Digite o nome do eletrodoméstico:");
        fflush(stdin);
        fgets(eletrodomestico[i].dispositivo, tamanho, stdin);

        printf("Digite, em KWh, a potência do dispositivo:");
        scanf("%f", &eletrodomestico[i].potencia);

        printf("Digite o tempo ativo total desse dispositivo por dia:");
        scanf("%f", &eletrodomestico[i].tempoAtivo);

    }

    printf("Digite uma quantidade determinada de dias:");
    scanf("%d", &dias);


    printf("Consumo de cada eletrodoméstico.\n");

    for (i = 0; i < tam; i++)
    {
        eletrodomestico[i].consumo = eletrodomestico[i].potencia*eletrodomestico[i].tempoAtivo*dias;
        somaConsumo += eletrodomestico[i].consumo;
        consumoPercentual = eletrodomestico[i].consumo/somaConsumo;

        printf("\ndispositivo: %s\npotência: %.1f\ntempo ativo por dia: %1.f\nconsumo: %.1f\nconsumo relativo: %f %\n", eletrodomestico[i].dispositivo, eletrodomestico[i].potencia, eletrodomestico[i].tempoAtivo, eletrodomestico[i].consumo, consumoPercentual);
    }

    printf("Consumo total dos dispositivos: %.2f", somaConsumo);

    return 0;


}