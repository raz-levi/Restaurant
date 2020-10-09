#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <bits/stdc++.h>
using std::string;
enum Role {waiter=0, cashier, chef, hostess, cleaner, delivery, barman};

class Employee {
public:
    Employee(unsigned int id, Role role, double salary): _id(id), _role(role), _salary(salary), _time(0), _entered(false){
    }

    unsigned int getId() const {
        return _id;
    }

    void markEntrance() {
        if (_entered) return;
        _work_time.emplace_back(std::time(nullptr));
        _entered = true;
    }

    void markQuit() {
        if (!_entered) return;
        _work_time.back().quit = std::time(nullptr);
        _time += _work_time.back().quit-_work_time.back().entrance;
        _entered = false;
    }

    void printSchedule(const string& name) const {
        std::cout << "============== Name: " << name<< ", Id: " << _id << ", Role: " << this->roleToString()
        << ", Per hour: " << _salary << ", Total to pay: " << this->calculateMonthlySalary() << " =============="
        << std::endl;

        for (auto it : _work_time){
            std::cout << "Entrance: " << std::asctime(std::localtime(&it.entrance));
            if (it.quit != 0) std::cout << "Quit: " << std::asctime(std::localtime(&it.quit)) << std::endl;
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
        this->resetWorkTime();
        return salary;
    }

    void resetWorkTime() {
        _work_time.clear();
        _time = 0;
        _entered = false;
    }

private:
    unsigned int _id;
    Role _role;
    double _salary;
    double _time;
    bool _entered;

    struct WorkTime{
        std::time_t entrance;
        std::time_t quit;
        explicit WorkTime(std::time_t time): entrance(time), quit(0) {}
    };
    std::list<WorkTime> _work_time;
    
    string roleToString() const {
        switch (_role) {
            case waiter:
                return "Waiter";
            case cashier:
                return "Cashier";
            case chef:
                return "Chef";
            case hostess:
                return "Hostess";
            case cleaner:
                return "Cleaner";
            case delivery:
                return "Delivery";
            default:
                return "Barman";
        }
    }
};

#endif //EMPLOYEE_H