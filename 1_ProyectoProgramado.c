/**********************************************************************
    Instituto Tecnológico de Costa Rica
    Estructuras de Datos IC-2001
    I Semestre 2018
    Profesora: Samanta Ramijan Carmiol
    Carnet: 9104658
    	    2017120035
    Alumnos: Jorge Jaén Ríos
	     Bryan Pérez Rojas	
    Proyecto: Listas enlazadas.
**********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "1_ProyectoProgramado.h"
#include "1_ProyectoProgramadoMenu.h"

int main(){
	char file_path[1024]="",add_folder[1024]="";//add_file[1024]="";
	char rutaDestino[1024];
	//listaElemento name_registro;
	int i = 0;
	 
	if (getcwd(rutaDestino, sizeof(rutaDestino)) == NULL){
		printf("Error al obtener el diretorio actual: %s\n", rutaDestino);
	}
	
	strcpy(file_path,"");
	strcpy(file_path,rutaDestino);
	strcat(file_path,CARPETA);
	
	strcpy(add_folder,"mkdir ");
	strcat(add_folder,rutaDestino);
	strcat(add_folder,CARPETA);

	i = exist_dir(add_folder);	
	/*if  (exist_file (file_path, name_registro)!=0){
		strcat (file_path, ARCHIVOREGISTRO);
		nuevo = readFile (file_path);
	}	*/
	menuPrincipal();							
	
	return 0;
}

