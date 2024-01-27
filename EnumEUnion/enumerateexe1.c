#include<stdio.h>
#include<stdlib.h>

typedef enum
{
	masculino,
	feminino
}Genero;

typedef struct
{
	char nome[80];
	int idade;
	Genero genero_pessoa;
}Pessoa;

int main(void)
{
	Pessoa *pessoa = (Pessoa*)malloc(sizeof(Pessoa));
	
	printf("Digite o nome: \n");
	scanf(" %[^\n]", pessoa->nome);
	printf("Digite a idade: \n");
	scanf(" %d", &pessoa->idade);
	printf("Digite o genero, 0 para masculino e 1 para feminino: \n");
	scanf(" %d", &pessoa->genero_pessoa);
	
	printf("\n");
	printf("\n");
	printf("Nome: %s\n", pessoa->nome);
	printf("Idade: %d\n", pessoa->idade);
	
	if(pessoa->genero_pessoa)
	{
		printf("Gênero feminino!\n");
	}
	else
	{
		printf("Gênero masculino!\n");
	}
	
}
