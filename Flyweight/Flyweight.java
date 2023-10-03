import java.util.HashMap;
import java.util.Map;

// Flyweight interface
interface MusicalNote {
    void play(int duration);
}

// Concrete Flyweight
class ConcreteMusicalNote implements MusicalNote {
    private final String note; // Intrinsic state (shared)

    public ConcreteMusicalNote(String note) {
        this.note = note;
    }

    @Override
    public void play(int duration) {
        // Play the musical note using the shared intrinsic state and the provided duration
        System.out.println("Playing note " + note + " for " + duration + " milliseconds.");
    }
}

// Flyweight Factory
class MusicalNoteFactory {
    private final Map<String, ConcreteMusicalNote> notePool = new HashMap<>();

    public MusicalNote getMusicalNote(String note) {
        if (!notePool.containsKey(note)) {
            notePool.put(note, new ConcreteMusicalNote(note));
        }
        return notePool.get(note);
    }
}

public class MusicPlayer {
    public static void main(String[] args) {
        MusicalNoteFactory noteFactory = new MusicalNoteFactory();

        // Client code
        String[] melody = {"C", "D", "E", "F", "G", "A", "B"};

        for (String note : melody) {
            MusicalNote musicalNote = noteFactory.getMusicalNote(note);
            musicalNote.play(200); // Play each note for 200 milliseconds
        }
    }
}
