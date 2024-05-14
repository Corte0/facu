#include<stdio.h>

typedef struct 
{
    unsigned long long int id ;
    float precio;
    char nombre[150];
}producto_t;


typedef struct 
{
    producto_t barato;
    producto_t caro;
}estadistica_t;


void inicializar_producto(producto_t*p);
void imprimir_producto (producto_t *p);
void imprimir_producto_en_archivo (producto_t *p,FILE *dst);


int main(){

    FILE* datos_parseados;
    FILE* datos_estadisticos;

    datos_parseados = fopen("datos_parseados.csv", "r");
    datos_estadisticos = fopen("datos_estadisticos.txt", "w");

    if(datos_estadisticos == NULL || datos_parseados == NULL){
        printf("Error al abrir el archivo de datos estadisticos\n");
    } else {
        printf("Archivo de datos estadisticos abierto correctamente\n");

        estadistica_t estadistica;
        producto_t aux;

        inicializar_producto(&estadistica.barato);
        inicializar_producto(&estadistica.caro);
        inicializar_producto(&aux);

        char string [250];

        estadistica.barato.precio = 100000;

        while (!feof(datos_parseados)){
            fgets(string,sizeof(string),datos_parseados);
            sscanf(string,"%lld,%f,%[^/]s",&aux.id,&aux.precio,aux.nombre);
            //imprimir_producto(&aux);
            if (aux.precio < estadistica.barato.precio){
                estadistica.barato = aux;
            }else if (aux.precio > estadistica.caro.precio){
                estadistica.caro = aux;
            }
        }

        printf("\nProducto mas barato: \n");
        imprimir_producto(&estadistica.barato);
        printf("\nProducto mas caro: \n");
        imprimir_producto(&estadistica.caro);

        fprintf(datos_estadisticos,"Producto mas barato: \n");
        imprimir_producto_en_archivo(&estadistica.barato,datos_estadisticos);
        fprintf(datos_estadisticos,"\nProducto mas caro: \n");
        imprimir_producto_en_archivo(&estadistica.caro,datos_estadisticos);  

        fclose(datos_parseados);
        fclose(datos_estadisticos);
    }
}

void imprimir_producto (producto_t *p){
    printf("ID: %lld\n",p->id);
    printf("Precio: %.2f\n",p->precio);
    printf("Nombre: %s",p->nombre);
}

void imprimir_producto_en_archivo (producto_t *p,FILE *dst){
    fprintf(dst,"ID: %lld\n",p->id);
    fprintf(dst,"Precio: %.2f\n",p->precio);
    fprintf(dst,"Nombre: %s",p->nombre);
}

void inicializar_producto(producto_t*p){
    p->id = 0;
    p->precio = 0;
}