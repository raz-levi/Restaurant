#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <bits/stdc++.h>
using std::string;
enum Role {waiter=0, cashier, chef, hostess, cleaner, delivery, barman};

class Employee {
public:
    Employee(unsigned int id, string& name, Role role, double salary): _id(id),
    _name(std::move(name)), _role(role), _salary(salary), _time(0){
        std::ofstream remember((std::to_string(_id)+"entrance.txt").c_str());
        std::ofstream employee((std::to_string(_id)+".txt").c_str());
        if (!employee || !remember) {
            throw FileError();
        }
    }
    ~Employee(){
        std::remove((std::to_string(_id)).c_str());
        std::remove((std::to_string(_id)+"entrance.txt").c_str());
    }


    int getId() const {
        return _id;
    }

    void markEntrance() const {
        std::ifstream check((std::to_string(_id)+"entrance").c_str());
        if (!check) {
            throw FileError();
        }
        if (!check.eof()) return; // TODO check if needs to earse the file
        std::ofstream remember((std::to_string(_id)+"entrance.txt").c_str());
        std::ofstream employee((std::to_string(_id)+".txt").c_str());
        if (!employee || !remember) {
            throw FileError();
        }
        std::time_t entrance_time = std::time(nullptr);
        remember << entrance_time;
        employee << "Entrance: " << std::asctime(std::localtime(&entrance_time))<< std::endl;
    }

    void markQuit() {
        std::ifstream remember((std::to_string(_id)+"entrance.txt").c_str());
        std::ofstream employee((std::to_string(_id)+".txt").c_str());
        if (!remember || !employee) {
            throw FileError();
        }
        if (remember.eof()) return; // TODO check if needs to earse the file
        std::time_t quit_time = std::time(nullptr);
        std::time_t entrance_time;
        remember >> entrance_time;
        _time += quit_time-entrance_time;
        employee << "Quit: " << std::asctime(std::localtime(&quit_time))<< std::endl;
        std::remove((std::to_string(_id)+"entrance.txt").c_str());
        std::ifstream temp((std::to_string(_id)+"entrance.txt").c_str());
    }

    void printSchedule() const {
        std::ifstream employee(std::to_string(_id).c_str());
        if (!employee) {
            throw FileError();
        }
        while (!employee.eof()) {
            char c;
            employee >> c;
            std::cout << c;
        }
    }

    void setSalary(double salary){
        _salary = salary;
    }

    void setRole(Role new_role){
        _role = new_role;
    }

    double calculateMonthlySalary() const {
        return _time * (_salary / 3600);
    }

    double endMonth() {
        double salary = this->calculateMonthlySalary();
        this->clearWorkTime();
        _time = 0;
        return salary;
    }

    void clearWorkTime() const {
        std::remove((std::to_string(_id)).c_str());
        std::remove((std::to_string(_id)+"entrance.txt").c_str());
        std::ofstream remember((std::to_string(_id)+"entrance.txt").c_str());
        std::ofstream employee((std::to_string(_id)+".txt").c_str());
        if (!employee || !remember) {
            throw FileError();
        }
    }


class FileError: public std::exception {
        const char * what() const noexcept override {
            return "File error";
        }
    };

private:
    int _id;
    string _name;
    Role _role;
    double _salary;
    double _time;
};

#endif //EMPLOYEE_H