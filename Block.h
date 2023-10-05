#pragma once

#include <easyx.h>
#include "Game.h"

#define BLOCK_WIDTH 20	// ������

// ������
class Block
{
public:
	Block(Game& game, const int& x = (MAP_WIDTH - 4) / 2, const int& y = 0);	// ��ʼ������
	bool move(const unsigned& direction = 0);									// �ƶ�������0 ��ʾ����һ��1 ��ʾ����һ��2 ��ʾ����һ�񣬵����Ƽ�⵽��ײʱ���� true
	void draw() const;															// ���ƺ���
	void clear() const;															// �������
	void addMap() const;														// ��ӷ��鵽��ͼ
	void rotate();																// ��ת���飬false ����true ����
	bool checkCollision() const;												// ��ײ���
	static void generateBlockData();											// ��ʼ����������
	void setPos(const int& x = (MAP_WIDTH - 4) / 2, const int& y = 0);			// ���÷�������
	void randType();															// �����������
	void operator=(const Block& block);											// Ϊ Block ��ֵ

private:
	int x;							// ���� X ����
	int y;							// ���� Y ����
	unsigned char type;				// ��������
	bool direction;					// ��ת����false ����˳ʱ�룬true ������ʱ��
	bool block[4][4];				// �������飬true ��ʾ�з��飬false ��ʾû����
	COLORREF color;					// ���������ɫ
	static bool blockData[7][4][4];	// �������ݣ����������Դ
	Game& game;						// Game ���ö���
};