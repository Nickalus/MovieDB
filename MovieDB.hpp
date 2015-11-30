#ifndef MOVIEDB_HPP
#define MOVIEDB_HPP

#include <mysql/mysql.h>
#include <string>

class MovieDB
{
  public:
    MovieDB();
    bool Connect();
    void Run();

  private:
    void Query(std::string);

    void Help();
    void Add(std::string);
    void Update(std::string);

    void Report();

  private:
    //Connector for the database
    MYSQL * mConnector;
    //Results from the database
    MYSQL_RES * mRes;
    //Location of the server
    std::string mServer;
    //The statement for the prepared statements
    MYSQL_STMT * mStatement;
};

#endif
