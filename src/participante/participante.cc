#include <string>
#include "usuarioReg.h"
#include "participante.h"
#include <vector>
#include "curso.h"



void Participante::valorar_curso(Curso &curso, int valoracion){
    auto val = curso.get_valoracion();
    val.push_back(valoracion);
    curso.set_valoracion(val);
    
}
void Participante::inscribirse_curso(Curso &curso){
    if(curso.get_aforo()==curso.get_size_participantes()){
        auto lista = curso.get_lista_espera();
        lista.push_back(get_dni());
        curso.set_lista_espera(lista);
    }
    else{
        auto lista = curso.get_lista_participantes();
        lista.push_back(get_dni());
        curso.set_participantes(lista);
    }
}