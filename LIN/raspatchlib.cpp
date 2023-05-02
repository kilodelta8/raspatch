/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

//#include <cstdlib>
#include <curl/curl.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <time.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <stdio.h>


static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}


void curlGetWeather()
{
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
    std::ofstream data;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "api.openweathermap.org/data/2.5/weather?zip=38103,us&units=imperial&appid=0154f6e7aa7d9e10d378fc5e71f7647b");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);//<------must be called after curl_easy_init()
        data.open("/home/kd8/cpp/weatherdata/weather.json", std::ios::trunc);
        data << readBuffer;
        data.close();
    }
}


/*<<<---------------------------------weatherReadFromTxt--------------------------------->>>*/
//reads nth line of the formatted weather text file
std::string ReadNthLine(const std::string& filename, int n)
{
    std::ifstream in(filename.c_str());
    std::string s;
    for (int i = 0; i < n; ++i)
    {
        std::getline(in, s);
    }
    std::getline(in, s);
    return s;
}

//returns the temperature as a double
int temperature(void)
{
    std::string::size_type sz;
    std::string test = ReadNthLine("/home/kd8/cpp/weatherdata/weatherparsed.txt",  0);
    int temperature = stoi(test, &sz);
    return temperature;
}

//returns wind speed as a double
int windSpeed(void)
{
    std::string::size_type sz;
    std::string test = ReadNthLine("/home/kd8/cpp/weatherdata/weatherparsed.txt",  1);
    int windSpeed = std::stoi(test, &sz);
    return windSpeed;    
}

//returns overcast as an int (read from a percentage)
int overcast(void)
{
    std::string::size_type sz;
    std::string test = ReadNthLine("/home/kd8/cpp/weatherdata/weatherparsed.txt",  2);
    int overcast = std::stoi(test, &sz);
    return overcast;
}

//returns visibility(not sure how they get the number) as an int
int visibility(void)
{
    std::string::size_type sz;
    std::string test = ReadNthLine("/home/kd8/cpp/weatherdata/weatherparsed.txt",  3);
    int vis = std::stoi(test, &sz);
    return vis;
}



/*<<<-----------------------------------logger-------------------------------------------->>>*/
//This functions gets the current time and returns it as a string
std::string time()
{
    // declaring argument of time() 
    time_t my_time = time(NULL); 
    // ctime() used to give the present time 
    std::string time = ctime(&my_time); 
    return time;
}

//log() takes the OFSTREAM object and a string as an argument and appends both to
//a text file specified in the function.  It also calls the time() function and adds
//the date and time the log was made to the file.
void log(std::ofstream &outFile, std::string data)
{
    //dont forget to create the file object in main
    outFile.open("/home/kd8/cpp/weatherdata/log.txt", std::ios::app);
    //check to make sure the file has opened correctly
    if (!outFile.is_open())
    {
        std::cout << "Log() Failed to open file...\n";//<----let you know via console
    }
    else if (outFile.is_open())
    {
        outFile << time() << data << std::endl; //<------log the data to the file
    }
    //close the file
    outFile.close();
}
