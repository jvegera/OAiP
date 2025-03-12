#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <fstream>

struct Train {
    std::string name;
    int number;
    std::string time;
};

void consoleInput(Train*& train);
void fileInput(Train*& train, std::fstream& file);
void sorting(Train*& train);
void change(Train*& train);
void consoleOutput(Train*& train);
void fileOutput(Train*& train, std::fstream& file);

#endif //TRAIN_H