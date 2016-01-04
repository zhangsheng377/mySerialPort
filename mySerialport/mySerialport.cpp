// mySerialport.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SerialPort.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{

	CSerialPort mySerialPort;

	//if (!mySerialPort.InitPort(2))
	if (!mySerialPort.InitPort(2))
	{
		std::cout << "initPort fail !" << std::endl;
	}
	else
	{
		std::cout << "initPort success !" << std::endl;
	}

	if (!mySerialPort.OpenListenThread())
	{
		std::cout << "OpenListenThread fail !" << std::endl;
	}
	else
	{
		std::cout << "OpenListenThread success !" << std::endl;
	}

	char t;
	while (1) {
		//mySerialPort.WriteData((unsigned char*)"123", 9);
		if(mySerialPort.ReadChar(t)) std::cout << t;
	}
	int temp;
	std::cin >> temp;

	return 0;
}

