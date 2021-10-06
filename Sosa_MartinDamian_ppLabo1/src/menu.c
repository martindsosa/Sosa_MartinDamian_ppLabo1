/*
 * menu.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */



#include <stdio.h>
int Menu(){
	int miOpcion;
	printf("\nMENU DE OPCIONES \n");
	printf("------------------\n");
	printf("1. ALTA\n");
	printf("2. BAJA\n");
	printf("3. MODIFICACION\n");
	printf("4. MOSTRAR\n");
	printf("5. \n");
	printf("6. \n");
	printf("7. \n");
	printf("8. \n");
	printf("10. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &miOpcion);
    return miOpcion;
}
