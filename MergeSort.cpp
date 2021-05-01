#include<bits/stdc++.h>

using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define ss(s) scanf("%s",s)
#define str(x) strlen(x)
#define pb push_back

void change(int &x,int &y)
{
	int aux=x;
	x=y;
	y=aux;
}
void imprimir(int a[],int n) //n elementos del vector
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
}

void Merge(int a[],int lo,int mi,int hi){
		int n1,n2,index1,index2,k;
		n1=mi-lo+1;// lo ,lo+1, ... mi = mi-lo+1
		n2=hi-mi;   // mi+1,mi+2 .. hi  = hi-mi-1+1
		
		int arr1[n1],arr2[n2];
		
		for(int i=0;i<n1;i++)
			arr1[i]=a[lo+i];
		for(int i=0;i<n2;i++)
			arr2[i]=a[mi+1+i];
		
		index1=0,index2=0,k=lo;
		
		while(index1<n1 && index2<n2)
		{
			if(arr1[index1]<arr2[index2]){
				a[k++]=arr1[index1++];
			}
			else {
				a[k++]=arr2[index2++];
			}
		}
		
		while(index1<n1){
			a[k++]=arr1[index1++];
		}
		while(index2<n2){
			a[k++]=arr2[index2++];
		}
		
}

void Mergesort(int a[],int lo,int hi){
	if(lo>=hi)return ;
	int mi=(lo+hi)/2;
	Mergesort(a,lo,mi);
	Mergesort(a,mi+1,hi);
	Merge(a,lo,mi,hi);
}
int main()
{
	int a[]={88,79,21,15,99,88,88,65,75,88,85,76,46,84,24,88,88,48,88,45,0,88};
	int n=sizeof(a)/sizeof(int);
	int primero=0;
	int ultimo=n-1;
    Mergesort(a,primero,ultimo);	
    imprimir(a,n);

	return 0;
}
