#define PI 3.14159265358979323846
#include <iostream>
#include <vector>
#include <cmath>


class Detail {
protected:
    Detail(double side_length) : side(side_length) {
        std::cout << "Detail constructed with side = " << side << std::endl;
    }

public:
    virtual ~Detail() {
        std::cout << "Detail destructed" << std::endl;
    }

    virtual double area() const {
        return side * side;
    }

    virtual void info() const {
        std::cout << "This is a Detail (Square) with area = " << area() << std::endl;
    }

    
    template<typename T, typename... Args>
    friend T* create(Args&&... args);

protected:
    double side;
};


class Assembly : public Detail {
protected:
    Assembly(double radius) : Detail(radius) {
        std::cout << "Assembly constructed with radius = " << side << std::endl;
    }

public:
    virtual ~Assembly() {
        std::cout << "Assembly destructed" << std::endl;
    }

    virtual double area() const override {
        return PI * side * side;
    }

    virtual void info() const override {
        std::cout << "This is an Assembly (Circle) with area = " << area() << std::endl;
    }

    template<typename T, typename... Args>
    friend T* create(Args&&... args);
};


template<typename T, typename... Args>
T* create(Args&&... args) {
    return new T(std::forward<Args>(args)...);
}

int main() {
    std::vector<Detail*> storage;

    
    storage.push_back(create<Detail>(5.0));      
    storage.push_back(create<Assembly>(3.0));    

    
    for (const auto& obj : storage) {
        obj->info();
    }

    
    for (auto& obj : storage) {
        delete obj;
    }

    return 0;
}
