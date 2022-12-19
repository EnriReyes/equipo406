# GTest include code for fetch content over the internet 
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
# End GTest include code 

#Testing filedatos library
add_executable(filedatos_test filedatos_test.cc)
target_link_libraries(filedatos_test
PRIVATE GTest::GTest filedatos usuarioReg)
add_test(filedatos_gtests filedatos_test)
#
#Testing usuarioreg library
add_executable(usuarioReg_test usuarioReg_test.cc)
target_link_libraries(usuarioReg_test
PRIVATE GTest::GTest usuarioReg)
add_test(usuarioReg_gtests usuarioReg_test)
#

add_executable(filecurso_test filecurso_test.cc)
target_link_libraries(filecurso_test
PRIVATE GTest::GTest filecurso curso)
add_test(filecurso_gtests filecurso_test)
#
#Testing filelogin library
add_executable(filelogin_test filelogin_test.cc)
target_link_libraries(filelogin_test
PRIVATE GTest::GTest filelogin)
add_test(filelogin_gtests filelogin_test)
#
