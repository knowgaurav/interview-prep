#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    double myPow(double x, long long n)
    {
        if (n == 0)
            return 1;

        if (n < 0)
            return myPow(1 / x, n * (-1));

        double temp = myPow(x, n / 2);

        if (n % 2 == 0)
            return temp * temp;

        return temp * temp * x;
    }
};

// GFG
class Solution
{
private:
    int mod = 10000007;
    long long pow(long long n, long long k)
    {
        if (k == 0)
            return 1;
        return (n * pow(n, k - 1)) % mod;
    }

    long long optimisedPow(long long n, long long k)
    {
        if (k == 0)
            return 1;

        long long temp = optimisedPow(n, k / 2);
        temp = (temp * temp) % mod;

        // Power is even
        if (k % 2 == 0)
            return temp;

        // Power is odd
        return (temp * n) % mod;
    }

public:
    // You need to complete this fucntion

    long long power(int N, int R)
    {
        // Your code here
        int temp = N, rev = 0;

        while (temp)
        {
            rev = (rev * 10) + temp % 10;
            temp /= 10;
        }

        return optimisedPow(N, rev);
    }
};