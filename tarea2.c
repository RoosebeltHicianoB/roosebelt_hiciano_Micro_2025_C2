#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

// Simulaciones de funciones MQTT y hardware
void mqtt_publicar(const char* topico, const char* mensaje) {
    printf("[MQTT] %s: %s\n", topico, mensaje);
}

void buzzer_activar() {
    printf("Buzzer activado\n");
}

void lampara_encender() {
    printf("Lámpara encendida\n");
}

void lampara_apagar() {
    printf("Lámpara apagada\n");
}

void lampara_parpadear(int tiempo_ms) {
    printf("Lámpara parpadeando cada %d ms\n", tiempo_ms);
}

void mostrar_error(const char* mensaje) {
    printf("Error: %s\n", mensaje);
    mqtt_publicar("puerta/error", mensaje);
}

// Estados de la puerta
typedef enum {
    CERRADA,
    ABIERTA,
    DESCONOCIDA,
    ABRIENDO,
    CERRANDO
} EstadoPuerta;

EstadoPuerta estado_actual = DESCONOCIDA;

void enviar_estado_mqtt(const char* estado) {
    mqtt_publicar("puerta/estado", estado);
}

void finalizar_apertura() {
    estado_actual = ABIERTA;
    enviar_estado_mqtt("abierta");
    lampara_encender();
}

void finalizar_cierre() {
    estado_actual = CERRADA;
    enviar_estado_mqtt("cerrada");
    lampara_apagar();
}

void abrir_puerta() {
    estado_actual = ABRIENDO;
    enviar_estado_mqtt("abriendo");
    buzzer_activar();
    lampara_parpadear(500);
    sleep(3);
    finalizar_apertura();
}

void cerrar_puerta() {
    estado_actual = CERRANDO;
    enviar_estado_mqtt("cerrando");
    buzzer_activar();
    lampara_parpadear(250);
    sleep(3);
    finalizar_cierre();
}

void presionar_boton_pp() {
    switch (estado_actual) {
        case CERRADA:
            abrir_puerta();
            break;
        case ABIERTA:
        case DESCONOCIDA:
            cerrar_puerta();
            break;
        default:
            mostrar_error("Estado inválido para PP");
            break;
    }
}

int main() {
    char entrada;
    while (1) {
        printf("Presiona 'P' para botón PP: ");
        scanf(" %c", &entrada);
        if (entrada == 'P' || entrada == 'p') {
            presionar_boton_pp();
        }
    }
    return 0;
}
