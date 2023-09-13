
/*Observer Design Pattern:
The Observer design pattern is a behavioral pattern that defines a one-to-many dependency 
between objects so that when one object (the subject) changes state, all its dependents 
(observers) are notified and updated automatically. This pattern is useful for building 
systems where the state of one object needs to be reflected in the state of other objects.*/

/*In this code, the Observer pattern is applied by creating a relationship between a subject 
(Moodle) and one or more observers (Student). Observers are notified whenever the subject's 
state (course scores) changes. This allows the Student observer to react to changes in the 
"algo" course score, demonstrating the decoupling of the subject and observer. This pattern 
is useful for scenarios where multiple objects need to stay synchronized with the state of 
a single object.*/

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Observer {
public:
    virtual void update(const char *course) = 0;
};

class Subject {
protected:
    vector<Observer *> observers;
public:
    void Attach(Observer *observer) {
        observers.push_back(observer);
    }

    void Detach(Observer *observer) {
        for (auto o : observers)
            if (o == observer)
                observer = nullptr;
    }

    virtual void Notify(const char* course) {
        for (auto o : observers)
            if (o != nullptr)
                o->update(course);
    }
};

class Moodle : public Subject {
    int mathScore, algoScore;
public:
    Moodle() {
        mathScore = 0;
        algoScore = 0;
    }
    void setScore(const char *course, int score) {
        if (strcmp(course, "algo") == 0) {
            algoScore = score;
            Notify("algo");
            return;
        }
        if (strcmp(course, "math") == 0) {
            mathScore = score;
            Notify("math");
        }
    }
    int getScore(const char* course) const {
        if (strcmp(course, "algo") == 0)
            return algoScore;
        if (strcmp(course, "math") == 0)
            return mathScore;
        return 0;
    }
};

class Student : public Observer {
    Moodle* moodle;
public:
    Student(Moodle* moodle) {
        this->moodle = moodle;
    }
    void update(const char *course) override {
        cout << "Update in " << course << "'s score." << endl;
        if (strcmp(course, "algo") == 0) {
            if(moodle->getScore("algo") > 90)
                cout << "WOW." << endl;
        }
    }
};

int main() {
    Moodle* moodle = new Moodle();
    Student* s = new Student(moodle);
    moodle->Attach(s);
    moodle->setScore("math", 90);
    moodle->setScore("algo", 80);
    moodle->setScore("algo", 95);
}
