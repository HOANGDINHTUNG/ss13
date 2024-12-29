#include<stdio.h>
#define MAX 100
int array[MAX];
int n;
void inputArray();
void outputArray();
void addIndex();
void editIndex();
void deleteIndex();
void decreaseArray();
void increaseArray();
int linearSearch(int x);
int binarySearch(int x);
int main(){
	int choice;
	do{
		printf("==================MENU=================\n");
		printf("1.Nhap so phan tu can nhap va gia tri cac phan tu\n");
		printf("2.In ra cac gia tri phan tu dang quan ly\n");
		printf("3.Them mot phan tu vao vi tri chi dinh\n");
		printf("4.Sua mot phan tu o vi tri chi dinh\n");
		printf("5.Xoa mot phan tu o vi tri chi dinh\n");
		printf("6.Xap xep cac phan tu\n");
		printf("7.Tim kiem phan tu nhap vao\n");
		printf("8.Thoat\n");
		printf("Moi nhap vao chuc nang: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:{
				inputArray();
				break;
			}
			case 2:{
				outputArray();
				break;
			}
			case 3:{
				addIndex();
				break;
			}
			case 4:{
				editIndex();
				break;
			}
			case 5:{
				deleteIndex();
				break;
			}
			case 6:{
				int num;
				printf("6.1/Giam dan\n");
				printf("6.2/Tang dan\n");
				printf("moi nhap su lua chon (1 hoac 2): ");
				scanf("%d",&num);
				if(num==1){
					decreaseArray();
					printf("Da sap xep!!!\n");
				}
				else if(num==2){
					increaseArray();
					printf("Da sap xep!!!\n");
				}
				else{
					printf("Lua chon khong ton tai!!!\n");
				}
				break;
			}
			case 7:{
				int num;
				printf("7.1/Tim kiem tuyen tinh\n");
				printf("7.2/Tim kiem nhi phan\n");
				printf("Moi nhap su lua chon(1 hoac 2): ");
				scanf("%d",&num);
				if(num==1){
					int x;
					printf("Moi nhap so can tim: ");
					scanf("%d",&x);
					if(linearSearch(x)!=-1){
						printf("So %d nam o vi tri thu %d trong mang!!!\n",x,linearSearch(x));
					}
					else{
						printf("So %d khong ton tai trong mang!!!!\n",x);
					}
				}
				else if(num==2){
					int x;
					printf("Moi nhap so can tim: ");
					scanf("%d",&x);
					if(linearSearch(x)!=-1){
						printf("So %d nam o vi tri thu %d trong mang!!!\n",x,binarySearch(x));
					}
					else{
						printf("So %d khong ton tai trong mang!!!!\n",x);
					}
				}
				else{
					printf("Lua chon khong ton tai!!!\n");
				}
				break;
			}
			case 8:{
				printf("chuong trinh ket thuc!!!!!\n");
				break;
			}
			default:
				printf("vui long nhap lai (1-8)!!!!\n");
				break;
		}
	}while(choice!=8);
}
void inputArray(){//nhap
	printf("Moi nhap vao so phan tu : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("array[%d] = ",i);
		scanf("%d",&array[i]);
	}
}
void outputArray(){//xuat
	for(int i=0;i<n;i++){
		printf("array[%d] = %d\n",i,array[i]);
	}
}
void addIndex(){//them phan tu
	if(n==MAX){
		printf("mang da day khong the them vao !!!!\n");
	}
	int index,value;
	printf("moi nhap vao vi tri can them : ");
	scanf("%d",&index);
	printf("moi nhap vao gia tri cho phan tu moi them : ");
	scanf("%d",&value);
	if(index<0){
		index=0;
	}
	else if(index>=n){
		index=n;
	}
	for(int i=n-1;i>=index;i--){
		array[i+1]=array[i];
	}
	array[index]=value;
	++n;
}
void editIndex(){//sua phan tu
	int edit,newValue;
	printf("moi nhap vao vi tri can sua: ");
	scanf("%d",&edit);
	if(edit<0||edit>=n){
		printf("Vi tri sua khong ton tai trong mang!!!\n");
	}
	else{
		printf("moi nhap vao gia tri moi (gia tri cu la %d): ",array[edit]);
		scanf("%d",&newValue);
		array[edit]=newValue;
	}
}
void deleteIndex(){//xoa phan tu
	int erase;
	printf("moi nhap vao vi tri can xoa: ");
	scanf("%d",&erase);
	if(erase<0||erase>=n){
		printf("Vi tri xoa khong ton tai trong mang!!!\n");
	}
	else{
		for(int i=erase;i<=n-1;++i){
			array[i]=array[i+1];
		}
		--n;
	}
}
void decreaseArray(){//giam dan
	for(int i=0;i<n;i++){
		int key=array[i];
		int j=i-1;
		while(j>=0&&array[j]<key){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=key;
	}
}
void increaseArray(){//tang dan
	for(int i=0;i<n;i++){
		int min=array[i];
		for(int j=i+1;j<n;j++){
			if(array[j]<min){
				min=array[j];
				array[j]=array[i];
				array[i]=min;
			}
		}
	}
}
int linearSearch(int x){//tim kiem tuyen tinh
	for(int i=0;i<n;i++){
		if(array[i]==x)
		return i;
	}
	return -1;
}
int binarySearch(int x){//tim kiem nhi phan
	//sap xep
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(array[j]>array[j+1]){
				int temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	//tim kiem
	int left=0;
	int right=n-1;
	while(left<=right){
		int mid=(left+right)/2;
		if(array[mid]==x){
			return mid;
		}
		else if(array[mid]<x){
			left=mid+1;
		} 
		else{
			right=mid-1;
		}
	}
	return -1;
}
