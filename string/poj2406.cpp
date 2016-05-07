#include <iostream>
using namespace std;

int P(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        sum = sum + i;
    }
    return sum;
}

int M(int n)
{
    return n * (n + 1) / 2;
}


int main(void)
{

    while (true) 
    {
        int x;
        cin >> x;
        cout << "P: " <<  P(x) << " M: " << M(x) << endl;
    }
    return 0;
}
    
