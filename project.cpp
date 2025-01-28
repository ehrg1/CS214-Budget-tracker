#include <iostream>
using namespace std;

class MBT{
private:
    // structure containing a data part 
    //and link part
    double income = 0;

    struct node{
        double amount = 0;
        string category;
        node* link;
    } *p=NULL;

    public:
        void GetIncome();
        double TotalAmount();
        void AddExpense();
        void Display();
        bool IsOverIncome(double amt);
        void IncreaseBudget();
    
};
int main(){
    int choice = 0;
    MBT obj;
    obj.GetIncome();
    while (true){
        cout<<"\nBudget Tracker\n1.Add Expense\n2.Display Summary\n3.Increase Budget\n4.Exit\nEnter your choice: ";
        cin>>choice;
        cout<<endl;
        if(choice == 1){
            obj.AddExpense();
        }
        else if(choice == 2){
            obj.Display();
        }
        else if (choice == 3){
            obj.IncreaseBudget();
        }
        else if (choice == 4){
            break;
        }
        else {
            cout<<"invalid input!"<<endl;
        }
    }
    
}

void MBT::GetIncome(){
    cout<<"Enter your monthly income: $";
    cin>>income;
}



void MBT::AddExpense(){
    node *temp = NULL;
    node *r = NULL;
    double amt;
    // if the list is empty, create first node
    if (p == NULL){
        temp = new node;
        cout<<"Enter expense category: ";
        cin>>temp -> category; 
        cout<<"Enter expense amount: $";
        cin>>amt;
        temp -> amount = amt;
       
        if(IsOverIncome(amt)){

            cout<<"boudget is not enough"<<endl;
            return;
        }
        temp -> link = NULL;
        p = temp;
        cout<<"Expense added successfully!"<<endl<<endl;
    }
    else{
        // go to last node
        temp = p;
        while (temp -> link != NULL)
            temp = temp -> link;
        // add node at the end
        r = new node;
        cout<<"Enter expense category: ";
        cin>>r -> category; 
        cout<<"Enter expense amount: $";
        cin>>amt;
        r -> amount = amt;
        if(IsOverIncome(amt)){

            cout<<"boudget is not enough"<<endl;
            return;
        }
        r -> link = NULL;
        temp -> link = r;
        cout<<"Expense added successfully!"<<endl<<endl;
    }
}



void MBT::Display(){
    node *temp = p;
    cout<<"Monthly Budget summary"<<endl;
    cout<<"Income: $"<<income<<endl<<endl;
    cout<<"expenses:"<<endl;
    cout<<"category\tAmount"<<endl;
    cout<<"---------------------"<<endl;
    while (temp != NULL){
        cout<<temp->category<<"\t\t$"<<temp->amount<<endl;
        temp = temp->link;
    }
    cout<<"---------------------"<<endl;
    cout<<"total expenses"<<"\t$"<< TotalAmount()<<endl;
    cout<<"remaining budget $"<< (income-TotalAmount())<<endl<<endl;
}

double MBT::TotalAmount(){
    double total = 0;
    node *temp = p;
    while(temp!= NULL){
        total += temp->amount;
        temp = temp->link;
    }
    return total;
}

bool MBT:: IsOverIncome(double amt){
    if((TotalAmount() + amt) >income){
        return true;
    }
    else {
        return false;
    }
}
void MBT::IncreaseBudget(){
    int AddIncome;
    cout<<"add to your budget: $";
    cin>>AddIncome;
    income += AddIncome;
    
}