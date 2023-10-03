// Legacy class with incompatible interface
class LegacyPrinter {
    void printDocument() {
        System.out.println("Printing document...");
    }
}

// Modern interface
interface Printer {
    void print();
    void scan();
}

// Adapter to make LegacyPrinter compatible with Printer interface
class LegacyPrinterAdapter implements Printer {
    private LegacyPrinter legacyPrinter;

    public LegacyPrinterAdapter(LegacyPrinter legacyPrinter) {
        this.legacyPrinter = legacyPrinter;
    }

    @Override
    public void print() {
        legacyPrinter.printDocument();
    }

    @Override
    public void scan() {
        System.out.println("Scanning document...");
    }
}

// Client code
public class Main {
    public static void main(String[] args) {
        LegacyPrinter legacyPrinter = new LegacyPrinter();
        Printer printer = new LegacyPrinterAdapter(legacyPrinter);
        
        printer.print(); // Uses the adapted print method
        printer.scan();  // Uses the new scan method
    }
}
