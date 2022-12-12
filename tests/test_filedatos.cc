#include "filedatos.h"
#include "UsuarioReg.h"
#include <iostream>
#include <fstream>
#include <string>




TEST(filedatos, filedatos_obtener_datos) {
  std::string dni="31020644S";
  UsuarioReg aux(" ", " ", " ", " ", 0);
  File_datos fd;
  aux=fd.obtener_datos(dni);

  
  EXPECT_EQ("31020644S", aux.get_dni());
  EXPECT_EQ("Pepe Federico García", aux.get_nombrecompleto());
  EXPECT_EQ("login", aux.get_uco_login());
  EXPECT_EQ("mail@mail.mail", aux.get_email());
  EXPECT_EQ("10", aux.get_id());

}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}