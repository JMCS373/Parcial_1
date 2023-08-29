#include <stdio.h>


char Texto[100];
int main() {

    int op,num;
    do {
        
        FILE *archivo = fopen("salida.txt", "r");

        
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        
        printf("\n-------------------------------------\n");
        printf("PRIMO O COMPUESTO\n");
        printf("1. Calcular numero \n");
        printf("2. Ver historial\n");
        printf("3. Borrar historial\n");
        printf("4. Salida\n");
        printf("Elije una opcion: ");
        if (scanf("%d",&op)!=1){
        printf("Error:Ingrese una opcion valida\n");
        }
        getchar(); 

        switch (op) {
            case 1:
                printf("Introduzca un numero:\n");
                scanf("%d",&num);
                
                if (num == 0 || num == 1)
                {
                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1;
                }
                fprintf(archivo, "El numero ingresado es primo");
                fclose(archivo);

                printf("El numero ingresado es primo\n");
                }
                if (num == 4){
                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1;
                }
                fprintf(archivo, "El numero ingresado es compuesto");
                fclose(archivo);

                printf("El numero ingresado es compuesto\n");
                }
                for (int x = 2; x < num / 2; x++) {

                    if (num % x == 0){
                        FILE *archivo = fopen("salida.txt", "a"); 
                        if (archivo == NULL) {
                            printf("No se pudo abrir el archivo para escribir.\n");
                            return 1;
                        }
                        fprintf(archivo, "El numero ingresado es compuesto");
                        fclose(archivo);

                        printf("El numero ingresado es compuesto\n");
                    }else
                    {
                        FILE *archivo = fopen("salida.txt", "a"); 
                        if (archivo == NULL) {
                            printf("No se pudo abrir el archivo para escribir.\n");
                            return 1;
                        }
                        fprintf(archivo, "El numero ingresado es primo");
                        fclose(archivo);
                        printf("el numero ingresado es primo");
                    }
                    
                }

                break;

            case 2:
                printf("Historial de PRIMOS Y COMPUESTOS:\n");
                char linea[100];
                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                    printf("%s", linea);
                }
                fclose(archivo);

                break;

            case 3:
                archivo = fopen("salida.txt", "w");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fclose(archivo); 
                printf("Historial borrado.\n");
                break;

            case 4:
                printf("Cerrar programa\n");
                break;

            default:
                printf("Opcion invalida. Por favor, elija una opcion valida.\n");
                break;
        }
    } while (op != 4); 

    return 0; 
}