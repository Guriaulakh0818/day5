#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool compareY(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

double distance(const Point &p1, const Point &p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double closestPairUtil(vector<Point> &px, vector<Point> &py) {
    int n = px.size();
    if (n <= 3) {
        double minDist = numeric_limits<double>::max();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                minDist = min(minDist, distance(px[i], px[j]));
            }
        }
        return minDist;
    }

    int mid = n / 2;
    Point midPoint = px[mid];

    vector<Point> pxLeft(px.begin(), px.begin() + mid);
    vector<Point> pxRight(px.begin() + mid, px.end());

    vector<Point> pyLeft, pyRight;
    for (int i = 0; i < n; i++) {
        if (py[i].x <= midPoint.x) {
            pyLeft.push_back(py[i]);
        } else {
            pyRight.push_back(py[i]);
        }
    }

    double dl = closestPairUtil(pxLeft, pyLeft);
    double dr = closestPairUtil(pxRight, pyRight);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = 0; i < n; i++) {
        if (fabs(py[i].x - midPoint.x) < d) {
            strip.push_back(py[i]);
        }
    }

    double stripMin = numeric_limits<double>::max();
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && fabs(strip[j].y - strip[i].y) < d; j++) {
            stripMin = min(stripMin, distance(strip[i], strip[j]));
        }
    }

    return min(d, stripMin);
}

double closestPair(vector<Point> &points) {
    vector<Point> px = points;
    vector<Point> py = points;
    sort(px.begin(), px.end(), compareX);
    sort(py.begin(), py.end(), compareY);
    return closestPairUtil(px, py);
}

int main() {
    vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {0, 1}, {1, 0}};
    cout << "The smallest distance is " << closestPair(points) << endl;
    return 0;
}
