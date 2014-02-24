#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
long int maximize(long int a[],int n){
    long int b[50002];
    for(int i=0,k=n-1;i<n;i++,k--){
        b[k]=a[i];
    }
    long int prof=0,max=0;
    
    for(int i=0;i<n;i++){
        if(max<=b[i]){
            max=b[i];
        }
        prof+=max-b[i];
        
    }
 return prof;   
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long  int T,N,a[50002];
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=0;i<N;i++){cin>>a[i];
     
                            }
        cout<<maximize(a,N)<<endl;
    }     
    return 0;
}
 
