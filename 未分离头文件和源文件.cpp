#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int x;
	struct node * next;
	struct node* prior;
}node; 
int len;
node *create(struct node *&first){//����˫������
	first = (node*)malloc(sizeof(node));
	int a;
	struct node *p,*q; 
	if(first==NULL){
		printf("�ڴ����ʧ��\n");
		exit(1); 
	}
	first->next=NULL;
	first->prior=NULL;
	q=first;
	len=0;
	printf("\n��������������(��Ҫ�Կո��β��������Ҫ������һ������)��\n");
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
void print(struct node *&first){//�����ӡ 
	printf("��ӡ����\n");
	struct node* p;
	p=first->next;
	while(p!=NULL){
		printf("%d  ",p->x);
		p=p->next;
	}
	printf("\n");
}
void find(struct node *&first,int n){// ���� 
	int i;
	struct node* p=first;
	if(n==0||p==NULL||n>len){
		printf("\n������\n");
	}else{
	
	for(i=1;i<=n;i++){
		p=p->next;
	}
	n=p->x;
	printf("������ҵ�����Ϊ��%d  \n",n);
 }

}
void replace(struct node *&first,int n){//���� 
	struct node *p;
	int i;
	p=first;
	if(n==0||p==NULL||n>len){
		printf("\n����ʧ��\n");
	} 
	else {
	for(i=1;i<=n;i++){
		p=p->next;
	}
	printf("\n����������Ҫ��������ݣ�");
	scanf("%d",&(p->x));
   }
}
void insert(struct node *&first,int n){//���� 
	struct node *p,*new1;
	int i;
	p=first;
	new1=(node*)malloc(sizeof(node));
	new1->next=NULL;
	new1->prior=NULL;
	if(n==0||p==NULL||n>len) {
		printf("\n����ʧ��\n"); 
	}else {
	
	for(i=1;i<=n;i++){
		p=p->next;
	}
	printf("\n�������½ڵ�����ݣ�\n");
	scanf("%d",&(new1->x));
	new1->next=p;
	new1->prior=p->prior;
	p->prior->next=new1;
	p->prior=new1;
	len++;
  }
}
void delet(struct node *&first,int n){//ɾ�� 
	struct node *p;
	p=first;
	int i;
	if(n==0||p==NULL||n>len) {
		printf("\nɾ��ʧ��\n"); 
	}else{
	
	for(i=1;i<=n;i++){
		p=p->next;
	}
	p->prior->next=p->next;
	p->next->prior=p->prior;
	len--;
  }
}
void sort(struct node *&first,int n){//���� 
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
	
	//�����Լ���ӡ���� 
	char ch; 
	int n;
	struct node* first;
	create(first);
	print(first);
	printf("\n������Ϊ��%d",len);
	printf("\n��ִ�в�����A(��������)��B���滻���ݣ���C(��������)��D(ɾ������),E(����),N(����)��������Ӧ��д��ĸִ�в���\n");
	printf("������ָ�� ");
	while(1){
	//�����Լ���ӡ 
	scanf("%c",&ch);
	if(ch == 'A')  {
	printf("\n����������ҵ����ݵ���ţ�");
	scanf("%d",&n);
	find(first,n) ;
	printf("������ָ�� ");
    }

    
	//�����Լ���ӡ 
	if(ch == 'B'){
	
	printf("\n����������Ҫ����ڼ�������:");
	scanf("%d",&n);
	replace(first,n);
	print(first);
	printf("������ָ�� ");
    }

    
	//�����Լ���ӡ
	if(ch == 'C'){
	printf("\n�������i�����ݣ��ҽ�����֮ǰ����һ�������ݣ�");
	scanf("%d",&n);
	insert(first,n);
	print(first);
	printf("\n������Ϊ��%d\n",len);
	printf("������ָ�� ");
    }


	//ɾ���Լ���ӡ

	if(ch == 'D'){
	printf("\n������Ҫɾ���ĵ�i�����ݣ�");
	scanf("%d",&n);
	delet(first,n);
	print(first);
	printf("\n������Ϊ��%d\n",len);
	printf("������ָ�� ");
    }

	//�����Լ���ӡ
	if(ch == 'E'){
	sort(first,len);
	print(first) ;
	printf("������ָ�� ");
    }
    
    //���� 
    if(ch == 'N'){ 
	break;
	}
  }
	return 0;

}



