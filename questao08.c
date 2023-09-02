/*Faça um programa que fac¸a operac¸oes simples de n ˜ umeros complexos: ´
• Crie e leia dois numeros complexos ´ z e w, compostos por parte real e parte imaginária. ´
• Apresente a soma, subtraçao e produto entre ˜ z e w, nessa ordem, bem como o
modulo de ambos.*/

#include <stdio.h>
#include <math.h>
#include <complex.h>

void calculaSoma();

void calculaSubtracao();

void calculaProduto();

void calculaModulo();

struct numeroComplexo
{
    int z1;
    int z2;
    int w1;
    int w2;
};

int main(void)
{
    struct numeroComplexo complexo;

    printf("Lembre-se que a primeira parte é real e a segunda parte é imaginária...\n");

    printf("Digite os valores do número complexo Z:");
    scanf("%d%d", &complexo.z1, &complexo.z2);

    printf("Agora, digite os valores do número complexo W:");
    scanf("%d%d", &complexo.w1, &complexo.w2);

    calculaSoma();

    calculaSubtracao();

    return 0;
}

void calculaSoma()
{   
    struct numeroComplexo complexo;

    printf("Soma igual a %d + %d.", (complexo.z1 + complexo.w1), (complexo.z2 + complexo.w2)*-1);
}

void calculaSubtracao()
{
    struct numeroComplexo complexo;

    printf("Subtração igual a %d - %d.", (complexo.z1 + complexo.w1), (complexo.z2 + complexo.w2)*-1);
}