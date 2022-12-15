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
#include <set>

//win h
#include <conio.h>
#include <Windows.h>

using namespace std;

typedef struct MusicData {
    char name[128];
    char singer[128];
    char month[128];
    float evenue = 0;
    int rank[6];
    int view_count = 0;

    bool operator() (const MusicData& a, const MusicData& b) const {
        string sa(a.name);
        string sb(b.name);
       
        return sa > sb;//char�� �񱳿����ڰ� �������� string ���ø��� Ȱ���ؼ� ���� ���սô�.
    }
    bool operator==(const MusicData& rhs) const {
        return strcmp(name, rhs.name);
    }
    bool operator<(const MusicData& rhs) const {
        string sa(rhs.name);
        string sb(name);

        return sa > sb;//char�� �񱳿����ڰ� �������� string ���ø��� Ȱ���ؼ� ���� ���սô�.
    }
}element;

struct myList {
    int index[128];
    char name[128];
};

//BASIC UI�� ������ ������ UI�� ��ȣ���Դϴ�.
enum UI {
    UI_find,
    UI_rank,
    UI_Mylist,
    UI_recommend,
    UI_makeViewsCount,
	UI_counter //������ enum ���� Ȱ���ؼ� ��ü ������ ���� ���� �� �ֽ��ϴ�.
};

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_RIGHT 77
#define KEY_LEFT 75
#define KEY_ENTER 13
#define KEY_ESC 27

