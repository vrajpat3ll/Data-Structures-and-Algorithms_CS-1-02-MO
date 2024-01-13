// Head Section
#include <iostream>
using namespace std;

// The functions should be written in a way that array becomes sorted
// in increasing order when heapSort() is called.

// Body Section
class Solution
{
public:
    // Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)
    {
        // Your Code Here
        int Lchild = 2 * i + 1;
        int Rchild = 2 * i + 2;
        int largest = i;
        
        if (arr[largest] < arr[Rchild] && Rchild < n)
        {
            largest = Rchild;
        }
        if (arr[i] < arr[Lchild] && Lchild < n)
        {
            largest = Lchild;
        }
        
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to build a Heap from array.
    void buildHeap(int arr[], int n)
    {
        // Your Code Here
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

    // Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // Your Code Here
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            n--;
            heapify(arr, n, 0);
        }
    }
};

// Tail Section
/* Function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Driver program to test above functions
int main()
{
    //     int T;
    //     cin >> T;

    //     while (T--) {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution ob;
    ob.heapSort(arr, n);

    printArray(arr, n);
    // }
    return 0;
}