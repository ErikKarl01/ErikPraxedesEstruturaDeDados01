#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int genero;
    int feedback;
} RespostaEntrevista;

void processarRespostas(RespostaEntrevista *respostas, int numEntrevistas) {
    int numMasculino = 0, i, numFeminino = 0, gostouPorFeminino = 0, gostouPorMasculino = 0;

    for (i = 0; i < numEntrevistas; i++) {
        printf("Entrevista %d:\n", i + 1);
        printf("Digite 1 para Masculino ou 2 para Feminino: ");
        scanf("%d", &respostas[i].genero);

        if (respostas[i].genero == 1 || respostas[i].genero == 2) {
            printf("Digite 3 se gostou do produto ou 4 se não gostou: ");
            scanf("%d", &respostas[i].feedback);

            if (respostas[i].genero == 2 && respostas[i].feedback == 3) {
                gostouPorFeminino++;
            } else if (respostas[i].genero == 1 && respostas[i].feedback == 3) {
                gostouPorMasculino++;
            }

            if (respostas[i].genero == 1) {
                numMasculino++;
            } else if (respostas[i].genero == 2) {
                numFeminino++;
            }
        } else {
            printf("Opção inválida para gênero. Tente novamente.\n");
            i--;
        }
    }

    float porcentagemGostouFeminino = (numFeminino != 0) ? (gostouPorFeminino / (float)numFeminino) * 100 : 0;
    float porcentagemGostouMasculino = (numMasculino != 0) ? (gostouPorMasculino / (float)numMasculino) * 100 : 0;

    printf("\nPorcentagem de mulheres que gostaram: %.2f%%\n", porcentagemGostouFeminino);
    printf("Porcentagem de homens que gostaram: %.2f%%\n", porcentagemGostouMasculino);
}

int main() {
    printf("Digite a quantidade de entrevistas: ");
    int numEntrevistas = 0;
    scanf("%d", &numEntrevistas);

    RespostaEntrevista *respostas = (RespostaEntrevista *)malloc(numEntrevistas * sizeof(RespostaEntrevista));
    if (respostas == NULL) {
        printf("Erro!\n");
        exit(1);
    }

    processarRespostas(respostas, numEntrevistas);

    free(respostas);

    return 0;
}
