/* Binary search is an important component in competitive programming or any algorithmic competition, having knowledge of shorthand functions reduces the time to code them. This searching only works when container is sorted. Related functions are discussed below.
**Binary_search(start_ptr, end_ptr, num)** : This function returns boolean true if the element is present in the container, else returns false.
*/

// C++ code to demonstrate the working of binary_search() 
  
#include<bits/stdc++.h>  
using namespace std; 
  
int main() 
{ 
    // initializing vector of integers 
    vector<int> arr = {12, 13, 220, 234, 20, 65}; 
      
    // using binary_search to check if 15 exists 
    if (binary_search(arr.begin(), arr.end(), 134)) 
       cout << "134 exists in vector"; 
    else 
       cout << "134 does not exist"; 
       
    cout << endl; 
} 
