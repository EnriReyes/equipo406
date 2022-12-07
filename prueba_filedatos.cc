#include "filedatos.h"
#include "UsuarioReg.h"
#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string dni="31020644S";
    UsuarioReg aux(" ", " ", " ", " ", 0);
    File_datos fd;
    aux=fd.obtener_datos(dni);
    std::cout << aux.get_dni() << aux.get_nombrecompleto() << std::endl;
}
