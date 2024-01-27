#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>



typedef struct
{
	float preco;
	char local[20];
	char atracao[20];

}Ingresso;

void preenche(Ingresso* i)
{
	printf("\n");
	printf("Digite o local.\n");
	scanf(" %[^\n]", i->local);
	printf("Digite o preco.\n");
	scanf(" %f", &i->preco);
	printf("Digite o atracao.\n");
	scanf(" %[^\n]", i->atracao);
	printf("\n");
}

void imprime(Ingresso* i)
{
	printf("\n");
	printf("Local: %s\n", i->local);
	printf("Preco: %.2f\n", i->preco);
	printf("Atracao: %s\n", i->atracao);
	printf("\n");
}

void altera_preco(Ingresso* i, float valor)
{
	i->preco = valor;
}

void imprime_menor_maior_preco(int n, Ingresso* vet)
{
	if(n == 1)
	{
		printf("Unico evento: %s\n", vet[0].atracao);
	}
	else
	{
		int i, indmaior = 0, indmenor  =0;
		float maior = 0, menor = 0;
	
		for(i = 0; i < n; i++)
		{
			if(vet[i].preco > maior)
			{
				indmaior = i;
			}
		}
	
		menor += maior;
	
		for(i = 0; i < n; i++)
		{
			if(vet[i].preco < menor)
			{
				indmenor = i;
			}
		}
		printf("\n");
		printf("Mais caro: %s\n", vet[indmaior].atracao);
		printf("Mais barato: %s\n", vet[indmenor].atracao);
		printf("\n");
	}
	
}

int main(void)
{
	int qt, i;
	
	printf("Digite a quantidade de eventos.\n");
	scanf("%d", &qt);
	Ingresso *ingresso = (Ingresso*)malloc(qt*sizeof(Ingresso));
	if(ingresso == NULL)
	{
		exit(1);
	}
	
	for(i = 0; i < qt; i++)
	{
		preenche(&ingresso[i]);
	}
	
	for(i = 0; i < qt; i++)
	{
		imprime(&ingresso[i]);
	}
	
	char nome[20];
	printf("\n");
	printf("Escolha um ingresso para alterar(Digite o nome da atracao).\n");
	scanf(" %[^\n]", nome);
	
	for(i = 0; i < qt; i++)
	{
		if(strcmp(ingresso[i].atracao, nome) == 0)
		{
			float valor = 0;
			printf("\n");
			printf("Escolha um valor: \n");
			scanf(" %f", &valor);
			altera_preco(&ingresso[i], valor);
		}
		
	}
	
	imprime_menor_maior_preco(qt, ingresso);
	for(i = 0; i < qt; i++)
	{
		imprime(&ingresso[i]);
	}
	
	free(ingresso);
	
	return 0;
		
}
