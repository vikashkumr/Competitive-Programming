/*
 Sort a large set of floating point numbers which are in the range 0.0 to 1.0 and are uniformly distributed across the range
 Bucket sort is mainly useful when input is uniformly distributed over a range. For example, consider the following problem. 
Algo: 
bucketSort(arr[], n)
1) Create n empty buckets (Or lists).
2) Do following for every array element arr[i].
    a) Insert arr[i] into bucket[n*array[i]]
3) Sort individual buckets using insertion sort.
4) Concatenate all sorted buckets.

TC: O(n) in best case O(n^2) in worst case
SC: O(n+k) k = bucket size
*/
[input] : 0.35, 0.12, 0.43, 0.15, 0.04, 0.50, 0.132

bucket   element
1 =>    0.04
2 =>    0.12 -> 0.132 -> 0.15
3 =>    0.35
4 =>    0.43
5 =>    0.50
6 =>
7 =>
8 =>
9 =>

aafter doing just traverse and print all number element will always present in sorted order
insertion in bucket take place 

//programme

// Function to sort arr[] of size n using bucket sort 
void bucketSort(float arr[], int n) { 
    // 1) Create n empty buckets 
    vector<float> b[n]; 
  
    // 2) Put array elements in different buckets 
    for (int i = 0; i < n; i++) { 
        int bi = n * arr[i]; // Index in bucket 
        b[bi].push_back(arr[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i = 0; i < n; i++) 
        sort(b[i].begin(), b[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
            arr[index++] = b[i][j]; 
} 

int main() { 
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    bucketSort(arr, n); 
  
    cout << "Sorted array is \n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
}