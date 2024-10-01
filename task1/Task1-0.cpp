#include <iostream>
using namespace std;

const double xa = 0, xb = 3, xc = 0;
const double ya = 0, yb = 0, yc = 4;

double getSquareOfTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)) / 2.0;
}

const double squareABC = getSquareOfTriangle(xa, ya, xb, yb, xc, yc);

bool isInTriangle(double x, double y) {
    double S1 = getSquareOfTriangle(xa, ya, xb, yb, x, y) ;
    double S2 = getSquareOfTriangle(xb, yb, xc, yc, x, y);
    double S3 = getSquareOfTriangle(xa, ya, xc, yc, x, y);

    return (S1 + S2 + S3) == squareABC;
}

int main() {
    double x = 1, y = 1;

    cin >> x >> y;
    while (x != 0 || y != 0) {
        if (isInTriangle(x, y)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        cin >> x >> y;
    }

    return 0;
}