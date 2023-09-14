
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

import java.util.ArrayList;
import java.util.List;

interface Observer {
    void update(String course);
}

class Subject {
    protected List<Observer> observers = new ArrayList<>();

    void attach(Observer observer) {
        observers.add(observer);
    }

    void detach(Observer observer) {
        observers.remove(observer);
    }

    void notify(String course) {
        for (Observer o : observers) {
            o.update(course);
        }
    }
}

class Moodle extends Subject {
    private int mathScore;
    private int algoScore;

    Moodle() {
        mathScore = 0;
        algoScore = 0;
    }

    void setScore(String course, int score) {
        if ("algo".equals(course)) {
            algoScore = score;
            notify("algo");
        } else if ("math".equals(course)) {
            mathScore = score;
            notify("math");
        }
    }

    int getScore(String course) {
        if ("algo".equals(course)) {
            return algoScore;
        } else if ("math".equals(course)) {
            return mathScore;
        }
        return 0;
    }
}

class Student implements Observer {
    private Moodle moodle;

    Student(Moodle moodle) {
        this.moodle = moodle;
    }

    @Override
    public void update(String course) {
        System.out.println("Update in " + course + "'s score.");
        if ("algo".equals(course)) {
            if (moodle.getScore("algo") > 90) {
                System.out.println("WOW.");
            }
        }
    }
}

// make sure to put this class in another file.
public class Main {
    public static void main(String[] args) {
        Moodle moodle = new Moodle();
        Student s = new Student(moodle);
        moodle.attach(s);
        moodle.setScore("math", 90);
        moodle.setScore("algo", 80);
        moodle.setScore("algo", 95);
    }
}
