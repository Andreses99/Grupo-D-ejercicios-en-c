#include <stdio.h>
#include <cstdbool>
#include <math.h>
void numPrimos(int num){
    int cont;
    int numPrim;

    for (int i = num; i>0 ; --i) {
        numPrim=1;
        cont=2;
        while (cont<=(i/2)){
            if (i % cont==0) {
                numPrim = 0;

            }
            cont++;
        }
        if (numPrim) {
            printf("%d-", i);

        }

    }

}

void numEgolatra(double num) {

    double sum=0;
    double tamanho = sizeof(num)-1;
    char numString [sizeof(num)];
    sprintf(numString, "%d", num);


    if (num>0 & num<10){
        printf("\n el numero %d es Egolatra", num);
    }
    else {
        for (int i = 0; i < tamanho; i++) {
            int cifraActual = numString[i] - '0';
            //  printf("\n %d-",cifraActual);
            int elevar = pow(cifraActual, tamanho);
            //printf(" \n %d - %d", cifraActual, tamanho);
            sum = sum + (elevar);
            // printf("%d *",sum);
        }

        if (sum == num) {
            printf("\n el numero %d es Egolatra", num);
        } else {
            printf(" \n EL NUMERO %d NO ES EGOLATRA", num);
        }
    }
}

int prueba() {

    int cont = 0;
    int tamanho ;
    int sumatoria = 0;
    char prue[] = {"OOXXOXXOOO"};
    tamanho = sizeof(prue);
    int sumar[sizeof(prue)];
    for (int i = 0; i <= tamanho; ++i) {
        cont++;
        if (prue[i] == 'O') {

            sumar[i] = cont;
        } else if (prue[i] == 'X') {
            cont = 0;
            sumar[i] = cont;
        }
    }
    for (int j = 0; j <=tamanho-2; ++j) {

        printf("%d ", sumar[j]);
        sumatoria = sumatoria + sumar[j];

    }
    return sumatoria;

}

int main() {
    int opt=0;
    bool continuar=true;

    while (continuar){

        printf("\n\n\t-*-*-*-*-*-*-* BIENVENIDOS -*-*-*-*-*-*-*-*-*\n\n");

        printf("1) Encontrar los numeros primos descendentemente. \n");
        printf("2) Verificar si el numero es egolatra o no.\n");
        printf("3) ...........................\n");
        printf("4)...................\n");
        printf("5).............\n");
        printf("6)....................\n");
        printf("7) Ver el resultado de la prueba ya registrada. \n");
        printf("8) Salir del programa \n");
        printf("Que desea hacer? \n");
        scanf("%d",&opt);

        switch (opt){

            case 1:
                int numPrim;
                printf("\tEjercicio 1\n");
                printf("Digite un numero\n");
                scanf("%d", &numPrim);
                if (numPrim > 0) {
                    numPrimos(numPrim);
                } else {
                    printf("Error tiene que elegir un numero mayor a 1\n");
                }
                break;

            case 2:
                double num;
                printf("\tEjercicio 2 \n");
                printf("Digite un numero para saber si es egolatra o no \n");
                scanf("%d",&num);
                numEgolatra(num);

                break;

            case 3:
                printf("\tEjercicio 3 \n");

                break;

            case 4:
                printf("\tEjercicio 4 \n");

                break;

            case 5:
                printf("\tEjercicio 5 \n");

                break;

            case 6:
                printf("\tEjercicio 6\n ");

                break;

            case 7:

                printf("\tEjercicio 7\n ");
                printf("\nla suma dio! %d \n",prueba());


                break;

            case 8:
                printf("\tPrograma terminado que tenga buen dia \n");
                continuar=false;


                break;
            default: puts("Error");
                continuar=false;

        }

    }

    return 0;
}
