#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 25

int cantidadPlatos = 0;
int ID[MAX_PRODUCTOS];
char nombre[MAX_PRODUCTOS][50];
char descripcion[MAX_PRODUCTOS][100];
int cantidad[MAX_PRODUCTOS];
float precio[MAX_PRODUCTOS];

void menuInicial(int *opcion) {
    printf("1) Ver productos\n");
    printf("2) Ingreso producto\n");
    printf("3) Modificar producto\n");
    printf("4) Eliminar producto\n");
    printf("5) Salir\n");
    printf("Digite una opción: ");
    scanf("%d", opcion);
}

void verProductos() {
    if (cantidadPlatos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    printf("\n--- Productos ---\n");
    printf("ID\tNombre\t\tDescripción\tCantidad\tPrecio\n");

    for (int i = 0; i < cantidadPlatos; i++) {
        printf("%d\t%s\t\t%s\t%d\t\t%.2f\n", ID[i], nombre[i], descripcion[i], cantidad[i], precio[i]);
    }
}

void ingresarProducto() {
    if (cantidadPlatos == MAX_PRODUCTOS) {
        printf("No se pueden ingresar más productos.\n");
        return;
    }

    printf("\n--- Ingreso de Producto ---\n");

    printf("ID: ");
    scanf("%d", &ID[cantidadPlatos]);

    printf("Nombre: ");
    scanf("%s", nombre[cantidadPlatos]);

    printf("Descripción: ");
    scanf("%s", descripcion[cantidadPlatos]);

    printf("Cantidad: ");
    scanf("%d", &cantidad[cantidadPlatos]);

    printf("Precio: ");
    scanf("%f", &precio[cantidadPlatos]);

    cantidadPlatos++;

    printf("Producto ingresado correctamente.\n");
}

void modificarProducto() {
    if (cantidadPlatos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    int id;
    int indice = -1;

    printf("\n--- Modificación de Producto ---\n");
    printf("Ingrese el ID del producto a modificar: ");
    scanf("%d", &id);

    for (int i = 0; i < cantidadPlatos; i++) {
        if (ID[i] == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("No se encontró el producto con ID %d\n", id);
        return;
    }

    printf("Nombre (actual: %s): ", nombre[indice]);
    scanf("%s", nombre[indice]);

    printf("Descripción (actual: %s): ", descripcion[indice]);
    scanf("%s", descripcion[indice]);

    printf("Cantidad (actual: %d): ", cantidad[indice]);
    scanf("%d", &cantidad[indice]);

    printf("Precio (actual: %.2f): ", precio[indice]);
    scanf("%f", &precio[indice]);

    printf("Producto modificado correctamente.\n");
}

void eliminarProducto() {
    if (cantidadPlatos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    int id;
    int indice = -1;

    printf("\n--- Eliminación de Producto ---\n");
    printf("Ingrese el ID del producto a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < cantidadPlatos; i++) {
        if (ID[i] == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("No se encontró el producto con ID %d\n", id);
        return;
    }

    for (int i = indice; i < cantidadPlatos - 1; i++) {
        ID[i] = ID[i + 1];
        strcpy(nombre[i], nombre[i + 1]);
        strcpy(descripcion[i], descripcion[i + 1]);
        cantidad[i] = cantidad[i + 1];
        precio[i] = precio[i + 1];
    }

    cantidadPlatos--;

    printf("Producto eliminado correctamente.\n");
}
