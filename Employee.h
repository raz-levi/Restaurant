#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <ctime>
#include <iostream>
#include <list>
using std::string;
enum Role {waiter=0, cashier, chef, hostess, cleaner, delivery, barman};

class Employee {
public:
    Employee(unsigned int id, Role role, double salary): _id(id), _role(role), _salary(salary), _time(0), _entered(false){
    }
    unsigned int getId() const;

    void markEntrance();

    void markQuit();

    void printSchedule(const string& name) const;

    void setSalary(double salary);

    void setRole(Role new_role);

    double calculateMonthlySalary() const;

    double endMonth();

    void resetWorkTime();

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
    
    string roleToString() const;
};

#endif //EMPLOYEE_H