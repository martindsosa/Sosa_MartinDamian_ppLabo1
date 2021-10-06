/*
 * avion-marca.h
 *
 *  Created on: 6 oct. 2021
 *      Author: martindamian
 */

#ifndef AVION_MARCA_H_
#define AVION_MARCA_H_
#include "marca.h"
#include "avion.h"
int SubMenu();
int BuscarAvionLibre(eAvion*, int);
int BuscarAvion(eAvion[],int,int);
void CargarListadoAviones(eAvion[],int,int*,eMarca[],int);
int MostrarAviones(eAvion[],int,eMarca[],int);
void MostrarUnAvion(eAvion,char[]);
eAvion CargarUnAvion (int*,eMarca[],int);
int BajaAvion(eAvion[],int,eMarca[],int);
int ModificarAvion(eAvion[],int,eMarca[],int);
void MostrarUnaMarca(eMarca);
void MostrarMarcas(eMarca[],int);
int BuscarMarca(eMarca[],int,int);
#endif /* AVION_MARCA_H_ */
