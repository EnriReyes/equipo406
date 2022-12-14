#ifndef ADMIN_H
#define ADMIN_H

#include "coordCursos.h"
class Admin: public CoordCursos{

    public:
    Admin(std::string dni,
                    std::string nombrecompleto,
                    std::string email,
                    std::string uco_login,
                    int id): CoordCursos(dni,nombrecompleto,email,uco_login,id){}
    bool crear_curso();
    void borrar_curso();

};

#endif