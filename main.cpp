/*
*	������ȤС��Ϸ֮����˹����
*	���ߣ�QtС��
*	���뻷����Visual Studio 2022 + EasyX_20220901
*	����޸ģ�2023 �� 4 �� 5 ��
*/


#include "Block.h"
#include "Game.h"
#include <ctime>
#include <iostream>

int main()
{
	SetWindowText(initgraph(350, 440), L"����˹����");

	// ���û�ͼ��ɫ
	setbkcolor(WHITE);
	cleardevice();
	setlinecolor(BLACK);

	// ������Ϸ���������
	srand(time(NULL));
	Block::generateBlockData();

	Game game;
	game.drawMap();
	game.drawPrompt();

	Block b(game);
	Block nextBlock(game, 11, 2);	// ��һ����
	clock_t start = 0;				// ʱ�ӿ�ʼʱ��
	clock_t end;					// ʱ�ӽ���ʱ��

	ExMessage msg;

	nextBlock.draw();

	// ��Ϸѭ��
	BeginBatchDraw();
	while (true)
	{
		b.clear();
		clearrectangle(20, 20, 220, 420);
		game.drawMap();

		// ��������
		while (peekmessage(&msg, EX_KEY) && msg.message == WM_KEYDOWN)
		{
			switch (msg.vkcode)
			{
				// �ϼ���ת
			case 'W':
			case VK_UP:
				b.rotate();
				break;

				// �¼���������
			case 'S':
			case VK_DOWN:
				if (b.move())
				{
					// �������÷���
					b.addMap();
					b = nextBlock;
					b.setPos();
					nextBlock.clear();
					nextBlock.setPos(11, 2);
					nextBlock.randType();
					nextBlock.draw();

					// �������ո�����ȴ��������ײ��˵����Ϸ����
					if (b.checkCollision())
					{
						MessageBox(GetHWnd(), L"��Ϸ������", L"��ʾ", MB_ICONWARNING);
						goto exit;
					}
				}
				break;

				// ����ƶ�
			case 'A':
			case VK_LEFT:
				b.move(1);
				break;

				// �Ҽ��ƶ�
			case 'D':
			case VK_RIGHT:
				b.move(2);
				break;

				// Esc ���˳�����
			case VK_ESCAPE:
				goto exit;
				break;
			}
		}

		// �ж�ÿ���� 500 ���뷽������һ��
		end = clock();
		if (end - start >= 500)
		{
			if (b.move())
			{
				// �������÷���
				b.addMap();
				b = nextBlock;
				b.setPos();
				nextBlock.clear();
				nextBlock.setPos(11, 2);
				nextBlock.randType();
				nextBlock.draw();

				// �������ո�����ȴ��������ײ��˵����Ϸ����
				if (b.checkCollision())
				{
					MessageBox(GetHWnd(), L"��Ϸ������", L"��ʾ", MB_ICONWARNING);
					goto exit;
				}
			}
			start = clock();
			game.addGameTime();
		}
		b.draw();
		game.clearLine();
		FlushBatchDraw();	// ˢ�»�����
		Sleep(50);			// ÿ 50 �������һ�ΰ���
	}

exit:
	EndBatchDraw();

	closegraph();
	return 0;
}