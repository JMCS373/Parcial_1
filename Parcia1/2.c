#include <stdio.h>


char Texto[100];
int Nota,M,Me,Mo,R,De,V:
int main() {
int op; 

    
    do {
        FILE *archivo = fopen("historial.txt", "r");

        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        printf("\n-------------------------------------\n");
        printf("Calculos estadisticos de notas\n");
        printf("1. Calcular Notas\n");
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
                	
                printf("\n\nIntroduzca su primer nombre y primer apellido separados con un guion:\n");
                scanf("%s", Texto);  
                printf("Ingrese el peso (kg): ");
                scanf("%f", &peso);
                printf("Ingrese la altura (m): ");
                scanf("%f", &altura);

                float imc = calcularIMC(peso, altura);


                FILE *archivo = fopen("historial.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1;
                }
                fprintf(archivo, "Peso: %.2f kg, Altura: %.2f m, IMC: %.2f, Nombre:%s\n",
                        peso, altura, imc, Texto);
                fclose(archivo);

                printf("IMC calculado: %.2f\n", imc);

                if (imc<18.5){
                    printf("Su IMC es bajo %s",Texto);
                }else if (18.5<=imc<=24.9){
                    printf("Su IMC es normal %s",Texto);
                }else if (25<=imc<29.9){
                    printf("Su IMC es sobrepeso %s",Texto);
                }else if (imc>29.9){
                    printf("Su IMC es obeso %s",Texto);
                }
                
                break;

            case 2:
                printf("Historial de IMC:\n");
                char linea[100]; 
                while (fgets(linea, sizeof(linea), archivo) != NULL) {
                    printf("%s", linea);
                }
                fclose(archivo);

                break;

            case 3:
                archivo = fopen("historial.txt", "w");
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1; 
                }
                fclose(archivo);
                printf("Historial borrado.\n");
                break;

            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Por favor, elija una opcion valida.\n");
                break;
        }
    } while (op != 4); 

    return 0; 
}