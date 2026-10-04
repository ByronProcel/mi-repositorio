#include <stdio.h>
#include <string.h>
 
    char producto[40] = "";
    float precio = 0;
    int stock;
    int opc_temp = 0;
    int in_entero;
    int id;
    float ganancias = 0;
    float total_vendido = 0;
 
 
 
int mostrarMenu(void) {
    int opcion;
    printf("\n");
    printf("=== MENU PRINCIPAL ===\n");
    printf("1. Registrar\n");
    printf("2. Vender\n");
    printf("3. Comprar\n");
    printf("4. Visualizar\n");
    printf("5. Cerrar el programa\n");
 
    if (scanf("%d", &opcion) != 1) {
        while (getchar() != '\n');
        return 0;
    }
 
    return opcion;
}
 
int main(void) {
    char string_temp[40] = "";
    opc_temp = mostrarMenu();
    do
    {
        switch (opc_temp) {
            case 1:
                printf("=====REGISTRO DE PRODUCTO=====\n");
                // aplicar lo necesario para Registrar
               
                // comparar si el producto ya está registrado
                if( strlen(producto) == 0){
                    printf("El producto aun no esta registrado.\nIndique el nombre del producto: \n");
                    getchar();
                    fgets(producto, sizeof(producto), stdin);
                    producto[strcspn(producto, "\n")] = 0;
 
                    printf("Ingrese el ID del producto: \n");
                    scanf("%d", &id);
 
                    printf("Indique el precio del producto: \n");
                    scanf("%f", &precio);
 
                    printf("Indique la cantidad del producto: \n");
                    scanf("%d", &stock);
 
                }else{
                    printf("Usted ya registró el producto!. \n");
                }
 
                // si está registrado -> Ya se encuentra regisrado el producto : Asignar valor a producto
                break;
            case 2:
                printf("=====VENTA DE PRODUCTO=====\n");
                printf("Que cantidad deseas vender.\n");
                scanf("%d", &in_entero);
                if (in_entero <= 0) {
                    printf("ADVERTENCIA: CANTIDAD NEGATIVA NO ADMITIDA. SOLO INGRESAR VALORES POSITIVOS. \n");
                } else if (stock < in_entero) {
                    printf("ADVERTENCIA: STOCK INSUFICIENTE.\n");
                } else {
                    float descuento = 0;
                    float precio_final = precio;

                    printf("Ingrese el porcentaje de descuento (0 - 100): \n");
                    scanf("%f", &descuento);

                    if (descuento < 0 || descuento > 100) {
                        printf("ADVERTENCIA: DESCUENTO NO VALIDO. SE APLICARA DESCUENTO DE 0%%.\n");
                        descuento = 0;
                    }

                    precio_final = precio - (precio * (descuento / 100.0));

                    stock = stock - in_entero;
                    total_vendido = precio_final * in_entero;
                    ganancias = ganancias + total_vendido;

                    printf("Total vendido (con %.2f%% de descuento): %.2f\n", descuento, total_vendido);
                    printf("Productos en stock = %d\n", stock);
                }
                break;
            case 3:
                printf("=====REABASTECIMIENTO DE PRODUCTO=====\n");
                printf("Que cantidad deseas comprar.\n");
                scanf("%d", &in_entero);

                if (in_entero <= 0) {
                    printf("ADVERTENCIA: CANTIDAD NEGATIVA NO ADMITIDA. SOLO INGRESAR VALORES POSITIVOS. \n");
                } else {
                    stock = stock + in_entero;
                    printf("Productos en stock = %d\n", stock);
                }
                break;
            case 4:
                printf("=====DATOS DEL PRODUCTO=====\n");
                printf("%s\t\t\t%s\t\t\t%s\n", "NOMBRE", "PRECIO", "STOCK");
                printf("%s\t\t\t%.2f\t\t\t%d\n", producto, precio, stock);
                printf("Total recaudado: %.2f", ganancias);
               
                break;
            case 5:
                printf("Elegiste la opción 5: Salir.\n");
                // aplicar lo necesario para Mostrar
                break;
            default:
                printf("Opción no válida. Elige un número del 1 al 5.\n");
        }
        opc_temp = mostrarMenu(); //muestra una nueva accion sobre el menú
    } while (opc_temp != 5);
    return 0;
    //prueba de commit 2
}