#include<stdio.h>
#define MAX 100
int row,col;
int array[MAX][MAX];
void inputMatrix();
void outputMatrix(); 
void matrixAngle();
void matrixBoundary();
void mainAndSecondaryCross();
void matrixIsprime();
int main(){
	int choice;
	do{
		printf("=============MENU============\n");
		printf("1.Nhap gia tri cac phan tu cua mang\n");
		printf("2.In ra cac phan tu cua mang theo ma tran\n");
		printf("3.In ra cac phan tu cua goc theo ma tran\n");
		printf("4.In ra cac phan tu nam tren duong bien theo ma tran\n");
		printf("5.In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
		printf("6.In ra cac phan tu la so nguyen to theo ma tran\n");
		printf("7.Thoat\n");
		printf("Moi nhap su lua chon cua ban: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				inputMatrix();
				break;
			}
			case 2:{
				outputMatrix();
				break;
			}
			case 3:{
				matrixAngle();
				break;
			}
			case 4:{
				matrixBoundary();
				break;
			}
			case 5:{
				if(col==row){
					mainAndSecondaryCross();
				}
				else{
					printf("Ma tran khong co cheo chinh cheo phu!!!!!\n");
				}
				break;
			}
			case 6:{
				matrixIsprime();
				break;
			}
			case 7:{
				printf("thoat chuong trinh!!!!!!!");
				break;
			}
			default:
				printf("vui long nhap lai (1-7)!!!!!\n");
		}
	}while(choice!=7);
}

void inputMatrix(){//nhap
	printf("Moi nhap vao hang: ");
	scanf("%d",&row);
	printf("Moi nhap vao cot: ");
	scanf("%d",&col);
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("array[%d][%d] = ",i,j);
			scanf("%d",&array[i][j]);
		}
	}
}
void outputMatrix(){//in ma tran
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}
void matrixAngle(){//in 4 goc 
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i==0&&j==0||i==0&&j==col-1||i==row-1&&j==0||i==row-1&&j==col-1){
				printf("%d ",array[i][j]);
			}
			else{
				printf("  ",array[i][j]);
			}
		}
		printf("\n");
	}
}
void matrixBoundary(){//in duong bien
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i==0||j==0||i==row-1||j==col-1){
				printf("%d ",array[i][j]);
			}
			else{
				printf("  ",array[i][j]);
			}
		}
		printf("\n");
	}
}
void mainAndSecondaryCross(){//in cheo chinh cheo phu
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(i==j){
				printf("%d ",array[i][j]);	
			}
			else if(i+j==row-1){
				printf("%d ",array[row-1-j][j]);
			}
			else{
				printf("  ");
			}
		}
		printf("\n");
	}
}
void matrixIsprime(){//in ra so nguyen to
	int flap =1;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			flap=1;
			if(array[i][j]<=1){
				printf("  ",array[i][j]);
				flap=0;
			}
			for(int n=2;n*n<=array[i][j];n++){
				if(array[i][j]%n==0){
					printf("  ",array[i][j]);
					flap=0;
				}
			}
			if(flap==1){
				printf("%d ",array[i][j]);
			}
		}
		printf("\n");
	}
}


