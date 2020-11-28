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
void CARGAR (struct BASEDAT[], struct AUMENTO[], int);
void ACTUALIZACION (struct BASEDAT [], struct AUMENTO [], int);

int main()
{
	struct BASEDAT VEC[N];
	struct AUMENTO VEC2[5];
	srand(time(0));
	CARGAR (VEC, VEC2, N);
	MIRAR (VEC, N);
	ACTUALIZACION(VEC, VEC2, N);
	return 0;
}

void CARGAR (struct BASEDAT vec[],struct AUMENTO vec2[], int n)
{
	int i, j;
	
	char descripcion[12][50] = {"HARINA", "MAIZENA", "FIDEOS", "CAFE", "AZUCAR", "YERBA", "ARROZ", "LENTEJAS", "LECHE", "QUESO", "DESODORANTE", "JABON"};
	char proveedor[12][20] = {"MAROLIO", "MAROLIO", "LUCHETTI", "LEDESMA", "LEDESMA", "LEDESMA", "LUCHETTI", "MAROLIO", "SERENISIMA", "SERENISIMA", "AVON", "AVON"};
	char prov_aum[6][20] = {"MAROLIO", "LUCHETTI", "LEDESMA", "SERENISIMA", "AVON", "FIN"};
	float precio[12] = {55.40, 33.80, 49.50, 70.30, 58.99, 45.66, 20.59, 22.40, 69.30, 45.12, 90.50, 00.00};
	
	for (i=0; i<n; i++)
	{
		vec[i].ART = 2 + rand() % 99;
		strcpy(vec[i].DESC, descripcion[i]);
		strcpy(vec[i].PROV, proveedor[i]);
		vec[i].PRECIO = precio[i];
	}
	
	for (i=0; i<6; i++)
	{
		strcpy(vec2[i].PROV, prov_aum[i]);
		vec2[i].AUM = i+20;	
	}
}

void MIRAR (struct BASEDAT vec[], int n)
{
	int i, j;
	printf("\n %s \t %s \t %s \t %s \n\n", "ART", "DESCRIPCION", "PROVEEDOR", "PRECIO");
	for (i=0; i<n; i++)
		printf("\n %d \t %s \t %s \t %.2f", vec[i].ART, vec[i].DESC, vec[i].PROV, vec[i].PRECIO);
}

void ACTUALIZACION (struct BASEDAT vec[], struct AUMENTO vec2[], int n)
{
	int i, j;
	struct BASEDAT aux;
	printf("\n\n");
	for (i=0; i<n-1; i++)
		for (j=0; j<n-i-1; j++)
			if (vec[j].ART < vec[j+1].ART)
			{
				//swapping
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;				
			}
	
	for (i=0; strcmp(vec2[i].PROV,"FIN"); i++)
		for (j=0; j<n; j++)
			if(strcmp(vec2[i].PROV, vec2[j].PROV) == 0)
               vec[j].PRECIO += vec2[i].AUM;
	
	printf("\n %s \t %s \t %s \t %s \t %s \n\n", "ART", "DESCRIPCION", "PROVEEDOR", "PRECIO", "AUMENTO");
	for (i=0; i<n; i++)
		printf("\n %d \t %s \t %s \t %.2f \t %.2f",vec[i].ART,vec[i].DESC,vec[i].PROV,vec[i].PRECIO, vec2[i].AUM);
}






