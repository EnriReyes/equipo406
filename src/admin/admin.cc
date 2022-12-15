#include <iostream>
#include <fstream>
#include "admin.h"
#include "filecurso.h"

void Admin::borrar_curso(){
    File_curso f;
    std::string aux;
    std::cout<<"Inserte el curso que desee borrar.\n";
    getline(std::cin, aux);

    f.borrar_curso(aux);
}

bool Admin::crear_curso(){
    std::ifstream file("Archivo_main.txt");
    std::string aux;
    std::vector<std::string> v5, v;
    int j;
    File_curso f;

    if(!file){
       return false;
    }

    //Creamos el curso.
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
    std::cin>>j;
    c.set_aforo(j);

    //Guardamos el nombre del nuevo curso
    while(!file.eof()){
        getline(file, aux);
        v.push_back(aux);
    }
    file.close();
    v.push_back(c.get_id());
    remove("Archivo_main.txt");

    std::ofstream file1("Archivo_main.txt");
    if(!file1){
       return false;
    }
    file1<<v[0];
    for(int i=1;i<v.size(); i++){
        file1<<"\n";
        file1<<v[i];
    }
    file1.close();

    return f.guardar_curso(c);
}

