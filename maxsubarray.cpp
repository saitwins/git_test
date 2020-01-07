#include<iostream>
#include<tuple>
using namespace std;
tuple<int, int, int> maxcross(int *a,int low,int mid,int high)
{
	signed int lsum=-100000;
	signed int rsum=-100000;
	int sum=0;
        int maxl,maxr;
	for(int i=mid;i>=low;i--)
	{
		sum=sum+a[i];
		if(sum>lsum)
		{
			lsum=sum;
			maxl=i;
		}
	}
	sum=0;
	for(int i=mid+1;i<=high;i++)
	{
		sum=sum+a[i];
		if(sum>rsum)
		{
			rsum=sum;
			maxr=i;
		}
	}
	return make_tuple(maxl,maxr,lsum+rsum);
	
}
tuple<int,int,int> maxsub(int *a,int low,int high)
{
int llow,lhigh,lsum,rlow,rhigh,rsum,clow,chigh,csum;
int mid;	
	if(low==high)
	{
		return make_tuple(low,high,a[low]);
	}
	else
	  mid=((low+high)/2);
	  tie(llow,lhigh,lsum)=maxsub(a,low,mid);
	  tie(rlow,rhigh,rsum)=maxsub(a,mid+1,high);
	  tie(clow,chigh,csum)=maxcross(a,low,mid,high);
	  if(lsum>=rsum && lsum>=csum)
	  {
	     return make_tuple(llow,lhigh,lsum);	
	  }
	  if(rsum>=lsum && rsum>=csum)
	  {
	  	return make_tuple(rlow,rhigh,rsum);
	  }
	  if(csum>=lsum && csum>=rsum)
	  {
	    return make_tuple(clow,chigh,csum);	
	  }
}
int main()
{
	int n,l,h,v;
	cout<<"enter the n value";
	cin>>n;
	int p[n];
        for(int i=0;i<n;i++)
        {
        cin>>p[i];
        }
	tie(l,h,v)=maxsub(p,0,n-1);
	cout<<"i val"<<l<<"\n";
	cout<<"j val"<<h<<"\n";
	cout<<"v val"<<v;
}
