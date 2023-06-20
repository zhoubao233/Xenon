#include "Warcraft.h"

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)/*本质上就是DDL文件 有些程序ROOT目录 会自动加载    也可以手动注入*/
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		HideDll((HMODULE)dwGameDll);
		HideDll(hModule);

		if (WarcraftVersion() == 6401)
		{
			SettingInitialize();

			JassNativesInit();

			ColorInvisiblesInit();
			DamageNotifierInit();
			DreamUiInit();
			GameStartNotifierInit();
			GrayHpUnderFogInit();
			InstantGameStartInit();
			ManaBarInit();
			RoshanNotifierInit();
			RuneNotifierInit();
			SafeClickInit(true);

			HANDLE hThread = CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)HotKeys, NULL, NULL, NULL);
			CloseHandle(hThread);
		}
	}

	return TRUE;
}