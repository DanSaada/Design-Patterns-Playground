#include <iostream>

// Abstract Product Interfaces
class Button {
public:
    virtual void render() = 0;
    virtual void onClick() = 0;
};

class Dialog {
public:
    virtual void show() = 0;
};

// Concrete Products for Windows
class WindowsButton : public Button {
public:
    void render() override {
        // Render Windows button
        std::cout << "Rendering Windows button." << std::endl;
    }

    void onClick() override {
        // Handle Windows button click
        std::cout << "Handling Windows button click." << std::endl;
    }
};

class WindowsDialog : public Dialog {
public:
    void show() override {
        // Show Windows dialog
        std::cout << "Showing Windows dialog." << std::endl;
    }
};

// Concrete Products for macOS
class MacOSButton : public Button {
public:
    void render() override {
        // Render macOS button
        std::cout << "Rendering macOS button." << std::endl;
    }

    void onClick() override {
        // Handle macOS button click
        std::cout << "Handling macOS button click." << std::endl;
    }
};

class MacOSDialog : public Dialog {
public:
    void show() override {
        // Show macOS dialog
        std::cout << "Showing macOS dialog." << std::endl;
    }
};

// Abstract Factory Interface
class UIFactory {
public:
    virtual Button* createButton() = 0;
    virtual Dialog* createDialog() = 0;
};

// Concrete Factories
class WindowsUIFactory : public UIFactory {
public:
    Button* createButton() override {
        return new WindowsButton();
    }

    Dialog* createDialog() override {
        return new WindowsDialog();
    }
};

class MacOSUIFactory : public UIFactory {
public:
    Button* createButton() override {
        return new MacOSButton();
    }

    Dialog* createDialog() override {
        return new MacOSDialog();
    }
};

int main() {
    // Choose the desired UI factory based on the platform
    UIFactory* uiFactory;
    std::string platform = "macOS"; // Change this to "Windows" to use Windows UI
    if (platform == "macOS") {
        uiFactory = new MacOSUIFactory();
    } else if (platform == "Windows") {
        uiFactory = new WindowsUIFactory();
    } else {
        std::cerr << "Invalid platform: " << platform << std::endl;
        return 1;
    }

    // Create UI components using the factory
    Button* button = uiFactory->createButton();
    Dialog* dialog = uiFactory->createDialog();

    // Use the created UI components
    button->render();
    button->onClick();

    dialog->show();

    // Clean up
    delete button;
    delete dialog;
    delete uiFactory;

    return 0;
}
