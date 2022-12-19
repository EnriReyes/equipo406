#include "filedatos.h"
#include "usuarioReg.h"
#include "gtest/gtest.h"



TEST(Filedatos, filedatos_obtener_datos) {
  UsuarioReg aux(" ", " ", " ", " ", 0);
  File_datos fd;
  aux=fd.obtener_datos("31020644S");
  EXPECT_EQ("31020644S",aux.get_dni());
  EXPECT_EQ("Pepe Federico García",aux.get_nombrecompleto());
  EXPECT_EQ("mail@mail.mail",aux.get_email());
  EXPECT_EQ("login",aux.get_uco_login());
  EXPECT_EQ(1,aux.get_id());
  aux=fd.obtener_datos2("login");
  EXPECT_EQ("31020644S",aux.get_dni());
  EXPECT_EQ("Pepe Federico García",aux.get_nombrecompleto());
  EXPECT_EQ("mail@mail.mail",aux.get_email());
  EXPECT_EQ("login",aux.get_uco_login());
  EXPECT_EQ(1,aux.get_id());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
