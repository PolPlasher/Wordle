#ifndef CASILLA_H
#define CASILLA_H

//  Dos valores para almacenar la letra y el color de cada casilla
typedef struct {
  char letra;
  int color;
} t_casilla;

//  Asigna un espacio a la casilla del argumento
void inicializar_casilla(t_casilla *casilla);

//  Asigna una letra y un color a una casilla 
void poner_letra_en_casilla(t_casilla *casilla, char letra, int color);

//  Imprime la casilla seleccionada en el argumento
void imprimir_casilla(t_casilla casilla);

#endif