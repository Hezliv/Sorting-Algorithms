#include <iostream>
#include <vector>
using namespace std;
// O(1) space
// O(n) time
int Partition(vector<int>& ar, int low, int high) // Hoare's Partition algorithm
{
    int i = low - 1;
    int j = high + 1;
    int pivot = ar[(low + high) / 2];
    while (true)
    {
        do { i++; } while (ar[i] < pivot);
        do { j--; } while (ar[j] > pivot);
        if (i >= j) return j;
        swap(ar[i], ar[j]);
    }
}

//Ω(n log n)
//O(n ^ 2)

void QuickSort(vector<int>& array, int low, int high)
{
    if (low < high)
    {
        int p = Partition(array, low, high);

        QuickSort(array, low, p);
        QuickSort(array, p + 1, high);
    }
}

int main()
{
    vector<int> array = { 2, 1, 5, 7, 3, 10 };
    QuickSort(array, 0, array.size() - 1);
    for (int i : array)
    {
        cout << i << " ";
    }
}

