//
//  main.cpp
//  Student
//
//  Created by Clay Cribbs on 9/4/16.
//  
//

#include <iostream>
#include <vector>
using namespace std;


///Student Structure containing string name, int numClasses, and also a classList array.
struct Student
{
    public:
    string name;
    int numClasses;
    vector<string> classList;
    string addClass;
    
    
    ///Sets info for the Student
    void set_info()
    {
        bool done = false; //User is not done yet
        string choice;
        
        
        //Initial name prompt
        cout << "Enter your name\n";
        getline(cin,name);
        
        ///Classes prompt loops until user is done
        while (!done)
        {
            bool innerDone = false; //innerloop has not run its course yet
            string thisChoice; //thisChoice is the class that user is inputting this loop iteration
            
            cout << "Enter a class name or type 'n' to quit.\n";
            getline(cin,thisChoice);
            
            if (tolower(thisChoice[0])== 'n') //Checks if user wants to 'quit'
            {
                done = true;
            }
            else  // Inner loop starts ask user to add the classes until they are done
            {
                while (!innerDone)
                {
                    
                    addClass = " ";
                    cout << "Add " <<thisChoice<<" to list of Classes? Press 'y' for yes or 'n' for no.\n";
                    getline(cin,addClass); // Confirms user wants to add the typed class
                    
                    
                    // If user wants to add the class it is added to classList
                    if (tolower(addClass[0])=='y')
                    {
                        classList.push_back(thisChoice);
                        numClasses += 1;
                        cout << thisChoice << " added successfully.\n";
                        innerDone = true;
                    } // if user wants to quit then the innerloop is done
                    else if (tolower(addClass[0])=='n')
                    {
                        innerDone = true;
                    }
                    else ///tells user they didnt enter a valid selection, innerloop restarts
                    {
                        cout << "Not a valid input\n";
                    }
                }
            }
        }
    }
    
    string get_name()
    {
        return name;
    }
    
    vector<string> get_classList()
    {
        return classList;
    }

    int get_numClasses()
    {
        return numClasses;
    }
    
    void display_info()
    {
        int x = 0;
        
        cout << "\nStudent: " << name << "\n";
        //Print each Class
        while (x < (classList.size()))
        {
            cout << "Class " << x+1 << ": " << classList.at(x) << "\n";
            x += 1;
        }
        cout << "\nNumber of Classes: " << numClasses << "\n\n";
    }
    
    void clear_info()
    {
            name = "";
            classList.clear();
            numClasses = 0;
            cout << "Student object attributes cleared succesfully.\n\n";
    }
    
    
};


///Main Method drives new student
int main(int argc, const char * argv[])
    {
        bool finished = false; //User is not finished yet
        
        string moreData; // Holds users choice if they want to enter more data 'y' or 'n'
        
        Student myStudent; // Creates Student object, could be refactored into the finished loop if you wanted a new student object
        while (!finished) // ... to be created each iteration.
        {
            cout << "Would you like to enter new student data 'y' or 'n' \n";
            getline(cin, moreData);
            
            if (tolower(moreData[0])=='y') //if they want to enter data set_info is run and then display_info
            {

                myStudent.set_info();
                myStudent.display_info();
                myStudent.clear_info(); // Before starting next student, info is cleared
            }
            else if (tolower(moreData[0])=='n') // If n then clear_info 'finished' and loop exit
            {
                myStudent.display_info(); //Final display of info
                myStudent.clear_info(); //Clears info before exit
                finished = true;
            }
            else{
                cout << "Not a valid input. \n";
            }
        }

        
        return 0;
    }

