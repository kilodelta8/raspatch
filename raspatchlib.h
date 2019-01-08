/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   raspatchlib.h
 * Author: kd8
 *
 * Created on January 8, 2019, 3:46 PM
 */

#ifndef RASPATCHLIB_H
#define RASPATCHLIB_H
#include <iostream>




/*<<<------------------------------------------------------------------------------>>>*/
//required for curl to operate(**>Called by curlGetWeather()<**)
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

//sets up a curl object and fetches the weather data in JSON format
void curlGetWeather(void);




/*<<<------------------------------------------------------------------------------->>>*/
//called by temperature(), windSpeed(), overcast(), and visibility() to fetch stored weather data
std::string ReadNthLine(const std::string& filename, int n);

//returns temperature as an int
int temperature(void);

//returns windspeed
int windSpeed(void);

//returns overcast(taken as a percent, given as int)
int overcast(void);

//returns visibility, need to define how they get this number
int visibility(void);



/*<<<---------------------------------------------------------------------------------->>>*/
//returns the date and time as a string
std::string time();
//logs to a text file
void log(std::ofstream &outFile, std::string data);


#endif /* RASPATCHLIB_H */

