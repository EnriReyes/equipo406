#include <string>
#include "usuarioReg.h"
#include "participante.h"
#include <vector>
#include "curso.h"



void Participante::valorar_curso(Curso &curso, int valoracion){
    int j = 0;
    auto c = curso.get_lista_participantes();
    for(auto i = c.begin(); i!=c.end();++i){
        if(*i==get_dni()){
            j++;
            break;
        }
    }
    if(j==1){
        auto val = curso.get_valoracion();
        val[get_dni()]=valoracion;
        curso.set_valoracion(val);
        std::cout<<"Valoracion realizada con exito\n";
    }
    else{
        printf("ERROR, este usuario no esta inscrito en el curso\n");
    }
    
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
            v=curso.get_lista_espera();
            for(auto list = v.begin(); list!=v.end(); list++){
                if(get_dni()==*list){
                    std::cout<<"ERROR, usuario ya inscrito en la lista de espera\n";
                    return;
                } 
            }
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