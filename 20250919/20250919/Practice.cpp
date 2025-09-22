#include <iostream>

using namespace std;

class AllCalcultaeFunc
{
public:
	AllCalcultaeFunc()
	{

	}
	virtual ~AllCalcultaeFunc()
	{

	}

	
};

int AddResultFunc(int a, int b)
{
	cout << "덧셈 : " << a + b << endl;
	return 0;
}








int main()
{
	int(*pAddResultFunc)(int) = AddResultFunc;
	AddResultFunc();




}