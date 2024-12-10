/*

210 final exam
COMSC-210
Naveen Islam

*/

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

// function prototypes

// struct for node in linked list got coffee booth queue simulation
struct Node {
    string cusName;
    string cusOrder;
    Node* next;
};

void addCustomer(const string& name, const string& coffee, Node*& head) {
    Node* newNode = new Node{name, coffee, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
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

    // for random generation each runtime
    srand(static_cast<unsigned>(time(nullptr)));

    string customerNames[] = {"Yoshi", "Link", "Zelda", "Ganondorf", "Impa", "Peach", "Mario", "Luigi", "Bowser", "Pauline", "King Dedede", "Fox", "Ness", "Lucas", "Ash", "Pikachu", "Isabelle", "Captain Toad"};
    string coffeeNames[] = {"Caramel Macchiato", "Vanilla Latte", "Hazelnut Mocha", "Pumpkin Spice Latte", "Coconut Cappuccino", "Irish Cream Coffee", "Maple Pecan Latte", "Almond Milk Flat White", "Salted Caramel Cold Brew", "White Chocolate Mocha"};
    
    Node* head = nullptr;

    for (int i = 0; i < 3; i++) {
        addCustomer(customerNames[i], coffeeNames[i], head);
    }

    queueOutput(head);

    return 0;
}