#ifndef TABLE_H
#define TABLE_H
#include <bits/stdc++.h>
#include "Dish.h"
using std::string;

class Table{
public:
    explicit Table(): _available(true), _bill(0) {}

    bool isAvailable() const {
        return _available;
    }

    bool seatCustomer() {
        return _available = false;
    }

    double getCurrentBill() const {
        return _bill;
    }

    double getFinalBill() {
        double bill = _bill;
        _bill = 0;
        _available = true;
        for (int i=0; i<_orders.size(); i++){
            std::cout << *_orders.front();
            _orders.pop();
        }
        return bill;
    }

    void orderDish(Dish* dish){
        _orders.push(dish);
        _bill += dish->getPrice();
    }

    void getCredit(double credit){
        _bill -= credit;
    }

private:
    bool _available;
    std::queue<Dish*> _orders;
    double _bill;
};

class Tables{
public:
    explicit Tables(unsigned int capacity): _customers(0), _expensive(0) {
        for (int i=1; i<= capacity; i++){
            _tables.insert({i,Table()});
            _available.push(i);
        }
    }

    // Set capacity by factor: new_capacity = old_capacity + factor (factor can be negative)
    void setCapacity(int factor) {
        if (factor >= 0) {
            for (unsigned int i=_tables.size() + 1; i<= _tables.size() + factor; i++){ //TODO check!
                _tables.insert({i,Table()});
                _available.push(i);
            }
        }
        else if (getNumOfAvailableTables() >= factor){
            for (int i=0; i<std::abs(factor); i++) {
                int available = _available.top();
                _tables.erase(available);
                _available.pop();
            }
        }
    }

    unsigned int getNumOfCustomer() const {
        return _tables.size() - _available.size();
    }

    unsigned int getNumOfAvailableTables() const {
        return _available.size();
    }

    void seatCustomer(){
        if (!_available.empty()){
            _tables.find(_available.top())->second.seatCustomer();
            _available.pop();
            _customers++;
        }
    }

    double getFinalBill(int num){
        _available.push(num);
        double bill = _tables.find(num)->second.getFinalBill();
        if (_expensive < bill)
            _expensive = bill;
        return bill;
    }

    double getCurrentBill(int num) const {
        Table table = _tables.find(num)->second;
        if (!table.isAvailable())
            return table.getCurrentBill();
        return -1;
    }

    void giveCredit(int num, double credit){
        Table table = _tables.find(num)->second;
        if (!table.isAvailable())
             table.getCredit(credit);
    }

    bool orderDish(int num_table, Dish* dish){
        Table table = _tables.find(num_table)->second;
        if (!table.isAvailable()) {
            table.orderDish(dish);
            return true;
        }
        return false;
    }

    unsigned int getNumberOfCustomers() const {
        return _customers;
    }

    unsigned int getMostExpensiveBill() const {
        return _expensive;
    }

private:
    std::unordered_map<int, Table> _tables;
    std::stack<int> _available;
    unsigned int _customers;
    unsigned int _expensive;
};

#endif //TABLE_H
