#pragma once
#include <fstream>
#include <iostream>
class ScoreHandler
{
public:
	ScoreHandler();
	~ScoreHandler();

	int readFile() const;
	void writeFile(const char* score);

private:
	std::ofstream file;
};

