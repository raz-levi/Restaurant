#include <bits/stdc++.h>
#include "Restaurant.h"
#include <chrono>
#include <thread>
using std::cout;
using std::endl;

void init(){
    Restaurant restaurant;
    if (restaurant.getNumberOfEmployees() != 0) cout<< "Init Failed"<< endl;
    else cout << "Init Success"<< endl;
}

void addOne(){
    Restaurant restaurant;
    string name = "Raz";
    restaurant.addNewEmployee(name, chef, 29.12);
    if (restaurant.getNumberOfEmployees() != 1){
        cout<< "addOne Failed: insertion"<< endl;
        return;
    }
    name = "Raz";
    restaurant.removeEmployee(name);
    if (restaurant.getNumberOfEmployees() != 0){
        cout<< "deleteOne Failed: remove"<< endl;
        return;
    }
    else cout << "addOne Success"<< endl;
}

void addSome(int s){
    Restaurant restaurant;
    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.addNewEmployee(name, chef, 29.12);
        if (restaurant.getNumberOfEmployees() != i) {
            cout << "addSome Failed: insertion "<< i << endl;
            return;
        }
    }

    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.removeEmployee(name);
        if (restaurant.getNumberOfEmployees() != s-i) {
            cout << "addSome Failed: remove "<< i << endl;
            return;
        }
    }

    cout << "addSome Success"<< endl;
}

void markEnter(){
    Restaurant restaurant;
    string name = "Raz";
    restaurant.addNewEmployee(name, chef, 29.12);
    if (restaurant.getNumberOfEmployees() != 1){
        cout<< "markEnter Failed: insertion"<< endl;
        return;
    }
    name = "Raz";
    restaurant.markEntrance(name);
    name = "Raz";
    restaurant.printScheduleForOne(name);
    cout << endl;
    name = "Raz";
    restaurant.removeEmployee(name);
    if (restaurant.getNumberOfEmployees() != 0){
        cout<< "markEnter Failed: remove"<< endl;
        return;
    }
    else cout << "markEnter Success"<< endl;
}

void markQuit(){
    Restaurant restaurant;
    string name = "Raz";
    restaurant.addNewEmployee(name, chef, 29.12);
    if (restaurant.getNumberOfEmployees() != 1){
        cout<< "markQuit Failed: insertion"<< endl;
        return;
    }
    name = "Raz";
    restaurant.markEntrance(name);
    name = "Raz";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    restaurant.markQuit(name);
    name = "Raz";
    restaurant.printScheduleForOne(name);
    cout << endl;
    name = "Raz";
    restaurant.removeEmployee(name);
    if (restaurant.getNumberOfEmployees() != 0){
        cout<< "markQuit Failed: remove"<< endl;
        return;
    }
    else cout << "markQuit Success"<< endl;
}

void calculateSalary(){
    Restaurant restaurant;
    string name = "Raz";
    restaurant.addNewEmployee(name, chef, 29.12);
    if (restaurant.getNumberOfEmployees() != 1){
        cout<< "calculateSalary Failed: insertion"<< endl;
        return;
    }
    name = "Raz";
    restaurant.markEntrance(name);
    name = "Raz";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    restaurant.markQuit(name);
    name = "Raz";
    cout << restaurant.calculateMonthlySalary(name) <<endl;
    name = "Raz";
    restaurant.removeEmployee(name);
    if (restaurant.getNumberOfEmployees() != 0){
        cout<< "calculateSalary Failed: remove"<< endl;
        return;
    }
    else cout << "calculateSalary Success"<< endl;
}

