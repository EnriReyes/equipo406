#ifndef COORDCURSOS_H
#define COORDCURSOS_H
#include "curso.h"
#include "usuarioReg.h"


class CoordCursos: public UsuarioReg{
    public:
            CoordCursos(std::string dni,
                    std::string nombrecompleto,
                    std::string email,
                    std::string uco_login,
                    int id): UsuarioReg(dni,nombrecompleto,email,uco_login,id){}
        void administrar_ponentes(Curso curso);
        void administrar_descp(Curso curso);
        bool buscar_alumno(Curso curso, std::string alumno);
};

#endif