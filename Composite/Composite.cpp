#include <iostream>
#include <vector>

using namespace std;

// Component interface
class Employee {
public:
    virtual void showDetails() = 0;
};

// Leaf class
class Developer : public Employee {
private:
    string name;

public:
    Developer(const string& name) : name(name) {}

    void showDetails() override {
        cout << "Developer: " << name << endl;
    }
};

// Composite class
class Manager : public Employee {
private:
    string name;
    vector<Employee*> subordinates;

public:
    Manager(const string& name) : name(name) {}

    void addSubordinate(Employee* employee) {
        subordinates.push_back(employee);
    }

    void showDetails() override {
        cout << "Manager: " << name << endl;
        for (Employee* subordinate : subordinates) {
            subordinate->showDetails();
        }
    }
};

int main() {
    Manager ceo("John (CEO)");
    Manager engineeringHead("Alice (Engineering Head)");
    Developer dev1("Bob");
    Developer dev2("Charlie");

    engineeringHead.addSubordinate(&dev1);
    engineeringHead.addSubordinate(&dev2);
    ceo.addSubordinate(&engineeringHead);

    ceo.showDetails();

    return 0;
}
