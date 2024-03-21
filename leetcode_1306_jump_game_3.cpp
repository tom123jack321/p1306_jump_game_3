// My solution to LeetCode problem "1306. Jump Game III"
// https://leetcode.com/problems/jump-game-iii/description/
// Recursive
// 1. Recursion formula : J(i) = J(i+a[i]) + J(i-a[i]), where "J" denotes recursive function "jump_2" and "i" the index of array "arr"
// 2. Returned quantity : bool, with 0 as false, 1 as true (in accordance wit the formula)
// 3. Input parameters : vector "spot" marking whether a position of "arr" has been visited, with 1 as yes, 0 as no; others like "arr", index "a" and vector of positions of value 0, are clear
// 4. Boundary condition : for the function to terminate ("return"), check whether it reaches any element in "v0", whether access to "arr" elements crosses either boundary, whether the position "a" has been visited
// Result : submitted to LeetCode and passed all tests with 28ms runtime (beats 86.89% of users with c++) and 40.66MB memory (beats 30.99% of users with c++) (why it consumes so much memory is beyond me)

#include <iostream>
#include <vector>
// #mark a#

using namespace std;

class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    bool b;
    int s=arr.size();
    vector<int> v0;
    for(int i=0;i<s;i++){ if(arr[i]==0){ v0.push_back(i);} }
    // cout << "arr ";
    // for (int i=0;i<arr.size();i++){ cout << arr[i] << " " ;}
    // cout << endl;
    // cout << "v0 ";
    // for (int i=0;i<v0.size();i++){ cout << v0[i] << " " ;}
    // cout << endl;
    vector<int> spot(s, -1);
    b=jump_2(arr, start, spot, v0);
    return b;
  }
  // #mark f#
  bool jump_2(const vector<int>& arr, const int a, vector<int>& spot, const vector<int>& v0 ){
    bool b=0;
    // #mark h#
    for(int i=0;i<v0.size();i++){
      if(a==v0[i]){ return true; }
    }
    if(a<0 || a> arr.size()-1 ){ return false; }
    else if(spot[a]==1){ return false; }
    spot[a]=1; 
    b=jump_2(arr, a+arr[a], spot, v0) + jump_2(arr, a-arr[a], spot, v0);
    return b;
  }
};

// #mark z#

int main(){
  Solution sol;
  // vector<int> arr={4,2,3,0,3,1,2};
  // int start=5;
  // vector<int> arr={4,2,3,0,3,1,2};
  // int start=0;
  // vector<int> arr={3,0,2,1,2};
  // int start=2;
  vector<int> arr={0,0};         // true
  int start=0;
  // vector<int> arr={0,3,0,6,3,3,4};         // true
  // int start=6;
  bool b=sol.canReach(arr, start);
  cout << "b " << b << "\n";
}
