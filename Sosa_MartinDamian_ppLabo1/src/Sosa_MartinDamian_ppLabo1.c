/*
 ============================================================================
 Name        : Sosa_MartinDamian_ppLabo1.c
 Author      : Martin D. Sosa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "marca.h"
#include "avion.h"
#include "viaje.h"
#include "avion-marca.h"
#define TAMANIOMARCA 7
#define TAMAVION 3
#define TAMVIAJE 3
#define LIBRE 1
#define OCUPADO 0

int main()
{
    setbuf(stdout,NULL);
    int opcion;
    int resp;
    int numAvion = 1;
    eMarca listaMarcas[TAMANIOMARCA];
    eAvion listaAviones[TAMAVION];
    eViaje listaViajes[TAMVIAJE];

    HardCodearMarca(listaMarcas,TAMANIOMARCA);
    HardCodearViaje(listaViajes,TAMVIAJE);
    do{
        opcion = Menu();
        switch(opcion){
    	    case 1:
    		    printf("“Ud. ha seleccionado lo opción 1-ALTA\n");
    		    CargarListadoAviones(listaAviones,TAMAVION,&numAvion,listaMarcas,TAMANIOMARCA);

        	break;
        	case 2:
    	    	printf("“Ud. ha seleccionado lo opción 2-BAJA”\n");
    	    	resp = BajaAvion(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA);
    	    	if (resp == 1){
    	    		printf("AVION dado de BAJA !!!");
    	    	}else{
    	    		printf("NO se realizo BAJA !!!");
    	    	}
    	    break;
    	    case 3:
    		    printf("“Ud. ha seleccionado lo opción 3-MODIFICACION”\n");
    		    resp = ModificarAvion(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA);
    		    if (resp == -1){
					printf("NO se realizo MODIFICACION !!!");
				}else{
					printf(" MODIFICADO !!!");
				}
    	    break;
		    case 4:
    			printf("“Ud. ha seleccionado lo opción 4-MOSTRAR”\n");
        	    resp = MostrarAviones(listaAviones,TAMAVION,listaMarcas,TAMANIOMARCA);
        	    if (resp == 0)
        	    {
        	        printf ("No hay AVIONES DADOS DE ALTA !!!");
        	    }

       		break;
    		case 5:
    			printf("“Ud. ha seleccionado lo opción 5-”\n");
    		break;
    		case 6:
    			printf("“Ud. ha seleccionado lo opción 6-\n");

    		break;
    		case 7:
				printf("“Ud. ha seleccionado lo opción 7-”\n");

			break;
    		case 8:
				printf("“Ud. ha seleccionado lo opción 8-\n");

			break;

    		case 10:
    			printf("Gracias por usar el Sistema!!!\n");
    		break;
    		default:
    			printf("Opcion ingresada erronea. Reingrese\n");
    	}
    }while(opcion!=10);
    return 0;
}

