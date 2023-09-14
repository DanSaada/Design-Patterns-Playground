
/*The Singleton design pattern is a creational design pattern that ensures a class has 
only one instance and provides a global point of access to that instance. This means that 
no matter how many times you request an instance of the Singleton class, you will always 
get the same instance.*/

/*In the provided example, the Singleton pattern ensures that there is a single instance 
of the Spaceship class, and this instance is created on-demand when you call getSpaceship. 
It allows you to share and reuse this instance across different parts of your code, ensuring
consistency and preventing multiple instances of Spaceship from being created accidentally.*/

/*when you run the code, it creates a Spaceship Singleton and prints out the names of two 
spaceship instances. Here's what would be printed out:
s1 name: I am Spaceship999
s2 name: I am Spaceship999
Both s1 and s2 refer to the same instance of the Spaceship Singleton, so they both have the
 same name, "Spaceship999."
*/

class Spaceship {
    private String name;

    private Spaceship() {
        name = "Spaceship999";
    }

    public void describe() {
        System.out.println("I am " + name);
    }

    public static Spaceship getInstance() {
        return SpaceshipHolder.INSTANCE;
    }

    private static class SpaceshipHolder {
        private static final Spaceship INSTANCE = new Spaceship();
    }
}

// make sure to put this class in a different file
public class Main {
    public static void main(String[] args) {
        Spaceship s1 = Spaceship.getInstance();
        System.out.print("s1 name: ");
        s1.describe();

        Spaceship s2 = Spaceship.getInstance();
        System.out.print("s2 name: ");
        s2.describe();
    }
}