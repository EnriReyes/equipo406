add_library(filelogin filelogin.cc filelogin.h)
target_link_libraries(filelogin PUBLIC curso)
target_include_directories(filelogin PUBLIC
                          ${CMAKE_CURRENT_LIST_DIR}
                          ${PROJECT_SOURCE_DIR}/src/curso
                          )
# ${CMAKE_CURRENT_LIST_DIR} dir. de este CMakeLisis.txt