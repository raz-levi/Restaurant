#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <bits/stdc++.h>
#include "Employee.h"
#include "Category.h"

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
            double monthly_salary = it.second.endMonth();
            summary.push_back({it.first, monthly_salary});
            total += monthly_salary;
        }
        summary.push_back({"Total ", total});
        return summary;
    }

    void printScheduleForOne(string& name) const {
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            it->second.printSchedule(name);
        }
    }

    void printScheduleForAll() const {
        for (auto &it : _employees){
            it.second.printSchedule(it.first);
            std::cout << std::endl;
        }
    }

    void markEntrance(string& name) {
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

    void resetWorkTimeForOne(string& name){
        auto it = _employees.find(name);
        if (it != _employees.end()) {
            it->second.resetWorkTime();
        }
    }

    void resetWorkTimeForAll(){
        for (auto &it : _employees){
            it.second.resetWorkTime();
            std::cout << std::endl;
        }
    }

    void addNewEmployee(string& name, Role role, double salary){
        _employees.insert({std::move(name), Employee(_employees.size()+1, role, salary)});
    }

    void removeEmployee(string& name){
        std::remove((std::to_string(this->getEmployeeId(name))+"entrance.txt").c_str());
        std::remove((std::to_string(this->getEmployeeId(name))+".txt").c_str());
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

std::ostream& operator<<(std::ostream& os, const Restaurant::EmployeeSalary& employee) {
    return os << "Name: " << employee.Name << " | Salary: " << employee.salary << std::endl;
}

#endif //RESTAURANT_H
