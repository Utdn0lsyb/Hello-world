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
	Person zhangsan("zhangsan", 18 ); //Person对象的姓名为zhangsan，年龄为18
	p1 = &zhangsan;
	p1->show();//展示zhangsan的姓名和年龄
	Student* p2;
	p2 = new Student("lisi", 19, "20190001", 2); // Student对象的姓名为lisi，年龄为19，学号为20190001，总共有两个成绩
	((Student*)p2)->inputScore();//输入Student对象的两个成绩的分数
	p2->show();//展示Student对象的姓名、年龄和学号
	delete p2;
	return 0;
}

