#include <iostream>
#include <string>
using namespace std;

struct Task {
	string task;
	Task* link;
};


int main() {
	int userInput;
	string TaskName;
	Task* head = new Task; //Creating a head node
	head->link = nullptr; // Pointing head node to null 

	Task* nextTask = new Task; // Creating a nextTask node
	nextTask = head; //nextTask now refers to the same node as head

	while (true) {
		cout << "ToDo List Menu: " << endl;
		cout << "1. Add a Task" << endl;
		cout << "2. Remove a Task" << endl;
		cout << "3. Display Tasks" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> userInput;
		cin.ignore();

	switch (userInput) {
		case 1:
			cout << "Enter task description: ";
			getline(cin, nextTask->task); // Take in the user string and put it in the nextTask node
			nextTask->link = new Task; // Create a new node and point to it
			nextTask = nextTask->link; // Make the new node the nextTask node
			nextTask->link = nullptr; // Point that new node to null
			break;
		case 2:
			cout << "Enter task description to remove: ";
			getline(cin, TaskName);

			nextTask = head; //nextTask now refers to the same node as head
			while (nextTask != nullptr) {
				if (nextTask->task == TaskName) { // comparing both the TaskName and the Task String in that node
					delete nextTask; // Deletes the node if they match
				}
				else {
					cout << "No such task exists" << endl;
				}
				nextTask = nextTask->link; // nextTask points to the next node
			}
			break;
		case 3:
			nextTask = head; //nextTask now refers to the same node as head
			while (nextTask != nullptr) {
				cout << nextTask->task << endl; // displays task the task the node contains
				nextTask = nextTask->link; // points to the next node

			}
			break;
		case 4:
			cout << "GoodBye" << endl;
			exit(0);
		}
	}
}