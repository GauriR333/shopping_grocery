#include<stdio.h>
#include<string.h>
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

void get_item_info(item*);
void get_customer_info(customer*);
float item_calculation(item);
void display_bill(customer,item*);

void main(){
	customer cust;
	get_customer_info(&cust);
	item items[100];
    get_item_info(items);
	display_bill(cust,items);
}
	
void get_customer_info( customer *cust){
	
	printf("Enter the Customer Details\n\tName : ");
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
	printf("\n\tName\tMRP\tGST\tQTY\tGST Amount\tTotal Amount");
	printf("\n\t-----------------------------------------------------------------");
	int i;
	float all_item_total=0;
	for(i=0;i<2;i++){
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
	int i;
	int b=2;
	printf("\n\tEnter Items ");
	for(i=0;i<b;i++){
		printf("\n\tName : ");
		scanf("%s",&items[i].Item);
		
		printf("\tMRP : ");
		scanf("%d",&items[i].MRP);
		
		printf("\tGST %  : ");
		scanf("%d",&items[i].GST);
				
		printf("\tQuntity : ");
		scanf("%d",&items[i].QTY);
		
		printf("\n");
	}
}

float item_calculation(item item){
	float gst=((item.MRP*item.GST)/100)*item.QTY;
	return gst;		
}




	
	
	
	
