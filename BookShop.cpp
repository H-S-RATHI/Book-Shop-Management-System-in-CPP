#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <conio.h>
#define CLEAR_SCREEN "cls"
#define getch _getch
#else
#include <stdio_ext.h> // For __fpurge on some non-Windows systems
#define CLEAR_SCREEN "clear"
#define getch getchar
#endif

using namespace std;

int ascii = 178, i = 0;
char ch = ascii;

struct BookShop {
    int id;
    float price;
    string name, a_name, p_name;
} B[25];

void Heading() {
    cout << "\n";
    for (int y = 1; y < 26; y++) {
        cout << ch;
    }
    cout << " BOOK SHOP PROJECT IN C++ ";
    for (int y = 1; y < 26; y++) {
        cout << ch;
    }
}

void Insert() {
    system(CLEAR_SCREEN);
    Heading();
    cout << "\n\n ENTER BOOK ID             ->";
    cin >> B[i].id;
    cout << "\n\n ENTER BOOK NAME           ->";
    cin >> B[i].name;
    cout << "\n\n ENTER BOOK AUTHOR NAME    ->";
    cin >> B[i].a_name;
    cout << "\n\n ENTER BOOK PUBLISHER NAME ->";
    cin >> B[i].p_name;
    cout << "\n\n ENTER BOOK PRICE          ->";
    cin >> B[i].price;
    i++;

    cout << "\n\n " << ch << ch << ch << " NEW BOOK INSERTED SUCCESSFULLY" << ch << ch;
}

void Search() {
    system(CLEAR_SCREEN);
    Heading();
    if (i == 0) {
        cout << "\n\n" << ch << ch << "STRUCTURE IS EMPTY";
    } else {
        int t_id, found = 0;
        cout << "\n\n ENTER BOOK ID FOR SEARCH -> ";
        cin >> t_id;

        for (int a = 0; a < i; a++) {
            if (t_id == B[a].id) {
                cout << "\n\n BOOK NAME      -> " << B[a].name;
                cout << "\n\n ATUHOR NAME    -> " << B[a].a_name;
                cout << "\n\n PUBLISHER NAME -> " << B[a].p_name;
                cout << "\n\n BOOK PRICE     -> " << B[a].price;
                found++;
                break;
            }
        }
        if (found == 0) {
            cout << "\n\n " << ch << ch << ch << "BOOK ID NOT FOUND" << ch << ch;
        }
    }
}

void Update() {
    system(CLEAR_SCREEN);
    Heading();
    if (i == 0) {
        cout << "\n\n" << ch << ch << "STRUCTURE IS EMPTY";
    } else {
        int t_id, found = 0;
        cout << "\n\n ENTER BOOK ID FOR UPDATE -> ";
        cin >> t_id;

        for (int a = 0; a < i; a++) {
            if (t_id == B[a].id) {
                cout << "\n\n ENTER BOOK NAME           ->";
                cin >> B[a].name;
                cout << "\n\n ENTER BOOK AUTHOR NAME    ->";
                cin >> B[a].a_name;
                cout << "\n\n ENTER BOOK PUBLISHER NAME ->";
                cin >> B[a].p_name;
                cout << "\n\n ENTER BOOK PRICE          ->";
                cin >> B[a].price;
                cout << "\n\n " << ch << ch << ch << "BOOK UPDATED SUCCESSFULLY" << ch << ch;
                found++;
                break;
            }
        }
        if (found == 0) {
            cout << "\n\n " << ch << ch << ch << "BOOK ID NOT FOUND" << ch << ch;
        }
    }
}

void Delete() {
    system(CLEAR_SCREEN);
    Heading();
    if (i == 0) {
        cout << "\n\n" << ch << ch << "STRUCTURE IS EMPTY";
    } else {
        int t_id, found = 0;
        cout << "\n\n ENTER BOOK ID FOR DELETE -> ";
        cin >> t_id;

        for (int a = 0; a < i; a++) {
            if (t_id == B[a].id) {
                for (int k = a; k < i; k++) {
                    B[k].id = B[k + 1].id;
                    B[k].name = B[k + 1].name;
                    B[k].a_name = B[k + 1].a_name;
                    B[k].p_name = B[k + 1].p_name;
                    B[k].price = B[k + 1].price;
                }
                cout << "\n\n " << ch << ch << ch << "BOOK DELETED SUCCESSFULLY" << ch << ch;
                found++;
                i--;
                break;
            }
        }
        if (found == 0) {
            cout << "\n\n " << ch << ch << ch << "BOOK ID NOT FOUND" << ch << ch;
        }
    }
}

void Show() {
    system(CLEAR_SCREEN);
    Heading();
    if (i == 0) {
        cout << "\n\n" << ch << ch << "STRUCTURE IS EMPTY";
    } else {
        for (int a = 0; a < i; a++) {
            cout << "\n\n BOOK ID        -> " << B[a].id;
            cout << "\n\n BOOK NAME      -> " << B[a].name;
            cout << "\n\n ATUHOR NAME    -> " << B[a].a_name;
            cout << "\n\n PUBLISHER NAME -> " << B[a].p_name;
            cout << "\n\n BOOK PRICE     -> " << B[a].price << "\n\n";
            for (int y = 1; y <= 26; y++) {
                cout << ch;
            }
        }
    }
}

int main() {
p:
    int choice;
    system(CLEAR_SCREEN);
    Heading();
    cout << "\n\n " << ch << ch << " 1. INSERT BOOK";
    cout << "\n\n " << ch << ch << " 2. SEARCH BOOK";
    cout << "\n\n " << ch << ch << " 3. UPDATE BOOK";
    cout << "\n\n " << ch << ch << " 4. DELETE BOOK";
    cout << "\n\n " << ch << ch << " 5. SHOW ALL BOOKS";
    cout << "\n\n " << ch << ch << " 6. EXIT\n\n";

    for (int i = 1; i < 26; i++) {
        cout << ch;
    }

    cout << "\n\n" << ch << ch << " ENTER YOUR CHOICE ->";
    cin >> choice;

    switch (choice) {
    case 1:
        Insert();
        break;

    case 2:
        Search();
        break;

    case 3:
        Update();
        break;

    case 4:
        Delete();
        break;

    case 5:
        Show();
        break;

    case 6:
        exit(0);
        break;

    default:
        cout << "\n\n " << ch << ch << "PLEASE SELECT CORRECT OPTION";
    }

    getch();
    goto p;
}
