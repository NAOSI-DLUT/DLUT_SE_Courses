# include<stdio.h>
# include<stdlib.h>

struct birthday {
	int year;
	int month;
	int day;
};

struct staff{
	int id;
	char name[100];
	struct birthday birth;
	float sallary;
};

struct staff * sort(struct staff *sta, int num){
	for (int i = 0; i < num - 1; i++){
		for (int j = 0; j < num - 1 - i; j++){
			if (sta[j].sallary > sta[j + 1].sallary){
				struct staff tmp;
				tmp = sta[j];
				sta[j] = sta[j + 1];
				sta[j + 1] = tmp;
			}
		}
	}
	return sta;
}

struct staff * input_information(int num){
	struct staff *staff_array = NULL;
	staff_array = (struct staff *)malloc(sizeof(struct staff) * num);

	for (int i = 0; i < num; i++){
		printf("�������%d��Ա����ID:", i + 1);
		scanf("%d", &staff_array[i].id);
		printf("�������%d��Ա��������:", i + 1);
		scanf("%s", &staff_array[i].name);
		printf("�������%d��Ա�������գ���,��,�գ�:", i + 1);
		scanf("%d,%d,%d", &staff_array[i].birth.year, &staff_array[i].birth.month, &staff_array[i].birth.day);
		printf("�������%d��Ա���Ĺ���:", i + 1);
		scanf("%f", &staff_array[i].sallary);
	}

	return staff_array;
}

void show_staff_information(struct staff *sta, int num){
	for (int i = 0; i < num; i++){
		printf("��%dλԱ����Ϣ:\n", i+1);
		printf("Ա��ID : %d\t", sta[i].id);
		printf("Ա������ : %s\t", sta[i].name);
		printf("Ա������ : [%d,%d,%d]\t", sta[i].birth.year, sta[i].birth.month, sta[i].birth.day);
		printf("Ա������ : %.2f\n", sta[i].sallary);
	}
}

int main(){
	int num_staff;
	printf("������Ա������:");
	scanf("%d", &num_staff);

	printf("\nԭʼ˳��\n");
	struct staff *sta_arr = NULL;
	sta_arr = input_information(num_staff);
	show_staff_information(sta_arr, num_staff);
	
	printf("\n��������\n");
	struct staff *sorted_sta_arr = NULL;
	sorted_sta_arr = sort(sta_arr, num_staff);
	show_staff_information(sorted_sta_arr, num_staff);

	system("pause");

}