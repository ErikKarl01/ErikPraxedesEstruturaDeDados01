#include<stdio.h>

void inverter(int* vet, int n)
{
	int i, temp;
	for(i = 0; i < n/2; i++)
	{
		temp = vet[i];
		vet[i] = vet[n - i -1];
		vet[n - i -1] = temp;
	}
}

int main(void)
{
	int n, i;
	printf("Quantidade de termos: \n");
	scanf("%d", &n);
	int vet[n];
	
	for(i = 0; i < n; i++)
	{
		printf("Digite o termo %d: \n", i);
		scanf(" %d", &vet[i]);
	}
	
	inverter(vet, n);
	printf("Ao inverter temos: \n");
	for(i = 0; i < n; i++)
	{
		printf("O termo %d: %d\n", i, vet[i]);
	}
}
