#include <stdio.h>		/* Header file for system call printf */
#include <unistd.h>		/* Header file for system call gtcwd */
#include <sys/types.h>		/* Header file for system calls opendir, readdir y closedir */
#include <dirent.h>
#include <string.h>
int open (const char * path, int flag);


int main(int argc, char *argv[])
{
	DIR* directorio;
	struct dirent *fin;
    	char *buf=NULL;
	int nbytes=0;
	
	//Aquí estamos comprobando que no tenga argumentos. Si no los tiene:
    if(argc==1){
	//Obtenemos ruta actual y lo guardamos en buf
          buf=getcwd ( buf, PATH_MAX);
          //Abrimos el directorio y guardamos el descriptor del directorio en directorio
	  directorio=opendir(buf);
	//Leemos todas las entradas del directorio actual mientras las haya.
          while ((fin=readdir(directorio))!=NULL) 
	  {
		// Si el atributo d_type es de tipo regular, entonces:
		if (fin->d_type==DT_REG)
			{
				// Abrimos el fichero y almacenamos el descriptor de fichero del inicio.
				//Usamos 0000, que es sólo lectura, en vez de O_RDONLY, ya que no reconocía ese formato.
				int fd = open (fin->d_name, 0000);
				
				//Usamos LSEEK para mover el puntero al final del fichero.			
				nbytes= lseek(fd, 0, SEEK_END);	
				//Cerramos el fichero
				close(fd);
				//Imprimimos el nombre del archivo, con una tabulación y el tamaño.
				printf ("%s\t %i\n", fin->d_name, nbytes);
				
			}
	  }
          closedir(directorio);
          return 0;
		}

	else{
		//Si tiene algún argumento, damos el error.
		printf("ERROR: ES UN SCRIPT SIN ARGUMENTOS\n");
		return -1;
	}
}
