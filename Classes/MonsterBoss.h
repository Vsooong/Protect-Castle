#ifndef __ProtectCastle__MonsterBoss__
#define __ProtectCastle__MonsterBoss__

#include"MonsterBase.h"
class MonsterBoss:public MonsterBase
{
private:
	MonsterBase* _Boss;
	const int dodge = 40;
	void Strong();
public:
	MonsterBoss();
	MonsterBoss(MonsterBase* mBase);
	~MonsterBoss();
};
#endif