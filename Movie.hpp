#ifndef MOVIE_HPP
#define  MOVIE_HPP

#include <mysql/mysql.h>
#include <string>

#include "DBObject.hpp"

class Movie : public DBObject
{
  public:
    Movie(MYSQL *);

    void Add();
    void Update();

  protected:
    void Help();
    void View();
};

#endif
