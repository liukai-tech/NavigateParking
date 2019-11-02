#include "mapinfo.h"

MapInfo::MapInfo()
{
    // default value
    for(int i = 0; i < MAP_WIDTH; ++i)
    {
        for(int j = 0; j < MAP_HEIGHT; ++j)
        {
            int index = MAP_WIDTH * j + i;
            if(i == 0 || j == 0 || i == MAP_WIDTH - 1 || j == MAP_HEIGHT - 1)
            {
                map[index] = MapGrid::MG_Wall;
                continue;
            }
            map[index] = MapGrid::MG_None;
        }
    }

    buildLeftPart();
    buildRightPart();
    buildCenterHorizontal();
    buildTopAndBottom();
    buildVerticalRoad();
}

void MapInfo::buildLeftPart()
{
    // build road
    for(int i = 1; i < MAP_HEIGHT - 1; ++i)
    {
        // left main
        for(int j = 0; j < 3; ++j)
        {
            int index = i * MAP_WIDTH + 6 + j;
            map[index] = MapGrid::MG_Road_Left;
        }
        for(int j = 0; j < 3; ++j)
        {
            int index = i * MAP_WIDTH + 9 + j;
            map[index] = MapGrid::MG_Road_Right;
        }
    }
    // build park position
    for(int i = 1; i < MAP_HEIGHT - 1; ++i)
    {
        // left near wall
        for(int j = 0; j  < 5; ++j)
        {
            int index = i * MAP_WIDTH + 1 + j;
            map[index] = MapGrid::MG_ParkPosition;
        }
        // left near road
        for(int j = 0; j < 10; ++j)
        {
            int index = i * MAP_WIDTH + 12 + j;
            map[index] = MapGrid::MG_ParkPosition;
        }
    }
    // left part
    for(int iter = 0; iter < 29; ++iter)
    {
        for(int i = 1; i < MAP_HEIGHT - 1; ++i)
        {
            // road left
            for(int j = 0; j  < 3; ++j)
            {
                int index = i * MAP_WIDTH + (22 + iter * 16) + j;
                map[index] = MapGrid::MG_Road_Left;
            }
            // road right
            for(int j = 0; j  < 3; ++j)
            {
                int index = i * MAP_WIDTH + (25 + iter * 16) + j;
                map[index] = MapGrid::MG_Road_Right;
            }
            // park
            for(int j = 0; j < 10; ++j)
            {
                int index = i * MAP_WIDTH + (28 + iter * 16) + j;
                map[index] = MapGrid::MG_ParkPosition;
            }
        }
    }
}

void MapInfo::buildRightPart()
{
    // build road
    for(int i = 1; i < MAP_HEIGHT - 1; ++i)
    {
        // left main
        for(int j = 0; j < 3; ++j)
        {
            int index = i * MAP_WIDTH + (MAP_WIDTH - 9) - j;
            map[index] = MapGrid::MG_Road_Left;
        }
        for(int j = 0; j < 3; ++j)
        {
            int index = i * MAP_WIDTH + (MAP_WIDTH - 6) - j;
            map[index] = MapGrid::MG_Road_Right;
        }
    }
    // build park position
    for(int i = 1; i < MAP_HEIGHT - 1; ++i)
    {
        // left near wall
        for(int j = 0; j  < 5; ++j)
        {
            int index = i * MAP_WIDTH + (MAP_WIDTH - 1) - j;
            map[index] = MapGrid::MG_ParkPosition;
        }
        // left near road
        for(int j = 0; j < 10; ++j)
        {
            int index = i * MAP_WIDTH + (MAP_WIDTH - 12) - j;
            map[index] = MapGrid::MG_ParkPosition;
        }
    }
    // left part
    for(int iter = 0; iter < 29; ++iter)
    {
        for(int i = 1; i < MAP_HEIGHT - 1; ++i)
        {
            // road left
            for(int j = 0; j  < 3; ++j)
            {
                int index = i * MAP_WIDTH + (MAP_WIDTH - 25 - iter * 16) - j;
                map[index] = MapGrid::MG_Road_Left;
            }
            // road right
            for(int j = 0; j  < 3; ++j)
            {
                int index = i * MAP_WIDTH + (MAP_WIDTH - 22 - iter * 16) - j;
                map[index] = MapGrid::MG_Road_Right;
            }
            // park
            for(int j = 0; j < 10; ++j)
            {
                int index = i * MAP_WIDTH + (MAP_WIDTH - 28 - iter * 16) - j;
                map[index] = MapGrid::MG_ParkPosition;
            }
        }
    }
}

