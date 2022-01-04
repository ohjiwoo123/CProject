#include <iostream>
#define MAX 9
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= MAX; i++) {
        cout << n << " * " << i << " = " << n * i << endl;
    }

}