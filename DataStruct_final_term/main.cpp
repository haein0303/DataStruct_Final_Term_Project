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

    //MusicData ����ü�迭[�÷����鼭 �����ְ� vector];
    //MusicData data[200];
    


	char key = 0;//�����ݷ��� �������� �ᵵ ������ �����
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
		if (key == 0xE0 || key == 0)   //�Է¹��� ���� Ȯ��Ű �̸�
			key = _getch();            //�ѹ��� �Է��� �޴´�.
		

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
        cout << "���� �ε� ����" << endl;
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
        printf("����(1: �����߰�, 2: �������, 3: �����Ϻ���) : ");
        scanf(" %d", &select);
        switch (select) {
        case 1:
            printf("�߰��� �뷡������ �Է��Ͻÿ�: "); 
            scanf("%s", song);
            int i;
            for (i = 0;i < 200;i++) {
                if (strcmp(song,v_data[i].name)) {//�뷡����Ʈ ���ϱ�
                    strcpy(tmp.name, song);
                    dinsert(head, tmp);
                    printf("%s��(��) �����Ͽ� �߰��Ǿ����ϴ�.\n", &song);
                    break;
                }
            }
            if(i==200)
                printf("%s��(��) �뷡����Ʈ�� �����ϴ�.\n", &song);
            break;
        case 2:
            do {
                current = head->rlink;
                print_dlist1(head);
                printf("\n��ɾ �Է��Ͻÿ�(<, >, q): ");
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
            while (getchar() != '\n'); //�߸��Է��ϸ� ���� ����
            printf("�ɼ��� �߸� �����ϼ̽��ϴ�.\n");
            break;
        }        
    }
    free(head);
}

