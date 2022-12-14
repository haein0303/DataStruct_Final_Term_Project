#pragma once

#define _CRT_SECURE_NO_WARNINGS
//기본 헤더
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


//stl 헤더
#include <string>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>

//윈도우즈 헤더
#include <Windows.h>
#include <conio.h>


typedef struct MusicData {
    int rank = -1;
    char name[128];
    char singer[128];
    int key = 0;
}element;



#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ENTER 13

enum UINUM {
	UI_base,
	UI_list
};