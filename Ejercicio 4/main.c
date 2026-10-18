#include <stdio.h>
#include "inventario.h"

int main(void) {
    float precios[PRODUCTOS_MAX];
    char nombres[PRODUCTOS_MAX][LARGO_NOMBRE];
    int cantidad = 0;

    float total;
    float promedio;
    int indice_caro;
    int indice_barato;

    char nombreABuscar[LARGO_NOMBRE];
    int posicion_buscada;

    printf("=====Registro de Productos=====\n");
    cantidad = ingresarProductos(nombres, precios);

    total = calcularTotal(precios, cantidad);
    promedio = calcularPromedio(precios, cantidad);
    indice_caro = obtenerIndiceMasCaro(precios, cantidad);
    indice_barato = obtenerIndiceMasBarato(precios, cantidad);

    printf("=====Resultados=====\n");
    printf("Total del inventario: $%.2f\n", total);
    printf("Promedio de precios: $%.2f\n", promedio);

    printf("Producto mas caro: %s ($%.2f)\n", nombres[indice_caro], precios[indice_caro]);
    printf("Producto mas barato: %s ($%.2f)\n", nombres[indice_barato], precios[indice_barato]);

    printf("=====Busqueda=====\n");
    printf("Ingrese el nombre del producto a buscar: ");
    scanf("%30s", nombreABuscar);

    posicion_buscada = buscarProductoPorNombre(nombres, cantidad, nombreABuscar);

    if (posicion_buscada == -1) {
        printf("El producto no se encuentra dentro del inventario.\n");
    } else {
        printf("El producto fue encontrado. El precio es: $%.2f\n", precios[posicion_buscada]);
    }
    printf("\nPresione enter para salir.....");
    while(getchar() != '\n');
    getchar();
    return 0;
}