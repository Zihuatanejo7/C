#define _CRT_SECURE_NO_WARNINGS 1


// 参考：https://www.cplusplus.com/reference/string/string/
# include <iostream>
using namespace std;
# include <string>

// 几种的string构造函数
// (字符串,int pos,int len)  x:起始位置   y：长度
// (int num,char x) num个x字符
void test01()
{
	string s1;    //构造一个空字符串
	cout << "s1 = " << s1 << endl;

	string s2("i am in tianjin, now");    // 用常量字符串构造s2
	cout << "s2 = " << s2 << endl;

	string s3(s2);                         // 用s2构造s3
	cout << "s3 = " << s3 << endl;

	string s4("i am in tianjin, now", 2, 8);  // 将字符串从第二个字符后8个字符给s4
	cout << "s4 = " << s4 << endl;

	string s5("i am in tianjin, now", 6);    // 将字符串的前6个字符给s5
	cout << "s5 = " << s5 << endl;

	string s6( 6,'a');  //将6个'a'构造s6
	cout << "s6 = " << s6 << endl;

}

// 字符串中的赋值操作   相当于c语言中的memcpy
void test02()
{
	// 可以用等号   运算符重载
	string str1 = "abcdefg";
	cout << "str1 = "<<str1 << endl;

	//string类重的assign成员函数
	string str2;
	str2.assign("qwertyuiop");
	cout << "str2 = "<<str2 << endl;

	string str3;
	str3.assign("qwertyuiop", 2, 3);                   // 起始位置：2  长度：3
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign( 6,'a');                              // 6 个'a'
	cout << "str4 = " << str4 << endl;

}

// 字符串中的连接   相当于c语言中的strcat
void test03()
{
	// += 运算发重载
	string s1("我爱");
	s1 += "玩MAC";
	cout << "s1 = " << s1 << endl;

	string s2;
	s2 += "我喜欢";
	cout << "s2 = " << s2 << endl;


	// string中的append成员函数
	string s3;
	s3.append("我爱打电动");
	cout << "s3 = " << s3<<endl;

	string s4;
	s4.append("i love movie",2,3);
	cout << "s4 = " << s4 << endl;

	string s5;
	s5.append(6,'a');
	cout << "s5 = " << s5 << endl;
}

// 字符串中的查找  和 替换
void test04()
{
	string s1("asdfghjklzxcvbnmwertyuiop");
	int pos = s1.find("jklz");
	cout << "pos = " << pos<< endl;

	string s2("asdfghjklzxcvbnmwertyuiop");
	pos = s2.find("jklz",3);      // 从第三个字符开始往后找
	cout << "pos = " << pos << endl;
	
	string s3("asdfghjklzxcvbnmwertyuiop");
	pos = s3.rfind("op");
	cout << "pos = " << pos << endl;

	string s4("asdfghjklzxcvbnmwertyuiop");
	s4.replace(2, 3, "jjjjj");
	cout << "s4 = " << s4 << endl;

}


// 比较
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


// 字符读取
void test06()
{
	string s1;
	s1 = "sdfghjkl";
	cout << "s1 = " << s1 << endl;

	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] ;    // [] 运算符重载
	}
	cout << endl;

	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1.at(i);    // [] 运算符重载
	}
	cout << endl;
}

// 字符串插入和删除
void test07()
{
	string str1("plmikjgn");
	str1.insert(1,"woqu");
	cout << "str1 = " << str1 <<endl;

	string str2("plmikjgn");
	str2.insert(0, "abcdefg", 2, 3);    // "abcdefg" 中的第2个字符向后的3个字符插入到str2
	cout << "str2 = " << str2 << endl;

	string str3("plmikjgn");
	str3.erase(0, 2);
	cout << "str3 = " << str3 << endl;
}

//子串
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


