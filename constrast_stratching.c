#include<stdio.h>
#include<stdlib.h>

int **read_im(char **src_path,int *nrow,int *ncol,int *max){
	char p[10];
	char ch;
	int i,j,k=1,l;
	int n,r,x;
	int **m;
	
	
	FILE *fp;
	fp=fopen(*src_path,"r");
		if(fp==NULL){
		printf("file could not be open\n");
		exit(1);
	}
	
	while(k<=5){
		if(k==3){
			fscanf(fp,"%d %d",&*nrow,&*ncol);
//			printf("a=%d b=%d\n",*nrow,*ncol);
//			a=50;b=50;
			m=(int **)malloc(*nrow*sizeof(int*));
			for(l=0;l<*nrow;l++){
			m[l]=(int*)malloc(*ncol*sizeof(int));
			}
//		printf("matrix is created");
		}
		else if(k==4){
			fscanf(fp,"%d",&*max);
//			printf("max=%d\n",*max);
		}
		else if(k==5){
			for(i=0;i<*nrow;i++){
				for(j=0;j<*ncol;j++){
					fscanf(fp,"%d",&m[i][j]);
				}
			}
		}
		else{
			while((ch=getc(fp))!='\n'){
			//fscanf(fp,"%s",c);
//			fprintf(stdout,"%c",ch);
			//strcat(c,a);
			}
		printf("\n");
		}
	
	k++;
	
	}
return m;	

fclose(fp);
}

void write_im(int **m,char **des_path,int *nrow,int *ncol,int *max){
	FILE *des_file;
	int i,j;
	
	des_file=fopen(*des_path,"w");
	if(des_file==NULL){
		printf("unable to open the file\n");
		exit(1);
	}
	
	fprintf(des_file,"%s\n","P2");
	fprintf(des_file,"%s\n","# ASCII PGM file created by PGMA_WRITE@arnab");
	fprintf(des_file,"%d %d\n",*nrow,*ncol);
	fprintf(des_file,"%d\n",*max);
	for(i=0;i<*nrow;i++){
		for(j=0;j<*ncol;j++){
			fprintf(des_file,"%d ",m[i][j]);
		}
		fprintf(des_file,"\n");
	}
	printf("File copied\n");
	fclose(des_file);
	
}
/*
void line(int x1,int y1,int x2,int y2,char color){
int x=x1;
int y=y1;
int a=y2-y1;
int b=x1-x2;
float m=(a/-b);
int h=2a+b;
OnPixel(x,y,color);
if()
*/



void con(int **m,char **des_path,int *nrow,int *ncol,int *max){
	int r[*max];
	int min=255;
//	int count=0;
	FILE *des_file;
	int i,j,k,mat;
	
	des_file=fopen(*des_path,"w");
	if(des_file==NULL){
		printf("unable to open the file\n");
		exit(1);
	}

		
		for(k=0;k<*max;k++)
		r[k]=0;
		for(i=0;i<*nrow;i++){
		for(int j=0;j<*ncol;j++){
			mat=m[i][j];
			if(min>=mat){
			min=mat;				
			}
			}
		}


	for(i=0;i<*nrow;i++){
		for(j=0;j<*ncol;j++){
			m[i][j]=(256-1)*(m[i][j]-min)/(*max-min);		
		}	
	}
		for(i=0;i<*nrow;i++){
		for(int j=0;j<*ncol;j++){
			mat=m[i][j];
			r[mat-1]++;
			}
			
		}
	
	printf("min=%d\n",min);
	
	for(i=0;i<*max;i++){
		printf("%d|",i+1);
		for(int k=0;k<r[i];k+=100)
		printf(".");
		//printf("%d\n",r[i]);
		printf("\n");
	}
		
}



int main(int argc, char **argv){
	char *src_path, *des_path;
	
	int ch;
	int **m;
	int nrow;
	int ncol;
	int max;
	int i,j;
	
	
	if(argc!=3)
	printf("usage:a.out <src> <dst> \n");
	
	src_path=argv[1];
	des_path=argv[2];
	
	m=read_im(&src_path,&nrow,&ncol,&max);

	con(&*m,&des_path,&nrow,&ncol,&max);
	
	write_im(&*m,&des_path,&nrow,&ncol,&max);
	
		
	
	return 0;
}
