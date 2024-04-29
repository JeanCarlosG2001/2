#include <stdio.h>
#include <math.h>

float CalcularVelocidad(float VelocidadInicial, float Aceleracion, float Tiempo, float Distancia);
float CalcularDistancia(float VelocidadInicial, float Aceleracion, float Tiempo, float Distancia);
float CalcularAceleracion(float VelocidadInicial, float VelocidadFinal, float Tiempo, float Distancia, float Aceleracion);

int main() {
    int opcion;
    float VelocidadInicial, VelocidadFinal, Aceleracion, Tiempo, Distancia;

    printf("MRUV\n");
    do {
        printf("Escriba 1 si quiere calcular la Distancia\nEscriba 2 si quiere calcular la Velocidad\nEscriba 3 si quiere calcular la Aceleracion\nEscriba 0 para salir del programa\n");
        scanf("%d", &opcion);
        switch (opcion) {
        case 0:
            printf("Hasta pronto!");
            break;
        case 1:
            Distancia = CalcularDistancia(VelocidadInicial, Aceleracion, Tiempo, Distancia);
            printf("La distancia es %.2f\n", Distancia);
            break;
        case 2:
            VelocidadFinal = CalcularVelocidad(VelocidadInicial, Aceleracion, Tiempo, Distancia);
            printf("La velocidad es %.2f\n", VelocidadFinal);
            break;
        case 3:
            Aceleracion = CalcularAceleracion(VelocidadInicial, VelocidadFinal, Tiempo, Distancia, Aceleracion);
            printf("La aceleracion es %.2f\n", Aceleracion);
            break;
        default:
            printf("Inserte un valor valido\n");
    }
    } while (opcion != 0);
    return 0;
}

float CalcularDistancia(float VelocidadInicial, float Aceleracion, float Tiempo, float Distancia) {
    printf("Escriba la Velocidad Inicial:\n");
    scanf("%f", &VelocidadInicial);
    printf("Escriba la Aceleracion (Si no hay, escriba 0):\n");
    scanf("%f", &Aceleracion);
    printf("Escriba el Tiempo:\n");
    scanf("%f", &Tiempo);

    if (Aceleracion == 0) {
        Distancia = VelocidadInicial * Tiempo;
    } else {
        Distancia = VelocidadInicial * Tiempo + (Aceleracion * pow(Tiempo, 2)) / 2;
    }

    return Distancia;
}

float CalcularVelocidad(float VelocidadInicial, float Aceleracion, float Tiempo, float Distancia) {
    float VelocidadFinal;
    printf("Escriba la Velocidad Inicial:\n");
    scanf("%f", &VelocidadInicial);
    printf("Escriba la Aceleracion:\n");
    scanf("%f", &Aceleracion);
    printf("Escriba el Tiempo (Si no hay, escriba 0):\n");
    scanf("%f", &Tiempo);
    printf("Escriba la Distancia (Si no hay, escriba 0):\n");
    scanf("%f", &Distancia);

    if (Tiempo == 0) {
        VelocidadFinal = sqrt(pow(VelocidadInicial, 2) + (2 * Aceleracion * Distancia));
    } else {
        VelocidadFinal = VelocidadInicial + (Aceleracion * Tiempo);
    }

    return VelocidadFinal;
}

float CalcularAceleracion(float VelocidadInicial, float VelocidadFinal, float Tiempo, float Distancia, float Aceleracion) {
    printf("Escriba la Velocidad Inicial:\n");
    scanf("%f", &VelocidadInicial);
    printf("Escriba la Velocidad Final:\n");
    scanf("%f", &VelocidadFinal);
    printf("Escriba el Tiempo (Si no hay, escriba 0):\n");
    scanf("%f", &Tiempo);
    printf("Escriba la Distancia (Si no hay, escriba 0):\n");
    scanf("%f", &Distancia);

    if (Tiempo == 0) {
        Aceleracion = (pow(VelocidadFinal, 2) - pow(VelocidadInicial, 2)) / (2 * Distancia);
    } else if (VelocidadFinal == 0) {
        Aceleracion = (2 * (Distancia - (VelocidadInicial * Tiempo))) / pow(Tiempo, 2);
    } else {
        Aceleracion = (VelocidadFinal - VelocidadInicial) / Tiempo;
    }

    return Aceleracion;
}