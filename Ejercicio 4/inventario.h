#ifndef INVENTARIO_H
#define INVENTARIO_H

#define PRODUCTOS_MAX 10
#define LARGO_NOMBRE 31

float calcularTotal(float precios[], int cantidad);

float calcularPromedio(float precios[], int cantidad);

int obtenerIndiceMasCaro(float precios[], int cantidad);

int obtenerIndiceMasBarato(float precios[], int cantidad);

int ingresarProductos(char nombres[][LARGO_NOMBRE], float precios[]);

int buscarProductoPorNombre(char nombres[][LARGO_NOMBRE], int cantidad, char nombreBuscado[]);

#endif