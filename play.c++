#include <iostream>
using namespace std;
#include <windows.h>
#include <string.h>
#include <string>
#include <math.h>

string folder[1000][1000]; int af = -1;int file[999]; int setter = -1;
// loading screen
void showoptions(int *key);

void per(int time){     // loading screen
    int random = 0,load = 1;
        while(load <100){
            load = load + random;
            random = rand() % 10 + 1;
                if(load <100){
                cout<<"loading.... please wait "<<endl;
                cout<<load<<"%";
                Sleep(time);
                system("cls");
            }  
        } 
    }

// creating folders
void addfolder(){   // for adding a folder 
    af++;
    cout<<"Type your folder's name : ";
    file[af] = 0;
    cin>>folder[af][0];
    per(50);
    cout<<"folder created successfully "<<endl;
    system("pause");
    system("cls");
}

void deleteF(int *key){  //for deleting a folder
    for(int i = *key ; i<af;i++){
        int n = file[i];
        int j = file[i+1];
        file[i] = file[i+1];
        int counter = 0;
        while(j>=0){
            folder[i][counter] = folder[i+1][counter];
            counter++;
            j--;
        }
    }
        af--;
        per(10);
        cout<<"Folder deleted successfully ";
        system("pause");
        system("cls");
}

void renameF(int *key){ // renaming folders
    int n = *key;
    cin>>*folder[n];
    system("pause");
    system("cls");
}

void displayF(){        //display all folders
    for(int i = 0;i<=af;i++){
        cout<<*folder[i]<<endl;
    }
    system("pause");
    system("cls");
}

//void sortF(){  }
void sortfisize(int key){
    int n = file[key];
    for(int i=1;i<n;i++){
        int prev = folder[key][i].size();
        for(int j = i+1;j<=n;j++){
            int next = folder[key][j].size();
            if(prev > next){
                    swap(folder[key][i],folder[key][j]);
            }
            else{
                system("pause");
                system("cls");
            }
        }
    }
}

void sortfiname(int key){
    int n = file[key];
    for(int i=1;i<n;i++){
        int counter = 0;
        int prev = int(folder[key][i][counter]);
        for(int j = i+1;j<=n;j++){
            int temp = 0;
            int next = int(folder[key][j][temp]);
            if(prev > next){
                    swap(folder[key][i],folder[key][j]);
            }
            else if(prev == next){
                counter++;
                temp++;
            }
            else{
                system("pause");
                system("cls");
            }
        }
    }
}

void sortoptions(int key){
    int choice;
    cout<<"SORT BY ? - "<<endl;
    cout<<"\t press 1 to sort by size  "<<endl;
    cout<<"\t press 2 to sort by name  "<<endl;
    cout<<"\t press any number to return - "<<endl;

    cin>>choice;
    if(choice == 1){
        sortfisize(key);
    }
    else if(choice == 2){
        sortfiname(key);
    }
    else{
        int *val = &key;
        showoptions(val);
        system("cls");
    }

}
// about files 
void datafi(int key){       //for enetering data in files
    file[key] = file[key]+1;
    int n = file[key];
    cout<<"Enter your data :";
    cin>>folder[key][n];
    per(10);
    cout<<"file added successfully "<<endl;
    system("pause");
    system("cls");

}

void displayfi(int key){    //for displaying files ( content in a folder)
    int n = file[key];
    for(int i = key;i<=key;i++){
    for(int j = 0 ; j<=n ; j++){
            if(j == 0 ){
                cout<<"file -> "<<folder[key]<<"  /  "<<*folder[key]<<endl<<endl;
            }
            else{
            cout<<folder[i][j]<<endl;
            }
        }
        system("pause");
        system("cls");
    }
}

void deleteFi(int key,int *deln){
    per(10);
    int n = file[key];
    int j = *deln;
    for(int i = j ; i<n ; i++){
        folder[key][i] = '\0';
        folder[key][i] = folder[key][i+1];
    }
    file[key] -= 1;
    cout<<"file deleted successfully..."<<endl;
    system("pause");
    system("cls");
}

void renameFi(int key, int sel){
    int choice ;
    cout<<"press 1 to confirm renaming OR press any key to continue "<<endl;
    cin>>choice;
    if(choice != 1){
        folder[key][sel] = folder[key][sel];
    }
    else if(choice == 1){
    cout<<"type the name you wanna change for "<<folder[key][sel]<<endl<<endl;
    cin>>folder[key][sel];
    }
}

