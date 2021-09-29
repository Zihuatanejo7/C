#define _CRT_SECURE_NO_WARNINGS 1


// �ο���https://www.cplusplus.com/reference/string/string/
# include <iostream>
using namespace std;
# include <string>

// ���ֵ�string���캯��
// (�ַ���,int pos,int len)  x:��ʼλ��   y������
// (int num,char x) num��x�ַ�
void test01()
{
	string s1;    //����һ�����ַ���
	cout << "s1 = " << s1 << endl;

	string s2("i am in tianjin, now");    // �ó����ַ�������s2
	cout << "s2 = " << s2 << endl;

	string s3(s2);                         // ��s2����s3
	cout << "s3 = " << s3 << endl;

	string s4("i am in tianjin, now", 2, 8);  // ���ַ����ӵڶ����ַ���8���ַ���s4
	cout << "s4 = " << s4 << endl;

	string s5("i am in tianjin, now", 6);    // ���ַ�����ǰ6���ַ���s5
	cout << "s5 = " << s5 << endl;

	string s6( 6,'a');  //��6��'a'����s6
	cout << "s6 = " << s6 << endl;

}

// �ַ����еĸ�ֵ����   �൱��c�����е�memcpy
void test02()
{
	// �����õȺ�   ���������
	string str1 = "abcdefg";
	cout << "str1 = "<<str1 << endl;

	//string���ص�assign��Ա����
	string str2;
	str2.assign("qwertyuiop");
	cout << "str2 = "<<str2 << endl;

	string str3;
	str3.assign("qwertyuiop", 2, 3);                   // ��ʼλ�ã�2  ���ȣ�3
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign( 6,'a');                              // 6 ��'a'
	cout << "str4 = " << str4 << endl;

}

// �ַ����е�����   �൱��c�����е�strcat
void test03()
{
	// += ���㷢����
	string s1("�Ұ�");
	s1 += "��MAC";
	cout << "s1 = " << s1 << endl;

	string s2;
	s2 += "��ϲ��";
	cout << "s2 = " << s2 << endl;


	// string�е�append��Ա����
	string s3;
	s3.append("�Ұ���綯");
	cout << "s3 = " << s3<<endl;

	string s4;
	s4.append("i love movie",2,3);
	cout << "s4 = " << s4 << endl;

	string s5;
	s5.append(6,'a');
	cout << "s5 = " << s5 << endl;
}

// �ַ����еĲ���  �� �滻
void test04()
{
	string s1("asdfghjklzxcvbnmwertyuiop");
	int pos = s1.find("jklz");
	cout << "pos = " << pos<< endl;

	string s2("asdfghjklzxcvbnmwertyuiop");
	pos = s2.find("jklz",3);      // �ӵ������ַ���ʼ������
	cout << "pos = " << pos << endl;
	
	string s3("asdfghjklzxcvbnmwertyuiop");
	pos = s3.rfind("op");
	cout << "pos = " << pos << endl;

	string s4("asdfghjklzxcvbnmwertyuiop");
	s4.replace(2, 3, "jjjjj");
	cout << "s4 = " << s4 << endl;

}


// �Ƚ�
void test05()
{
	string str1("abcdefhjkg");
	string str2("abcdefhjkg");
	int ret = str1.compare(str2);
	if (!ret)
	{
		cout << "str1 = str2" << endl;
	}

	str1[0] = 'b';
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	ret = str1.compare(str2);
	if (ret > 0)
	{
		cout << "str1 > str2" << endl;
	}
	else if (ret < 0)
	{
		cout << "str1 < str2" << endl;
	}
	else
	{
		cout << "str1 = str2" << endl;
	}

}


// �ַ���ȡ
void test06()
{
	string s1;
	s1 = "sdfghjkl";
	cout << "s1 = " << s1 << endl;

	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] ;    // [] ���������
	}
	cout << endl;

	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1.at(i);    // [] ���������
	}
	cout << endl;
}

// �ַ��������ɾ��
void test07()
{
	string str1("plmikjgn");
	str1.insert(1,"woqu");
	cout << "str1 = " << str1 <<endl;

	string str2("plmikjgn");
	str2.insert(0, "abcdefg", 2, 3);    // "abcdefg" �еĵ�2���ַ�����3���ַ����뵽str2
	cout << "str2 = " << str2 << endl;

	string str3("plmikjgn");
	str3.erase(0, 2);
	cout << "str3 = " << str3 << endl;
}

//�Ӵ�
void test08()
{
	string s1("lixiaoyuyu");
	string s2 = s1.substr(2, 5);
	cout << "s1 = " << s1 <<endl;
	cout << "s2 = " << s2 << endl;

	string s3("zhaozhiyang1997@gmail.com");
	int pos = s3.find('@');
	cout << "pos = " << pos << endl;

	string s4 = s3.substr(0, pos);
	cout << "s4 = " << s4 << endl;
}


int main()
{
	
	//test01();
	
	//test02();

	//test03();

	//test04();

	//test05();

	//test06();

	//test07();

	test08();
	system("pause");
	return 0;
}


