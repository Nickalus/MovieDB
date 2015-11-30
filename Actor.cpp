#include "Actor.hpp"

#include <string>
#include <iostream>

Actor::Actor(MYSQL * connector) : DBObject(connector)
{
}

void Actor::Add()
{
  std::string actor;

  std::cout << "Please add an actor (first name, last name, birthday, and gender (seperate by spaces): ";
  std::getline(std::cin, actor);

  std::string statement_string = "INSERT INTO Actor(first_name, last_name, birthday, gender) VALUES(?,?,?,?)";
  MYSQL_BIND param[3];

  if(mysql_stmt_prepare(mStatement, statement_string.c_str(), statement_string.size()) != 0)
  {
    print_stmt_error(mStatement, "Could not prepare INSERT statement");
    return;
  }

  memset((void *)param, 0, sizeof(param));

  std::string temp;
  std::istringstream iss(actor);

  iss >> temp;

  param[0].buffer_type = MYSQL_TYPE_STRING;
  param[0].buffer = (void *)temp.c_str();
  param[0].buffer_length = temp.size();
  param[0].is_null = 0;
}

void Actor::Update()
{

}

void Actor::Help()
{

}

void Actor::View()
{

}
