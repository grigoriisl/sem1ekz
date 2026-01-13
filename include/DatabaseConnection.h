#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <pqxx/pqxx>
#include <vector>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

template <typename T>
class DatabaseConnection {
private:
    shared_ptr<pqxx::connection> conn;
    pqxx::work* currentTransaction;

public:
    DatabaseConnection(const string& connectionString) {
        currentTransaction = nullptr;
        conn = make_shared<pqxx::connection>(connectionString);
        if (conn->is_open()) {
            cout << "Connected to database." << endl;
        }
    }

    vector<vector<string>> executeQuery(const string& sql) {
        vector<vector<string>> result;
        pqxx::nontransaction work(*conn);
        pqxx::result res = work.exec(sql);
        
        for (auto row : res) {
            vector<string> rowData;
            for (auto field : row) {
                rowData.push_back(field.c_str());
            }
            result.push_back(rowData);
        }
        return result;
    }

    bool executeNonQuery(const string& sql) {
        pqxx::work work(*conn);
        work.exec(sql);
        work.commit();
        return true;
    }

    void beginTransaction() {
        if (!currentTransaction) {
            currentTransaction = new pqxx::work(*conn);
        }
    }

    void commitTransaction() {
        if (currentTransaction) {
            currentTransaction->commit();
            delete currentTransaction;
            currentTransaction = nullptr;
        }
    }

    void rollbackTransaction() {
        if (currentTransaction) {
            currentTransaction->abort();
            delete currentTransaction;
            currentTransaction = nullptr;
        }
    }

    bool createFunction(const string& sql) {
        return executeNonQuery(sql);
    }

    bool createTrigger(const string& sql) {
        return executeNonQuery(sql);
    }

    string getTransactionStatus() {
        if (currentTransaction) return "active";
        return "inactive";
    }

    ~DatabaseConnection() {
        if (currentTransaction) delete currentTransaction;
        if (conn->is_open()) conn->close();
    }
};

#endif