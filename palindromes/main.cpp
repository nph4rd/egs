#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 

void expandPalindrome(vector<int> &C, string inputString, int leftIndex, int rightIndex, int n)
{
    bool isPal = 1;
    int e = 0;
    while (isPal && rightIndex + e < n && leftIndex - e > -1)
    {
        if (inputString[rightIndex + e] == inputString[leftIndex - e])
        {
            C[rightIndex + e] = 1;
            C[leftIndex - e] = 1;

        }
        else
        {
            isPal = 0; 
        }
        e++;
    }
}


void findPalindrome(vector<int> &C, string inputString, int m, int n, int k, bool isEven)
{
    int steps = k / 2;
    vector<int> B = C;
    if (isEven)
    {
        if (k % 2)
        {
             k++;
        }
        if (m + steps < n && m - steps + 1 > -1)
        {
            bool isPal = 1;
            int j = 0;
            /* int palLength = 0; */
            /* int steps = k / 2; */ 
            while (isPal &&  j < steps)
            {
                if (inputString[m + steps - j] == inputString[m - steps + 1 + j])
                {
                    B[m - steps + j + 1] = 1;
                    B[m + steps - j] = 1;    
                }
                else
                {
                    isPal = 0;
                }
                j++;
            } 
            if (isPal)
            {
                C = B;
                int rightIndex = m + steps;
                int leftIndex = m - steps + 1;
                expandPalindrome(C, inputString, leftIndex, rightIndex, n);
            }
        }
    }
    else
    {
        if (m + steps < n  && m - steps > 0)
        {
            bool isPal = 1;
            int j = 1;
            /* int palLength = 1; */
            while (isPal && j < steps)
            {
                if (inputString[m - steps + j] == inputString[m + steps  - j])
                {
                    B[m] = 1;
                    B[m - steps + j] = 1;
                    B[m + steps - j] = 1;  
                }
                else
                {
                    isPal = 0;
                }
                j++;
            } 
            if (isPal)
            {
                C = B;
                int rightIndex = m + steps;
                int leftIndex = m - steps;
                expandPalindrome(C, inputString, leftIndex, rightIndex, n);
            }
        }
    }
}

void getAnswer(vector<int> &C, string inputString, int n, int k)
{  
    int i;
    int m = n / 2;

    if (n % 2) // Odd
    {    
        findPalindrome(C, inputString, m, n, k, 1);
        findPalindrome(C, inputString, m, n, k, 0);
        for (i = 1; i < m + 1; i++)
        {
            findPalindrome(C, inputString, m - i, n, k, 1);
            findPalindrome(C, inputString, m - i, n, k, 0);
            findPalindrome(C, inputString, m + i, n, k, 1);
            findPalindrome(C, inputString, m + i, n, k, 0);
        }
    }
    else
    {
        m--;
        for (i = 0; i < m + 1; i++)
        {
            findPalindrome(C, inputString, m - i, n, k, 1);
            findPalindrome(C, inputString, m - i, n, k, 0);
            findPalindrome(C, inputString, m + i + 1, n, k, 1);
            findPalindrome(C, inputString, m + i + 1, n, k, 0);
        }
    }
}

int main()
{
    string inputString;
    int N;
    int k;
    int answer = 0;
    cin >> N >> k;
    cin >> inputString;
    vector<int> C(N, 0);
    getAnswer(C, inputString, N, k);
    answer = count(C.begin(), C.end(), 0);
    cout << answer  << endl;
}


