cmake_minimum_required(VERSION 3.23)
project(MIPT)

set(CMAKE_CXX_STANDARD 14)



#set(SFML_DIR ../../SFML-2.5.1/lib/cmake/SFML)
#find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


add_executable(MIPT MIPT/DandD/main.cpp) #MIPT/DandD/main.cpp MIPT/DandD/Map.h MIPT/DandD/Map.cpp MIPT/DandD/Room.h MIPT/DandD/Room.cpp)

#target_link_libraries(MIPT sfml-graphics sfml-audio)
