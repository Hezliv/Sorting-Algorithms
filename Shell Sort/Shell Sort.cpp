#include <iostream>
#include <vector>
using namespace std;

void ShellSort(vector<int>& ar)
{
    for (int interval = ar.size() / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < ar.size(); i++)
        {
            int temp = ar[i];
            int j = 0;          
            for (j = i; j >= interval && ar[j - interval] > temp; j -= interval)
            {
                ar[j] = ar[j - interval];
            }
            ar[j] = temp;
        }
    }
}

int main()
{
    vector<int> ar = { 2, 1, 7, 3, 5, 6, 8 };
    ShellSort(ar);
    for (auto a : ar)
        cout << a << " ";
}
 
