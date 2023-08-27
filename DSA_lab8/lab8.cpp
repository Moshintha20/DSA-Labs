#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root) 
{
  // Find largest among root, left child and right child
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != root) 
    {
        swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}
  
// implementing heap sort
void heapSort(int arr[], int n) 
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
  
      // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
 }
   
/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
    cout << arr[i] << " ";
    cout << "\n";
}
  
// main program
int main()
{
    cout << "Number of elements in the array" << endl;
    int num;
    cin >> num;
    int heap_arr[num] = {};
    cout << "Enter elements of the array" << endl;
    for (int i=0; i<num; i++)
    {
        cin >> heap_arr[i];
    }
    int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
    cout<<"Input array"<<endl;
    displayArray(heap_arr,n);
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array"<<endl;
    displayArray(heap_arr, n);
}
