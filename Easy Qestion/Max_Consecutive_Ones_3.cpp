#include<bits/stdc++.h>
using namespace std;
//Max consecutive ones
//Brute Force    TC=O(n^2)
void MaxOnes1(vector<int>v,int k) {
    int n=v.size();
    int Mx=0;
    for(int i=0; i<n; i++) {
        int cnt=k;
        int l=0;
        for(int j=i; j<n; j++) {
            if(v[j]==1) {
                l++;
                Mx=max(Mx,l);
            }
            else if(v[j]==0&&cnt>0) {
                cnt--;
                l++;
                Mx=max(Mx,l);
            }
            else {
                break;
            }
        }
    }
    cout<<Mx;
}
//Better
/*
void MaxOnes(vector<int>v,int k) {
    int n=v.size();
    int l,r,cnt,len,lm;
    cnt=l=r=l=lm=0;
    while(r<n) {
        if(v[r]==1) {
            len=r+1-l;
            lm=max(lm,len);
            r++;

        }
        else {
            while(cnt>=k) {
                if(v[l]==0) {
                    cnt--;
                }
                l++;
            }
            len=r+1-l;
            lm=max(lm,len);
            r++;
            cnt++;
        }
    }
    cout<<lm;
}
*/

int main() {
    vector<int>v= {0,0,1,1,1,0,0};

    // MaxOnes1(v,2);
    MaxOnes(v,0);

    return 0;
}
