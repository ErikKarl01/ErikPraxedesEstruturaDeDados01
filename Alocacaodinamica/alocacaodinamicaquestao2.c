#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int nquestoes, nalunos, acertos;

void compararesposta(char** aluno, char gabarito[])
{
	int i, j, alunospassou = 0;
	float porcent;
	for(i = 0; i < nalunos; i++)
	{
		acertos = 0;
		for(j = 0; j < nquestoes; j++)
		{
			if(aluno[i][j] == gabarito[j])
			{
				acertos++;
			}
			
		}
		if(acertos*(10/nquestoes)>=6)
		{
			alunospassou++;
		}
		printf("O aluno %d obteve %d acertos.\n", i+1, acertos);	
	}
	
	porcent = ((float)alunospassou/nalunos)*100;//dividir inteiro por inteiro vai dar um inteiro
	printf("A porcentágem de alunos que passaram foi de %f.\n", porcent);
	
	
	
}


int main(void)
{
	int i, j;
	float porcapr;
	char** aluno;
	
	printf("Digite um numero de alunos: \n");
	scanf("%d", &nalunos);
	printf("escolha um número de questões: \n");
	scanf("%d", &nquestoes);
	
	char gabarito[nquestoes];
	aluno = (char**)malloc(nalunos*sizeof(char*));
	
	for(i = 0; i < nalunos; i++)
	{
		*(aluno + i) = (char*)malloc(nquestoes*sizeof(char));
	}
	
	for(i = 0; i < nquestoes; i++)
	{
		printf("Escolha a resposta da questão %d:\n", i+1);
		scanf(" %c", &gabarito[i]); //%c que lê um unico caractere ao invês de uma string
	}
	
	for(i = 0; i < nalunos; i++)
	{
		for(j = 0; j < nquestoes; j++)
		{
			printf("Escolha a resposta do aluno %d:\n", i+1);
			scanf(" %c", *(*(aluno+i)+j));
		}
	}
	
	compararesposta(aluno, gabarito);
	
	for (i = 0; i < nalunos; i++) {
        free(*(aluno + i));
    }
    free(aluno);
	
	
}
