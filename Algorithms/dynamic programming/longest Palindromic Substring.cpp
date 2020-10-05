#include<bits/stdc++.h>
using namesapce std;

//dp approach
//consumes extra space of n^2
// int palin(string s){
//   int n = s.length();
//   int dp[n][n]={0};
//   int maxlength=1;
//   for(int i=0;i<n;i++){
//     dp[i][i]=1;
//   }
//   for(int i=0;i<n-1;i++){
//     if(s[i]==s[i+1]){
//       maxlength=2;
//       dp[i][i+1]=1;
//     }
//   }
//   for(int k=3;k<=n;k++){
//       for(int i=0;i<n-k+1;i++){
//         int j=i+k-1;
//         if(dp[i+1][j-1]==1 && s[i]==s[j]){
//           if(maxlength<k){
//             maxlength=k;
//           }
//           dp[i][j]=1;
//         }
//       }
//   }
//   return maxlength;
// }

//to save space
//Approach : fixing centre and then traversing to its right and left
int palin(string s){
  int n = s.length();
  int maxlength=1;
  int high,low;
  for(int i=1;i<=n;i++){
    low=i-1;high=i;
    while(low>=0 && high<n && s[low]==s[high]){
      if(maxlength<high-low+1){
        maxlength=high-low+1;
      }
      low--;
      high++;
    }
    low=i-1;high=i+1;
    while(low>=0 && high<n && s[low]==s[high]){
      if(maxlength<high-low+1){
        maxlength=high-low+1;
      }
      low--;
      high++;
    }
  }
  return maxlength;
}

int main(){
  string s;
  cin>>s;
  int maxlength=palin(s);
  cout<<maxlength<<"\n";
}
