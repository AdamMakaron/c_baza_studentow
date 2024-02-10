#include "DatabaseManager.h"
#include <iostream>

using namespace std;

int main() {
    DatabaseManager::initialize("C:/Users/Macarena/Desktop/Laborki/123123/Students.db");

    int choice = -1;
    while (choice != 0) {
        cout << "1. Create Table" << endl;
        cout << "2. Insert Data" << endl;
        cout << "3. Delete Data" << endl;
        cout << "4. Update Data" << endl;
        cout << "5. Select Data" << endl;
        cout << "6. Show Tables" << endl;
        cout << "7. Show Data" << endl;
        cout << "8. Remove Table" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            DatabaseManager::createTable();
            break;
        case 2:
            DatabaseManager::insertData();
            break;
        case 3:
            DatabaseManager::deleteData();
            break;
        case 4:
            DatabaseManager::updateData();
            break;
        case 5:
            DatabaseManager::selectData();
            break;
        case 6:
            DatabaseManager::showTables();
            break;
        case 7:
            DatabaseManager::showData();
            break;
        case 8:
            DatabaseManager::removeTable();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }

    return 0;
}
