#include <stdio.h>
#include <stdlib.h>


char Texto[100];
int num1=0;
int num2=0;
int res;
int main() {

int op; 
    
    do {
        FILE *archivo = fopen("salida.txt", "r");

        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        printf("\n-------------------------------------\n");
        printf("JUEGO SIMULADO DEL GRAN 8\n");
        printf("1. JUGAR AL GRAN 8\n");
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
                
                printf("\n\nIntroduzca su primer nombre y primer apellido unidos con un guion:\n");
                scanf("%s", Texto);  
                num1 = rand() %9;
                num2 = rand() %9;
                res = num1+num2;
                if (res==8)
                {
                    printf("Has gando %s, tu resultado fue de %d",Texto,res);
                }else{ 
                    printf("Has perdido %s, tu resultado fue de %d",Texto,res);
                }
                
                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fprintf(archivo, "Resultado: %d, Nombre: %s\n",
                        res, Texto);
                fclose(archivo); 

                break;

            case 2:
                printf("Historial de JUEGO DEL GRAN 8:\n");
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
                printf("Opcion invalida, Elija una opcion valida.\n");
                break;
        }
    } while (op != 4); 

    return 0; 
}