#include <stdio.h>
#include <math.h>

char Texto[100];
int Nota,All,n1,n2,n3,n4,n5,M,Me,Mo,R,De,a,b,c,d,e,V;
int main() {
int op; 

    
    do {
        FILE *archivo = fopen("salida.txt", "r");

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
                printf("Ingrese sus 5 calificaciones separadas por comas, en orden descendente:\n");
                scanf("%d,%d,%d,%d,%d",&n1,&n2,&n3,&n4,&n5);

                All= n1+n2+n3+n4+n5;
                M = (n1+n2+n3+n4+n5)/5;
                Me = (n1+n2+n3+n4+n5)/2;
                //Moda
                if (n1==n2||n1==n3||n1==n4||n1==n5)
                {
                   Mo=n1;
                }
                if (n2==n3||n2==n4||n2==n5)
                {
                   Mo=n2;
                }
                if (n3==n4|n3==n5)
                {
                   Mo=n3;
                }
                if (n4==n5)
                {
                   Mo=n4;
                }
                R= n1-n5;
                a = n1-M;
                b = n2-M;
                c = n3-M;
                d = n4-M;
                e = n5-M;
                De=(sqrt(((a+b+c+d+e)*(a+b+c+d+e))/4));
                V=((((n1-M)*(n1-M))/5)+(((n2-M)*(n2-M))/5)+(((n3-M)*(n3-M))/5)+(((n4-M)*(n4-M))/5)+(((n5-M)*(n5-M))/5));

                FILE *archivo = fopen("salida.txt", "a"); 
                if (archivo == NULL) {
                    printf("No se pudo abrir el archivo para escribir.\n");
                    return 1;
                }
                fprintf(archivo, "Media:%d, Mediana:%d, Moda:%d, Rango:%d, Desviacion estanfar:%d, Varianza:%d, Nombre:%s\n",
                        M,Me,Mo,R,De,V,Texto);
                fclose(archivo);

                break;

            case 2:
                printf("Historial de calculos estadisticos\n");
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
                printf("Borrar historial\n");
                break;

            case 4:
                printf("Cerrar programa\n");
                break;

            default:
                printf("Opcion invalida,elija una opcion valida.\n");
                break;
        }
    } while (op != 4); 

    return 0; 
}