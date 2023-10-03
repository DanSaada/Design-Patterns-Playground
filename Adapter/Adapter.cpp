#include <iostream>

// Legacy class with incompatible interface
class LegacyPrinter {
public:
    void printDocument() {
        std::cout << "Printing document..." << std::endl;
    }
};

// Modern interface
class Printer {
public:
    virtual void print() = 0;
    virtual void scan() = 0;
};

// Adapter to make LegacyPrinter compatible with Printer interface
class LegacyPrinterAdapter : public Printer {
private:
    LegacyPrinter* legacyPrinter;

public:
    LegacyPrinterAdapter(LegacyPrinter* legacyPrinter) : legacyPrinter(legacyPrinter) {}

    void print() override {
        legacyPrinter->printDocument();
    }

    void scan() override {
        std::cout << "Scanning document..." << std::endl;
    }
};

int main() {
    LegacyPrinter legacyPrinter;
    LegacyPrinterAdapter adapter(&legacyPrinter);

    // Using the adapted LegacyPrinter as a Printer
    Printer* printer = &adapter;

    printer->print(); // Uses the adapted print method
    printer->scan();  // Uses the new scan method

    return 0;
}
