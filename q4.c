#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t votmutex; // mutex dinamico criado
int pthread_mutex_init (votmutex, NULL);


typedef struct{
		int n;
		int c;
		int t;
		int finalResult[c];   //resultado final da soma de votos dos candidatos
}ARG; // estrutura criada para enviar argumentos para a função
 


void * function (void *arg) {
	FILE *arq;               // ponteiro para abrir arquivo .bin   
    ARG * in = (ARG *) arg;  //
    int resultados[in->c];       //ponteiro onde será salvo os resultados lidos
    char filename[in->n];        //array para nome do arquivo de tamanho n(qtd arq)

    	for (int j = 1; j <= in->n; j++){

	    	pthread_mutex_lock(&votmutex);

			sprintf(filename, "%d.bin",j);//escrever o nome do arquivo 
   
	 		arq = fopen(filename, "rb"); //abrir arquivo no modo leitura
	 		fread(&resultados, sizeof (int), in->c, arq); // ler arquivo e salvar na string

	 		for(int h=0; h < in->c; h++){ // for criado para somar e salvar os votos dos candidatos na posição referente ao mesmo
	 			for (int s= 0; s <= in->c; s++){
	 				if (resultados[h]==s){
	 					finalResult[s]++; //incrementa a qtd de votos do candidato
	 					in->porcResult[s]++; // incrementa a qtd de votos do candidato (variavel criada para faciliatr o calculo da porcentagem) 
	 				}
	 			}
	 			
	 		}



	 		pthread_mutex_unlock(&votmutex); 
 		
 		}
}


int main(){
	ARG a;
	int open;

	printf("Digite a qtd de arquivos: \n");
	scanf("%d", &a.n);

	do{
	printf("Digite a qtd de Threads: \n");
	scanf("%d", &a.t);
	}while(t<1 || t>n);

    printf("Digite a qtd de candidatos: \n");
	scanf("%d", &a.c);

	pthread_t threads[a.t]; //criação de T threads
	


	for(int i=0; i<a.t; i++){
		open = pthread_create(&threads[i], NULL, function, (void *)(&a));
		if (open!=0)     
            printf("ERRO\n");
        else 
            printf("thread %d criada", a.t);         
	}

	for(int k=0; k<a.t; k++){
        pthread_join(threads[k], NULL);
    }

    printf("")


    pthread_exit(NULL);

    return 0;

}
