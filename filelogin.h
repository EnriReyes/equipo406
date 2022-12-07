#ifndef FILELOGIN_H
#define FILELOGIN_H
#include "curso.h"
#include <string>

class File_Login{
    private:
    std::string filelogin;
    public:
    int buscar_usuario(std::string nombre, std::string password);
};

#endif