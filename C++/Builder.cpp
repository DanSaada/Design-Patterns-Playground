
/*Builder Design Pattern:
The Builder design pattern is a creational pattern that separates the construction 
of a complex object from its representation, allowing the same construction process 
to create different representations. 
It is useful when you have a complex object with many optional parameters or configurations.*/

/*This code demonstrates how the Builder design pattern can be used to create Computer objects 
with flexible configuration options, allowing for easy construction of complex objects with 
various specifications.*/

#include <iostream>
#include <string>

using namespace std;

class Computer {
    friend class ComputerBuilder;
    string cpu;
    string gpu;
    int ramGb;
    int storageGb;

    Computer(const string& cpu, const string& gpu, int ramGb, int storageGb)
        : cpu(cpu), gpu(gpu), ramGb(ramGb), storageGb(storageGb) {}

public:
    void print() const {
        cout << "Computer Specifications:" << endl;
        cout << "\tCPU: " << (cpu.empty() ? "N/A" : cpu) << endl;
        cout << "\tGPU: " << (gpu.empty() ? "N/A" : gpu) << endl;
        cout << "\tRAM: " << ramGb << " GB" << endl;
        cout << "\tStorage: " << storageGb << " GB" << endl;
    }
};

class ComputerBuilder {
    string cpu;
    string gpu;
    int ramGb;
    int storageGb;

public:
    ComputerBuilder() : ramGb(0), storageGb(0) {}

    ComputerBuilder& setCPU(const string& cpu) {
        this->cpu = cpu;
        return *this;
    }

    ComputerBuilder& setGPU(const string& gpu) {
        this->gpu = gpu;
        return *this;
    }

    ComputerBuilder& setRAM(int ramGb) {
        this->ramGb = ramGb;
        return *this;
    }

    ComputerBuilder& setStorage(int storageGb) {
        this->storageGb = storageGb;
        return *this;
    }

    Computer build() const {
        return Computer(cpu, gpu, ramGb, storageGb);
    }
};

int main() {
    ComputerBuilder computerBuilder;
    Computer myComputer = computerBuilder.setCPU("Intel i7")
                                          .setGPU("NVIDIA GeForce RTX 3080")
                                          .setRAM(16)
                                          .setStorage(512)
                                          .build();
    myComputer.print();

    Computer anotherComputer = computerBuilder.setCPU("AMD Ryzen 9")
                                              .setGPU("AMD Radeon RX 6900 XT")
                                              .setRAM(32)
                                              .setStorage(1000)
                                              .build();
    anotherComputer.print();

    return 0;
}

