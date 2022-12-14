add_executable(app_main app_main.cc)
target_link_libraries(app_main PUBLIC curso usuarioReg participante filedatos filelogin filecurso admin)
target_include_directories(app_main PUBLIC
                    ${CMAKE_CURRENT_LIST_DIR} 
                    ${PROJECT_SOURCE_DIR}/src/curso
                    ${PROJECT_SOURCE_DIR}/src/usuarioReg
                    ${PROJECT_SOURCE_DIR}/src/participante
                    ${PROJECT_SOURCE_DIR}/src/filedatos
                    ${PROJECT_SOURCE_DIR}/src/filelogin
                    ${PROJECT_SOURCE_DIR}/src/filecurso
                    ${PROJECT_SOURCE_DIR}/src/admin)


                    


