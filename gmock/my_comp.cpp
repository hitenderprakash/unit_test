#include <string>
#include "db_interface.h"
#include "my_comp.h"

int myComp::init(){
    if(db){
        return db->login(username,password);
    }
    return 0;
}

int myComp::stop(){
    if(db){
        return db->logout(username);
    }
    return 0;
}