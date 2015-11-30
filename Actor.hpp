#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <mysql/mysql.h>

#include "DBObject.hpp"

class Actor : public DBObject
{
  public:
    Actor(MYSQL *);

    void Add();
    void Update();

  protected:
    void Help();
    void View();
};

#endif
