#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class account{
    public:
        long long int acc_no;
        char name[100];
        long long int money;
        char type[100];

        void create()
        {
            cout<<"\n** Enter All The Account Details:";
            cout<<"\n++ Enter Account Number: ";
            cin>>acc_no;
            cout<<"++ Enter Name: ";
            scanf(" %[^\n]s", name);
            cout<<"++ Enter Balance: ";
            cin>>money;
            cout<<"++ Enter Account Type: ";
            scanf(" %[^\n]s", type);
        }
        void show()
        {
            cout<<"\nAccount Number: "<<acc_no<<endl;
            cout<<"Name: "<< name<< endl;
            cout<<"Balance: "<<money<<endl;
            cout<<"Account Type: "<< type<<endl;
        }
        void report()
        {
            printf("\n%10lld\t\t",acc_no);
            printf("%20s\t\t", name);
            printf("%12lld\t\t", money);
            printf("%15s", type);
        }
        void modify()
        {
            char mod_name, mod_type;
            cout<<"\n++ Want to Modify Name? (Type 'Y' for Yes and 'N' for No): ";
            cin>>mod_name;
            if(mod_name=='Y'){
                cout<<"++ Enter Modified Name: ";
                scanf(" %[^\n]s", name);
            }
            cout<<"++ Want to Modify Type? (Type 'Y' for Yes and 'N' for No): ";
            cin>>mod_type;
            if(mod_type=='Y'){
                cout<<"++ Enter Modified Type: ";
                scanf(" %[^\n]s", type);
            }
        }
        void deposit()
        {
            long long int dep;
            cout<<"\nEnter Deposit Amount:";
            cin>>dep;
            money+=dep;
        }
        void withdraw()
        {
            long long int with;
            cout<<"\nEnter Withdraw Amount:";
            cin>>with;
            if(money>=with) money-=with;
            else cout<<"**Not Enough Balance in Account!!\n";
        }
        long long int acc_number()
        {
            long long int no=acc_no;
            return no;
        }
        long long int balance()
        {
            long long int bal=money;
            return bal;
        }
        string show_type()
        {

        }


};

int main()
{
    account A[1000];
    long long int n,i,cnt=0;
    while(1)
    {
        cout<<"\n** Welcome!!\n";
        cout<<"** Choose an Option\n";
        cout<<"       (1) Create Account\n";
        cout<<"       (2) Show Account\n";
        cout<<"       (3) Modify Account\n";
        cout<<"       (4) Deposit Money\n";
        cout<<"       (5) Withdraw Money\n";
        cout<<"       (6) Accounts Report\n";
        cout<<"       (7) Exit\n";

        long long int choice;
        cout<<"\n++ Enter Your Choice: ";
        cin>>choice;
        switch(choice){
        case 1:
            A[cnt].create();
            cnt+=1;
            break;

        case 2:
           cout<<"\n++ Enter Account Number: ";
           long long int show_check,l;
           cin>>show_check;
           cout<<"**Account Details\n";
           for(l=0; l<cnt; l++){
               if(A[l].acc_no==show_check){
                   A[l].show();
                   break;
               }
           }
           if(l==cnt) cout<<"\n** No Such Account Found!!\n";
           break;

        case 3:
            cout<<"\n++ Enter Account Number: ";
            long long int mod_check,q;
            cin>>mod_check;
            for(q=0; q<cnt; q++){
                if(A[q].acc_no==mod_check){
                    A[q].modify();
                    break;
                }
            }
            if(q==cnt) cout<<"\n** No Such Account Found!!\n";
            break;


        case 4:
            long long int ac,m;
            cout<<"Enter Account Number: ";
            cin>>ac;
            for(m=0; m<cnt; m++){
                if(A[m].acc_no==ac){
                    A[m].deposit();
                    break;
                }
            }
            if(m==cnt) cout<<"\n** No Such Account Found!!\n";
            break;

        case 5:
            long long int draw_check,w;
            cout<<"Enter Account Number: ";
            cin>>draw_check;
            for(w=0; w<cnt; w++){
                if(A[w].acc_no==draw_check){
                    A[w].withdraw();
                    break;
                }
            }
            if(w==cnt) cout<<"\n** No Such Account Found!!\n";
            break;

        case 6:
            cout<<"\n**Accounts Report:\n";
            cout<<"Account Number              Account Holder's Name        Account Balance            Type";
            for(i=0; i<cnt; i++){
                A[i].report();
            }
            break;

        case 7:
            cout<<"\n** Thank You!!\n";
            return 0;
            break;

        default:
            cout<<"\n** Wrong Option!!\n";
            break;

        }
    }
    return 0;
}
