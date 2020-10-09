#ifndef CATEGORY_H
#define CATEGORY_H
#include <bits/stdc++.h>
using std::string;
using Product = string; // Assume operator== for Product

class Category{
public:
    explicit Category(string& name): _name(std::move(name)) {}

    void addDish(string& name, int rank, double price) {
        _dishes.emplace_back(name, rank, price);
        std::push_heap(_dishes.begin(), _dishes.end());
    }

    void addDishWithProducts(string& name, std::list<Product>& products, int rank, double price) {
        _dishes.emplace_back(name, products, rank, price);
        std::push_heap(_dishes.begin(), _dishes.end());
    }

    void addDishWithProductsAndAllergens(string& name, std::list<Product>& products, std::list<Product>& allergens,
                                         int rank, double price) {
        _dishes.emplace_back(name, products, allergens, rank, price);
        std::push_heap(_dishes.begin(), _dishes.end());
    }

    void removeDish(string& name){
        for (auto it = _dishes.begin(); it !=_dishes.end(); it++){
            if (*it == name){
                _dishes.erase(it);
                std::make_heap(_dishes.begin(), _dishes.end());
                return;
            }
        }
    }

    void changeDishName(string& name) {
        for (auto& it : _dishes)
            if (it == name){
                it._name = std::move(name);
                return;
            }
    }

    void changeDishPrice(string& name, double price) {
        for (auto& it : _dishes)
            if (it == name){
                it._price = price;
                return;
            }
    }

    void changeDishRank(string& name, int rank) {
        for (auto& it : _dishes)
            if (it == name){
                it._rank = rank;
                return;
            }
    }

    void addProductToDish(string& name, Product& product){
        for (auto& it : _dishes)
            if (it == name){
                it._products.push_back(std::move(product));
                return;
            }
    }

    void addAllergenToDish(string& name, Product& allergen){
        for (auto& it : _dishes)
            if (it == name){
                it._allergens.push_back(std::move(allergen));
                return;
            }
    }

    void removeProductFromDish(string& name, Product& product){
        for (auto& it : _dishes)
            if (it == name)
                for (auto i = it._products.begin(); i != it._products.end(); i++)
                    if (*i == product) {
                        it._products.erase(i);
                        return;
                    }
    }

    void removeAllergenFromDish(string& name, Product& allergen){
        for (auto& it : _dishes)
            if (it == name)
                for (auto i = it._allergens.begin(); i != it._allergens.end(); i++)
                    if (*i == allergen) {
                        it._allergens.erase(i);
                        return;
                    }
    }

    void printProducts(string& name){
        for (auto& it : _dishes)
            if (it == name)
                for (auto& i : it._allergens)
                    std::cout << i << ", ";
    }

    void printAllergens(string& name){
        for (auto& it : _dishes)
            if (it == name)
                for (auto& i : it._allergens)
                    std::cout << i << ", ";
    }

private:
    struct Dish{
        string _name;
        std::list<Product> _products;
        std::list<Product> _allergens;
        int _rank;
        double _price;
        bool _available;

        Dish(string& name, int rank, double price):
                _name(std::move(name)), _rank(rank), _price(price), _available(true) {}
        Dish(string& name, std::list<Product>& products, int rank, double price):
                _name(std::move(name)), _products(std::move(products)), _rank(rank), _price(price), _available(true) {}
        Dish(string& name, std::list<Product>& products, std::list<Product>& allergens, int rank, double price):
                _name(std::move(name)), _products(std::move(products)), _allergens(std::move(allergens)), _rank(rank),
                _price(price), _available(true) {}

        bool operator<(const Dish& other) const {
            return _rank < other._rank;
        }
        bool operator==(const string& other) const {
            return _name == other;
        }
};

string _name;
std::vector<Dish> _dishes;
};

#endif //CATEGORY_H
