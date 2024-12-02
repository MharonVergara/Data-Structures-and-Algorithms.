#include <iostream>

#include <queue>

#include <string>

#include <thread>

#include <chrono>



using namespace std;



class Person {

public:

    string name;

    int ticket_num;



    Person(string name, int ticket_num) : name(name), ticket_num(ticket_num) {}

};



class Queue {

private:

    queue<Person> people;

    int current_num = 1;



public:

    void add(string name) {

        Person person(name, current_num++);

        people.push(person);

        cout << name << " added to the queue with Ticket #00" << person.ticket_num << endl;

        cout << "Queue size: " << people.size() << endl;

    }



    void auto_serve() {

        if (!people.empty()) {

            cout << "\nAfter 1 minute...\n";

            Person front_person = people.front();

            cout << "Serve: " << front_person.name << " received a ticket (Ticket #00" << front_person.ticket_num << ")" << endl;

            people.pop();

            cout << "Queue size: " << people.size() << endl;

            if (!people.empty()) {

                Person next_person = people.front();

                cout << "Next in line: " << next_person.name << " (Ticket #00" << next_person.ticket_num << ")" << endl;

            }

        } else {

            cout << "Queue is empty." << endl;

        }

    }



    bool is_empty() const {

        return people.empty();

    }



    int size() const {

        return people.size();

    }



    void peek() const {

        if (!people.empty()) {

            Person front_person = people.front();

            cout << "Next in line: " << front_person.name << " with Ticket #00" << front_person.ticket_num << endl;

        } else {

            cout << "Queue is empty." << endl;

        }

    }



    int position(string name) const {

        int pos = 1;

        queue<Person> temp = people;



        while (!temp.empty()) {

            Person current_person = temp.front();

            if (current_person.name == name) {

                return pos;

            }

            temp.pop();

            pos++;

        }



        return -1;

    }

};



void show_menu(Queue &q) {

    int choice;

    string name;



    do {

        cout << "\n1. Enqueue a person \n2. Check your position\n3. Exit\n";

        cout << "Choose an option: ";

        cin >> choice;



        switch (choice) {

            case 1:

                cout << "Enter the name: ";

                cin >> name;

                q.add(name);

                break;



            case 2:

                cout << "Enter your name: ";

                cin >> name;

                int pos;

                pos = q.position(name);

                if (pos == -1) {

                    cout << name << " is not in the queue." << endl;

                } else {

                    cout << name << " is currently at position " << pos << " in the queue." << endl;

                }

                break;



            case 3:

                cout << "Exiting..." << endl;

                break;



            default:

                cout << "Invalid choice. Please try again." << endl;

                break;

        }

    } while (choice != 3);

}



void auto_serve_sim(Queue &q) {

    while (true) {

        this_thread::sleep_for(chrono::seconds(60));

        q.auto_serve();

    }

}



int main() {

    Queue q;



    thread auto_serve_thread(auto_serve_sim, ref(q));



    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << endl;



    show_menu(q);



    auto_serve_thread.detach();



    return 0;

}