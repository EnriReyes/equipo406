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
    auto v= curso.get_lista_participantes();
    int a=0;
    for(auto list = v.begin(); list!=v.end(); list++){
        if(get_dni()==*list){
            a=1;
            std::cout<<"ERROR, usuario ya inscrito\n";
            break;
        }
    }
    if(a!=1){
        if(curso.get_aforo()==curso.get_size_participantes()){
            auto lista = curso.get_lista_espera();
            lista.push_back(get_dni());
            curso.set_lista_espera(lista);
            std::cout<<"Lista de participantes llena, entrando en lista de espera\n";
        }
        else{
            auto lista = curso.get_lista_participantes();
            lista.push_back(get_dni());
            curso.set_participantes(lista);
            std::cout<<"Usuario inscrito de forma satisfactoria\n";
        }
    }
}