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
		printf("请输入第%d个员工的ID:", i + 1);
		scanf("%d", &staff_array[i].id);
		printf("请输入第%d个员工的姓名:", i + 1);
		scanf("%s", &staff_array[i].name);
		printf("请输入第%d个员工的生日（年,月,日）:", i + 1);
		scanf("%d,%d,%d", &staff_array[i].birth.year, &staff_array[i].birth.month, &staff_array[i].birth.day);
		printf("请输入第%d个员工的工资:", i + 1);
		scanf("%f", &staff_array[i].sallary);
	}

	return staff_array;
}

void show_staff_information(struct staff *sta, int num){
	for (int i = 0; i < num; i++){
		printf("第%d位员工信息:\n", i+1);
		printf("员工ID : %d\t", sta[i].id);
		printf("员工姓名 : %s\t", sta[i].name);
		printf("员工生日 : [%d,%d,%d]\t", sta[i].birth.year, sta[i].birth.month, sta[i].birth.day);
		printf("员工工资 : %.2f\n", sta[i].sallary);
	}
}

int main(){
	int num_staff;
	printf("请输入员工数量:");
	scanf("%d", &num_staff);

	printf("\n原始顺序\n");
	struct staff *sta_arr = NULL;
	sta_arr = input_information(num_staff);
	show_staff_information(sta_arr, num_staff);
	
	printf("\n升序排序\n");
	struct staff *sorted_sta_arr = NULL;
	sorted_sta_arr = sort(sta_arr, num_staff);
	show_staff_information(sorted_sta_arr, num_staff);

	system("pause");

}