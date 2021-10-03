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

    return hospital_nuevo;

}


char* leer_linea(FILE* file){
    if(!file) return NULL;

    char* linea = NULL;
    char* aux = NULL;

    int inicio = 0;
    int final = 0;
    int incremento = 80;

    while((aux = realloc(linea, (size_t) (final+incremento)))){
        linea = aux;
        final += incremento;
        aux[final-1] = 1;

        if(!fgets(aux+inicio, final-inicio, file)){
            free(linea);
            return NULL;
        }

        if(aux[final-1] != 0 || (aux[final-1]==0 && aux[final-2]=='\n'))
            return linea;

        inicio = final-1;
    }

    free(linea);
    return NULL;
}


void agregar_linea_hospital(hospital_t* hospital, char** vector_linea){
    if(!hospital || !vector_linea) return;

    size_t cantidad_pokemon = 0;

    for (int i = 2; vector_linea[i] ; i=i+2){
        hospital->vector_pokemones = realloc(hospital->vector_pokemones, (size_t)(i/2) * sizeof(pokemon_t));
        if(!hospital->vector_pokemones) return;

        (hospital->vector_pokemones)[cantidad_pokemon].nombre = vector_linea[i];

        for (int j = 3; vector_linea[j]; j=j+2){
            (hospital->vector_pokemones)[cantidad_pokemon].nivel = (size_t) vector_linea[j];

            cantidad_pokemon++;
        }
    }
    return;
}


bool hospital_leer_archivo(hospital_t* hospital, const char* nombre_archivo){
    if(!hospital || !nombre_archivo) return false;

    FILE* archivo_hospital = fopen(nombre_archivo, "r");
    if(!archivo_hospital) return false;

    char* linea_leida;
    char** vector_linea;
    size_t cantidad_lineas = 0;

    bool leer_archivo = true;
    while(leer_archivo){
        linea_leida = leer_linea(archivo_hospital);
        if(!linea_leida) return false;

        vector_linea = split(linea_leida, ';');

        agregar_linea_hospital(hospital, vector_linea);


        cantidad_lineas++;
    }
    hospital->cantidad_entrenador = cantidad_lineas; 


    /*size_t bytes_leidos = 0;


    while(fgets(linea_leida, sizeof(char*), archivo_hospital)){
            size_t leido = strlen(linea_leida+bytes_leidos);
            if(leido > 0 && *(linea_leida+bytes_leidos+leido-1) == '\n'){
                *(linea_leida+bytes_leidos+leido-1) = 0;

            }

    }*/






    //bool cierre_exitoso;

    int cierre = fclose(archivo_hospital);

    if(cierre==0){ 
        return true;
    }
    return false;
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

    /*pokemon_t* vector_pokemon_alfabetico = ordenar_pokemon_alfabetico(&(hospital->vector_pokemones), hospital->cantidad_pokemon);
    size_t i = 0;

    while(funcion(hospital->vector_pokemones[i])) i++;
    return i;*/
    return 0;
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
