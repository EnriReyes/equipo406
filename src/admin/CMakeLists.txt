add_library(admin admin.cc admin.h)
target_link_libraries(admin PUBLIC coordCursos filecurso)
target_include_directories(admin PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/coordCursos
                          ${PROJECT_SOURCE_DIR}/src/filecurso
                          )
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt