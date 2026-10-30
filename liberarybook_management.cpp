#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    Book *left, *right;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        left = right = nullptr;
    }
};

Book* insertBook(Book* root, int id, string title, string author) {
    if (root == nullptr)
        return new Book(id, title, author);

    if (id < root->id)
        root->left = insertBook(root->left, id, title, author);
    else if (id > root->id)
        root->right = insertBook(root->right, id, title, author);
    else
        cout << "Book ID already exists!\n";

    return root;
}

Book* searchBook(Book* root, int id) {
    if (root == nullptr || root->id == id)
        return root;

    if (id < root->id)
        return searchBook(root->left, id);

    return searchBook(root->right, id);
}

void displayBooks(Book* root) {
    if (root == nullptr)
        return;

    displayBooks(root->left);

    cout << "Book ID: " << root->id
         << " | Title: " << root->title
         << " | Author: " << root->author << '\n';

    displayBooks(root->right);
}

Book* minimumBook(Book* root) {
    while (root != nullptr && root->left != nullptr)
        root = root->left;

    return root;
}

Book* deleteBook(Book* root, int id) {
    if (root == nullptr)
        return nullptr;

    if (id < root->id) {
        root->left = deleteBook(root->left, id);
    } else if (id > root->id) {
        root->right = deleteBook(root->right, id);
    } else {
        if (root->left == nullptr) {
            Book* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            Book* temp = root->left;
            delete root;
            return temp;
        }

        Book* temp = minimumBook(root->right);

        root->id = temp->id;
        root->title = temp->title;
        root->author = temp->author;

        root->right = deleteBook(root->right, temp->id);
    }

    return root;
}

int main() {
    Book* root = nullptr;
    int choice, id;
    string title, author;

    do {
        cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Delete Book\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input!\n";
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter Book Title: ";
            getline(cin, title);

            cout << "Enter Author Name: ";
            getline(cin, author);

            root = insertBook(root, id, title, author);
            break;

        case 2: {
            cout << "Enter Book ID to search: ";
            cin >> id;

            Book* found = searchBook(root, id);

            if (found != nullptr) {
                cout << "Book Found!\n";
                cout << "Title: " << found->title << '\n';
                cout << "Author: " << found->author << '\n';
            } else {
                cout << "Book not found!\n";
            }
            break;
        }

        case 3:
            if (root == nullptr)
                cout << "Library is empty!\n";
            else
                displayBooks(root);
            break;

        case 4:
            cout << "Enter Book ID to delete: ";
            cin >> id;

            if (searchBook(root, id) == nullptr) {
                cout << "Book not found!\n";
            } else {
                root = deleteBook(root, id);
                cout << "Book deleted successfully!\n";
            }
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
/*
PS D:\vedika111> cd "d:\vedika111\" ; if ($?) { g++ liberarybook_management.cpp -o liberarybook_management } ; if ($?) { .\liberarybook_management }

===== LIBRARY BOOK MANAGEMENT =====
1. Add Book
2. Search Book
3. Display All Books
4. Delete Book
5. Exit
Enter your choice: 1
Enter Book ID: 101
Enter Book Title: C++ Programing
Enter Author Name: Bjarne Stroustrup

===== LIBRARY BOOK MANAGEMENT =====
1. Add Book
2. Search Book
3. Display All Books
4. Delete Book
5. Exit
Enter your choice: 1
Enter Book ID: 105
Enter Book Title: Data Structure
Enter Author Name: Seymour Lipschutz

===== LIBRARY BOOK MANAGEMENT =====
1. Add Book
2. Search Book
3. Display All Books
4. Delete Book
5. Exit
Enter your choice: 3
Book ID: 101 | Title: C++ Programing | Author: Bjarne Stroustrup
Book ID: 105 | Title: Data Structure | Author: Seymour Lipschutz

===== LIBRARY BOOK MANAGEMENT =====
1. Add Book
2. Search Book
3. Display All Books
4. Delete Book
5. Exit
Enter your choice: 2
Enter Book ID to search: 101
Book Found!
Title: C++ Programing
Author: Bjarne Stroustrup

===== LIBRARY BOOK MANAGEMENT =====
1. Add Book
2. Search Book
3. Display All Books
4. Delete Book
5. Exit
Enter your choice: 4
Enter Book ID to delete: 105
Book deleted successfully!
/*