void markEnterWhileEntered(){
    Restaurant restaurant;
    string name = "Raz";
    restaurant.addNewEmployee(name, chef, 29.12);
    if (restaurant.getNumberOfEmployees() != 1){
        cout<< "markEnterWhileEntered Failed: insertion"<< endl;
        return;
    }

    name = "Raz";
    restaurant.markEntrance(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    name = "Raz";
    restaurant.markEntrance(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    name = "Raz";
    restaurant.markEntrance(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    name = "Raz";
    restaurant.markQuit(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    name = "Raz";
    restaurant.markQuit(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    name = "Raz";
    restaurant.markQuit(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));


    name = "Raz";
    restaurant.markEntrance(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));


    name = "Raz";
    restaurant.markEntrance(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));


    name = "Raz";
    restaurant.markQuit(name);
    std::this_thread::sleep_for(std::chrono::seconds(2));

    name = "Raz";
    restaurant.printScheduleForOne(name);

    name = "Raz";
    cout << restaurant.endMonthForOne(name);
}

void Monster(int s){
    Restaurant restaurant;
    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.addNewEmployee(name, chef, 29.12);
        if (restaurant.getNumberOfEmployees() != i) {
            cout << "printScheduleForAll Failed: insertion "<< i << endl;
            return;
        }
    }

    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.markEntrance(name);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.markQuit(name);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    string name = "2";
    restaurant.setRole(name, hostess);

    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.markEntrance(name);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    name = "2";
    restaurant.setSalary(name, 1000);

    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.markQuit(name);
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    name = "1";
    restaurant.resetWorkTimeForOne(name);

    name = "1";
    restaurant.markEntrance(name);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    name = "1";
    restaurant.markEntrance(name);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    name = "1";
    restaurant.markEntrance(name);
    name = "1";
    restaurant.markQuit(name);
    name = "1";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    restaurant.markQuit(name);
    name = "1";
    restaurant.markQuit(name);

    restaurant.printScheduleForAll();
    auto vec= restaurant.endMonthForAll();
    for (auto& it : vec){
        cout << it;
    }

    restaurant.resetWorkTimeForAll();
    restaurant.printScheduleForAll();

    for (int i=1; i<=s; i++){
        string name = std::to_string(i);
        restaurant.removeEmployee(name);
        if (restaurant.getNumberOfEmployees() != s-i) {
            cout << "printScheduleForAll Failed: remove "<< i << endl;
            return;
        }
    }
}

void Monster2(){
    Restaurant restaurant;
    string name = "Guy Levi";
    restaurant.addNewEmployee(name, cashier, 29.12);
    name = "Guy Levi";
    restaurant.markEntrance(name);

    name = "Raz Levi";
    restaurant.addNewEmployee(name, cashier, 29.12);
    name = "Raz Levi";
    restaurant.markEntrance(name);

    std::this_thread::sleep_for(std::chrono::seconds(5));

    name = "Guy Levi";
    restaurant.markQuit(name);
    name = "Raz Levi";
    restaurant.markQuit(name);

    restaurant.printScheduleForAll();
    auto vec= restaurant.endMonthForAll();
    for (auto& it : vec){
        cout << it;
    }

    restaurant.printScheduleForAll();

    name = "Guy Levi";
    restaurant.markEntrance(name);
    name = "Raz Levi";
    restaurant.markEntrance(name);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    name = "Raz Levi";
    restaurant.markEntrance(name);

    name = "Guy Levi";
    restaurant.markQuit(name);
    name = "Raz Levi";
    restaurant.markQuit(name);

    restaurant.printScheduleForAll();

    name = "Raz Levi";
    restaurant.endMonthForOne(name);

    restaurant.printScheduleForAll();

    name = "Guy Levi";
    restaurant.markEntrance(name);
    name = "Raz Levi";
    restaurant.markEntrance(name);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    name = "Raz Levi";
    restaurant.markEntrance(name);

    name = "Guy Levi";
    restaurant.markQuit(name);
    name = "Raz Levi";
    restaurant.markQuit(name);

    restaurant.printScheduleForAll();
    vec= restaurant.endMonthForAll();
    for (auto& it : vec){
        cout << it;
    }

    name = "Guy Levi";
    restaurant.removeEmployee(name);
    name = "Raz Levi";
    restaurant.removeEmployee(name);
}

void notInEmployees(){
    Restaurant restaurant;
    string name="Raz";
    restaurant.markEntrance(name);
    restaurant.addNewEmployee(name, cashier, 29);
    name="Raz";
    restaurant.markQuit(name);
    name="Raz";
    restaurant.markEntrance(name);
    name="Ra";
    restaurant.markQuit(name);
    restaurant.printScheduleForAll();
}

int main(){
    /*
    init();
    addOne();
    addSome(5);
    markEnter();
    markQuit();
    calculateSalary();
    markEnterWhileEntered();
     */
    //addSome(10000);
    //Monster(4);
    //Monster2();
    notInEmployees();





    return 1;
    // std::this_thread::sleep_for(std::chrono::seconds(4));

}
