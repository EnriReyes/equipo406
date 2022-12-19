#include "filecurso.h"
#include "usuarioReg.h"
#include "gtest/gtest.h"
#include "curso.h"



TEST(filecurso, leer_datos_curso) {
  File_curso f;
  Curso c("Matematicas");
  

  EXPECT_TRUE(f.leer_curso(c));

  EXPECT_EQ("Este es el curso de Matematicas del sistema",c.get_descripcion());
  EXPECT_EQ("12/11/2022",c.get_fecha_inicio());
  EXPECT_EQ("01/04/2023",c.get_fecha_final());
  EXPECT_EQ(4,c.get_aforo());

  std::vector<std::string> v=c.get_ponentes();
    EXPECT_EQ("Paco",v[0]);
  EXPECT_EQ("Luis",v[1]);  
  EXPECT_EQ("Silvia",v[2]);  

  
}

TEST(filecurso, vector_cursos) {
    File_curso f;
  
    std::vector<std::string> v=f.get_vector_cursos();
    EXPECT_EQ("Matematicas",v[0]);
    EXPECT_EQ("Literatura",v[1]);  
    EXPECT_EQ("Biologia",v[2]);  

  
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}