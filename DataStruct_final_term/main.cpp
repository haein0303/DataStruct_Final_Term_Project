#include "stack.h"
#include "stdafx.h"
#include "UI.h"
#include "priorityQueue.h"
#include "deque.h"
#include "LinkedList.h"

using namespace std;


extern DListNode* current;


vector<string> csv_read_row(istream& in, char delimiter);
void FileLoading(istream& in,vector<MusicData> &data);
int listTest();

vector<MusicData> v_data;

int main() {   
    
    
	ifstream file("Top200Chart.csv");	
	
    FileLoading(file, v_data);

    cout << v_data.size() << endl;

    for (MusicData a : v_data) {
        cout << a.rank << " : " << a.singer << " : " << a.name << endl;
    }

    //MusicData 구조체배열[늘려가면서 쓸수있게 vector];
    //MusicData data[200];
    


	char key = 0;//세미콜론은 여러개를 써도 문제가 없어요
    int UI_num = 0;
    int _i_ingame_selected = 1;
    int viewcounter = 0;
    while (0) {
        
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
                printf("%d. %s - %s \n", v_data[i].rank + 1, v_data[i].name, v_data[i].singer);
            }

            switch (key)
            {
            case KEY_UP:
                if (v_data.size() > (viewcounter + 10)) {
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
    listTest();
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

int listTest()
{
    
    char ch;
    char song[128]; 
    int select;
    element tmp;
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head);
    while (1) {
        printf("할일(1: 음악추가, 2: 음악재생, 3: 재생목록보기) : ");
        scanf(" %d", &select);
        switch (select) {
        case 1:
            printf("추가할 노래제목을 입력하시오: "); 
            scanf("%s", song);
            int i;
            for (i = 0;i < 200;i++) {
                if (strcmp(song,v_data[i].name)) {//노래리스트 비교하기
                    strcpy(tmp.name, song);
                    dinsert(head, tmp);
                    printf("%s이(가) 재생목록에 추가되었습니다.\n", &song);
                    break;
                }
            }
            if(i==200)
                printf("%s이(가) 노래리스트에 없습니다.\n", &song);
            break;
        case 2:
            do {
                current = head->rlink;
                print_dlist1(head);
                printf("\n명령어를 입력하시오(<, >, q): ");
                ch = getchar();
                if (ch == '<') {
                    current = current->llink;
                    if (current == head)
                        current = current->llink;
                }
                else if (ch == '>') {
                    current = current->rlink;
                    if (current == head)
                        current = current->rlink;
                }
                print_dlist1(head);
                getchar();
            } while (ch != 'q');
            break;
        case 3:
            current = head->rlink;
            print_dlist2(head);
            break;
        default:
            while (getchar() != '\n'); //잘못입력하면 버퍼 빼줘
            printf("옵션을 잘못 선택하셨습니다.\n");
            break;
        }        
    }
    free(head);
}

