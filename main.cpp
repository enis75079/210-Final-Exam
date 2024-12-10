/*

210 final exam
COMSC-210
Naveen Islam

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// function prototypes

// struct for node in linked list got coffee booth queue simulation
struct Node {
    string cusName;
    string cusOrder;
    Node* next;
};

void addCustomer(const string& name, const string& coffee, Node*& head, Node*& tail) {
    Node* newNode = new Node{name, coffee, nullptr};
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void serveCustomer(Node*& head, Node*& tail) {
    if (head == nullptr) {
        return;
    } else {
        cout << "Serving: " << head->cusName << ", Ordered: " << head->cusOrder << endl;
    
        Node* temp = head;
        head = head->next;
    }

    if (head == nullptr) {
        tail = nullptr;
    }
}

void queueOutput(Node* head) {
    if (head != nullptr) {
        Node* current = head;
        while (current) {
            cout << current->cusName << " ordered " << current->cusOrder << endl;
            current = current->next;
        }
    }
}

// main function
int main() {

    vector<string> customerNames = {"Yoshi", "Link", "Zelda", "Ganondorf", "Impa", "Peach", "Mario", "Luigi", "Bowser", "Pauline", "King Dedede", "Fox", "Ness", "Lucas", "Ash", "Pikachu", "Isabelle", "Captain Toad"};
    vector<string> coffeeNames = {"Caramel Macchiato", "Vanilla Latte", "Hazelnut Mocha", "Pumpkin Spice Latte", "Coconut Cappuccino", "Irish Cream Coffee", "Maple Pecan Latte", "Almond Milk Flat White", "Salted Caramel Cold Brew", "White Chocolate Mocha"};
    
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < 3; i++) {
        addCustomer(customerNames[rand() % 18], coffeeNames[rand() % 10], head, tail);
    }

    for (int i = 0; i <= 9; i++) {
        cout << "Round: " << i + 1 << endl;

        if (head) {
            serveCustomer(head, tail);
        } else {
            cout << "No customers." << endl;
        }

        if (rand() % 2 == 0) {
            addCustomer(customerNames[rand() % 18], coffeeNames[rand() % 10], head, tail);
        }

        queueOutput(head);
    }

    return 0;
}