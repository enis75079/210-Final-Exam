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
void addCustomer(string&, string&, Node&, Node&);

// struct for node in linked list got coffee booth queue simulation
struct Node {
    string cusName;
    string cusOrder;
    Node* next;
};

void addCustomer(string& name, string& coffee, Node& begin, Node& end) {

}

int main() {
    string customerNames[] = {"Yoshi", "Link", "Zelda", "Ganondorf", "Impa", "Peach", "Mario", "Luigi", "Bowser", "Pauline", "King Dedede", "Fox", "Ness", "Lucas", "Ash", "Pikachu", "Isabelle", "Captain Toad"};
    string coffeeNames[] = {"Caramel Macchiato", "Vanilla Latte", "Hazelnut Mocha", "Pumpkin Spice Latte", "Coconut Cappuccino", "Irish Cream Coffee", "Maple Pecan Latte", "Almond Milk Flat White", "Salted Caramel Cold Brew", "White Chocolate Mocha"};
    
    return 0;
}