#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Publication {
protected:
    string title; 
    float price;  
public:
    void getdata() {
        while (true) {
            cout << "Enter price: ";
            cin >> price;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a numeric value for price." << endl;
            } else {
                break;
            }
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

        cout << "Enter title: ";
        getline(cin, title);
    }


    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};


class Book : public Publication {
private:
    int pageCount; 
public:
    
    void getdata() {
        Publication::getdata(); 

        while (true) {
            cout << "Enter page count: ";
            cin >> pageCount;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                cout << "Invalid input. Please enter a numeric value for page count." << endl;
            } else {
                break;
            }
        }
    }


    void putdata() const {
        Publication::putdata(); 
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};


class Type : public Publication {
private:
    float playTime;
public:

    void getdata() {
        Publication::getdata(); 

        while (true) {
            cout << "Enter play time (in minutes): ";
            cin >> playTime;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                cout << "Invalid input. Please enter a numeric value for play time." << endl;
            } else {
                break;
            }
        }
    }


    void putdata() const {
        Publication::putdata(); 
        cout << "Play time: " << playTime << " minutes" << endl;
    }
};

int main() {
   
    Book myBook;
    Type myType;

    
    cout << "\nEnter data for book publication:" << endl;
    myBook.getdata();

   
    cout << "\nEnter data for type publication:" << endl;
    myType.getdata();

   
    cout << "\nData for book:" << endl;
    myBook.putdata();

    
    cout << "\nData for type:" << endl;
    myType.putdata();

    return 0;
}
