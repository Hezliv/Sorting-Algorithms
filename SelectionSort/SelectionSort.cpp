#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

template <typename T>
void SelectionSort(vector<T>& v)
{
    size_t index = v.size() - 1;
    size_t max = 0;
    while (index > 0)
    {
        for (size_t i = 0; i < index + 1; i++)
        {
            if (v[max] < v[i])
                max = i;
        }
        if(index != max)
            swap(v[max], v[index]);
        index--;
        max = 0;
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
    for (int i : nums)
    {
        GenerateMass(arr, i);
        auto start = chrono::steady_clock::now();
        SelectionSort(arr);
        for (int i : arr)
            cout << i << " ";
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
    cout << "\n";
}

