#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

struct DATOS {
	char NOMBRE[20];
	char SEXO;
	int HANDI;
};

struct PAREJA {
	struct DATOS MUJER;
	struct DATOS HOMBRE;
};

void CARGAR (struct PAREJA [], int);
void ORDENAR (struct PAREJA [], int);
void MIRAR (struct PAREJA [], int);


int main()
{
	struct PAREJA VEC[MAX];
	
	CARGAR (VEC, MAX);
	MIRAR (VEC, MAX);
	ORDENAR (VEC, MAX);
	MIRAR (VEC, MAX);
	
	return 0;
}

void CARGAR (struct PAREJA vec[], int M)
{
	int i;
	for (i=0; i<M; i++)
	{
		// CARGA DE INTEGRANTE FEMENINO
		printf("\nIngrese nombre jugador femenino:");
		gets(vec[i].MUJER.NOMBRE);
		fflush(stdin);
		vec[i].MUJER.SEXO = 'F';
		printf("\nIngrese su handicap:");
		scanf("%d", &vec[i].MUJER.HANDI);
		fflush(stdin);
		// CARGA DE INTEGRANTE MASCULINO
		printf("\nIngrese nombre jugador masculino:");
		gets(vec[i].HOMBRE.NOMBRE);
		fflush(stdin);
		vec[i].HOMBRE.SEXO = 'M';
		printf("\nIngrese su handicap:");
		scanf("%d", &vec[i].HOMBRE.HANDI);
		fflush(stdin);
	}
}

void ORDENAR (struct PAREJA vec[], int M)
{
	int i, j;
	struct PAREJA aux;
	
	for (i=0; i<M-1; i++)
		for (j=0; j<M-i-1; j++)
			if (vec[j].HOMBRE.HANDI < vec[j+1].HOMBRE.HANDI)
			{
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
			}	
	for (i=0; i<M-1; i++)
		for (j=0; j<M-i-1; j++)
			if (vec[j].MUJER.HANDI > vec[j+1].MUJER.HANDI)
			{
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
			}	
			
}

void MIRAR (struct PAREJA vec[], int M)
{
	int i;
	printf("\n%-10s %-10s %-10s %-10s %-10s %-10s", "JUGADORA", "SEXO", "HANDI", "JUGADOR", "SEXO", "HANDI");
		for (i=0; i<M; i++)
		{
			printf("\n%-10s %-10c %-10d %-10s %-10c %-10d", vec[i].MUJER.NOMBRE, vec[i].MUJER.SEXO, vec[i].MUJER.HANDI, vec[i].HOMBRE.NOMBRE, vec[i].HOMBRE.SEXO, vec[i].HOMBRE.HANDI);
			fflush(stdin);
		}	
}






