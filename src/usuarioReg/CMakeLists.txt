add_library(usuarioReg usuarioReg.cc usuarioReg.h)
target_link_libraries(usuarioReg PUBLIC curso)
target_include_directories(usuarioReg PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso
                          )
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt