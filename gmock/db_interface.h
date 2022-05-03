#pragma once
#include <string>
class dbConnect{
    public:
    virtual int login(const std::string& username, const std::string& password) = 0;
    virtual int logout(const std::string& username) = 0;
};

