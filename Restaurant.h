#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <bits/stdc++.h>
#include "Employee.h"
using std::string;

class Restaurant {
public:
    struct EmployeeSalary{
        string Name;
        double salary;
    };

    int getNumberOfEmployees() const {
        return _employees.size();
    }

    // If Employee doesn't exist- return -1
    int getEmployeeId(string& name) const {
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            return it->second.getId();
        }
        return -1;
    }

    // If Employee doesn't exist- return -1
    double calculateMonthlySalary(string& name) const{
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            return it->second.calculateMonthlySalary();
        }
        return -1;
    }

    // If Employee doesn't exist- return -1
    double endMonthForOne(string& name){
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            return it->second.endMonth();
        }
        return -1;
    }

    std::vector<EmployeeSalary> endMonthForAll(){
        std::vector<EmployeeSalary> summary;
        double total = 0;
        for (auto &it : _employees){
            summary.push_back({it.first, it.second.endMonth()});
            total += summary[summary.size()].salary;
        }
        summary.push_back({"Total: ", total});
        return summary;
    }

    void printScheduleForOne(string& name) const {
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            it->second.printSchedule();
        }
    }

    void printScheduleForAll() const {
        for (auto &it : _employees){
            std::cout << "==============" << it.second.getId() << "==============" << std::endl;
            it.second.printSchedule();
            std::cout << std::endl;
        }
    }

    void markEntrance(string& name) const {
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            it->second.markEntrance();
        }
    }

    void markQuit(string& name){
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            it->second.markQuit();
        }
    }

    void addNewEmployee(string& name, Role role, double salary){
        _employees.insert({name, Employee(_employees.size()+1 ,name, role, salary)});
    }

    void removeEmployee(string& name){
        _employees.erase(name);
    }

    void setSalary(string& name, double salary){
        auto it = _employees.find(name);
        if (it != _employees.end()){
            it->second.setSalary(salary);
        }
    }

    void setRole(string& name, Role role){
        auto it = _employees.find(name);
        if (it != _employees.end()){
            it->second.setRole(role);
        }
    }

private:
    std::map<string, Employee> _employees;
};

#endif //RESTAURANT_H
