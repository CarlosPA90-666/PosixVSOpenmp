#ifndef FUNCTIONSOPENMP_H_INCLUDED
#define FUNCTIONSOPENMP_H_INCLUDED

void matrizInit(int N,  double *matrizA, double *matrizB, double *matrizC);

void multiplicacionMatrices(int N,  double *matrizA, double *matrizB, double *matrizC);

void imprimirMatrices(int N, double *matriz);

void MatrizTranspuesta(int n, double *matrizB);

void sampleStart();

void sampleStop();

void printTime();


#endif
