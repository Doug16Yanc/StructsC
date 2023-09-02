/*Faça um programa que converta coordenadas polares para cartesianas:
• Crie e leia um ponto em coordenada polar, composto por raio (r) e argumento (a)
em radianos.
1
• Crie outro ponto, agora em coordenada cartesiana, composto por x e y, sabendo
que x = r ∗ cosa e y = r ∗ sina.*/

#include <stdio.h>
#include <math.h>

void lerPolar();

void converteEmCartesiano();

struct Coordenada
{
    float x;
    float y;
    float raio;
    float argumento;
};

int main(void)
{
    struct Coordenada coordenada;

    lerPolar();

    converteEmCartesiano();

    return 0;
}

void lerPolar()
{
    struct Coordenada coordenada;

    printf("Digite o raio:");
    scanf("%f", &coordenada.raio);

    printf("Digite o argumento (radianos):");
    scanf("%f", &coordenada.argumento);
}


void converteEmCartesiano()
{
    struct Coordenada coordenada;

    float pi = 3.141592;
    float graus;

    graus = (180*pi)/coordenada.argumento;

    coordenada.x = coordenada.raio*cos(graus);
    coordenada.y = coordenada.raio*sin(graus);

    printf("\nConvertendo coordenadas polares em coordenadas cartesianas...\n");

    printf("X = %.f e Y = %.f.\n", coordenada.x, coordenada.y);
}