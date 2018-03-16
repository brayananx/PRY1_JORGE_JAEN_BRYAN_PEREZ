/**********************************************************************
    Instituto Tecnológico de Costa Rica
    Estructuras de Datos IC-2001
    I Semestre 2018
    Profesora: Samanta Ramijan Carmiol
    Carnet: 9104658
	Alumno: Jorge Jaén Ríos
	Proyecto: Listas enlazadas.
**********************************************************************/

#ifndef ProyectoProgramado_h

	#define ProyectoProgramado_h
	
	//Declaración de la estructura del Nodo
	typedef struct Nodo{
		char dato;
		struct Nodo* siguiente;
		struct Nodo* anterior;
	}Nodo;
	
	Nodo *primero=NULL;
	Nodo *ultimo=NULL;
	Nodo *actual=NULL;
	Nodo *temp=NULL;

	void mensaje(char msg[100]);
	int muestra(char *nodo_name);
	int copy_file(char *archivoOriginal, char *nuevoArchivo);
	int add_first_node(char *file_path,char *name_nodo);
	void show_list();
	int registraNodo(char *ruta_Auxiliar,char *name_nodo);
	int add_last_node(char *file_path,char *name_nodo);
		
	int exist_file(char *nuevoArchivo){
		FILE *origen;
		origen = fopen(nuevoArchivo,"r");
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

	int add_last_node(char *file_path,char *name_nodo){
		
		Nodo *nuevo=malloc(sizeof(char));
		char *rutaAuxiliar=malloc(sizeof(char));
		char *rutaAuxiliar2=malloc(sizeof(char));
		
		strcpy(rutaAuxiliar,file_path);
		strcat(rutaAuxiliar,name_nodo);		
		strcat(rutaAuxiliar,".txt");

		strcpy(&nuevo->dato,name_nodo);
		nuevo->anterior=NULL;
		nuevo->siguiente=NULL;

	
		if (exist_file(file_path)==0){
			mensaje("El nuevo nombre del archivo ya existe...");
		}
		else{			
			if (primero==NULL){
				mensaje("La lista se encuentra vacía no se puede agregar el nodo al final.");
			}
			else{
				ultimo->siguiente=nuevo;
				nuevo->siguiente=NULL;
				nuevo->anterior=ultimo;
				ultimo=nuevo;
			}
			/*
			strcpy(rutaAuxiliar2,file_path);
			if(registraNodo(rutaAuxiliar2,name_nodo)!=0){
				return 1;		
			}
			*/
			return 0;
		}
		return 0;
	}
	
	int add_first_node(char *file_path,char *name_nodo){
		
		Nodo *nuevo=malloc(sizeof(char));
		char *rutaAuxiliar=malloc(sizeof(char));
		char *rutaAuxiliar2=malloc(sizeof(char));
		
		strcpy(rutaAuxiliar,file_path);
		strcat(rutaAuxiliar,name_nodo);		
		strcat(rutaAuxiliar,".txt");

		strcpy(&nuevo->dato,name_nodo);
		nuevo->anterior=NULL;
		nuevo->siguiente=NULL;

	
		if (exist_file(file_path)==0){
			mensaje("El nuevo nombre del archivo ya existe...");
		}
		else{			
			if (primero==NULL){
				primero=nuevo;
				primero->siguiente=NULL;
				primero->anterior=NULL;				
				ultimo=primero;
			}
			else{
				primero->anterior=nuevo;
				nuevo->siguiente=primero;			
				primero=nuevo;
			}
			strcpy(rutaAuxiliar2,file_path);
			/*
			if(registraNodo(rutaAuxiliar2,name_nodo)!=0){
				return 1;		
			}
			*/
			return 0;
		}
		return 0;
	}
	
	void show_list(){
		actual=primero;
		int i;
		char *caracter=malloc(sizeof(char));
		if(primero!=NULL){
			while(actual!=NULL){
				caracter=&actual->dato;
				printf("%s\n",caracter);
				caracter=NULL;
				actual = actual->siguiente;
			}
		}
		free(actual);
	}
	
	void mensaje(char msg[100]){
		printf("%s\n",msg);
		printf("Presione cualquier tecla para continuar....\n");
		getchar();
		getchar();
	}
	
	int registraNodo(char *ruta_Auxiliar,char *name_nodo){

		FILE *file;
		char separador [] = ";";
		char archivoRegistro[]="registroNodos.txt";
		
		strcat(ruta_Auxiliar,archivoRegistro);	
		strcat(name_nodo,".txt");

		file=fopen(ruta_Auxiliar,"at");
		if(file==NULL){
			fclose(file);
			return 1;
		}
		else{
			fputs(name_nodo,file);
			fputs(separador,file);
			fclose(file);
			return 0;
		}

	}
	
	int copy_file(char *archivoOriginal, char *nuevoArchivo){
		FILE *origen;
		FILE *destino;
		char imprimeCaracter;
		origen = fopen(archivoOriginal,"r");
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

#endif