void MapInfo::buildCenterHorizontal()
{
    for(int i = 1; i < MAP_HEIGHT - 1; ++i)
    {
        // left
        for(int j = 0; j  < 5; ++j)
        {
            int index = i * MAP_WIDTH + 486 + j;
            map[index] = MapGrid::MG_Road_Left;
        }
        // right
        for(int j = 0; j < 5; ++j)
        {
            int index = i * MAP_WIDTH + 490 + j;
            map[index] = MapGrid::MG_Road_Right;
        }
        // park
        for(int j = 0; j < 12; ++j)
        {
            int index = i * MAP_WIDTH + 494 + j;
            map[index] = MapGrid::MG_ParkPosition;
        }
        // left
        for(int j = 0; j  < 5; ++j)
        {
            int index = i * MAP_WIDTH + 506 + j;
            map[index] = MapGrid::MG_Road_Left;
        }
        // right
        for(int j = 0; j < 5; ++j)
        {
            int index = i * MAP_WIDTH + 510 + j;
            map[index] = MapGrid::MG_Road_Right;
        }
    }
}

void MapInfo::buildTopAndBottom()
{
    // top
    for(int i = 12; i < MAP_WIDTH - 12; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            int index = (j + 1) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_ParkPosition;
        }
    }
    // bottom
    for(int i = 12; i < MAP_WIDTH - 12; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            int index = (MAP_HEIGHT - j - 1) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_ParkPosition;
        }
    }
}

void MapInfo::buildVerticalRoad()
{
    // top
    for(int i = 12; i < MAP_WIDTH - 12; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int index = (j + 6) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_Road_Left;
        }
        for(int j = 0; j < 3; ++j)
        {
            int index = (j + 9) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_Road_Right;
        }
    }
    // bottom
    for(int i = 12; i < MAP_WIDTH - 12; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            int index = (MAP_HEIGHT - 9 - j) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_Road_Left;
        }
        for(int j = 0; j < 3; ++j)
        {
            int index = (MAP_HEIGHT - 6 - j) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_Road_Right;
        }
    }
    // other road
    for(int iter = 1; iter < 3; ++iter)
    {
        for(int i = 12; i < MAP_WIDTH - 12; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                int index = (iter * 162 + j) * MAP_WIDTH + i;
                map[index] = MapGrid::MG_Road_Left;
            }
            for(int j = 0; j < 3; ++j)
            {
                int index = (iter * 162 + 3 + j) * MAP_WIDTH + i;
                map[index] = MapGrid::MG_Road_Right;
            }
            for(int j = 0; j < 3; ++j)
            {
                int index = (MAP_HEIGHT - iter * 162 - 3 - j) * MAP_WIDTH + i;
                map[index] = MapGrid::MG_Road_Left;
            }
            for(int j = 0; j < 3; ++j)
            {
                int index = (MAP_HEIGHT - iter * 162 - j) * MAP_WIDTH + i;
                map[index] = MapGrid::MG_Road_Right;
            }
        }
    }
    // center
    for(int i = 12; i < MAP_WIDTH - 12; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            int index = (495 + j) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_Road_Left;
        }
        for(int j = 0; j < 5; ++j)
        {
            int index = (500 + j) * MAP_WIDTH + i;
            map[index] = MapGrid::MG_Road_Right;
        }
    }
}