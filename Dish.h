#ifndef DISH_H
#define DISH_H
#include <bits/stdc++.h>
using std::string;
using Product = string; // Assume operator==, operator<, operator<<

class Dish{
public:
    Dish(string& name, string& description, int rank, double price):
            _name(std::move(name)), _description(std::move(description)), _rank(rank), _price(price),
            _available(true), _sold(0) {}
    Dish(string& name, string& description, std::unordered_set<Product>& products, int rank, double price):
            _name(std::move(name)), _description(std::move(description)), _products(std::move(products)), _rank(rank),
            _price(price), _available(true), _sold(0) {}

    const string& getName() const {
        return _name;
    }

    const string& getDescription() const {
        return _description;
    }

    int getRank() const {
        return _rank;
    }

    double getPrice() const {
        return _price;
    }

    bool isAvailable() const {
        return _available;
    }

    void changeName(string& name){
        _name = std::move(name);
    }

    void changeDescription(string& description){
        _description = std::move(description);
    }

    void addProduct(Product& product){
        _products.insert(product);
    }

    void removeProduct(Product& product){
        _products.erase(product);
    }

    void setRank(int rank){
        _rank = rank;
    }

    void setPrice(double price){
        _price = price;
    }

    void outOfVariety(){
        _available = false;
    }

    void putInVariety(){
        _available = true;
    }

    void printProducts() const {
        for (auto& it : _products){
            std::cout << it << " ";
        }
        std::cout << std::endl;
    }

    void orderDish(){
        _sold++;
    }

    unsigned int getNumberOfSales() const {
        return _sold;
    }

    bool operator<(const Dish* other) const {
        if (_rank == other->_rank)
            return _name < other->_name;
        return _rank < other->_rank;
    }
    bool operator==(const string& name) const {
        return _name == name;
    }

private:
    string _name;
    string _description;
    std::unordered_set<Product> _products;
    int _rank;
    double _price;
    bool _available;
    unsigned int _sold;
};

std::ostream& operator<<(std::ostream& os, const Dish& dish) {
    return os << "Name: " << dish.getName() << std::endl << dish.getDescription() << std::endl << "Price: "
              << dish.getPrice() << std::endl << std::endl;
}

class Category{
public:
    ~Category(){
        for (auto& it : _dishes_details){
            delete it.second;
        }
    }

    // if dish doesn't exist- return null
    Dish* getDish(string& name) {
        auto it = _dishes_details.find(name);
        if (it == _dishes_details.end())
            return nullptr;
        return it->second;
    }

    // if dish doesn't exist- return null
    const Dish* getDish(string& name) const {
        auto it = _dishes_details.find(name);
        if (it == _dishes_details.end())
            return nullptr;
        return it->second;
    }

    void addDish(string& name, string& description, int rank, double price) {
        Dish* new_dish = new Dish(name, description, rank, price);
        _dishes_details.insert({new_dish->getName(), new_dish});
        _dishes.insert(std::lower_bound(_dishes.begin(), _dishes.end(), new_dish, pred), new_dish);

    }

    void addDishWithProducts(string& name, string& description, std::unordered_set<Product>& products, int rank, double price) {
        Dish* new_dish = new Dish(name, description, products, rank, price);
        _dishes_details.insert({new_dish->getName(), new_dish});
        _dishes.insert(std::lower_bound(_dishes.begin(), _dishes.end(), new_dish, pred), new_dish);
    }

    void removeDish(string& name){
        Dish* removed = getDish(name);
        if (!removed) return;
        for (auto it = std::lower_bound(_dishes.begin(), _dishes.end(), removed, pred);
        it != std::upper_bound(_dishes.begin(), _dishes.end(), removed, pred); it++)
            if ((*it)->getName() == name){
                _dishes.erase(it);
                break;
            }
        _dishes_details.erase(name);
        delete removed;
    }

    void changeDishName(string& name, string& new_name) {
        Dish* dish = this->getDish(name);
        if (!dish) return;
        _dishes_details.erase(name);
        dish->changeName(new_name);
        _dishes_details.insert({dish->getName(), dish});
    }

    void changeDishDescription(string& name, string& description) {
        Dish* dish = this->getDish(name);
        if (dish)
            dish->changeDescription(description);
    }

    void setDishPrice(string& name, double price) {
        Dish* dish = this->getDish(name);
        if (dish)
            dish->setPrice(price);
    }

    void setDishRank(string& name, int rank) {
        Dish* dish = getDish(name);
        for (auto it = std::lower_bound(_dishes.begin(), _dishes.end(), dish, pred);
             it !=std::upper_bound(_dishes.begin(), _dishes.end(), dish, pred); it++)
            if ((*it)->getName() == name){
                _dishes.erase(it);
                break;
            }
        dish->setRank(rank);
        _dishes.insert(std::lower_bound(_dishes.begin(), _dishes.end(), dish, pred), dish);
    }

    void addProductToDish(string& name, Product& product){
        Dish* dish = this->getDish(name);
        if (dish)
            dish->addProduct(product);
    }

    void removeProductFromDish(string& name, Product& product){
        Dish* dish = this->getDish(name);
        if (dish)
            dish->removeProduct(product);
    }

    void outOfVariety(string& name){
        Dish* dish = this->getDish(name);
        if (dish)
            dish->outOfVariety();
    }

    void putInVariety(string& name){
        Dish* dish = this->getDish(name);
        if (dish)
            dish->putInVariety();
    }

    void printCategory(const string& name) const {
        std::cout << "============== " << name << " ==============" << std::endl;
        for (auto& it : _dishes) {
            if (it->isAvailable())
                std::cout << *it;
        }
        std::cout << std::endl;
    }

    void printProductsDish(string& name) const {
        const Dish* dish = this->getDish(name);
        if (dish)
            dish->printProducts();
    }

    void printBestDishes(int k) {
        for (auto it = _dishes.end()-1; it != _dishes.begin()-1; it--){
            if (k == 0) return;
            std::cout << **it;
            k--;
        }

    }

    // if dish doesn't exist- return -1
    int getDishRank(string& name) const {
        const Dish* dish = this->getDish(name);
        if (dish)
            return dish->getRank();
        return -1;
    }

    // if dish doesn't exist- return -1
    double getDishPrice(string& name) const {
        const Dish* dish = this->getDish(name);
        if (dish)
            return dish->getPrice();
        return -1;

    }

private:
    std::vector<Dish*> _dishes;
    std::unordered_map<string, Dish*> _dishes_details;

    static bool pred(const Dish* a, const Dish* b) {
        if (a->getRank() == b->getRank())
            return a->getName() < b->getName();
        return a->getRank() < b->getRank();
    }
};

#endif //DISH_H
