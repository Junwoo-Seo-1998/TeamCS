/**
 * @file CS_Application.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Control application.
 * @version 0.1
 * @date 2018-12-10
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "CS_WinHeader.hpp"
#include "CS_GameData.hpp"
#include <glm/vec2.hpp>
class CS_Graphics;
class CS_StageManager;
struct CS_InitData
{
    std::string Title="";
    std::string StartStage ="";
    int Height=480;  
    int Width= 640;
    CS_GameData GameData;
};

class CS_Application
{
    friend CS_Graphics;
	friend CS_StageManager;
public:
    static bool Init(CS_InitData& initData);
    static void Update();
    static void ShutDown();
    static void EndAll();
    static glm::vec2 GetWindowSize();
private:
    static PIXELFORMATDESCRIPTOR MakePixelDescription();
    static bool MakeOldOpenglWindow();
    static void RegisterOpenglClass();
    static bool MakeOpenGLContext();
    static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    static void PeekMessages();
    static void SwapBuffer();
    


};

