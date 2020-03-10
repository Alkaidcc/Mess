//sumafile.cpp --functions with an array argument 
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
const int SIZE = 60;
int main()
{
char filename[SIZE];
ifstream inFile;                //object for handing file input 
cout << "Enter name of date file : ";
cin.getline(filename,SIZE);
inFile.open(filename);       //associate infile with a file
if (!inFile .is_open ())
{
cout << "could not open the file "<<filename <<endl;
cout <<"program terminating.\n";
exit(EXIT_FAILURE);
}
double value ;
double sum = 0.0;
int count = 0;   // number of items read

inFile >> value ;  //get first value
while (inFile.good())  //while input good and not at eof
{
    ++count;             //one more item read
    sum += value;     //calculate running total
    inFile >>value;   //get next value
}
if (inFile.eof())
std::cout << " end of file reached .\n";
else if (inFile.fail())
std::cout<<"input terminate by date mismatch.\n";
    else 
std::cout <<"Input terminated for unknown reason .\n";
if (count==0)
               std::cout <<"No date processed.\n";
else 
{
std::cout <<"Items read :" <<  count <<endl;
std::cout <<"sum:"<<sum<<endl ;
std::cout << "Average :"<<sum / count << endl;

}
inFile.close();
return 0;

}