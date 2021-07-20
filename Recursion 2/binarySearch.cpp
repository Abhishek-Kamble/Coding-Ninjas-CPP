#include<iostream>
using namespace std;

int binary_Search(int arr[], int l, int r, int x) 
{ 
    if(r>=l)
    {
        int mid = l+(r-l)/2;

        if(arr[mid] == x)
            return mid;

        if(x < arr[mid])
            return binary_Search(arr, l, mid-1, x);

        return binary_Search(arr, mid+1, r, x);
   }

   return -1;
} 

int binarySearch(int *arr, int len, int x)
{
    return binary_Search(arr, 0, len-1, x);
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
