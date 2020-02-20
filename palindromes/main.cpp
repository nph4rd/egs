#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std; 


void findPalindrome(vector<int> &C, string inputString, int m, int n, int k, bool isEven)
{
    vector<int> B = C;
    if (isEven)
    {
        if (m < n - 1 && m > -1)
        {
            bool isPal = 1;
            int j = 0;
            int palLength = 0;
            while (isPal && m + j + 1 < n && m - j > -1)
            {
                if (inputString[m + j + 1] == inputString[m - j])
                {
                    palLength += 2;
                    B[m + j + 1] = 1;
                    B[m - j] = 1;    
                }
                else
                {
                    isPal = 0;
                }
                j++;
            } 
            if (palLength >= k)
            {
                C = B;
            }
        }
    }
    else
    {
        if (m < n - 1 && m > 0)
        {
            bool isPal = 1;
            int j = 1;
            int palLength = 1;
            while (isPal && m + j < n && m - j > -1)
            {
                if (inputString[m + j] == inputString[m - j])
                {
                    palLength += 2;
                    B[m] = 1;
                    B[m + j] = 1;
                    B[m - j] = 1;    
                }
                else
                {
                    isPal = 0;
                }
                j++;
            } 
            if (palLength >= k)
            {
                C = B;
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


