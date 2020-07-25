class Players
{
    private:
    float salaries[50];
    string names[50];
    int salaryArrSize;
    int nameArrSize;
    
    public:
    Players();
    Players(float[], string[]);
    float MaxSalary();
    string MaxSalaryName();
    void ReadFile(string);
};

Players::Players()
{
    salaryArrSize = 50;
    nameArrSize = 50;
    for(int i = 0; i < salaryArrSize; i++)
    {
        salaries[i] = -1.0;
    }
    
    for(int j = 0; j < nameArrSize; j++)
    {
        names[j] = "";
    }
}

float Players::MaxSalary()
{
    float maxSalary = 0.0;
    
    for(int i = 0; i < salaryArrSize; i++)
    {
        if(salaries[i] > maxSalary)
        {
            maxSalary = salaries[i];
        }
    }
    
    return maxSalary;
}

string Players::MaxSalaryName()
{
    float maxSalary = 0.0;
    int maxSalaryIndex = 0;
    
    for(int i = 0; i < salaryArrSize; i++)
    {
        if(salaries[i] > maxSalary)
        {
            maxSalaryIndex = i;
        }
    }
    
    return names[maxSalaryIndex];
}

void Players::ReadFile(string fileName)
{
    int lineCounter = 0;
    char delimiter = ',';
    string splitArr[2];
    string lines;
    ifstream inputFile;
    inputFile.open(fileName);
    
    if(inputFile.is_open())
    {
        while(getline(inputFile, lines) && lineCounter < salaryArrSize)
        {
            if(lines == "")
            {
                lines = "";
            }
            
            else
            {
                split(lines, ',', splitArr, 2);
                
                names[lineCounter] = splitArr[0];
                salaries[lineCounter] = stof(splitArr[1]);
                
                lineCounter++;
            }
        }
    }
    inputFile.close();
}