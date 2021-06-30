/*
Merge Sort Code
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5
*********************************************************************************/

#include <iostream>
using namespace std;

void merge(int a[], int b[], int low, int mid, int high)
{
    for (int i = low; i <= high; i++)
    {
        b[i] = a[i];
    }
    int left = low;
    int right = mid + 1;
    int index = low;
    while (left <= mid && right <= high)
    {
        if (b[left] <= b[right])
            a[index++] = b[left++];
        else
            a[index++] = b[right++];
    }

    // copy remainder of the left side
    int remainder = mid - left + 1;
    for (int i = 0; i < remainder; i++)
    {
        a[index + i] = b[left + i];
    }
}

// merge sort starts here
void mergeSort(int a[], int b[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(a, b, low, mid);
    mergeSort(a, b, mid + 1, high);
    merge(a, b, low, mid, high);
}

// prepare for real mergesort()
void mergeSort(int a[], int len)
{
    int *b = new int[len];
    mergeSort(a, b, 0, len - 1);
    delete[] b;
}

//main function
int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}
