#ifndef DISH_H
#define DISH_H
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
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

    const string& getName() const;

    const string& getDescription() const;

    int getRank() const;

    double getPrice() const;

    bool isAvailable() const;

    void changeName(string& name);

    void changeDescription(string& description);

    void addProduct(Product& product);

    void removeProduct(Product& product);

    void setRank(int rank);

    void setPrice(double price);

    void outOfVariety();

    void putInVariety();

    void printProducts() const;

    void orderDish();

    unsigned int getNumberOfSales() const;

private:
    string _name;
    string _description;
    std::unordered_set<Product> _products;
    int _rank;
    double _price;
    bool _available;
    unsigned int _sold;
};

std::ostream& operator<<(std::ostream& os, const Dish& dish);

class Category{
public:
    ~Category();

    // if dish doesn't exist- return null
    Dish* getDish(string& name);

    // if dish doesn't exist- return null
    const Dish* getDish(string& name) const;

    void addDish(string& name, string& description, int rank, double price);

    void addDishWithProducts(string& name, string& description, std::unordered_set<Product>& products, int rank, double price);

    void removeDish(string& name);

    void changeDishName(string& name, string& new_name);

    void changeDishDescription(string& name, string& description);

    void setDishPrice(string& name, double price);

    void setDishRank(string& name, int rank);

    void addProductToDish(string& name, Product& product);

    void removeProductFromDish(string& name, Product& product);

    void outOfVariety(string& name);

    void putInVariety(string& name);

    void printCategory(const string& name) const;

    void printProductsDish(string& name) const;

    void printBestDishes(int k);

    // if dish doesn't exist- return -1
    int getDishRank(string& name) const;

    // if dish doesn't exist- return -1
    double getDishPrice(string& name) const;

private:
    std::vector<Dish*> _dishes;
    std::unordered_map<string, Dish*> _dishes_details;

    static bool pred(const Dish* a, const Dish* b);
};

#endif //DISH_H
