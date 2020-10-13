#include <bits/stdc++.h>
#include "Restaurant.h"
using std::cout;
using std::endl;

void init(){
    Restaurant restaurant;
    cout << "============== Init Success ==============" << endl << endl;
}

void addCat(){
    cout << "Should print Pizza only:"<< endl;
    Restaurant restaurant;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    restaurant.printMenu();
    cout << "============== addCat Success ==============" << endl << endl;
}

void removeCat(){
    cout << "Should print nothing:"<< endl;
    Restaurant restaurant;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    name = "Pizza";
    restaurant.removeCategory(name);
    restaurant.printMenu();
    cout << "============== removeCat Success ==============" << endl << endl;
}

void addSomeCat(int k){
    Restaurant restaurant;
    for (int i=1; i<=k; i++){
        string name = std::to_string(i);
        restaurant.addNewCategory(name);
    }
    restaurant.printMenu();
    cout << "============== addSomeCat Success ==============" << endl << endl;
}

void removeSomeCat(int k){
    Restaurant restaurant;
    for (int i=1; i<=k; i++){
        string name = std::to_string(i);
        restaurant.addNewCategory(name);
    }

    for (int i=1; i<=k; i++){
        string name = std::to_string(i);
        restaurant.removeCategory(name);
    }

    restaurant.printMenu();
    cout << "============== removeSomeCat Success ==============" << endl << endl;
}

void addDish(){
    cout << "Should print Pizza:"<< endl;
    Restaurant restaurant;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    string cat = "Pizza";
    string dish = "Olives";
    string de= "Very good Pizza";
    restaurant.addDish(cat, dish, de, 5, 100);
    restaurant.printMenu();
    cout << "============== addDish Success ==============" << endl << endl;
}

void removeDish(){
    cout << "Should print Pizza only:"<< endl;
    Restaurant restaurant;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    string cat = "Pizza";
    string dish = "Olives";
    string de= "Very good Pizza";
    restaurant.addDish(cat, dish, de, 5, 100);
    restaurant.printMenu();
    cat = "Pizza";
    dish = "Olives";
    restaurant.removeDish(cat, dish);
    cout << "Should print nothing:"<< endl;
    restaurant.printMenu();
    cout << "============== removeDish Success ==============" << endl << endl;
}

void addSomeDish(int k){
    Restaurant restaurant;
    cout << "Should print some dishes:"<< endl;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    name = "Pizza";
    for (int i=1; i<=k; i++){
        string dish = std::to_string(i);
        string de = "checking";
        restaurant.addDish(name, dish, de, 5, 120);
    }
    restaurant.printMenu();
    cout << "============== addSomeDish Success ==============" << endl << endl;
}

void addRemoveDish(int k){
    Restaurant restaurant;
    cout << "Should print nothing"<< endl;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    name = "Pizza";
    for (int i=1; i<=k; i++){
        string dish = std::to_string(i);
        string de = "checking";
        restaurant.addDish(name, dish, de, 5, 120);
    }
    restaurant.printMenu();
    for (int i=1; i<=k; i++){
        string dish = std::to_string(i);
        string de = "checking";
        restaurant.removeDish(name, dish);
    }
    restaurant.printMenu();
    cout << "============== addRemoveDish Success ==============" << endl << endl;
}

void printProduct(){
    cout << "Should print products:"<< endl;
    Restaurant restaurant;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    string cat = "Pizza";
    string dish = "Olives";
    string de= "Very good Pizza";
    std::unordered_set<Product> a = {"a", "b", "c", "d", "e"};
    restaurant.addDishWithProducts(cat, dish, de, a, 5, 100);
    cat = "Pizza";
    dish = "Olives";
    restaurant.printDishProduct(cat, dish);
    cout << "============== printProduct Success ==============" << endl << endl;
}

void MonsterPrint(int k, int m){
    Restaurant restaurant;
    for (int i=1; i<=k; i++){
        string name = std::to_string(i);
        restaurant.addNewCategory(name);
        for (int j=1; j<=m; j++){
            name = std::to_string(i);
            string dish = std::to_string(j);
            string de = "checking";
            restaurant.addDish(name, dish, de, 5, 120);
        }
    }
    restaurant.printMenu();
    cout << "============== MonsterPrint Success ==============" << endl << endl;
}

void MonsterPrint2(int k, int m, int n){
    Restaurant restaurant;
    for (int i=1; i<=k; i++){
        string name = std::to_string(i);
        restaurant.addNewCategory(name);
        for (int j=1; j<=m; j++){
            name = std::to_string(i);
            string dish = std::to_string(j);
            string de = "checking";
            restaurant.addDish(name, dish, de, 5, 120);
        }
    }
    std::unordered_set<Product> a;
    for (int i=1; i<= n; i++){
        string name = std::to_string(i);
        a.insert(name);
    }
    string name = "1";
    string dish = "good";
    string de = "checking";
    restaurant.addDishWithProducts(name, dish, de, a, 5, 120);

    name = "1";
    dish = "good";
    restaurant.printMenu();
    restaurant.printDishProduct(name, dish);

    restaurant.removeDish(name, dish);
    restaurant.printMenu();

    restaurant.removeCategory(name);
    restaurant.printMenu();
    cout << "============== MonsterPrint2 Success ==============" << endl << endl;
}

