#define WIN32_LEAN_AND_MEAN
#include<Windows.h>
#include<iostream>

#define VK_A 0x97
 
	void keyboarad_handle() {
		int var = 0;
		
		while (1)
		{
		

			if (GetKeyState('Q') & 0x8000)
			{
				std::cout << " clicked: " << var++ << std::endl;
				Sleep(400);
				std::cout << "woke";

			}
			if (GetKeyState('W') & 0x8000)
			{
				std::cout << " clicked: " << var++ << std::endl;
			}
			if (GetKeyState('E') & 0x8000)
			{
				std::cout << " clicked: " << var++ << std::endl;

			}
			if (GetKeyState('r') & 0x8000)
			{
				std::cout << " clicked: " << var++ << std::endl;

			}
		}

	};
