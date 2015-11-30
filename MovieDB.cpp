#include "MovieDB.hpp"
#include "Actor.hpp"
#include "Movie.hpp"
#include "Genre.hpp"

#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>

////////////////////////////////////////////////////////////////////////////////
// Description: Constructor, does nothing other than run mysql_init
// Inputs: none
// Output: none
// Example: Project2 p2;
////////////////////////////////////////////////////////////////////////////////
MovieDB::MovieDB()
: mConnector(mysql_init(NULL)),
  mServer("mysql.cs.uky.edu")
{
  if(mConnector == NULL)
  {
    std::cerr << mysql_error(mConnector);
    exit(1);
  }
  else
  {
    std::cout << "Connected!" << std::endl;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Description: Establishes connection to the databse
// Inputs: none
// Output: true or false depending on if the connection was successful
// Example: Project2 p2;
//          if(p2.Connect)
//          {
//            //Loop
//          }
////////////////////////////////////////////////////////////////////////////////
bool MovieDB::Connect()
{
  if(!mysql_real_connect(mConnector, mServer.c_str(), "ntyo222", "u0442840", "ntyo222", 0, NULL, 0))
  {
    std::cerr << mysql_error(mConnector);

    return false;
  }

  return true;
}

void MovieDB::Run()
{
  std::string command = "Not Exit!";

  while(command.compare("exit") != 0)
  {
    std::cout << "Enter a command or type help: ";

    std::getline(std::cin, command);

    //Make all text lower case
    std::transform(command.begin(), command.end(), command.begin(), ::tolower);

    std::istringstream iss(command);

    //Loop till end of string
    while(iss)
    {
      iss >> command;

      //Test the command string for the correct command
      if(command.compare("add") == 0)
      {
        iss >> command;

        MovieDB::Add(command);
      }
      else if(command.compare("update") == 0)
      {
        iss >> command;

        MovieDB::Update(command);
      }
      else if(command.compare("help") == 0)
      {
        MovieDB::Help();
      }
      else if(command.compare("exit") == 0)
      {
        std::cout << "Exiting" << std::endl;
      }
      else
      {
        std::cout << "Invild input!" << std::endl;
      }
    }
  }
}

void MovieDB::Help()
{

}

void MovieDB::Add(std::string s)
{
  //Test the command string for the correct command
  if(s.compare("actor") == 0)
  {
    //Smart pointer for memory management
    std::unique_ptr<Actor> actor(new Actor(mConnector));

    actor->Add();
    return;
  }
  else if(s.compare("movie") == 0)
  {
    std::unique_ptr<Movie> movie(new Movie(mConnector));

    movie->Add();
    return;
  }
  else if(s.compare("genre") == 0)
  {
    std::unique_ptr<Genre> genre(new Genre(mConnector));

    genre->Add();
    return;
  }
  else if(s.compare("back") == 0)
  {
    return;
  }
  else
  {
    std::cout << "Invild input!" << std::endl;
  }
}

void MovieDB::Update(std::string s)
{
  //Test the command string for the correct command
  if(s.compare("actor") == 0)
  {
    //Smart pointer for memory management
    std::unique_ptr<Actor> actor(new Actor(mConnector));

    actor->Update();
    return;
  }
  else if(s.compare("movie") == 0)
  {
    std::unique_ptr<Movie> movie(new Movie(mConnector));

    movie->Update();
    return;
  }
  else if(s.compare("genre") == 0)
  {
    std::unique_ptr<Genre> genre(new Genre(mConnector));

    genre->Update();
    return;
  }
  else if(s.compare("back") == 0)
  {
    return;
  }
  else
  {
    std::cout << "Invild input!" << std::endl;
  }
}
