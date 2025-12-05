#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Segment {
    double x1, y1, x2, y2;
    double length;
};

// Функція-компаратор для sort (C++98)
bool compareSegments(const Segment& a, const Segment& b) {
    return a.length < b.length;
}

double distance(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx*dx + dy*dy);
}

int main() {
    string filename = "points.txt";
    ifstream infile(filename);

    if (!infile) {
        cerr << "Failed to open file " << filename << endl;
        return 1;
    }

    vector<double> xs, ys;
    double x, y;
    char c;

    // Читання точок формату (x, y)
    while (infile >> c) {
        if (c != '(') continue;

        infile >> x;
        infile >> c;  // ,
        infile >> y;
        infile >> c;  // )

        xs.push_back(x);
        ys.push_back(y);
    }

    if (xs.size() < 2) {
        cout << "Not enough points to calculate distance." << endl;
        return 0;
    }

    vector<Segment> segments;

    // Створюємо всі відрізки
    for (size_t i = 0; i < xs.size(); i++) {
        for (size_t j = i + 1; j < xs.size(); j++) {
            Segment s;
            s.x1 = xs[i];
            s.y1 = ys[i];
            s.x2 = xs[j];
            s.y2 = ys[j];
            s.length = distance(xs[i], ys[i], xs[j], ys[j]);
            segments.push_back(s);
        }
    }

    // Сортування без лямбди
    sort(segments.begin(), segments.end(), compareSegments);

    // Запис у файл
    ofstream outfile("segments.txt");
    if (!outfile) {
        cerr << "Failed to create segments.txt" << endl;
        return 1;
    }

    for (size_t i = 0; i < segments.size(); i++) {
        const Segment& s = segments[i];
        outfile << "(" << s.x1 << ", " << s.y1 << ") - "
                << "(" << s.x2 << ", " << s.y2 << ") : "
                << s.length << "\n";
    }

    outfile.close();

    cout << "Segments successfully written to segments.txt" << endl;

    return 0;
}
