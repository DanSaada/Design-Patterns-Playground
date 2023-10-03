#include <iostream>
#include <string>
#include <unordered_map>

// Flyweight interface
class MusicalNote {
public:
    virtual void play(int duration) = 0;
};

// Concrete Flyweight
class ConcreteMusicalNote : public MusicalNote {
private:
    std::string note; // Intrinsic state (shared)

public:
    ConcreteMusicalNote(const std::string& note) : note(note) {}

    void play(int duration) override {
        // Play the musical note using the shared intrinsic state and provided duration
        std::cout << "Playing note " << note << " for " << duration << " milliseconds." << std::endl;
    }
};

// Flyweight Factory
class MusicalNoteFactory {
private:
    std::unordered_map<std::string, MusicalNote*> notePool;

public:
    MusicalNote* getMusicalNote(const std::string& note) {
        if (notePool.find(note) == notePool.end()) {
            notePool[note] = new ConcreteMusicalNote(note);
        }
        return notePool[note];
    }

    ~MusicalNoteFactory() {
        for (const auto& entry : notePool) {
            delete entry.second;
        }
    }
};

int main() {
    MusicalNoteFactory noteFactory;

    // Client code
    std::string melody[] = {"C", "D", "E", "F", "G", "A", "B"};

    for (const std::string& note : melody) {
        MusicalNote* musicalNote = noteFactory.getMusicalNote(note);
        musicalNote->play(200); // Play each note for 200 milliseconds
    }

    return 0;
}
