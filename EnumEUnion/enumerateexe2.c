#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef union
{
	char alimento[20];
	char bebida[20];
	char eletronico[20];
}Tipo;

typedef struct
{
	char nome[20];
	float preco;
	Tipo tipo_produto;
}Produto;

int main(void)
{
	Produto *produto = (Produto*)malloc(sizeof(Produto));
	char tipoprod[20];
	
	printf("Digite o nome do produto: \n");
	scanf(" %[^\n]", produto->nome);
	printf("Digite o preço do produto: \n");
	scanf("%f", &produto->preco);
	printf("Digite o tipo do produto (Alimento, Bebida ou Eletronico): \n");
	scanf("%s", tipoprod);
	
	if(strcmp(tipoprod, "Alimento"))
	{
		strcpy(produto->tipo_produto.alimento, tipoprod);
	}
	else if(strcmp(tipoprod, "Bebida"))
	{
		strcpy(produto->tipo_produto.bebida, tipoprod);
	}
	else if(strcmp(tipoprod, "Eletronico"))
	{
		strcpy(produto->tipo_produto.eletronico, tipoprod);
	}
	
	printf("\n");
	printf("\n");
	printf("Nome: %s\n", produto->nome);
	printf("Preço: %.2f\n", produto->preco);
	printf("Tipo: %s\n", produto->tipo_produto);
	
	free(produto);
}

