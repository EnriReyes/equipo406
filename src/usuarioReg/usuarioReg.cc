#include <string>
#include <iostream>
#include <vector>
#include <list>
#include "usuarioReg.h"
#include "curso.h"


void UsuarioReg::ver_curso(class Curso c){
    std::list<std::string> l_participantes = c.get_lista_participantes();
    std::list<std::string> l_lista_espera = c.get_lista_espera();
    std::cout << std::endl;
    std::map<std::string, int> v = c.get_valoracion();
    int nEle = v.size();
    int suma=0, media =0;
    std::list<std::string>::iterator i;
    i=l_participantes.begin();
    for(i; i!=l_participantes.end(); ++i){
        if(v.find(*i)!=v.end())
            if(v[*i]!=-1){
                suma+=v[*i];
            }
    }
    if(suma!=0){
        media = (suma/nEle);
    }

    std::cout << "ID: " << c.get_id() << "." << "\t\t\t\t\t\t\t"<< "AFORO: " << c.get_aforo() << std::endl;
    std::cout << c.get_descripcion() << "." << std::endl;
    std::cout<<"Ponentes: "<<std::endl;
    std::vector<std::string> v594=c.get_ponentes();
    for(int i=0; i<3; i++){
        std::cout<<"\t"<<v594[i]<<std::endl;
    }
    std::cout << std::endl<<"Fecha de inicio: "<< c.get_fecha_inicio() << "\t\t\t\t Fecha final: "<< c.get_fecha_final() << "." << std::endl;
    std::cout << "Valoración del curso: " << media << "/10" << std::endl<<std::endl;

    i=l_participantes.begin();
    std::cout << "Numero participantes inscritos: "<< c.get_size_participantes()<<std::endl;
    if(get_id()==3||get_id()==2){
        std::cout<< "\nLista: " << std::endl;
        for(i; i!=l_participantes.end(); ++i){
            std::cout <<"\t"<< *i << std::endl;
        }

        std::list<std::string>::iterator i2;
        i2=l_lista_espera.begin();
        std::cout << "Numero de participantes en lista de espera: "<< c.get_size_espera() << "\n Lista: \n" << std::endl;
        for(i2; i2!=l_lista_espera.end(); ++i2){
            std::cout <<"\t"<< *i2 << std::endl;
        }
    }
}