#include<bits/stdc++.h>
using namespace std;
//Longest Substring with atmost k distrint character
//Brute Force
void len(string s,int k) {
    int n=s.length();
    int lenM=0;
    for(int i=0; i<n; i++) {
        set<char>st;
        for(int j=i; j<n; j++) {
            st.insert(s[j]);
            if(st.size()>k)break;

            lenM=max(lenM,j+1-i);
        }
//TC=O(n^2)

    }
    cout<<lenM<<endl;
}
//Batter
void len2(string s,int k) {
    int n=s.length();
    int lenM=0;
    int l,r;
    l=r=0;
    unordered_map<char,int>m;
    while(r<n) {
        m[s[r]]++;
        while(l<=r &&m.size()>k) {
            m[s[l]]--;
            if(m[s[l]]==0) {
                m.erase(s[l]);
            }
            l++;
        }
        lenM=max(lenM,r+1-l);
        r++;
    }
    //TC : O(2n) SC: O(k)
    cout<<lenM<<endl;
}
//Optimal
void len3(string s,int k) {
    int n=s.length();
    int lenM=0;
    int l,r;
    l=r=0;
    unordered_map<char,int>m;
    while(r<n) {
        m[s[r]]++;
        if(m.size()>k) {
            m[s[l]]--;
            if(m[s[l]]==0) {
                m.erase(s[l]);
            }
            l++;
        }
        if(m.size()<=k) {
            lenM=max(lenM,r+1-l);
        }
        r++;
    }
    //TC : O(n) SC : O(n/2)
    cout<<lenM<<endl;
}



int main() {
    string s="aaabbccd";
    int k=2;
    len(s,k);
    len2(s,k);
    len3(s,k);


    return 0;
}
