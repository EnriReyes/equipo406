#ifndef _PARTICIPANTE_
#define _PARTICIPANTE_

#include <iostream>
#include <string>
#include "curso.h"
#include "UsuarioReg.h"

class Participante:UsuarioReg{
    public:
    Participante(std::string dni,
std::string nombrecompleto,
std::string email,
std::string uco_login,
int id);
    void valorar_curso(Curso curso, int valoracion);
    void inscribirse_curso(Curso curso);};



#endif