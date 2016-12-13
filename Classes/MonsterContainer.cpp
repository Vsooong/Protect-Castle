#include "MonsterContainer.h"
#include <vector>


MonsterContainer::MonsterContainer()
{

}


MonsterContainer::~MonsterContainer()
{
}
void MonsterContainer::loadMonster(Game& game, rapidjson::Value& monstersArray) {



	for (int i = 0; i < monstersArray.Size(); i++) {
		auto monsterDatas = MonsterDataOfWave::create();
		int count = monstersArray[i]["count"].GetInt();
		monsterDatas->setCount(count);
		int delivery = monstersArray[i]["delivery"].GetInt();
		monsterDatas->setDelivery(delivery);
		const rapidjson::Value& monsterArray = monstersArray[i]["monster"];
		//		_monsterDatas.clear();
		for (int j = 0; j < monsterArray.Size(); j++) {
			// ���ÿһ�ֹ����name��lifeValue��gold����
			std::string name = monsterArray[j]["name"].GetString();
			int lifeValue = monsterArray[j]["lifeValue"].GetInt();
			int gold = monsterArray[j]["gold"].GetInt();
			// ����õ�name��lifeValue��gold���ݴ洢���Զ���MonsterData������
			auto monsterData = MonsterData::create();
			monsterData->setName(name);
			monsterData->setLifeValue(lifeValue);
			monsterData->setGold(gold);
			// ��MonsterData�洢���ؿ��������ݵļ��ϵ���
			monsterDatas->pushBack(monsterData);
		}
		game._monsterAllDatas.pushBack(monsterDatas);
	}
	game._monsterDatas =game. _monsterAllDatas.at(0);
	game._delivery =game._monsterDatas->getDelivery();

}



