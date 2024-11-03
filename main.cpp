#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class travel {
public:
    int ff, tf, rf;

    travel() : ff(4000), tf(3000), rf(2000) {}
};

class tour : public travel {
public:
    string name;
    string gen;
    int age;
    long long mobile_num;

    tour* next;
    static tour* head; // head is shared across all instances

    tour() : age(0), mobile_num(0), next(nullptr) {}

    friend void heading();
    friend void details();
    friend void india();
    friend void modification();
    friend void receipt();
};

tour* tour::head = nullptr; // initialize head pointer to nullptr
int amt = 0, k;

char str1[100];
char str2[100];
string date;

void add_passenger(string n, string g, int a, long long mb) {
    tour* newptr = new tour();
    newptr->name = n;
    newptr->gen = g;
    newptr->age = a;
    newptr->mobile_num = mb;

    if (tour::head == nullptr) {
        tour::head = newptr;
    } else {
        tour* ptr = tour::head;
        while (ptr->next != nullptr) {
            ptr = ptr->next;
        }
        ptr->next = newptr;
    }
}

void heading() {
    cout << "\t\t\t\t TOUR AND TRAVEL COMPANY \n";
}

int ch;

void mode_of_travel() {
    system("CLS");
    heading();
    cout << "\n1. By Flight\n2. By Train\n3. By Road\n";
    cout << "Enter your choice: ";
    cin >> ch;

    if (ch == 1) {
        amt = 4000;
        strcpy(str2, "by flight");
    } else if (ch == 2) {
        amt = 3000;
        strcpy(str2, "by train");
    } else if (ch == 3) {
        amt = 2000;
        strcpy(str2, "by road");
    } else {
        cout << "Enter the correct choice\n";
        mode_of_travel(); // Re-prompt if choice is invalid
    }
}

void india() {
    int a;
    system("CLS");
    heading();
    cout << "------------ India Tour Packages ------------\n";
    cout << "1. Ladakh (5 days 6 nights)\n";
    cout << "2. Shimla (3 days 4 nights)\n";
    cout << "3. Manali (4 days 5 nights)\n";
    cout << "4. Darjeeling (6 days 5 nights)\n";
    cout << "5. Goa (5 days 5 nights)\n";
    cout << "Enter your choice: ";
    cin >> a;

    switch (a) {
        case 1:
            amt = 12000;
            strcpy(str1, "Ladakh - 5 days 6 nights");
            break;
        case 2:
            amt = 12000;
            strcpy(str1, "Shimla - 3 days 4 nights");
            break;
        case 3:
            amt = 12000;
            strcpy(str1, "Manali - 4 days 5 nights");
            break;
        case 4:
            amt = 12000;
            strcpy(str1, "Darjeeling - 6 days 5 nights");
            break;
        case 5:
            amt = 12000;
            strcpy(str1, "Goa - 5 days 5 nights");
            break;
        default:
            cout << "Enter correct choice!\n";
            india(); // Re-prompt if choice is invalid
            break;
    }
}

void receipt() {
    system("CLS");
    heading();
    tour* ptr = tour::head;
    cout << "-------- Booking Receipt --------\n";
    cout << "[Passenger Information]\n";

    for (int i = 1; i <= k; i++) {
        cout << "Passenger " << i << ":\n";
        cout << "Name: " << ptr->name << "\n";
        cout << "Gender: " << ptr->gen << "\n";
        cout << "Age: " << ptr->age << "\n";
        cout << "Mobile Number: " << ptr->mobile_num << "\n";
        ptr = ptr->next;
    }

    cout << "\nPackage: " << str1 << "\n";
    cout << "Departure Date: " << date << "\n";
    cout << "Mode of Travel: " << str2 << "\n";

    long long tourAmount = amt * k;
    long long travelAmount = ch == 1 ? 4000 * k : (ch == 2 ? 3000 * k : 2000 * k);
    long long totalAmount = tourAmount + travelAmount;

    cout << "Tourism Amount: " << tourAmount << "\n";
    cout << "Travel Amount: " << travelAmount << "\n";
    cout << "Total Amount: " << totalAmount << "\n";
    cout << "Details sent to your mobile number.\n";
    cout << "Thank you for planning your trip with us!\n";
}

void details() {
    string nme, gn;
    int a;
    long long mb;
    system("CLS");
    heading();

    cout << "Enter the number of passengers: ";
    cin >> k;
    cin.ignore();

    cout << "Enter departure date (dd/mm/yyyy): ";
    getline(cin, date);

    for (int i = 1; i <= k; i++) {
        system("CLS");
        heading();

        cout << "Enter Passenger " << i << " Name: ";
        getline(cin, nme);

        cout << "Enter Passenger " << i << " Gender: ";
        getline(cin, gn);

        cout << "Enter Passenger " << i << " Age: ";
        cin >> a;
        cout << "Enter Passenger " << i << " Mobile Number: ";
        cin >> mb;
        cin.ignore();

        add_passenger(nme, gn, a, mb);
    }
}

void modification() {
    system("CLS");
    char q;
    cout << "Do you want to modify your details? (y/n): ";
    cin >> q;

    if (q == 'n' || q == 'N') {
        receipt();
        return;
    }

    int ch1;
    cout << "Choose Modification Section\n";
    cout << "1. Add Passenger\n";
    cout << "2. Modify Package\n";
    cout << "3. Modify Mode of Travel\n";
    cout << "Enter your choice: ";
    cin >> ch1;

    switch (ch1) {
        case 1:
            details();
            break;
        case 2:
            india();
            break;
        case 3:
            mode_of_travel();
            break;
        default:
            cout << "Please choose the correct option!\n";
            modification(); // Re-prompt if choice is invalid
            break;
    }
    receipt();
}

int main() {
    int choice;
    do {
        heading();
        cout << "Press 1 for Main Menu\n";
        cout << "Press 0 to Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            india();
            mode_of_travel();
            details();
            modification();
        } else if (choice != 0) {
            cout << "Enter correct choice\n";
        }
    } while (choice == 0 || choice == 1);

    return 0;
}
