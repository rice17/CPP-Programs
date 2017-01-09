//Application of priority queue to solve the problem of hospital queues
//Implementing a queue as a singly linked list

#include <iostream>

using namespace std;

class pqueue
{
    struct node
    {
        int patient_id;
        string name;
        node *next;
    };
    node *queue[3];       //start of queue
    node *e[3];           //rear of queue
public:
    pqueue()
    {
        queue[0] = NULL;       //highest priority
        queue[1] = NULL;
        queue[2] = NULL;       //lowest priority
    }
    void enqueue()
    {
        cout << "\nEnter priority [1(high) - 3 (low)]: ";
        int p;
        cin >> p;
        if (!p || (p>>2 != 0))  //Evaluates to true if p is not in [1, 2, 3]
        {
            cout << "Enter correct choice!\n";
            return;
        }
        if(queue[--p] == NULL)
        {
            queue[p] = new node;
            cout << "Enter patient ID : ";
            cin >> queue[p]->patient_id;
            cout << "Enter patient name : ";
            cin >> queue[p]->name;
            queue[p]->next = NULL;
            e[p] = queue[p];
        }
        else
        {
            e[p]->next = new node;
            e[p] = e[p]->next;
            cout << "\nEnter patient ID : ";
            cin >> e[p]->patient_id;
            cout << "Enter patient's name : ";
            cin >> e[p]->name;
            e[p]->next = NULL;
        }
    }
    
    void show_queue()
    {
        node *temp;
        string priority[3] = {"High Priority", "Medium Priority", "Low Priority"};
        cout << "Queue of Patients :";
        for (int i = 0; i < 3; ++i)
        {
            if (queue[i] != NULL)
            {
                cout << endl << priority[i] << " : ";
                cout.width(10);
                cout << endl << "Patient ID";
                cout.width(20);
                cout << "Patient Name";
                cout << endl;
                temp = queue[i];
                while(temp != NULL)
                {
                    cout.width(10);
                    cout << temp->patient_id;
                    cout.width(20);
                    cout << temp->name;
                    cout << endl;
                    temp = temp->next;
                }
            }
        }
        if (queue[0] == NULL && queue[1] == NULL && queue[2] == NULL)
            cout << "\nNo patients in the queue\n";
    }
    
    void dequeue()
    {
        for (int i = 0; i < 3; ++i)
        {
            if(queue[i] != NULL)
            {
                cout << endl << queue[i]->name << " was served\n";
                node *temp;
                temp = queue[i];
                queue[i] = queue[i]->next;
                delete temp;
                return;
            }
        }
        cout << "There are no patients in the queue\n";
    }
};

int main()
{
    pqueue patients;
    while (true)
    {
        cout << "\nMenu :\n";
        cout << "1. Add patient to the queue\n";
        cout << "2. Serve patient\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice : ";
        int ch;
        cin >> ch;
        if (ch == 4)
        {
            break;
        }
        switch (ch)
        {
            case 1:
                patients.enqueue();
                break;
            case 2:
                patients.dequeue();
                break;
            case 3:
                patients.show_queue();
                break;
            default:
                cout << "\nEnter correct choice!\n";
        }
    }
    return 0;
}
