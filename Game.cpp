#include "Game.h"

void Game::drawMap() const
{
	// ���Ʊ߿�
	roundrect(10, 10, 340, 430, 10, 10);
	rectangle(20, 20, 220, 420);

	// ���Ƶ�ͼ
	setfillcolor(LIGHTCYAN);
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			if (map[i][j])
			{
				int left = 20 + 20 * i, top = 20 + 20 * j;
				fillrectangle(left, top, left + 20, top + 20);
			}
		}
	}
}

void Game::drawPrompt() const
{
	// ��������
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	wcscpy_s(f.lfFaceName, L"΢���ź�");
	f.lfQuality = DEFAULT_QUALITY;
	settextstyle(&f);
	settextcolor(BLACK);

	// ���� ����һ���顱 ��ʾ
	outtextxy(235, 20, L"��һ����");
	rectangle(240, 60, 320, 140);

	// ���� �������� �� ��ʱ�䡱
	f.lfHeight = 25;
	settextstyle(&f);

	wchar_t str[10];
	wsprintf(str, L"������%u", score);
	outtextxy(230, 150, str);

	wsprintf(str, L"ʱ�䣺%u��", gameTime / 1000);
	outtextxy(230, 175, str);

	// ���� ������˹���顱
	f.lfHeight = 40;
	settextstyle(&f);
	settextcolor(RED);
	outtextxy(234, 250, L"����˹");
	outtextxy(250, 290, L"����");
	outtextxy(240, 330, L"Tetris");

	// ���� �����ߡ�
	f.lfHeight = 25;
	settextstyle(&f);
	outtextxy(234, 395, L"���ߣ�С��");
}

bool Game::checkLine(const unsigned& line) const
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		if (map[i][line] == 0)
		{
			return false;
		}
	}
	return true;
}

void Game::clearLine()
{
	int line = -1;
	// �ж���һ������
	for (int j = 0; j < MAP_HEIGHT; j++)
	{
		if (checkLine(j))
		{
			line = j;
			break;
		}
	}

	if (line != -1)
	{
		// ����һ����������
		for (int j = line; j > 0; j--)
		{
			for (int i = 0; i < MAP_WIDTH; i++)
			{
				map[i][j] = map[i][j - 1];
			}
		}
		score += 10;	// ����Ϸ������ 10
	}
	drawPrompt();
}
