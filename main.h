#pragma once
#include "game.h"
#include <iostream>
#include <fstream>
#include <algorithm>


void parse(int& N, int& R, int& E)
{
	std::ifstream cFile ("config.txt");
    if (cFile.is_open())
    {
        std::string line;
        while(getline(cFile, line)){
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                                 line.end());
            if(line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            if (name == "N")
            	N = std::stoi( value );
            if (name == "R")
            	R = std::stoi( value );
            if (name == "E")
            	E = std::stoi( value );
        }
        
    }
    else {
        std::cerr << "Couldn't open config file for reading.\n Using default values.";
    }
}