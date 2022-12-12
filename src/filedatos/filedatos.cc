#include "filedatos.h"
#include "UsuarioReg.h"
#include <string>
#include <iostream>
#include <fstream>

UsuarioReg File_datos::obtener_datos(std::string dni){
    
    std::ifstream file;
    file.open("file_datos.txt",std::ios::in);
    if(file.fail()){
        std::cout << "Error al abrir el fichero \n" << std::endl;
        exit(1);
    }

    int id;
    std::string nombrecompleto, mail, login, clave, idstring;

    while(!file.eof()){
        getline(file,clave);
        getline(file,nombrecompleto);
        getline(file,login);
        getline(file,mail);
        getline(file,idstring);
        id = stoi(idstring);
        if(clave==dni){
            std::cout << "Usuario Encontrado\n" << std::endl;
            UsuarioReg aux(clave,nombrecompleto,mail,login,id);
            file.close();
            return aux;
        }
    }
    std::cout << "Usuario no Encontrado\n" << std::endl;
    file.close();
    UsuarioReg aux2(" ", " ", " ", " ", 0);
    return aux2;
}