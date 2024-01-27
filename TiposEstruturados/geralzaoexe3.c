#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
	float h;
	float b;
} Ret;

typedef struct
{
	float raio;
} Circ;

Ret* ret_circunscrito(Circ* c, float h)
{
    Ret* ret = (Ret*)malloc(sizeof(Ret));
    if(ret == NULL)
    {
        printf("Error!");
        exit(1);
    }
    ret->h = h;
    ret->b = 2 * sqrt(pow(c->raio, 2) - pow(h / 2, 2));
    return ret;
}

Circ* circ_interno(Ret* r)
{
    
	Circ *circulo=(Circ*)malloc(sizeof(Circ));
    if(circulo==NULL)
	{
        exit(1);
    }
    
	if(r->h < r->b)
	{
        circulo->raio= r->h/2.0;
    }
	else if(r->b < r->h)
	{
        circulo->raio= r->b/2.0;
    }
    return(circulo);
}

int main(void)
{
    float h;
    Circ* c = (Circ*)malloc(sizeof(Circ));
    float raio;

    printf("Escolha o raio do círculo para calcular o maior retângulo circunscrito: \n");
    scanf("%f", &raio);
    c->raio = raio;
    
    printf("Escolha a altura do retângulo: \n");
    scanf(" %f", &h);

    while (2 * c->raio < h)
    {
        printf("Valor inválido de altura!\n");
        printf("Escolha outro valor de altura (Deve ser menor que o diâmetro do círculo)!\n");
        scanf(" %f", &h);
    }

    Ret* retangulo = ret_circunscrito(c, h);

    printf("Base: %.5f e altura: %.5f\n", retangulo->b, retangulo->h);

    
	Ret* ret2 = (Ret*)malloc(sizeof(Ret));
	printf("\n");
	printf("\n");
	printf("Escolha a altura do retangulo para calcular o maior raio do círculo que cabe nele: \n");
	scanf("%f", &ret2->h);
	printf("Escolha a largura do retangulo: \n");
	scanf("%f", &ret2->b);
	
	Circ* circulo2 =  circ_interno(ret2);
	printf("Raio do maior círculo interno ao retângulo é: %.5f", circulo2->raio);
	
	
	free(retangulo);
    free(c);
    free(circulo2);
    return 0;
}
