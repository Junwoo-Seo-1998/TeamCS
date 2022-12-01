/**
 * @file CS_Physics.hpp
 * @author Junwoo Seo
 * @email seojunwoo72\@gmail.com
 * @brief Basic physics calculation.
 * @version 0.1
 * @date 2018-12-14
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#pragma once
#include <vector>
#include "CS_Object.hpp"

//obj id
struct CollisionData
{
	int ID = -1;
	std::string name="";
};

typedef std::vector < std::pair<CollisionData, CollisionData> > CollisionPairs;

class CS_ColliderComponent;

class CS_StageManager;
class CS_Physics
{
public:
friend class CS_StageManager;

//Registers a collider with the physics engine
    static void AddColliderComponent(CS_ColliderComponent* pCollider);
//Unregisters a collider with the physics engine
    static void RemoveColliderComponent(CS_ColliderComponent* pCollider);
//Gets all pairs of objects that collided this frame.
    static void GetCollisionPairs(CollisionPairs& pairs);
	static bool IsThereCollidingWithName(int this_ID, const std::string& name);
	static bool IsThereCollidingWithID(int this_ID, int other_ID);
	static bool IsThereAnyColliding(const std::string& object_name);
	static bool IsThereAnyColliding(int object_ID);
//Marks a pair of Objects as having collided.
    static void AddCollisionPair(CollisionData First, CollisionData Second);

private:
	static void Update(void);
	static void Pause(void);
	static void Resume(void);
};