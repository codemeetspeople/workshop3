#include <iostream>
#include <cmath>

class Point {
    private:
        // Attributes
        int x;
        int y;

    public:
        // Constructors
        Point() {
            this->x = 0;
            this->y = 0;
        }

        Point(int x, int y) {
            this->x = x;
            this->y = y;
        }

        // Getters / Accessors
        int getX() const {
            return this->x;
        }

        int getY() const {
            return this->y;
        }

        // Setters / Mutators
        void setX(int value) {
            this->x = value;
        }

        void setY(int value) {
            this->y = value;
        }

        // Methods
        double distance(const Point& other) const {
            return hypot(this->x-other.x, this->y-other.y);
        }

        bool operator==(const Point& other) const {
            return this->x == other.x && this->y == other.y;
        }

        bool operator!=(const Point& other) const {
            return !((*this) == other);
        }

        Point operator+(const Point& other) const {
            return Point(this->x+other.x, this->y+other.y);
        }

        Point operator-(const Point& other) const {
            return Point(this->x-other.x, this->y-other.y);
        }

        friend std::ostream& operator<<(std::ostream& out, const Point& point);
};

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.x << ", " << point.y << ")";
    return out;
}

int main() {
    Point p;

    std::cout << p << std::endl;

    return 0;
}
