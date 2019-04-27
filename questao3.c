#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    int l;
    int c;
    int matriz[l][c];
}ARG;

void * function (void *arg) {
   
    ARG * in = (ARG *) arg;
    int li = in -> l;
    int co = in -> c;
    int m, k;

    for(m=0; m<li; m++){ //teste para ver se esta certo

        for(k=0; k<co; k++){

            printf("%d", in -> matriz[k][m]);
        }

        printf("\n");

    }
 
}

int main(){
  
    int l, c;
    int n, t;
    int i, j;
    int m, k;
    int rc;

    printf("Digite o numero de threads: ");
    scanf("%d", &n);

    pthread_t threads[n];

    printf("Digite a quantidade de linhas e colunas: ");
    scanf("%d %d", &l, &c);

    a.l = l;
    a.c = c;

    ARG a;

    for(i=0; i<a.l; i++){

        for(j=0; j<a.c; j++){
            scanf("%d", &a.matriz[j][i]);
        }

        printf("\n");

    }

    for(t=0; t<=n; t++){

        rc = pthread_create(&threads[t], NULL, function, (void *)(&a));

            if (rc){         
                printf("ERRO; código de retorno é %d\n", rc);         
                exit(-1); 
            }
    }

 /*       for(m=0; m<a.l; m++){

        for(k=0; k<a.c; k++){
            printf("%d", matriz[k][m]);
        }

        printf("\n");

    } */


    pthread_exit(NULL);
    exit(0);
    return 0;
}