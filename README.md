# Hospital-system

## 1.0 Overview
Hospital System information

 - Implement the following system for a hospital

 - There are 20 different specialization (e.g. Children, Surgery, etc)

 - For each specialization, there are only 5 available spots [queue]

 - Adding a patient :

   - Read the requested specialization [1-20].
   - Read his name and status (0 = regular, 1 = urgent)
   - If 5 patients exist, apologize and don't accept.
   - If the user is regular, add in end of queue.therwise, add in Begin

 - Print patients, for the specializations that have waiting patients

 - Dr pickup a patient :

   - Read the requested specialization. If no patients, inform the doctor
   - Otherwise, ask the patient to go with the Dr. Remove from the queue


## 2.0 Functions used in the project


### 2.1 Add patient

- Used to :
 
   add a new patient to the system.

- Code :
```cpp

void add_patient(){
    cout<<"Entre specialization (1->20), name ,states(0->regular , 1->argent) :\n";
    cin>>specialization>>name>>states;
    
    //Check if the number is valid or not
    if(specialization>20||specialization<1){
        cout<<"Invalid specialization\nEnter number from 1->20";
        return;
    }
    specialization--;
    //If the specialization is full
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

```

### 2.2 Print all patients

- Used to :

   print all patients for each specialization.
   
- Code :
```cpp

void print_all_patients(){
    int indx{};
    
    //Iterating over all specilizations and print it's patients 
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

```

### 2.3 Get next patient

- Used to :

   Allowing the current patient to enter to the doctor.
   
- Code :

```cpp

void get_next_patient(){
    cout<<"Enter specialization\n";
    cin>>specialization;
    --specialization;
    // If there is no patients
    if(v[specialization].empty()){
        cout<<"No patients at the moment . Have rest ,Dr\n";
    }
    
    // Deleting patient from the specization 
    else{
        cout<<v[specialization].front()<<" please go with the Dr\n";
        v[specialization].pop_front();
    }
}

```



### 3.0 Notes

I used Deque because it takes O(1) to push_front & pop_front ( in case the patient is urgent ) and O(1) push_back & pop_back ( in case the patient is regular ) and it's useful in our case .

```cpp

vector<deque<string>>v(20);

``` 





























