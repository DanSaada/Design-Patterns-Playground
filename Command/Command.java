import java.util.HashMap;
import java.util.Map;

// Command interface
interface Command {
    void execute();
}

// Receiver
class Light {
    void turnOn() {
        System.out.println("Light is on");
    }

    void turnOff() {
        System.out.println("Light is off");
    }
}

// Concrete command for turning the light on
class LightOnCommand implements Command {
    private final Light light;

    LightOnCommand(Light l) {
        this.light = l;
    }

    public void execute() {
        light.turnOn();
    }
}

// Concrete command for turning the light off
class LightOffCommand implements Command {
    private final Light light;

    LightOffCommand(Light l) {
        this.light = l;
    }

    public void execute() {
        light.turnOff();
    }
}

// Room class representing a room in the house
class Room {
    private final Light light;
    String roomName;
    boolean lightStage = false;

    Room(String roomName) {
        this.roomName = roomName;
        this.light = new Light();
    }

    Command createLightOnCommand() {
        return new LightOnCommand(light);
    }

    Command createLightOffCommand() {
        return new LightOffCommand(light);
    }
}

// Invoker
class RemoteControl {
    private final Map<Integer, Room> rooms = new HashMap<>();

    void addRoom(int roomNumber, Room room) {
        rooms.put(roomNumber, room);
    }

    void pressButton(int roomNumber) {
        Room selectedRoom = rooms.get(roomNumber);
        if (selectedRoom != null) {
            Command command = selectedRoom.lightStage ? selectedRoom.createLightOffCommand() : selectedRoom.createLightOnCommand();
            selectedRoom.lightStage = !selectedRoom.lightStage;
            if (command != null) {
                System.out.print(selectedRoom.roomName + " - ");
                command.execute();
            }
        } else {
            System.out.println("Invalid room number: " + roomNumber);
        }
    }
    
        public static void main(String[] args) {
        Room livingRoom = new Room("Living Room");
        Room kitchen = new Room("Kitchen");
        Room bedroom = new Room("Bedroom");

        RemoteControl remote = new RemoteControl();

        // Add rooms to the remote control
        remote.addRoom(1, livingRoom);
        remote.addRoom(2, kitchen);
        remote.addRoom(3, bedroom);

        // Press the button to turn on/off lights in specific rooms
        remote.pressButton(1); // Turn on living room light
        remote.pressButton(2); // Turn on kitchen light
        remote.pressButton(3); // Turn on bedroom light
        remote.pressButton(2); // Turn off kitchen light
    }
}
