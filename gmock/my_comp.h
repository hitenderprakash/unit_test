#include <string>
#include "db_interface.h"

class myComp{
    private:
    dbConnect *db;
    std::string username;
    std::string password;

    public:
    myComp(dbConnect *_db, const std::string& user, const std::string& pass):db(_db),username(user),password(pass){

    }
    int init();

    int stop();

};