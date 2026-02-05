#include <iostream>
#include<vector>
#include <span>
#include<chrono>
#include<ctime>
using namespace std;

//void BubbleSort(std::span<int>& v)
//{
//    for (int i = 0; i < v.size() - 1; i++)
//    {
//        for (int j = 0; j < v.size() - 1 - i; j++)
//        {
//            if (v[j] < v[j + 1])
//            {
//                int temp = v[j];
//                v[j] = v[j + 1];
//                v[j + 1] = temp;
//            }
//        }
//    }
//}

void BubbleSort(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
}

void BubbleSort(int* mass, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (mass[j] < mass[j + 1])
            {
                int temp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = temp;
            }
        }
    }
}

void GenerateMass(vector<int>& arr, int n)
{
    arr = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1 + rand() % (n - 1);
    }
}

int main()
{   
    srand(time(0));
    vector<int> arr;
    vector<int> nums = { 100, 300, 500, 1000, 1500, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 15000, 20000, 25000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000 };
    for(int i : nums)
    {
        GenerateMass(arr, i);
        auto start = chrono::steady_clock::now();
        BubbleSort(arr);
        auto end = chrono::steady_clock::now();
        auto diffmsc = chrono::duration_cast<chrono::microseconds>(end - start).count();
        auto diffms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        auto diffs = chrono::duration_cast<chrono::seconds>(end - start).count();
        cout << "n - " << i << "    ";
        cout << "time: " << diffmsc << "\n";
        arr.clear();
    }

    for (int i : arr)
        cout << i << " ";
}


