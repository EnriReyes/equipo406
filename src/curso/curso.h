#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <vector>
#include <list>

class Curso{
    private:
        std::string id_, descripcion_, fecha_inicio_, fecha_final_;
        std::vector<int> valoracion_;
        std::vector<std::string> ponentes_;
        int aforo_;
        std::list<std::string> participantes_, lista_espera_;
    public:
        Curso(std::string id="", std::string descripcion = "", std::string fecha_inicio = "", 
                std::string fecha_final ="", int aforo = 0): id_(id), descripcion_(descripcion),
                                                            fecha_inicio_(fecha_inicio), fecha_final_(fecha_final),
                                                            aforo_(aforo){}

        inline void set_ponentes(const std::vector<std::string> &ponentes){ponentes_=ponentes;}
        inline void set_descripcion(const std::string &descripcion){descripcion_=descripcion;}
        inline void set_fecha_inicio(const std::string &fecha_inicio){fecha_inicio_=fecha_inicio;}
        inline void set_fecha_final(const std::string &fecha_final){fecha_final_=fecha_final;}
        inline void set_valoracion(const std::vector<int> &valoracion){valoracion_=valoracion;}
        inline void set_id(const std::string &id){id_=id;}
        inline void set_aforo(int aforo){aforo_=aforo;}
        inline void set_participantes(const std::list<std::string> &participantes){participantes_=participantes;}
        inline void set_lista_espera(const std::list<std::string> &lista_espera){lista_espera_=lista_espera;}

        inline std::string get_descripcion()const{return descripcion_;}
        inline std::string get_fecha_inicio()const{return fecha_inicio_;}
        inline std::string get_fecha_final()const{return fecha_final_;}
        inline std::string get_id()const{return id_;}
        inline int get_aforo()const{return aforo_;}
        inline std::vector<int> get_valoracion()const{return valoracion_;}

        inline int get_size_participantes()const{return participantes_.size();}
        inline int get_size_espera()const{return lista_espera_.size();}
        inline std::list<std::string> get_lista_participantes()const{return participantes_;}
        inline std::list<std::string> get_lista_espera()const{return lista_espera_;}
        inline std::vector<std::string> get_ponentes()const{return ponentes_;}
};
#endif