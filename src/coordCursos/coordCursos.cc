#include "coordCursos.h"
#include "curso.h"
#include <iostream>

void CoordCursos::administrar_ponentes(Curso curso){
    std::vector<std::string> v = curso.get_ponentes();
    std::string aux;

    std::cout<<"Ponentes actuales: \n";
    for(int i =0; i<3; i++){
        std::cout<<v[i]<<std::endl;
    }

    std::cout<<"Introduce el nombre de los nuevos ponentes\n";
    std::vector<std::string> nuevo;

    for(int i =0; i<3; i++){
        getline(std::cin, aux);
        nuevo.push_back(aux);
    }

    curso.set_ponentes(nuevo);
    std::cout<<"Actualizacion de ponentes realizada con exito\n";

}

void CoordCursos::administrar_descp(Curso curso){
    int i=0;
    std::string aux;

    while(i!=4){
        std::cout<<"Introduzca el numero de la operacion que desee realizar desea realizar:\n ";
        std::cout<<"1.Actualizar descripción.\n";
        std::cout << "2.Actualizar fecha inicio del curso.\n";
        std::cout << "3.Actualizar fecha final del curso.txt.\n";
        std::cout << "4.Volver al curso.\n";
        std::cin >> i;
        switch (i)
        {
        case 1:

            std::cout<<"Anterior descripcion del curso era:\n"<<curso.get_descripcion()<<std::endl;
            std::cout<<"Introduce la nueva descripcion: ";
            getline(std::cin, aux);
            curso.set_descripcion(aux);
            std::cout<<"Cambios realizados.\n";
            break;

        case 2:
            std::cout<<"Anterior fecha de inicio del curso era:\n"<<curso.get_fecha_inicio()<<std::endl;
            std::cout<<"Introduce la nueva fecha de inicio: ";
            getline(std::cin, aux);
            curso.set_descripcion(aux);
            std::cout<<"Cambios realizados.\n";
            break;
        break;
        case 3:
            std::cout<<"Anterior fecha de finalizacion era\n:"<<curso.get_fecha_inicio()<<std::endl;
            std::cout<<"Introduce la nueva fecha de finalizacion: ";
            getline(std::cin, aux);
            curso.set_descripcion(aux);
            std::cout<<"Cambios realizados.\n";
            break;
        break;

        case 4:
            std::cout<<"Saliendo del sistema de actualizacion\n";
        break;

        default:
            std::cout<<"Error, la accion no existe\n";
            break;
        }
    }
}

bool CoordCursos::buscar_alumno(Curso curso, std::string alumno){
    std::list<std::string> p = curso.get_lista_participantes();
    for(auto list = p.begin(); list!=p.end(); list++){
        if((*list)==alumno){
            return true;
        }
    }
    return false;
}
