#include <stdio.h>
#include <string.h>

#define ALUM 4
#define MATE 10

struct LIBRETA {
	char MATERIA[MATE][20];
	int NOTA[MATE];
};

struct ALUMNO {
	char NOMBRE[20];
	struct LIBRETA ASIGNATURA;
};

void CARGAR (struct ALUMNO[], int, int);
void MIRAR (struct ALUMNO[], int, int);
void DESAPRUEBA (struct ALUMNO [], int, int);

int main ()
{
	struct ALUMNO vector[ALUM];	
	srand(time(0));
	CARGAR (vector, ALUM, MATE);
	MIRAR (vector, ALUM, MATE);
	DESAPRUEBA (vector, ALUM, MATE);
	return 0;
}

void CARGAR (struct ALUMNO vec[], int A, int M)
{
	int i, j;
	char aux_materias[10][20] = {"Matematica", "Fisica", "Quimica", "Economia", "Algebra", "Informatica", "Legislacion", "Tecnologias", "Redaccion", "Proyectos"};

	for (i=0; i<A; i++)
	{
		printf("\nIngrese nombre del alumno:");
		fflush(stdin);
		gets(vec[i].NOMBRE);
		for (j=0; j<M; j++)
		{
			strcpy(vec[i].ASIGNATURA.MATERIA[j], aux_materias[j]);
			vec[i].ASIGNATURA.NOTA[j] = rand() % 11;
		}
	}
}

void MIRAR (struct ALUMNO vec[], int A, int M)
{
	int i, j;
	printf("\n%s %5s %5s %5s %5s %5s %5s %5s %5s %5s %5s\n\n", "ALUM", "Mat", "Fis", "Qui", "Eco", "Alg", "Inf", "Leg", "Tec", "Red", "Pro");
	for (i=0; i<A; i++)
	{
		printf("\n");
		printf("%s", vec[i].NOMBRE);
		for (j=0; j<M; j++)
			printf("%6d", vec[i].ASIGNATURA.NOTA[j]);
	}
}
	
void DESAPRUEBA (struct ALUMNO vec[], int A, int M)	
{
	int i, j;
	char auxiliar[20];
	printf("\nIngrese materia:");
	fflush(stdin);
	gets(auxiliar);
	for (i=0; i<A; i++)
		for (j=0; j<M; j++)
			if (stricmp(vec[i].ASIGNATURA.MATERIA[j], auxiliar) == 0)
				if (vec[i].ASIGNATURA.NOTA[j]<4)
					printf("\n%s debe rendir recuperatorio.\n", vec[i].NOMBRE);
}














