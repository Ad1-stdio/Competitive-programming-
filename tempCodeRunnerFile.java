#include <iostream>
#include <string>
using namespace std;

// Base Class 1
class Shape {
protected:
    double width;
    double height;
public:
    void setDimensions(double w, double h) {
        width = w;
        height = h;
    }
};

// Base Class 2
class Color {
protected:
    string colorName;
public:
    void setColor(string c) {
        colorName = c;
    }
};

// Multiple Inheritance: Rectangle inherits from Shape AND Color
class Rectangle : public Shape, public Color {
public:
    double calculateArea() {
        return width * height;
    }
};

// Multilevel Inheritance: ColoredRectangle inherits from Rectangle
class ColoredRectangle : public Rectangle {
public:
    void displayDetails() {
        cout << "Area of ColoredRectangle (width=" << width 
            << ", height=" << height << "): " << calculateArea() 
            << " sq units, Color: " << colorName << endl;
    }
};

int main() {
    ColoredRectangle cr;
    
    // Setting values using inherited methods
    cr.setDimensions(5, 3);
    cr.setColor("Red");
    
    // Display result
    cr.displayDetails();

    return 0;
}