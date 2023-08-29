#include <stdio.h>


char Texto[100];
int main() {

    int op,a,a1,b,b1,c,c1,d,d1,e,e1,R;
    do {
        
        FILE *archivo = fopen("salida.txt", "r");

        
        if (archivo == NULL) {
            printf("No se pudo abrir el archivo para leer.\n");
            return 1; 
        }

        
        printf("\n-------------------------------------\n");
        printf("ADIVINANZAS\n");
        printf("1. COMENZAR JUEGO \n");
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
            printf("COMIENZA JUEGO\n");
            printf("Tengo agujas y no se coser, tengo numeros y no se leer.\n");
            printf("1) maquina de coser\n");
            printf("2) reloj\n");
            printf("3) dial\n");
            scanf("%d",&a);
            if (a==2)
            {
                a1=1;
            }else{
                a1=0;
            }
            
            printf("Volando voy, volando vengo, y en el camino me entretengo.\n");
            printf("1) pajaro\n");
            printf("2) avion\n");
            printf("3) cometa\n");
            scanf("%d",&b);
            if (b==1)
            {
                b1=1;
            }else{
                b1=0;
            }

            printf("Blanca por dentro, verde por fuera, si quieres que te lo diga, espera.\n");
            printf("1) manzana\n");
            printf("2) pera\n");
            printf("3) sandia\n");
            scanf("%d",&c);
            if (c==2)
            {
                c1=1;
            }else{
                c1=0;
            }

            printf("Siempre avanzo sin moverme del sitio, marco el paso del tiempo con mi tic-tac.\n");
            printf("1) pendulo\n");
            printf("2) corazon\n");
            printf("3) reloj\n");
            scanf("%d",&d);
            if (d==3)
            {
                d1=1;
            }else{
                d1=0;
            }

            printf("En el campo camino, sin patas me desplazo, soy muy suave y cuando me enojo, todo se estremece.\n");
            printf("1) nube\n");
            printf("2) oveja\n");
            printf("3) algodon\n");
            scanf("%d",&e);
            if (e==1)
            {
                e1=1;
            }else{
                e1=0;
            }

            R=a1+b1+c1+d1+c1;

            printf("Escriba su nombre:\n");
            scanf("%s",Texto);

                    FILE *archivo = fopen("salida.txt", "a"); 
                    if (archivo == NULL) {
                        printf("No se pudo abrir el archivo para escribir.\n");
                        return 1;
                    }
                    fprintf(archivo, "%d RESPUESTAS CORRECTAS DE %s\n",R,Texto);
                    fclose(archivo);

                    printf("%d RESPUESTAS CORRECTAS DE %s",R,Texto);
                    break;

            case 2:
                printf("Historial de JUEGOS:\n");
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
                printf("Opcion invalida, elija una opcion valida.\n");
                break;
        }
    } while (op != 4); 

    return 0; 
}