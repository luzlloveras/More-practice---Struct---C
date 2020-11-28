#include <stdio.h>
#include <string.h>

#define N 12

struct BASEDAT {
	int ART;		// Numero de artiulo
	char DESC[50];	// Descripcion del articulo
	char PROV[20];	// Nombre del proveedor
	float PRECIO; 	// Precio del articulo
};

struct AUMENTO {
	char PROV[20];	// Nombre del proveedor
	float AUM;		// Aumento porcentual a aplicar
};

void MIRAR (struct BASEDAT[], int);
void CARGAR (struct BASEDAT[], int);

int main()
{
	struct BASEDAT vector[N];
	struct AUMENTO vector_2[N];
	srand(time(0));
	MIRAR (vector, N);
	CARGAR (vector, N);
	
	
	return 0;
}

void CARGAR (struct BASEDAT vec[], int L)
{
	int i, j;
	char descripcion[12][30] = {"HARINA", "MAIZENA", "FIDEOS", "CAFE", "AZUCAR", "YERBA", "ARROZ", "HUEVOS", "LECHE", "QUESO", "DETERGENTE", "JABON"};
	char proveedor[12][30] = {"MAROLIO", "SANCOR", "MATARAZZO", "LA VIRGINIA", "LEDESMA", "PAYADITO", "LUCHETTI", "LA GRANJA", "LA SERENISIMA", "VERONICA", "MAGISTRAL", "AVON"};
	float precio[12] = {55.40, 33.80, 49.50, 70.30, 58.99, 45.66, 20.59, 22.40, 69.30, 45.12, 90.50, 79.80};	
	for (i=0; i<L; i++)
		for (j=0; j<L; j++)
		{
			vec[i].ART = rand() % 11;
			strcpy(vec[i].DESC, descripcion[j]);
			strcpy(vec[i].PROV, proveedor[j]);
			vec[i].PRECIO = precio[j];
		}
}

void MIRAR (struct BASEDAT vec[], int L)
{
	int i, j;
	printf("\nART \t DESCRIPCION \t PROVEEDOR \t PRECIO\n");
	fflush(stdin);
	for (i=0; i<L; i++)
			printf("%d", vec[i].ART);
}





