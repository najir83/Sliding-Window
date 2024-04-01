#include<bits/stdc++.h>
using namespace std;
//Fruit into Baskets
//BruteForce ..TC=O(n^2)
/*void fruitNo(vector<int>v) {
    int n=v.size();
    int f1=0,f2=0;
    int f, mf=0;
    for(int i=0; i<n; i++) {
        f1=-1,f2=-1;
        f=0;
        for(int j=i; j<n; j++) {
            if(f1==-1 && v[j]!=f2) {
                f1=v[j];
            }
            else if(f2==-1 && v[j]!=f1) {
                f2=v[j];
            }
            if(v[j]==f1 || v[j]==f2) {
                f++;
            }
            else {
                mf=max(mf,f);
                break;
            }
        }
    }

    cout<<"The max Fruit : "<<mf<<endl;
}
*/
//Batter
/*
TC=O(n^2). Sc=O(3)
void fruitNo(vector<int>v) {
    int n=v.size();

    int i,j;
    unordered_map<int,int>m;
    int lm;
    lm=0;
    i=j=0;
    while(i<n) {
        m[v[i]]++;
        while(m.size()>2) {
            m[v[j]]--;
            if(m[v[j]]==0) {
                m.erase(v[j]);
                j++;
                break;
            }
            j++;
        }
        if(m.size()<=2) {
            int l=i+1-j;
            lm=max(lm,l);
        }



        i++;
    }
    cout<<lm<<endl;
}
*/
//Optimal
//TC=O(n). Sc=O(n/2)
void fruitNo(vector<int>v) {
    int n=v.size();

    int i,j;
    unordered_map<int,int>m;
    int lm;
    lm=0;
    i=j=0;
    while(i<n) {
        m[v[i]]++;
        if(m.size()>2) {
            m[v[j]]--;
            if(m[v[j]]==0) {
                m.erase(v[j]);
            }
            cout<<m.size()<<" ";
            j++;
        }


        if(m.size()<=2) {
            int l=i+1-j;
            lm=max(lm,l);
        }



        i++;
    }
    cout<<lm<<endl;
}
int main() {
    vector<int>v= {1,2,1,2,1,2,1,2,1,2,3,4,5,6,7,8,9,10,11,12,13};
    fruitNo(v);


    return 0;

}
