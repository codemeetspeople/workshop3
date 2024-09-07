#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

double pointDistance(const struct Point& a, const struct Point& b) {
    return hypot(a.x-b.x, a.y-b.y);
}

bool operator==(const struct Point& a, const struct Point& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const struct Point& a, const struct Point& b) {
    return !(a == b);
}

struct Point operator+(const struct Point& a, const struct Point& b) {
    struct Point sum = {a.x+b.x, a.y+b.y};
    return sum;
}

struct Point operator-(const struct Point& a, const struct Point& b) {
    struct Point diff = {a.x-b.x, a.y-b.y};
    return diff;
}

std::ostream& operator<<(std::ostream& out, const struct Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}


int main() {
    struct Point a = {1, 10};
    struct Point b = {2, 5};

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a+b << std::endl;
    std::cout << a-b << std::endl;

    std::cout << std::boolalpha << (a==b) << std::endl;
    std::cout << std::boolalpha << (a!=b) << std::endl;
    std::cout << pointDistance(a, b) << std::endl;

    return 0;
}
