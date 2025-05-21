#include <iostream>
using namespace std;

class Expense {
public:
    string expenseName; 
	int expensePrice;
    Expense* next;

    Expense(string name,int price) {
        expenseName = name;
        expensePrice = price;
        next = NULL;
    }
};


class Month {
public:
	double totalprice;
    string monthName;
    Expense* expenseHead; 
	 Expense* expenseTail; 
	 
    Month* next;

    Month(string name) {
        monthName = name;
        expenseHead = NULL;
        next = NULL;
    }

   
    void addExpense(string expense,int price) {
        Expense* newExp = new Expense(expense,price);
        totalprice=totalprice+price;
        if(expenseHead==NULL){
        	expenseHead=expenseTail=newExp;
		}
		else{
			expenseTail->next=newExp;
			expenseTail=newExp;
		}
  
    }

 
    void displayExp() {
        Expense* Exp = expenseHead;
        while (Exp != NULL) {
            cout << "  Expense Name : " << Exp->expenseName << endl;
            cout << "  Expense Price: " << Exp->expensePrice << endl;
            Exp = Exp->next;
        }
    }
    
    void updateexp(){
        Expense* Exp = expenseHead;
        while (Exp != NULL) {
            cout << "  Expense Name : " << Exp->expenseName << endl;
            cout << "  Expense Price: " << Exp->expensePrice << endl;
            Exp = Exp->next;
        }
        Exp=expenseHead;
        cout<<"Enter expense name u want to change :";
        string n;
        cin>>n;
		while ( Exp!=NULL )
		{
			if( Exp->expenseName==n )
			{
				totalprice-=Exp->expensePrice;
		   int ep;
		   string en;
		   cout<<"Enter new name :";
		   cin>>en;
		   Exp->expenseName=en;
		   cout<<"Enter new price :";
		   cin>>ep;
		   Exp->expensePrice=ep;
		   	totalprice+=Exp->expensePrice;
			 } 
			Exp=Exp->next;  
		}
	   
	}
};


Month* addMonth(Month* head, string name) {
    Month* newMonth = new Month(name);

    if (head == NULL) {
        return newMonth;
    }

    Month* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newMonth;
    return head;
}



void display(Month* head) {
    Month* m = head;
    while (m != NULL) {
        cout << "Month: " << m->monthName << endl;
        m->displayExp();
        cout<<"Total Expenes of this month = "<<m->totalprice<<endl;
        m = m->next;
    }
}

void greaterexp(Month* head) {
    if (head == NULL) {
        cout << "No months available.\n";
        return;
    }

    Month* maxMonth = head;
    Month* temp = head->next;

    while (temp != NULL) {
        if (temp->totalprice > maxMonth->totalprice) {
            maxMonth = temp;
        }
        temp = temp->next;
    }

    cout << "\nMonth with the highest total expense: " << maxMonth->monthName << endl;
    cout << "Total Expense: " << maxMonth->totalprice << endl;
}

void smallerexp(Month* head) {
    if (head == NULL) {
        cout << "No months available.\n";
        return;
    }

    Month* minMonth = head;
    Month* temp = head->next;

    while (temp != NULL) {
        if (temp->totalprice < minMonth->totalprice) {
            minMonth = temp;
        }
        temp = temp->next;
    }

    cout << "\nMonth with the Lowest total expense: " << minMonth->monthName << endl;
    cout << "Total Expense: " << minMonth->totalprice << endl;
}

void search(Month* head){
	string name;
	cout<<"Enter month u want to search ";
	cin>>name;
	  if (head == NULL) {
        cout << "No months available.\n";
        return;
    }
   
     Month* temp = head;
     
      while (temp != NULL) {
        if (temp->monthName==name) {
        	cout<<"Month name : "<<temp->monthName<<endl;
        	temp->displayExp();
            cout<<"Total Expense : "<<temp->totalprice<<endl;
        }
        temp = temp->next;
    }
	
}

		
		
void  update(Month *head){
	string name;
	cout<<"Enter month to update its expense ";
	cin>>name;
	  if (head == NULL) {
        cout << "No months available.\n";
        return;
    }
   
     Month* temp = head;
     
      while (temp != NULL) {
        if (temp->monthName==name) {
        	cout<<"Month name : "<<temp->monthName<<endl;
        	temp->updateexp();
        }
        temp = temp->next;
    }
	cout<<"Updated succesfully"<<endl;	
}


void pop_front(Month*& head) {
    if (head == NULL) {
        cout << "Empty linked list.\n";
        return;
    }

    Month* temp = head;
    head = head->next;

    Expense* exp = temp->expenseHead;
    while (exp != NULL) {
        Expense* toDelete = exp;
        exp = exp->next;
        delete toDelete;
    }

    delete temp;
    cout << "Month deleted successfully from front.\n";
}

void del(Month*& head) {
    string mon;
    cout << "Enter Month you want to delete: ";
    cin >> mon;

    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

 
    if (head->monthName == mon) {
        pop_front(head);
        return;
    }

    Month* prev = head;
    Month* curr = head->next;

    while (curr != NULL) {
        if (curr->monthName == mon) {
            prev->next = curr->next;

           
            Expense* exp = curr->expenseHead;
            while (exp != NULL) {
                Expense* toDelete = exp;
                exp = exp->next;
                delete toDelete;
            }

            delete curr;
            cout << "Month deleted successfully.\n";
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Month not found.\n";
}


int main() {
    Month* monthList = NULL;

    int choice;
    do {
    	
        cout << "\n===== Expense Tracker Menu =====\n";
        cout << "1. Add Month\n";
        cout << "2. Display All Months\n";
        cout << "3. Show Month with Highest Expense\n";
        cout << "4. Show Month with Lowest Expense\n";
        cout << "5. Search a Month\n";
        cout << "6. Update Expense in a Month\n";
        cout << "7. Delete a Month\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
      case 1: {
    string monthName;
    cout << "Enter new month name: ";
    cin >> monthName;
    monthList = addMonth(monthList, monthName);

    Month* temp = monthList;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    int count;
    cout << "How many expenses do you want to enter? ";
    cin >> count;

    for (int i = 0; i < count; i++) {
        string expenseName;
        int price;
        cout << "Enter expense name: ";
        cin >> expenseName;
        cout << "Enter expense price: ";
        cin >> price;
        temp->addExpense(expenseName, price);
    }

    break;
}


            case 2:
                display(monthList);
                break;
            case 3:
                greaterexp(monthList);
                break;
            case 4:
                smallerexp(monthList);
                break;
            case 5:
                search(monthList);
                break;
            case 6:
                update(monthList);
                break;
            case 7:
                del(monthList);
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

