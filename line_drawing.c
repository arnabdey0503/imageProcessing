#include<stdio.h>
#include<stdlib.h>


int main(int argc, char **argv){
	char *des_path;
	int x1,x2,y1,y2;
	FILE *des_file;
	int i,j,l,k;
	
	int ch;
	int **m;
	int nrow=600;
	int ncol=600;
	int max=255;
	float ma;
	
	
	if(argc!=2)
	printf("usage:a.out <dst> \n");
	
	des_path=argv[1];	


	des_file=fopen(des_path,"w");
	if(des_file==NULL){
		printf("unable to open the file\n");
		exit(1);
	}
	m=(int **)malloc(nrow*sizeof(int*));
			for(l=0;l<nrow;l++){
			m[l]=(int*)malloc(ncol*sizeof(int));
			}
	for(i=0;i<nrow;i++){
		for(j=0;j<ncol;j++){
			m[i][j]=255;
			if((i%10==0)||(j%10==0))
			m[i][j]=200;
		}
	}

fprintf(des_file,"%s\n","P2");
	fprintf(des_file,"%s\n","# ASCII PGM file created by PGMA_WRITE@arnab");
	fprintf(des_file,"%d %d\n",nrow,ncol);
	fprintf(des_file,"%d\n",max);
	
		

	printf("Enter x1 & y1 \n");
	scanf("%d %d",&x1,&y1);
	printf("Enter x2 & y2 \n");
	scanf("%d %d",&x2,&y2);
	ma=(float)(y2-y1)/(x2-x1);
	printf("m=%f",ma);
	int x=x1;
	int y=y1;
	while(x<=x2){
	if(ma<=1){
		x=x+1;
		y=(int)(y+(float)(ma+0.5));
//		printf("(%d %d)\n",x,y);
		}
	else{
	y=y+1;
	x=(int)(x+(1/ma)+0.5);
//	printf("(%d %d)\n",x,y);	
		}
	m[x][y]=0;		
	}
		for(i=0;i<nrow;i++){
		for(j=0;j<ncol;j++){
			fprintf(des_file,"%d ",m[i][j]);
		}
		fprintf(des_file,"\n");
	}
printf("File copied\n");

fclose(des_file);
return 0;
}
