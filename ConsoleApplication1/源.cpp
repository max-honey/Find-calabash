#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<queue> 
using namespace std;
struct s
{
	int x;
	int y;
};
struct s dl[1];
int a[105][105];
int c[105][105];
queue< s > qu;
int main()
{
	int n, m;
	int k;
	int i, j;
	int x, y, p;
	int end_x, end_y;
	while (scanf("%d %d", &n, &m) != EOF)
	{	
		while(qu.size()!=0)qu.pop();
		int flag = 0,tag=0;
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		scanf("%d", &k);
		for (i = 0; i<k; i++)
		{
			scanf("%d %d %d", &x, &y, &p);
			a[x][y] = p;//设定弹簧位置和能量
		}
		scanf("%d %d", &x, &y);//人的初始位置置为1
		c[x][y] = 0;
		dl[0].x = x;
		dl[0].y = y;
		if (a[x][y] > 0) { cout << "impossible" << endl; continue; }//人的位置有弹簧
		a[x][y] = -2;//标志走过了
		qu.push(dl[0]);
		scanf("%d %d", &end_x, &end_y);//输入宝葫芦位置
		if (a[end_x][end_y]>0)//如果放宝葫芦的地方已经放了弹簧
		{
			cout << "impossible" << endl; continue;
		}
		if (a[end_x - 1][y] > 1 && a[end_x + 1][y] > 1 && a[x][y - 1] > 1 && a[x][y + 1] > 1) { cout << "impossible" << endl; continue; }//宝葫芦被弹簧围住
		else if(a[end_x][end_y]==-2){ cout << "impossible" << endl; continue; }//如果放宝葫芦的地方已经有人
		else
			a[end_x][end_y] = -1;//设定宝葫芦的位置为-1
		if (a[dl[0].x][dl[0].y] == -1) { cout << "impossible" << endl; continue; }
		while (qu.size() != 0)
		{
			x = qu.front().x;
			y = qu.front().y;
			
			dl[0].x = qu.front().x - 1;//UP
			dl[0].y = qu.front().y;
			if (dl[0].x < 1);
			else
			{
				if (a[dl[0].x][dl[0].y] == -2)tag=1;//已经走过了,跳过
				else
				{
					while (a[dl[0].x][dl[0].y] > 0&&tag!=1)//有弹簧  找到最终位置
					{
						p = a[dl[0].x][dl[0].y];//p
						dl[0].x = dl[0].x - p;//跳跃
						if (dl[0].x < 1)//如果遇到墙则为1
						{
							dl[0].x = 1;
							break;
						}
						else;//继续寻找
					}//已经找到最终位置并且判断这个位置
					if (dl[0].x < 1)dl[0].x = 1;
					if (a[dl[0].x][dl[0].y] == -1) { c[dl[0].x][dl[0].y] = c[x][y] + 1; break; }//找到
					if (a[dl[0].x][dl[0].y] == -2);//已经走过了，则退队列
					else//进队列，并且标志走过了
					{
						a[dl[0].x][dl[0].y] = -2;
						qu.push(dl[0]);
						c[dl[0].x][dl[0].y] =c[x][y]+1;
					}//UP
				}
			}
			tag = 0;

			dl[0].x = qu.front().x;//RIGHT		
			dl[0].y = qu.front().y + 1;
			if (dl[0].y >= m);
			else
			{
				if (a[dl[0].x][dl[0].y] == -2)
					tag = 1;//已经走过了，跳过
				else
				{
					while (a[dl[0].x][dl[0].y] > 0 && tag != 1)//有弹簧  找到最终位置
					{
						p = a[dl[0].x][dl[0].y];//p
						dl[0].y = dl[0].y + p;//跳跃
						if (dl[0].y >= m)//如果遇到墙则为1
						{
							dl[0].y = m;
							break;
						}
						else;//继续寻找
					}//已经找到最终位置并且判断这个位置
					if (dl[0].y < 1)dl[0].y = 1;
					if (a[dl[0].x][dl[0].y] == -1) { c[dl[0].x][dl[0].y] = c[x][y] + 1; break; }//找到
					if (a[dl[0].x][dl[0].y] == -2);//已经走过了，则退队列
					else//进队列，并且标志走过了
					{
						a[dl[0].x][dl[0].y] = -2;
						qu.push(dl[0]);
						c[dl[0].x][dl[0].y] = c[x][y] + 1;
					}//RIGHT
				}
			}
			tag = 0;

			dl[0].x = qu.front().x + 1;//DOWN
			dl[0].y = qu.front().y;
			if (dl[0].x >= n);
			else
			{
				if (a[dl[0].x][dl[0].y] == -2)tag = 1;//已经走过了
				else
				{
					while (a[dl[0].x][dl[0].y] > 0 && tag != 1)//有弹簧  找到最终位置
					{
						p = a[dl[0].x][dl[0].y];//p
						dl[0].x = dl[0].x + p;//跳跃
						if (dl[0].x >= n)//如果遇到墙则为1
						{
							dl[0].x = n;
							break;
						}
						else;//继续寻找
					}//已经找到最终位置并且判断这个位置
					if (dl[0].x > n)dl[0].x = n;
					if (a[dl[0].x][dl[0].y] == -1) { c[dl[0].x][dl[0].y] = c[x][y] + 1; break; }//找到
					if (a[dl[0].x][dl[0].y] == -2);//已经走过了，则退队列
					else//进队列，并且标志走过了
					{
						a[dl[0].x][dl[0].y] = -2;
						qu.push(dl[0]);
						c[dl[0].x][dl[0].y] = c[x][y] + 1;
					}//DOWN
				}
			}
			tag = 0;

			dl[0].x = qu.front().x ;//LEFT
			dl[0].y = qu.front().y-1;
			if (dl[0].y < 1);
			else
			{
				if (a[dl[0].x][dl[0].y] == -2)tag = 1;//已经走过了，
				else
				{
					while (a[dl[0].x][dl[0].y] > 0 && tag != 1)//有弹簧  找到最终位置
					{
						p = a[dl[0].x][dl[0].y];//p
						dl[0].y = dl[0].y - p;//跳跃
						if (dl[0].y < 1)//如果遇到墙则为1
						{
							dl[0].y = 1;
							break;
						}
						else;//继续寻找
					}//已经找到最终位置并且判断这个位置
					if (dl[0].y < 1)dl[0].y = 1;
					if (a[dl[0].x][dl[0].y] == -1) { c[dl[0].x][dl[0].y] = c[x][y] + 1; break; }//找到
					if (a[dl[0].x][dl[0].y] == -2);//已经走过了，则退队列
					else//进队列，并且标志走过了
					{
						a[dl[0].x][dl[0].y] = -2;
						qu.push(dl[0]);
						c[dl[0].x][dl[0].y] = c[x][y] + 1;
					}//LEFT
				}
			}
			qu.pop();
			tag = 0;
		}
		if(qu.size()==0)cout << "impossible" << endl; 
		else cout << c[end_x][end_y] << endl;
	}
	return 0;
}