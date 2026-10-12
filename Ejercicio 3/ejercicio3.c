#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3
#define NOTA_MINIMA 0
#define NOTA_MAXIMA 10
#define NOTA_APROBATORIA 6

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    int i, j;

    printf("Registro de calificaciones\n\n");

    for (i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d\n", i + 1);

        for (j = 0; j < ASIGNATURAS; j++) {
            float nota;

            do {
                printf("  Nota %d: ", j + 1);
                scanf("%f", &nota);

                if (nota < NOTA_MINIMA || nota > NOTA_MAXIMA) {
                    printf("  Debe ingresar un valor entre %d y %d\n",
                           NOTA_MINIMA, NOTA_MAXIMA);
                }
            } while (nota < NOTA_MINIMA || nota > NOTA_MAXIMA);

            calificaciones[i][j] = nota;
        }

        printf("\n");
    }

    printf("Resultados por estudiante\n\n");

    for (i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        float maximo = calificaciones[i][0];
        float minimo = calificaciones[i][0];

        for (j = 0; j < ASIGNATURAS; j++) {
            suma = suma + calificaciones[i][j];

            if (calificaciones[i][j] > maximo) {
                maximo = calificaciones[i][j];
            }

            if (calificaciones[i][j] < minimo) {
                minimo = calificaciones[i][j];
            }
        }

        float promedio = suma / ASIGNATURAS;

        printf("Estudiante %d\n", i + 1);
        printf("  Promedio: %.2f\n", promedio);
        printf("  Mejor nota: %.2f\n", maximo);
        printf("  Peor nota: %.2f\n\n", minimo);
    }

    printf("Resultados por asignatura\n\n");

    for (j = 0; j < ASIGNATURAS; j++) {
        float suma = 0;
        float maximo = calificaciones[0][j];
        float minimo = calificaciones[0][j];
        int aprobados = 0;

        for (i = 0; i < ESTUDIANTES; i++) {
            suma = suma + calificaciones[i][j];

            if (calificaciones[i][j] > maximo) {
                maximo = calificaciones[i][j];
            }

            if (calificaciones[i][j] < minimo) {
                minimo = calificaciones[i][j];
            }

            if (calificaciones[i][j] >= NOTA_APROBATORIA) {
                aprobados++;
            }
        }

        float promedio = suma / ESTUDIANTES;
        int reprobados = ESTUDIANTES - aprobados;

        printf("Asignatura %d\n", j + 1);
        printf("  Promedio: %.2f\n", promedio);
        printf("  Mejor nota: %.2f\n", maximo);
        printf("  Peor nota: %.2f\n", minimo);
        printf("  Aprobados: %d\n", aprobados);
        printf("  Reprobados: %d\n\n", reprobados);
    }

    printf("presione enter para salir...\n");
    getchar();
    getchar();
    return 0;
}