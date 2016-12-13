#pragma once
#ifndef __ProtectCastle__MonsterContainer__
#define __ProtectCastle__MonsterContainer__
#include"MonsterDataOfWave.h"

#include "json/document.h"
#include "PointDelegate.h"

#include "Game.h"
extern class Game;
class MonsterContainer
{
public:


	MonsterContainer();
	~MonsterContainer();
	
	 void loadMonster(Game& game, rapidjson::Value& monstersArray);

//	void monsterMoveWithWayPoints(Vector<PointDelegate*> pathVector, Monster* monster);
};

#endif