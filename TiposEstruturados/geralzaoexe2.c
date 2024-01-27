#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	int matricula;
	char nome[80];
	char turma[20];
	float nota[3];
	float media;
}Aluno;

void matricula(int n,Aluno** alunos)
{
	int i;
	
	for(i = 0; i < n; i++)
	{
		printf("Digite o nome do aluno %d: ", i+1);
		scanf(" %[^\n]", alunos[i]->nome);
		
		printf("Digite a matrícula do aluno %d: ", i+1);
		scanf(" %d", &alunos[i]->matricula);
		
		printf("Digite a turma aluno %d: ", i+1);
		scanf(" %[^\n]", alunos[i]->turma);
	}
}

void lanca_notas(int n, Aluno** alunos)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("Digite a primeira nota do aluno %d: ", i+1);
		scanf(" %f", &alunos[i]->nota[0]);
		
		printf("Digite a segunda nota do aluno %d: ", i+1);
		scanf(" %f", &alunos[i]->nota[1]);
		
		printf("Digite a terceira nota do aluno %d: ", i+1);
		scanf(" %f", &alunos[i]->nota[2]);
		alunos[i]->media = (alunos[i]->nota[2]+alunos[i]->nota[1]+alunos[i]->nota[0])/3;
	}
	
}

void imprime_tudo(int n, Aluno** alunos)
{
	printf("\n");
	printf("Lançe as notas dos alunos: ");
	int i;
	for(i = 0; i < n; i++)
	{
		printf("\n");
		printf("Nome do aluno %d é %s\n", i+1, alunos[i]->nome);
		
		printf("Matricula do aluno %d é %d\n", i+1, alunos[i]->matricula);
		
		printf("A turma do aluno %d é %s\n", i+1, alunos[i]->turma);
		
		printf("A primeira nota do aluno %d é %.3f\n", i+1, alunos[i]->nota[0]);
		
		printf("A segunda nota do aluno %d é %.3f\n", i+1, alunos[i]->nota[1]);
		
		printf("A terceira nora do aluno %d é %.3f\n", i+1, alunos[i]->nota[2]);
		
		printf("A média do aluno %d é %.3f\n", i+1, alunos[i]->media);
		printf("\n");
	}
}

void imprime_turma(int n, Aluno** alunos, char turma[])
{
	printf("\n");
	printf("Alunos da turma %s: \n", turma);
	int i;
	for(i = 0; i < n; i++)
	{
		if(strcmp(alunos[i]->turma, turma) == 0)
		{
			printf("\n");
			
			printf("Nome é %s\n", alunos[i]->nome);
		
			printf("Matricula %d\n", alunos[i]->matricula);
		
			printf("A primeira nota %.3f\n", alunos[i]->nota[0]);
		
			printf("A segunda nota %.3f\n", alunos[i]->nota[1]);
		
			printf("A terceira nora %.3f\n", alunos[i]->nota[2]);
		
			printf("A média %.3f\n", alunos[i]->media);
			
			printf("\n");
		}
	}	
}

void imprime_turma_aprovados(int n, Aluno**alunos, char turma[])
{
	int i;
	int aprovados = 0;
	printf("\n");
	printf("Aprovados da turma: %s", turma);
	for(i = 0; i < n; i++)
	{
		if(strcmp(alunos[i]->turma, turma) == 0 && alunos[i]->media >= 7)
		{
			aprovados++;
		}
	}
	if(aprovados>0)
	{
		for(i = 0; i < n; i++)
		{
			if(strcmp(alunos[i]->turma, turma) == 0)
			{
				printf("\n");
			
				printf("Aluno: %s aprovado com média: %.3f\n", alunos[i]->nome, alunos[i]->media);
			
				printf("\n");
			}
		}
	}
	else
	{
		printf("\n");
		printf("Nenhum aluno aprovado!\n");
		printf("\n");
	}	
}

int main(void)
{
	int nalunos, capmax;
	
	while(1)
	{
		int i;
		
		printf("Escolha a capacidade máxima de alunos na diciplina: \n");
		scanf("%d", &capmax);
		
		printf("Escolha quantidade de alunos: \n");
		scanf("%d", &nalunos);

		
		if(nalunos <= capmax)
		{
			Aluno** alunos = (Aluno**)malloc(nalunos*sizeof(Aluno*));
			if(alunos == NULL)
			{
				exit(1);
			}
			
			
			for(i = 0; i < nalunos; i++)
			{
				alunos[i] = (Aluno*)malloc(sizeof(Aluno));
			}
			
			
			matricula(nalunos, alunos);
			lanca_notas(nalunos, alunos);
			imprime_tudo(nalunos, alunos);
	
			char turma[20];
			printf("Escolha uma turma para ser impresso os integrantes: ");
			scanf(" %[^\n]", turma);
			imprime_turma(nalunos, alunos, turma);
			
			
			printf("Escolha uma turma para ser impresso os alunos aprovados: ");
			scanf(" %[^\n]", turma);
			imprime_turma_aprovados(nalunos, alunos, turma);
			
			for (i = 0; i < nalunos; i++) {
                free(alunos[i]);
            }

            free(alunos);
			break;
		}
		else
		{
			printf("Número de alunos maior que a capacidade máxima, escolha uma nova quantidade de alunos");
		}	
	}
	
}
