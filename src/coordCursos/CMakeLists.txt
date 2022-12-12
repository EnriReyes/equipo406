add_library(coordCursos coordCursos.cc coordCursos.h)
target_link_libraries(coordCursos PUBLIC curso usuarioreg)
target_include_directories(coordCursos PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso
                          ${PROJECT_SOURCE_DIR}/src/usuarioreg
                          )
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt