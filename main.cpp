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
using namespace std;


const int MAX_TASKS = 100;

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

public:
    Scheduler() : taskCount(0) {}

    void addTask() 
    {
        if (taskCount >= MAX_TASKS)
        {
            cout << "Task list is full. Cannot add more tasks." << endl;
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
        cout << "Task added successfully!" << endl;
        for (int i = 0; i < 10; ++i)
            cout << endl;
    }

    void viewTasks() 
    {
        if (taskCount == 0)
        {
            cout << "No tasks scheduled." << endl << endl;
            return;
        }

        cout << left << setw(20) << "Title"
             << setw(12) << "Date"
             << setw(8) << "Time"
             << "Description" << endl;
        cout << "-------------------------------------------------------------\n";

        for (int i = 0; i < taskCount; ++i)
            cout << left << setw(20) << tasks[i].title
                 << setw(12) << tasks[i].date
                 << setw(8) << tasks[i].time
                 << tasks[i].description << endl;
        for (int i = 0; i < 10; ++i)
            cout << endl;
    }

    void deleteTask() 
    {
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
            cout << "Task deleted successfully!" << endl;
            for (int i = 0; i < 10; ++i)
                cout << endl;
        }
        else
            cout << "Task not found." << endl;
        for (int i = 0; i < 10; ++i)
            cout << endl;
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
    string version = "0.1.0";

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
            cout << "Exiting the application." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    };

    return 0;
}
