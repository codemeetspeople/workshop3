#include <iostream>

class NotReadyException {};
class OutOfAmmoException {};

class Gun {
    private:
        std::string model;
        int capacity;
        int amount;
        bool isReady;

    public:
        Gun(const std::string& model, int capacity) {
            this->model = model;
            this->capacity = capacity;
            this->amount = 0;
            this->isReady = false;
        }

        const std::string& getModel() const {
            return this->model;
        }

        int getCapacity() const {
            return this->capacity;
        }

        int getAmount() const {
            return this->amount;
        }

        bool ready() const {
            return this->isReady;
        }

        void refill() {
            this->amount = this->capacity;
        }

        void prepare() {
            this->isReady = !(this->isReady);
        }

        void shoot() {
            if ( !(this->ready()) ) {
                throw NotReadyException();
            }
            if ( this->getAmount() == 0 ) {
                throw OutOfAmmoException();
            }

            this->amount -= 1;
            std::cout << "Bang!!!!" << std::endl;
        }
};

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << gun.getModel() << " ";
    out << gun.getAmount() << "/" << gun.getCapacity() << " ";
    out << std::boolalpha << "ready(" << gun.ready() << ")";
    return out;
}


int main() {
    Gun beretta("Beretta", 9);
    std::cout << beretta << std::endl;

    beretta.refill();
    beretta.prepare();

    for ( ; ; ) {
        try {
            beretta.shoot();
        } catch ( OutOfAmmoException obj ) {
            break;
        }
    }

    return 0;
}
