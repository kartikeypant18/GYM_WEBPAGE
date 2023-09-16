#include <bits/stdc++.h>

using namespace std;
int f(vector<int>& wt, vector<int>& val, int ind, int W,vector<vector<int>>&dp)
{
	if(ind==0)
	{
		if(wt[0]<=W) return val[0];
		else return 0;
	}
	if(dp[ind][W]!=-1)return dp[ind][W];
	int take=INT_MIN;
	int not_take=0+f(wt,val,ind-1,W,dp);
	if(wt[ind]<=W)
	take=val[ind]+f(wt,val,ind-1,W-wt[ind],dp);
	return dp[ind][W]=max(take,not_take);
}
int knapsack(vector<int>& wt, vector<int>& val, int n, int W) 
{
	vector<vector<int>>dp(n,vector<int>(W+1,-1));
	return f(wt,val,n-1,W,dp);
}
int main() {

  int n;
  cin>>n;
  vector<int>val;
  vector<int>wt;
  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      val.push_back(x);
  }
  for(int i=0;i<n;i++)
  {
      int x;
      cin>>x;
      wt.push_back(x);
  }
  int W;
  cin>>W;
  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}