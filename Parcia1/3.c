#include <stdio.h>


char Texto[100];
int main() {

    int op,precio,precio1,IVA;
    do {
        
        FILE *archivo = fopen("salida.txt", "r");

        
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        
        printf("\n-------------------------------------\n");
        printf("IMPUESTO IVA\n");
        printf("1. Calcular IVA \n");
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
                	
                printf("\n\nIntroduzca el nombre del producto:\n");
                scanf("%s", Texto);  
                printf("Ingrese el precio del producto:\nQ");
                scanf("%d",&precio);

                precio1= (precio-(precio*0.12));
                IVA= precio*0.12;



                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1;
                }
                fprintf(archivo, "Precio de: %s = %d, Costo del IVA: %d\n",
                        Texto, precio1,IVA);
                fclose(archivo);

                printf("Precio de: %s = %d, Costo del IVA: %d\n",Texto,precio1,IVA);
                break;

            case 2:
                printf("Historial de IVA:\n");
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