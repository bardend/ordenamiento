#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define str(x) strlen(x)
#define pb push_back
#define DBG(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define RAYA do {cerr << "===========================" << endl; } while (false)
//#define DBG do { } while(false);
//#define RAYA do { }while(false);
const ll MOD=1e9+7;



void change(int &x,int &y){
	int aux=x;
	x=y;
	y=aux;
}

int left(int pos){
	return 2*pos;
}
int rigth(int pos){
	return 2*pos+1;
}
	
void Max_Heapify(int a[],int i,int siz){
	int largest,l,r;
	largest=i;
	l=left(i);
	r=rigth(i);

	if(l<=siz && a[l]>a[largest])
		largest=l;		
		
	if(r<=siz && a[r]>a[largest])
		largest=r;
			
	if(largest!=i){
		
		change(a[i],a[largest]);
		Max_Heapify(a,largest,siz);				
	}
}
	
void BUILD_MAX_HEAP(int a[],int siz){
	for(int k=siz/2;k>=1;k--){
		Max_Heapify(a,k,siz);
	}
}

void HEAPSORT(int a[],int siz){	
	BUILD_MAX_HEAP(a,siz);
	for(int i=siz;i>=2;i--){
		change(a[i],a[1]);
		Max_Heapify(a,1,i-1);
	}
	
	 for (int i = 1; i <= siz; i++)
    
		cout<<a[i]<<" ";
    
}
/*
 10
  1 9 5 7 3 6 4 8 2 0
*/
int main(){
	int n;
	cin>>n;
	
	int a[n+1];
 	for(int i=1;i<=n;i++)
		cin>>a[i];
		
		
	HEAPSORT(a,n);
	
	return 0;
}
