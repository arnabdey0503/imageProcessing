#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int a,b,i,j,k=1,l,e;
	int **m;
	char ch,ck;
	char c[50];
	//char a[10];
	FILE *fp;
	fp=fopen("pbmlib.ascii.pgm","r");
	if(fp==NULL){
		printf("file could not be open\n");
	}
	while(k<=5){
		if(k==3){
			fscanf(fp,"%d %d",&a,&b);
			printf("a=%d b=%d\n",a,b);
//			a=50;b=50;
			m=(int **)malloc(a*sizeof(int*));
			for(l=0;l<a;l++){
			m[l]=(int*)malloc(b*sizeof(int));
			}
//		printf("matrix is created");
		}
		else if(k==4){
			fscanf(fp,"%d",&e);
			printf("e=%d\n",e);
		}
		else if(k==5){
			for(i=0;i<a;i++){
				for(j=0;j<b;j++){
					fscanf(fp,"%d",&m[i][j]);
				}
			}
		}
		else{
			while((ch=getc(fp))!='\n'){
			//fscanf(fp,"%s",c);
			fprintf(stdout,"%c",ch);
			//strcat(c,a);
			}
		printf("\n");
		}
	
	k++;
	
	}
	
//	for(i=0;i<a;i++){
//		for(j=0;j<b;j++){
//			fscanf(fp,"%d",m[i][j]);
//		}
//	}
	
	printf("Matrix is:\n");
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	fclose(fp);
}


/*
R/W PGM see the pdf

write:
unsigned int ** read im(path);
int write im(unsigned int **mat,int nrow, int ncol, save path);
*/
