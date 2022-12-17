#include <fstream>
#include <iostream>
#include "curso.h"
#include "filecurso.h"
#include <string>

bool File_curso::guardar_curso(Curso c){

    std::string dni;
    std::string aux = c.get_id();
    aux += ".txt";
    int i =0;
    std::ofstream file(aux);
    if(!file){
       return false;
    }

    file << c.get_descripcion()<<"\n"<<c.get_fecha_inicio()<<"\n"<<c.get_fecha_final()<<"\n";
    
    std::vector<std::string> v3 = c.get_ponentes();
    for ( i = 0; i < 3; i++)
    {
        file<<v3[i]<<std::endl;
    }
    file<<c.get_aforo()<<std::endl;
    file<< c.get_size_participantes() << " " << c.get_size_espera();

    std::list<std::string> v = c.get_lista_participantes();
    std::map<std::string, int>v1 = c.get_valoracion();
    if(v.empty()){
        return true;
    }
    else{
        i =0;
        for(auto list = v.begin(); list!=v.end(); list++){
            file<<"\n";
            if(v1.find(*list)==v1.end()){
                v1[*list]=-1;
            }
            file<< *list <<"\n" << v1[*list];
            i++;
        }


        v=c.get_lista_espera();

        if(v.empty()){
            return true;
        }
        else{
            for(auto list = v.begin(); list!=v.end(); list++){
                file<<"\n";
                file<< *list;
            }
        }
    return true;
    }
}

bool File_curso::leer_curso(Curso &c){
    std::string aux1;
    std::string aux= c.get_id();
    aux+=".txt";

    std::ifstream file(aux);
    if(!file){
       return false;
    }
    //Leemos con getline la fila entera (desc, fechas)
    getline(file, aux1);
    c.set_descripcion(aux1);

    getline(file, aux1);
    c.set_fecha_inicio(aux1);

    getline(file, aux1);
    c.set_fecha_final(aux1);

    //Leemos los ponentes
    std::vector<std::string> v3;
    for ( int i = 0; i < 3; i++)
    {
        getline(file, aux1);
        v3.push_back(aux1);
    }
    c.set_ponentes(v3);

    int aforo;
    file >> aforo;
    c.set_aforo(aforo);

    //Leemos el tamano de las listas de espera y participantes del curso
    int a, b, valor;
    file >> a >> b;
    std::list<std::string> lista;
    std::map<std::string, int> valoracion; 
    //Leemos la valoración y el dni de los participantes.
    getline(file, aux1);
    for(int i=0;i<a;i++){
        getline(file, aux1);
        file>> valor;
        lista.push_back(aux1);
        valoracion[aux1]=valor;
        getline(file, aux1);
    }
    c.set_participantes(lista);
    c.set_valoracion(valoracion);
    //Limpiamos la lista y leemos lista de espera
    lista.clear();
    for(int i=0; i<b; i++){
        getline(file, aux1);
        lista.push_back(aux1);
    }
    c.set_lista_espera(lista);
    return true;
}

void File_curso::borrar_curso(std::string id){
    std::vector<std::string> v;
    std::ifstream file("Archivo_main.txt");
    std::string aux;
    int i =0;

    while(!file.eof()){
        getline(file, aux);
        if(aux!=id) {
            v.push_back(aux);
            std::cout<<v[i]<<"\n";
            i++;
        }
    }
    std::vector<std::string> v2 =get_vector_cursos();
    if(v2.size()==v.size()) {
        std::cout<<"ERROR, el curso seleccionado no existe.\n";
        return;
    }
    file.close();
    remove("Archivo_main.txt");

    std::ofstream file1("Archivo_main.txt");
    file1<<v[0];
    for(int i=1;i<v.size(); i++){
        file1<<"\n";
        file1<<v[i];
    }

    id+=".txt";
    //Se debe hacer esto, porque la función recibe un argumento de tipo char* y .str() devuelve un const char* b
    remove(id.c_str());
}

std::vector<std::string> File_curso::get_vector_cursos(){
    std::vector<std::string> v;
    std::ifstream file("Archivo_main.txt");
    std::string aux;

    while(!file.eof()){
        getline(file, aux);
        v.push_back(aux);
    }
    return v;
}
