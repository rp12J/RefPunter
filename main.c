#include <stdio.h>
#include "funciones.h"

#define MAX_PRODUCTOS 25

int main() {

    int cantidadPlatos = 0;
    char ID[MAX_PRODUCTOS][25];
    char nombre[MAX_PRODUCTOS][50];
    char descripcion[MAX_PRODUCTOS][100];
    int cantidad[MAX_PRODUCTOS];
    float precio[MAX_PRODUCTOS];

    int opcion;

    do {
        menuInicial(&opcion);

        switch (opcion) {
            case 1:
                verProductos(ID, nombre, descripcion, cantidad, precio, cantidadPlatos);
                break;
            case 2:
                ingresarProducto(ID, nombre, descripcion, cantidad, precio, &cantidadPlatos);
                break;
            case 3:
                modificarProducto(ID, nombre, descripcion, cantidad, precio, cantidadPlatos);
                break;
            case 4:
                eliminarProducto(ID, nombre, descripcion, cantidad, precio, &cantidadPlatos);
                break;
            case 5:
                printf("Te esperamos pronto\n");
                break;
            default:
                printf("Vuelva a intentarlo\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}