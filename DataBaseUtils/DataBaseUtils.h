#ifndef COCOS2DUTILS_DATABASEUTILS_H
#define COCOS2DUTILS_DATABASEUTILS_H

#include "cocos2d.h"
#include "../cocos2d/external/sqlite3/include/sqlite3.h"
USING_NS_CC;

class DataBaseUtils: Ref
{
public:
    static DataBaseUtils* getInstance();

    bool open();
    bool close();

    sqlite3 *db() { return _db; }
    const std::string &db_name() const { return _db_name; }
    int status_code() { return  _status_code; }
    const char* status_msg() const { return sqlite3_errmsg(_db); }

CC_CONSTRUCTOR_ACCESS:
    DataBaseUtils();
    DataBaseUtils(const DataBaseUtils &obj);
    DataBaseUtils &operator=(const DataBaseUtils &obj);
    ~DataBaseUtils();

private:
    std::string _db_name;
    std::string _db_path;
    int _status_code;
    sqlite3 *_db;

    static DataBaseUtils *_instance;
};

#endif //COCOS2DUTILS_DATABASEUTILS_H
