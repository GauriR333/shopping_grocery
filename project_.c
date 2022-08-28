#include<stdio.h>
#include<string.h>
#include<stdlib.h >
typedef struct customer{
	char name[10];
	int Ph_no;
	char Address[10];
}customer;

typedef struct item{
	char Item [100];
	int GST;
	int MRP;
	int QTY;
}item;

void show_menu();
void get_item_info(item*);
void get_customer_info(customer*);
float item_calculation(item);
void modify_customer_detil();
void display_bill(customer,item*);

item items[100];
customer cust;
int item_counter=0;

void main(){
	show_menu();
}
	
void get_customer_info( customer *cust){
	
	printf("\tEnter the Customer Details\n\tName : ");
	scanf("%s",&cust->name);
		
	printf("\tPhone NO.  : ");
	scanf("%d",&cust->Ph_no);
		
	printf("\tAddress  : ");
	scanf("%s",&cust->Address);
	}
	
void display_bill(customer cust,item* items){
	
	printf("\n\t----------------------------------------------------------------");
	printf("\n\t####################customer Detail#############################");
	printf("\n\n\n");
	printf("\tName : %s",cust.name);
	printf("\tPh_No  : %d",cust.Ph_no);
	printf("\tAddress : %s",cust.Address);
	printf("\n\t-----------------------------------------------------------------");
	printf("\n\n\n\t-----------------------------------------------------------------");
	printf("\n\n\n\t********************Your chart Bill********************\n");
	printf("\n\tName\tMRP\tGST\tQTY\tGST Amount\tTotal Amount");
	printf("\n\t-----------------------------------------------------------------");
	int i;
	float all_item_total=0;
	for(i=0;i<item_counter;i++){
  			printf("\n\t%s",items[i].Item);
			printf("\t%d",items[i].MRP);
			printf("\t%d",items[i].GST);
			printf("\t%d",items[i].QTY);
			float gst_amount =item_calculation(items[i]);
			printf("\t%f",gst_amount);
			float item_total=(items[i].MRP*items[i].QTY+gst_amount);
			printf("\t%f",item_total);
			all_item_total=all_item_total+item_total;	
		}
		printf("\n\t-----------------------------------------------------------------");
		printf("\n\t\t\t\t\tFinal Bill :\t%f",all_item_total);
		printf("\n\t-----------------------------------------------------------------\n\n\n\n\n");
}

void get_item_info(item* items){
	char choice [1];
	printf("\n\tEnter Items ");
	do{
		int i=item_counter++;
		
		printf("\n\tName : ");
		scanf("%s",&items[i].Item);
		
		printf("\tMRP : ");
		scanf("%d",&items[i].MRP);
		
		printf("\tGST %  : ");
		scanf("%d",&items[i].GST);
				
		printf("\tQuntity : ");
		scanf("%d",&items[i].QTY);
		
		printf("\n Do you want to add more items ? (y/n) : ");
		scanf("%s",&choice);
	}while(strcmp(choice,"y")==0);
}

float item_calculation(item item){
	float gst=((item.MRP*item.GST)/100)*item.QTY;
	return gst;		
}
void show_menu(){
	
	printf("\n\t*************************WEL-COME TO SHOPE*************************\n");
		
	while(1){
	
	int choice;
	printf("\n\t 1. Enter customer information " );
	printf("\n\t 2. Add to cart ");
	printf("\n\t 3. Modify cart ");
	printf("\n\t 4. Modify customer detil  ");
	printf("\n\t 5. Show bill ");	
	printf("\n\t 6. Exit ");
	printf("\n\t Enter choice : ");
	scanf("%d",&choice);
	
		switch(choice){
			
			case 1:
				get_customer_info(&cust);
				
			break;		
			
			case 2:
				
			 	get_item_info(items);
			 	
			break;
		
			case 3:
			
			break;
		
			case 4:
			modify_customer_detil();
			
			break;
			
			case 5:
				display_bill(cust,items);
	
			break;
		
			case 6:
			exit(0);
	//	break;
		 
			default:
			printf("\n\tPlease enter correct choice !");
				
		}
	} 
	
}

void modify_customer_detil(){
	
		int choice,i;
		//int true;
		choice=i;
	
	for(i=0;i<=4;i++){
	
		printf("\n\t----\t Here you change information  ----\n");
		printf("\n\t 1. Chang Name ");
		printf("\n\t 2. Change phone no. ");
		printf("\n\t 3. Change Addrees ");
		printf("\n\t 4. Chages Done ");
		printf("\n\t Enter choice : ");
		scanf("%d",&choice);
			
		//	if(choice==true){
			
					switch(choice){
				
					case 1:
					printf("\n\tName : ");
					scanf("\n\t%s",&cust.name);
					break;
					
					case 2:
					printf("\n\tPhone no. : ");
					scanf("\n\t%d",&cust.Ph_no);
					break;
				
					case 3:
					printf("\n\tAddress : ");
					scanf("\n\t%s",&cust.Address);
					break;
				
					case 4:
					break;
	
					//default:
					//printf("Please enter your choice ?");	
					}
		//}else;
			
	}
}

	
	
	
	
