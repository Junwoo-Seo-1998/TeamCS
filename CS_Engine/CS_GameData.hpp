/**
 * @file CS_GameData.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Sharable game data management.
 * @version 0.1
 * @date 2018-12-14
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include <string>
/*! This struct holds game data that is shared between stages. This struct must
have at least one data member in it.*/
struct CS_GameData
{
    int level=0;
    int maxLevels=0;
    std::string menuFile="";
};