add_library(visitante visitante.cc visitante.h)
target_link_libraries(visitante PUBLIC curso)
target_include_directories(visitante PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso
                          )
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt