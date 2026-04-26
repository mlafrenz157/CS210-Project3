// Project Three.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency;

public:
    void LoadData() {       // Read input file and count frequency of each item
        ifstream inFS("CS210_Project_Three_Input_File.txt");
        string item;

        while (inFS >> item) {
            itemFrequency[item]++;
        }

        inFS.close();
    }

    void WriteBackupFile() {        // Save frequency data to frequency.dat for backup
        ofstream outFS("frequency.dat");

        for (auto& pair : itemFrequency) {
            outFS << pair.first << " " << pair.second << endl;
        }

        outFS.close();
    }

    int GetItemFrequency(string item) {     // Return frequency of a specific item, or 0 if not found
        if (itemFrequency.count(item)) {
            return itemFrequency[item];
        }
        return 0;
    }

    void PrintAllFrequencies() {
        for (auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    void PrintHistogram() {     // Print histogram using '*' to represent frequency
        for (auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main() {
    ItemTracker tracker;
    tracker.LoadData();
    tracker.WriteBackupFile();

    int choice = 0;

    while (choice != 4) {       // Loop until user chooses to exit
        cout << "\nMenu\n";
        cout << "1. Search item frequency\n";
        cout << "2. Print all item frequencies\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            cout << "Enter item name: ";
            cin >> item;
            cout << item << " appears " << tracker.GetItemFrequency(item) << " times\n";
        }
        else if (choice == 2) {
            tracker.PrintAllFrequencies();
        }
        else if (choice == 3) {
            tracker.PrintHistogram();
        }
        else if (choice == 4) {
            cout << "Exiting program\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}