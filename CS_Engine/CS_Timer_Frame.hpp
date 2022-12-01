/**
 * @file CS_Timer_Frame.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief For Timer Frame
 * @version 0.1
 * @date 2018-12-14
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once

class CS_Timer_Frame
{
public:
	static void Reset();
	static double GetElapsedSeconds();
	static void Update();
	static float GetDt();
	static int GetFPS();
};

