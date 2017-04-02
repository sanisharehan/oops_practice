#include <vector>
#include <iostream>

using namespace std;


vector<int> 
mergesort(vector<int> &nums, int start, int end) {
        if (end == start) {
            vector<int> a;
            a.push_back(nums[start]);
            return a;
        }
        
        int mid = (end + start)/2;
        
        vector<int> arr1 = mergesort(nums, start , mid);
        vector<int> arr2 = mergesort(nums, mid+1, end);
        
        for (int i = 0; i < arr1.size(); i++){
            cout << arr1[i] << endl;
        }
        cout << "****" << endl;
        
        for (int i = 0; i < arr2.size(); i++){
            cout << arr2[i] << endl;
        }
        
        cout << "=====" << endl;
        
        
        // Merge the two arrays
        int i=0, j=0;
        vector<int> result;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) {
                result.push_back(arr1[i]);
                i++;
            } else {
                result.push_back(arr2[j]);
                j++;
            }
        }
        
        // Add remaining elements
        while (i <= (arr1.size() - 1)) {
            result.push_back(arr1[i]);
            i++;
        }
        
        while (j <= (arr2.size() -1)) {
            result.push_back(arr2[j]);
            j++;
        }
        
        for (int i = 0; i < result.size(); i++){
            cout << result[i] << endl;
        }
        cout << "---------" << endl;
        
        return result;
}

int main(int argc, char *argv[]) {
  vector<int> a;
  a.push_back(5);
  a.push_back(3);
  a.push_back(2);

  vector<int> a_sort = mergesort(a, 0, a.size()-1);
  cout << "Code running" << endl;
  for (int i = 0; i < a_sort.size() ; i++) {
    cout << a_sort[i] << endl;
  }
  return 0;
}