void checkNotIn(){
    Restaurant restaurant;
    string name = "1";
    restaurant.removeCategory(name);
    restaurant.addNewCategory(name);

    name = "1";
    string dish = "a";
    string de = "checking";
    restaurant.addDish(name, dish, de, 5, 120);

    name = "1";
    dish = "a";
    std::cout << restaurant.getDishRank(name, dish);
    dish = "b";
    restaurant.getDishRank(name, dish);
    name = "2";
    restaurant.getDishRank(name, dish);
    dish = "a";
    restaurant.getDishRank(name, dish);

    name = "1";
    dish = "a";
    restaurant.setDishPrice(name, dish, 999999);
    restaurant.printMenu();
    cout << "============== checkNotIn Success ==============" << endl << endl;
}

void checkVariety(){
    Restaurant restaurant;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    string cat = "Pizza";
    string dish = "Olives";
    string de= "Very good Pizza";
    restaurant.addDish(cat, dish, de, 5, 100);

    cat = "Pizza";
    dish = "Mushroom";
    de= "Very good Pizza";
    restaurant.addDish(cat, dish, de, 5, 100);
    restaurant.printMenu();

    cat = "Pizza";
    dish = "Mushroom";
    restaurant.outOfVariety(cat, dish);

    restaurant.printMenu();
    restaurant.putInVariety(cat, dish);
    restaurant.printMenu();
    cout << "============== checkVariety Success ==============" << endl << endl;
}

void makeChanges(){
    Restaurant restaurant;
    string name = "Pizza";
    restaurant.addNewCategory(name);
    string cat = "Pizza";
    string dish = "Olives";
    string de= "Very good Pizza";
    restaurant.addDish(cat, dish, de, 5, 100);
    cout << "Here is the initial menu" << endl;
    restaurant.printMenu();

    cat = "Pizza";
    dish = "Olives";
    restaurant.setDishPrice(cat, dish, 900);
    cout << "Here is the menu after changing price" << endl;
    restaurant.printMenu();

    restaurant.setDishRank(cat, dish, 1);
    cout << "Here is the menu after changing rank: " << restaurant.getDishRank(cat, dish) << endl << endl;
    cout << "Here is the dish price: " << restaurant.getDishPrice(cat, dish) << endl << endl;
    name = "Margarita";
    restaurant.changeDishName(cat, dish, name);
    cout << "Here is the menu after changing name" << endl;
    restaurant.printMenu();

    dish = "Margarita";
    de = "bla bla";
    restaurant.changeDishDescription(cat, dish, de);
    cout << "Here is the menu after changing description" << endl;
    restaurant.printMenu();

    Product product = "check";
    restaurant.addProductToDish(cat, dish, product);
    cout << "Here is the menu after changing product" << endl;
    restaurant.printDishProduct(cat, dish);

    product = "check";
    restaurant.removeProductFromDish(cat, dish, product);
    cout << "Here is the menu after removing product" << endl;
    restaurant.printDishProduct(cat, dish);

    restaurant.outOfVariety(cat, dish);
    cout << "Here is the menu after outOfVar" << endl;
    restaurant.printMenu();
    cout << "============== makeChanges Success ==============" << endl << endl;
}

void bestK(){
        Restaurant restaurant;
        string cat = "Pizza";
        restaurant.addNewCategory(cat);
        cat = "Pizza";
        for (int i = 1; i <= 10; i++) {
            string dish = std::to_string(i);
            string de = "..";
            restaurant.addDish(cat, dish, de, i%5, 100);
    }
        cat = "Pizza";
        restaurant.printBestDishes(cat, 4);
    cout << "============== bestK Success ==============" << endl << endl;
}

void lastOne(){
    Restaurant restaurant;
    string cat = "Pizza";
    restaurant.addNewCategory(cat);
    cat = "Pizza";
    for (int i = 1; i <= 10; i++) {
        string dish = std::to_string(i);
        string de = "..";
        restaurant.addDish(cat, dish, de, i%5, 100);
    }
    string dish = "1";
    restaurant.removeDish(cat, dish);
    dish = "2";
    restaurant.removeDish(cat, dish);
     dish = "3";
    restaurant.removeDish(cat, dish);
     dish = "4";
    restaurant.removeDish(cat, dish);
     dish = "5";
    restaurant.removeDish(cat, dish);
    dish = "9";
    restaurant.setDishRank(cat, dish, -1);
}

int main(){

    init();
    addCat();
    removeCat();
    addSomeCat(10);
    removeSomeCat(10);
    addDish();
    removeDish();
    addSomeDish(3);
    addRemoveDish(10);
    printProduct();
    MonsterPrint(5, 3);
    MonsterPrint2(4,3,10);
    checkNotIn();
    checkVariety();
    makeChanges();
    bestK();
    lastOne();





    return 1;
}
