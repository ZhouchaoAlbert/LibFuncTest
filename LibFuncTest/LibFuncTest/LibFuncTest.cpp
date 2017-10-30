// LibFuncTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "StringTest.h"

int _tmain(int argc, _TCHAR* argv[])
{
	StringTest();
	char aaa[10] = { 1,2,3,4,5,6,7,8,9 };
	std::string s(aaa, 5);
	return 0;
}

