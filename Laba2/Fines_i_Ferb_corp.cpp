#include <iostream>
#include <string>
#include <limits> 
using namespace std;

class Publication {
protected:
    string title; 
    float price;  
    float sales[3]; 
public:
    
    void getdata() {
        cout << "Enter title: ";
        getline(cin, title); 

        
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

        
        cout << "Enter sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            while (true) {
                cout << "Month " << i + 1 << ": ";
                cin >> sales[i];
                if (cin.fail()) {
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                    cout << "Invalid input. Please enter a numeric value for sales." << endl;
                } else {
                    break;
                }
            }
        }
    }


    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;

        
        cout << "Sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};

class Book {
private:
    int pageCount; 
    Publication& pub; 
public:
    Book(Publication& p) : pub(p) {}


    void getdata() {

        while (true) {
            cout << "Enter page count: ";
            cin >> pageCount;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a numeric value for page count." << endl;
            } else {
                break;
            }
        }
    }

    
    void putdata() const {
        pub.putdata();
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};


class Type {
private:
    float playTime; 
    Publication& pub; 
public:
  
    Type(Publication& p) : pub(p) {}

    
    void getdata() {
        
        while (true) {
            cout << "Enter play time (in minutes): ";
            cin >> playTime;
            if (cin.fail()) {
                cin.clear(); 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
                cout << "Invalid input. Please enter a numeric value for play time." << endl;
            } else {
                break;
            }
        }
    }

    
    void putdata() const {
        pub.putdata(); 
        cout << "Play time: " << playTime << " minutes" << endl;
    }
};

int main() {
    Publication pub; 

    
    cout << "Enter data for publication:" << endl;
    pub.getdata();

    
    Book myBook(pub);
    Type myType(pub);

    
    cout << "\nEnter data for book:" << endl;
    myBook.getdata();
    cout << "\nEnter data for type:" << endl;
    myType.getdata();

    
    cout << "\nData for book:" << endl;
    myBook.putdata();
    cout << "\nData for type:" << endl;
    myType.putdata();

    return 0;
}
