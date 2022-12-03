#include "curso.h"
#include "participante.h"
#include "iostream"
#include "UsuarioReg.h"
#include "filecurso.h"
#include "filelogin.h"

int main(){
    std::string aux;
    int i;
    std::vector<std::string> v5;
    Curso b("b");
    std::cout<<"Inserte el nombre del curso.\n";
    getline(std::cin, aux);
    Curso c(aux);

    std::cout<<"Inserte la descripcion del curso.\n";
    getline(std::cin, aux);
    c.set_descripcion(aux);

    std::cout<<"Inserte la fecha de inicio del curso.\n";
    getline(std::cin, aux);
    c.set_fecha_inicio(aux);

    std::cout<<"Inserte la fecha de final del curso.\n";
    getline(std::cin, aux);
    c.set_fecha_final(aux);

    for(int i=0; i<3; i++){
        std::cout<<"Inserte ponente.\n";
        getline(std::cin, aux);
        v5.push_back(aux);
    }
    c.set_ponentes(v5);

    std::cout<<"Inserte el aforo maximo.\n";
    std::cin>>i;
    c.set_aforo(i);

    File_curso f(c.get_id());
    std::cout<< c.get_id()<<" "<<c.get_descripcion()<<" "<<c.get_fecha_inicio()<<" "<<c.get_fecha_final()<<" "<<c.get_aforo()<<std::endl;


    Participante participante("122212", "Pepe Pepe Pepe", "prueba@gmail.com", "participante", 1);

    std::cout << participante.get_dni()<<" "<<participante.get_email()<<" "<<participante.get_nombrecompleto()<<" "<< participante.get_uco_login() <<std::endl;
    
    
    participante.valorar_curso(c, 10);
    std::cout << c.get_valoracion()[0] << std::endl;

    participante.inscribirse_curso(c);
    std::cout << c.get_size_participantes() << std::endl;

    File_Login login;
    std::cout << login.buscar_usuario("prueba", "prueba2");
    std::cout << login.buscar_usuario("oaoaoa", "a");
}

//Comentario de prueba para gitlens
