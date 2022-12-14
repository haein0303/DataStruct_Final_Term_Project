#pragma once


//std h
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

//stl h
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <format>

//win h
#include <conio.h>
#include <Windows.h>

typedef struct MusicData {
    char name[128];
    char singer[128];
    char month[128];
    float evenue = 0;
    int us_rank = 0;
    int uk_rank = 0;
    int de_rank = 0;
    int fr_rank = 0;
    int ca_rank = 0;
    int au_rank = 0;
    int view_count = 0;
}element;

//BASIC UI를 제외한 나머지 UI의 번호들입니다.
enum UI {
    UI_loading,
	UI_rank,
	UI_counter //마지막 enum 값을 활용해서 전체 갯수를 쉽게 구할 수 있습니다.
};

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ENTER 13
#define KEY_ESC 27

using namespace std;