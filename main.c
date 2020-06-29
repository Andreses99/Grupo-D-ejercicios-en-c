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

void numEgolatra(int num) {
    int sum=0;
    int tamanho = sizeof(num)-1;
    char numString [sizeof(num)];
    sprintf(numString, "%d", num);
    printf("tamaño es %d",num);

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
        } else{
            printf("ERROR DE SINTAXIS");
        }
    }
    for (int j = 0; j <=tamanho-2; ++j) {

        printf("%d ", sumar[j]);
        sumatoria = sumatoria + sumar[j];

    }
    return sumatoria;

}

int main() {
    printf("\nla suma dio! %d \n",prueba());
    numEgolatra(0);
    int numPrim;
    bool a = true, b = false;
    printf("Digite un numero\n");
    scanf("%d", &numPrim);
    if (numPrim > 0) {
        numPrimos(numPrim);
    } else {
        printf("Error tiene que elegir un numero mayor a 1");
    }

    return 0;
}
