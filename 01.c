#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 7

struct FECHA {
	int DIA;
	int MES;
	int ANIO;
};

struct INTEGRANTE {
	char NOMBRE[20];
	char SEXO;
	struct FECHA NAC;
};

void CARGAR (struct INTEGRANTE[], int);
void MIRAR (struct INTEGRANTE[], int);
void ORDENAR_SEXO (struct INTEGRANTE[], int);
void ORDENAR_CATEGORIA (struct INTEGRANTE[], int);

int main()
{
	struct INTEGRANTE VEC[MAX];
	
	srand(12883);
	
	CARGAR (VEC, MAX);
	MIRAR (VEC, MAX);
	ORDENAR_CATEGORIA(VEC, MAX);
	MIRAR (VEC, MAX);
	printf("\n\n\n");
	return 0;
}

void CARGAR (struct INTEGRANTE vec[], int M)
{
	int i;
	for (i=0; i<M; i++)
	{
		printf("\nIngrese nombre de integrante: ");
		gets(vec[i].NOMBRE);
		fflush(stdin);
		printf("\nIngrese sexo: ");
		scanf("%c", &vec[i].SEXO);
		fflush(stdin);
		vec[i].NAC.DIA = 1 + rand() % 29;
		vec[i].NAC.MES = 1 + rand() % 12;
		vec[i].NAC.ANIO = 2005 + rand() % 5;
	}
}

void MIRAR (struct INTEGRANTE vec[], int M)
{
	int i;
	printf("\n\n %-20s %-20s %-20s\n", "NOMBRE", "SEXO", "FECHA DE NACIMIENTO");
	for (i=0; i<M; i++)
		printf("\n%-20s %-20c %02d : %02d : %d", vec[i].NOMBRE, vec[i].SEXO, vec[i].NAC.DIA, vec[i].NAC.MES, vec[i].NAC.ANIO);
}

void ORDENAR_SEXO (struct INTEGRANTE vec[], int M)
{
	int i, j;
	struct INTEGRANTE aux[M];
	
	for (i=0; i<M-1; i++)
		for (j=0; j<M-i-1; j++)
			if (vec[j].SEXO != 'F')
			{
				aux[j] = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux[j];
			}	
}


void ORDENAR_CATEGORIA (struct INTEGRANTE vec[], int M)
{
	int i, j;
	struct INTEGRANTE aux[M];
	ORDENAR_SEXO(vec, M);
	for (i=0; i<M-1; i++)
		for (j=0; j<M-i-1; j++)
			if (vec[j].NAC.ANIO < vec[j+1].NAC.ANIO)
			{
				aux[j] = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux[j];
			}
}

			
			
