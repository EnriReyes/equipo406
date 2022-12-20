# CMake generated Testfile for 
# Source directory: /home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests
# Build directory: /home/user/UNIVERSIDAD/IS/proyecto/equipo406/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(filedatos_gtests "filedatos_test")
set_tests_properties(filedatos_gtests PROPERTIES  _BACKTRACE_TRIPLES "/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;18;add_test;/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;0;")
add_test(usuarioReg_gtests "usuarioReg_test")
set_tests_properties(usuarioReg_gtests PROPERTIES  _BACKTRACE_TRIPLES "/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;24;add_test;/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;0;")
add_test(filecurso_gtests "filecurso_test")
set_tests_properties(filecurso_gtests PROPERTIES  _BACKTRACE_TRIPLES "/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;30;add_test;/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;0;")
add_test(filelogin_gtests "filelogin_test")
set_tests_properties(filelogin_gtests PROPERTIES  _BACKTRACE_TRIPLES "/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;36;add_test;/home/user/UNIVERSIDAD/IS/proyecto/equipo406/tests/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
