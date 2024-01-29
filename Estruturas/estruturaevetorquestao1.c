#include<stdio.h>
#include<string.h>

struct Funcionario{
	char nome[30];
	float salario;
	int identificador;
	char cargo[20];
};

void cadastrafuncionario(struct Funcionario individuo[], int qt)
{
	int i;
	for(i = 0; i < qt; i++)
	{
		printf("\n");
		printf("Nome:\n");
		scanf(" %[^\n]s", individuo[i].nome);
		printf("Salario:\n");
		scanf(" %f", &individuo[i].salario);
		printf("Identificador:\n");
		scanf(" %d", &individuo[i].identificador);
		printf("Cargo:\n");
		scanf(" %[^\n]s", individuo[i].cargo);
		printf("\n");
	}
}

int pesquisafuncionario(struct Funcionario individuo[], int qt)
{
	char pessoa[30];
	int i;
	printf("Digite o nome:\n");
	scanf(" %[^\n]s", pessoa);
	for(i = 0; i < qt; i++)
	{
		if(strcmp(individuo[i].nome, pessoa) == 0)
		{
			return i;
		}
	}
	return -1;
}

void imprimir(struct Funcionario individuo[], int qt)
{
	int i;	
	for(i = 0; i < qt; i++)
	{
		printf("\n");
		printf("\n");
		printf("Nome: %s\n", individuo[i].nome);
		printf("Salario: %.2f\n", individuo[i].salario);
		printf("Identificador: %d\n", individuo[i].identificador);
		printf("Cargo: %s\n", individuo[i].cargo);
		printf("\n");
		printf("\n");	
	}
	
}

void compararsal(struct Funcionario individuo[], int qt)
{
	int i, indexmaior = 0, indexmenor = 0;
	float maior = 0, menor = 0;
	for(i = 0; i < qt; i++)
	{
		if(individuo[i].salario > maior)
		{
			maior = individuo[i].salario;
			indexmaior = i;
		}
	}
	menor += maior;
	
	for(i = 0; i < qt; i++)
	{
		if(individuo[i].salario < menor)
		{
			menor = individuo[i].salario;
			indexmenor = i;
		}
	}
	printf("\n");
	printf("O menor salário foi de %s no valor de %.2f\n", individuo[indexmenor].nome, menor);
	printf("O maior salario foi de %s no valor de %.2f\n", individuo[indexmaior].nome, maior);
}

void alterarsal(struct Funcionario *individuo)
{
	printf("\n");
	printf("Quanto deseja para novo salario?\n");
	scanf(" %f", &individuo->salario);
	printf("\n");
}

int main(void)
{
	int qt;
	printf("Escolha uma quantidade de funcionários para cadastrar: \n");
	scanf("%d", &qt);
	printf("\n");
	
	
	struct Funcionario individuo[qt];
	char resposta[4];
	int i, index;
	
	
	cadastrafuncionario(individuo, qt);
	imprimir(individuo, qt);
	
	
	printf("\n");
	printf("Deseja aumentar o salario(sim ou nao)?\n");
	scanf("%s", resposta);
	if (strcmp(resposta, "sim")==0)
	{
		index = pesquisafuncionario(individuo, qt);
		if(index == -1)
		{
			printf("\n");
			printf("Pessoa não encontrada\n");
		}
		else
		{
			alterarsal(&individuo[index]);
			imprimir(individuo, qt);
		}
	}
	
	
	compararsal(individuo, qt);
	
	return 0;
}
