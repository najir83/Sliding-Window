#include<bits/stdc++.h>
#include <chrono>
using namespace std;
//Largest Repeating Character Replacment
void longestlen(string s,int k) {
    int n=s.length();
    int len=0;
    for(int i=0; i<n; i++) {
        int mxFrequency=0;
        vector<int>v(26,0);

        for(int j=i; j<n; j++) {
            v[s[j]-'A']++;
            mxFrequency=max(mxFrequency,v[s[j]-'A']);
            if((j+1-i)-mxFrequency<=k) {
                len=max(len,j+1-i);
            }
            else {
                break;
            }
        }
    }
    cout<<len<<endl;
}


//TC=O(n^2)
//Batter
void longestlen2(string s,int k) {
    int n=s.length();
    int len=0;
    vector<int>v(26,0);
    int l,r;
    l=r=0;
    int fre=0;
    while(r<n) {
        v[s[r]-'A']++;
        fre=max(fre,v[s[r]-'A']);
        if((r-l+1)-fre>k) {
            v[s[l]-'A']--;
            // fre=max(fre,v[s[l]-'A']);
            l++;
        }
        len=max(len,r+1-l);
        r++;
    }
    cout<<len<<endl;
}

int main() {
    auto start=
        chrono::high_resolution_clock::now();

    string s="AABABBADAASDAA";
    int k=2;
    longestlen(s,k);
    longestlen2(s,k);



    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double,milli> duration = end - start;

    // Output the duration
    cout << "\nTime taken: " << duration.count() << "seconds" << endl;

    return 0;
}
