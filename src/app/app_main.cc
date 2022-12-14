#include <iostream>
#include "usuarioReg.h"
#include "filedatos.h"
#include "filecurso.h"
#include "filelogin.h"
#include "admin.h"

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

int main(){
    UsuarioReg usuario;
    File_curso c;
    int i=0, j=2, z;
    std::vector<std::string> v;

    registrarse( usuario ); 
    v=c.get_vector_cursos();

    std::cout<<"Cursos disponibles\n";
    for(int i=0; i<v.size(); i++){
        std::cout<<i+1<<". "<<v[i]<<std::endl;
    }
    
    while(i==0){
        std::cout<<"Que desea realizar?\n1. Visitar un curso\n";
        if(usuario.get_id()==2){
            std::cout<<"2. Borrar un curso\n3. Crear un curso\n";
            j=4;
        }
        std::cout<<j<<". "<<"Salir del sistema\n";
        std::cin>>z;
        std::cin.ignore(1,'\n');
        if(usuario.get_id()!=2){
            switch(z){
                case 1:
                    std::cout<<"Holo\n";
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
            switch(z){
                case 1:
                    std::cout<<"Holo\n\n\n\n\n\n\n\n";
                break;
                case 2:
                    std::cout<<"Borrar curso\n\n\n\n\n\n\n\n";
                break;
                case 3:
                    std::cout<<"Crear curso\n\n\n\n\n\n\n\n";
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