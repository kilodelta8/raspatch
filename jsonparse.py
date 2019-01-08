import json


#load json data from text file weather.txt
with open('weather.txt') as json_file:
    parsed_data = json.load(json_file)

    
#save pertinent elements into variables for printing/storing
main = parsed_data['main']
wind_speed = parsed_data['wind']
clouds = parsed_data['clouds']


#need to find a way to clear the weatherparsed.txt before proceeding


#output data to text file for main c++ to read in as variables
with open('weatherparsed.txt', 'w') as output:
    output.write(str(main['temp']))
    output.write('\n')
    output.write(str(wind_speed['speed']))
    output.write('\n')
    output.write(str(clouds['all']))
    output.write('\n')
    output.write(str(parsed_data['visibility']))


