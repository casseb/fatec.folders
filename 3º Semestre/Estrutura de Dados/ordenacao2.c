#include <stdio.h>

void sortMerge(int v[], int i, int f){
	int meio;
	if(i<f){
		meio = (f+i)/2;
		sortMerge(v,i,meio);
		sortMerge(v,meio+1,f);
		merge(v,i,f,meio);
	}
}


void merge(int v[], int i, int n, int m){
	int f=m, k=0, nv[n],l;
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
	sortMerge(v,0,n);
	int i;
	for(i=0;i<n;i++){
		printf("%i\n",v[i]);
	}
	return 0;
}
