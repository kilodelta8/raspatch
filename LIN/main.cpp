/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: kd8
 *
 * Created on January 8, 2019, 3:45 PM
 */
#include <iostream>
#include <cstdlib>
#include "raspatchlib.h"
#include <string>
#include <cstdlib>
/*
 * 
 */
int main(int argc, char** argv) {
    
    //curlGetWeather();

    std::string lang = "python ";
    std::string scrpt = "/home/kd8/cpp/Raspatch/extras/workingTests/jsonparse.py";
    std::string proc = lang + scrpt;
    int x = system(proc.c_str());
    
    std::cout << x << std::endl;
    
    
    return 0;
}

