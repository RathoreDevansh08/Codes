#include<cstdio>
using namespace std;

long int squares[50001];

long int findRing(int st, int end, long int k){
	long int mid=(st+end)/2;
	if(st>end)	return (2*st+1);
	if(squares[mid]==k)	return (2*mid+1);
	else if(squares[mid]<k)	return findRing(mid+1,end,k);
	else	return findRing(st,mid-1,k);
}

long int corner[5], row, column;

void index(int r, long int k, int n){
	long int steps;	row=n/2;	column=n/2;
	if(r==1)	return;
	if(k>=corner[0] && k<=corner[1]){	steps=k-corner[0];	row+=(r-1)/2;	column+=((r-1)/2)-steps-1;	return;	}
	if(k>=corner[1] && k<=corner[2]){	steps=k-corner[1];	column-=(r-1)/2;	row+=((r-1)/2)-steps;	return;	}
	if(k>=corner[2] && k<=corner[3]){	steps=k-corner[2];	row-=(r-1)/2;	column+=steps-((r-1)/2);	return;	}
	if(k>=corner[3] && k<=corner[4]){	steps=k-corner[3];	column+=(r-1)/2;	row+=steps-((r-1)/2);	return;	}
}

int main(){
	long int cnt=1;
	for(long int i=0; i<50001; i++){	squares[i]=cnt*cnt;	cnt+=2;	}
	long int r, n, k;
	while(scanf("%ld%ld",&n,&k)!=EOF){
		if(n==0 && k==0)	break;
		r = findRing(0,50000,k);
		corner[4]=r*r;		corner[0]=(r-2)*(r-2)+1;
		for(int i=3; i>0; i--)	corner[i]=corner[i+1]-r+1;
		index(r,k,n-1);
		printf("Line = %ld, column = %ld.\n",row+1,column+1);
	}
	return 0;
}

// First we need to find the ring in which k lies
// Then we need to find the corners, using corners and k value we can find the required index
// Time complexity is O(sqrt(k)) for each test case			, time 0.03 seconds
// We can make it fast by preprocessing all the squres, then use binary search in each test case, O(log(k))	, 0.000 seconds
