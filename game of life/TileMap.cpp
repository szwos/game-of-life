#include "TileMap.h"
#include "TextureManager.h"
#include <iostream>


TileMap::TileMap()
{
	panel = TextureManager::LoadTexture("assets//img//panel.png");


	
	for (int row = 0; row < size_x; row++)
	{
		for (int column = 0; column < size_y; column++)
		{
			map[row][column] = 0;
		}
	}

	 
	//TODO figure editor??, loading figures from files 
	src.x = src.y = 0; 
	src.w = dest.w = 10;
	src.h = dest.h = 10;

	dest.x = dest.y = 0;

	  //gosper glider gun
	
	newMap[4 + 1][0 + 1] = 1;
	newMap[5 + 1][0 + 1] = 1;
	newMap[4 + 1][1 + 1] = 1;
	newMap[5 + 1][1 + 1] = 1;
	newMap[4 + 1][10 + 1] = 1;
	newMap[5 + 1][10 + 1] = 1;
	newMap[6 + 1][10 + 1] = 1;
	newMap[3 + 1][11 + 1] = 1;
	newMap[7 + 1][11 + 1] = 1;
	newMap[2 + 1][12 + 1] = 1;
	newMap[8 + 1][12 + 1] = 1;
	newMap[2 + 1][13 + 1] = 1;
	newMap[8 + 1][13 + 1] = 1;
	newMap[5 + 1][14 + 1] = 1;
	newMap[3 + 1][15 + 1] = 1;
	newMap[7 + 1][15 + 1] = 1;
	newMap[4 + 1][16 + 1] = 1;
	newMap[5 + 1][16 + 1] = 1;
	newMap[6 + 1][16 + 1] = 1;
	newMap[5 + 1][17 + 1] = 1;
	newMap[4 + 1][20 + 1] = 1;
	newMap[3 + 1][20 + 1] = 1;
	newMap[2 + 1][20 + 1] = 1;
	newMap[4 + 1][21 + 1] = 1;
	newMap[3 + 1][21 + 1] = 1;
	newMap[2 + 1][21 + 1] = 1;
	newMap[1 + 1][22 + 1] = 1;
	newMap[5 + 1][22 + 1] = 1;
	newMap[0 + 1][24 + 1] = 1;
	newMap[1 + 1][24 + 1] = 1;
	newMap[5 + 1][24 + 1] = 1;
	newMap[6 + 1][24 + 1] = 1;
	newMap[2 + 1][34 + 1] = 1;
	newMap[3 + 1][34 + 1] = 1;
	newMap[2 + 1][35 + 1] = 1;
	newMap[3 + 1][35 + 1] = 1;
	

	newMap[40][20] = 1;
	newMap[41][20] = 1;
	newMap[41][21] = 1;
	newMap[40][21] = 1;



	/*
	newMap[20][20] = 1;
	newMap[20][21] = 1;
	newMap[20][22] = 1;
	newMap[20][23] = 1;
	newMap[20][24] = 1;
	newMap[20][25] = 1;
	newMap[20][26] = 1;
	newMap[20][27] = 1;
	newMap[20][29] = 1;
	newMap[20][30] = 1;
	newMap[20][31] = 1;
	newMap[20][32] = 1;
	newMap[20][33] = 1;
	newMap[20][37] = 1;
	newMap[20][38] = 1;
	newMap[20][39] = 1;
	newMap[20][46] = 1;
	newMap[20][47] = 1;
	newMap[20][48] = 1;
	newMap[20][49] = 1;
	newMap[20][50] = 1;
	newMap[20][51] = 1;
	newMap[20][52] = 1;
	newMap[20][54] = 1;
	newMap[20][55] = 1;
	newMap[20][56] = 1;
	newMap[20][57] = 1;
	newMap[20][58] = 1;
	*/


	//TODO a system that let's you pause simulation and create figures by clicking mouse on screen, also templates with pre built figures






	printf("sasiedzi [20][21]: %i]", neighbours(20, 21));



	newMap[size_y-1][size_x-1] = 1;

	printf("size_x: %i size_y: %i\n", size_x, size_y);

	for (int row = 0; row < size_y; row++)
	{
		for (int column = 0; column < size_x; column++)
		{
			printf("%i ", newMap[row][column]);
		}
		printf("\n");
	}





	UpdateMap();
	//printf("sasiedzi [20][21]: %i\n", neighbours(20, 21));
	
	printf("tablica sasiadow: \n");
	for (int row = 0; row < size_y; row++)
	{
		for (int column = 0; column < size_x; column++)
		{
			printf("%i ", neighbours(row, column));
		}
		printf("\n");
	}


}


int TileMap::neighbours(int row, int column)
{
	int count = 0;
	
	//* 0
	//0 0
	if (row == 0 && column == 0)
	{
		count = map[row+1][column] + map[row][column + 1] + map[row + 1][column + 1];
		return count;
	}

	//0 * 0
	//0 0 0
	if (row == 0)
	{
		count = map[row][column - 1] + map[row][column + 1] + map[row + 1][column - 1] + map[row + 1][column] + map[row + 1][column + 1];
		return count;
	}


	//0 0
	//* 0
	//0 0
	if (column == 0)
	{
		count = map[row - 1][column] + map[row - 1][column + 1] + map[row][column + 1] + map[row + 1][column] + map[row + 1][column];
		return count;
	}

	
	//0 0 0
	//0 * 0
	//0 0 0
	count = map[row - 1][column - 1] + map[row - 1][column] + map[row - 1][column + 1] + map[row][column - 1] + map[row][column + 1] + map[row + 1][column - 1] + map[row + 1][column] + map[row + 1][column + 1];
	return count;
}


void TileMap::LoadMap()
{
	for (int row = 0; row < size_y; row++)
	{
		for (int column = 0; column < size_x; column++)
		{

			if (neighbours(row, column)  < 2)
				newMap[row][column] = 0;

			if ((neighbours(row, column) == 2 || neighbours(row, column) == 3) && map[row][column] == 1)
				newMap[row][column] = 1;


			if (neighbours(row, column) > 3)
				newMap[row][column] = 0;

			if (neighbours(row, column) == 3 && map[row][column] == 0)
				newMap[row][column] = 1;


		}
	}
}

void TileMap::UpdateMap()
{
	for (int i = 0; i < size_y; i++)
	{
		for (int j = 0; j < size_x; j++)
		{
			map[i][j] = newMap[i][j];
		}
	}
}


void TileMap::DrawMap()
{
	int type = 0;
	
	for (int row = 0; row < size_y; row++)
	{
		for (int column = 0; column < size_x; column++)
		{
			type = newMap[row][column];
			dest.x = column * 10;
			dest.y = row * 10;

			if (type == 1)
				TextureManager::Draw(panel, src, dest);
				
		}
	}




}
