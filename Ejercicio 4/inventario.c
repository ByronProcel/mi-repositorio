#include <stdio.h>
#include <string.h>
#include "inventario.h"

float calcularTotal(float precios[], int cantidad)
{
    // 1. Crear acumulador
    float total = 0.0f;
    int i;
    // 2. Recorrer los precios con un for
    for (i = 0; i < cantidad; i++) {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[], int cantidad)
{
    if (cantidad <= 0)
    {
        return 0.0f;
    }
    float total = calcularTotal(precios, cantidad);

    return total/cantidad;
}

int obtenerIndiceMasCaro(float precios[], int cantidad)
{
    int indice_max = 0;
    int i;
    if (cantidad <= 0) {
            return -1;
        }
    for (i = 1; i < cantidad; i++)
    {
        if (precios[i] > precios[indice_max])
        {
            indice_max = i;
        }
    }
    return indice_max;
}

int obtenerIndiceMasBarato(float precios[], int cantidad)
{
    int indice_min = 0;
    int i;
    if (cantidad <= 0) {
            return -1;
        }
    for (i = 1; i < cantidad; i++)
    {
        if (precios[i] < precios[indice_min])
        {
            indice_min = i;
        }
    }
    return indice_min;
}

int ingresarProductos(char nombres[][LARGO_NOMBRE], float precios[])
{
    int cantidad = 0;
    int i;
    do
    {
        printf("\nIngrese la cantidad: ");
        scanf("%d", &cantidad);
        while(getchar() != '\n');

        if(cantidad < 1 || cantidad > PRODUCTOS_MAX)
        {
            printf("\nCantidad invalida. Ingrese un numero entre 1 y %d: ", PRODUCTOS_MAX);
        }
    } while (cantidad < 1 || cantidad > PRODUCTOS_MAX);
    for (i = 0; i < cantidad; i++)
    {
        printf("\nIngrese el nombre del producto: ");
        scanf("%30s", nombres[i]);
        while(getchar() != '\n');
        
        printf("\nIngrese el precio del producto: ");
        scanf("%f", &precios[i]);
        while(getchar() != '\n');
    }
    return cantidad;
}

int buscarProductoPorNombre(char nombres[][LARGO_NOMBRE], int cantidad, char nombreBuscado[])
{
    int i;
    if (cantidad <= 0) {
        return -1;
    }
    for (i = 0; i < cantidad; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            return i;
        }
    }
    return -1;
}