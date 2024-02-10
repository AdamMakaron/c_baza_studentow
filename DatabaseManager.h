#pragma once
#include <sqlite3.h>
#include <string>

class DatabaseManager {
public:
    static void initialize(const std::string& dbPath);
    static void createTable();
    static void insertData();
    static void deleteData();
    static void updateData();
    static void selectData();
    static void showTables();
    static void showData();
    static void removeTable();

private:
    static std::string databasePath;
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
    static void executeSQL(const std::string& sql);
};
