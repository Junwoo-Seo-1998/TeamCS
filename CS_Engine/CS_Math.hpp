/**
 * @file CS_Math.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Transform building process.
 * @version 0.1
 * @date 2018-12-14
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include "glm/glm.hpp"
namespace affine2D
{
	glm::mat3 build_translation(const glm::vec2 & translation);
	glm::mat3 build_rotation(float rad);
	glm::mat3 build_scale(const glm::vec2 & scale);
}
namespace mat2x2
{
    glm::mat2 build_rotation(float rad);
}