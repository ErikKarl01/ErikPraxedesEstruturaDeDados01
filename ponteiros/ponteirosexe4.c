#include<stdio.h>
#include<math.h>

void calcula_hexagono(float l, float *area, float *perimetro)
{
  *perimetro = 6*l;
  *area = (3*sqrt(l)*pow(l, 2))/2;
	
};


int main(void) 
{
	float l, area, perimetro;
	
	printf("digite o valor do lado do hexagono: \n");
	scanf("%f", &l);
	calcula_hexagono( l, &area, &perimetro);
	
	printf("A �rea � %f e o per�metro � %f", area, perimetro);
	return 0;
}
