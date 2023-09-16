#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Command interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver
class Light {
public:
    void turnOn() {
        cout << "Light is on" << endl;
    }
    
    void turnOff() {
        cout << "Light is off" << endl;
    }
};

// Concrete command for turning the light on
class LightOnCommand : public Command {
private:
    Light& light;
public:
    LightOnCommand(Light& l) : light(l) {}

    void execute() override {
        light.turnOn();
    }
};

// Concrete command for turning the light off
class LightOffCommand : public Command {
private:
    Light& light;
public:
    LightOffCommand(Light& l) : light(l) {}

    void execute() override {
        light.turnOff();
    }
};

// Room class representing a room in the house
class Room {
private:
    Light light;

public:
    string roomName;
    bool lightStage = false;
    
    Room(string roomName) : roomName(roomName) {}
    
    Command* createLightOnCommand() {
        return new LightOnCommand(light);
    }

    Command* createLightOffCommand() {
        return new LightOffCommand(light);
    }
};

// Invoker
class RemoteControl {
private:
    std::map<int, Room*> rooms;

public:
    void addRoom(int roomNumber, Room* room) {
        rooms[roomNumber] = room;
    }

    void pressButton(int roomNumber) {
        if (rooms.find(roomNumber) != rooms.end()) {
            Command* command = !(rooms[roomNumber]->lightStage) ? rooms[roomNumber]->createLightOnCommand() : rooms[roomNumber]->createLightOffCommand();
            rooms[roomNumber]->lightStage = !(rooms[roomNumber]->lightStage);
            if (command) {
                cout << rooms[roomNumber]->roomName << " - ";
                command->execute();
                delete command;
            }
        } else {
            cout << "Invalid room number: " << roomNumber << endl;
        }
    }
};

int main() {
    Room livingRoom("Living Room");
    Room kitchen("Kitchen");
    Room bedroom("Bedroom");

    RemoteControl remote;

    // Add rooms to the remote control
    remote.addRoom(1, &livingRoom);
    remote.addRoom(2, &kitchen);
    remote.addRoom(3, &bedroom);

    // Press the button to turn on/off lights in specific rooms
    remote.pressButton(1); // Turn on living room light
    remote.pressButton(2); // Turn on kitchen light
    remote.pressButton(3); // Turn on bedroom light
    remote.pressButton(2); // Turn off kitchen light

    return 0;
}
