#include <iostream>
#include <stack>  // STL approach

using namespace std;
class Point {
public:
    int x, y;

    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Overloading unary minus (-) operator
    Point operator-() const {
        return Point(-x, -y);
    }

    // Overloading binary plus (+) operator
    Point operator+(const Point& p) const {
        return Point(x + p.x, y + p.y);
    }

    // Overloading equality (==) operator
    bool operator==(const Point& p) const {
        return x == p.x && y == p.y;
    }

    // Display function
    void display() const {
        cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

// STL Approach: Using std::stack for undo functionality
class OperationStackSTL {
private:
    stack<Point> history;

public:
    void push(const Point& p) {
        history.push(p);
    }

    Point undo() {
        if (!history.empty()) {
            Point lastOp = history.top();
            history.pop();
            return lastOp;
        } else {
            return Point();  // Default point if stack is empty
        }
    }
};

// Non-STL Approach: Using an array-based stack implementation
class OperationStackManual {
private:
    Point history[100];  // Fixed size array
    int top;

public:
    OperationStackManual() : top(-1) {}

    void push(const Point& p) {
        if (top < 99) {
            history[++top] = p;
        }
    }

    Point undo() {
        if (top >= 0) {
            return history[top--];
        } else {
            return Point();
        }
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    
    OperationStackSTL operationsSTL;
    Point p3 = p1 + p2;
    operationsSTL.push(p3);
    Point p4 = -p1;
    operationsSTL.push(p4);

    
    cout << "After Addition: "; p3.display();
    cout << "After Negation: "; p4.display();
    cout << "Undo Last Operation: "; operationsSTL.undo().display();

    
    OperationStackManual operationsManual;
    operationsManual.push(p3);
    operationsManual.push(p4);

    cout << "------------------------"<<endl;
    cout << "Undo Last Operation: "; operationsManual.undo().display();

    cout << endl
         << endl
         << "24DIT006_PRINCEE BHINGRADIYA" << endl
         << endl;

    return 0;
}