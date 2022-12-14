#include "stdafx.h"
#include "fileLoader.h"

int read_data(const char* filename, vector<MusicData> &data) {

	ifstream file(filename);

    if (!file) {
        cout << "파일 로딩 실패" << endl;
        return 0;
    }

    while (file.good())
    {
        MusicData tmp;
        vector<string> row = csv_read_row(file, ',');
        for (int i = 0, leng = row.size(); i < leng; i++) {
            //cout << "[" << row[i] << "]" << "\t";
            switch (i) {
            case 0: // 발매 년월
                strcpy_s(tmp.month, row[i].c_str());
                break;
            case 2:
                strcpy_s(tmp.singer, row[i].c_str());
                break;
            case 3:
                strcpy_s(tmp.name, row[i].c_str());
                break;
            case 4:
                tmp.evenue = stod(row[i], nullptr);
                break;
            case 5:
                if (row[i][0] != '-') tmp.us_rank = stoi(row[i]);
                break;
            case 6:
                if (row[i][0] != '-') tmp.uk_rank = stoi(row[i]);
                break;
            case 7:
                if (row[i][0] != '-') tmp.de_rank = stoi(row[i]);
                break;
            case 8:
                if (row[i][0] != '-') tmp.fr_rank = stoi(row[i]);
                break;
            case 9:
                if (row[i][0] != '-') tmp.ca_rank = stoi(row[i]);
                break;
            case 10:
                if (row[i][0] != '-') tmp.au_rank = stoi(row[i]);
                break;
            }
        }
        data.push_back(tmp);
    }

    return 1;
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