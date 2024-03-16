#include<iostream>
using namespace std;

// Simple Binary Search
/*
int binarySearch(int arr[], int n, int key){

    int start = 0;
    int end = n-1;

    int mid = start + (end - start)/2;

    while(start <= end){

        if(arr[mid] ==  key){
            return mid; 
        }
        else if(arr[mid] < key){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){

    int even[6] = {2, 4, 6, 8, 10, 18};
    int odd[5] = {10, 15, 18, 22, 25};

    int key;
    cout<<"Enter the Key: ";
    cin>>key;

    int index = binarySearch(odd, 6, key);
    cout << "Index of key: " << index;
    return 0;
}
*/

// First and Last Position of of an Element sorted array
/*
int firstOccur(int arr[], int n, int key){
    
    int s = 0, e = n-1;
    int mid = s + (e-s) / 2;
    int ans = -1;

    while(s <= e){

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }

        else if(arr[mid] < key){
            s = mid + 1;
        }

        else if(arr[mid] > key){
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }
    return ans;
}

int lastOccur(int arr[], int n, int key){

    int s = 0, e = n-1;
    int mid = s + (e-s) / 2;
    int ans = -1;

    while(s <= e){

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }

        else if(arr[mid] < key){
            s = mid + 1;
        }

        else if(arr[mid] > key){
            e = mid - 1;
        }
        mid = s + (e-s) / 2;
    }
    return ans;
}

int main(){

    int array[8] = {1, 2, 3, 3, 3, 4, 7, 8};
    int key;
    cout<<"Enter the Key: ";
    cin>>key;

    cout << "First Occence of key: " << firstOccur(array, 8, key) << endl;
    cout << "First Occence of key: " << lastOccur(array, 8, key) << endl;
}
*/

// Get pivot element
/*
int getPivot(int arr[], int n){

    int s = 0;
    int e = n-1;
    int mid = s + (e-s) / 2;

    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s) / 2;
    }
    // return e;
    return s;
}

int main(){
    int array[5] = {3, 8, 10, 17, 1};
    cout << "Pivot is: " << getPivot(array, 5) << endl;
}
*/

// Find Square Root
long long int sqrtInt(int n){
    int s = 0;
    int e = n;
    long long int mid = s + (e-s) / 2;
    long long int ans = -1;

    while(s <= e){
        long long int square = mid*mid;
        if(square == n){
            return mid;
        }

        if(square < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
         mid = s + (e-s) / 2;
    }
    return ans;
}

double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i<precision; i++){
        factor = factor/10;
        for(double j = ans; j*j<n; j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){

    int n;
    cout<<"Enter the Number: ";
    cin>>n;

    int tempSol = sqrtInt(n);
    cout << "Square Root of Number: " << morePrecision(n, 5, tempSol) << endl;
    return 0;
}