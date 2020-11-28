// ME FALTA EL PUNTO C Y D

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 2

struct FECHA{
	int DIA;
	int MES;
	int ANIO;
};

struct ALUMNO {
	char NOMBRE[20];
	char SEXO;
	int NOTA[20];
	struct FECHA NAC;
};

void CARGAR (struct ALUMNO[], int);
void MIRAR (struct ALUMNO [], int);


int main()
{
	struct ALUMNO VEC[NUM];	
//	int CODIGO[MAT];
	CARGAR (VEC, NUM);
	MIRAR (VEC, NUM);
	return 0;
}

void CARGAR (struct ALUMNO vec[], int N)
{
	int i, j, dia, mes, anio;
	char nombre[20];
	char sexo;
	for (i=0; i<N; i++)
	{
		printf("\nIngrese nombre de alumno:");
		fflush(stdin);
		gets(nombre);
		strcpy(vec[i].NOMBRE, nombre);
		printf("\nIngrese su sexo:");
		fflush(stdin);
		scanf("%c", &sexo);
		vec[i].SEXO = sexo;
		printf("\nIngrese fecha de nacimiento:");
		fflush(stdin);
		scanf("%d/%d/%d", &dia, &mes, &anio);
		vec[i].NAC.DIA = dia;
		vec[i].NAC.MES = mes;
		vec[i].NAC.ANIO = anio;
		printf("\nIngrese Notas:");
		fflush(stdin);
		for (j=0; j<3; j++)
			scanf("%d", &vec[i].NOTA[j]);
	}
}

void MIRAR (struct ALUMNO vec[], int N)
{
	int i, j;
	printf("\n\nNOMBRE \t SEXO \t NACIMIENTO \t NOTAS");
	for (i=0; i<N; i++)
	{
		printf("\n%s \t %c \t %d/%d/%d \t", vec[i].NOMBRE);
		for (j=0; j<3; j++)
			printf("%2d", vec[i].NOTA[j]);
	}
}	

/*
int PROM_F (struct ALUMNO vec[], int N)
{
	int i, j, suma=0, cont=0, prom_f;
	for (i=0; i<N, i++)
		if (vec[i].SEXO == 'F')
			for (j=0; j<MAT; j++)
			{
				suma += vec[i].NOTAS[j];
				cont++;
			}
	prom_f = suma/cont;
	return prom_f;
}

int PROM_M (struct ALUMNO vec[], int N)
{
	int i, j, suma=0, cont=0, prom_m;
	for (i=0; i<N, i++)
		if (vec[i].SEXO == 'M')
			for (j=0; j<MAT; j++)
			{
				suma += vec[i].NOTAS[j];
				cont++;
			}
	prom_m = suma/cont;
	return prom_m;
}

*/




