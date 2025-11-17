#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include "Polynomial.h"
#include "rational.h"
#include "point.h"
#include "Time.h"
#include "Date.h"
#include "Point_18.h"
using namespace std;

int main() {

    std::vector<Rational> arr = {
        Rational(1, 2),
        Rational(-3, 4),
        Rational(5, 6),
        Rational(-1, 3),
        Rational(2, 7)
    };

    Rational minVal = arr[0];
    for (const auto& r : arr) {
        if (r < minVal)
            minVal = r;
    }

    std::cout << "Najmenshe racionalne chislo: ";
    minVal.output();
    std::cout << std::endl;


    double sum = 0.0;
    double term;
    int k = 1;

    do {
        term = (1.0 / (k * k)) * ( (k % 2 == 1) ? 1 : -1 );
        sum += term;
        k++;
    } while (std::abs(term) > 0.01);

    std::cout << "Suma ryadu z tochnistju 0.01: " << sum << std::endl;

    double trueValue = (M_PI * M_PI) / 12.0;
    std::cout << "Pi^2/12 = " << trueValue << std::endl;

    if (std::abs(sum - trueValue) < 0.05)
        std::cout << "Rjad zbizhnyj do pi^2/12" << std::endl;
    else
        std::cout << "Rjad NE zbizhnyj do pi^2/12" << std::endl;


    vector<Point> poly;
    string ans;

    while (true) {
        cout << "Ввести вершину? (Так/Ні): ";
        cin >> ans;
        if (ans == "Ні" || ans == "ні" || ans == "No" || ans == "no") break;

        double x, y;
        cout << "x = ";
        cin >> x;
        cout << "y = ";
        cin >> y;
        poly.emplace_back(x, y);
    }

    cout << "Kilkist vershin: " << Point::counter() << endl;

    if (poly.size() < 2) {
        cout << "Perimetr: 0\n";

    }

    double P = 0;
    for (size_t i = 0; i < poly.size(); i++)
        P += poly[i].distance(poly[(i + 1) % poly.size()]);

    cout << "Perimetr: " << P << endl;


    int deg;
    cout << "Vvedit kilkist koeficientiv polinoma: ";
    cin >> deg;

    Polynomial p(deg);

    cout << "Vvedit koeficienty: ";
    cin >> p;

    cout << "Vash polinom: ";
    p.print();

    ofstream out("poly.bin", ios::binary);
    writeBinary(out, p);
    out.close();

    Polynomial q(1);
    ifstream in("poly.bin", ios::binary);
    readBinary(in, q);
    in.close();

    cout << "Zchytano z binary-failu: ";
    q.print();


    Time time1(12, 30, 10);
    Time time2(14, 15, 5);
    cout << "Riznitsa v sekundah: " << time1.difference(time2) << endl;

    Date* d1 = Date::getInstance(2024, 11, 16);
    Date d2(2020, 5, 20);

    cout << "Riznitsa v dnyah: " << d1->difference(d2) << endl;



    int n;
    cout << "Введіть кількість точок: ";
    cin >> n;

    vector<Point_18> points(n);

    for(int i=0;i<n;i++){
        double x, y, vx, vy, ax, ay;
        cout << "Точка " << i+1 << ":\n";
        cout << "x0 y0: "; cin >> x >> y;
        points[i] = Point_18(x, y);
        cout << "vx vy: "; cin >> vx >> vy; points[i].setVelocity(vx, vy);
        cout << "ax ay: "; cin >> ax >> ay; points[i].setAcceleration(ax, ay);
    }

    double t;
    cout << "Введіть момент часу для відстані між двома точками: ";
    cin >> t;
    if(n>=2) {
        double d = points[0].distanceAt(points[1], t);
        cout << "Відстань між точками 1 і 2 у момент t=" << t << " : " << d << endl;
    }

    double t1, t2;
    cout << "Введіть проміжок часу [t1 t2] для перетинів: ";
    cin >> t1 >> t2;

    int total = countIntersections(points, t1, t2);
    cout << "Кількість перетинів траєкторій: " << total << endl;

    return 0;


}
