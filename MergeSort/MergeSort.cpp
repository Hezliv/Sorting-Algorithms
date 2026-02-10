#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void Merge(vector<T>& left_array, vector<T>& right_array, vector<T>& array)
{
    int left_length = left_array.size();
    int right_length = right_array.size();
    
    int i = 0, l = 0, r = 0;
    while (l < left_length && r < right_length)
    {
        if (left_array[l] < right_array[r])
        {
            array[i++] = left_array[l++];
        }
        else
        {
            array[i++] = right_array[r++];
        }
    }
    while (l < left_length)
    {
        array[i++] = left_array[l++];
    }
    while (r < right_length)
    {
        array[i++] = right_array[r++];
    }
}

template <typename T>
void MergeSort(vector<T>& array)
{
    int length = array.size();
    if (length <= 1) return;

    int middle = length / 2;
    vector<T> left_array(middle, 0);
    vector<T> right_array(length - middle, 0);
    int i = 0;
    int j = 0;
    for (; i < length; i++)
    {
        if (i < middle)
        {
            left_array[i] = array[i];
        }
        else
        {
            right_array[j++] = array[i];
        }
    }
    MergeSort(left_array);
    MergeSort(right_array);
    Merge(left_array, right_array, array);
}

int main()
{
    vector<int> test = { 3, 7, 2, 1, 5, 6 };
    MergeSort(test);
    for (auto i : test)
        cout << i << " ";
}
