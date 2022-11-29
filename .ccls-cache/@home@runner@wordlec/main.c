#include "casilla.h"
#include "colores.h"
#include "palabras.h"
#include <stdio.h>
#define NUM_LETRAS_PALABRA 5
#define NUM_FILAS 6

void imprimir_tablero(char matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                      int num_intento);
void inicializar_tablero(char matriz[NUM_FILAS][NUM_LETRAS_PALABRA]);
void pedir_palabra(char palabra[NUM_LETRAS_PALABRA]);
void poner_palabra(char matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                   char palabra[NUM_LETRAS_PALABRA], int num_intento);

int main() {
  char palabra[NUM_LETRAS_PALABRA];
  // t_casilla casillas[NUM_FILAS][NUM_LETRAS_PALABRA];
  char casillas[NUM_FILAS][NUM_LETRAS_PALABRA];
  int num_intento = 0;

  inicializar_tablero(casillas);
  do {
    imprimir_tablero(casillas, num_intento);
    pedir_palabra(palabra);
    poner_palabra(casillas, palabra, num_intento);
    num_intento++;
    borrar_pantalla();
  } while (num_intento < NUM_FILAS);
  imprimir_tablero(casillas, num_intento);
  return 0;
}

void imprimir_tablero(char matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                      int num_intento) {
  int x, y, fila = 0, columna = 0, counter = 0;
  printf("\n");
  for (x = 0; x < 13; x++) {
    printf("\t\t");
    columna = 0;
    for (y = 0; y < 11; y++) {
      if (x % 2 == 0) {
        if (y % 2 == 0) {
          printf("+");
        } else {
          printf("-");
        }
      } else {
        if (y % 2 == 0) {
          printf("|");
        } else {
          printf("%c", matriz[fila][columna]);
          columna++;
        }
      }
    }
    counter++;
    if (counter >= 2) {
      fila++;
      counter = 0;
    }
    printf("\n");
  }
  printf("\n");
}

void inicializar_tablero(char matriz[NUM_FILAS][NUM_LETRAS_PALABRA]) {
  int i, j;
  for (i = 0; i < NUM_FILAS; i++) {
    for (j = 0; j < NUM_LETRAS_PALABRA; j++) {
      matriz[i][j] = ' ';
    }
  }
}

void pedir_palabra(char palabra[NUM_LETRAS_PALABRA]) {
  int i;
  printf("Introduzca palabra: ");
  for (i = 0; i < NUM_LETRAS_PALABRA; i++) {
    scanf("%c", &palabra[i]);
  }
  scanf("%*c");
}

void poner_palabra(char matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                   char palabra[NUM_LETRAS_PALABRA], int num_intento) {
  int i;
  for (i = 0; i < NUM_LETRAS_PALABRA; i++) {
    matriz[num_intento][i] = palabra[i];
  }
}