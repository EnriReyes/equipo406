add_library(filedatos filedatos.cc filedatos.h)
target_link_libraries(filedatos PUBLIC usuarioReg filecurso)
target_include_directories(filedatos PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/usuarioReg
                          ${PROJECT_SOURCE_DIR}/src/filecurso
                          )
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt