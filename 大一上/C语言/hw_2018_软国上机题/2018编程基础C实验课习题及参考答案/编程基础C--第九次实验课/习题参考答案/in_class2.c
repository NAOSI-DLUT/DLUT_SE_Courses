# include<stdio.h>
# include<stdlib.h>

struct node{
	int num;
	struct node *next;
};

struct node * create_list(int node_num){
	struct node *head, *tail;
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	tail = head;
	for (int i = 0; i < node_num; i++){
		struct node *tmp_node = (struct node *)malloc(sizeof(struct node));
		printf("Ϊ��%d����㸳ֵ:", i + 1);
		scanf("%d", &(tmp_node->num));
		tmp_node->next = NULL;
		tail->next = tmp_node;
		tail = tmp_node;
	}
	return head;
}

void show_list(struct node *L){
	printf("\n�������\n");
	struct node *p = L->next;
	int counter = 0;
	while (p){
		counter++;
		printf("��%d�����ֵ [%d]\n", counter, p->num);
		p = p->next;
	}
	
}

void show_reverse_list(struct node *L, int num_node){
	printf("\n�������\n");
	int *arr = (int *)malloc(num_node * sizeof(int));
	struct node *p = L->next;
	for (int i = num_node - 1; i >= 0; i--){
		arr[i] = p->num;
		p = p->next;
	}
	
	for (int j = 0; j < num_node; j++){
		printf("��%d�����ֵ [%d]\n", j + 1, arr[j]);
	}
}

struct node * insert_new_node2end(struct node *L){
	struct node *added_node = (struct node *)malloc(sizeof(struct node));

	printf("�������¼���ڵ��ֵ:");
	scanf("%d", &added_node->num);
	added_node->next = NULL;

	struct node *p = L;
	while (p->next){
		p = p->next;
	}
	p->next = added_node;

	return L;
}

struct node * delete_node(struct node *L){
	int num_delete;
	printf("������Ҫɾ���Ľ����ֵ:");
	scanf("%d", &num_delete);

	struct node *p, *hp;
	hp = L;

	while (hp && hp->next){
		p = hp->next;
		if (p->num == num_delete){
			hp->next = p->next;
			free(p);
			return L;
		}
		else{
			hp = hp->next;
		}
	}
	printf("δ�ҵ����и���ֵ�Ľ��\n");
}

int main(){
	int num_node;
	printf("����������ڵ����:");
	scanf("%d", &num_node);

	struct node *L = create_list(num_node);
	show_list(L);

	show_reverse_list(L, num_node);
	
	insert_new_node2end(L);
	show_list(L);

	delete_node(L);
	show_list(L);

	system("pause");
}