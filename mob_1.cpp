#include "DXUT.h"
#include "mob_1.h"
#include "cMBullet.h"

mob_1::mob_1(vector<cBullet*>& bullet, Vec2 mob_p)
	:m_bullet(bullet)
{
	this->mob_p = mob_p;
}

mob_1::~mob_1()
{

}

void mob_1::Update(Vec2 m_pos, int cell [][CELLSIZEY])
{
	if (cell[int(mob_p.x)][int(mob_p.y)] == 3)
	{
		mob_1::~mob_1();
	}

	Skill(m_pos);
}

void mob_1::Skill(Vec2 m_pos)
{
	frame += Delta * 5;
	if (frame >= m_ani.size())
		frame = 0;

	if (bultime > 1) //1초마다 기본 불렛
	{
		Vec2 pos;
		D3DXVec2Normalize(&pos, &(m_pos - mob_p));
		m_bullet.push_back(new cMBullet(Vec2(mob_p.x + 70, mob_p.y), pos, 1));
		bultime = 0;
	}

	bultime += Delta;
}
void mob_1::Render()
{

}
void mob_1::UIRender()
{
	UI->CenterRender(m_ani[int(frame)], mob_p, 2);
}