#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
#define ss(s) scanf("%s",s)
#define str(x) strlen(x)
#define pb push_back
#define DBG(x) do {cerr << #x <<" = " << (x) << endl; } while (false)
#define RAYA do {cerr << "===========================" << endl; } while (false)
const int N=1e6+5;

void intercambiar(int &x,int &y)
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

void ordQuicksort(int a[],int primero,int ultimo)
{	
	if(primero>ultimo)return;
	int i,j,central;
	int pivote;
	central=(primero+ultimo)/2;
	pivote=a[central];
	i=primero;
	j=ultimo;
	do{
		while (a[i]<pivote) i++;
		while (a[j]>pivote) j--;
		if (i<=j)
		{
			intercambiar(a[i],a[j]);
			i++;
			j--;
		}
	}while (i<=j);
	
	ordQuicksort(a,primero,j);
	ordQuicksort(a,i,ultimo);
}
int main()
{
	int a[]={88,79,21,15,99,88,88,65,75,88,85,76,46,84,24,88,88,48,88,45,0,88};
	int n=sizeof(a)/sizeof(int);
	int primero=0;
	int ultimo=n-1;
	ordQuicksort(a,primero,ultimo);	
	imprimir(a,n);
	return 0;
}

