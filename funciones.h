#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
    int ID;
    char nombre[50];
    char descripcion[100];
    int cantidad;
    float precio;
} Comida;

void verProductos();
void ingresarProducto();
void modificarProducto();
void eliminarProducto();

#endif  