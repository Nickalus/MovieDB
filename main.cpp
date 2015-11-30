#include "MovieDB.hpp"

#include <iostream>
#include <string>
#include <cstdio>

int main(int argc, char *argv[])
{
  MovieDB * movieDB = new MovieDB();

  if(movieDB->Connect())
  {
    movieDB->Run();
  }
}
