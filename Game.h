#pragma once

#include <easyx.h>

#define MAP_WIDTH 10	// ��ͼ���
#define MAP_HEIGHT 20	// ��ͼ�߶�

// ��Ϸ��
class Game
{
public:
	void drawMap() const;						// ���Ƶ�ͼ
	void drawPrompt() const;					// ������ʾ����
	bool checkLine(const unsigned& line) const;	// �ж�����
	void clearLine();							// �������

// ��������
public:
	// ���õ�ͼ
	void setMap(const int& x, const int& y, const bool& value)
	{
		map[x][y] = value;
	}

	// ��ȡ��ͼ
	const bool& getMap(const int& x, const int& y) const
	{
		return map[x][y];
	}

	// �����Ϸʱ��
	void addGameTime()
	{
		gameTime += 500;
	}

private:
	bool map[MAP_WIDTH][MAP_HEIGHT] = { 0 };	// ��ͼ����
	unsigned score = 0;							// ��Ϸ����
	unsigned gameTime = 0;						// ��Ϸʱ��
};

