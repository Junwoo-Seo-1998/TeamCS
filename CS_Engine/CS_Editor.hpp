#pragma once
#include <string>


class CS_Camera;

class CS_Editor
{
public:
	static bool IsEditModeOn();
	static void EditStart(CS_Camera* cam);
    static void Update(float dt);
	static void EditEnd();
	static std::string GetSelectedLevel();
	static void UnSelectObject();
private:
	static void SaveAll();
    static void CameraControl(float dt);
    static void SelectObject();
	static void ShowMenuBar();
	static void SetPositionEditWindow();
	//debug settings{
	static void ShowDebugSettings();
	//}
	//spawn menu{
	static void ShowSpawnButton();
	static void ShowSpawnMenu();
	//}
	//Edit menu{
	static void ShowAddComponentButton();
	static void ShowAddComponentTree();
	static void ShowObjectEditMenu();
	//}

    static void ShowGui();
	
	
};
