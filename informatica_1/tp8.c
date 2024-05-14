#define TAM 200 
#include <stdio.h>
#include <stdlib.h>

int ingresarValidarTam(void);
void cargarArreglo(float *, const int);
int calcularValidas(const float *, const int);
int calcularDefectuosas(const float *, const int); 
void mostrarPiezas(const float *, const int);
void mostrarPiezasValidasOrdenadasMenorMayor(const float *, const int);
void ingresarEntero (int *);
void ingresarFlotante (float *);
void swap(int *, int*);

int main (void){
    float arr[TAM];
    int size = ingresarValidarTam();

    cargarArreglo(arr,size);

    printf("\nValidas: %d\n", calcularValidas(arr,size));
    printf("Defectuosas: %d\n\n", calcularDefectuosas(arr,size));
    
    mostrarPiezas(arr,size);
    mostrarPiezasValidasOrdenadasMenorMayor(arr,size);
    
    return 0;
}

void mostrarPiezasValidasOrdenadasMenorMayor(const float *arr, const int size) {
    int indices[TAM]={0};
    int validas = 0;
    for (int i=0; i<size; i++)
        if(*(arr+i)>=20 && *(arr+i)<=200){
            *(indices+validas)=i;
            validas++;
        }

    for (int i = 0; i < validas ; i++)
        for (int j = 0; j < validas - i - 1; j++) 
            if (*(arr+*(indices+j)) > *(arr+*(indices+j+1)))
                swap(indices+j,indices+j+1);

    printf("\nListado de piezas validas ordenadas:\n");
    for (int i=0; i<calcularValidas(arr,size); i++){
        printf("%.2f\n",*(arr+*(indices+i)));
    }   
}

void swap(int *a, int*b){
    int tmp = *a;
    *a=*b;
    *b=tmp;
}

void mostrarPiezas(const float *arr, const int size){
    printf("\nListado de piezas desordenado:\n");
    for (int i=0; i<size; i++)
        printf("%.2f\n",*(arr+i));
}

int calcularDefectuosas(const float *arr, const int size) {
    int defectuosas=0;
    for (int i=0; i<size; i++)
        if(*(arr+i)<20 || *(arr+i)>200)   
            defectuosas++;
    return defectuosas;
}

int calcularValidas(const float *arr, const int size){
    int validas=0;
    for (int i=0; i<size; i++)
        if(*(arr+i)>=20 && *(arr+i)<=200)   
            validas++;
    return validas;
}

void cargarArreglo(float *arr, const int size) {
    printf("ingrese las calidades de las %d piezas\n",size);
    for(int i=0; i<size; i++)
        do{   
            printf("pieza N%d:",i+1);
            ingresarFlotante((arr+i));
            if(*(arr+i)<=0)
                printf("debe ingresar un numero positivo.  \n");
        }while(*(arr+i)<=0  );
}

int ingresarValidarTam(){
    int n=0;
    printf("Ingrese el numero de piezas:");
    do{   
        ingresarEntero(&n);
        if(n<=0)
            printf("debe ingresar un numero positivo.  \n");
        else if (n>TAM)
            printf("debe ingresar un numero menor a %d.  ",TAM);
    }while(n<=0 || n>TAM);
    return n;
}

void ingresarEntero (int *val){
	if (scanf(" %d", val) != 1) {
		printf("Debe ingresar un numero entero.  ");
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
        ingresarEntero(val);
    }   
}

void ingresarFlotante (float *val){
	if (scanf(" %f", val) != 1) {
		printf("Debe ingresar un numero flotante.  ");
		char c;
		while ((c = getchar()) != '\n' && c != EOF);
        ingresarFlotante(val);
    }   
}

