#include <iostream>
#include "usuarioReg.h"
#include "filedatos.h"
#include "filecurso.h"
#include "filelogin.h"
#include "admin.h"
#include "participante.h"
#include "curso.h"

void ver_datos_participante(std::string partici){
    std::cout<<"\n\n\n\n\n\n\n\n";
    File_datos d;
    UsuarioReg p = d.obtener_datos(partici);
    std::cout<<"DATOS PARTICIPANTE: \n";

    std::cout<<"Nombre: "<<p.get_nombrecompleto()<<std::endl<<"Correo electrónico: "<< p.get_email()<<"\n";
    std::cout<<"Usuario de la UCO: "<<p.get_uco_login()<<"\n";
}

void registrarse(UsuarioReg &usuario ){
    int i = 0, j, z;
    std::string aux1, aux2;
    File_Login l;
    File_datos d;
    std::cout<<"Bienvenido al sistema de gestion de cursos de extension de la universidad de Cordoba\n";

    while(i==0){
        std::cout<<"Que desea realizar?\n1. Ingresar como visitante\n2. Regstrarse\n";
        std::cin>>j;
        std::cin.ignore(1,'\n');
        switch(j){
            case 1:
                i=1;
                std::cout<<"\n\n\n\n\n\n\n\n";
            break;
            case 2:
                std::cout<<"Introduce el nombre de usuario.\n";
                std::getline(std::cin, aux1);
                std::cout<<"Introduce la contraseña.\n";
                std::getline(std::cin, aux2);
                z=l.buscar_usuario(aux1, aux2);
                if(z==0)std::cout<<"El nombre de usuario no existe\n\n\n\n\n\n\n\n";
                if(z==-1)std::cout<<"Contraseña Incorrecta\n\n\n\n\n\n\n\n";
                if(z==1){
                    std::cout<<"Se ha iniciado sesion correctamente\n\n\n\n\n\n\n\n";
                    usuario= d.obtener_datos2(aux1);
                    i = 1;
                }
            break;
            default:
                    std::cout<<"Opción indicada no existe\n\n\n\n\n\n\n\n";
            break;
        }
    }

}

