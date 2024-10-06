#include <iostream>
#include <string>
#include <limits>


using namespace std;

enum class BookType {
    Artistic,
    Technical
};

class Book {
private:
    string author;
    string title;
    BookType type;

public:
    Book(const string& author, const string& title, BookType type) {
        if (author.empty() || title.empty()) {
            throw invalid_argument("Author and title cannot be empty.");
        }
        this->author = author;
        this->title = title;
        this->type = type;
    }

    BookType getType() const {
        return type;
    }

    string getAuthor() const {
        return author;
    }

    string getTitle() const {
        return title;
    }
};

class Library {
private:
    Book** books;
    int size;
    int capacity;

    void resize() {
        int newCapacity = capacity * 2;
        Book** newBooks = new Book*[newCapacity];
        for (int i = 0; i < size; ++i) {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
        capacity = newCapacity;
    }

public:
    Library() : books(nullptr), size(0), capacity(10) {
        books = new Book*[capacity];
    }

    ~Library() {
        for (int i = 0; i < size; ++i) {
            delete books[i];
        }
        delete[] books;
    }

    void addBook(const Book& book) {
        if (size >= capacity) {
            resize();
        }
        books[size++] = new Book(book);
    }

    void printCountsWithSwitch() const {
        int artisticCount = 0;
        int technicalCount = 0;

        for (int i = 0; i < size; ++i) {
            switch (books[i]->getType()) {
                case BookType::Artistic:
                    artisticCount++;
                    break;
                case BookType::Technical:
                    technicalCount++;
                    break;
                default:
                    break;
            }
        }

        cout << "\n[With switch]\n";
        cout << "Artistic books: " << artisticCount << "\n";
        cout << "Technical books: " << technicalCount << "\n";
    }

    void printCountsWithoutSwitch() const {
        int artisticCount = 0;
        int technicalCount = 0;

        for (int i = 0; i < size; ++i) {
            if (books[i]->getType() == BookType::Artistic) {
                artisticCount++;
            }
            else if (books[i]->getType() == BookType::Technical) {
                technicalCount++;
            }
        }

        cout << "\n[Without switch]\n";
        cout << "Artistic books: " << artisticCount << "\n";
        cout << "Technical books: " << technicalCount << "\n";
    }
};

int getValidatedInteger(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            if (value > 0) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return value;
            }
            else {
                cout << "Please enter a positive number.\n";
            }
        }
        else {
            cout << "Invalid input. Please enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string getValidatedString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) {
            return input;
        }
        else {
            cout << "Input cannot be empty. Please try again.\n";
        }
    }
}

BookType getBookType() {
    while (true) {
        cout << "Select the type of book:\n";
        cout << "1. Artistic\n";
        cout << "2. Technical\n";
        int choice;
        if (cin >> choice) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (choice == 1) {
                return BookType::Artistic;
            }
            else if (choice == 2) {
                return BookType::Technical;
            }
            else {
                cout << "Invalid choice. Please enter 1 or 2.\n";
            }
        }
        else {
            cout << "Invalid input. Please enter 1 or 2.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    Library library;

    int numberOfBooks = getValidatedInteger("Enter the number of books: ");

    for (int i = 0; i < numberOfBooks; ++i) {
        cout << "\n--- Adding book " << i + 1 << " ---\n";
        string author = getValidatedString("Enter author: ");
        string title = getValidatedString("Enter title: ");
        BookType type = getBookType();

        try {
            Book book(author, title, type);
            library.addBook(book);
            cout << "Book added successfully!\n";
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << "\n";
            --i;
        }
    }

    library.printCountsWithSwitch();
    library.printCountsWithoutSwitch();

    return 0;
}


