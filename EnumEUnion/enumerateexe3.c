#include<stdio.h>
#include<stdlib.h>

typedef enum
{
	JANEIRO,
	FEVEREIRO, 
	MARCO, 
	ABRIL, 
	MAIO,
	JUNHO, 
	JULHO, 
	AGOSTO, 
	SETEMBRO, 
	OUTUBRO, 
	NOVEMBRO,
	DEZEMBRO
}Mes;

typedef struct
{
	int dia;
	int ano;
	Mes mes;
}Data;

int main(void)
{
	Data* data = (Data*)malloc(sizeof(Data));
	
	printf("Digite o dia: \n");
	scanf("%d", &data->dia);
	printf("Digite o mes(1 para janeiro, 2 para fevereiro e assim sucessivamente): \n");
	scanf("%d", (int*)&data->mes); 
	printf("Digite o ano: \n");
	scanf("%d", &data->ano);
	
	printf("\n");
	printf("\n");
	printf("%02d/%02d/%04d", data->dia, data->mes+1, data->ano);
	free(data);
}
