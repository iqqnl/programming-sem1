#include <iostream> 
#include <cstring> 
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
 
int main(int argc, char* argv[]) 
{ 
    setlocale(LC_ALL, "ru_RU"); 
 bool isHuman = false; 
 if (argc <= 1 || strcmp(argv[1], "false") != 0) isHuman = true; 
    if(isHuman) cout << "Введите 0 0 , чтобы завершить ввод" << endl; 
     
    double x = 1, y = 1; 
    while (x != 0 || y != 0) { 
        if(isHuman) cout << "Введите координаты" << endl; 
        cin >> x >> y; 
        if (x == 0 && y == 0) 
        {
            break;
        }
        if (isInTriangle(x, y)) {
            if(isHuman) 
            { 
                cout << "Точка входит" << endl; 
            }  
            else 
            { 
               cout << "YES" << endl; 
            }
        } 
        else{
            if(isHuman) 
            { 
                cout << "Точка не входит" << endl; 
            }  
            else 
            { 
                cout << "No" << endl; 
            } 
        }
    } 
 
    return 0; 
}