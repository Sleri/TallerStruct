#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>

/* 
* Programa: Uso de la figura struct con funciones
* Fecha: 30 de octubre de 2018
* Elaborado por: Natalia Agudelo Valdes
*/

struct producto{
	int cod;
	char nom[20];
	float precio;
};

struct tienda{
	struct producto prod[4];
}datos[4];

void crear(struct tienda datosR[4]){
	for(int j = 0; j < 4; j++){
		printf("Tienda %d: \n", j + 1);
		for(int i = 0; i < 4; i++){
			printf("Producto %d: \n", i + 1);
			printf("Ingrese el codigo: ");
			scanf("%d", &datosR[j].prod[i].cod);
			fflush(stdin);
			printf("Ingrese la descripcion: ");
			gets(datosR[j].prod[i].nom);
			fflush(stdin);
			printf("Ingrese el precio: ");
			scanf("%f", &datosR[j].prod[i].precio);
			fflush(stdin);
			printf("\n");
		}
		printf("\n");
	}	
}



//se crea un struct nuevo dentro de los limites de la funcion
void imprimir(struct tienda p[4]){
	printf("\nDatos: \n");
	for(int j = 0; j < 4; j++){
		printf("Tienda %d: \n", j + 1);
		for(int i = 0; i < 4; i++){
			printf("Producto %d: ", i + 1);
			printf("\nCodigo del producto: %d\n", p[j].prod[i].cod);  //se llama lo que se necesite (.cod) con el nombre de la nueva estructura
			printf("Descripcion del producto: %s\n", p[j].prod[i].nom);
			printf("Precio del producto: %.0f\n", p[j].prod[i].precio);
			printf("\n");
		}
		printf("\n");
	}
}

void sumar(struct tienda suma[4]){
	float operacion[4];
	int j = 0, k = 1, m = 2, n = 3, i = 0;
	printf("\nSumatoria de los productos en todas las tiendas: \n");
	printf("\n");
	do{
		printf("Producto %d: ", i + 1);
		operacion[j] = suma[j].prod[i].precio + suma[k].prod[i].precio + suma[m].prod[i].precio + suma[n].prod[i].precio;
		printf("%.0f\n", operacion[j]);
			
		i++;
	}while(i < 4);
	
	
}


int main(){
	system ("color B");
	/*struct producto pr1; //esto solo se usa cuando es una funcion retornable (void struct producto crear(struct producto prod)
	pr1 = crear(prod);*/
	
	//llamado de struct a una funcion
	crear(datos);
	imprimir(datos);
	sumar(datos);
}
