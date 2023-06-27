#include <stdio.h>
#include "funciones.h"

int main() {

    int opcion;

    do {
        menuInicial(&opcion);

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