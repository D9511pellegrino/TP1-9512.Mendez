#include "hospital.h"
#include "split.h"
#include "ordenamiento.h"

#include <stdio.h>

struct _hospital_pkm_t{
    size_t cantidad_entrenador;
    size_t cantidad_pokemon;
    pokemon_t* vector_pokemones;
};

struct _pkm_t{
    char* nombre;
    size_t nivel;
};

hospital_t* hospital_crear(){
    hospital_t* hospital_nuevo = calloc(1, sizeof(hospital_t));
    if(!hospital_nuevo) return NULL;
    
    hospital_nuevo->cantidad_entrenador = 0;
    hospital_nuevo->cantidad_pokemon = 0;
    hospital_nuevo->vector_pokemones = NULL;

    /*hospital_nuevo->vector_pokemones = realloc(hospital_nuevo->vector_pokemones, sizeof(pokemon_t*));
    if(!hospital_nuevo->vector_pokemones){
        free(hospital_nuevo);
        return NULL;
    } 
     
    hospital_nuevo->vector_pokemones */  

    return hospital_nuevo;

}

bool hospital_leer_archivo(hospital_t* hospital, const char* nombre_archivo){
    if(!nombre_archivo || !nombre_archivo) return false;

    FILE* archivo_hospital = fopen(nombre_archivo, "r");
    if(!archivo_hospital) return false;

    char* linea_leida = NULL;
    char* linea_aux = NULL;

    int inicio = 0;
    int final = 0;
    int incremento = 60;

    while((linea_aux = realloc(linea_leida, final+incremento))){
        linea_leida = linea_aux;
        final += incremento;
        linea_aux[final-1] = 1;

        if(!fgets(linea_aux+inicio, final-inicio, archivo_hospital)){
            free(linea_leida);
            return NULL;
        }

        //if(linea_aux[final-1] != 0 || (aux))
    }

    /*size_t bytes_leidos = 0;


    while(fgets(linea_leida, sizeof(char*), archivo_hospital)){
            size_t leido = strlen(linea_leida+bytes_leidos);
            if(leido > 0 && *(linea_leida+bytes_leidos+leido-1) == '\n'){
                *(linea_leida+bytes_leidos+leido-1) = 0;

            }

    }*/



    int cierre_exitoso = fclose(archivo_hospital);

    if(cierre_exitoso) return true;
    else return false;
}

size_t hospital_cantidad_pokemon(hospital_t* hospital){
    if(!hospital) return 0;
    return hospital->cantidad_pokemon;
}

size_t hospital_cantidad_entrenadores(hospital_t* hospital){
    if(!hospital) return 0;
    return hospital->cantidad_entrenador;
}

size_t hospital_a_cada_pokemon(hospital_t* hospital, bool (*funcion)(pokemon_t* p)){
    if(!hospital || !funcion) return 0;

    /*pokemon_t* vector_pokemon_alfabetico =*/ ordenar_pokemon_alfabetico(&(hospital->vector_pokemones), hospital->cantidad_pokemon);
    size_t i = 0;

    while(funcion(vector_pokemon_alfabetico[i])) i++;
    return i;
}


/*void lista_recorrer(lista_t *l, bool (*visitar)(void *dato)){

    if(lista_es_vacia(l)) return;

    struct nodo *n = l->lista;
    while(n != NULL) {
        if(!visitar(n->dato)) break;
        n = n->sig;
    }
}*/


void hospital_destruir(hospital_t* hospital){
    if(!hospital) return;

    size_t iterar = 0;
    while(iterar < hospital->cantidad_pokemon){
        free(hospital->vector_pokemones[iterar].nombre);
        free(&(hospital->vector_pokemones[iterar]));
        iterar++;
    }
    free(hospital);
    return;
}

size_t pokemon_nivel(pokemon_t* pokemon){
    if(!pokemon) return 0;
    return pokemon->nivel;
}

const char* pokemon_nombre(pokemon_t* pokemon){
    if(!pokemon) return NULL;
    return pokemon->nombre;
}
