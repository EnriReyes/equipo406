#ifndef USUARIOREG_H
#define USUARIOREG_H

#include <string>

class UsuarioReg{
private: 
    std::string dni_ , nombrecompleto_ , email_ , uco_login_;
    int id_;
public:
//Constructor
UsuarioReg(std::string dni,
std::string nombrecompleto,
std::string email,
std::string uco_login,
int id
): dni_(dni), nombrecompleto_(nombrecompleto),
 email_(email), uco_login_(uco_login), id_(id){}
//Observadores
inline std::string get_dni()const{return dni_;}
inline std::string get_nombrecompleto()const{return nombrecompleto_;}
inline std::string get_email()const{return email_;}
inline std::string get_uco_login()const{return uco_login_;}
inline int get_id()const{return id_;}
};


#endif