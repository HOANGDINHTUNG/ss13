#include<stdio.h>
#define MAX 100
int array[MAX][MAX];
int row,col;
void matrixExport();
void matrixImport();
int main(){
	matrixExport();
	matrixImport();
}
void matrixExport(){
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
void matrixImport(){
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}
