#include <stdio.h>

void supremoMerge(int v[], int i, int f, int m){
	if(f>0){
		if((f-i)%2==0){
			merge(v,i,m-1,(f-i)/2);
			merge(v,m,f,(f-i)/2);
		}else{
				
		}
	}
}

void merge(int v[], int i, int n, int m){
	f=m, k=0, nv[n],l;
	for(k=0;i < m && f < n;k++){
		if(v[i]<=v[f])
			nv[k] = v[i++];
		else{
			if(v[f]<=v[i])
			nv[k] = v[f++];
		}
	}
	
	for(i;i<m;i++)
		nv[i] = v[i];
	
	for(f;f<n;f++)
		nv[f] = v[f];	
	
	for(i=0;i<n;i++)
		v[i] = nv[i];
}

int main(){
	int n = 11;
	int v[] = {10,50,70,80,100,8,30,60,90,200,300};
	mergeSort(v,n,5);
	return 0;
}
