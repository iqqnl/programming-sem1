#include <iostream> 
#include <cmath> 
#include <iomanip> 
#include <cstring> 
using namespace std;  
 
bool isPrime(int num) { 
    if (num <= 1) return false; 
    if (num <= 3) return true; 
    if (num % 2 == 0 || num % 3 == 0) return false; 
    for (int i = 5; i * i <= num; i += 6) { 
        if (num % i == 0 || num % (i + 2) == 0) return false; 
    } 
    return true; 
} 
 
bool isPowerOfTwo(int num) { 
    return num && !(num & (num - 1)); 
} 
 
int main(int argc, char* argv[]) { 
    bool isHuman = false; 
    if (argc <= 1 || strcmp(argv[1], "false") != 0) { 
        isHuman = true; 
    } 
 
    int N; 
    if (isHuman) { 
        cout << "Введите количество элементов в последовательности: "; 
    } 
    cin >> N; 
 
    int num, sum = 0, maxNum = INT_MIN, minNum = INT_MAX; 
    int divisibleByFive = 0, powerOfTwoCount = 0, exceedsPrevSum = 0; 
    int prev1 = 0, prev2 = 0; 
 
    if (isHuman) { 
        cout << N << " Положительные целые числа:" << endl; 
    } 
 
    for (int i = 0; i < N; ++i) { 
        cin >> num; 
        sum += num; 
        if (num > maxNum) maxNum = num; 
        if (num < minNum) minNum = num; 
 
        if (isHuman && isPrime(num)) { 
            cout << num << " Является простым числом." << endl; 
        } 
 
        if (num % 5 == 0) ++divisibleByFive; 
        if (isPowerOfTwo(num)) ++powerOfTwoCount; 
        if (i >= 2 && num > prev1 + prev2) ++exceedsPrevSum; 
 
        prev2 = prev1; 
        prev1 = num; 
    } 
 
    double average = static_cast<double>(sum) / N; 
 
    cout << fixed << setprecision(2) << average << endl; 
    cout << maxNum - minNum << endl; 
    cout << divisibleByFive << endl; 
    cout << powerOfTwoCount << endl; 
    cout << exceedsPrevSum << endl; 
 
    return 0; 
}