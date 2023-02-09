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

- Used to add a new patient in the system

Code :
```
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

```


