#include "casilla.h"
#include "colores.h"
#include "palabras.h"
#include <stdio.h>

void inicializar_casilla(t_casilla *casilla) {
  casilla->letra = ' ';
  casilla->color = COLOR_DEFAULT;
}

void poner_letra_en_casilla(t_casilla *casilla, char letra, int color) {
  casilla->letra = letra;
  casilla->color = color;
}

void imprimir_casilla(t_casilla casilla) {
  switch (casilla.color) {
  case COLOR_DEFAULT:
    printf_color(COLOR_DEFAULT);
    break;
  case COLOR_LETRA_Y_POSICION_OK:
    printf_color(COLOR_LETRA_Y_POSICION_OK);
    break;
  case COLOR_LETRA_OK:
    printf_color(COLOR_LETRA_OK);
    break;
  case COLOR_LETRA_KO:
    printf_color(COLOR_LETRA_KO);
    break;
  default:
    break;
  }
  printf("%c", casilla.letra);
  printf_color(COLOR_DEFAULT);
}