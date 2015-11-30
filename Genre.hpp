#ifndef GENRE_HPP
#define GENRE_HPP

#include <mysql/mysql.h>
#include <string>

#include "DBObject.hpp"

class Genre : public DBObject
{
  public:
    Genre(MYSQL *);

    void Add();
    void Update();

  protected:
    void Help();
    void View();
};

#endif
