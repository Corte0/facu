#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float calcularAreaCirculo(float radio);
float celciusAFarenheit(float celcius);
int esPar(int n);
int contarDigitos(int n);
float potencia (float n, int pot);
int invertirEntero(int n);
int sumaNaturales(int n);
int encontrarMaximo(int a, int b, int c);
int esPrimo(int n);
int factorial(int n);

//cadenas
int longitudDeCadena(char *s);
char* concatenar(char*a, char*b);

int main () {
  int n = 8;
  float f = 4.56;
  char cadena[] = "Hola ";
  char cadena1[] = "Mundo";
  printf("numero: %d\ninverso: %d\ndigitos: %d\n",n,invertirEntero(n), contarDigitos(n));
  printf("suma: %d\n",sumaNaturales(n));
  printf("maximo: %d\n",encontrarMaximo(4,5,3));
  printf("%d %s\n",n,esPrimo(n)?"es primo":"no es primo");
  printf("%d!=%d\n",n,factorial(n));
  printf("%f a la %d = %f\n",f,n,potencia(f,n));
  printf("%s tiene %d caracteres\n",cadena,longitudDeCadena(cadena));
  printf("%s\n",concatenar(cadena,cadena1));
  return 0;
}

float calcularAreaCirculo(float radio){
  return (M_PI * radio * radio);
}

float celciusAFarenheit(float celcius){
  return (float)180/100 * celcius + 32;
}

int esPar(int n){
  return n % 2;
}

int contarDigitos(int n){
  int digitos = 1, potencia = 10;
  while (n %  potencia != n){
    digitos++;
    potencia *= 10;
  }
  return digitos;
}

int invertirEntero(int n){
  int res = 0;
  while (n != 0){
    res = res * 10 + n % 10;
    n /= 10;
  }
  return res;
}

int sumaNaturales(int n){
  int res = 0;
  while (n != 0){
    res += n;
    n--;
  }
  return res;
}

int encontrarMaximo(int a, int b, int c){
  if(a>b && a>c)
    return a;
  if(b>c)
    return b;
  return c;
}

int esPrimo(int n){
  for(int i = n-1; i>1; i--)
    if(n % i == 0) return 0;
  return 1;
}

int factorial(int n){
  for(int i = n-1; i>1; i--)
    n *= i;
  return n;
}

float potencia (float n, int pot){
  float res = n;
  for(int i=1; i<pot; i++)
    res *= n;
  return res;
}

// Cadenas y Caracteres

int longitudDeCadena(char *s){
  int longitud = 0;
  while (*(s+longitud) != '\0')
    longitud++;
  return longitud;
}

