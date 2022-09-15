#include <Windows.h>
#include <iostream>
#include <random>

using namespace std;

std::string gen_string(const int length)
{
	std::string GeneratedString;
	static const char Alphabet[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; i++)
	{
		GeneratedString += Alphabet[rand() % (sizeof(Alphabet) - 1)];
	}
	return GeneratedString;
}

int main()
{
	SetConsoleTitleA(gen_string(25).c_str());
	system("COLOR 17");

	int value = 1;

	HWND hwnd = FindWindowA(NULL, "AssaultCube");

	if (hwnd == NULL)
	{
		printf_s("Hileyi baslatmadan once oyuna giris yapiniz.");
		Sleep(3000);
		exit(-1);
	}
	else
	{
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

		if (procID == NULL)
		{
			exit(-1);
		}
		else
		{
			printf("Hile baslatildi.");

			for (;;)
			{
				if (GetAsyncKeyState(VK_INSERT))
				{
					WriteProcessMemory(handle, (LPVOID)0x88239C, &value, sizeof(int), 0); // Health
					WriteProcessMemory(handle, (LPVOID)0x8823B8, &value, sizeof(int), 0); // MK-77
					WriteProcessMemory(handle, (LPVOID)0x8823CC, &value, sizeof(int), 0); // MTP-57
					WriteProcessMemory(handle, (LPVOID)0x8823DC, &value, sizeof(int), 0); // MK-77 Clip
					WriteProcessMemory(handle, (LPVOID)0x8823F0, &value, sizeof(int), 0); // MTP-57 Clip
					value++;
				}
				if (GetAsyncKeyState(VK_END))
				{
					exit(-1);
				}
			}
		}
	}
}

