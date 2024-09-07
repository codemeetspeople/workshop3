#include <iostream>
#include <cstring>

class Data {
    public:
        union {
            char charValue[25];
            int intValue;
        };
        bool isInt;
};


std::ostream& operator<<(std::ostream& out, const Data& data) {
    if ( data.isInt ) {
        out << data.intValue;
    } else {
        out << data.charValue;
    }
    return out;
}


int main() {
    Data data;

    data.intValue = 1488;
    data.isInt = true;

    std::cout << data << std::endl;

    std::strcpy(data.charValue, "Hello, world!");
    data.isInt = false;

    std::cout << data << std::endl;

    data.intValue = 787878;
    data.isInt = true;

    std::cout << data << std::endl;

    return 0;
}

