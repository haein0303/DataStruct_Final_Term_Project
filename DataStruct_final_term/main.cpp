

#pragma _CRT_SECURE_NO_WARNINGS

#include "stack.h"
#include "stdafx.h"
#include "UI.h"
#include "priorityQueue.h"

using namespace std;

vector<string> csv_read_row(istream& in, char delimiter);
void FileLoading(istream& in,vector<MusicData> &data);

int main() {

    
    
    vector<MusicData> data;
	ifstream file("Top200Chart.csv");	
	
    FileLoading(file, data);

    cout << data.size() << endl;

    for (MusicData a : data) {
        cout << a.rank << " : " << a.singer << " : " << a.name << endl;
    }

	
	char key = 0;//세미콜론은 여러개를 써도 문제가 없어요
    int UI_num = 0;
    int _i_ingame_selected = 1;
    int viewcounter = 0;
    while (1) {
        
        ClearUI();
        switch (UI_num)
        {

        case UINUM::UI_base:
            BaseUI(_i_ingame_selected);
            switch (key)
            {
            case KEY_UP:
                _i_ingame_selected = (_i_ingame_selected + 1) % 3 + 1;
                break;
            case KEY_DOWN:
                _i_ingame_selected = _i_ingame_selected % 3 + 1;
                break;
            case KEY_ENTER:
                UI_num = _i_ingame_selected;
                break;
            default:
                break;
            }
            break;
        case UINUM::UI_list:
            ChartUI_top();
            

            for (int i = viewcounter; i < viewcounter+10; i++)
            {
                printf("%d. %s - %s \n", data[i].rank + 1, data[i].name, data[i].singer);
            }

            switch (key)
            {
            case KEY_UP:
                if (data.size() > (viewcounter + 10)) {
                    viewcounter++;
                }                
                break;
            case KEY_DOWN:
                if (0 < viewcounter) {
                    viewcounter--;
                }
                break;
            case KEY_ENTER:
                UI_num = _i_ingame_selected;
                break;
            default:
                break;
            }

            break;

        }
       
		key = _getch();
		if (key == 0xE0 || key == 0)   //입력받은 값이 확장키 이면
			key = _getch();            //한번더 입력을 받는다.
		

	} 
}


vector<string> csv_read_row(istream& in, char delimiter)
{
    stringstream ss;
    bool inquotes = false;
    vector<string> row;
    while (in)
    {
        char c = in.get();
        if (!inquotes && c == '"') //begin
        {
            inquotes = true;
        }
        else if (inquotes && c == '"') //quotechar
        {
            if (in.peek() == '"')//2 consecutive quotes resolve to 1
            {
                ss << (char)in.get();
            }
            else //endquotechar
            {
                inquotes = false;
            }
        }
        else if (!inquotes && c == delimiter) //end of field
        {
            row.push_back(ss.str());
            ss.str("");
        }
        else if (!inquotes && (c == '\r' || c == '\n'))
        {
            if (in.peek() == '\n') { in.get(); }
            row.push_back(ss.str());
            return row;
        }
        else
        {
            ss << c;
        }
    }
}

void FileLoading(istream& file, vector<MusicData>& data)
{

    if (!file) {
        cout << "파일 로딩 실패" << endl;
        return;
    }

    while (file.good())
    {
        MusicData tmp;
        vector<string> row = csv_read_row(file, ',');
        for (int i = 0, leng = row.size(); i < leng; i++) {
            //cout << "[" << row[i] << "]" << "\t";
            switch (i) {
            case 0:
                tmp.rank = data.size();
                break;
            case 1:
                strcpy_s(tmp.singer, row[i].c_str());
                break;
            case 2:
                strcpy_s(tmp.name, row[i].c_str());
            }
        }
        cout << endl;
        data.push_back(tmp);
    }
} 



