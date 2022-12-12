#ifndef ADMIN_H
#define ADMIN_H

#include "coordCursos.h"
class Admin: public CoordCursos{

    public:
    bool crear_curso();
    void borrar_curso();

};

#endif