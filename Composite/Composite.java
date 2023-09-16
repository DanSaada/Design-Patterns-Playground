import java.util.ArrayList;
import java.util.List;

// Component interface
interface Employee {
    void showDetails();
}

// Leaf class
class Developer implements Employee {
    private String name;

    public Developer(String name) {
        this.name = name;
    }

    public void showDetails() {
        System.out.println("Developer: " + name);
    }
}

// Composite class
class Manager implements Employee {
    private String name;
    private List<Employee> subordinates = new ArrayList<>();

    public Manager(String name) {
        this.name = name;
    }

    public void addSubordinate(Employee employee) {
        subordinates.add(employee);
    }

    public void showDetails() {
        System.out.println("Manager: " + name);
        for (Employee subordinate : subordinates) {
            subordinate.showDetails();
        }
    }
    
        public static void main(String[] args) {
        Manager ceo = new Manager("John (CEO)");
        Manager engineeringHead = new Manager("Alice (Engineering Head)");
        Developer dev1 = new Developer("Bob");
        Developer dev2 = new Developer("Charlie");

        engineeringHead.addSubordinate(dev1);
        engineeringHead.addSubordinate(dev2);
        ceo.addSubordinate(engineeringHead);

        ceo.showDetails();
    }
}
