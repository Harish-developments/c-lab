#include<stdio.h>

typedef struct{
	int accno;
	char name[25];
	int bal;
}student;

void main(){
	int i,n,minbal,opt;
	int count = 0;
	FILE *fp;
	printf("Enter how many Records : \n");
	scanf("%d",&n);
	student s[n];
	fp = fopen("account.dat","W");
	for(i=0;i<n;i++){
		printf("Reade the information of account holder : \n");
		scanf("%d%s%d",&s[i].accno,s[i].name,&s[i].bal);
		fwrite(&s,sizeof(s),1,fp);
	}
	fclose(fp);
	fp=fopen("Account.dat","r");
	do{
		printf("\n1-Display\n2-Search\n3-Exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nAccount record in the file\n\n");
				rewind(fp);
				for(i=0;i<n;i++){
					printf("%d\t%s\t%d\n",s[i].accno,s[i].name,s[i].bal);
				}
				
				break;
			case 2:
				printf("Read minimum balance of the customer to be searched ?");
				scanf("%d",&minbal);
				for(i = 0;i<n;i++){
					if(s[i].bal<=minbal){
						count++;
					}
				}
				
				printf("The minimum balance account = %d\n",count);
				break;
			case 3:
				printf("Exit!!!press a key...\n");
				getch();
				break;
			default:
				printf("Invalid output\n");
				}
		}while(opt!=3);
		fclose(fp);
	}
