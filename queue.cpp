#include<stdio.h>
#define SIZE 5
int item[SIZE];
int front=-1; int rear=-1;
int isFull(){
	if((front==rear+1)|| (front==0 && rear==SIZE-1)){
		return 1;	
	}
	else {
		return 0;
	}
}
int isEmpty(){
	if(front==-1){
		return 1;
	}
	else {
		return 0;
	}
}
void enQueue(int element){
	if(isFull()){
		printf("Queue is full \n");
	}
	else{
		if(front==-1)
		front=0;
	
		rear=(rear+1)%SIZE;
		item[rear]=element;
		printf("Inserted:%d ",element);
	}
}
int deQueue(){
	int element;
	if(isEmpty()){
		printf("Queue is Empty \n");
		return(-1);
	}
	else{
		element=item[front];
		if(front==rear){
			front=-1;
			rear=-1;
			
		}
		else{
			front=(front+1)%SIZE;
		}
		printf("Deleted Element :%d \n",element);
		return element;
	}
}
void display(){
	int i;
	if(isEmpty()){
		printf("Empty Queue \n");
	}
	else{
		printf("Front:%d \n",front);
		printf("Items \n");
		for(i=front;i !=rear;i=(i+1)%SIZE){
			printf("%d \n",item[i]);
		}
		printf("%d \n",item[i]);
		printf("Rear:%d \n",rear);
	}
}
int main(){
	deQueue();
	enQueue(1);
	enQueue(2);
	enQueue(3);
	enQueue(4);
	enQueue(5);
	enQueue(6);         // bunu ekleyemeyecek
	display();
	deQueue();
	display();
	enQueue(7);
	display();
	enQueue(8);
}
