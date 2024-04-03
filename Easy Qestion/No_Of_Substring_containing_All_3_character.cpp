#include<bits/stdc++.h>
using namespace std;
//No of substr containing all 3 character
//Brute Force
void No(string s) {
    int n=s.length();
    int lenM=0;
    for(int i=0; i<n; i++) {
        set<char>st;
        for(int j=i; j<n; j++) {
            st.insert(s[j]);
            if(st.size()==3) {
                lenM++;
            }
        }
//TC=O(n^2)

    }
    cout<<lenM<<endl;
}
//Batter

void No2(string s) {
    int n=s.length();
    int lenM=0;
    int l,r;
    l=r=0;
    unordered_map<char,int>m;
    while(r<n) {
        m[s[r]]++;
        while(m.size()==3) {
            lenM+=(1+(n-r-1));
            m[s[l]]--;
            if(m[s[l]]==0) {
                m.erase(s[l]);
            }
            l++;
        }
        r++;
    }

//tc=O(2n) sc=O(3)
    cout<<lenM<<endl;
}
void No3(string s) {
    int n=s.length();
    int lenM=0;
    vector<int>v(3,-1);
    for(int i=0; i<n; i++) {
        v[s[i]-'a']=i;
        if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1) {
            lenM+=(1+min(v[0],min(v[1],v[2])));
        }
    }
    //TC : O(n)
    cout<<lenM<<endl;
}


int main() {
    string s="bbacba";

    No(s);
    No2(s);
    No3(s);
    return 0;
}
