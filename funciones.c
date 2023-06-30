#include <stdio.h>
#include <string.h>
#include "funciones.h"

#define MAX_PRODUCTOS 25

void menuInicial(int *opcion) {
    printf("Cevicheria El Palenque\n");
    printf("1) Ver productos\n");
    printf("2) Ingreso producto\n");
    printf("3) Modificar producto\n");
    printf("4) Eliminar producto\n");
    printf("5) Salir\n");
    printf("Digite una opción: ");
    scanf("%d", opcion);
}

void verProductos(char ID[][25], char nombre[][50], char descripcion[][100], int *cantidad, float *precio, int cantidadPlatos) {
    if (cantidadPlatos == 0) {
        printf("No hay comida ingresada.\n");
        return;
    }

    printf("\n--- Carta ---\n");
    printf("ID      Nombre              Descripción                     Cantidad        Precio\n");

    for (int i = 0; i < cantidadPlatos; i++) {
        printf("%s      %s              %s                     %d        %.2f\n", ID[i], nombre[i], descripcion[i], cantidad[i], precio[i]);
    }
}

void ingresarProducto(char ID[][25], char nombre[][50], char descripcion[][100], int *cantidad, float *precio, int *cantidadPlatos) {
    if (*cantidadPlatos >= MAX_PRODUCTOS) {
        printf("No se puede registrar más comida.\n");
        return;
    }

    printf("\n--- Ingresar carta ---\n");

    printf("ID: ");
    scanf("%s", ID[*cantidadPlatos]);

    printf("Nombre: ");
    scanf("%s", nombre[*cantidadPlatos]);

    printf("Descripción: ");
    scanf("%s", descripcion[*cantidadPlatos]);

    printf("Cantidad: ");
    scanf("%d", &cantidad[*cantidadPlatos]);

    printf("Precio: ");
    scanf("%f", &precio[*cantidadPlatos]);

    (*cantidadPlatos)++;

    printf("Plato ingresado satisfactoriamente.\n");
}

void modificarProducto(char ID[][25], char nombre[][50], char descripcion[][100], int *cantidad, float *precio, int cantidadPlatos) {
    if (cantidadPlatos == 0) {
        printf("No hay comida ingresada.\n");
        return;
    }

    char id[25];
    int indice = -1;

    printf("\n--- Modificación de carta ---\n");
    printf("Ingrese el ID del plato: ");
    scanf("%s", id);

    for (int i = 0; i < cantidadPlatos; i++) {
        if (strcmp(ID[i], id) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("No se encontró el plato con el ID %s\n", id);
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

    printf("Carta modificada satisfactoriamente.\n");
}


void eliminarProducto(char ID[][25], char nombre[][50], char descripcion[][100], int *cantidad, float *precio, int *cantidadPlatos) {
    if (*cantidadPlatos == 0) {
        printf("No hay comida ingresada.\n");
        return;
    }

    char id[25];
    int indice = -1;

    printf("\n--- Eliminación en la carta ---\n");
    printf("Ingrese el ID del plato a eliminar: ");
    scanf("%s", id);

    for (int i = 0; i < *cantidadPlatos; i++) {
        if (strcmp(ID[i], id) == 0) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("No se encontró el plato con el ID %s\n", id);
        return;
    }

    for (int i = indice; i < *cantidadPlatos - 1; i++) {
        strcpy(ID[i], ID[i + 1]);
        strcpy(nombre[i], nombre[i + 1]);
        strcpy(descripcion[i], descripcion[i + 1]);
        cantidad[i] = cantidad[i + 1];
        precio[i] = precio[i + 1];
    }

    (*cantidadPlatos)--;

    printf("Plato eliminado satisfactoriamente.\n");
}
