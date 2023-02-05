#include <bits/stdc++.h>
#define _  ios_base::sync_with_stdio(false) , cin.tie(0),cout.tie(0);
#define int long long
#define PB push_back
#define all(x) x.begin(),x.end()
#define fx(x) fixed<<setprecision(x)
using namespace std;
vector<deque<string>>v(20);
int states,specialization;
string name;
void add_patient(){
    cout<<"Entre specialization (1->20), name ,states(0->regular , 1->argent) :\n";
    cin>>specialization>>name>>states;
    if(specialization>20||specialization<1){
        cout<<"Invalid specialization\nEnter number from 1->20";
        return;
    }
    specialization--;
    if(v[specialization].size()>=5){
        cout<<"Sorry we can't add more patients for this specialization.\n";
    }
    if(v[specialization].size()<5){
        if(states==1)
        {
            v[specialization].push_front(name);
        }
        else
        {
            v[specialization].push_back(name);
        }
    }
}
void print_all_patients(){
    int indx{};
    for(auto &&it:v){
        ++indx;
        if(!it.empty()){
            cout<<"There are "<<it.size()<<" patients in specialization "<<indx<<'\n';
            for(auto &&i:it){
                cout<<i<<'\n';
            }
            cout<<"-------------------------\n";
        }

    }
}
void get_next_patient(){
    cout<<"Enter specialization\n";
    cin>>specialization;
    --specialization;
    if(v[specialization].empty()){
        cout<<"No patients at the moment . Have rest ,Dr\n";
    }
    else{
        cout<<v[specialization].front()<<" please go with the Dr\n";
        v[specialization].pop_front();
    }
}
signed main() {
    while(true){
        cout << "\nEnter your choice:\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";
        int choice;
        cin>>choice;
        if (choice == 1)
            add_patient();
        else if (choice == 2)
            print_all_patients();
        else if (choice == 3)
            get_next_patient();
        else
            break;
    }
}