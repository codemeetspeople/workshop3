#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;

    double distance(const struct Point& other) const {
        return hypot(this->x-other.x, this->y-other.y);
    }

    bool operator==(const struct Point& other) const {
        return this->x == other.x && this->y == other.y;
    }

    bool operator!=(const struct Point& other) const {
        return !((*this) == other);
    }

    struct Point operator+(const struct Point& other) const {
        struct Point sum = {this->x+other.x, this->y+other.y};
        return sum;
    }

    struct Point operator-(const struct Point& other) const {
        struct Point diff = {this->x-other.x, this->y-other.y};
        return diff;
    }
};


std::ostream& operator<<(std::ostream& out, const struct Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}


int main() {
    struct Point a = {1, 10};
    struct Point b = {2, 5};

    std::cout << std::boolalpha << (a==b) << std::endl;
    std::cout << std::boolalpha << (a!=b) << std::endl;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a+b << std::endl;
    std::cout << a-b << std::endl;

    std::cout << a.distance(b) << std::endl;

    return 0;
}
