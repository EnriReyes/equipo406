# GTest include code for fetch content over the internet 
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)
# End GTest include code 

#Testing filedatos library
add_executable(filedatos_test filedatos_test.cc)
target_link_libraries(filedatos_test
PRIVATE GTest::GTest filedatos)
add_test(filedatos_gtests filedatos_test)
#
