#include "Table.h"
Table::Table() : _available(true), _bill(0) {}

bool Table::isAvailable() const {
    return _available;
}

bool Table::seatCustomer() {
    return _available = false;
}

double Table::getCurrentBill() const {
    return _bill;
}

double Table::getFinalBill() {
    double bill = _bill;
    _bill = 0;
    _available = true;
    int iteration = _orders.size();
    for (int i=0; i<iteration; i++){
        std::cout << *_orders.front();
        _orders.pop();
    }
    return bill;
}

void Table::orderDish(Dish *dish) {
    _orders.push(dish);
    _bill += dish->getPrice();
}

void Table::getCredit(double credit) {
    _bill -= credit;
}


Tables::Tables(int capacity) : _customers(0), _expensive(0) {
    for (int i=1; i<= capacity; i++){
        _tables.insert({i,Table()});
        _available.push(i);
    }
}

void Tables::increaseCapacity(int factor) {
    if (factor >= 0) {
        unsigned int old_capacity = _tables.size() + 1;
        unsigned int new_capacity = _tables.size() + factor;
        for (unsigned int i=old_capacity; i<= new_capacity; i++){
            _tables.insert({i,Table()});
            _available.push(i);
        }
    }
}

unsigned int Tables::getNumOfCustomer() const {
    return _tables.size() - _available.size();
}

unsigned int Tables::getNumOfAvailableTables() const {
    return _available.size();
}

unsigned int Tables::seatCustomer() {
    if (!_available.empty()){
        int table_number = _available.top();
        _tables.find(table_number)->second.seatCustomer();
        _available.pop();
        _customers++;
        return table_number;
    }
    return -1;
}

double Tables::getFinalBill(unsigned int num) {
    _available.push(num);
    double bill = _tables.find(num)->second.getFinalBill();
    if (_expensive < bill)
        _expensive = bill;
    return bill;
}

double Tables::getCurrentBill(int num) const {
    const Table* table = &_tables.find(num)->second;
    if (!table->isAvailable())
        return table->getCurrentBill();
    return -1;
}

void Tables::giveCredit(int num, double credit) {
    Table* table = &_tables.find(num)->second;
    if (!table->isAvailable())
        table->getCredit(credit);
}

bool Tables::orderDish(int num_table, Dish *dish) {
    Table* table = &_tables.find(num_table)->second;
    if (!table->isAvailable()) {
        table->orderDish(dish);
        return true;
    }
    return false;
}

unsigned int Tables::getCapacity() const {
    return _tables.size();
}

unsigned int Tables::getTotalNumberOfCustomers() const {
    return _customers;
}

double Tables::getMostExpensiveBill() const {
    return _expensive;
}
