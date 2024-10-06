#include <iostream>
#include <string>
#include <limits> // Для использования numeric_limits
using namespace std;

// Базовый класс Publication
class Publication {
protected:
    string title; // Название книги или аудиозаписи
    float price;  // Цена
    float sales[3]; // Массив продаж за последние 3 месяца
public:
    // Метод ввода данных
    void getdata() {
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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер после ввода цены

        // Ввод данных о продажах
        cout << "Enter sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            while (true) {
                cout << "Month " << i + 1 << ": ";
                cin >> sales[i];
                if (cin.fail()) {
                    cin.clear(); // Сбрасываем флаг ошибки
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
                    cout << "Invalid input. Please enter a numeric value for sales." << endl;
                } else {
                    break;
                }
            }
        }
    }

    // Метод вывода данных
    void putdata() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;

        // Вывод данных о продажах
        cout << "Sales for the last 3 months:" << endl;
        for (int i = 0; i < 3; ++i) {
            cout << "Month " << i + 1 << ": $" << sales[i] << endl;
        }
    }
};

// Производный класс Book
class Book {
private:
    int pageCount; // Количество страниц
    Publication& pub; // Ссылка на общий объект Publication
public:
    // Конструктор с передачей ссылки на Publication
    Book(Publication& p) : pub(p) {}

    // Метод ввода данных
    void getdata() {
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
    void putdata() const {
        pub.putdata(); // Вывод данных из Publication
        cout << "Page count: " << pageCount << " pages" << endl;
    }
};

// Производный класс Type
class Type {
private:
    float playTime; // Время записи в минутах
    Publication& pub; // Ссылка на общий объект Publication
public:
    // Конструктор с передачей ссылки на Publication
    Type(Publication& p) : pub(p) {}

    // Метод ввода данных
    void getdata() {
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
    void putdata() const {
        pub.putdata(); // Вывод данных из Publication
        cout << "Play time: " << playTime << " minutes" << endl;
    }
};

int main() {
    Publication pub; // Создаем общий объект Publication

    // Вводим общие данные для Publication один раз (включая продажи)
    cout << "Enter data for publication:" << endl;
    pub.getdata();

    // Создаем объекты Book и Type, используя ссылку на общий Publication
    Book myBook(pub);
    Type myType(pub);

    // Вводим специфичные данные для книги и аудиозаписи
    cout << "\nEnter data for book:" << endl;
    myBook.getdata();
    cout << "\nEnter data for type:" << endl;
    myType.getdata();

    // Выводим данные для книги и аудиозаписи
    cout << "\nData for book:" << endl;
    myBook.putdata();
    cout << "\nData for type:" << endl;
    myType.putdata();

    return 0;
}
