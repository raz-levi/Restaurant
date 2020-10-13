#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <bits/stdc++.h>
#include "Employee.h"
#include "Dish.h"
#include "Table.h"

class Restaurant {
public:
    explicit Restaurant(unsigned int capacity = 5): _tables(capacity), _total_account(0), _monthly_account(0),
    _daily_account(0), _best_selling(nullptr) {} // TODO erase default capacity

    // ================== Employees ==================
    int getNumberOfEmployees() const {
        return _employees.size();
    }

    // If Employee doesn't exist- return -1
    unsigned int getEmployeeId(string& name) const {
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

    // ================== Menu ==================
    void addNewCategory(string& name){
        _menu.insert({std::move(name), Category()});
    }

    void removeCategory(string& name){
        _menu.erase(name);
    }

    void addDish(string& category, string& dish, string& description, int rank, double price){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.addDish(dish, description, rank, price);
    }

    void addDishWithProducts(string& category, string& dish, string& description, std::unordered_set<Product>& products,
                             int rank, double price){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.addDishWithProducts(dish, description, products, rank, price);
    }

    void removeDish(string& category, string& dish){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.removeDish(dish);
    }

    void addProductToDish(string& category, string& dish, Product product){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.addProductToDish(dish, product);
    }

    void removeProductFromDish(string& category, string& dish, Product product){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.removeProductFromDish(dish, product);
    }

    void changeDishName(string& category, string& dish, string& name){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.changeDishName(dish, name);
    }

    void changeDishDescription(string& category, string& dish, string& description){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.changeDishDescription(dish, description);
    }

    void outOfVariety(string& category, string& dish){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.outOfVariety(dish);
    }

    void putInVariety(string& category, string& dish){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.putInVariety(dish);
    }

    void setDishPrice(string& category, string& dish, double price){
        auto i = _menu.find(category);
        if (i != _menu.end())
          i->second.setDishPrice(dish, price);
    }

    void setDishRank(string& category, string& dish, int rank){
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.setDishRank(dish, rank);
    }

    void printMenu() const {
        for (auto& it : _menu) {
            it.second.printCategory(it.first);
        }
    }

    void printDishProduct(string& category, string& dish) const {
        auto i = _menu.find(category);
        if (i != _menu.end())
           i->second.printProductsDish(dish);
    }

    void printBestDishes(string& category, unsigned int k) {
        auto i = _menu.find(category);
        if (i != _menu.end())
            i->second.printBestDishes(k);
    }

    // If Dish doesn't exist- return -1
    int getDishRank(string& category, string& dish) const {
        auto i = _menu.find(category);
        if (i != _menu.end())
            return i->second.getDishRank(dish);
        else
            return -1;
    }

    // If Dish doesn't exist- return -1
    double getDishPrice(string& category, string& dish) const {
        auto i = _menu.find(category);
        if (i != _menu.end())
            return i->second.getDishPrice(dish);
        else
            return -1;
    }

    // ================== Tables ==================

    void setCapacity(int factor) {
        _tables.setCapacity(factor);
    }

    unsigned int getNumOfCustomer() const {
        return _tables.getNumOfCustomer();
    }

    unsigned int getNumOfAvailableTables() const {
        return _tables.getNumOfAvailableTables();
    }

    void seatCustomer(){
        _tables.seatCustomer();
    }

    double getFinalBill(int num){
        std::cout << "============== Bill ==============" << std::endl;
        double bill = _tables.getFinalBill(num);
        std::cout << std::endl << "============== Total to pay: " << bill << " ==============" << std::endl;
        _daily_account += bill;
        return bill;
    }

    // return -1 if table is available
    double getCurrentBill(int num) const {
        return _tables.getCurrentBill(num);
    }

    int getNumOfOrders(int num) const {
        return _orders.size();
    }

    void giveCredit(int num, double credit){
        _tables.giveCredit(num, credit);
    }

    void orderDish(int num, string& category, string& dish){
        auto cat = _menu.find(category);
        if (cat == _menu.end()) return;
        Dish* ordered = cat->second.getDish(dish);
        if (!ordered || !ordered->isAvailable()) return;
        if (_tables.orderDish(num, ordered)) {
            ordered->orderDish();
            if (ordered->getNumberOfSales() > _best_selling->getNumberOfSales())
                _best_selling = ordered;
            _orders.push(ordered);
        }
    }

    void supplyDish(){
        _orders.pop();
    }

    // ================== Finance  ==================

    void endDay(){
        _monthly_account += _daily_account;
        _daily_account = 0;
    }

    void endMonth(){
        std::cout << "============== Employees Report ==============" << std::endl;
        double total = 0;
        for (auto &it : _employees){
            double monthly_salary = it.second.endMonth();
            total += monthly_salary;
            std::cout << "Name: " << it.first << " | Salary: " << monthly_salary << std::endl << std::endl;
        }
        std::cout << "============== Monthly Report ==============" << std::endl;
        std::cout << "Total salaries: " << total << std::endl;
        std::cout << "Total costumers: " << _monthly_account << std::endl;
        _monthly_account -= total;
        std::cout << "Total this month: " << _monthly_account << std::endl;
        _total_account += _monthly_account;
        _monthly_account = 0;
    }

    double getDailyAccount() const {
        return _daily_account;
    }

    double getMonthlyAccount() const {
        return _monthly_account;
    }

    double getTotalAccount() const {
        return _total_account;
    }

    // ================== Statistics  ==================

    string getBestSellingDish() const {
        if (_best_selling)
            return _best_selling->getName();
        return "The menu is empty";
    }

    unsigned int getTotalNumberOfCustomers() const {
        return _tables.getNumOfCustomer();
    }

    unsigned int getMostExpensiveBill() const {
        return _tables.getMostExpensiveBill();
    }

private:
    std::unordered_map<string, Employee> _employees;
    std::unordered_map<string, Category> _menu;
    Tables _tables;
    std::queue<Dish*> _orders;

    double _total_account;
    double _monthly_account;
    double _daily_account;

    Dish* _best_selling;
};

#endif //RESTAURANT_H
