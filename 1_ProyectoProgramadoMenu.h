#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "1_ProyectoProgramado.h"

#ifndef ProyectoProgramadoMenu_h

	#define ProyectoProgramadoMenu_h
	
	//Funciones de menu.
	void registroNodos();
	void menuPrincipal();
	void muestraNodosMenu();
	void showAbout();
	void showHelp();

	void menuPrincipal(){
		//DeclaraciÛn variables locales
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
				show_list(lista);
			} else if(pOpcion==3) {
				muestraNodosMenu();
			} else if(pOpcion==4) {
				showAbout();
				mensaje("");
			} else if(pOpcion==5) {
				showHelp();
				mensaje("");
			}
		}		
	}
		
	void registroNodos(){
		//DeclaraciÛn de variables locales
		char rutaWindows[]="c:\\\\directorio\\\\";
		char rutaLinux[]="/home/directorio/";
		char rutaOrigen[1024]="";
		listaElemento nombreArchivo;
		char file_path[1024]="";	
		char rutaDestino[1024];
		listaElemento name_nodo;
	
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
			if (getcwd(rutaDestino, sizeof(rutaDestino)) == NULL){
				printf("Error al obtener el diretorio actual: %s\n", rutaDestino);
			}
			
			strcpy(file_path,"");
			strcpy(file_path,rutaDestino);
	
		    if (pOpcion==1){
						
				printf("La ruta actual es : %s\n\n",rutaDestino);
				printf("Ejmeplo de ingreso de ruta Windows: %s , Ruta Linux: %s\n\n",rutaWindows,rutaLinux);
				printf("Ingrese la ruta donde es encuentra el archivo a copiar: ");
				fflush(stdout);
				scanf("%s",rutaOrigen);
				
				printf("Ingrese el nombre del archivo a copiar: ");
				fflush(stdout);
				scanf("%s", nombreArchivo.nombre);
							
				if (exist_file(rutaOrigen,nombreArchivo)!=0){
					mensaje("El archivo indicado no existe en la ruta indicada...");
				}
				else{
					fflush(stdout);
					printf("Nombre nuevo del archivo: ");
					scanf("%s", name_nodo.nombre);
					
					//Valida si el archivo indicado para copiar existe.
					//strcat(name_nodo.nombre,EXTENSION);
		
					//strcpy(file_path,"");
					//strcpy(file_path,rutaDestino);
					strcat(file_path,CARPETA);
					//InclusiÛn del nodo
					fflush(stdout);
					//strcpy(&name_nodo->dato,nombre);
					nuevo=add_first_node(file_path,name_nodo);
					if (nuevo!=NULL){
						memset(file_path,'\0',1024);
						strcpy(file_path,rutaDestino);
						strcat(file_path,CARPETA);
						strcat(file_path,name_nodo.nombre);
						strcat(file_path,EXTENSION);
						strcat(rutaOrigen,nombreArchivo.nombre);
						strcat(rutaOrigen,EXTENSION);
						copy_file(rutaOrigen,file_path);
						mensaje("Se copio correctamente el archivo.");
					}
				}
					
			} else if(pOpcion==2) {
						
				printf("La ruta actual es : %s\n\n",rutaDestino);
				printf("Ejmeplo de ingreso de ruta Windows: %s , Ruta Linux: %s\n\n",rutaWindows,rutaLinux);
				printf("Ingrese la ruta donde es encuentra el archivo a copiar: ");
				fflush(stdout);
				scanf("%s",rutaOrigen);
				
				printf("Ingrese el nombre del archivo a copiar: ");
				fflush(stdout);
				scanf("%s", nombreArchivo.nombre);
							
				if (exist_file(rutaOrigen,nombreArchivo)!=0){
					mensaje("El archivo indicado no existe en la ruta indicada...");
				}
				else{
					fflush(stdout);
					printf("Nombre nuevo del archivo: ");
					scanf("%s", name_nodo.nombre);
					
					//Valida si el archivo indicado para copiar existe.
					//strcat(name_nodo.nombre,EXTENSION);
		
		
					strcpy(file_path,rutaDestino);
					strcat(file_path,CARPETA);
					//InclusiÛn del nodo
					fflush(stdout);
					//strcpy(&name_nodo->dato,nombre);
					nuevo=add_last_node(file_path,name_nodo);
					if (nuevo!=NULL){
						memset(file_path,'\0',1024);
						strcpy(file_path,rutaDestino);
						strcat(file_path,CARPETA);				
						strcat(file_path,name_nodo.nombre);
						strcat(file_path,EXTENSION);
						strcat(rutaOrigen,nombreArchivo.nombre);
						strcat(rutaOrigen,EXTENSION);
						copy_file(rutaOrigen,file_path);
						mensaje("Se copio correctamente el archivo.");
					}
				}
			}
		}		
	}
	
	void muestraNodosMenu(){
		char file_path[1024]="";		
		char rutaDestino[1024];
		
		if (getcwd(rutaDestino, sizeof(rutaDestino)) == NULL){
			printf("Error al obtener el diretorio actual: %s\n", rutaDestino);
		}		
		strcpy(file_path,rutaDestino);
		strcat(file_path,CARPETA);	
		
		int pOpcion=0;
		listaNodo *auxiliar;
		auxiliar=lista;
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
				if(lista!=NULL){
					auxiliar=show_current_node(file_path,auxiliar);
				}
			}else if(pOpcion==3) {
				if (lista!=NULL){
					auxiliar=show_next_node(file_path,auxiliar);
				}
			}else if(pOpcion==4) {
				if (lista!=NULL){
					auxiliar=show_previous_node(file_path,auxiliar);
				}
			}
		}	
	}

	void showHelp (){
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
	    printf ("\t*\tImprime mensaje de error en caso de que este sea el √∫ltimo.\t*\n");
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
	    printf ("\t*\tDespliega informaci√≥n relevante sobre el programa \t\t*\n");
	    printf ("\t*************************************************************************\n\n");
	}
	void showAbout (){
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
	    printf ("\t\t*\t Jorge Jaen Rios   - 9104658\t\t\t\t*\n");
	    printf ("\t\t*\t Bryan Perez Rojas - 2017120035\t\t\t\t*\n");
	    printf ("\t\t*****************************************************************\n\n");
	}


#endif
