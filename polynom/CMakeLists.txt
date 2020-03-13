cmake_minimum_required(VERSION "3.17.0")


project("LabC.c")

add_executable("${PROJECT_NAME}" "LabC.c.cpp")

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)

install(FILES "LabC.c.cpp" DESTINATION src)