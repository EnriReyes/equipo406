#ifndef FILEDATOS_H
#define FILEDATOS_H
#include "usuarioReg.h"
#include <string>

class File_datos{
    private:
    std::string file_datos_;
    public:
    UsuarioReg obtener_datos(std::string dni);
    UsuarioReg obtener_datos2(std::string uco_login);
};

#endif