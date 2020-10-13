#include "Restaurant.h"

Restaurant::Restaurant(int capacity) : _tables(capacity), _total_account(0), _monthly_account(0),
                                       _daily_account(0), _best_selling(nullptr) {}

int Restaurant::getNumberOfEmployees() const {
    return _employees.size();
}

unsigned int Restaurant::getEmployeeId(string &name) const {
    auto it = _employees.find(name);
    if (it != _employees.end()) {
        return it->second.getId();
    }
    return -1;
}

double Restaurant::calculateMonthlySalary(string &name) const {
    auto it = _employees.find(name);
    if (it != _employees.end()) {
        return it->second.calculateMonthlySalary();
    }
    return -1;
}

void Restaurant::printScheduleForOne(string &name) const {
    auto it = _employees.find(name);
    if (it != _employees.end()) {
        it->second.printSchedule(name);
    }
}

void Restaurant::printScheduleForAll() const {
    for (auto &it : _employees){
        it.second.printSchedule(it.first);
        std::cout << std::endl;
    }
}

void Restaurant::markEntrance(string &name) {
    auto it = _employees.find(name);
    if (it != _employees.end()) {
        it->second.markEntrance();
    }
}

void Restaurant::markQuit(string &name) {
    auto it = _employees.find(name);
    if (it != _employees.end()) {
        it->second.markQuit();
    }
}

void Restaurant::resetWorkTimeForOne(string &name) {
    auto it = _employees.find(name);
    if (it != _employees.end()) {
        it->second.resetWorkTime();
    }
}

void Restaurant::resetWorkTimeForAll() {
    for (auto &it : _employees){
        it.second.resetWorkTime();
        std::cout << std::endl;
    }
}

void Restaurant::addNewEmployee(string &name, Role role, double salary) {
    _employees.insert({std::move(name), Employee(_employees.size()+1, role, salary)});
}

void Restaurant::removeEmployee(string &name) {
    std::remove((std::to_string(this->getEmployeeId(name))+"entrance.txt").c_str());
    std::remove((std::to_string(this->getEmployeeId(name))+".txt").c_str());
    _employees.erase(name);

}

void Restaurant::setSalary(string &name, double salary) {
    auto it = _employees.find(name);
    if (it != _employees.end()){
        it->second.setSalary(salary);
    }
}

void Restaurant::setRole(string &name, Role role) {
    auto it = _employees.find(name);
    if (it != _employees.end()){
        it->second.setRole(role);
    }
}

void Restaurant::addNewCategory(string &name) {
    _menu.insert({std::move(name), Category()});
}

void Restaurant::removeCategory(string &name) {
    _menu.erase(name);
}

void Restaurant::addDish(string &category, string &dish, string &description, int rank, double price) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.addDish(dish, description, rank, price);
}

void Restaurant::addDishWithProducts(string &category, string &dish, string &description,
                                     std::unordered_set<Product> &products, int rank, double price) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.addDishWithProducts(dish, description, products, rank, price);
}

void Restaurant::removeDish(string &category, string &dish) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.removeDish(dish);
}

void Restaurant::addProductToDish(string &category, string &dish, Product product) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.addProductToDish(dish, product);
}

void Restaurant::removeProductFromDish(string &category, string &dish, Product product) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.removeProductFromDish(dish, product);
}

void Restaurant::changeDishName(string &category, string &dish, string &name) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.changeDishName(dish, name);
}

void Restaurant::changeDishDescription(string &category, string &dish, string &description) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.changeDishDescription(dish, description);
}

void Restaurant::outOfVariety(string &category, string &dish) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.outOfVariety(dish);
}

void Restaurant::putInVariety(string &category, string &dish) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.putInVariety(dish);
}

void Restaurant::setDishPrice(string &category, string &dish, double price) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.setDishPrice(dish, price);
}

void Restaurant::setDishRank(string &category, string &dish, int rank) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.setDishRank(dish, rank);
}

void Restaurant::printMenu() const {
    for (auto& it : _menu) {
        it.second.printCategory(it.first);
    }
}

void Restaurant::printDishProduct(string &category, string &dish) const {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.printProductsDish(dish);
}

void Restaurant::printBestDishes(string &category, int k) {
    auto i = _menu.find(category);
    if (i != _menu.end())
        i->second.printBestDishes(k);
}

int Restaurant::getDishRank(string &category, string &dish) const {
    auto i = _menu.find(category);
    if (i != _menu.end())
        return i->second.getDishRank(dish);
    else
        return -1;
}

double Restaurant::getDishPrice(string &category, string &dish) const {
    auto i = _menu.find(category);
    if (i != _menu.end())
        return i->second.getDishPrice(dish);
    else
        return -1;
}

void Restaurant::increaseCapacity(int factor) {
    _tables.increaseCapacity(factor);
}

unsigned int Restaurant::getNumOfCustomer() const {
    return _tables.getNumOfCustomer();
}

unsigned int Restaurant::getNumOfAvailableTables() const {
    return _tables.getNumOfAvailableTables();
}

unsigned int Restaurant::seatCustomer() {
    return _tables.seatCustomer();
}

double Restaurant::getFinalBill(unsigned int num) {
    if (num < 1 || num > _tables.getCapacity()) return -1;
    std::cout << "============== Bill ==============" << std::endl;
    double bill = _tables.getFinalBill(num);
    std::cout << std::endl << "============== Total to pay: " << bill << " ==============" << std::endl << std::endl;
    _daily_account += bill;
    return bill;
}

double Restaurant::getCurrentBill(int num) const {
    return _tables.getCurrentBill(num);
}

int Restaurant::getNumOfOrders() const {
    return _orders.size();
}

void Restaurant::giveCredit(int num, double credit) {
    _tables.giveCredit(num, credit);
}

void Restaurant::orderDish(int num, string &category, string &dish) {
    auto cat = _menu.find(category);
    if (cat == _menu.end()) return;
    Dish* ordered = cat->second.getDish(dish);
    if (!ordered || !ordered->isAvailable()) return;
    if (_tables.orderDish(num, ordered)) {
        ordered->orderDish();
        if (!_best_selling || ordered->getNumberOfSales() > _best_selling->getNumberOfSales())
            _best_selling = ordered;
        _orders.push(ordered);
    }
}

void Restaurant::supplyDish() {
    if (!_orders.empty())
        _orders.pop();
}

void Restaurant::endDay() {
    _monthly_account += _daily_account;
    _daily_account = 0;
}

void Restaurant::endMonth() {
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

double Restaurant::getDailyAccount() const {
    return _daily_account;
}

double Restaurant::getMonthlyAccount() const {
    return _monthly_account;
}

double Restaurant::getTotalAccount() const {
    return _total_account;
}

string Restaurant::getBestSellingDish() const {
    if (_best_selling)
        return _best_selling->getName();
    return "The menu is empty";
}

unsigned int Restaurant::getTotalNumberOfCustomers() const {
    return _tables.getTotalNumberOfCustomers();
}

double Restaurant::getMostExpensiveBill() const {
    return _tables.getMostExpensiveBill();
}
