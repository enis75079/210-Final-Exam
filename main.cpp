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

// addCustomer function. adds a customer to the coffee queue
void addCustomer(const string& name, const string& coffee, Node*& head, Node*& tail) {
    Node* newNode = new Node{name, coffee, nullptr};
    if (head == nullptr) {
        // if queue is empty, then sets the new node to tail and head
        head = newNode;
        tail = newNode;
    } else {
        // appends the new node to the tail
        tail->next = newNode;
        tail = newNode;
    }
}

// serveCustomer function. removes the customer at the front of the coffee queue to serve next in linked list
void serveCustomer(Node*& head, Node*& tail) {
    if (head == nullptr) {
        // doesnt serve if queue is empty
        return;
    } else {
        cout << "Serving: " << head->cusName << ", Ordered: " << head->cusOrder << endl;

        // creates temporary pointer to the node that will be removed
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == nullptr) {
        // if queue is empty, makes the tail null
        tail = nullptr;
    }
}

// queueOutput function. outputs the current coffee booth queue
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

// dequeVendor function. muffin booth queue using deque
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

    // for current queue
    if (!queue.empty()) {
        cout << "Muffin Booth Queue: " << endl;
        for (const auto& cus : queue) {
            cout << cus.cusName << " wants " << cus.cusOrder << endl;
        }
    }

}

// vectorVendor function. bracelet booth queue using vectors
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

    // for current queue
    if (!queue.empty()) {
        cout << "Bracelet Booth Queue: " << endl;
        for (const auto& cus : queue) {
            cout << cus.cusName << " wants " << cus.cusOrder << endl;
        }
    }
}

// mapVendor function. game booth queue using maps
void mapVendor(map<string, string>& queue, const string& vendor, vector<string>& names, vector<string>& games) {
    if (!queue.empty()) {
        auto it = queue.begin();
        cout << "Serving: " << it->first << ", Ordered: " << it->second << endl;
        queue.erase(it);
    } else {
        cout << "No customers." << endl;
        cout << endl;
    }

    if (rand() % 2 == 0) {
        string name = names[rand() % 18];
        string order = games[rand() % 10];
        queue[name] = order;
    }
    if (!queue.empty()) {
        cout << "Game Booth Queue: " << endl;
        for (const auto& cus : queue) {
            cout << cus.first << " wants " << cus.second << endl;
        }
        cout << endl;
    }
}

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

    // initializes the queue with 3 customers for each booth
    for (int i = 0; i < 3; i++) {
        addCustomer(customerNames[rand() % 18], coffeeNames[rand() % 10], head, tail);
        muffins.push_back({customerNames[rand() % 18], muffinNames[rand() % 10]});
        bracelets.push_back({customerNames[rand() % 18], muffinNames[rand() % 10]});
        switches[customerNames[rand() % 18]] = coffeeNames[rand() % 10];
    }

    // simulation for 10 rounds
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

        // calling the dequeVendor function to simulate the muffin booth queue
        dequeVendor(muffins, "Muffins Booth", customerNames, muffinNames);

        // calling the vectorVendor function to simulate the bracelet booth queue
        vectorVendor(bracelets, "Bracelets Booth", customerNames, braceletNames);

        // calling the mapVendor function to simulate the game booth queue
        mapVendor(switches, "Game Booth", customerNames, switchNames);
    }

    return 0;
}