#include<bits/stdc++.h>
using namespace std;
//Q.Maximum Points you get from n cards
void MxPoints(vector<int>v,int k) {
    int n=v.size();
    int maxPoints=INT_MIN;
    int r=n-k;

    int l=0;
    int points=0;
    for(int i=r; i<n; i++)points+=v[i];
    maxPoints=max(maxPoints,points);

    while(l<k && r<n) {
        points-=v[r];
        r++;
        points+=v[l];
        l++;
        maxPoints=max(maxPoints,points);
    }
    cout<<maxPoints;
}


int main() {
    vector<int>v= {6,2,3,4,7,2,1,7,1};
    int k=4;
    MxPoints(v,k);
    return 0;
}
