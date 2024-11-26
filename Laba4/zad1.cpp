#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>
#include <locale>

using namespace std;

class Vehicle {
public:
    virtual void move() const = 0;
    virtual ~Vehicle() = default;
};


class Bicycle : public Vehicle {
public:
    void move() const override {
        cout << "I zdes yandex poyavilsa?" << endl;
    }
};


class Car : public Vehicle {
public:
    void move() const override {
        cout << "Bibi suzuki" << endl;
    }
};


class Truck : public Vehicle {
public:
    void move() const override {
        cout << "Samosval hehe" << endl;
    }
};


template <typename T>
class ObjectArray {
private:
    unique_ptr<T[]> objects;
    size_t size;
public:
    ObjectArray(size_t size) {
        
        if (size > 1000) { 
            throw length_error("Too bg arr");
        }
        this->size = size;
        objects = make_unique<T[]>(size);
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw out_of_range("Ind out of rng");
        }
        return objects[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Ind out of rng");
        }
        return objects[index];
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    
    setlocale(0, "");

    try {
        
        ObjectArray<shared_ptr<Vehicle>> bigArray(1500); 
    } catch (const length_error& e) {
        cerr << "Err: " << e.what() << endl;
    }

    try {
        
        Bicycle bike;
        Car car;
        Truck truck;

        bike.move();
        car.move();
        truck.move();

        
        ObjectArray<shared_ptr<Vehicle>> vehicleArray(3);

        vehicleArray[0] = make_shared<Bicycle>();
        vehicleArray[1] = make_shared<Car>();
        vehicleArray[2] = make_shared<Truck>();

        for (size_t i = 0; i < vehicleArray.getSize(); ++i) {
            vehicleArray[i]->move();
        }

       
        vehicleArray[5]; 

    } catch (const out_of_range& e) {
        cerr << "Err: " << e.what() << endl;
    }

    return 0;
}
