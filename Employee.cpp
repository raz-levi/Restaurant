#include "Employee.h"
unsigned int Employee::getId() const {
    return _id;
}

void Employee::markEntrance() {
    if (_entered) return;
    _work_time.emplace_back(std::time(nullptr));
    _entered = true;
}

void Employee::markQuit() {
    if (!_entered) return;
    _work_time.back().quit = std::time(nullptr);
    _time += _work_time.back().quit-_work_time.back().entrance;
    _entered = false;
}

void Employee::printSchedule(const string &name) const {
    std::cout << "============== Name: " << name<< ", Id: " << _id << ", Role: " << this->roleToString()
              << ", Per hour: " << _salary << ", Total to pay: " << this->calculateMonthlySalary() << " =============="
              << std::endl;

    for (auto it : _work_time){
        std::cout << "Entrance: " << std::asctime(std::localtime(&it.entrance));
        if (it.quit != 0) std::cout << "Quit: " << std::asctime(std::localtime(&it.quit)) << std::endl;
    }
}

void Employee::setSalary(double salary) {
    _salary = salary;
}

void Employee::setRole(Role new_role) {
    _role = new_role;
}

double Employee::calculateMonthlySalary() const {
    return _time * (_salary / 3600);
}

double Employee::endMonth() {
    double salary = this->calculateMonthlySalary();
    this->resetWorkTime();
    return salary;
}

void Employee::resetWorkTime() {
    _work_time.clear();
    _time = 0;
    _entered = false;
}

string Employee::roleToString() const {
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
