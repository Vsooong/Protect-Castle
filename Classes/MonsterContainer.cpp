#include "MonsterContainer.h"
#include <vector>


MonsterContainer::MonsterContainer()
{

}


MonsterContainer::~MonsterContainer()
{
}
void MonsterContainer::loadMonster(TMXTiledMap* _tileMap, rapidjson::Value& monstersArray, int& monsterCount, Vector<MonsterDataOfWave*> & _monsterAllDatas) {



	for (int i = 0; i < monstersArray.Size(); i++) {
		auto monsterDatas = MonsterDataOfWave::create();
		int count = monstersArray[i]["count"].GetInt();
		monsterDatas->setCount(count);
		int delivery = monstersArray[i]["delivery"].GetInt();
		monsterDatas->setDelivery(delivery);
		const rapidjson::Value& monsterArray = monstersArray[i]["monster"];
		//		_monsterDatas.clear();
		for (int j = 0; j < monsterArray.Size(); j++) {
			// 获得每一种怪物的name、lifeValue和gold数据
			std::string name = monsterArray[j]["name"].GetString();
			int lifeValue = monsterArray[j]["lifeValue"].GetInt();
			int gold = monsterArray[j]["gold"].GetInt();
			// 将获得的name、lifeValue和gold数据存储到自定义MonsterData对象当中
			auto monsterData = MonsterData::create();
			monsterData->setName(name);
			monsterData->setLifeValue(lifeValue);
			monsterData->setGold(gold);
			// 将MonsterData存储到关卡怪物数据的集合当中
			monsterDatas->pushBack(monsterData);
		}
		_monsterAllDatas.pushBack(monsterDatas);
	}

}



