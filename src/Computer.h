#include "panding34.h"
#include "VictoryMethod.h"



#pragma once

class Computer
{
public:
	Computer();
	~Computer();



public:
	panding34 user;


	void putwhite(int cx, int cy, int c[][19]) {
		int white = 0;    //标志位white判断是否已放置白子
		int black = 0;



		//计算棋盘中黑子的数目
		for (int i = 0;i < 19;i++)
			for (int j = 0;j < 19;j++)
				if (c[i][j] == 1) black++;

		//第一个白子的位置
		if (black == 1) {
			for (int i = cx - 1;i <= (cx + 1);i++)
			{
				int tiao2 = 1;
				for (int j = cy - 1;j <= (cy + 1);j++)
				{

					if (c[i][j] == 0 && i >= 0 && j >= 0)
					{
						c[i][j] = 2; tiao2 = 0;break;
					}
				}
				if (tiao2 == 0) break;
			}
		}


		//第二个以及以后白子的放置位置
		else if (black > 1) {

			//优先处理一些不是连四、连五但有危险的特殊情况
			if (white == 0) {
				for (int i = 0;i < 19;i++)
				{
					bool flag = false;
					for (int j = 0; j < 19;j++) {

						if ((c[i][j] == 0 && c[i - 1][j] == 1 && c[i + 1][j] == 1 && c[i][j - 1] == 1 && c[i][j + 1] == 1) || (c[i][j] == 0 && c[i - 1][j] == 2 && c[i + 1][j] == 2 && c[i][j - 1] == 2 && c[i][j + 1] == 2))
						{
							c[i][j] = 2; white = 1;flag = true; break;
						}
						if ((c[i][j] == 0 && c[i - 1][j - 1] == 1 && c[i + 1][j + 1] == 1 && c[i + 1][j - 1] == 1 && c[i - 1][j + 1] == 1) || (c[i][j] == 0 && c[i - 1][j - 1] == 2 && c[i + 1][j + 1] == 2 && c[i + 1][j - 1] == 2 && c[i - 1][j + 1] == 2))
						{
							c[i][j] = 2; white = 1;flag = true; break;
						}


						if ((c[i][j] == 1 && c[i][j + 1] == 1 && c[i][j + 2] == 0 && c[i][j + 3] == 1 && c[i][j + 4] == 1) || (c[i][j] == 2 && c[i][j + 1] == 2 && c[i][j + 2] == 0 && c[i][j + 3] == 2 && c[i][j + 4] == 2))
						{
							c[i][j + 2] = 2; white = 1;flag = true; break;
						}
						if ((c[i][j] == 1 && c[i + 1][j] == 1 && c[i + 2][j] == 0 && c[i + 3][j] == 1 && c[i + 4][j] == 1) || (c[i][j] == 2 && c[i + 1][j] == 2 && c[i + 2][j] == 0 && c[i + 3][j] == 2 && c[i + 4][j] == 2))
						{
							c[i + 2][j] = 2; white = 1; flag = true;break;
						}
						if ((c[i][j] == 1 && c[i + 1][j + 1] == 1 && c[i + 2][j + 2] == 0 && c[i + 3][j + 3] == 1 && c[i + 4][j + 4] == 1) || (c[i][j] == 2 && c[i + 1][j + 1] == 2 && c[i + 2][j + 2] == 0 && c[i + 3][j + 3] == 2 && c[i + 4][j + 4] == 2)) {
							c[i + 2][j + 2] = 2;white = 1;flag = true;break;
						}
						if ((c[i][j] == 1 && c[i + 1][j - 1] == 1 && c[i + 2][j - 2] == 0 && c[i + 3][j - 3] == 1 && c[i + 4][j - 4] == 1) || (c[i][j] == 2 && c[i + 1][j - 1] == 2 && c[i + 2][j - 2] == 0 && c[i + 3][j - 3] == 2 && c[i + 4][j - 4] == 2)) {
							c[i + 2][j - 2] = 2;white = 1;flag = true;break;
						}


						if (c[i][j] == 2 && c[i][j + 1] == 1 && c[i][j + 2] == 1 && c[i][j + 3] == 1 && c[i][j + 4] == 0 && c[i][j + 5] == 1)
						{
							c[i][j + 4] = 2; white = 1;flag = true; break;
						}
						if (c[i][j] == 2 && c[i + 1][j] == 1 && c[i + 2][j] == 1 && c[i + 3][j] == 1 && c[i + 4][j] == 0 && c[i + 5][j] == 1)
						{
							c[i + 4][j] = 2; white = 1; flag = true;break;
						}
						if (c[i][j] == 2 && c[i + 1][j + 1] == 1 && c[i + 2][j + 2] == 1 && c[i + 3][j + 3] == 1 && c[i + 4][j + 4] == 0 && c[i + 5][j + 5] == 1) {
							c[i + 4][j + 4] = 2;white = 1;flag = true;break;
						}
						if (c[i][j] == 2 && c[i + 1][j - 1] == 1 && c[i + 2][j - 2] == 1 && c[i + 3][j - 3] == 1 && c[i + 4][j - 4] == 0 && c[i + 5][j - 5] == 1) {
							c[i + 4][j - 4] = 2;white = 1;flag = true;break;
						}


						if (c[i][j] == 1 && c[i][j + 1] == 0 && c[i][j + 2] == 1 && c[i][j + 3] == 1 && c[i][j + 4] == 1 && c[i][j + 5] == 2)
						{
							c[i][j + 4] = 2; white = 1;flag = true; break;
						}
						if (c[i][j] == 1 && c[i + 1][j] == 0 && c[i + 2][j] == 1 && c[i + 3][j] == 1 && c[i + 4][j] == 1 && c[i + 5][j] == 2)
						{
							c[i + 4][j] = 2; white = 1; flag = true;break;
						}
						if (c[i][j] == 1 && c[i + 1][j + 1] == 0 && c[i + 2][j + 2] == 1 && c[i + 3][j + 3] == 1 && c[i + 4][j + 4] == 1 && c[i + 5][j + 5] == 2) {
							c[i + 4][j + 4] = 2;white = 1;flag = true;break;
						}
						if (c[i][j] == 1 && c[i + 1][j - 1] == 0 && c[i + 2][j - 2] == 1 && c[i + 3][j - 3] == 1 && c[i + 4][j - 4] == 1 && c[i + 5][j - 5] == 2) {
							c[i + 4][j - 4] = 2;white = 1;flag = true;break;
						}


						if ((c[i][j] == 0 && c[i][j + 1] == 1 && c[i][j + 2] == 1 && c[i][j + 3] == 0 && c[i][j + 4] == 1 && c[i][j + 5] == 0) || (c[i][j] == 0 && c[i][j + 1] == 2 && c[i][j + 2] == 2 && c[i][j + 3] == 0 && c[i][j + 4] == 2 && c[i][j + 5] == 0))
						{
							c[i][j + 3] = 2; white = 1;flag = true; break;
						}
						if ((c[i][j] == 0 && c[i + 1][j] == 1 && c[i + 2][j] == 1 && c[i + 3][j] == 0 && c[i + 4][j] == 1 && c[i + 5][j] == 0) || (c[i][j] == 0 && c[i + 1][j] == 2 && c[i + 2][j] == 2 && c[i + 3][j] == 0 && c[i + 4][j] == 2 && c[i + 5][j] == 0))
						{
							c[i + 3][j] = 2; white = 1; flag = true;break;
						}
						if ((c[i][j] == 0 && c[i + 1][j + 1] == 1 && c[i + 2][j + 2] == 1 && c[i + 3][j + 3] == 0 && c[i + 4][j + 4] == 1 && c[i + 5][j + 5] == 0) || (c[i][j] == 0 && c[i + 1][j + 1] == 2 && c[i + 2][j + 2] == 2 && c[i + 3][j + 3] == 0 && c[i + 4][j + 4] == 2 && c[i + 5][j + 5] == 0)) {
							c[i + 3][j + 3] = 2;white = 1;flag = true;break;
						}
						if ((c[i][j] == 0 && c[i + 1][j - 1] == 1 && c[i + 2][j - 2] == 1 && c[i + 3][j - 3] == 0 && c[i + 4][j - 4] == 1 && c[i + 5][j - 5] == 0) || (c[i][j] == 0 && c[i + 1][j - 1] == 2 && c[i + 2][j - 2] == 2 && c[i + 3][j - 3] == 0 && c[i + 4][j - 4] == 2 && c[i + 5][j - 5] == 0)) {
							c[i + 3][j - 1] = 2;white = 1;flag = true;break;
						}


						if ((c[i][j] == 0 && c[i][j + 1] == 1 && c[i][j + 2] == 0 && c[i][j + 3] == 1 && c[i][j + 4] == 1 && c[i][j + 5] == 0) || (c[i][j] == 0 && c[i][j + 1] == 2 && c[i][j + 2] == 0 && c[i][j + 3] == 2 && c[i][j + 4] == 2 && c[i][j + 5] == 0))
						{
							c[i][j + 2] = 2; white = 1;flag = true; break;
						}
						if ((c[i][j] == 0 && c[i + 1][j] == 1 && c[i + 2][j] == 0 && c[i + 3][j] == 1 && c[i + 4][j] == 1 && c[i + 5][j] == 0) || (c[i][j] == 0 && c[i + 1][j] == 2 && c[i + 2][j] == 0 && c[i + 3][j] == 2 && c[i + 4][j] == 2 && c[i + 5][j] == 0))
						{
							c[i + 2][j] = 2; white = 1; flag = true;break;
						}
						if ((c[i][j] == 0 && c[i + 1][j + 1] == 1 && c[i + 2][j + 2] == 0 && c[i + 3][j + 3] == 1 && c[i + 4][j + 4] == 1 && c[i + 5][j + 5] == 0) || (c[i][j] == 0 && c[i + 1][j + 1] == 2 && c[i + 2][j + 2] == 0 && c[i + 3][j + 3] == 2 && c[i + 4][j + 4] == 2 && c[i + 5][j + 5] == 0)) {
							c[i + 2][j + 2] = 2;white = 1;flag = true;break;
						}
						if ((c[i][j] == 0 && c[i + 1][j - 1] == 1 && c[i + 2][j - 2] == 0 && c[i + 3][j - 3] == 1 && c[i + 4][j - 4] == 1 && c[i + 5][j - 5] == 0) || (c[i][j] == 0 && c[i + 1][j - 1] == 2 && c[i + 2][j - 2] == 0 && c[i + 3][j - 3] == 2 && c[i + 4][j - 4] == 2 && c[i + 5][j - 5] == 0)) {
							c[i + 2][j - 2] = 2;white = 1;flag = true;break;
						}
					}
					if (flag) break;
				}
			}

			//连四情况下白子的放置位置	
			int four = user.panding(4, c);
			if (four != 0 && white == 0)
			{
				if (user.blackV != 0 || user.whiteV != 0)
				{
					if (c[user.blackV][user.whiteV + 1] == 0)
					{
						c[user.blackV][user.whiteV + 1] = 2;white = 1;
					}
					else
					{
						c[user.blackV][user.whiteV - 4] = 2;white = 1;
					}




				}


				if (user.bz != 0 || user.wz != 0)
				{
					if (c[user.bz - 4][user.wz] == 0)
					{
						c[user.bz - 4][user.wz] = 2;white = 1;
					}
					else
						if (c[user.bz + 1][user.wz] == 0)
						{
							c[user.bz + 1][user.wz] = 2;white = 1;
						}

				}


				if (user.bxf != 0 || user.wxf != 0)
				{
					if (c[user.bxf + 4][user.wxf + 4] == 0)
					{
						c[user.bxf + 4][user.wxf + 4] = 2;white = 1;
					}
					else
						if (c[user.bxf - 1][user.wxf - 1] == 0)
						{
							c[user.bxf - 1][user.wxf - 1] = 2;white = 1;
						}

				}


				if (user.bxz != 0 || user.wxz != 0)
				{
					if (c[user.bxz + 4][user.wxz - 4] == 0)
					{
						c[user.bxz + 4][user.wxz - 4] = 2;white = 1;
					}
					else
						if (c[user.bxz - 1][user.wxz + 1] == 0)
						{
							c[user.bxz - 1][user.wxz + 1] = 2;white = 1;
						}
				}




			}



			//连三情况下白子的放置位置
			int three = user.panding(3, c);
			if (three != 0 && white == 0)
			{
				if (user.blackV != 0 || user.whiteV != 0)
				{
					if (c[user.blackV][user.whiteV - 3] == 0) {
						if (c[user.blackV][user.whiteV + 1] == 0)
						{
							c[user.blackV][user.whiteV - 3] = 2;white = 1;
						}
					}
				}

				else {
					if (user.bz != 0 || user.wz != 0)
					{
						if (c[user.bz + 1][user.wz] == 0) {
							if (c[user.bz - 3][user.wz] == 0)
							{
								c[user.bz + 1][user.wz] = 2;white = 1;
							}
						}
					}

					else {
						if (user.bxf != 0 || user.wxf != 0)
						{
							if (c[user.bxf - 1][user.wxf - 1] == 0) {
								if (c[user.bxf + 3][user.wxf + 3] == 0)
								{
									c[user.bxf - 1][user.wxf - 1] = 2;white = 1;
								}
							}
						}

						else {
							if (user.bxz != 0 || user.wxz != 0)
							{
								if (c[user.bxz - 1][user.wxz + 1] == 0) {
									if (c[user.bxz + 3][user.wxz - 3] == 0)
									{
										c[user.bxz - 1][user.wxz + 1] = 2;white = 1;
									}
								}

							}
						}
					}
				}
			}



			//无以上情况下白子的放置位置，优先考虑了四个方向无黑子的方向放置
			if (white == 0)
			{

				int wh1 = 1;
				for (int i = 2;i < 19;i++) {

					for (int j = 2;j < 19;j++) {
						if (c[i][j] == 2) {
							if (c[i][j - 2] == 0 && c[i][j - 1] == 0 && c[i][j + 1] == 0 && c[i][j + 2] == 0)
							{
								c[i][j - 1] = 2;wh1 = 0;break;
							}
							if (c[i - 2][j] == 0 && c[i - 1][j] == 0 && c[i + 1][j] == 0 && c[i + 2][j] == 0)
							{
								c[i - 1][j] = 2;wh1 = 0;break;
							}
							if (c[i - 2][j - 2] == 0 && c[i - 1][j - 1] == 0 && c[i + 1][j + 1] == 0 && c[i + 2][j + 2] == 0)
							{
								c[i - 1][j - 1] = 2;wh1 = 0;break;
							}
							if (c[i - 2][j + 2] == 0 && c[i - 1][j + 1] == 0 && c[i + 1][j - 1] == 0 && c[i + 2][j - 2] == 0)
							{
								c[i - 1][j + 1] = 2;wh1 = 0;break;
							}
						}
					}
					if (wh1 == 0) break;
				}

				if (wh1 == 1) {
					for (int i = cx - 1;i <= (cx + 1);i++)
					{
						int tiao2 = 1;
						for (int j = cy - 1;j <= (cy + 1);j++)
						{

							if (c[i][j] == 0 && i >= 0 && j >= 0 && i <= 18 && j <= 18)
							{
								c[i][j] = 2; tiao2 = 0;break;
							}
						}
						if (tiao2 == 0) break;
					}
				}

			}
		}
	}
};



