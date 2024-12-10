/*

210 final exam
COMSC-210
Naveen Islam

*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <map>
using namespace std;

// function prototypes

// struct for node in linked list got coffee booth queue simulation
struct Node {
    string cusName;
    string cusOrder;
    Node* next;
};

struct Customer {
    string cusName;
    string cusOrder;
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
        cout << "Coffee Booth Queue: " << endl;
        while (current) {
            cout << current->cusName << " wants " << current->cusOrder << endl;
            current = current->next;
        }
    }
}

void dequeVendor(deque<Customer>& queue, const string& vendor, vector<string>& names, vector<string>& muffins) {
    if (!queue.empty()) {
        Customer cus = queue.front();
        queue.pop_front();
        cout << "Serving: " << cus.cusName << ", Ordered: " << cus.cusOrder << endl;
    } else {
        cout << "No customers." << endl;
    }

    if (rand() % 2 == 0) {
        queue.push_back({names[rand() % 18], muffins[rand() % 10]});
    }

    if (!queue.empty()) {
        cout << "Muffin Booth Queue: " << endl;
        for (const auto& cus : queue) {
            cout << cus.cusName << " wants " << cus.cusOrder << endl;
        }
    }

}

void vectorVendor(vector<Customer>& queue, const string& vendor, vector<string>& names, vector<string>& bracelets) {
    if (!queue.empty()) {
        Customer cus = queue.front();
        cout << "Serving: " << cus.cusName << ", Ordered: " << cus.cusOrder << endl;
    } else {
        cout << "No customers." << endl;
    }

    if (rand() % 2 == 0) {
        queue.push_back({names[rand() % 18], bracelets[rand() % 10]});
    }

    if (!queue.empty()) {
        cout << "Bracelet Booth Queue: " << endl;
        for (const auto& cus : queue) {
            cout << cus.cusName << " wants " << cus.cusOrder << endl;
        }
    }
}

void mapVendor(map<string, string>& queue, const string& vendor)

// main function
int main() {

    vector<string> customerNames = {"Yoshi", "Link", "Zelda", "Ganondorf", "Impa", "Peach", "Mario", "Luigi", "Bowser", "Pauline", "King Dedede", "Fox", "Ness", "Lucas", "Ash", "Pikachu", "Isabelle", "Captain Toad"};
    vector<string> coffeeNames = {"Caramel Macchiato", "Vanilla Latte", "Hazelnut Mocha", "Pumpkin Spice Latte", "Coconut Cappuccino", "Irish Cream Coffee", "Maple Pecan Latte", "Almond Milk Flat White", "Salted Caramel Cold Brew", "White Chocolate Mocha"};
    vector<string> muffinNames = {"Chocolate Chip Muffin", "Egg Muffin", "Strawberry Muffin", "Pumpkin Spice Muffin", "Banana Nut Muffin", "Rebel Muffin", "Keto Blueberry Muffin", "Apple Cinnamon Muffin", "Keto Double Chocolate Muffin", "2x2 Muffin"};
    vector<string> braceletNames = {"Beaded Bracelet", "Woven Bracelet", "Friendship Bracelet", "Charm Bracelet", "Macrame Bracelet", "Custom Name Bracelet", "Infinity Bracelet", "Heart Bracelet", "Gummy Bracelet", "Spike Bracelet"};
    vector<string> switchNames = {"Super Mario Odyssey", "Mario Kart 8 Deluxe", "The Legend of Zelda - Breath of the Wild", "Super Smash Bros. Ultimate", "Animal Crossing - New Horizons", "Splatoon 3", "Luigi's Mansion 3", "Kirby and the Forgotten Land", "Xenoblade Chronicles 3", "Switch Sports"};

    Node* head = nullptr;
    Node* tail = nullptr;

    deque<Customer> muffins;

    vector<Customer> bracelets;

    map<string, string> switches;



    for (int i = 0; i < 3; i++) {
        addCustomer(customerNames[rand() % 18], coffeeNames[rand() % 10], head, tail);
        muffins.push_back({customerNames[rand() % 18], muffinNames[rand() % 10]});
        bracelets.push_back({customerNames[rand() % 18], muffinNames[rand() % 10]});
        switches[customerNames[rand() % 18]] = coffeeNames[rand() % 10];
    }

    for (int i = 0; i <= 9; i++) {
        cout << endl;
        cout << "Round: " << i + 1 << endl;

        if (head) {
            serveCustomer(head, tail);
            cout << endl;
        } else {
            cout << "No customers." << endl;
        }

        if (rand() % 2 == 0) {
            addCustomer(customerNames[rand() % 18], coffeeNames[rand() % 10], head, tail);
        }

        queueOutput(head);

        dequeVendor(muffins, "Muffins Booth", customerNames, muffinNames);

        vectorVendor(bracelets, "Bracelets Booth", customerNames, braceletNames);
    }

    return 0;
}