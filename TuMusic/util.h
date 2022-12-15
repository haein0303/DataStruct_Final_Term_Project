#pragma once


enum Sorting {
	S_US,
	S_UK,
	S_DE,
	S_FR,
	S_CA,
	S_AU, 
	S_RANK,
	S_VIEWS,
	SORTING_COUNT
};

enum COUNTRY {
	US,
	UK,
	DE,
	FR,
	CA,
	AU,
	COUNTRY_COUNT
};

int calcRank(int sort, const MusicData& data);