void visitar_curso(std::vector<std::string> v,UsuarioReg usuario){
                        std::string aux556;
    int j, i=0, z, aux34=1;
    bool h;
    std::list<std::string> lista;
    File_curso f;
    Curso c;
    std::string partici;
    
    std::cout<<"\n\n\n\n\n\n\n\n";

    std::cout<<"Cursos disponibles\n";
    for(int i=0; i<v.size(); i++){
        std::cout<<i+1<<". "<<v[i]<<std::endl;
    }

    std::cout<<"Introduzca el numero del curso que desee visitar\n";
    std::cin>>j;
    if(1>j||v.size()<j){
        printf("Error, numero del curso incorrecto.\nSaliedo a la pagina anterior...\n");
        return;
    }

    c.set_id(v[j-1]);
    f.leer_curso(c);

     while(i==0){
        j=1;
        std::cout<<"\n\n\n\n\n\n\n\n";
        usuario.ver_curso(c);
        std::cout<<"Que desea realizar?\n";
        if(usuario.get_id()==2 || usuario.get_id()==3){
            std::cout<<"1. Buscar un alumno\n2. Editar descripción\n3. Editar ponentes.\n";
            j=4;
        }
        if(usuario.get_id()==1){
            std::cout<<"1. Inscribirse en el curso.\n";
            std::cout<<"2. Valorar curso.\n";
            j=3;
        }
        std::cout<<j<<". "<<"Salir del curso\n";
        std::cin>>z;
        std::cin.ignore(1,'\n');
        std::cout<<"\n\n\n\n\n\n\n\n";
        if(usuario.get_id()==-1){
            switch(z){
                case 1:
                    std::cout<<"Saliendo del curso...\n";
                    i=1;
                break;
                default:
                    std::cout<<"Opción indicada no existe\n\n\n\n\n\n\n\n";
                break;
            }
        }
        if(usuario.get_id()==1){
            Participante p(usuario.get_dni(), usuario.get_nombrecompleto(),
                                    usuario.get_email(), usuario.get_uco_login(), usuario.get_id());
            switch(z){
                case 1:
                    p.inscribirse_curso(c);
                break;
                case 2:
                    int val;
                    while(aux34==1){
                        std::cout<<"Inserte valoración del curso (del 1 al 10 y numeros enteros)\n";
                        std::cin>>val;
                        if(val>10||val<0){
                            std::cout<<"ERROR, valor insertado no comprendido en el intervalo [0,10]\n";
                        }
                        else aux34=0;
                    }
                    p.valorar_curso(c, val);
                break;
                case 3:
                    std::cout<<"Saliendo del curso...";
                    i=1;
                    std::cout<<"\n\n\n\n\n\n\n\n";
                break;
                default:
                    std::cout<<"Opción indicada no existe\n\n\n\n\n\n\n\n";
                break;
            }
        }
        if(usuario.get_id()==2 || usuario.get_id()==3){
            Admin a(usuario.get_dni(), usuario.get_nombrecompleto(),
                                    usuario.get_email(), usuario.get_uco_login(), usuario.get_id());
            switch(z){
                case 1:
                    if(c.get_lista_participantes().empty()==true){
                        std::cout<<"Error no hay ningún participante ingresado en el curso\n";
                        break;
                    }
                    std::cout<<"Participantes inscritos:\n";
                    lista=c.get_lista_participantes();
                    for(auto i=lista.begin(); i!=lista.end(); ++i){
                        std::cout << *i << std::endl;
                    }
                    std::cout<<"Inserte el dni del alumno que desee buscar.\n";
                    std::getline(std::cin, partici);
                    h=a.buscar_alumno(c, partici);
                    if(h==true){
                        ver_datos_participante(partici);
                    }
                break;
                case 2:
                    a.administrar_descp(c);
                    
                break;
                case 3:
                    a.administrar_ponentes(c);
                break;
                case 4:
                    std::cout<<"Saliendo del curso...\n\n\n\n\n\n\n\n";
                    i=1;
                break;
                default:
                    std::cout<<"Opción indicada no existe\n\n\n\n\n\n\n\n";
                break;
            }
        }
        std::cout<<"\n\n\n\n";
    }
     f.guardar_curso(c);

}


int main(){
    UsuarioReg usuario;
    File_curso c;
    int i=0, j=2, z;
    std::vector<std::string> v;
    std::string aux;

    registrarse( usuario ); 
    v=c.get_vector_cursos();

    while(i==0){
        v=c.get_vector_cursos();
        std::cout<<"Cursos disponibles\n";
        for(int i=0; i<v.size(); i++){
            std::cout<<i+1<<". "<<v[i]<<std::endl;
        }
    
        std::cout<<"\nQue desea realizar?\n1. Visitar un curso\n";
        if(usuario.get_id()==3){
            std::cout<<"2. Borrar un curso\n3. Crear un curso\n";
            j=4;
        }
        std::cout<<j<<". "<<"Salir del sistema\n";
        std::cin>>z;
        std::cin.ignore(1,'\n');
        if(usuario.get_id()!=3){
            switch(z){
                case 1:
                    visitar_curso(v, usuario);
                    std::cout<<"\n\n\n\n\n\n\n\n";
                break;
                case 2:
                    std::cout<<"Saliendo del sistema...\n\n\n\n\n\n\n\n";
                    i=1;
                break;
                default:
                    std::cout<<"Opción indicada no existe\n\n\n\n\n\n\n\n";
                break;
            }
        }
        else{
        Admin a(usuario.get_dni(), usuario.get_nombrecompleto(),
                                    usuario.get_email(), usuario.get_uco_login(), usuario.get_id());
            switch(z){
                case 1:
                    visitar_curso(v, usuario);
                    std::cout<<"\n\n\n\n\n\n\n\n";
                break;
                case 2:
                    a.borrar_curso();
                    std::cout<<"\n\n\n\n\n\n\n\n";
                break;
                case 3:
                    a.crear_curso();
                    std::cout<<"\n\n\n\n\n\n\n\n";
                break;
                case 4:
                    std::cout<<"Saliendo del sistema...\n\n\n\n\n\n\n\n";
                    i=1;
                break;
                default:
                    std::cout<<"Opción indicada no existe\n\n\n\n\n\n\n\n";
                break;
            }
        }
    }
    return 0;
}