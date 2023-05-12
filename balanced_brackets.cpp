// Solve this problem on LeetCode and copy your code here to submit
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

class Solution {
public:
    bool isValid(string s)
     {
         stack<char> temp;
         for(int i=0; i < s.length(); i++){
             if(temp.empty()){
                 temp.push(s[i]); //stack empty push the current brackets

             }
             else if((temp.top() == '(' && s[i] == ')') || (temp.top() == '[' && s[i] == ']') || (temp.top() == '{' && s[i] == '}')){
                 temp.pop(); //if found any complete pair of bracket
             }
             else{
                 temp.push(s[i]);
             }
         }
         if(temp.empty()){
             //if stack is empty return true
             return true;
         }
         return false;
        }
};

int main()
        {
          int t=9999999;
          while(t--){
            Solution obj;
            string a;
            cin>>a;
            int check = obj.isValid(a);

            if(check==1)
                cout<<"Balanced"<<endl;

            else if(check==0)
                cout<<"Not-Balanced"<<endl;

            else
                cout<<"NA"<<endl;
        }
        return 0;
        }



