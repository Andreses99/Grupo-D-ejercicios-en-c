#include <stdio.h>
#include <string.h>
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





void prueba(){

    int cont=0;
    int continuar=1;
    int aciertos=0;
    int tamanho=0;
    int sumatoria=0;
   // char* prue[]={"O","X","X","O","X","O","O"};
    char prue[]={"OOXXOXXOOO"};
   // char prue[]={'O','O','X','X','O','X','X','O','O','O'};
    tamanho= sizeof(prue);
    int sumar[sizeof(prue)-2];
    for (int i = 0; i <=sizeof(prue)-2 ; ++i) {
       // printf("%d", sizeof(prue));
       cont++;
        if (prue[i] == 'O') {

            sumar[i]=cont;
//            suma+=suma+1;
            }
        else if (prue[i] =='X')
                cont=0;
                sumar[i]=cont;

    }
   // printf("%d",suma);
    for (int j =0; j<=tamanho-2  ; ++j) {

            printf("%d ", sumar[j]);
            sumatoria=sumatoria+sumar[j];

    }
    printf(" \n la suma dio = %d ",sumatoria);
      //  printf("%d + los aciertos son %d y las fallas son %d",resultado,aciertos,fallas);
     //   }

    }







int main() {
    prueba();
    numPrimos(23);
    return 0;
}
