#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include "Dish.h"
using std::string;

class Table{
public:
    explicit Table();

    bool isAvailable() const;

    bool seatCustomer();

    double getCurrentBill() const;

    double getFinalBill();

    void orderDish(Dish* dish);

    void getCredit(double credit);

private:
    bool _available;
    std::queue<Dish*> _orders;
    double _bill;
};

class Tables{
public:
    explicit Tables(int capacity);

    // increase capacity by factor: new_capacity = old_capacity + factor (factor can not be negative)
    void increaseCapacity(int factor);

    unsigned int getNumOfCustomer() const;

    unsigned int getNumOfAvailableTables() const;

    // return -1 if all tables are busy
    unsigned int seatCustomer();

    double getFinalBill(unsigned int num);

    double getCurrentBill(int num) const;

    void giveCredit(int num, double credit);

    bool orderDish(int num_table, Dish* dish);

    unsigned int getCapacity() const;

    unsigned int getTotalNumberOfCustomers() const;

    double getMostExpensiveBill() const;

private:
    std::unordered_map<int, Table> _tables;
    std::stack<int> _available;
    unsigned int _customers;
    double _expensive;
};

#endif //TABLE_H
