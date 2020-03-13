cmake_minimum_required(VERSION "3.17.0")


project("work2.c")

add_executable("${PROJECT_NAME}" "work2.c.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

install(FILES "work2.c.cpp" DESTINATION src)