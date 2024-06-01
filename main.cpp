///////////////////////////
//
//  Task app v0.1.0
//
//  Ceated by Angel May 2024
//
////////////////////////////

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;


const int MAX_TASKS = 100;
const string FILENAME = "tasks.txt";

class Task
{
    public:
    string title;
    string date;
    string time;
    string description;

    Task() : title(""), date(""), time(""), description("") {}
    Task(string t, string d, string ti, string desc)
        : title(t), date(d), time(ti), description(desc) {}
};

class Scheduler
{
private:
    Task tasks[MAX_TASKS];
    int taskCount;

    void loadTasks()
    {
        ifstream inFile(FILENAME);
        if (!inFile.is_open())
        {
            ofstream outFile(FILENAME);
            outFile.close();
            taskCount = 0;
            return;
        }

        string line;
        taskCount = 0;
        
        while (getline(inFile, line) && taskCount < MAX_TASKS)
        {
            stringstream ss(line);
            getline(ss, tasks[taskCount].title, '|');
            getline(ss, tasks[taskCount].date, '|');
            getline(ss, tasks[taskCount].time, '|');
            getline(ss, tasks[taskCount].description, '|');

            taskCount++;
        }
        inFile.close();
    }


    void saveTasks()
    {
        ofstream outFile(FILENAME);

        if (outFile.is_open())
        {
            for (int i = 0; i < taskCount; ++i)
            {
                outFile << tasks[i].title << "|"
                        << tasks[i].date << "|"
                        << tasks[i].time << "|"
                        << tasks[i].description << endl;
            }
            outFile.close();
        }
    }

public:
    Scheduler() : taskCount(0) {
        loadTasks();
    }

    ~Scheduler()
    {
        saveTasks();
    }

    void addTask() 
    {
        system("cls");

        if (taskCount >= MAX_TASKS)
        {
            system("cls");
            cout << "Task list is full. Cannot add more tasks." << endl << endl;
            return;
        }

        string title, date, time, description;
        cout << "Enter task title: ";
        getline(cin, title);
        cout << "Enter task date (MM-DD-YYYY): ";
        getline(cin, date);
        cout << "Enter task time (HH:MM): ";
        getline(cin, time);
        cout << "Enter task description: ";
        getline(cin, description);

        tasks[taskCount] = Task(title, date, time, description);
        taskCount++;
        system("cls");
        cout << "Task added successfully!" << endl << endl;
    }

    void viewTasks() 
    {
        system("cls");

        if (taskCount == 0)
        {
            cout << "No tasks scheduled." << endl << endl;
            return;
        }

        cout << left << setw(20) << "Title"
             << setw(12) << "Date"
             << setw(8) << "Time"
             << "Description" << endl;
        cout << "-------------------------------------------------------------" << endl;

        for (int i = 0; i < taskCount; ++i)
            cout << left << setw(20) << tasks[i].title
                 << setw(12) << tasks[i].date
                 << setw(8) << tasks[i].time
                 << tasks[i].description << endl;
        
        cout <<"\n\n";
    }

    void deleteTask() 
    {
        system("cls");

        string title;
        cout << "Enter the title of the task to delete: ";
        getline(cin, title);

        int index = -1;
        for (int i = 0; i < taskCount; ++i)
            if (tasks[i].title == title) 
            {
                index = i;
                break;
            }

        if (index != -1) 
        {
            for (int i = index; i < taskCount - 1; ++i)
                tasks[i] = tasks[i + 1];
            
            taskCount--;
            system("cls");
            cout << "Task deleted successfully!" << endl << endl;
        }
        else
        {
            system("cls");
            cout << endl << endl << "Task not found." << endl << endl;
        }
    }
};

void displayMenu(string version)
{
    cout << "Scheduler Menu v" << version << endl << endl;
    cout << "1. Add Task: " << endl;
    cout << "2. View Tasks: " << endl;
    cout << "3. Delete Task: " << endl;
    cout << "4. Exit" << endl << endl;
    cout << "Choose option: ";
}

int main()
{
    Scheduler scheduler;
    int choice;
    string version = "0.1.1";

    while (true)
    {
        displayMenu(version);
        cin >> choice;
        cin.ignore();

        switch (choice) 
        {
        case 1:
            scheduler.addTask();
            break;
        case 2:
            scheduler.viewTasks();
            break;
        case 3:
            scheduler.deleteTask();
            break;
        case 4:
            system("cls");
            cout << "Exiting the application." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    };

    return 0;
}
