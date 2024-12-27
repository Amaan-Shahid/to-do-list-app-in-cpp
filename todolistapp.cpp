#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

struct Task{
    int id;
    char task[100];
};

Task tasks[100];
int taskcount = 0;


void addTask(){
if(taskcount>100){
    cout<<"Space Overflow!"<<endl;
    return;
}
cout<<"Enter ID"<<endl;
cin>>tasks[taskcount].id;
cin.ignore();
cout<<"Enter Task"<<endl;
cin.getline(tasks[taskcount++].task,100);
cout<<"Task Added Successfully!"<<endl;
} 

void removeTask(){
int id;
cout<<"Enter Task ID"<<endl;
cin>>id;
if(taskcount==0){
    cout<<"No Task Added"<<endl;
    return;
}
for(int i=0;i<taskcount;i++){
    if(id==tasks[i].id){
        for(int j=i;j<taskcount;j++){
            tasks[i]=tasks[i+1];
            taskcount--;
        }
        cout<<"Task Deleted Successfully!"<<endl;
        return;
    }
}
cout<<"Wrong ID"<<endl;
}

void viewTask(){
  if(taskcount==0){
    cout<<"No Task Added"<<endl;
    return;
  }
  cout<<"ID \t Task"<<endl;
  for(int i=0;i<taskcount;i++){
    cout<<setw(2)<<tasks[i].id<<"\t"<<tasks[i].task<<endl;
  }

}

int main(){
  int n;
  while(true){
  cout<<"1. Add Task"<<endl;
  cout<<"2. Remove Task"<<endl;    
  cout<<"3. View Task"<<endl;
  cout<<"4. Exit Program"<<endl;
  cout<<"Enter No. to choose!"<<endl;
  cin>>n;
  switch(n){
    case 1:
    addTask();
    break;
    case 2:
    removeTask();
    break;
    case 3: 
    viewTask();
    break;
    case 4:
    cout<<"Terminating the Program!"<<endl;
    return 0;
    default:
    cout<<"Invalid Number!"<<endl;
  }
  }
return 0;
}
