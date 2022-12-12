add_library(filecurso filecurso.cc filecurso.h)
target_link_libraries(filecurso PUBLIC curso)
target_include_directories(filecurso PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso
                          )
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt