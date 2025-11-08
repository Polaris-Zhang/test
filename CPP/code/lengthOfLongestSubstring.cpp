#include<iostream>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_set<char> seen;
    int wins = 0,left = 0;
    for(int right = 0;right<s.length();right ++){
          if(seen.find(s[right])!=seen.end()){
                seen.erase(s[left]);
                left++;
          }
          seen.insert(s[right]);
          wins = max(wins,right-left+1);
    }
    return wins;
}

int main() {
    string testStr = "abcabcbb";
    cout << "Length of longest substring without repeating characters: " 
         << lengthOfLongestSubstring(testStr) << endl;
    return 0;
}