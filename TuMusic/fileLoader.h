#pragma once

int read_data(const char* filename, std::vector<MusicData>& data);
std::vector<string> csv_read_row(istream& in, char delimiter);
