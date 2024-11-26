#define PI 3.14159265358979323846
#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <cmath>


class Base {
public:
    Base(double side_length = 1.0) : side(side_length) {
        std::cout << "Base constructed with side = " << side << std::endl;
    }

   
    Base(const Base& other) : side(other.side) {
        std::cout << "Base copied with side = " << side << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base destructed" << std::endl;
    }

    virtual double area() const {
        return side * side;
    }

    virtual void info() const {
        std::cout << "This is Base (Square) with area = " << area() << std::endl;
    }

    
    virtual Base* clone() const {
        return new Base(*this);
    }

protected:
    double side;
};


class Derived : public Base {
public:
    Derived(double radius = 1.0) : Base(radius) {
        std::cout << "Derived constructed with radius = " << side << std::endl;
    }

    
    Derived(const Derived& other) : Base(other.side) {
        std::cout << "Derived copied with radius = " << side << std::endl;
    }

    virtual ~Derived() {
        std::cout << "Derived destructed" << std::endl;
    }

    virtual double area() const override {
        return PI * side * side;
    }

    virtual void info() const override {
        std::cout << "This is Derived (Circle) with area = " << area() << std::endl;
    }

    virtual Base* clone() const override {
        return new Derived(*this);
    }
};


void add(const Base& obj, std::vector<Base*>& storage) {
    std::cout << "Adding object to storage..." << std::endl;
    storage.push_back(obj.clone());
}

int main() {
    std::vector<Base*> storage;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    
    for (int i = 0; i < 3; ++i) {
        int random_number = std::rand();
        if (random_number % 2 == 0) {
            double side_length = (std::rand() % 10) + 1;  
            std::cout << "\nCreating Base object with side = " << side_length << std::endl;
            Base base_obj(side_length);
            add(base_obj, storage);
        } else {
            double radius = (std::rand() % 10) + 1; 
            std::cout << "\nCreating Derived object with radius = " << radius << std::endl;
            Derived derived_obj(radius);
            add(derived_obj, storage);
        }
    }


    std::cout << "\nDisplaying information about objects in storage:" << std::endl;
    for (const auto& obj : storage) {
        obj->info();
    }

    for (auto& obj : storage) {
        delete obj;
    }

    return 0;
}
