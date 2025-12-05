#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    double x, y, z;
};

struct Segment {
    Point a, b;
    double len;
};

// обчислення довжини у 3D
double distance3D(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) +
                (p1.y - p2.y)*(p1.y - p2.y) +
                (p1.z - p2.z)*(p1.z - p2.z));
}

// компаратор для сортування
bool cmp(const Segment& s1, const Segment& s2) {
    return s1.len < s2.len;
}

int main() {
    ifstream fin("points_219.txt");
    if (!fin) {
        cerr << "Cannot open points.txt\n";
        return 1;
    }

    vector<Point> points;
    double x, y, z;
    char c; // для ком та пробілів

    // читаємо формат: x , y , z
    while (fin >> x >> c >> y >> c >> z) {
        Point p; p.x = x; p.y = y; p.z = z;
        points.push_back(p);
    }
    fin.close();

    if (points.size() < 2) {
        cout << "Not enough points.\n";
        return 0;
    }

    vector<Segment> segments;

    // формуємо всі відрізки
    for (int i = 0; i < (int)points.size(); i++) {
        for (int j = i + 1; j < (int)points.size(); j++) {
            Segment s;
            s.a = points[i];
            s.b = points[j];
            s.len = distance3D(points[i], points[j]);
            segments.push_back(s);
        }
    }

    // сортування за довжиною
    sort(segments.begin(), segments.end(), cmp);

    // запис у файл
    ofstream fout("segments_219.txt");
    for (int i = 0; i < (int)segments.size(); i++) {
        fout << "(" 
             << segments[i].a.x << "," 
             << segments[i].a.y << "," 
             << segments[i].a.z << ")  -  ("
             << segments[i].b.x << "," 
             << segments[i].b.y << "," 
             << segments[i].b.z << ")"
             << " : " << segments[i].len << "\n";
    }
    fout.close();

    cout << "Segments written to segments.txt\n";
    return 0;
}
