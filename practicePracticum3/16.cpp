/*
1) Create a class named Temperatures with a default constructor, public methods ReadFile, getMinTemp, and getMinTempDay and private data member 
    temp_values, which is a temperatures array with 7 floating point values and days which is an array of 7 strings.  Use 120.0 as the default values inside temperatures array.

2) The public method ReadFile will read each line from the given filename and store each value into the arrays.  The file is in the following format:

1,33.2
2,30.7 
3,17
4,0

Expected Output : 
getMinTemp:  0
getMinTempDay: Wednesday
The first value (before the comma) represents one of the days of the week as an integer (1 to 7).  The week starts with Sunday. The second value (after the comma) 
    represents a temperature value. 

3) The public method getMinTemp returns the minimum temperature in the dataset as a floating point value. 



4) The public method getMinTempDay returns a string as the day of the week associated with minimum temperature in the data. The day will follow the naming convention as follows:
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday


You only need to write the class definition and any code that is required for that class.  Place all code within the class definition.  Our code will create and test your class.


NOTE: We have provided a function that may make the parsing easier:
int split(string s, char sep, string words[], int max_words);
*/

class Temperatures
{
    private:
    float temp_values[7];
    string days[7];
    
    public:
    Temperatures()
    {
        for(int i = 0; i < 7; i++)
        {
            temp_values[i] = 120.0;
        }
    }
    
    void ReadFile(string fileName)
    {
        ifstream file;
        file.open(fileName);
        string line;
        string tempLine[2];
        int counter = 0;
        
        while(getline(file, line))
        {
            split(line, ',', tempLine, counter);
            
            days[counter] = tempLine[0];
            temp_values[counter] = stof(tempLine[1]);
            
            counter++;
        }
    }
    
    float getMinTemp()
    {
        float min = temp_values[0];
        
        for(int i = 0; i < 7; i++)
        {
            if(temp_values[i] < min)
            {
                min = temp_values[i];
            }
        }
        
        return min;
    }
    
    string getMinTempDay()
    {
        float min = 1000000;
        int id;
        string day;
        
        for(int i = 0; i < 7; i++)
        {
            if(temp_values[i] < min)
            {
                min = temp_values[i];
                id = i;
            }
        }
        
        int num = stoi(days[id]);
    
    
        switch(num)
        {
            case 1:
                day = "Sunday";
                break;
                
            case 2:
                day = "Monday";
                break;
                
            case 3:
                day = "Tuesday";
                break;
                
            case 4:
                day = "Wednesday";
                break;
                
            case 5:
                day = "Thursday";
                break;
                
            case 6:
                day = "Friday";
                break;
                
            default:
                day = "Saturday";
                break;
        }
        return day;
    }
};