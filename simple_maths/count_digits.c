#include<stdio.h>
//#include<malloc.h>
#include<stdlib.h>

struct digits{
int num;
struct digits * next;

};

int main()
{

	int t, number, i, digit;
	scanf("%d",&t);
	for(i = 0; i < t; i++)
	{
		scanf("%d", &number);
		struct digits * head;
		struct digits * newNode;	
		struct digits * nextNode;	
		if(number == 0){
			newNode = (struct digits *)malloc(sizeof(struct digits));
			newNode->next = NULL;
			newNode->num = 0;
			head=newNode;			
		}	
		else{
			int count = 0;
			while(number > 0)
			{
					
				newNode = (struct digits *)malloc(sizeof(struct digits));
				newNode->num = number%10;
				newNode->next = NULL;
				number = number/10;
				if(count==0){
					head = newNode;
					count++;
					nextNode = newNode;
				}
				else{
					nextNode->next = newNode;
					nextNode = nextNode->next;
					count++;
				}
					
			}
			
		}
		struct digits * pointer = head;
		while(pointer != NULL){
			printf("%d\t", pointer->num);
			pointer = pointer->next;
		}
		printf("\n");
	}
return 0;
}
