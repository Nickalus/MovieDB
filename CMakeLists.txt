Cmake_Minimum_Required(VERSION 2.8)

Project(MovieDB)

#C++ flags

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -g")

# Sources
SET(PROJECT_SOURCES
    main.cpp
    MovieDB.cpp
    DBObject.cpp
    Actor.cpp
    Genre.cpp
    Movie.cpp
   )

SET(PROJECT_HEADERS
    MovieDB.hpp
    DBObject.hpp
    Actor.hpp
    Genre.hpp
    Movie.hpp
    )

Add_Executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})
Target_Link_Libraries(${PROJECT_NAME} mysqlclient)
