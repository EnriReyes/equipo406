#ifndef VISITANTE_H
#define VISITANTE_H

#include <string>

class visitante{
private:
    int id_visitante_;
public:
    visitante(int id_visitante):id_visitante_(id_visitante){}
    void ver_curso(class Curso c);
};

#endif