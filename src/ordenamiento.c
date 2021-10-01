#include <stdio.h>

#include "hospital.h"
#include "ordenamiento.h"


void merge_pokemon_array(pokemon_t** p, size_t min, size_t mid, size_t max){
	//index_1 es el indice del 1er subarray, index_2 del 2do, index_merged del resultante del merge
	size_t index_1, index_2, index_merged;
	size_t tamano_temporal_1 = mid - min + 1;
	size_t tamano_temporal_2 = max - mid;

	pokemon_t vector_temporal_1[tamano_temporal_1];
	pokemon_t vector_temporal_2[tamano_temporal_2];

	//copio datos a vectores temporales

	for(index_1 = 0; index_1 < tamano_temporal_1; index_1++)
		vector_temporal_1 = p[min + index_1];
	for(index_2 = 0; index_2 < tamano_temporal_2; index_2++)
		vector_temporal_2 = p[mid + 1 + index_2];

	index_1 = 0;
	index_2 = 0;
	index_merged = min;

	while(index_1 < tamano_temporal_1 && index_2 < tamano_temporal_2){
		if((vector_temporal_1[index_1].name)[0]  )
	}
	




}

void ordenar_pokemon_alfabetico(pokemon_t* p, size_t min, size_t max){
	if(!p) return NULL;

	size_t mid = (max - min) / 2;

	ordenar_pokemon_alfabetico(p, min, mid);
	ordenar_pokemon_alfabetico(p, mid+1, max);



}