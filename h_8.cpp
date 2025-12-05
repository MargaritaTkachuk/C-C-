#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <type_traits>

using namespace std;

template <typename T>
class Interval {
private:
    pair<T, T> bounds;
    bool leftClosed;
    bool rightClosed;

public:
    Interval(T l, T r, bool lC = true, bool rC = true)
        : bounds(l, r), leftClosed(lC), rightClosed(rC)
    {
        if (bounds.first > bounds.second)
            throw runtime_error("Invalid interval bounds");
    }

    friend ostream& operator<<(ostream& os, const Interval& I) {
        os << (I.leftClosed ? "[" : "(")
           << I.bounds.first << ", " << I.bounds.second
           << (I.rightClosed ? "]" : ")");
        return os;
    }

    // ---- Перевірка перетину ----
    bool intersects(const Interval& other) const {
        T L = max(bounds.first, other.bounds.first);
        T R = min(bounds.second, other.bounds.second);

        if (L > R) return false;
        if (L == R) {
            bool include =
                (L == bounds.first ? leftClosed : false) &&
                (L == other.bounds.first ? other.leftClosed : false);
            return include;
        }
        return true;
    }

    // ---- Перетин ----
    Interval intersection(const Interval& other) const {
        if (!intersects(other))
            throw runtime_error("Intervals do not intersect!");

        T L = max(bounds.first, other.bounds.first);
        T R = min(bounds.second, other.bounds.second);

        bool newLeftClosed =
            (L == bounds.first ? leftClosed : false) &&
            (L == other.bounds.first ? other.leftClosed : false);

        bool newRightClosed =
            (R == bounds.second ? rightClosed : false) &&
            (R == other.bounds.second ? other.rightClosed : false);

        return Interval(L, R, newLeftClosed, newRightClosed);
    }

    // ---- Об'єднання ----
    Interval unionWith(const Interval& other) const {
        if (!intersects(other))
            throw runtime_error("Intervals do not intersect, union impossible");

        T L = min(bounds.first, other.bounds.first);
        T R = max(bounds.second, other.bounds.second);

        bool newLeftClosed =
            (L == bounds.first ? leftClosed : false) ||
            (L == other.bounds.first ? other.leftClosed : false);

        bool newRightClosed =
            (R == bounds.second ? rightClosed : false) ||
            (R == other.bounds.second ? other.rightClosed : false);

        return Interval(L, R, newLeftClosed, newRightClosed);
    }
};

int main() {
    int n;
    cout << "Enter number of intervals: ";
    cin >> n;

    vector<Interval<int> > arr;
    arr.reserve(n);

    cout << "Enter intervals as: left right leftClosed rightClosed\n";
    cout << "(Example: 1 5 1 0 means [1,5) )\n\n";

    for (int i = 0; i < n; i++) {
        int a, b;
        bool lC, rC;
        cin >> a >> b >> lC >> rC;
        arr.emplace_back(a, b, lC, rC);
    }

    cout << "\nIntervals:\n";
    for (auto& x : arr) cout << x << endl;

    try {
        Interval<int> current = arr[0];

        for (int i = 1; i < n; i++)
            current = current.intersection(arr[i]);

        cout << "\nCommon intersection: " << current << endl;
    }
    catch (exception& e) {
        cout << "\nNo common intersection: " << e.what() << endl;
    }

    return 0;
}
