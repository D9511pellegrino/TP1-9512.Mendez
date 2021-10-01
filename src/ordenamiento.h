#ifndef ORDENAMIENTO_H_
#define ORDENAMIENTO_H_

#include "hospital.h"

#include <stdbool.h>
#include <stdlib.h>

/* La función recibe un vector de pokemones y su posicion minima y maxima. Los ordena mediante merge alfabeticamente de la a a la z.
Devuelve el vector ordenado, en caso de falla devuelve NULL.*/
void ordenar_pokemon_alfabetico(pokemon_t** p, size_t min, size_t max);

#endif // ORDENAMIENTO_H_