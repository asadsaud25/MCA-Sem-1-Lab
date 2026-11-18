#include <iostream>
#include <string>
using namespace std;

struct Book {
    int book_id;
    string title;
    string author;
    double price;
};

void printBook(Book b) {
    cout << "Book ID : " << b.book_id << endl;
    cout << "Title   : " << b.title << endl;
    cout << "Author  : " << b.author << endl;
    cout << "Price   : " << b.price << endl;
}

int main() {
    int n;
    cout << "Number of books: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Book b;
        cout << "Book " << i + 1 << " ID: ";
        cin >> b.book_id;
        cout << "Title: ";
        getline(cin >> ws, b.title);
        cout << "Author name: ";
        getline(cin, b.author);
        cout << "Price: ";
        cin >> b.price;
        cout << endl;
        printBook(b);
        cout << endl;
    }
    return 0;
}
