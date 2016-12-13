#pragma once
#ifndef __ProtectCastle__MonsterContainer__
#define __ProtectCastle__MonsterContainer__
#include"MonsterDataOfWave.h"
#include"MonsterFactory.h"
#include "json/document.h"
#include "PointDelegate.h"


class MonsterContainer
{
public:


	MonsterContainer();
	~MonsterContainer();
	
	void loadMonster(TMXTiledMap* _tileMap, rapidjson::Value& monstersArray,int&  monsterCount, Vector<MonsterDataOfWave*> & _monsterAllDatas);

//	void monsterMoveWithWayPoints(Vector<PointDelegate*> pathVector, Monster* monster);
};

#endif