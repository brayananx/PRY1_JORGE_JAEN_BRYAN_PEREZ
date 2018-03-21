/**********************************************************************
    Instituto Tecnológico de Costa Rica
    Estructuras de Datos IC-2001
    I Semestre 2018
    Profesora: Samanta Ramijan Carmiol
    Carnet: 9104658
    	    2017120035
	Alumno: Jorge Jaén Ríos
		Bryan Pérez Rojas
	Proyecto: Listas enlazadas.
**********************************************************************/


#ifndef ProyectoProgramado_h

	#define ProyectoProgramado_h
	
	//Declaración de constantes globales
	#define EXTENSION ".txt"
	#define CARPETA "/ascii/"
	#define ARCHIVOREGISTRO "registroNodos.txt"

	//Declaración de la estructura del Nodo
	typedef struct listaElemento{
		char nombre[18];
	}listaElemento;
	
	typedef struct listaNodo{
		listaElemento dato;
		struct listaNodo* siguiente;
		struct listaNodo* anterior;
	}listaNodo;

	//Declaración de las variables globales de tipo nodo
	listaNodo *lista,*nuevo;
	
	//Verifica si un archivo existe en la ruta indicada y directorio
	int exist_file(char *direccion,listaElemento elemento);
	int exist_dir(char *direccion);
	//Registro de nodos
	listaNodo *add_first_node(char *file_path,listaElemento elemento);
	listaNodo *add_last_node(char *file_path,listaElemento elemento);
	//Muestra un mensaje en pantalla y hace una pausa
	void mensaje(char msg[100]);
	//Procede a realizar la copia del archivo
	int copy_file(char *archivoOriginal, char *nuevoArchivo);
	//Registra los nodos creados en el archivo de historial
	int registraNodo(char *ruta_Auxiliar,listaElemento name_nodo);
	//Muestra el contenido completo de la lista
	void show_list (listaNodo *lista);
	int show_file(char *nodo_name);
	//Funciones que permiten moverse dentro de la lista.
	listaNodo *show_current_node(char *file_path,listaNodo *lista);
	listaNodo *show_next_node(char *file_path,listaNodo *lista);
	listaNodo *show_previous_node(char *file_path,listaNodo *lista);
	listaNodo *readFile (char *file_path);
	listaNodo *validaElemento(listaElemento elemento);

    
	int exist_file(char *direccion,listaElemento elemento){
		FILE *origen;
		char ruta[1024]="";
		strcpy(ruta,direccion);
		strcat(ruta,elemento.nombre);
		strcat(ruta,EXTENSION);
		origen = fopen(ruta,"r");
		if (origen==NULL){
			fclose(origen);
			return 1;
		}
		else
		{
			fclose(origen);
			return 0;
		}
	}
	
	listaNodo *add_first_node(char *file_path,listaElemento elemento){
	
		listaNodo *nuevo;
		
		nuevo=calloc(1,sizeof(nuevo));
		char rutaAuxiliar[1024]="";
		
		nuevo->dato=elemento;		
		nuevo->anterior=NULL;
		nuevo->siguiente=NULL;
		strcpy(rutaAuxiliar,file_path);
		
		if (exist_file(rutaAuxiliar,elemento)==0){
			mensaje("El nuevo nombre del archivo ya existe...");
		}
		else{
			if (nuevo!=NULL){
				if (lista==NULL){
					lista=nuevo;
					if(registraNodo(file_path,elemento)!=0){
						mensaje("Se registro el nodo correctamente en el registro de nodos.");
					}				
				}
				else{
					nuevo->siguiente=lista;
					lista=nuevo;
					if(registraNodo(file_path,elemento)!=0){
						mensaje("Se registro el nodo correctamente en el registro de nodos.");
					}
				}
			}			
		}
		return nuevo;
	}
	
	listaNodo *add_last_node(char *file_path,listaElemento elemento){
	
		listaNodo *nuevo,*auxiliar=lista;
		
		nuevo=calloc(1,sizeof(nuevo));
		char rutaAuxiliar[1024]="";
		
		nuevo->dato=elemento;		
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
		strcpy(rutaAuxiliar,file_path);
		
		if (exist_file(rutaAuxiliar,elemento)==0){
			mensaje("El nuevo nombre del archivo ya existe...");
		}
		else{
				if (auxiliar==NULL){
					mensaje("La lista se encuentra vacia, no se puede ingresar el nodo ultimo.");
				}
				else{
					while(auxiliar->siguiente!=NULL){
						auxiliar=auxiliar->siguiente;
					}
					auxiliar->siguiente=nuevo;
					if(registraNodo(file_path,elemento)!=0){
						mensaje("Se registro el nodo correctamente en el registro de nodos.");
					}
				}			
		}
		return auxiliar;
	}
	
	void mensaje(char msg[100]){
		printf("%s\n",msg);
		printf("Presione cualquier tecla para continuar....\n");
		getchar();
		getchar();
	}
	
	int copy_file(char *archivoOriginal, char *nuevoArchivo){
		FILE *origen;
		FILE *destino;
	
		char imprimeCaracter;
		origen = fopen(archivoOriginal,"rt");
		destino = fopen(nuevoArchivo,"wt");
		if (origen==NULL || destino==NULL ) 
	        {
	            return 1;
	        }
	        else
	        {
	            while((imprimeCaracter = fgetc(origen)) != EOF){
	            	fputc(imprimeCaracter,destino);
		    	}
	    	}
	    fclose(origen);
	    fclose(destino);
		return 0;
	}
	
	int registraNodo(char *ruta_Auxiliar,listaElemento name_nodo){
	
		FILE *file;
		char separador [] = ";";
		char archivoRegistro[]="registroNodos.txt";
		char nodoNombre[30]="";
		
		strcpy(nodoNombre,name_nodo.nombre);
		//strcat(nodoNombre,EXTENSION);
		strcat(ruta_Auxiliar,archivoRegistro);	
	
		file=fopen(ruta_Auxiliar,"at");
		if(file==NULL){
			fclose(file);
			return 1;
		}
		else{
			fputs(nodoNombre,file);
			fputs(separador,file);
			fclose(file);
			return 0;
		}
	}
	void show_list (listaNodo *lista){
		listaNodo *nuevo;
		nuevo = lista;               
		while (nuevo != NULL)        
		{
		  printf("%s\n", nuevo->dato.nombre);
		  nuevo = nuevo->siguiente;               
		}
		printf("\n");
	}

	listaNodo *show_current_node(char *file_path,listaNodo *lista){
		listaNodo *nuevaPosicion;
		nuevaPosicion=lista;
		listaElemento name_nodo;
		
		char ruta[1024]="";
		strcpy(ruta,file_path);
	
		if(nuevaPosicion!=NULL){
			name_nodo=lista->dato;
			strcat(ruta,name_nodo.nombre);
			strcat(ruta,EXTENSION);
			if (show_file(ruta)!=0){
				mensaje("No encontro el nodo actual.");
			}
		}
		return nuevaPosicion;
	}
	
	listaNodo *show_next_node(char *file_path,listaNodo *lista){
		listaNodo *nuevaPosicion;
		nuevaPosicion=lista;
		listaElemento name_nodo;
		name_nodo=lista->dato;
		char ruta[1024]="";
		strcpy(ruta,file_path);
		strcat(ruta,name_nodo.nombre);
		strcat(ruta,EXTENSION);
		if(nuevaPosicion!=NULL){
			nuevaPosicion=nuevaPosicion->siguiente;
			if (show_file(ruta)!=0 && nuevaPosicion != NULL){
				mensaje("No encontro el nodo actual.");
			}
			else{
				nuevaPosicion = nuevaPosicion -> anterior;
			}
		}
		return nuevaPosicion;
	}
	
	listaNodo *show_previous_node(char *file_path,listaNodo *lista){
		listaNodo *nuevaPosicion;
		nuevaPosicion=lista;
		listaElemento name_nodo;
		name_nodo=lista->dato;
		char ruta[1024]="";
		strcpy(ruta,file_path);
		strcat(ruta,name_nodo.nombre);
		strcat(ruta,EXTENSION);
		if(nuevaPosicion!=NULL){
			nuevaPosicion=nuevaPosicion->anterior;
			if (show_file(ruta)!=0 && nuevaPosicion != NULL){
				mensaje("No encontro el nodo actual.");
			}
			else{
				nuevaPosicion = nuevaPosicion -> anterior;
			}
		}
		return nuevaPosicion;
	}
	
	int show_file(char *nodo_name)
	{
		FILE *archivo;
		char imprimeCaracter;
		archivo = fopen(nodo_name,"r");
		if (archivo==NULL)
	        {
	            return 1;
	        }
	        else
	        {
	            while((imprimeCaracter = fgetc(archivo)) != EOF){
					printf("%c",imprimeCaracter);
		    	}
	    	}
	    fclose(archivo);
		return 0;
	}

	listaNodo *readFile (char *file_path){
		FILE *archivo;
		char valorRegistro[10]="";
		char nombre[100]="";
		listaElemento name_nodo;
		int cont=0;
		int contAux=0;
		listaNodo *nuevo;
	
		//nuevo=lista;
		nuevo=calloc(1,sizeof(nuevo));
	
		if (lista==NULL){
			archivo = fopen (file_path, "rt");
			if (archivo == NULL){
				mensaje("Error al tratar de leer el archivo");
			}
			fgets(nombre,sizeof(nombre),archivo);
			cont=0;
	
			while(sizeof(nombre)>cont){
				
				if ((nombre[cont] != ';')&&(nombre[cont]!='0')){
					valorRegistro[contAux]=nombre[cont];
					cont++;
					contAux++;
				}
				else{
					if(valorRegistro[0]!='0'){
						strcpy(name_nodo.nombre,valorRegistro);
						nuevo=validaElemento(name_nodo);
						lista=nuevo;
						cont++;
						contAux=0;
						memset(valorRegistro,'\0',sizeof(valorRegistro));
					}
				}
			}
			fclose (archivo);
			memset(nombre,'\0',sizeof(nombre));
		}
	
		return nuevo;
	}
	
	listaNodo *validaElemento(listaElemento elemento){
		listaNodo *nuevo,*auxiliar=lista;
		
		nuevo=calloc(1,sizeof(nuevo));
		
		nuevo->dato=elemento;		
		nuevo->siguiente=NULL;
		nuevo->anterior=NULL;
		
		if (auxiliar==NULL){
			auxiliar=nuevo;
		}
		else{
			auxiliar->siguiente=nuevo;
		}			
		return auxiliar;
	}

	int exist_dir(char *direccion){
		DIR *dir;

		dir = opendir (direccion);
		if (dir == NULL){
			system(direccion);
			
		}
		int closedir(DIR *dir);
		return 0;
	}
	


#endif
