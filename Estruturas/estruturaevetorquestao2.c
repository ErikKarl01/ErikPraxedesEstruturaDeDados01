#include<stdio.h>
#include<string.h>
#include<stdbool.h>


struct Pessoa{
	char nome[30];
	int idade;
	int documento;
};

int qt;

void registrar (struct Pessoa *individuo) //ponteiro para primeiro elemento array individuo
{
	int i;
	for(i = 0; i < qt; i++)
	{
		printf("\n");
		printf("Nome:\n");
		scanf(" %[^\n]s", individuo[i].nome);
		printf("Idade:\n");
		scanf("%d", &individuo[i].idade);//fornecer endereço do primeiro elemento
		printf("Documento:\n");
		scanf("%d", &individuo[i].documento);
		printf("\n");
	}
}

void listar(struct Pessoa individuo[])
{
	int i;
	for(i = 0; i < qt; i++)
	{
		printf("\n");
		printf("\n");
		printf("Nome: %s\n", individuo[i].nome);
		printf("Documento: %d\n", individuo[i].documento);
		printf("Idade: %d\n", individuo[i].idade);
		printf("\n");
		printf("\n");
	}	
}

int attidade(struct Pessoa *individuo)
{
	char pessoa[30];
	int achou = -1, i;
	printf("\n");
	printf("Nome da pessoa que se deseja alterar a idade:\n");
	scanf("%s", pessoa);
	for(i = 0; i < 4; i++)
	{
		if(strcmp(individuo[i].nome, pessoa) == 0)
		{
			achou = i;
			break;
		}
	}
	if(achou>=0 && achou < 4)
	{
		printf("\n");
		printf("Digite a nova idade: \n");
		scanf(" %d", &individuo[achou].idade);
		return 1;
	}
	else
	{
		printf("\n");
		printf("Pessoa não encontrada!\n");
		return 0;
	}
	
}

void compararidade(struct Pessoa individuo[])
{
	int maior = 0, menor = 0, i, indexmenor = 0, indexmaior = 0;
	for(i = 0; i < qt; i++)
	{
		if(individuo[i].idade > maior)
		{
			maior = individuo[i].idade;
			indexmaior = i;
		}
	}
	menor += maior;
	
	for(i = 0; i < qt; i++)
	{
		if(individuo[i].idade < menor)
		{
			menor = individuo[i].idade;
			indexmenor = i;
		}
	}
	printf("\n");
	printf("A pessoa de maior idade é %s de idade %d\n", individuo[indexmaior].nome, maior);
	printf("A pessoa de menor idade é %s de idade %d\n", individuo[indexmenor].nome, menor);
	printf("\n");
}

int main(void)
{
	printf("Digite a quantidade de pessoas: \n");
	scanf("%d", &qt);
	struct Pessoa individuo[qt];
	char continuar[3];
	
	registrar(individuo);
	listar(individuo);
	while(true){
		printf("Deseja atualizar a idade de uma pessoa(sim ou nao)?\n");
		scanf("%s", continuar);
		if(strcmp(continuar, "sim") == 0)
		{
			attidade(individuo);
		}
		else
		{
			listar(individuo);
			break;
		}	
	}
	
	compararidade(individuo);
	
	return 0;
}
