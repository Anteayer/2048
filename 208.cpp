#include <iostream>
#include <cstring>
#include <ctime>
#include <windows.h>
#include <cstdlib>
#include <conio.h>

using namespace std;


int GameMap[4][4],score = 0;
int flag[4][4],tot = 0;
int special = 0;
void PrintGame()
{
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<=3;j++)
		{
			cout<<GameMap[i][j]<<"\t";
		}
		cout<<endl<<endl;
	}
	cout<<"Your Score is:"<<score<<endl;
}

int GetPositionNumber()
{
	return rand() % 4;
}

int GetGameNumber()
{
	int res[] = {2,4};
	return res[rand() % 2];
}

void ExchangeGameMap()
{
	int x = GetPositionNumber();
	int y = GetPositionNumber();
	if(flag[x][y]){
		ExchangeGameMap();
	}else{
		GameMap[x][y] = GetGameNumber();
		flag[x][y] = 1;
		return;
	}
}

void FlagOptions()
{
	if(tot == 16)
	{
		cout<<"GameOver";
		return;
	}
	tot = 0;
	memset(flag,0,sizeof(flag));
	for(int i=0;i<=3;i++)
	{
		for(int j=0;j<=3;j++)
		{
			if(GameMap[i][j])
			{
					flag[i][j] = 1;
					tot++;
			}
		}
	}
}

void UpOptions()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=0;j<=3;j++)
		{
			if(GameMap[i-1][j] == 0 && GameMap[i][j])
			{
				GameMap[i-1][j] = GameMap[i][j];
				GameMap[i][j] = 0;
				special = 1;
			}
		}
	}
}

void DownOptions()
{
	for(int i=2;i>=0;i--)
	{
		for(int j=0;j<=3;j++)
		{
			if(GameMap[i+1][j] == 0 && GameMap[i][j])
			{
				GameMap[i+1][j] = GameMap[i][j];
				GameMap[i][j] = 0;
				special = 1;
			}
		}
	}
}

void LeftOptions()
{
	for(int i=0;i<=3;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(GameMap[i][j-1] == 0 && GameMap[i][j])
			{
				GameMap[i][j-1] = GameMap[i][j];
				GameMap[i][j] = 0;
				special = 1;
			}
		}
	}
}

void RightOptions()
{
	for(int i=0;i<=3;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(GameMap[i][j+1] == 0 && GameMap[i][j])
			{
				GameMap[i][j+1] = GameMap[i][j];
				GameMap[i][j] = 0;
				special = 1;
			}
		}
	}
}

