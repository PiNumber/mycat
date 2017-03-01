#include <stdio.h>		/* Header file for printf */
#include <sys/types.h>		/* Header file for system call  open */
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>		/* Header file for system calls read, write y close */

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){

	/*If the number of arguments is less than two (argv[0] -> program, argv[1] -> file to be shown) we print the error and return -1*/
	if(argc != 2){
            printf("Error: argumentos erróneos\n");
            return -1;
	}
        if (argv[1] == NULL) {
            printf("Error: argumentos erróneos\n");
            return -1;

        }else{	

            int fd = open(argv[1], O_RDONLY);//Abrimos fichero en modo solo lectura y almacenamos su descriptor de fichero en fd
            char buffer[BUFFER_SIZE];

        if (fd == -1) {
            printf("Error al abrir %s\n", argv[1]);
            return -1;
        }

        while (read(fd, buffer, 1) != 0) {  // Leemos del fichero de 1 en 1 bytes hasta que llegue al final del fichero
		// Escribimos el fichero de 1 en 1, ya que sino el buffer se llena de basura e imprime datos no necesarios (Y no controlados).
		//De ésta manera, conseguimos controlar la lectura y escritura del fichero.
		write(STDOUT_FILENO, buffer, 1);           
		
		// Es otra posible manera de imprimir los datos.				
		// printf("%s", buffer);
        }	
        close(fd);
	
	return 0;
}
	
}
