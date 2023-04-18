#define PI 3.141592654
#include "mbed.h"
#include "MMA7660.h"


class Shape {
public:

    enum shape_is {square, triangle, circle};

    // Constructor
    Shape(int a) {
        _a = a;
        shape_type = square;
    }

    Shape(int a, int b) {
        _a = a;
        _b = b;
        if (_b == 0)
            shape_type = circle;
        else 
            shape_type = triangle;
    }

    float area() {
        if (shape_type == circle)
            return (PI*_a*_a);
        if (shape_type == triangle)
            return (_a*_b*0.5);
        if (shape_type == square)
            return (_a*_a);
    }

    float perimeter() {
        if (shape_type == circle)
            return (2*PI*_a);
        if (shape_type == triangle)
            return (_a + sqrt(static_cast<float>(_a*_a + 4*_b*_b)) + sqrt(static_cast<float>(_b*_b + 4*_a*_a)));
        if (shape_type == square)
            return (4*_a);
    }

    void print_shape() {
        if (shape_type == circle)
            printf("Shape is a circle\r\n");
        if (shape_type == triangle)
            printf("Shape is a triangle\r\n");
        if (shape_type == square)
            printf("Shape is a square\r\n");
    }

private:
    int _a;
    int _b;
    shape_is shape_type;
};


int main() {  
    // Input
    Shape square(5);
    Shape triangle(3,1);
    Shape circle(6,0);

    square.print_shape();
    printf("area is %f, perimeter is %f\r\n", square.area(), square.perimeter());
    circle.print_shape();
    printf("area is %f, perimeter is %f\r\n", circle.area(), circle.perimeter());
    triangle.print_shape();
    printf("area is %f, perimeter is %f\r\n", triangle.area(), triangle.perimeter());
}
