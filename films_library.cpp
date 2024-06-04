#include <iostream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
//vector<int> ttm;
#include <stdlib.h>
using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

vector<Book> library;

int def_print(const vector<Book>& library) {
    cout << endl;
    cout << "------------------------------------------------------" << endl;
    for (const auto& book : library) {
        cout << book.title << " " << book.author << " " << book.year << " " << book.genre << endl;
    }
    cout << "------------------------------------------------------" << endl;
    return 0;
}

int searchByTitle(const string& title) {
    bool found = false;
    for (const auto& book : library) {
        if (book.title == title) {
            cout << "Найден Фильм: " << book.title << " (Автор: " << book.author << ", Год издания: " << book.year << ", Жанр: " << book.genre << ")" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Фильм с названием " << title << " не найден." << endl;
    }
    return 0;
}

void searchByAuthor(const string& auth) {
    bool found = false;
    for (const auto& book : library) {
        if (book.author == auth) {
            if (!found) {
                cout << "Найдены фильмы авторства " << auth << ":" << endl;
                found = true;
            }
            cout << book.title << " (Год издания: " << book.year << ", Жанр: " << book.genre << ")" << endl;
        }
    }
    if (!found) {
        cout << "Фильмы авторства " << auth << " не найдены." << endl;
    }
}

void removeBook(const string& title) {
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->title == title) {
            library.erase(it);
            cout << "Фильм успешно удален из библиотеки!" << endl;
            return;
        }
    }
    cout << "Фильм с таким названием не найден в библиотеке." << endl;
}

int Film(vector<Book>& library) {
    Book book1;
    cout << "Введите название Фильма: ";
    cin >> book1.title;
    cout << "Введите автора Фильма: ";
    cin >> book1.author;
    cout << "Введите год издания Фильма: ";
    cin >> book1.year;
    cout << "Введите жанр Фильма: ";
    cin >> book1.genre;
    library.push_back(book1);
    cout << "Фильм успешно добавлен в библиотеку!" << endl;
    return 0; 
}

void sortLibrary(vector<Book>& library) {
    sort(library.begin(), library.end(), [](const Book& a, const Book& b) {
        return a.genre < b.genre;
    });
    cout << "Библиотека отсортирована по жанру!" << endl;
}

int main() {
    while (true) {
        cout << "Выберите действие: " << endl;
        cout << "1. Поиск фильма по названию" << endl;
        cout << "2. Поиск фильма по автору" << endl;
        cout << "3. Удаление Фильма" << endl;
        cout << "4. Хотите добавить Фильм? " << endl;
        cout << "5. Вывести всю библиотеку" << endl;
        cout << "6. Сортировка библиотеки по жанру" << endl;
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Введите название Фильма: ";
                string title;
                cin >> title;
                searchByTitle(title);
                break;
            }
            case 2: {
                cout << "Введите автора Фильма: ";
                string author;
                cin >> author;
                searchByAuthor(author);
                break;
            }
            case 3: {
                cout << "Введите название Фильма для удаления: ";
                string titleToRemove;
                cin >> titleToRemove;
                removeBook(titleToRemove);
                break;
            }
            case 4: {
                Film(library);
                break;
            }
            case 5: {
                def_print(library);
                break;
            }
            case 6: {
                sortLibrary(library);
                break;
            }
            default: {
                cout << "Некорректный выбор действия." << endl;
                return 0;
            }
        }
    }
    return 0;
}
