#include<bits/stdc++.h>
using namespace std;
//S L I D I N G     W I N D O W
//type 1: Constant Window
/*/Q. given array and k , take k consicutive ele and find max sum
void sum(vector<int>v,int k) {
    int sum=0;
    int mx=INT_MIN;
    for(int i=0; i<k; i++) {
        sum+=v[i];
    }
    mx=max(mx,sum);
    int i,j;
    i=0;
    j=k;
    cout<<sum<<" ";
    while(j<v.size()) {
        sum-=v[i++];
        sum+=v[j++];
        cout<<sum<<" ";
        mx=max(mx,sum);
    }
    cout<<"\n : "<<mx;
}
*/
//Longest Subarray with sum<=k
void longestArr(vector<int>v,int k) {
    int n=v.size();

//bruteforce:
    /*  vector<int>ans;
      int longSum=INT_MIN;
      int lenM=0;
      for(int i=0; i<n; i++) {
          int sum=0;
          int len=0;
          for(int j=i; j<n; j++) {
              sum+=v[j];
              len++;
              if(sum<=k) {
                  longSum=max(longSum,sum);
                  if(longSum==sum) {
                      lenM=max(len,lenM);
                  }
              }
          }
      }
      *//*

//Optimal
int ms=INT_MIN;
int lenM=0;
int len=0;
int s=0;
int l,r;
l=0;
r=0;
while(r<n) {
s+=v[r];
len++;
r++;
if(s<=k) {
ms=max(ms,s);
lenM=max(lenM,len);
}
else {

while(l<r) {
len--;
s-=v[l];
l++;
if(s<=k)break;
}
ms=max(ms,s);
lenM=max(lenM,len);
}
}
*/
    int l,r;
    int s=0;
    l=0,r=0;
    int maxl=0;
    int teml=0;
    while(r<n) {
        s+=v[r];
        teml++;
        if(s>k) {
            s-=v[r];
            teml--;

        }
        if(s<=k) {
            maxl=max(maxl,teml);
            r++;
        }
    }


    cout<<" Length :"<<maxl;
}


int main() {
    vector<int>v= {2,5,1,7,10};
    int k=14;
//   sum(v,k);
    longestArr(v,k);
    return 0;
}
