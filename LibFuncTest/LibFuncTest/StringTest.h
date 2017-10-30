#ifndef __STRING_TEST_H__
#define __STRING_TEST_H__
#include <string>
#include<iostream>
/*
由于本人对字符串操作一般都使用CString 导致对string不是很熟，今天我就把string所有用法自己用代码敲一篇，已达到孰能生巧
*/

/*
一、string 函数的详细使用:
1.声明一个字符串

① string s;                定义一个空的字符串
② string s(str);           拷贝构造,定义一个str的复制品
③ string s(str,idx)        将str字符串idx后部分当做s的初始值
④ string s(cstr)           将c字符串当做s的初始值
⑤ string s(cstr,len)       将c字符串前len个字符当做初始值
⑥ string s(num,c)          生成一个包含num个c的字符串
⑦ string s(str,spos,count) 将str字符串起始位置(spos)拷贝count个数据到s作为初始值

*/

void DefineStringInit()
{
	std::string str1 = "hello world str1";
	std::string str2 = "i am str2";
	char cstr[10] = { 1, 2, 3, 4, 5, 'a', 'b', 'c', 'd', 'e' };

	std::string s;             //①
	std::string s1(str1);      //② s1 = "hello world str1"
	std::string s2(str1,12);   //③ s2 = "str1"
	std::string s3(str2, 1);   //③ s3 = " am str2"
	std::string s4(cstr);      //④ s4 = "\x1\x2\x3\x4\x5abcde"
	std::string s5(cstr, 8);   //⑤ s5 = "\x1\x2\x3\x4\x5abc"
	std::string s6(8, 'a');    //⑥ s6 = "aaaaaaaa"
	std::string s7(str1, 3, 5);//⑦ s7 = "lo wo"
}

/*
二、string 字符串操作函数

① insert()						插入字符
② replace()					替换字符
③ size(),length()				返回字符数量
④ empty()						判断字符串是否为空
⑤ erase()						删除字符
⑥ clear()                      删除全部字符
⑦ ==,!=,<,<=,>,>=,compare()    比较字符串
⑧=,assign()                    赋以新值
⑨swap()                        交换两个字符串的内容
⑩+=,append(),push_back()       在尾部添加字符
⑪[ ], at()                     存取单一字符
⑫c_str()                       将内容以C_string返回
⑬substr()                      返回某个子字符串
⑭copy()                        将某值赋值为一个C_string
⑮data()                        将内容以字符数组形式返回
⑯find                          查找函数            


*/
//you are beauty, but i am more handsome!
void InsertTest()
{
	//insert 
	//s.insert(pos,str)				在s的pos位置插入str	
	//s.insert(pos,str,a,n)			在s的pos位置插入str中插入位置a到后面的n个字符
	//s.insert(pos,cstr,n)			在pos位置插入cstr字符串从开始到后面的n个字符
	//s.insert(pos,cstr)			在s的pos位置插入cstr
	//s.insert(pos,n,ch)			在s.pos位置上面插入n个ch
	//s.insert(s.it,ch)				在s的it指向位置前面插入一个字符ch，返回新插入的位置的迭代器
	//s.insert(s.it,n,ch)			在s的it所指向位置的前面插入n个ch
	//s.insert(it,str.ita,str.itb)	在it所指向的位置的前面插入[ita,itb)的字符串
	std::string str = "you are ";
	std::string str2 = "beauty";
	std::string str3 = "not ";
	std::string str4 = ", but i am more handsome!";
	std::string str5 = "ha ha ";
	std::string::iterator it;
	str.insert(8, str2);                      //you are beauty
	str.insert(8, str3, 0, 4);                //you are not beauty
	str.insert(18, " but i am beauty", 9);    //you are not beauty but i am 
	str.insert(27, " more handsome!");        //you are not beauty but i am more handsome!
	str.insert(18, 1, ',');                   //you are not beauty, but i am more handsome!
	it = str.insert(str.begin() + 18, '~');   //you are not beauty~, but i am more handsome!
	str.insert(str.end(), 3, '.');            //you are not beauty~, but i am more handsome!...
	str.insert(it + 1, str5.begin(), str5.begin() + 6); //you are not beauty~ha ha , but i am more handsome!...
}

