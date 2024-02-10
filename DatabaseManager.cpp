#include "DatabaseManager.h"
#include <iostream>
#include <cstdlib>

using namespace std;

string DatabaseManager::databasePath = "";

void DatabaseManager::initialize(const string& dbPath) {
    databasePath = dbPath;
}

void DatabaseManager::createTable() {
    system("cls");
    string table_name;
    cout << "Enter Table Name: ";
    cin >> table_name;
    string sql = "CREATE TABLE IF NOT EXISTS '" + table_name + "'("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "Name TEXT NOT NULL, "
        "LNAME     TEXT NOT NULL, "
        "AGE       INT  NOT NULL, "
        "ADDRESS   CHAR(50), "
        "GRADE     CHAR(1) );";
    executeSQL(sql);
}

void DatabaseManager::insertData() {
    system("cls");
    string name;
    string table_name;
    string lname;
    string address;
    int age;
    float grade;
    cout << "Enter Table Name: ";
    cin >> table_name;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter last name: ";
    cin >> lname;
    cout << "Enter address: ";
    cin >> address;
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter grade: ";
    cin >> grade;

    string sql = "INSERT INTO '" + table_name + "' (NAME, LNAME, AGE, ADDRESS, GRADE) VALUES('" + name + "', '" + lname + "', '" + address + "', " + to_string(age) + ", " + to_string(grade) + "); ";
    executeSQL(sql);
}

void DatabaseManager::deleteData() {
    system("cls");
    string table_name;
    int id;
    cout << "Enter Table Name: ";
    cin >> table_name;
    cout << "Enter ID to delete: ";
    cin >> id;

    string sql = "DELETE FROM '" + table_name + "' WHERE ID = " + to_string(id) + ";";
    executeSQL(sql);
}

void DatabaseManager::updateData() {
    system("cls");
    string table_name;
    int id;
    string grade;
    cout << "Enter Table Name: ";
    cin >> table_name;
    cout << "Enter ID to update: ";
    cin >> id;
    cout << "Enter new grade: ";
    cin >> grade;

    string sql = "UPDATE '" + table_name + "' SET Grade = '" + grade + "' WHERE ID = " + to_string(id) + ";";
    executeSQL(sql);
}

void DatabaseManager::selectData() {
    system("cls");
    string table_name;
    cout << "Enter Table Name: ";
    cin >> table_name;
    string sql = "SELECT * FROM '" + table_name + "';";
    executeSQL(sql);
}

void DatabaseManager::showTables() {
    system("cls");
    string sql = "SELECT name FROM sqlite_master; "
        "WHERE type = 'table' AND name NOT LIKE 'sqlite_%';";
    executeSQL(sql);
}

void DatabaseManager::showData() {
    system("cls");
    string table_name;
    cout << "Enter table name to display its data: ";
    cin >> table_name;

    string sql = "SELECT * FROM " + table_name + ";";
    executeSQL(sql);
}

void DatabaseManager::removeTable() {
    system("cls");
    string table_name;
    cout << "Enter table name to remove: ";
    cin >> table_name;

    string sql = "DROP TABLE IF EXISTS " + table_name + ";";
    executeSQL(sql);
}

void DatabaseManager::executeSQL(const string& sql) {
    sqlite3* db;
    char* messageError;

    if (sqlite3_open(databasePath.c_str(), &db) == SQLITE_OK) {
        if (sqlite3_exec(db, sql.c_str(), callback, 0, &messageError) != SQLITE_OK) {
            cerr << "Error executing SQLite3 statement: " << messageError << endl;
            sqlite3_free(messageError);
        }
        else {
            cout << "Operation done successfully" << endl;
        }
        sqlite3_close(db);
    }
    else {
        cerr << "Failed to open DB" << endl;
    }
}

int DatabaseManager::callback(void* NotUsed, int argc, char** argv, char** azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << ": " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
    return 0;
}
