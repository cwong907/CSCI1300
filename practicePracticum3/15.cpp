/*1) Create a class named Stats with a default constructor, public methods ReadFile, getAvgStringLength, and getLongestString and private data member data, 
    which is a vector of strings, containing all the lines from the file.

2) The public method ReadFile will read each line from the given filename and store each value into the vector.  The file is in the following format:

This is a test string
HelloWorld
Expected Output : 
getAvgStringLength:  15.5
getLongestString:    This is a test string
Each line represents a string in the file.

3) The public method getAvgStringLength returns the average length of all strings read from the file as a floating point value

4) The public method getLongestString returns a string that has the longest length in the data read from the given file. If there is a tie, 
    you should return the last longest string inside the dataset


You only need to write the class definition and any code that is required for that class.  Place all code within the class definition.  Our code will create and test your class.
*/

class Stats
{
    private:
    vector<string> data;
    int dataSize;
    
    public:
    
    void ReadFile(string fileName)
    {
        ifstream file;
        file.open(fileName);
        string line = "";
        int counter = 0;
        
        while(getline(file, line))
        {
            if(line != "")
            {
                data.push_back(line);
                counter++;
            }
        }
    }
    
    float getAvgStringLength()
    {
        float avg;
        int sum = 0;
        int counter = 0;
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].size() != 0)
            {
                sum += data[i].size();
                counter++;
            }
        }
        
        avg = (float)(sum) / counter;
        
        return avg;
    }
    
    string getLongestString()
    {
        int longest = data[0].size();
        int idx;
        
        for(int i = 0; i < data.size(); i++)
        {
            if(data[i].size() >= longest)
            {
                longest = data[i].size();
                idx = i;
            }
        }
        
        return data[idx];
    }
    
};