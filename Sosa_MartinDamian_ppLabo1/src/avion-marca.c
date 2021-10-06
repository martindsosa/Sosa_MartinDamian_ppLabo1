/*
 * avion-marca.c
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "marca.h"
#include "avion.h"
#include "avion-marca.h"
#include "utn.h"

#define LIBRE 1
#define OCUPADO 0


int SubMenu(){
	int miOpcion;
	printf("\nSUBMENU MODIFICACIONES \n");
	printf("-----------------------\n");
	printf("1. MODELO\n");
	printf("2. CANTIDAD DE ASIENTOS\n");
	printf("3. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d", &miOpcion);
    return miOpcion;
}
int BuscarAvionLibre(eAvion* listaAviones, int sizeAvion)
{
    int i;
    int index = -1;
    for(i=0; i<sizeAvion; i++)
    {
        if(listaAviones[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
void CargarListadoAviones(eAvion listaAviones[],int sizeAvion,int* numAvion,eMarca listaMarcas[],int sizeMarca)
{
    int encontro;
    encontro = BuscarAvionLibre(listaAviones,sizeAvion);
    if(encontro!=-1)
    {
       listaAviones[encontro] = CargarUnAvion(numAvion,listaMarcas,sizeMarca);
    }
    else
    {
        printf("No hay espacio");
    }
}

eAvion CargarUnAvion (int* numAvion,eMarca listaMarcas[],int sizeMarca)
{
    eAvion miAvion;
    int matricula=0;
    int fecha=0;
    int viaje=0;
    int auxMarca;
    int modelo=0;
    int cantAsientos=0;
    int posicion;

    miAvion.idAvion = *numAvion;
    (*numAvion)++;


    if(GetInt(&matricula,"Ingrese matricula : ","Error!!! \n",0,999999,2)){
		miAvion.matricula = matricula;
	}else{
		miAvion.matricula = 0;
	}

    if(GetInt(&fecha,"Ingrese fecha ddmmaaaa : ","Error!!! \n",0,999999,2)){
		miAvion.fecha = fecha;
	}else{
		miAvion.fecha = 0;
	}
    if(GetInt(&viaje,"Ingrese id viaje : ","Error!!! \n",0,999999,2)){
        	miAvion.idViaje = viaje;
        }else{
        	miAvion.idViaje = 0;
        }

    MostrarMarcas(listaMarcas,sizeMarca);
    printf("Ingrese Marca : ");
    scanf("%d",&auxMarca);
    do{
        posicion = BuscarMarca(listaMarcas,sizeMarca,auxMarca);
        if (posicion == -1){
        	MostrarMarcas(listaMarcas,sizeMarca);
            printf("\nError Reingrese Marca: ");
            scanf("%d",&auxMarca);
        }
    }while(posicion == -1);
    if(GetInt(&modelo,"Ingrese modelo : ","Error!!! \n",0,2021,2)){
		miAvion.modelo = modelo;
	}else{
		miAvion.modelo = 0;
	}
    if(GetInt(&cantAsientos,"Ingrese cantidad de asientos : ","Error!!! \n",0,600,2)){
		miAvion.cantAsientos = cantAsientos;
	}else{
		miAvion.cantAsientos = 0;
	}

    miAvion.isEmpty = OCUPADO;

    return miAvion;
}
int BajaAvion(eAvion listaAviones[],int sizeAvion,eMarca listaMarcas[],int sizeMarca)
{
    int i;
    int auxMatricula;
    int avionDadoDeBaja = 0;
    if(MostrarAviones(listaAviones,sizeAvion,listaMarcas,sizeMarca)== 1){
    	printf("Ingrese matricula del avion a dar de baja: ");
		scanf ("%d",&auxMatricula);
		for (i=0;i<sizeAvion;i++){
			if(auxMatricula == listaAviones[i].matricula){
				listaAviones[i].isEmpty = LIBRE;
				avionDadoDeBaja = 1;
				break;
			}
		}
    }
    return avionDadoDeBaja;
}

int MostrarAviones(eAvion listaAviones[],int sizeAvion,eMarca listaMarcas[],int sizeMarca)
{
    int i;
    int flagHayAvion = 0;
    char descMarca[20] = " ";
    int indiceMarca = 0;
    printf(" LISTADO DE EMPLEADOS \n");
    printf("----------------------\n");
    for (i=0;i<sizeMarca;i++)
    {
        if(listaMarcas[i].isEmpty == OCUPADO)
        {
        	//traer la descripcion de marcas
        	indiceMarca = BuscarMarca(listaMarcas,sizeMarca,listaAviones[i].idAvion);
        	if( indiceMarca != -1){
        		strcpy(descMarca,listaMarcas[indiceMarca].descripcion);
        	}else{
        		strcpy(descMarca,"SIN Marca");
        	}
            MostrarUnAvion(listaAviones[i],descMarca);
            flagHayAvion = 1;
        }
    }
    return flagHayAvion;
}

void MostrarUnAvion(eAvion miAvion,char descripcion[])
{

    printf("idAvion: %4d Matricula: %6d fecha: %8d idViaje: %4d Marca: %20s modelo: %4d cantidad de asientos %2d\n",miAvion.idAvion
    																			  	  	  	  	  	  	  	  	  ,miAvion.matricula
																												  ,miAvion.fecha
																												  ,miAvion.idViaje
																												  ,descripcion
																												  ,miAvion.modelo
																												  ,miAvion.cantAsientos);
}

int ModificarAvion(eAvion listaAviones[],int sizeAvion,eMarca listaMarcas[],int sizeMarca)
{
    int posicion= -1;
    int auxModelo;
    int auxCantAsientos;
    int intento = 0;
    int auxMatricula;
    int opcion;

    if(MostrarAviones(listaAviones,sizeAvion,listaMarcas,sizeMarca)== 1){
    	printf("Ingrese matricula de avion a MODIFICAR: ");
		scanf ("%d",&auxMatricula);
		do{
			posicion = BuscarAvion(listaAviones,sizeAvion,auxMatricula);
			if (posicion == -1){
				MostrarAviones(listaAviones, sizeAvion, listaMarcas, sizeMarca);
				printf("\nError Reingrese matricula: ");
				scanf("%d",&auxMatricula);
				intento++;
			}

		}while(intento<3 && posicion == -1);
		if(intento <3 && posicion != -1){
			opcion = SubMenu();
			do{
				opcion = SubMenu();
				switch(opcion){
				case 1:
				    if(GetInt(&auxModelo,"Ingrese modelo : ","Error!!! \n",0,999999,2)){
				    	listaAviones[posicion].modelo = auxModelo;
				    }else{
				    	listaAviones[posicion].modelo = 0;
				    }

				break;
				case 2:
					if(GetInt(&auxCantAsientos,"Ingrese cantidad de asientos : ","Error!!! \n",0,999999,2)){
						listaAviones[posicion].cantAsientos = auxCantAsientos;
					}else{
						listaAviones[posicion].cantAsientos = 0;
					}
				break;
				default:
					printf("Opcion ingresada erronea. Reingrese\n");
				}
			}while(opcion!=3);
		}
	}
    return posicion;
}
void MostrarMarcas(eMarca listaMarcas[],int sizeMarca)
{
    int i;
    int flagHayMarcas = 0;
    printf(" LISTADO DE MARCAS \n");
    printf(" ------------------------ \n");
    for (i=0;i<sizeMarca;i++)
    {
        if(listaMarcas[i].isEmpty == OCUPADO)
        {
            MostrarUnaMarca(listaMarcas[i]);
            flagHayMarcas = 1;
        }
    }
    if (flagHayMarcas != 1)
    {
        printf ("No hay marcas cargadas ");
    }
}
void MostrarUnaMarca(eMarca miMarca)
{
	printf("Num: %4d Descripcion: %15s \n",miMarca.id,miMarca.descripcion);
}

int BuscarMarca(eMarca listaMarcas[],int sizeMarca,int marca){
	int i;
	int indice = -1;
	for (i=0;i<sizeMarca;i++){
		if(listaMarcas[i].id == marca){
			indice = i;
			break;
		}
	}
	return indice;
}
int BuscarAvion(eAvion listaAviones[],int sizeAvion,int matricula){
    int i;
    int indice = -1;
    for (i=0;i<sizeAvion;i++){
        if(listaAviones[i].matricula == matricula){
            indice = i;
            break;
        }
    }
    return indice;
}
