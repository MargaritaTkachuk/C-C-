#include <iostream>
#include <string>
using namespace std;

class Rational {
private:
    int num, den;

public:
    Rational(int n = 0, int d = 1) : num(n), den(d) {
        if (den == 0) throw runtime_error("Zero denominator!");
    }

    bool operator>(const Rational& other) const {
        return (long long)num * other.den > (long long)other.num * den;
    }

    friend ostream& operator<<(ostream& os, const Rational& r) {
        return os << r.num << "/" << r.den;
    }
};

template <typename T>
T myMax(const T& a, const T& b) {
    return (a > b) ? a : b;
}

int main() {
    cout << myMax(555, -23) << endl;
    cout << myMax(3.14, 2.7) << endl;
    cout << myMax(string("hello"), string("world")) << endl;
    cout << myMax(Rational(7,8), Rational(-2,32)) << endl;

    return 0;
}
