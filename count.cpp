#include<stdio.h>

int main(){
	int a[10]={2,5,6,7,5,2,9,3,5,4};
	int r[10];
//	int count=0;
	for(int k=0;k<10;k++)
	r[k]=0;
	for(int i=0;i<10;i++){
		for(int j=1;j<=10;j++){
			if(a[i]==j){
				r[j-1]++;
			//	printf("%d\n",r[i]);
			//	count=count+1;
			}
			
		}
	}
	
	for(int i=0;i<10;i++){
		printf("%d|",i+1);
		for(int k=0;k<r[i];k++)
		printf("*");
		printf("\n");
	}
		
		
}

