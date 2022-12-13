#include "usuarioReg.h"
#include "gtest/gtest.h"



TEST(UsuarioRegistrado, constructor) {
  UsuarioReg aux("dni", "nombrecompleto", "email", "uco_login", 0);

  EXPECT_EQ("dni",aux.get_dni());
  EXPECT_EQ("nombrecompleto",aux.get_nombrecompleto());
  EXPECT_EQ("email",aux.get_email());
  EXPECT_EQ("uco_login",aux.get_uco_login());
  EXPECT_EQ(0,aux.get_id());
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