void MainOptions()
{
	while(1)
	{
		system("cls");
		PrintGame();
		int first = getch();
		if(first == 224)
		{	
			int key = getch();
			if(key == 72){//up
				int lt = 0;
				for(int i=1;i<=4;i++)	UpOptions();
				for(int i=0;i<=3;i++)
				{
					if(GameMap[0][i] == GameMap[1][i] && (GameMap[0][i] !=0 && GameMap[1][i] != 0))
					{
						GameMap[0][i]*=2;
						GameMap[1][i] = 0;						
						score+=GameMap[0][i];
						lt = 1;
					}
					else if(GameMap[1][i] == GameMap[2][i] && GameMap[2][i] != GameMap[3][i] && (GameMap[1][i] !=0 && GameMap[2][i] != 0))
					{
						GameMap[1][i]*=2;
						GameMap[2][i] = 0;
						score+=GameMap[1][i];
						lt = 1;
					}
					if(GameMap[2][i] == GameMap[3][i] && (GameMap[2][i] !=0 && GameMap[3][i] != 0))
					{
						GameMap[2][i]*=2;
						GameMap[3][i] = 0;
						score+=GameMap[2][i];
						lt = 1;
					}
				}

				for(int i=1;i<=4;i++)	UpOptions();
				FlagOptions();
				if(!lt && !special)continue;
				else if(lt || special) ExchangeGameMap(),special = 0;
				system("cls");
				PrintGame();

			}else if(key == 80){//down
				int lt = 0;
					for(int i=1;i<=4;i++)	DownOptions();
					for(int i=0;i<=3;i++)
					{
						if(GameMap[3][i] == GameMap[2][i] && (GameMap[3][i]!=0 &&GameMap[2][i]!=0))
						{
							GameMap[3][i]*=2;
							GameMap[2][i] = 0;
							score+=GameMap[3][i];
							lt = 1;
						}
						else if(GameMap[2][i] == GameMap[1][i] && GameMap[1][i] != GameMap[0][i] && (GameMap[2][i]!=0 &&GameMap[1][i]!=0))
						{
							GameMap[2][i]*=2;
							GameMap[1][i] = 0;
							score+=GameMap[2][i];
							lt = 1;
						}
						if(GameMap[1][i] == GameMap[0][i] && (GameMap[1][i]!=0 && GameMap[0][i]!=0))
						{
							GameMap[1][i]*=2;
							GameMap[0][i] = 0;
							score+=GameMap[i][i];
							lt = 1;
						}
					}

					for(int i=1;i<=4;i++)	DownOptions();
					FlagOptions();
					if(!lt && !special)continue;
					else if(lt || special) ExchangeGameMap(),special = 0;
					system("cls");
					PrintGame();

			}else if(key == 75){//left
				int lt = 0;
					for(int i=1;i<=4;i++) 	LeftOptions();
					for(int i=0;i<=3;i++)
					{
						if(GameMap[i][0] == GameMap[i][1] && (GameMap[i][0])!=0 && GameMap[i][1]!=0)
						{
							GameMap[i][0]*=2;
							GameMap[i][1]=0;
							score+=GameMap[i][0];
							lt = 1;
						}
						else if(GameMap[i][1] == GameMap[i][2] && GameMap[i][2] != GameMap[i][3] && (GameMap[i][1])!=0 && GameMap[i][2]!=0)
						{
							GameMap[i][1]*=2;
							GameMap[i][2]=0;
							score+=GameMap[i][1];
							lt = 1;
						}
						if(GameMap[i][2] == GameMap[i][3] && (GameMap[i][2])!=0 && GameMap[i][3]!=0)
						{
							GameMap[i][2]*=2;
							GameMap[i][3]=0;
							score+=GameMap[i][2];
							lt = 1;
						}
					}

					for(int i=1;i<=4;i++)	LeftOptions();
					FlagOptions();
					if(!lt && !special)continue;
					else if(lt || special) ExchangeGameMap(),special = 0;
					system("cls");
					PrintGame();

			}else if(key == 77){//right
				int lt = 0;
					for(int i=1;i<=4;i++) RightOptions();
					for(int i=0;i<=3;i++)
					{
						if(GameMap[i][3] == GameMap[i][2] && (GameMap[i][3])!=0 && GameMap[i][2]!=0)
						{
							GameMap[i][3]*=2;
							GameMap[i][2]=0;
							score+=GameMap[i][3];
							lt = 1;
						}
						else if(GameMap[i][2] == GameMap[i][1] && GameMap[i][1] != GameMap[i][0] && (GameMap[i][2])!=0 && GameMap[i][1]!=0)
						{
							GameMap[i][2]*=2;
							GameMap[i][1]=0;
							score+=GameMap[i][2];
							lt = 1;
						}
						if(GameMap[i][1] == GameMap[i][0] && (GameMap[i][1])!=0 && GameMap[i][0]!=0)
						{
							GameMap[i][1]*=2;
							GameMap[i][0]=0;
							score+=GameMap[i][1];
							lt = 1;
						}
					}
					for(int i=1;i<=4;i++)	RightOptions();
					FlagOptions();
					if(!lt && !special)continue;
					else if(lt || special) ExchangeGameMap(),special = 0;
					system("cls");
					PrintGame();
			}	
		}
	}
}

int main()
{
	srand((unsigned)time(NULL)); 
	memset(GameMap,0,sizeof(GameMap));
	memset(flag,0,sizeof(flag));
	ExchangeGameMap();
	ExchangeGameMap();
	MainOptions();
	system("pause");
	return 0;
}