void fileselector(int key,int s){             //to select files 
    int n = file[key];
    int select;                         //to select which file you wanna del 
        for(int i = 0;i<=n;i++){
            if(i == 0 ){
                cout<<"file -> "<<folder[key]<<"  /  "<<*folder[key]<<endl<<endl;
            }
            else{
            cout<<"press "<<i<<" to select file -> "<<folder[key][i]<<endl;
            }
        }
        cout<<"press "<<n+1<<" to go back "<<endl<<endl;
        cout<<"select a file you wanna delete :";
        cin>>select;
        if(select >0 && select <=n){
            if(s == 2){
        deleteFi(key,&select);
        system("cls");
            }
            if(s == 3){
                renameFi(key,select);          // key is for folder 
            }
        }
        else if(select > n+1 || n<0){
            cout<<"ERROR NO file found ENTER AGAIN returning back to options"<<endl;
            Sleep(1500);
            system("cls");
        }
        else if(select == 0){
            cout<<"ERROR!! INVALID ACTION returning back to options"<<endl;
            Sleep(1500);
            system("cls");
        }
    system("cls");
}

void showoptions(int *key){  //for showing options when selected a folder 
    int choice;
        do{
        cout<<"location -> "<<folder[*key]<<"  /   "<<*folder[*key]<<endl<<endl;
            cout<<"Press 1 to enter a data  "<<endl;   
            cout<<"Press 2 to delete a data "<<endl;
            cout<<"Press 3 to rename   "<<endl;
            cout<<"Press 4 to display   "<<endl;
            cout<<"Press 5 to sort  "<<endl;
            cout<<"Press 6 to return to the folder"<<endl;
            cout<<"select : ";
            cin>>choice;
            system("cls");
            if(choice == 1){
                datafi(*key);
            }
            if(choice == 2){
                int s = 2;
                fileselector(*key,s);
            }
            if(choice == 3){
                int s = 3;
                fileselector(*key,s);
            }
            if(choice == 4){
                displayfi(*key);
            }
            if(choice == 5){
                sortoptions(*key);
            }

        }while(choice != 6 );
}

void selectF(int s){ // folder selector 
    int select,choice; 
    do{
    for(int i= 0 ; i<=af;i++){
        cout<<"press "<<i <<" to select "<<*folder[i]<<endl;
    }
    cout<<"press "<<(af+1)<<" to return to main menu "<<endl;
    
    cout<<"select your folder : ";
    cin>>select;
    system("cls");
    if(select>=0 && select <=af){    
        if(s == 4){   
        cout<<"SELECT A FOLDER TO ENTER "<<endl<<endl;
        showoptions(&select);
        }
        if(s == 3){
        cout<<"SELECT A FOLDER TO DELETE "<<endl<<endl;
        deleteF(&select);
        break;
        }
        if(s == 5){
            cout<<"TYPE A NEW NAME FOR FOLDER  "<<*folder[select]<<"  :  "<<endl<<endl;
            renameF(&select);
        }
    }
    else if(select>af+1){
        cout<<"ERROR!! no such folder found .... choose again"<<endl;
    }
        }while(select != (af+1));
    
}

void searchall(){    //searching algo
    string search;
    cout<<"Type any folder or file you wanna search :";
    cin>>search;
    for(int i = 0 ; i <= af ; i++){
        int n = file[i];
        for(int j = 0; j <=n;j++){
            if(search == folder[i][j]){
                if(i != 0 ){
                    cout<<"found in folder "<<*folder[i]<<"  file "<<folder[i][j]<<"  is in number ->  "<<j<<endl;
                }
                else if( i == 0){
                    cout<<"folder found , number of "<<*folder[i]<<"  is -> "<<i<<endl;
                }
                else{
                    cout<<"NO FOLDER / FILE found named "<<search<<endl;
                }
            }
        }
    }
    system("pause");
    system("cls");
}

int main(){
    cout<<"GENERATING IN MEMORY FILE SYSTEM PLEASE WAIT ....";
            Sleep(2000);
            system("cls");
    int choice;

    do{
        cout<<"--------------------- IN MEMEORY FILE SYSTEM --------------------- "<<endl;
        cout<<"1) Type 1 to add a new folder "<<endl;
        cout<<"2) Type 2 to display "<<endl;
        cout<<"3) Type 3 to delete a folder "<<endl;
        cout<<"4) Type 4 to select a folder  "<<endl;
        cout<<"5) Type 5 to rename a folder  "<<endl;
        cout<<"6) Type 6 to search  "<<endl;
        cout<<"7) Type 7 to EXIT "<<endl;
        cout<<"------------------------------------------------------------------ "<<endl;
        cin>>choice;
        system("cls");
        if(choice == 1){
            addfolder();
        }
        if(choice == 2){
            displayF();
        }
        if(choice == 3){
            int s = 3;
            selectF(s);
        }
        if(choice == 4){
            int s = 4;
            selectF(s);
        }
        if(choice == 5){
            int s = 5;
            selectF(s);
        }
        if(choice == 6){
            searchall();
        }
        if(choice == 6){
            searchall();
        }
    }while(choice != 7);
}