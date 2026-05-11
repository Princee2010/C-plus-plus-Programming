#include<iostream>
using namespace std;

void mergeSortedArray(int *arr1, int n, int *arr2, int m, int *mergedArr)
{
    int i = 0 , j = 0 , k = 0;
    while (i < n && j< m)
    {
        if (arr1[i]<arr2[j])
        {
            mergedArr [k++] = arr1[i++];
        }else
        {
            mergedArr[k++] = arr2[j++]; 
        }
    }
    while (i < n)
    {
        mergedArr[k++] = arr1[i++];
    }
    while (j < m)
    {
        mergedArr[k++] = arr2[j++];
    }
}



int main()
{

    int n,m;
    cout<<"Enter sizes of two arrays :";
    cin>> n >> m;

    int *arr1 = new int[n];
    int *arr2 = new int[m];
    int * mergedArr = new int [n+m];

    cout << "Enter " << n << " sorted elements for first array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter " << m << " sorted elements for second array: ";
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    mergeSortedArray(arr1, n, arr2, m, mergedArr);

    cout << "Merged Sorted Array: ";
    for (int i = 0; i < n + m; i++)
    {
        cout << mergedArr[i] << " ";
    }
    cout << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] mergedArr;
    
    cout << endl<< endl<< "24DIT006_PRINCEE BHINGRADIYA" << endl<<endl;

    return 0;
}