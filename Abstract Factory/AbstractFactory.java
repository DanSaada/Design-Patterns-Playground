// Abstract Factory Interface
interface UIFactory {
    Button createButton();
    Dialog createDialog();
}

// Concrete Factories
class WindowsUIFactory implements UIFactory {
    public Button createButton() {
        return new WindowsButton();
    }

    public Dialog createDialog() {
        return new WindowsDialog();
    }
}

class MacOSUIFactory implements UIFactory {
    public Button createButton() {
        return new MacOSButton();
    }

    public Dialog createDialog() {
        return new MacOSDialog();
    }
}

// Abstract Product Interfaces
interface Button {
    void render();
    void onClick();
}

interface Dialog {
    void show();
}

// Concrete Products for Windows
class WindowsButton implements Button {
    public void render() {
        // Render Windows button
    }

    public void onClick() {
        // Handle Windows button click
    }
}

class WindowsDialog implements Dialog {
    public void show() {
        // Show Windows dialog
    }
}

// Concrete Products for macOS
class MacOSButton implements Button {
    public void render() {
        // Render macOS button
    }

    public void onClick() {
        // Handle macOS button click
    }
}

class MacOSDialog implements Dialog {
    public void show() {
        // Show macOS dialog
    }
}

public class Main {
    public static void main(String[] args) {
        // Choose the desired UI factory based on the platform
        UIFactory uiFactory;
        String platform = "macOS"; // Change this to "Windows" to use Windows UI
        if (platform.equals("macOS")) {
            uiFactory = new MacOSUIFactory();
        } else if (platform.equals("Windows")) {
            uiFactory = new WindowsUIFactory();
        } else {
            throw new IllegalArgumentException("Invalid platform: " + platform);
        }

        // Create UI components using the factory
        Button button = uiFactory.createButton();
        Dialog dialog = uiFactory.createDialog();

        // Use the created UI components
        button.render();
        button.onClick();

        dialog.show();
    }
}

