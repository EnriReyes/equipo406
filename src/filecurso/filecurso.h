#ifndef FILECURSO_H
#define FILECURSO_H
#include "curso.h"
#include <string>

class File_curso{
    private:
    std::string file;
    public:
    bool guardar_curso(Curso c);
    bool leer_curso(Curso &c);
    void borrar_curso(std::string id);
    std::vector<std::string> get_vector_cursos();
};

#endif