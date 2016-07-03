#include<stdio.h>

main(){
	int x;
	//int *p;
	x=0x765432f2;
	char *c=(char*)(&x);
	//printf("%x\n",&x);
	printf("%x\n",*c);
	printf("%x\n",*(c+1));
	printf("%x\n",*(c+2));
//	int x1=(int)(*c);
//	printf("%d",x1);
	
}
