
#include <iostream>
#include <cmath>

class Circle {
public:
    double x, y, r;

    Circle() : x(0), y(0), r(0) {} // Конструктор по умолчанию
    Circle(double x, double y, double r) : x(x), y(y), r(r) {} // Параметризованный конструктор
    
    // Конструктор копирования не требуется, так как все члены данных - простые типы

    void input() {
        std::cin >> x >> y >> r;
    }

    void output() const {
        std::cout << "Center: (" << x << ", " << y << "), Radius: " << r << std::endl;
    }

    double area() const {
        return M_PI * r * r;
    }

    bool contains(double px, double py) const {
        return (px - x) * (px - x) + (py - y) * (py - y) <= r * r;
    }

    Circle operator+(double factor) const {
        return Circle(x, y, r * factor);
    }

    Circle& operator+=(double factor) {
        r *= factor;
        return *this;
    }

    bool operator==(const Circle& other) const {
        return r == other.r;
    }

    bool operator!=(const Circle& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Circle& c);
    friend std::istream& operator>>(std::istream& is, Circle& c);
};

std::ostream& operator<<(std::ostream& os, const Circle& c) {
    os << "Center: (" << c.x << ", " << c.y << "), Radius: " << c.r;
    return os;
}

std::istream& operator>>(std::istream& is, Circle& c) {
    is >> c.x >> c.y >> c.r;
    return is;
}


#include <iostream>
#include <cmath>

class FreeVector {
public:
    double x, y, z;

    FreeVector() : x(0), y(0), z(0) {} // Конструктор по умолчанию
    FreeVector(double x, double y, double z) : x(x), y(y), z(z) {} // Параметризованный конструктор

    // Конструктор копирования не требуется, так как все члены данных - простые типы

    void input() {
        std::cin >> x >> y >> z;
    }

    void output() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    FreeVector operator+(const FreeVector& other) const {
        return FreeVector(x + other.x, y + other.y, z + other.z);
    }

    FreeVector& operator+=(const FreeVector& other) {
        x += other.x; y += other.y; z += other.z;
        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, const FreeVector& v);
    friend std::istream& operator>>(std::istream& is, FreeVector& v);
};

std::ostream& operator<<(std::ostream& os, const FreeVector& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

std::istream& operator>>(std::istream& is, FreeVector& v) {
    is >> v.x >> v.y >> v.z;
    return is;
}


#include <iostream>
#include <cmath>

class Complex {
public:
    double x, y;

    Complex() : x(0), y(0) {} // Конструктор по умолчанию
    Complex(double x, double y) : x(x), y(y) {} // Параметризованный конструктор

    // Конструктор копирования не требуется, так как все члены данных - простые типы

    void input() {
        std::cin >> x >> y;
    }

    void output() const {
        std::cout << x << " + " << y << "i" << std::endl;
    }

    double modulus() const {
        return std::sqrt(x * x + y * y);
    }

    Complex conjugate() const {
        return Complex(x, -y);
    }

    // Операторы перегрузки...

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.x << " + " << c.y << "i";
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
    is >> c.x >> c.y;
    return is;
}
#include <iostream>
#include <algorithm>
#include <ctime>

class Array {
public:
    int* arr;
    int mem, n;

    // Конструктор А
    Array(int mem_ = 1, int n_ = 0) : mem(mem_), n(n_) {
        arr = new int[mem];
        std::fill(arr, arr + mem, 0);
    }

    // Конструктор Б
    Array(int n_) : mem(n_), n(n_) {
        arr = new int[n];
        std::fill(arr, arr + n, 0);
    }

    Array(int* arr_, int n_) : mem(n_), n(n_) {
        arr = new int[mem];
        std::copy(arr_, arr_ + n_, arr);
    }

    Array(const Array& other) : mem(other.mem), n(other.n) {
        arr = new int[mem];
        std::copy(other.arr, other.arr + n, arr);
    }

    ~Array() {
        delete[] arr;
    }

    void input() {
        for (int i = 0; i < n; ++i) std::cin >> arr[i];
    }

    void output() {
        for (int i = 0; i < n; ++i) std::cout << arr[i] << ' ';
        std::cout << '\n';
    }

    int find(int key) {
        for (int i = 0; i < n; ++i) if (arr[i] == key) return i;
        return -1;
    }

    // Другие методы...

};

#include <iostream>
#include <cstring>

class String {
public:
    char* line;
    int len;

    String(char* str) {
        len = strlen(str);
        line = new char[len + 1];
        strcpy(line, str);
    }

    String(int L = 80) : len(L) {
        line = new char[len + 1];
        std::fill(line, line + len, ' ');
        line[len] = '\0';
    }

    String(const String& other) : len(other.len) {
        line = new char[len + 1];
        strcpy(line, other.line);
    }

    ~String() {
        delete[] line;
    }

    // Перегрузки операторов...

};

#include <iostream>

template<typename T>
class Stack {
public:
    T* arr;
    int max, n;

    Stack(int k = 50) : max(k), n(0) {
        arr = new T[max];
    }

    Stack(const Stack<T>& other) : max(other.max), n(other.n) {
        arr = new T[max];
        std::copy(other.arr, other.arr + n, arr);
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return n == 0;
    }

    bool isFull() {
        return n == max;
    }

    void push(const T& value) {
        if (isFull()) {
            std::cerr << "Stack is full\n";
            return;
        }
        arr[n++] = value;
    }

    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty\n";
            return T(); // Or throw an exception
        }
        return arr[--n];
    }

    T top() {
        if (isEmpty()) {
            std::cerr << "Stack is empty\n";
            return T(); // Or throw an exception
        }
        return arr[n - 1];
    }

    // Перегрузки операторов...

};




