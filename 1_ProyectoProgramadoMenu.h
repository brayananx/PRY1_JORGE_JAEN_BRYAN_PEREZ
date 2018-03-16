#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "1_ProyectoProgramado.h"

#ifndef ProyectoProgramadoMenu_h

	#define ProyectoProgramadoMenu_h
	void menuPrincipal();
	void registroNodos();
	void muestraNodosMenu();
	void showAbout();
	void showHelp();
	
	void menuPrincipal(){
		//Declaración variables locales
		int pOpcion=0;
	
		while(pOpcion!=6){
	
		    printf("--------------------------------------------------------------------\n");
		    printf("|                                                                  |\n");
		    printf("|                         MENU PRINCIPAL                           |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|               1. Registro de Nodo                                |\n");
		    printf("|               2. Muestra archivos txt                            |\n");
		    printf("|               3. Muestra figuras                                 |\n");
		    printf("|               4. Acerca de..                                     |\n");
		    printf("|               5. Ayuda                                           |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|               6. Salir del sistema                               |\n");
		    printf("--------------------------------------------------------------------\n");
		   	printf("Digite la opcion: ");
		    scanf("%i",&pOpcion);
		    if (pOpcion==1){
				registroNodos();
			} else if(pOpcion==2) {
				show_list();
			} else if(pOpcion==3) {
				muestraNodosMenu();
			} else if(pOpcion==4) {
				showAbout();
			} else if(pOpcion==5) {
				showHelp();
			}
		}		
	}
	
	void registroNodos(){
		//Declaración de variables locales
		char rutaWindows[]="c:\\\\directorio\\\\";
		char rutaLinux[]="/home/directorio/";
		char rutaOrigen[1024]="";
		char nombreArchivo[30] = "";
		char nombreNuevo[30]="";
		char temp[30]="";
		char extension[4]=".txt";
		char file_path[1024]="";	
		char rutaDestino[1024];
		char *name_nodo=malloc(sizeof(char));
		
		if (getcwd(rutaDestino, sizeof(rutaDestino)) == NULL){
			printf("Error al obtener el diretorio actual: %s\n", rutaDestino);
		}			
		int pOpcion=0;
		
		while(pOpcion!=3){
	
		    printf("--------------------------------------------------------------------\n");
		    printf("|                                                                  |\n");
		    printf("|                       REGISTRO DE NODOS                          |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|          1. Registrar al principio de la Lista Doble             |\n");
		    printf("|          2. Registrar al final de la Lista Doble                 |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|          3. Regresar al menu anterior.                           |\n");
		    printf("--------------------------------------------------------------------\n");
		   	printf("Digite la opcion: ");
		    scanf("%i",&pOpcion);
		    
			strcpy(file_path,"");
			if (getcwd(rutaDestino, sizeof(rutaDestino)) == NULL){
				printf("Error al obtener el diretorio actual: %s\n", rutaDestino);
			}
			
		    if (pOpcion==1){
							
				printf("La ruta actual es : %s\n\n",rutaDestino);
				printf("Ejmeplo de ingreso de ruta Windows: %s , Ruta Linux: %s\n\n",rutaWindows,rutaLinux);
				printf("Ingrese la ruta donde es encuentra el archivo a copiar: ");
				scanf("%s",rutaOrigen);
				
				printf("Ingrese el nombre del archivo a copiar: ");
				scanf("%s",nombreArchivo);
				
				strcat(nombreArchivo,extension);
				strcat(rutaOrigen,nombreArchivo);
							
				if (exist_file(rutaOrigen)!=0){
					mensaje("El archivo indicado no existe en la ruta indicada...");
				}
				else{
					

					printf("Nombre nuevo del archivo: ");
					scanf("%s",name_nodo);
					
					//Valida si el archivo indicado para copiar existe.
					
					strcat(nombreNuevo,name_nodo);
					strcat(temp,name_nodo);
					strcat(nombreNuevo,extension);


					strcpy(file_path,rutaDestino);
					strcat(file_path,"\\ascii\\");
					//Inclusión del nodo
    	
					if(add_first_node(file_path,name_nodo)!=0){
						mensaje("Error al tratar de crear el archivo de registros del nodo.");
					}
					/*
					else{
						strcat(file_path,nombreNuevo);
						copy_file(rutaOrigen,nombreNuevo);
					}
					*/
				}	
			} else if(pOpcion==2) {

				printf("La ruta actual es : %s\n\n",rutaDestino);
				printf("Ejmeplo de ingreso de ruta Windows: %s , Ruta Linux: %s\n\n",rutaWindows,rutaLinux);
				printf("Ingrese la ruta donde es encuentra el archivo a copiar: ");
				scanf("%s",rutaOrigen);
				
				printf("Ingrese el nombre del archivo a copiar: ");
				scanf("%s",nombreArchivo);
				
				strcat(nombreArchivo,extension);
				strcat(rutaOrigen,nombreArchivo);
							
				if (exist_file(rutaOrigen)!=0){
					mensaje("El archivo indicado no existe en la ruta indicada...");
				}
				else{
					

					printf("Nombre nuevo del archivo: ");
					scanf("%s",name_nodo);
					
					//Valida si el archivo indicado para copiar existe.
					
					strcat(nombreNuevo,name_nodo);
					strcat(temp,name_nodo);
					strcat(nombreNuevo,extension);


					strcpy(file_path,rutaDestino);
					strcat(file_path,"\\ascii\\");
					//Inclusión del nodo
    	
					if(add_last_node(file_path,name_nodo)!=0){
						mensaje("Error al tratar de crear el archivo de registros del nodo.");
					}
					/*
					else{
						strcat(file_path,nombreNuevo);
						copy_file(rutaOrigen,nombreNuevo);
					}
					*/			
				}	
			}
		}		
	}

	void muestraNodosMenu(){
		//Declaración de variables locales
		char rutaWindows[]="c:\\\\directorio\\\\";
		char rutaLinux[]="/home/directorio/";
		char rutaOrigen[1024]="";
		char nombreArchivo[30] = "";
		char nombreNuevo[30]="";
		char temp[30]="";
		char extension[4]=".txt";
		char file_path[1024]="";	
		char rutaDestino[1024];
		char *name_nodo=malloc(sizeof(char));
		
		if (getcwd(rutaDestino, sizeof(rutaDestino)) == NULL){
			printf("Error al obtener el diretorio actual: %s\n", rutaDestino);
		}			
		int pOpcion=0;
		
		while(pOpcion!=5){
	
		    printf("--------------------------------------------------------------------\n");
		    printf("|                                                                  |\n");
		    printf("|                       REGISTRO DE NODOS                          |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|          1. Eliminar nodo                                        |\n");
		    printf("|          2. Imprimir el archivo del nodo actual                  |\n");
		    printf("|          3. Imprimir el archivo del nodo siguiente               |\n");
		    printf("|          4. Imprimir el archivo del nodo anterior                |\n");
		    printf("--------------------------------------------------------------------\n");
		    printf("|          5. Regresar al menu anterior.                           |\n");
		    printf("--------------------------------------------------------------------\n");
		   	printf("Digite la opcion: ");
		    scanf("%i",&pOpcion);
		    if (pOpcion==1){
				mensaje("Elimiar Nodo\n");
			} else if(pOpcion==2) {
				mensaje("Nodo Actual\n");
			}else if(pOpcion==3) {
				mensaje("Nodo Siguiente\n");
			}else if(pOpcion==4) {
				mensaje("Nodo anterior\n");
			}
	
		}		
	}

	/*****************************************
	El void que viene a continuación lo que hace es mostrar los diferentes
	comandos que se pueden realizar, lo que se espera recibir y su función.
	*****************************************/
	void showHelp(){
	    printf ("\n\t*************************************************************************\n");
	    printf ("\t*\t\t\tLos comandos disponibles son \t\t\t*\n");
	    printf ("\t*1. add_first_node\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tCrea una copia del archivo en la carpeta ASCII\t\t\t*\n");
	    printf ("\t*\tAgrega un nuevo nodo, con el nombre indicado por el usuario,\t*\n\t*\tal inicio de la lista enlazada doble. \t\t\t\t*\n");
	    printf ("\t*Parametros: \t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t1. file_path\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t2. node_name\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*2. add_last_node\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tCrea una copia del archivo en la ruta indicada, con el nombre\t*\n\t*\tespecificado, en la carpeta ASCII \t\t\t\t*\n");
	    printf ("\t*\tAgrega un nuevo nodo, con el nombre indicado por el usuario,\t*\n\t*\tal inicio de la lista enlazada doble. \t\t\t\t*\n");
	    printf ("\t*Parametros: \t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t1. file_path\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t2. node_name\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*3. delete_node\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tBorrar el archivo con el nombre especificado\t\t\t*\n");
	    printf ("\t*\tBorrar el nodo con el nombre indicado\t\t\t\t*\n");
	    printf ("\t*Parametros: \t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t1. node_name\t\t\t\t\t\t\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*4. show_current_node\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tImprime en consola el archivo con el nodo actual\t\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*5. show_next_node\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tImprime en consola el archivo con el siguiente nodo. Cambiar el\t*\n\t*\tnodo actual al siguiente.\t\t\t\t\t*\n");
	    printf ("\t*\tImprime mensaje de error en caso de que este sea el último.\t*\n");
	    printf ("\t*\tEn caso de no haber desplegado ninguno, se imprime el primero\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*6. show_previous_node\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tImprime en consola el archivo con el siguiente nodo. Cambiar el\t*\n\t*\tnodo actual al anterior.\t\t\t\t\t*\n");
	    printf ("\t*\tImprime mensaje de error en caso de que este sea el primero.\t*\n");
	    printf ("\t*\tEn caso de no haber desplegado ninguno, se imprime el primero\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\tt\t*\n");
	    printf ("\t*7. help\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tDespliega los comandos que pueden ser utilizados en el programa\t*\n");
	    printf ("\t*\t\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*8. about\t\t\t\t\t\t\t\t*\n");
	    printf ("\t*\tDespliega información relevante sobre el programa \t\t*\n");
	    printf ("\t*************************************************************************\n\n");
	    mensaje("");
	}
	
	/*****************************************
	El void que viene a continuación lo que hace es mostrar información
	sobre el programa, tal como nombre de los desarrolladores, nombre
	del curso, el objetivo del programa y el lenguaje utilizado.
	*****************************************/
	
	void showAbout(){
	    printf ("\n\t\t*****************************************************************\n");
	    printf ("\t\t*\t\tooooooooooooo oooooooooooo   .oooooo.   \t*\n");
	    printf ("\t\t*\t\t8'   888   `8 `888'     `8  d8P'  `Y8b  \t*\n");
	    printf ("\t\t*\t\t     888       888         888          \t*\n");
	    printf ("\t\t*\t\t     888       888oooo8    888          \t*\n");
	    printf ("\t\t*\t\t     888       888    ""     888        \t\t*\n");
	    printf ("\t\t*\t\t     888       888       o `88b    ooo  \t*\n");
	    printf ("\t\t*\t\t    o888o     o888ooooood8  `Y8bood8P'  \t*\n");
	    printf ("\t\t*****************************************************************\n");
	    printf ("\t\t*****************************************************************\n");
	    printf ("\t\t*Objetivo:\t\t\t\t\t\t\t*\n");
	    printf ("\t\t*\tVisualizar de ASCII\t\t\t\t\t*\n");
	    printf ("\t\t*Lenguaje utilizado:\t\t\t\t\t\t*\n");
	    printf ("\t\t*\t\t C \t\t\t\t\t\t*\n");
	    printf ("\t\t*Curso:\t\t\t\t\t\t\t\t*\n");
	    printf ("\t\t*\tEstructuras de Datos\t\t\t\t\t*\n");
	    printf ("\t\t*Desarrolladores: \t\t\t\t\t\t*\n");
	    printf ("\t\t*\t Jorge Jaén Ríos   - 9104658\t\t\t\t*\n");
	    printf ("\t\t*\t Bryan Pérez Rojas - 2017120035\t\t\t\t*\n");
	    printf ("\t\t*****************************************************************\n\n");
	    mensaje("");
	}


#endif
