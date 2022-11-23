#ifndef FILECURSO_H
#define FILECURSO_H

#include "curso.h"

class File_curso{
    private:
        std::string file_curso_;
    public:
        File_curso(std::string file_curso=""): file_curso_(file_curso){}
        bool guardar_curso(Curso c);
        bool leer_curso(Curso &c);
        void borrar_curso(std::string id);
        std::vector<Curso> get_vector_cursos();
};


#endif