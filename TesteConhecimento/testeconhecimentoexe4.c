#include<stdio.h>

int main(void)
{
	int inicio, fim, n;
	printf("Digite o primeiro n�mero do intervalo: \n");
	scanf("%d", &inicio);
	printf("Digite o ultimo n�mero do intervalo: \n");
	scanf("%d", &fim);
	printf("Digite a quantidade de termos, incluindo o inicio e o fim: \n");
	scanf("%d", &n);
	int soma = (fim + inicio)*n/2;
	
	
	printf("A soma � %d", soma);
}
