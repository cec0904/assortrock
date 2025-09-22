#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "Hello World!";

	// 길이 알고싶다 ?
	cout << str.length() << endl;

	// 문자열의 크기 알고싶다 ?
	cout << str.size() << endl;

	// 
	cout << str.capacity() << endl;



	str += "!!!!!!!!!!!";
	cout << str << endl;
	cout << str.length() << endl;
	cout << str.capacity() << endl;

	// C 스타일의 문자열로 변환시켜준다
	const char* pchar = str.c_str();
	const char* pchar2 = str.data();

	// 이 문자열이 비어있는가 ?
	str.empty();		// bool 값을 준다
						// 문자열이 비어있으면 true, 뭔가 있으면 false





	if (str.empty())
	{
		cout << "비어있습니다." << endl;
	}
	else
	{
		cout << "무언가 있습니다." << endl;
	}
	
	str.clear();		// 문자열을 비운다.

	//////////////////////////////////////////////////
	// 문자열 비교

	str = "Hello";
	string str2 = "Hello";

	if (str == str2)
	{
		cout << "같다." << endl;
	}
	else 
	{
		cout << "다르다." << endl;
	}
	


	//////////////////////////////////////////////
	// 문자열 찾기

	str = "ABCDEFG";
	str2 = "DE";

	str.find(str2);
	int findIndex = (int)str.find(str2);
	if (findIndex != string::npos)		// string::npos 면 일치하는 문자가 없다.
	{
		cout << "인덱스를 찾았습니다." << findIndex << endl;
	}
	else
	{
		cout << "인덱스를 찾지 못했습니다." << endl;
	}




	return 0;

}