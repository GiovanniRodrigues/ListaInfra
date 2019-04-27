#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    int contador;
    int i;
    int j;
}ARG;

void * function (void *arg) {
	
    ARG * in = (ARG *) arg;

    in->contador = in->contador+1;

    printf("contador: %d\n thread: %d\n", in->contador, in->i);	

    if(in->contador == 100000) {
        
        printf("A thread %d alcançou o valor 100000!", in->i);
    
    }

}

int main () {

    int n;
    
    printf("Digite a quantidade de threads que deseja utilizar: \n");
    scanf("%d", &n);

    n = n-1; //coloquei isso aqui pq tava dando uma thread a mais

	pthread_t threads[n];
    ARG a;

	do{

        for(a.i=0; a.i<=n; a.i++){

            pthread_create(&threads[a.i], NULL, function, (void *)(&a));

            if(a.contador == 100000) printf("break do create");

        }

        if(a.contador < 100000){

            for(a.j=0; a.j<=n; a.j++){

                pthread_join(threads[a.j], NULL);

            }
        }

    }while(a.contador < 100000);

	exit(0);
}
