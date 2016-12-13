#include"MonsterFactory.h"



		 MonsterBase* MonsterFactory::getMonster(MonsterData* monsterData)
{

		// ���ݹ������ƴ�������
		auto monster = Monster::create(monsterData->getName());
		

		// ���ù������ơ�����ֵ���������Ľ��ֵ�͹����������
		monster->setName(monsterData->getName());
		monster->setLifeValue(monsterData->getLifeValue());
		monster->setGold(monsterData->getGold());
		monster->setScale(0.7);
		

		// ����������
		auto loadingBar = LoadingBar::create("planeHP.png");
		// ���ý���������
		loadingBar->setDirection(LoadingBar::Direction::LEFT);
		// ���ý�������С
		loadingBar->setScale(0.06f, 0.1f);
		// ���ý������ٷֱ�
		loadingBar->setPercent(100);
		// ������������Ϊ����Ѫ��
		monster->setHP(loadingBar);

		return monster;

}