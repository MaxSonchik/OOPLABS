#include <iostream>
#include <string>
#include <limits>
using namespace std;


class Publication {
protected:
    string title; 
    float price;  
public:
    
    void getTitleAndPrice() {
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

    
    void putTitleAndPrice() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};


class Sales {
private:
    float sales[3]; 
public:
    
    void getdata() {
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
        cout << "Sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};


class Book : public Sales {
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

        Sales::getdata(); 
    }


    void putdata() const {
        cout << "Book details:" << endl;
        pub.putTitleAndPrice(); 
        cout << "Page count: " << pageCount << " pages" << endl;
        Sales::putdata(); 
    }
};


class Type : public Sales {
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

        Sales::getdata(); 
    }

    
    void putdata() const {
        cout << "Audiobook details:" << endl;
        pub.putTitleAndPrice(); 
        cout << "Play time: " << playTime << " minutes" << endl;
        Sales::putdata(); 
    }
};

int main() {
    Publication pub; 

    cout << "Enter common data for publication (title and price):" << endl;
    pub.getTitleAndPrice();

    Book myBook(pub);
    Type myType(pub);


    cout << "\nEnter specific data for book:" << endl;
    myBook.getdata();

    cout << "\nEnter specific data for type (audiobook):" << endl;
    myType.getdata();


    cout << "\nData for book:" << endl;
    myBook.putdata();

 
    cout << "\nData for audiobook:" << endl;
    myType.putdata();

    return 0;
}
