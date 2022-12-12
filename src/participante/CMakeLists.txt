add_library(participante participante.cc participante.h)
target_link_libraries(participante PUBLIC curso usuarioReg)
target_include_directories(curso PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso
                          ${PROJECT_SOURCE_DIR}/src/usuarioReg)
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt