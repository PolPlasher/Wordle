#include "colores.h"
#include "palabras.h"
#include <stdio.h>
#define TIPO_VACIA 0
#define TIPO_LETRA_Y_POSICION 1
#define TIPO_LETRA_OK 2
#define TIPO_LETRA_KO 3

typedef struct {
  char letra;
  int color;
} t_casilla;

void inicializar_casilla(t_casilla *casilla);
void poner_letra_en_casilla(t_casilla *casilla, char letra, int color);
void imprimir_casilla(t_casilla casilla);

void inicializar_casilla(t_casilla *casilla) {
  casilla->letra = ' ';
  casilla->color = TIPO_VACIA;
}

void poner_letra_en_casilla(t_casilla *casilla, char letra, int color) {
  casilla->letra = letra;
  casilla->color = color;
}

void imprimir_casilla(t_casilla casilla) {
  switch (casilla.color) {
  case TIPO_LETRA_Y_POSICION:
    printf_color(COLOR_LETRA_OK);
    break;
  case TIPO_LETRA_OK:
    printf_color(COLOR_LETRA_OK);
    break;
  case TIPO_LETRA_KO:
    printf_color(COLOR_LETRA_KO);
    break;
  default:
    break;
  }
  printf("%c", casilla.letra);
  printf_color(0);
}