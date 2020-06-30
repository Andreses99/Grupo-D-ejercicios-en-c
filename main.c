#include <stdio.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include<string.h>
#include <stdlib.h>

int Uw,Fll;
char aux;

int falling(char number[10]){
    for (int i =0;i<strlen(number);i++){
        for (int j =0;j<strlen(number)-1;j++){
            if (number[j]>number[j+1]){
                aux=number[j];
                number[j]=number[j+1];
                number[j+1]=aux;
            }
        }
    }
    Fll=atoi(number);
    return Fll;
}
int Upward(char number[10]){
    for (int i =0;i<strlen(number);i++){
        for (int j =0;j<strlen(number)-1;j++){
            if (number[j]<number[j+1]){
                aux=number[j];
                number[j]=number[j+1];
                number[j+1]=aux;
            }
        }
    }
    Uw=atoi(number);
    return Uw;
}
int numberMagic(char number[10]) {
    return Upward(number)-falling(number);
}

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

double CalImc(float peso, float altura) {
    return peso/(altura*altura);
}


int main() {
    int opt = 0;
    bool continuar = true;

    while (continuar) {

        printf("\n\n\t-*-*-*-*-*-*-* BIENVENIDOS -*-*-*-*-*-*-*-*-*\n\n");

        printf("1) Encontrar los numeros primos descendentemente. \n");
        printf("2) Verificar si el numero es egolatra o no.\n");
        printf("3) Numero Magico\n");
        printf("4) IMC \n");
        printf("5)Calcular la suma de cada uno de los digitos que no correspondan a un determinado digito\n");
        printf("6)Dado un patron de bits p y un numero n, cuantas veces esta p en F(n)?\n");
        printf("7) Ver el resultado de la prueba ya registrada. \n");
        printf("8) Salir del programa \n");
        printf("Que desea hacer? \n");
        scanf("%d", &opt);

        switch (opt) {

            case 1:
                printf("\tEjercicio 1\n");
                printf("Digite un numero\n");
                int numPrim;
                scanf("%d", &numPrim);
                if (numPrim > 0) {
                    numPrimos(numPrim);
                } else {
                    printf("Error tiene que elegir un numero mayor a 1\n");
                }
                main();
                break;

            case 2:
                printf("\tEjercicio 2 \n");
                printf("Digite un numero para saber si es egolatra o no \n");
                double num;
                scanf("%d", &num);
                numEgolatra(num);
                main();
                break;

            case 3:
                printf("\tEjercicio 3 \n");

                printf("Bienvenido al Programa de Numeros Magicos \n");
                printf("Digite un numero: \n");
                char number[10];
                scanf("%s", number);
                int nb;
                nb = atoi(number);
                if (nb == numberMagic(number)) {
                    printf("El numero %i es un numero magico\n",nb);
                }
                else {
                    printf("El numero %i no es un numero magico\n",nb);
                }
                main();
                break;

            case 4:
                printf("\tEjercicio 4 \n");
                printf("¿Es usted Hombre o Mujer?\n");
                printf("Escribe h para hombre y m para mujer\n");
                char genero;
                scanf("%s", &genero);
                printf("Digite su peso?\n");
                float peso,altura;
                if (scanf("%f", &peso) != 1) {
                    printf("solo se puede ingresar numeros");
                } else {
                    printf("Digite su altura \n");
                    if (scanf("%f", &altura) != 1) {
                        printf("solo se puede ingresar numeros");
                    } else {
                        switch (genero) {
                            case 'h':
                                if (CalImc(peso, altura) <= 17) {
                                    printf("Desnutricion");
                                } else if (CalImc(peso, altura) > 17 && CalImc(peso, altura) < 20) {
                                    printf("Bajo peso");
                                } else if (CalImc(peso, altura) >= 20 && CalImc(peso, altura) < 25) {
                                    printf("Normal");
                                } else if (CalImc(peso, altura) >= 25 && CalImc(peso, altura) < 30) {
                                    printf("Sobrepeso");
                                } else if (CalImc(peso, altura) >= 30 && CalImc(peso, altura) < 35) {
                                    printf("Obesidad");
                                } else if (CalImc(peso, altura) >= 35 && CalImc(peso, altura) <= 40) {
                                    printf("Obesidad Marcada");
                                } else if (CalImc(peso, altura) > 40) {
                                    printf("Obesidad Morbida ");
                                }
                                break;
                            case 'm':
                                if (CalImc(peso, altura) <= 16) {
                                    printf("Desnutricion");
                                } else if (CalImc(peso, altura) > 16 && CalImc(peso, altura) < 20) {
                                    printf("Bajo peso");
                                } else if (CalImc(peso, altura) >= 20 && CalImc(peso, altura) < 24) {
                                    printf("Normal");
                                } else if (CalImc(peso, altura) >= 24 && CalImc(peso, altura) < 29) {
                                    printf("Sobrepeso");
                                } else if (CalImc(peso, altura) >= 29 && CalImc(peso, altura) < 34) {
                                    printf("Obesidad");
                                } else if (CalImc(peso, altura) >= 34 && CalImc(peso, altura) <= 39) {
                                    printf("Obesidad Marcada");
                                } else if (CalImc(peso, altura) > 39) {
                                    printf("Obesidad Morbida ");
                                }
                                break;
                            default:
                                printf("Error %s no es valido por favor ingresa de nuevo", genero);
                                break;
                        }
                    }
                    main();
                    break;

                    case 5:
                        printf("\tEjercicio 5 \n");
                    int sum;
                    int cont=0;
                    int dt;
                    int n1;
                    int n2;

                    printf("digite el numero inicial del rango!\n");
                    scanf("%d",&n1);
                    printf("digite el segundo numero del rango!\n ");
                    scanf("%d",&n2);

                    printf("digite el numero que no quiere tener en cuenta: \n");
                    scanf("%d",&dt);
                    int is=n1;

                    for (int i=n1;i<=n2;i++){
                        int is=i;


                        while (is>=i) {
                            while (is>0) {
                                if (is % 10 != dt) {
                                    sum = sum + is % 10;

                                    is = is / 10;


                                } else {
                                    cont++;

                                    is = is / 10;
                                }
                            }

                        }

                    }
                    printf(" \nRespuesta: ");
                    printf("\nSuma: %d",sum);
                    printf("\nnumeros sobrantes: %d",cont);
                     main();
                    break;

                    case 6:
                        printf("\tEjercicio 6\n ");


                    long   patron;
                    int   b1=0;
                    int b2=1;
                    int r=1;
                    int suma=0;
                    int n;
                    int rt;
                    printf("Digite el patron de bits: \n");
                    scanf("%d",&patron);
                    printf("digite el numero: \n");
                    scanf("%i",&n);
                    printf("\n las veces que esta %d",patron);
                    printf("  en F(%d",n,")");

                    printf(")");
                    while(patron>0){
                        suma=suma+patron%10;
                        patron=patron/10;


                    }

                    for (int i=1;i<n;i++){
                        b2=b1+r;
                        b1=r;
                        r=b2;

                    }

                    if(sum<b2){
                        rt=b2/suma;

                        printf(" Es: %d \n",rt);
                    }else{
                        printf("no se encuentra ningun patron");
                    }
                    printf("\nF(%d",n);
                    printf(")= %d",b2);
                    main();
                    break;

                    case 7:

                        printf("\tEjercicio 7\n ");
                    printf("\nla suma dio! %d \n", prueba());

                    main();
                    break;

                    case 8:
                        printf("\tPrograma terminado que tenga buen dia \n");
                    continuar = false;

                    break;
                    default:
                        puts("Error");
                    continuar = false;

                }

        }

        return 0;
    }
}
