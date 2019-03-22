#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int isEquivalent(char* str1,int s1 ,char* str2,int s2,int count) {
	int flag = 0;
	
	int str1len = 0;
	int str2len = 0;
	if (str1 == NULL || str2 == NULL) {
		printf("str1 or str2 is NULL");
		return 0;
	}

	//�ж������ַ����Ƿ����
	if (strncmp(str1+s1, str2+s2,count) == 0) {     //O(count)
		flag = 1;
		return flag;
	}

	//�ж��Ƿ��ܹ��ֳ���ȵ�������
	if (count % 2 == 1) {
		flag = 0;
		return flag;
	}

	int flagA1_B1 = isEquivalent(str1, s1, str2, s2, count / 2);
	int flagA1_B2 = isEquivalent(str1, s1, str2, s2 + count / 2, count / 2);
	if (flagA1_B1 && flagA1_B2) {
		return isEquivalent(str1,s1,str1,s1+count/2,count/2);
	}
	else if (flagA1_B1) {
		return isEquivalent(str1, s1 + count / 2, str2, s2 + count / 2, count / 2);
	}
	else if (flagA1_B2) {
		return isEquivalent(str1, s1 + count / 2, str2, s2, count / 2);
	}
	else {
		return 0;
	}
	
}


//05
int main05() {

	char* str1 = "abcdefghzhanghao";
	char* str2 = "abcdefghnazhhgoa";
	if (strlen(str1) != strlen(str2)) {
		printf("�ַ������Ȳ���ȣ�һ�����ȼ�\n");
		system("pause");
		return 0;
	}
	int flag = isEquivalent(str1, 0, str2, 0, strlen(str1));
	if (flag == 1) {
		printf("%s��%s�ȼ�",str1, str2);
	}
	else {
		printf("%s��%s���ȼ�", str1, str2);
	}
	printf("\n-----------------------------------------\n");
	system("pause");
	return 0;
}
