#include <iostream>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <assert.h>
#include <vector>
#include <fstream>
using namespace std;

/*
double cubeVol(double sideL)
{
	double vol;
	assert(sideL>=0);
	
	vol = pow(sideL, 3);
	return vol;
}


int main()
{
	int sideL;
	
	cout << "Enter side length" << endl;
	cin >> sideL;
	
	cout << "The cube volume is: " << cubeVol(sideL) << endl;
	assert(cubeVol(3)==27);
}


int main()
{
	int counter = 0;
	
	do
	{
		counter++;
		cout << counter << endl;
	}
	while (counter < 10);
}

int main()
{
	int counter = 0;
	
	do
	{
		cout << "Enter a number." << endl;;
		cin >> counter;
	}
	while (counter < 0 || counter > 5);
}


int main()
{
	for (int x = 0; x < 10; x++)
	{
		cout << "Counter." << endl;
	}
}

int main()
{
	string name, name2;
	
	cout << "Please enter name." << endl;
	
	cin >> name >> name2;
	cout << endl << "Hello " << name << " " << name2 << "!" << endl;
}
*/

/*
int main()
{
	string name, name2;
	int number = 123;
	string nbr = to_string(number);
	
	cout << to_string(M_PI);
}
*/

/*int main()
{
	string s1 = "racecar";
	string s2 = "tacocat";
	
	string palindrome = "";
	string dummy = "";
	
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		s1[i]
		cout << s1[i];
		palindrome += s1[i];
	}
	cout << endl;
	
	cout << (palindrome == s1) << endl;
}
*/

/*int main()
{
	string s = "Hello World!";
	string m = "ll";
	int matches = 0;
	
	for(int i = 0; i <= s.length() - m.length(); i++)
	{
		cout << s.substr(i, m.length()) << " is this " << m << "?" << endl;
		
		if(s.substr(i, m.length()) == m) matches++;
	}
	
	cout << matches << " matches" << endl;
}*/

/*int main()
{
	double sum = 0;
	int counter = 0;
	double value;
	
	do 
	{
		cin >> value:
		counter++;
		if(value != -1)
		{
			sum += value;
			counter++;
		}
	} while (value != -1);
	
	cout << "The average is: " << sum/counter;
}

int main()
{
	double sum = 0;
	int counter = 0;
	double value;
	
	do 
	{
		cin >> value:
		if(cin.fail() == false)
		{
			sum += value;
			counter++;
		}
	} while (cin.fail() == false);
	
	cout << "The average is: " << sum/counter;
}

int main()
{
	int sum = 0, value = 0;
	while(cin >> value)
	{
		sum += value;
	}
	
	cout << "Sum: " << endl;
}*/

/*int main()
{
	int numbers[] = {8, 9, 7, 6, 4, 5, 2, 3, 1, 0};
	int size = 10;
	
	/*for(int i = 0; i < size; i++)
	
		cout << numbers[i] << " ";
		cout << endl;
	
	
	int min = numbers[0];
	int where = 0;
	
	for(int i = 1; i < size; i++)
	{
		if(min > numbers[i])
		{
			where = i;
			min = numbers[i];
		}
	}
	
	int dummy = numbers[0];
	numbers[0] = numbers[where];
	numbers[where] = dummy;
	
	for(int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
		cout << endl;
	}
}
*/
/*void change(double number[])
{
	number[0] = 1;
	number[1] = 2;
}

int main()
{
	double a[]  = {3.1415, 2};
	
	cout << "a: " << a[0] << endl;
	change(a);
	cout << "a: " << a[0] << endl;
}*/

/*int main()
{
	vector<int> numbers(10);
	
	cout << "Vector size is: " << numbers.size() << endl;
	for(int i = 0; i < 10; i++)
	{
		numbers.pop_back();
	}
	cout << "Vector size is: " << numbers.size() << endl;
}*/

/*int main()
{
	ifstream in_file;
	in_file.open("numbers.txt");
	
	double number;
	
	while(in_file >> number)
	{
		cout << fixed << setprecision(18) << number << endl;
	}
}

/*int main()
{
	ifstream in_file;
	in_file.open("numbers.txt");
	
	char number;
	double pi = 0;
	int digits;
	
	while(in_file >> number)
	{
		if(number != '.')
		{
			pi += (int) (number - 48) / pow(10, digits);
			digits++;
		}
	}
	cout << setprecision(40) << pi;
}

int main()
{
	ifstream in_file;
	in_file.open("random.txt");
	
	char letter;
	string word;
	
	while(in_file >> letter)
	{
		cout << word << " ";
	}
}*/

/*#include <iostream>
using namespace std;

void shiftElements (int* arr1, int n, int k)
{
    if (k < 0)
    {
        cout << "No Shift" << endl;
        return;
    }
    
    for (int j = 1; j <= k%n; j++) // shifts elements k%n times
    {
        int temp=arr1[n-1]; // store last element in temp

        for(int i = n-1; i>0 ;i--)
        {
            arr1[i]=arr1[i-1]; // move all elements to its right except first element

            arr1[0]=temp; // store temp in first element
        }
    }
}*/

/*class CashRegister
{
	private:
	double totalPrice = 0; 
	int numberOfItems = 0;
	
	public:
	double getTotalPrice();		//accessor 
	int getNumberOfItems();		//accessor
	void addItem(double price);	//mutator
	void clear();				//mutator
};

double CashRegister::getTotalPrice()
{
	return totalPrice;
}

int CashRegister::getNumberOfItems()
{
	return numberOfItems;
}

void CashRegister::addItem(double price)
{
	totalPrice +=price;
	numberOfItems++;
}

void CashRegister::clear()
{
	totalPrice = 0;
	numberOfItems = 0;
}

int main()
{
	CashRegister reg;
	reg.addItem(2.00);
	reg.addItem(2.35);
	reg.clear();
	
	cout << "Total Price: " << reg.getTotalPrice() << endl;
	cout << "Total Items: " << reg.getNumberOfItems() << endl;
}*/


/*
int main()
{
	int number = 2;
	int* p_to_int = &number;
	
	*p_to_int += 1;
	
	cout << *p_to_int << endl;
	
	int numbers[] = {1, 2, 3, 4, 5};
	
	cout << *(numbers + 1) << endl; 
	
	//cout << p_to_myclass->get.title() << endl;
}
*/

int main()
{
		
}

class Student
{
    public:
        Student();
        Student(string, double);
        double getGPA();
    
    private:
        string name;
        double gpa;
};

Student::Student()
{
    name = "";
    gpa = 0;
}

Student::Student(string studentName, double studentGPA)
{
    name = studentName;
    gpa = studentGPA;
}

double Student::getGPA()
{
    return gpa;
}

class University
{
    public:
        University();
        University(string);
        void setUniversityName(string);
        double getStudentGPA(int);
        int getNumStudents();
        string getUniversityName();
        
    private:
        string universityName;
        vector<Student> students; 
};

University::University()
{
    universityName= "";
}

University::University(string universityName_in)
{
    universityName = universityName_in;
}

void University::setUniversityName(string universityName_in);
{
    universityName = universityName_in;
}

int University::getUniversityName()
{
    
}


int main()
{
    
}