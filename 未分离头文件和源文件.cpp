#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int x;
	struct node * next;
	struct node* prior;
}node; 
int len;
node *create(struct node *&first){//创建双向链表
	first = (node*)malloc(sizeof(node));
	int a;
	struct node *p,*q; 
	if(first==NULL){
		printf("内存分配失败\n");
		exit(1); 
	}
	first->next=NULL;
	first->prior=NULL;
	q=first;
	len=0;
	printf("\n请输入链表数据(不要以空格结尾，否则需要多输入一个数据)：\n");
	do{
		scanf("%d",&a);
		p=(node*)malloc(sizeof(node));
		p->x=a;
		p->prior=q;
		q->next=p;
		q=p;	
		len++;	
	}while(getchar()!='\n');
	q->next=NULL;
	return first;
}
void print(struct node *&first){//正向打印 
	printf("打印链表：\n");
	struct node* p;
	p=first->next;
	while(p!=NULL){
		printf("%d  ",p->x);
		p=p->next;
	}
	printf("\n");
}
void find(struct node *&first,int n){// 查找 
	int i;
	struct node* p=first;
	if(n==0||p==NULL||n>len){
		printf("\n无数据\n");
	}else{
	
	for(i=1;i<=n;i++){
		p=p->next;
	}
	n=p->x;
	printf("你想查找的数据为：%d  \n",n);
 }

}
void replace(struct node *&first,int n){//代替 
	struct node *p;
	int i;
	p=first;
	if(n==0||p==NULL||n>len){
		printf("\n代替失败\n");
	} 
	else {
	for(i=1;i<=n;i++){
		p=p->next;
	}
	printf("\n请输入你想要代替的数据：");
	scanf("%d",&(p->x));
   }
}
void insert(struct node *&first,int n){//插入 
	struct node *p,*new1;
	int i;
	p=first;
	new1=(node*)malloc(sizeof(node));
	new1->next=NULL;
	new1->prior=NULL;
	if(n==0||p==NULL||n>len) {
		printf("\n插入失败\n"); 
	}else {
	
	for(i=1;i<=n;i++){
		p=p->next;
	}
	printf("\n请输入新节点的数据：\n");
	scanf("%d",&(new1->x));
	new1->next=p;
	new1->prior=p->prior;
	p->prior->next=new1;
	p->prior=new1;
	len++;
  }
}
void delet(struct node *&first,int n){//删除 
	struct node *p;
	p=first;
	int i;
	if(n==0||p==NULL||n>len) {
		printf("\n删除失败\n"); 
	}else{
	
	for(i=1;i<=n;i++){
		p=p->next;
	}
	p->prior->next=p->next;
	p->next->prior=p->prior;
	len--;
  }
}
void sort(struct node *&first,int n){//排序 
	int i,j,t;
	int count=n;
	struct node *min,*max,*p;
	p=first;
	p=p->next;
	for(i=1;i<count;i++){
		if(i%2!=0){
			min=p;
			for(j=0;j<n-1;j++){
				p=p->next;
				if(p->x<min->x){
					t=min->x;
					min->x=p->x;
					p->x=t;
				}
			}n--;
		}
		else{
			max=p;
			for(j=0;j<n-1;j++){
				p=p->prior;
				if(p->x>max->x){
					t=max->x;
					max->x=p->x;
					p->x=t;
				}
			}n--;
		}
	}
	
}

int main (){
	
	//创建以及打印链表 
	char ch; 
	int n;
	struct node* first;
	create(first);
	print(first);
	printf("\n链表长度为：%d",len);
	printf("\n可执行操作：A(查找数据)，B（替换数据），C(插入数据)，D(删除数据),E(排序),N(结束)，输入相应大写字母执行操作\n");
	printf("请输入指令 ");
	while(1){
	//查找以及打印 
	scanf("%c",&ch);
	if(ch == 'A')  {
	printf("\n输入你想查找的数据的序号：");
	scanf("%d",&n);
	find(first,n) ;
	printf("请输入指令 ");
    }

    
	//代替以及打印 
	if(ch == 'B'){
	
	printf("\n请输入你想要代替第几个数据:");
	scanf("%d",&n);
	replace(first,n);
	print(first);
	printf("请输入指令 ");
    }

    
	//插入以及打印
	if(ch == 'C'){
	printf("\n请输入第i号数据，我将在它之前插入一个新数据：");
	scanf("%d",&n);
	insert(first,n);
	print(first);
	printf("\n链表长度为：%d\n",len);
	printf("请输入指令 ");
    }


	//删除以及打印

	if(ch == 'D'){
	printf("\n请输入要删除的第i号数据：");
	scanf("%d",&n);
	delet(first,n);
	print(first);
	printf("\n链表长度为：%d\n",len);
	printf("请输入指令 ");
    }

	//排序以及打印
	if(ch == 'E'){
	sort(first,len);
	print(first) ;
	printf("请输入指令 ");
    }
    
    //结束 
    if(ch == 'N'){ 
	break;
	}
  }
	return 0;

}



