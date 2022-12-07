#ifndef FILEDATOS_H
#define FILEDATOS_H
#include "UsuarioReg.h"
#include <string>

class File_datos{
    private:
    std::string file_datos_;
    public:
    UsuarioReg obtener_datos(std::string dni);
};

#endif