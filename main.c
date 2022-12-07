#include "main.h"
#include <stdio.h>

int main() {
  char palabra[NUM_LETRAS_PALABRA];
  t_casilla casillas[NUM_FILAS][NUM_LETRAS_PALABRA];
  char solucion[NUM_LETRAS_PALABRA] = "ARBOL";
  int palabra_correcta = 0;
  int num_intento = 0;

  inicializar_tablero(casillas);
  do {
    imprimir_tablero(casillas, num_intento);
    pedir_palabra(palabra);
    palabra_correcta = poner_palabra(casillas, palabra, num_intento, solucion);
    num_intento++;
    borrar_pantalla();
  } while (partida_acabada(num_intento, palabra_correcta, solucion) == 0);
  imprimir_tablero(casillas, num_intento);
  return 0;
}

void imprimir_tablero(t_casilla matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                      int num_intento) {
  //  Como los caracteres no coinciden con los huecos, se tienen que separar en
  //  x/y, fila/columna El contador sirve para detectar si estamos en una fila
  //  de caracteres o huecos
  int x, y, fila = 0, columna, contador = 0;
  printf("\n");
  //  Hay 13 filas de caracteres (teniendo en cuenta los +-)
  for (x = 0; x < 13; x++) {
    printf("\t\t");
    columna = 0;
    //  Hay 11 columnas de caracteres
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
          imprimir_casilla(matriz[fila][columna]);
          columna++;
        }
      }
    }
    contador++;
    if (contador >= 2) {
      fila++;
      contador = 0;
    }
    printf("\n");
  }
  printf("\n");
}

void inicializar_tablero(t_casilla matriz[NUM_FILAS][NUM_LETRAS_PALABRA]) {
  int i, j;
  for (i = 0; i < NUM_FILAS; i++) {
    for (j = 0; j < NUM_LETRAS_PALABRA; j++) {
      inicializar_casilla(&matriz[i][j]);
    }
  }
}

void pedir_palabra(char palabra[NUM_LETRAS_PALABRA]) {
  int i = 0;
  char enter = 0;
  printf("Introduzca palabra: ");
  do {
    //  Lee todos los valores utiles en palabra y los que sobran en enter (hasta
    //  dar con un \n)
    if (i < NUM_LETRAS_PALABRA) {
      do {
        scanf("%c", &palabra[i]);
      } while (palabra[i] == '\n');
    } else {
      scanf("%c", &enter);
    }
    palabra[i] = capitalizar(palabra[i]);
    i++;
  } while (enter != '\n');
  enter = 0;
}

int poner_palabra(t_casilla matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                  char palabra[NUM_LETRAS_PALABRA], int num_intento,
                  char solucion[NUM_LETRAS_PALABRA]) {
  int i, j, tipo, letras_correctas = 0;
  for (i = 0; i < NUM_LETRAS_PALABRA; i++) {
    tipo = COLOR_LETRA_KO;
    if (palabra[i] == solucion[i]) {
      tipo = COLOR_LETRA_Y_POSICION_OK;
      letras_correctas++;
    } else {
      for (j = 0; j < NUM_LETRAS_PALABRA; j++) {
        if (palabra[i] == solucion[j]) {
          tipo = COLOR_LETRA_OK;
        }
      }
    }
    poner_letra_en_casilla(&matriz[num_intento][i], palabra[i], tipo);
  }
  if (letras_correctas >= 5) {
    return TRUE;
  } else {
    return FALSE;
  }
}

char capitalizar(char letra) {
  //  Si la letra es minúscula la trasforma en mayúscula
  if (letra >= 'a' && letra <= 'z') {
    letra -= 32;
  }
  return letra;
}

int partida_acabada(int num_intento, int palabra_correcta,
                    char solucion[NUM_LETRAS_PALABRA]) {
  if (palabra_correcta) {
    printf("\nGANAR GANAR POLLO PARA CENAR\n");
    return TRUE;
  } else if (num_intento == NUM_FILAS) {
    printf("\nAY POBRESITO AS PERDIDO ;-(\n%s\n", solucion);
    return TRUE;
  }
  return FALSE;
}