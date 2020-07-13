#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
class Person {
public:
	Person() {};
	Person(char name1[], int age1);
	void show();
protected:
	char name[20];
	int age;
};
Person::Person(char name1[], int age1)
{
	strcpy(name, name1);
	age = age1;
}
void Person::show()
{
	cout << name << ':' << age << endl;
}
class Student :public Person {
public:
	Student(char name1[], int age1, string ID1, int N) :Person(name1, age1)
	{
		ID = ID1;
		n = N;
	}
	void show();
	void inputScore();
protected:
	string ID;
	int n;
	int score[20];
};
void Student::show()
{
	cout << name << ':' << age;
	cout << '    ' << ID << endl;
}
void Student::inputScore()
{
	for (int i = 0; i < n; i++)
	{
		cin >> score[i];
	}
}
int main(int argc, char** argv)
{
	Person* p1;
	Person zhangsan("zhangsan", 18 ); //Person���������Ϊzhangsan������Ϊ18
	p1 = &zhangsan;
	p1->show();//չʾzhangsan������������
	Student* p2;
	p2 = new Student("lisi", 19, "20190001", 2); // Student���������Ϊlisi������Ϊ19��ѧ��Ϊ20190001���ܹ��������ɼ�
	((Student*)p2)->inputScore();//����Student����������ɼ��ķ���
	p2->show();//չʾStudent����������������ѧ��
	delete p2;
	return 0;
}