void ReplaceTest()
{
	std::string str  = "this is a test string.";
	std::string str2 = "n example";
	std::string str3 = "sample phrase";
	std::string str4 = "useful.";
	//第9个字符及后面的4个字符被str2代替
	str.replace(9, 5, str2);             // "this is an example string."
	//第19个字符串以及后面的5个字符用str的第7个字符以及后面的5个字符代替
	str.replace(19, 6, str3, 7, 6);      // "this is an example phrase."
	//第8个字符以及后面的9个字符用字符串参数代替
	str.replace(8, 10, "just a");        // "this is just a phrase."    
	//第8个字符以及后面的5个字符用字符串参数的前7个字符替换
	str.replace(8, 6, "a short www", 7); // "this is a short phrase."  
	//第22以及后面的0个字符用3个叹号替换
	str.replace(22, 1, 3, '!');          // "this is a short phrase!!!"  
                                        
	str.replace(str.begin(), str.end() - 3, str3);                       // "sample phrase!!!"     
	str.replace(str.begin(), str.begin() + 6, "replace");                // "replace phrase!!!"     
	str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);    // "replace is cool!!!"   
	str.replace(str.begin() + 12, str.end() - 4, 4, 'o');                // "replace is cooool!!!"
	str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end());  // "replace is useful."    
}

void AssignTest()
{
	std::string str;
	std::string str2 = "The quick brown fox jumps over a lazy dog.";
	//直接把str2赋值给str
	str.assign(str2);
	//把str2第10个字符以及后面的8个字符赋给str
	str.assign(str2, 10, 9);
	//把参数中的0到6个字符串赋给str
	str.assign("pangrams are cool", 7);
	//直接使用参数赋值
	str.assign("c-string");
	//给str赋值10个'*'字符
	str.assign(10, '*');
	//指定base迭代器范围的字符串
	str.assign(str2.begin() + 16, str2.end() - 12);
}

void FindTest()
{
	std::string str("There are two needles in this haystack with needles.");
	std::string str2("needle");

	//在str当中查找第一个出现的needle，找到则返回出现的位置，否则返回结尾
	std::size_t found = str.find(str2);
	if (found != std::string::npos)
	{
		std::cout << "first 'needle' found at: " << found << '\n';  //找到
	}
	//在str当中，从第found+1的位置开始查找参数字符串的前6个字符
	found = str.find("needles are small", found + 1, 6);
	if (found != std::string::npos)
		std::cout << "second 'needle' found at: " << found << '\n';
	//在str当中查找参数中的字符串
	found = str.find("haystack");
	if (found != std::string::npos)
		std::cout << "'haystack' also found at: " << found << '\n';
	//查找一个字符
	found = str.find('.');
	if (found != std::string::npos)
		std::cout << "Period found at: " << found << '\n';
	//组合使用，把str2用参数表中的字符串代替
	// let's replace the first needle:
	str.replace(str.find(str2), str2.length(), "preposition");
	std::cout << str << '\n';
}

void CompareTest()
{
	std::string s1 = "123";
	std::string s2 = "123";
	std::cout << s1.compare(s2) << std::endl;//0
	s1 = "123", s2 = "1234";
	std::cout << s1.compare(s2) << std::endl;//-1
	s1 = "1234", s2 = "123";
	std::cout << s1.compare(s2) << std::endl;//1
	std::string str1("green apple");
	std::string str2("red apple");
	if (str1.compare(str2) != 0)
		std::cout << str1 << " is not " << str2 << '\n';
	//str1的第6个字符以及后面的4个字符和参数比较
	if (str1.compare(6, 5, "apple") == 0)
		std::cout << "still, " << str1 << " is an apple\n";
	if (str2.compare(str2.size() - 5, 5, "apple") == 0)
		std::cout << "and " << str2 << " is also an apple\n";
	//str1的第6个字符以及后面的4个字符和str2的第4个字符以及后面的4个字符比较
	if (str1.compare(6, 5, str2, 4, 5) == 0)
		std::cout << "therefore, both are apples\n";
}

void StringOperateFunc()
{
	InsertTest();
	ReplaceTest();
	AssignTest();
	CompareTest();
}


void StringTest()
{
	DefineStringInit();
	StringOperateFunc();
}




#endif

