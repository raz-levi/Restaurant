#include "Dish.h"

const string &Dish::getName() const {
    return _name;
}

const string &Dish::getDescription() const {
    return _description;
}

int Dish::getRank() const {
    return _rank;
}

double Dish::getPrice() const {
    return _price;
}

bool Dish::isAvailable() const {
    return _available;
}

void Dish::changeName(string &name) {
    _name = std::move(name);
}

void Dish::changeDescription(string &description) {
    _description = std::move(description);
}

void Dish::addProduct(Product &product) {
    _products.insert(product);
}

void Dish::removeProduct(Product &product) {
    _products.erase(product);
}

void Dish::setRank(int rank) {
    _rank = rank;
}

void Dish::setPrice(double price) {
    _price = price;
}

void Dish::outOfVariety() {
    _available = false;
}

void Dish::putInVariety() {
    _available = true;
}

void Dish::printProducts() const {
    for (auto& it : _products){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void Dish::orderDish() {
    _sold++;
}

unsigned int Dish::getNumberOfSales() const {
    return _sold;
}

std::ostream &operator<<(std::ostream &os, const Dish &dish) {
    return os << "Name: " << dish.getName() << std::endl << dish.getDescription() << std::endl << "Price: "
              << dish.getPrice() << std::endl << std::endl;
}

Category::~Category() {
    for (auto& it : _dishes_details){
        delete it.second;
    }
}

Dish *Category::getDish(string &name) {
    auto it = _dishes_details.find(name);
    if (it == _dishes_details.end())
        return nullptr;
    return it->second;
}

const Dish *Category::getDish(string &name) const {
    auto it = _dishes_details.find(name);
    if (it == _dishes_details.end())
        return nullptr;
    return it->second;
}

void Category::addDish(string &name, string &description, int rank, double price) {
    Dish* new_dish = new Dish(name, description, rank, price);
    _dishes_details.insert({new_dish->getName(), new_dish});
    _dishes.insert(std::lower_bound(_dishes.begin(), _dishes.end(), new_dish, pred), new_dish);

}

void Category::addDishWithProducts(string &name, string &description, std::unordered_set<Product> &products, int rank,
                                   double price) {
    Dish* new_dish = new Dish(name, description, products, rank, price);
    _dishes_details.insert({new_dish->getName(), new_dish});
    _dishes.insert(std::lower_bound(_dishes.begin(), _dishes.end(), new_dish, pred), new_dish);
}

void Category::removeDish(string &name) {
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

void Category::changeDishName(string &name, string &new_name) {
    Dish* dish = this->getDish(name);
    if (!dish) return;
    _dishes_details.erase(name);
    dish->changeName(new_name);
    _dishes_details.insert({dish->getName(), dish});
}

void Category::changeDishDescription(string &name, string &description) {
    Dish* dish = this->getDish(name);
    if (dish)
        dish->changeDescription(description);
}

void Category::setDishPrice(string &name, double price) {
    Dish* dish = this->getDish(name);
    if (dish)
        dish->setPrice(price);
}

void Category::setDishRank(string &name, int rank) {
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

void Category::addProductToDish(string &name, Product &product) {
    Dish* dish = this->getDish(name);
    if (dish)
        dish->addProduct(product);
}

void Category::removeProductFromDish(string &name, Product &product) {
    Dish* dish = this->getDish(name);
    if (dish)
        dish->removeProduct(product);
}

void Category::outOfVariety(string &name) {
    Dish* dish = this->getDish(name);
    if (dish)
        dish->outOfVariety();
}

void Category::putInVariety(string &name) {
    Dish* dish = this->getDish(name);
    if (dish)
        dish->putInVariety();
}

void Category::printCategory(const string &name) const {
    std::cout << "============== " << name << " ==============" << std::endl;
    for (auto& it : _dishes) {
        if (it->isAvailable())
            std::cout << *it;
    }
    std::cout << std::endl;
}

void Category::printProductsDish(string &name) const {
    const Dish* dish = this->getDish(name);
    if (dish)
        dish->printProducts();
}

void Category::printBestDishes(int k) {
    for (auto it = _dishes.end()-1; it != _dishes.begin()-1; it--){
        if (k == 0) return;
        std::cout << **it;
        k--;
    }

}

int Category::getDishRank(string &name) const {
    const Dish* dish = this->getDish(name);
    if (dish)
        return dish->getRank();
    return -1;
}

double Category::getDishPrice(string &name) const {
    const Dish* dish = this->getDish(name);
    if (dish)
        return dish->getPrice();
    return -1;

}

bool Category::pred(const Dish *a, const Dish *b) {
    if (a->getRank() == b->getRank())
        return a->getName() < b->getName();
    return a->getRank() < b->getRank();
}
