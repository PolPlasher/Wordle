//  Si MAIN_H no esta definido
#ifndef MAIN_H

//  Automáticamente se define MAIN_H
#define MAIN_H

//  Y se crea el siguiente codigo:

//  Se incluyen todas las librerias necesarias en main.c
#include "casilla.h"
#include "colores.h"
#include "palabras.h"

//  Se definen todas las constantes necesarias en main.c
#define NUM_LETRAS_PALABRA 5
#define NUM_FILAS 6

//  Se declaran todas las funciones necesarias en main.c

//  Imprime el tablero
void imprimir_tablero(t_casilla matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                      int num_intento);

//  Inicializa el tablero con el char ' ' en cada hueco
void inicializar_tablero(t_casilla matriz[NUM_FILAS][NUM_LETRAS_PALABRA]);

//  Pide una palabra i la almacena
void pedir_palabra(char palabra[NUM_LETRAS_PALABRA]);

//  Pone la palabra en la matriz
int poner_palabra(t_casilla matriz[NUM_FILAS][NUM_LETRAS_PALABRA],
                  char palabra[NUM_LETRAS_PALABRA], int num_intento,
                  char solucion[NUM_LETRAS_PALABRA]);

//  Capitaliza el input de pedir_palabra() si es necesario
char capitalizar(char letra);

//  Comprueba si la partida se ha acabado o no
int partida_acabada(int num_intento, int palabra_correcta,
                    char solucion[NUM_LETRAS_PALABRA]);

//  Se rompe la condición de la linea 2
#endif