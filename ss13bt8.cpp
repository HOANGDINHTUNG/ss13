#include<stdio.h>
int UCLN(int x,int y){//giai thuat Euclid
	while(y!=0){
		int r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int main(){
	int a,b;
	printf("moi nhap vao a: ");
	scanf("%d",&a);
	printf("moi nhap vao b: ");
	scanf("%d",&b);
	printf("Uoc chung lon nhat cua %d va %d la %d",a,b,UCLN(a,b));
	return 0;
}
