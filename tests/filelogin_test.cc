#include "filelogin.h"
#include "gtest/gtest.h"


TEST(filelogin, filelogin_buscar_usuario) {
  File_Login fl;
  int aux;
  aux=fl.buscar_usuario("login", "1234");
  EXPECT_EQ(1,aux);
  aux=fl.buscar_usuario("log", "X");
  EXPECT_EQ(-1, aux);
  aux=fl.buscar_usuario("prueba", "prueba");
  EXPECT_EQ(0, aux);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
