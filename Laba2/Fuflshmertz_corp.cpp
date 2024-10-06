#include <iostream>
#include <string>
#include <limits> // Для использования numeric_limits
using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title; // Название книги или аудиозаписи
    float price;  // Цена
public:
    // Метод ввода данных
    void getdata() {
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер перед вводом строки
        cout << "Enter title: ";
        getline(cin, title); // Читаем строку для названия

        // Ввод и проверка цены
        while (true) {
            cout << "Enter price: ";
            cin >> price;
            if (cin.fail()) {
                cin.clear(); // Сбрасываем флаг ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                cout << "Invalid input. Please enter a numeric value for price." << endl;
            } else {
                break;
            }
        }
    }

    // Метод вывода данных
    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

// Класс Book, наследующийся от Publication
class Book : public Publication {
private:
    int pageCount; // Количество страниц
public:
    // Метод ввода данных
    void getBookData() {
        // Ввод и проверка количества страниц
        while (true) {
            cout << "Enter page count: ";
            cin >> pageCount;
            if (cin.fail()) {
                cin.clear(); // Сбрасываем флаг ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                cout << "Invalid input. Please enter a numeric value for page count." << endl;
            } else {
                break;
            }
        }
    }

    // Метод вывода данных
    void putBookData() const {
        putdata(); // Вывод общих данных из Publication
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};

// Класс Type, наследующийся от Publication
class Type : public Publication {
private:
    float playTime; // Время записи в минутах
public:
    // Метод ввода данных
    void getTypeData() {
        // Ввод и проверка времени записи
        while (true) {
            cout << "Enter play time (in minutes): ";
            cin >> playTime;
            if (cin.fail()) {
                cin.clear(); // Сбрасываем флаг ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                cout << "Invalid input. Please enter a numeric value for play time." << endl;
            } else {
                break;
            }
        }
    }

    // Метод вывода данных
    void putTypeData() const {
        putdata(); // Вывод общих данных из Publication
        cout << "Play time: " << playTime << " minutes" << endl;
    }
};

int main() {
    // Создаем объекты Book и Type
    Book myBook;
    Type myType;

    // Вводим общие данные о публикации один раз
    cout << "Enter common data for publication (title and price):" << endl;
    myBook.getdata(); // Ввод общих данных (title и price) один раз

    // Вводим специфичные данные для книги и аудиозаписи
    cout << "\nEnter specific data for book:" << endl;
    myBook.getBookData(); // Ввод данных для Book

    cout << "\nEnter specific data for type (audiobook):" << endl;
    myType.getTypeData(); // Ввод данных для Type

    // Выводим данные для книги
    cout << "\nData for book:" << endl;
    myBook.putBookData();

    // Выводим данные для аудиозаписи
    cout << "\nData for type:" << endl;
    myType.putTypeData();

    return 0;
}
