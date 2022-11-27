#include "UsuarioReg.h"
#include "curso.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>


int main(){
    std::string aux;
    int i;

    std::cout<<"Inserte el nombre del curso.\n";
    getline(std::cin, aux);
    Curso c(aux);

    std::cout<<"Inserte la descripcion del curso.\n";
    getline(std::cin, aux);
    c.set_descripcion(aux);

    std::cout<<"Inserte la fecha de inicio del curso.\n";
    getline(std::cin, aux);
    c.set_fecha_inicio(aux);

    std::cout<<"Inserte el fecha del final del curso.\n";
    getline(std::cin, aux);
    c.set_fecha_final(aux);

    std::cout<<"Inserte el aforo maximo.\n";
    std::cin>>i;
    c.set_aforo(i);

    std::cout << "Inserte una valoración para el curso" << std::endl;
    getline(std::cin, aux);
    std::vector<int> valoracion(9,10);
    c.set_valoracion(valoracion);

    std::cout << "Curso insertado" << std::endl;

    UsuarioReg u ("30120644S", "Javier Vioque Moreno", "javiervioquemoreno@gmail.com", "i12vimoj", 1);
    std::cout << "UsuarioReg creado" << std::endl << std::endl;
    std::cout << "Comenzamos la prueba de la funcionalidad ver_curso()" << std::endl;

    u.ver_curso(c);
}