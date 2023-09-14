
/*Builder Design Pattern:
The Builder design pattern is a creational pattern that separates the construction 
of a complex object from its representation, allowing the same construction process 
to create different representations. 
It is useful when you have a complex object with many optional parameters or configurations.*/

/*This code demonstrates how the Builder design pattern can be used to create Computer objects 
with flexible configuration options, allowing for easy construction of complex objects with 
various specifications.*/

public class Computer {
    private String cpu;
    private String gpu;
    private int ramGb;
    private int storageGb;

    private Computer(String cpu, String gpu, int ramGb, int storageGb) {
        this.cpu = cpu;
        this.gpu = gpu;
        this.ramGb = ramGb;
        this.storageGb = storageGb;
    }

    public void print() {
        System.out.println("Computer Specifications:");
        System.out.println("\tCPU: " + (cpu.isEmpty() ? "N/A" : cpu));
        System.out.println("\tGPU: " + (gpu.isEmpty() ? "N/A" : gpu));
        System.out.println("\tRAM: " + ramGb + " GB");
        System.out.println("\tStorage: " + storageGb + " GB");
    }

    public static class ComputerBuilder {
        private String cpu;
        private String gpu;
        private int ramGb;
        private int storageGb;

        public ComputerBuilder() {
            // Default values
            ramGb = 0;
            storageGb = 0;
        }

        public ComputerBuilder setCPU(String cpu) {
            this.cpu = cpu;
            return this;
        }

        public ComputerBuilder setGPU(String gpu) {
            this.gpu = gpu;
            return this;
        }

        public ComputerBuilder setRAM(int ramGb) {
            this.ramGb = ramGb;
            return this;
        }

        public ComputerBuilder setStorage(int storageGb) {
            this.storageGb = storageGb;
            return this;
        }

        public Computer build() {
            return new Computer(cpu, gpu, ramGb, storageGb);
        }
    }

    public static void main(String[] args) {
        ComputerBuilder computerBuilder = new ComputerBuilder();
        Computer myComputer = computerBuilder
                .setCPU("Intel i7")
                .setGPU("NVIDIA GeForce RTX 3080")
                .setRAM(16)
                .setStorage(512)
                .build();
        myComputer.print();

        Computer anotherComputer = computerBuilder
                .setCPU("AMD Ryzen 9")
                .setGPU("AMD Radeon RX 6900 XT")
                .setRAM(32)
                .setStorage(1000)
                .build();
        anotherComputer.print();
    }
}
