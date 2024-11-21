#include <iostream>
#include <fstream>
using namespace std;

class Book {
private:
    string name;
    string author;
    int release_date;
public:
    Book() {
        name = "-";
        author = "-";
        release_date = 0;
    }
    Book(string name_b, string author_b, int release_date_b) {
        name = name_b;
        author = author_b;
        release_date = release_date_b;
    }
    void display() {
        cout << "Name: " << name << "\tAuthor: " << author << "\tRelease date: " << release_date<< endl;
    }
    static void sortByName(Book* arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j].name > arr[j + 1].name) { 
                    Book temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    static void sortByAuthor(Book* arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j].author > arr[j + 1].author) {
                    Book temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    static void sortByDate(Book* arr, int size) {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j].release_date > arr[j + 1].release_date) {
                    Book temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void saveToFile(const Book* book, int size, const string& filename) {
        // Открываем файл в режиме записи (std::ios::out) - всегда создаст файл, если его нет
        ofstream file(filename, std::ios::out);

        if (!file) {
            std::cerr << "Error creating or opening file: " << filename << std::endl;
            return;
        }
        // Записываем данные в файл
        for (int i = 0; i < size; ++i) {
            file << "Name: " << book[i].name << "\tAuthor: " << book[i].author << "\tRelease date: " << book[i].release_date << "\n";
        }
        file.close();
        std::cout << "Results saved to " << filename << std::endl;
    }

 };

void main()
{

    int size;
    cout << "Enter the number of books:\n";
    cin >> size;

    Book* book = new Book[size];

    for (int i = 0; i < size; i++) {
        string name;
        string author;
        int release_date;
        cout << "Enter the title of the book, its author and the date of publication " << i << ":\n";
        cin >> name >> author >> release_date;
        book[i] = Book(name, author, release_date);
    }

    cout << "Choose an action" << endl;
    cout << "1)Output an array" << endl;
    cout << "2)Sort by name" << endl;
    cout << "3)Sort by author" << endl;
    cout << "4)Sort by year of release" << endl;
    cout << "5)Move an array to a file" << endl;

    while (1) {
        cout << '\n' << "Enter an action" << endl;
        int act;
        cin >> act;
        string file;
        switch (act) {
        case 1:
            for (int i = 0; i < size; i++) {
                book[i].display();
            }
            break;
        case 2:
            book->sortByName(book, size);
            for (int i = 0; i < size; i++) {
                book[i].display();
            }
            break;
        case 3:
            book->sortByAuthor(book, size);
            for (int i = 0; i < size; i++) {
                book[i].display();
            }
            break;
        case 4:
            book->sortByDate(book, size);
            for (int i = 0; i < size; i++) {
                book[i].display();
            }
            break;
        case 5:
            cout << "Enter the file name" << endl;
            cin >> file;
            book->saveToFile(book, size, file);
            break;
        default:
            cout << "Enter the correct action number" << endl;
        }

    }
    delete[] book;
}
