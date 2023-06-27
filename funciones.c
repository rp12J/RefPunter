#include <stdio.h>
#include "funciones.h"

Comida productos[25];  

int cantidadPlatos = 0;

void verProductos() {
    if (cantidadPlatos == 0) {
        printf("No hay productos ingresados.\n");
        return;
    }

    printf("\n--- Productos ---\n");
    printf("ID\tNombre\t\tDescripción\tCantidad\tPrecio\n");

    for (int i = 0; i < cantidadPlatos; i++) {
        Comida *p = &productos[i];
        printf("%d\t%s\t\t%s\t%d\t\t%.2f\n", p->ID, p->nombre, p->descripcion, p->cantidad, p->precio);
    }
}

void ingresarProducto() {
    if (cantidadPlatos == 25) {
        printf("No se pueden ingresar más productos.\n");
        return;
    }

    Comida *p = &productos[cantidadPlatos];

    printf("\n--- Ingreso de Producto ---\n");

    printf("ID: ");
    scanf("%d", &(p->ID));

    printf("Nombre: ");
    scanf("%s", p->nombre);

    printf("Descripción: ");
    scanf("%s", p->descripcion);

    printf("Cantidad: ");
    scanf("%d", &(p->cantidad));

    printf("Precio: ");
    scanf("%f", &(p->precio));

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
        Comida *p = &productos[i];
        if (p->ID == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("No se encontró el producto con ID %d\n", id);
        return;
    }

    Comida *p = &productos[indice];

    printf("Nombre (actual: %s): ", p->nombre);
    scanf("%s", p->nombre);

    printf("Descripción (actual: %s): ", p->descripcion);
    scanf("%s", p->descripcion);

    printf("Cantidad (actual: %d): ", p->cantidad);
    scanf("%d", &(p->cantidad));

    printf("Precio (actual: %.2f): ", p->precio);
    scanf("%f", &(p->precio));

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
        Comida *p = &productos[i];
        if (p->ID == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("No se encontró el producto con ID %d\n", id);
        return;
    }

    for (int i = indice; i < cantidadPlatos - 1; i++) {
        productos[i] = productos[i + 1];
    }

    cantidadPlatos--;

    printf("Producto eliminado correctamente.\n");
}
