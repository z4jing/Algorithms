// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

int partition(int* arr, int left, int right) {
    int j = left-1;
    for (int i = left; i < right; ++i) {
        if (arr[i] <= arr[right]) {
            ++j;
            int tem = arr[j];
            arr[j] = arr[i];
            arr[i] = tem;
        }
    }
    int tem = arr[j+1];
    arr[j+1] = arr[right];
    arr[right] = tem;
    return j+1;
}

void quicksort(int* arr,int left, int right) {
    if (left < right) {
        int index = partition(arr, left, right);
        quicksort(arr, left, index-1);
        quicksort(arr, index+1, right);
    }
}

int main() {
    // Write C++ code here
    int arr [] =  {1,9,6,7,8,4,5,9,3,24};
    quicksort(arr,0,9);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
