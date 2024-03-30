#include<bits/stdc++.h>
using namespace std;
//Longest Sub Array Without repeatation 
void LengOfSubstring(string s) {
//TC : O(n)
    int lm=0;
    int i=0;
    int n=s.length();
    int j=0;
    int l=0;
    unordered_map<char,int>st;
//string tem="";
    /* while(i<n) {
         if(st.find(s[i])==st.end()) {
             l++;
             lm=max(lm,l);
             st.insert(s[i]);
             i++;
         }
         else {
             st.erase(s[j]);
             l--;
             j++;
         }

     }*/
    while(i<n) {

        auto it=st.find(s[i]);
        if(it==st.end() || it->second<j) {
            l++;
            st[s[i]]=i;
            i++;
            lm=max(lm,l);
        }
        else {


            // st.erase(s[j]);
            j=st[s[i]]+1;
            st[s[i]]=i;

            l=i+1-j;
            i++;
        }

    }

    cout<<lm;
}


int main() {
    string s="cadbzabcd";
    LengOfSubstring(s);
    return 0;
}
