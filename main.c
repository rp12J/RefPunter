#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;

    do {
        printf("\n--- Cevichería El Palenque ---\n");
        printf("1. Ver productos\n");
        printf("2. Ingreso de producto\n");
        printf("3. Modificación de producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Salir\n");
        fflush(stdin);

        printf("\nEscoja una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                verProductos();
                break;
            case 2:
                ingresarProducto();
                break;
            case 3:
                modificarProducto();
                break;
            case 4:
                eliminarProducto();
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