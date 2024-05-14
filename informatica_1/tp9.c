#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct
{
    char nombre[40];
    int anio_nacimiento;
} autor_t;

typedef struct libro
{
    char nombre[40];
    int cant_paginas;
    int cant_capitulos;
    int *paginas_por_capitulo;
    float precio;
    autor_t datos_autor;
} libro_t;

void ingresar_cantidad(int *);
void cargar_biblioteca(libro_t *bib, int cant);
void imprimir_biblioteca(libro_t *bib, int cant);
void ordenar_por_precio_menor_mayor(libro_t *bib, int cant);

void ingresarEntero(int *);
void ingresarFlotante(float *);
void swap_libro(libro_t *a, libro_t *b);

int main()
{

    libro_t biblioteca[TAM] = {0};
    int cantidad;

    ingresar_cantidad(&cantidad);

    cargar_biblioteca(biblioteca, cantidad);

    printf("===============================================\n");
    printf("Imprimr biblioteca desordenada: \n");
    imprimir_biblioteca(biblioteca, cantidad);

    printf("===============================================\n");
    printf("Imprimir biblioteca ordenada: \n");
    ordenar_por_precio_menor_mayor(biblioteca, cantidad);
    imprimir_biblioteca(biblioteca, cantidad);

    return 0;
}

void ordenar_por_precio_menor_mayor(libro_t *bib, int cant)
{
    for (int i = 0; i < cant - 1; i++)
        for (int j = 0; j < cant - i - 1; j++)
            if (bib[j].precio > bib[j + 1].precio)
                swap_libro(&bib[j], &bib[j + 1]);
}

void swap_libro(libro_t *a, libro_t *b)
{
    libro_t temp = *a;
    *a = *b;
    *b = temp;
}

void imprimir_biblioteca(libro_t *bib, int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("Nombre del libro: %s\n", bib[i].nombre);
        printf("Cantidad de paginas: %d\n", bib[i].cant_paginas);
        printf("Cantidad de capitulos: %d\n", bib[i].cant_capitulos);

        for (int j = 0; j < bib[i].cant_capitulos; j++)
        {
            printf("Cantidad de paginas del capitulo %d: %d\n", j + 1, bib[i].paginas_por_capitulo[j]);
        }

        printf("Precio del libro: %.2f\n", bib[i].precio);
        printf("Nombre del autor: %s\n", bib[i].datos_autor.nombre);
        printf("Fecha de nacimiento del autor: %d\n", bib[i].datos_autor.anio_nacimiento);
        i != cant - 1 ? printf("------------------------------------------------\n") : printf("\n");
    }
}

void cargar_biblioteca(libro_t bib[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese los datos del libro #%d:\n", i + 1);
        printf("Nombre del libro: ");
        scanf(" %[^\n]s", bib[i].nombre);

        printf("Cantidad de capitulos: ");
        ingresarEntero(&bib[i].cant_capitulos);

        bib[i].paginas_por_capitulo = malloc(bib[i].cant_capitulos * sizeof(int));

        for (int j = 0; j < bib[i].cant_capitulos; j++)
        {
            printf("Ingrese el numero de paginas en el capitulo %d: ", j + 1);
            scanf("%d", &bib[i].paginas_por_capitulo[j]);
            bib[i].cant_paginas += bib[i].paginas_por_capitulo[j];
        }

        printf("Precio: ");
        ingresarFlotante(&bib[i].precio);

        printf("Datos del autor:\n");
        printf("  Nombre del autor: ");
        scanf(" %[^\n]s", bib[i].datos_autor.nombre);
        printf("  Ano de nacimiento del autor: ");
        ingresarEntero(&bib[i].datos_autor.anio_nacimiento);
        printf("\n");
    }
}

void ingresar_cantidad(int *n)
{
    printf("Ingrese el numero de libros:");
    do
    {
        ingresarEntero(n);
        if (n <= 0)
            printf("debe ingresar un numero positivo.  \n");
        else if (*n > TAM)
            printf("debe ingresar un numero menor a %d.  ", TAM);
    } while (n <= 0 || *n > TAM);
}

void ingresarEntero(int *val)
{
    if (scanf(" %d", val) != 1)
    {
        printf("Debe ingresar un numero entero.  ");
        char c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        ingresarEntero(val);
    }
}

void ingresarFlotante(float *val)
{
    if (scanf(" %f", val) != 1)
    {
        printf("Debe ingresar un numero flotante.  ");
        char c;
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        ingresarFlotante(val);
    }
}