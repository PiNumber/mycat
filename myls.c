#include <stdio.h>		/* Header file for system call printf */
#include <unistd.h>		/* Header file for system call gtcwd */
#include <sys/types.h>		/* Header file for system calls opendir, readdir y closedir */
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	
	DIR* dirp;
	struct dirent *fin;
        char *buf=NULL;


       // Sin argumento
        if(argc==1){
          buf=getcwd ( buf, PATH_MAX);
          dirp=opendir(buf);

            /*if (buf==NULL){// Si no hay dirección se sale
		printf("Error en la lectura");
		return -1;
	    }else{
             */
                //Almacenamos dirección actual en dirp
            //}
        //Con un argumento

        }else{
           dirp = opendir(argv[1]);// apuntamos con el puntero dirp que apunta a un dirección de tipo DIR a un descriptor de
                                        //directorio que se puede utilizar para la lectura de las entradas de dicho directorio
        }
        if (dirp==NULL){
	printf("Error en la apertura");
        return -1;
	}
	
	while ((fin=readdir(dirp))!=NULL)
        {
        printf("%s \n", fin->d_name);
	}
	closedir(dirp);		
	
return 0;
}



 
 
 
