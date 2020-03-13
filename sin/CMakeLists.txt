cmake_minimum_required(VERSION "3.17.0")


project("LabC2.c")

add_executable("${PROJECT_NAME}" "LabC2.c.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

install(FILES "LabC2.c.cpp" DESTINATION src)