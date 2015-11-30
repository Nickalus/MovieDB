#ifndef DBOBJECT_HPP
#define DBOBJECT_HPP

#include <mysql/mysql.h>
#include <string>

class DBObject
{
  public:
    DBObject(MYSQL *);

    virtual void Add() = 0;
    virtual void Update() = 0;

  protected:
    void Query(std::string);

    virtual void Help() = 0;
    virtual void View() = 0;

  protected:
    //Connector for the database
    MYSQL * mConnector;
    //Results from the database
    MYSQL_RES * mRes;
    //The statement for the prepared statements
    MYSQL_STMT * mStatement;
};

#endif
