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
 
    if (in->contador < 100000) {

        printf("contador: %d\n thread: %d\n", in->contador, in->i);
        
        }
 
    if(in->contador == 100000) {
       
        printf("A thread %d alcançou o valor 100000!", in->i);
   
    }
 
}
 
int main () {
 
    int n;
   
    printf("Digite a quantidade de threads que deseja utilizar: \n");
    scanf("%d", &n);
 
    n = n-1;
 
    pthread_t threads[n];
    int teste;
    ARG a;

    int rc;
 
    do{
 
        for(a.i=0; a.i<=n; a.i++){

            if(a.contador < 100000) { 

            rc = pthread_create(&threads[a.i], NULL, function, (void *)(&a));

                if (rc){         
                    printf("ERRO; código de retorno é %d\n", rc);         
                    exit(-1); 
                }    
            
            }
 
        }
 
        if(a.contador < 100000){
 
            for(a.j=0; a.j<=n; a.j++){
                
                if(a.contador < 100000) {
                pthread_join(threads[a.j], NULL);
                }
            }
        }
 
    }while(a.contador < 100000);

    pthread_exit(NULL);
    exit(0);
}