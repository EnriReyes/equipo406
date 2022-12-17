#include <fstream>
#include <iostream>
#include "filelogin.h"
#include <string>

int File_Login::buscar_usuario(std::string nombre, std::string password){
    std::string aux;
    std::ifstream file("usuarios_registrados.txt");
    if(!file){
       return 0;
    }
    while(!file.eof())
    {
        getline(file, aux);
        if(aux == nombre){
            getline(file, aux);
            if(aux == password){
                return 1;
            }
            return -1;
        }
    }
    return 0;
}