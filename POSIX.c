#include <stdio.h>
#include <stdlib.h>
#include "functionsPOSIX.h"
#include <pthread.h>

#define SIZE_DATA (1024*1024*64*3)

static double MEM_CHUNK[SIZE_DATA];

//estrategia declaracion de todas las variables de forma global

int N, numT;
double *matrizA, *matrizB, *matrizC;

void *multiplicacionMatricesT(void *arg){

	int i,j,k; //contadores
        int idthreads;//identificador del hilo
        int porcion;// porcion de la matrizA a enviar
        int inicioFila, finFila;//inicio y fin de la porcion de la matriz A

	idthreads   = *(int *)(arg); // se obtiene el identificador del hilo secuencialmente
	porcion     = N/numT;//porcion a computar
	inicioFila  = idthreads*porcion;
	finFila     = (idthreads +1) *porcion;


        for(i=inicioFila; i<finFila; i++)
                for(j=0; j<N; j++)
                {
                        double *pA, *pB, suma =0.0;
                        pA = matrizA+(i*N);//Fila
                        pB = matrizB+j; //Columna
                        for(k=0;k < N;k++, pA++, pB+=N){

                                suma += (*pA * *pB);
                        }
                        matrizC[i*N+j] = suma;
                }

return 0;
}

int main(int argc, char ** argv)
{
	int countT; //Contador general para los hilos
	pthread_t * hilos;//declarando apuntadores a hilos (posix)

	N = (int) atof(argv[1]);
	numT = (int) atof(argv[2]);


	matrizA = MEM_CHUNK;
	matrizB = matrizA + N*N;
	matrizC = matrizB + N*N;
	matrizInit(N, matrizA, matrizB, matrizC);

	sampleStart();


	//declaracion de hilos y asignacion de memoria
	hilos = (pthread_t *) malloc(numT*sizeof(pthread_t));
	//Se reparte el trabajo invocando cada hilo
	for (countT=0; countT<numT; countT++){
		int *tID;//puntero identificador del hilo
		tID = (int *) malloc(sizeof(int));
		*tID = countT;//Se apunta el puntero al contador general de hilos
		pthread_create(&hilos[countT], NULL, multiplicacionMatricesT,(void *) tID);

	}

	for(countT=0; countT<numT; countT++){
		//espera a que todos los hilos terminen al tiempo (sincronizacion)
		pthread_join(hilos[countT], NULL);

	} 
	sampleStop();
	printTime();


	return 0;

}
