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

    void putTitle() const {
        cout << "Title: " << title << endl;
    }

    float getPrice() const {
        return price;
    }
};


class Sales {
private:
    int booksSold[3];       
    int audiobooksSold[3];  
public:
 
    void getdata() {
        cout << "Enter number of books sold for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            while (true) {
                cout << "Month " << i + 1 << " (books): ";
                cin >> booksSold[i];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a numeric value." << endl;
                } else {
                    break;
                }
            }
        }

        cout << "Enter number of audiobooks sold for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            while (true) {
                cout << "Month " << i + 1 << " (audiobooks): ";
                cin >> audiobooksSold[i];
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a numeric value." << endl;
                } else {
                    break;
                }
            }
        }
    }


    void calculateMonthlySales(float price) const {
        for (int i = 0; i < 3; ++i) {
            int totalBooksSold = booksSold[i];
            int totalAudiobooksSold = audiobooksSold[i];

            float monthlySales = (totalBooksSold + totalAudiobooksSold) * price;

            cout << "Month " << i + 1 << ": $" << monthlySales << endl;
        }
    }
};


class BookSales : public Sales {
private:
    Publication& pub; 
public:

    BookSales(Publication& p) : pub(p) {}


    void getdata() {
        Sales::getdata(); 
    }


    void putdata() const {
        pub.putTitle();
        Sales::calculateMonthlySales(pub.getPrice()); 
    }
};

int main() {
    Publication pub; 


    cout << "Enter common data for publication (title and price):" << endl;
    pub.getTitleAndPrice();


    BookSales myBookSales(pub);


    cout << "\nEnter sales data (books and audiobooks):" << endl;
    myBookSales.getdata();

    cout << "\nSales data summary:" << endl;
    myBookSales.putdata();

    return 0;
}
