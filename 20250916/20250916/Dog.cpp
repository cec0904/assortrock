#include "Dog.h"

#include "Singleton.h"

void CDog::moungmoung()
{
	Singleton::GetInstance2().LogPrint("멍멍~ 멍멍~");
}
