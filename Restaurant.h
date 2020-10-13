/*
 * This project was written by Raz Levi.
 */
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include "Employee.h"
#include "Dish.h"
#include "Table.h"
using std::string;

class Restaurant {
public:
    explicit Restaurant(int capacity);

    // ================== Employees ==================
    int getNumberOfEmployees() const;

    // If Employee doesn't exist: return -1
    unsigned int getEmployeeId(string& name) const;

    // If Employee doesn't exist: return -1
    double calculateMonthlySalary(string& name) const;

    void printScheduleForOne(string& name) const;

    void printScheduleForAll() const;

    void markEntrance(string& name);

    void markQuit(string& name);

    void resetWorkTimeForOne(string& name);

    void resetWorkTimeForAll();

    void addNewEmployee(string& name, Role role, double salary);

    void removeEmployee(string& name);

    void setSalary(string& name, double salary);

    void setRole(string& name, Role role);

    // ================== Menu ==================
    void addNewCategory(string& name);

    void removeCategory(string& name);

    void addDish(string& category, string& dish, string& description, int rank, double price);

    void addDishWithProducts(string& category, string& dish, string& description, std::unordered_set<Product>& products,
                             int rank, double price);

    void removeDish(string& category, string& dish);

    void addProductToDish(string& category, string& dish, Product product);

    void removeProductFromDish(string& category, string& dish, Product product);

    void changeDishName(string& category, string& dish, string& name);

    void changeDishDescription(string& category, string& dish, string& description);

    void outOfVariety(string& category, string& dish);

    void putInVariety(string& category, string& dish);

    void setDishPrice(string& category, string& dish, double price);

    void setDishRank(string& category, string& dish, int rank);

    void printMenu() const;

    void printDishProduct(string& category, string& dish) const;

    void printBestDishes(string& category, int k);

    // If Dish doesn't exist- return -1
    int getDishRank(string& category, string& dish) const;

    // If Dish doesn't exist- return -1
    double getDishPrice(string& category, string& dish) const;

    // ================== Tables ==================

    void increaseCapacity(int factor);

    unsigned int getNumOfCustomer() const;

    unsigned int getNumOfAvailableTables() const;

    // return -1 if all tables are busy
    unsigned int seatCustomer();

    // return -1 if num is illegal
    double getFinalBill(unsigned int num);

    // return -1 if table is available
    double getCurrentBill(int num) const;

    int getNumOfOrders() const;

    void giveCredit(int num, double credit);

    void orderDish(int num, string& category, string& dish);

    void supplyDish();

    // ================== Finance  ==================

    void endDay();

    void endMonth();

    double getDailyAccount() const;

    double getMonthlyAccount() const;

    double getTotalAccount() const;

    // ================== Statistics  ==================

    string getBestSellingDish() const;

    unsigned int getTotalNumberOfCustomers() const;

    double getMostExpensiveBill() const;

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
