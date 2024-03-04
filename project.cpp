#include<bits/stdc++.h>
#include<string.h>
#include<map>
using namespace std;
string
location[10]={"NEWDELHI","MUMBAI","BENGALURU","CHENNAI","KOLKATA","JAIPUR","BHOPAL","LUCKNOW","CHANDIGARG","AHMEDABAD"};
map<int, string> mti;
map<char,string> m;
vector <int> graph[10];
bool vis[10];
int k=0;
void map_out()
{
 string
location[10]={"NEWDELHI","MUMBAI","BENGALURU","CHENNAI","KOLKATA","JAIPUR","BHOPAL","LUCKNOW","CHANDIGARG","AHMEDABAD"};
 string num="0123456789";
 for(int i=0;i<10;i++)
 {
 char s1=num[i];
 string s=location[i];
 m.insert(pair<char, string>(s1, s));
 }
/*
 for (auto itr = m.begin(); itr != m.end(); ++itr)
 {
 cout << itr->first<< '\t' << itr->second << '\n';
 }
*/
}
string find_s(char s)
{
 for (auto itr = m.begin(); itr != m.end(); ++itr)
 {
 if(itr->first==s)
 {
 return itr->second;
 }
 }
}
char find_c(string s)
{
 for (auto itr = m.begin(); itr != m.end(); ++itr)
 {
 if(itr->second==s)
 {
 return itr->first;
 }
 }
}
int find_out(string s)
{
 for (int i=0;i<10;i++)
 {
 if(location[i]==s)
 {
 return i;
 }
 }
 return -1;
}
string find_it(int x)
{
 for (auto itr = mti.begin(); itr != mti.end(); ++itr)
 {
 if(itr->first==x)
 {
 return itr->second;
 }
 }
}
void add(vector<int> graph[],int s,int d)
{
 graph[s].push_back(d);
 graph[d].push_back(s);
}
void printgraph(vector<int> graph[])
{
 cout<<"AVAILABLE ROUTES ";
 for (auto itr = mti.begin(); itr != mti.end(); ++itr)
 {
 cout<<"\n ROUTE :"<<find_it(itr->first);
 for(auto x: graph[itr->first])
 {
 cout<<"->"<<find_it(x);
 }
 cout<<endl;
 }
}
void map_it()
{
 // initialized a string array
 string
location[10]={"NEWDELHI","MUMBAI","BENGALURU","CHENNAI","KOLKATA","JAIPUR","BHOPAL","LUCKNOW","CHANDIGARG","AHMEDABAD"};
 // mapping of string to integer
 for(int i=0;i<10;i++)
 {
 mti.insert({i,location[i]});
 }
/*
 for (auto itr = mti.begin(); itr != mti.end(); ++itr)
 {
 cout << itr->first<< '\t' << itr->second << '\n';
 }
*/
}
void train_details()
{
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
cout<<" TRAIN DETAILS ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<endl;
 fstream file;
 string word,filename;
 string get;
 filename="serial1.txt";
 file.open(filename.c_str());
 int num1,num2;
 while (file >> word)
 {
 // displaying content
 get=word;
 cout<<"TRAIN ID: "<<get<<endl;
 cout<<"Source Station: "<<find_s(get[0])<<endl;
 cout<<"Destination Station: "<<find_s(get[1])<<endl;
  cout<<"Departing Time:"<<get[2]<<get[3]<<":"<<get[4]<<get[5]<<endl;
 cout<<"Arriving Time: "<<get[6]<<get[7]<<":"<<get[8]<<get[9]<<endl;
 cout<<endl;
 }
}
void search_train()
{
cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" TRAIN DETAIL";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<endl;
 fstream file;
 string word, t, q, filename;
 string get;
 filename="serial1.txt";
 string srch;
 int flag=0;
 cout<<"ENTER THE UNIQUE TRAIN IDENTIFICATION NUMBER: ";
 cin>>srch;
 file.open(filename.c_str());
 int num1,num2;
 while (file >> word)
 {
 // displaying content
 if(word==srch)
 {
 cout<<"TRAIN FOUND"<<endl;
 get=word;
 cout<<"TRAIN ID: "<<get<<endl;
 cout<<"Source Station: "<<find_s(get[0])<<endl;
 cout<<"Destination Station: "<<find_s(get[1])<<endl;
 cout<<"Departing Time:"<<get[2]<<get[3]<<":"<<get[4]<<get[5]<<endl;
 cout<<"Arriving Time:"<<get[6]<<get[7]<<":"<<get[8]<<get[9]<<endl;
 cout<<endl;
 }
 flag=1;
 }
 if(flag==0)
 {
 cout<<"INVALID TRAIN ID .....TRAIN NOT FOUND"<<endl;
 }
}
void add_train()
{
 ofstream my_train("serial1.txt",ios::app);
 string train_num;
 // Instructions for entering the train identification number
 cout<<endl;
 cout<<"KINDLY READ THE INSTRUCTIONS CAREFULLY TO ALLOT A TRAIN-ID "<<endl;
 cout<<"TRAIN NUMBER FORMAT A-B-XXXX-YYYY"<<endl;
 cout<<"A-> SOURCE STATION CODE "<<endl;
 cout<<"B-> DESTINATION STATION CODE"<<endl;
 cout<<"XXXX-> DEPARTING TIME"<<endl;
 cout<<"YYYY-> ARRIVAL TIME"<<endl;
 cout<<"KINDLY USE 24HR TIME FORMAT"<<endl;
 cout<<endl;
 for (auto itr = mti.begin(); itr != mti.end(); ++itr)
 {
 cout << itr->first<< '\t' << itr->second << '\n';
 }
 cout<<endl;
 cout<<"ENTER THE UNIQUE TRAIN IDENTIFICATION NUMBER: ";
 cin>>train_num;
 my_train<<train_num<<endl;
 cout<<endl;
 my_train.close();
}
void check_trains()
{
 string a;
 string b;
 cout<<"ENTER THE SOURCE STATION TO START YOUR JOURNEY: ";
 cin>>a;
 cout<<"ENTER THE DESTINATION STATION TO END YOUR JOURNEY: ";
 cin>>b;
 char c1;
 char c2;
 c1=find_c(a);
 c2=find_c(b);
 int flag=0;
 fstream file;
 string word, t, q, filename;
 string get;
 filename="serial1.txt";
 file.open(filename.c_str());
 while (file >> word)
 {
 // displaying content
 get=word;
 if(get[0]==c1 && get[1]==c2)
 {
 cout<<"TRAIN ID: "<<get<<endl;
 cout<<"Source Station: "<<find_s(get[0])<<endl;
 cout<<"Destination Station: "<<find_s(get[1])<<endl;
 cout<<"Departing Time:"<<get[2]<<get[3]<<":"<<get[4]<<get[5]<<endl;
 cout<<"Arriving Time:"<<get[6]<<get[7]<<":"<<get[8]<<get[9]<<endl;
 cout<<endl;
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 cout<<"TRAIN NOT FOUND !!!!";
 }
}
bool haspath(vector<int> graph[],int src,int dest,bool vis[],int
size1)
{
 if(src==dest)
 return true;
 vis[src]=true;
 for(int i=0;i<size1;i++) // check for it's neighbors
 {
 for(auto x: graph[i])
 {
 if(!vis[x] && haspath(graph,x,dest,vis,size1))
 return true;
 }
 }
 return false;
}
void check_path()
{
 string a;
 string b;
 cout<<"ENTER THE SOURCE STATION TO START YOUR JOURNEY: ";
 cin>>a;
 cout<<"ENTER THE DESTINATION STATION TO END YOUR JOURNEY: ";
 cin>>b;
 int n1,n2;
 n1=find_out(a);
 n2=find_out(b);
 if(0<=n1 && n1<=9 && 0<=n2 && n2<=9)
 {
 if(haspath(graph,n1,n2,vis,10))
 {
 cout<<"PATH EXIST BETWEEN "<<a<<" AND "<<b<<endl;
 }
 else
 {
 cout<<"PATH DON'T EXIST BETWEEN "<<a<<" AND"<<b<<endl;
 }
 }
 else
 {
 cout<<"PATH DON'T EXIST BETWEEN "<<a<<" AND "<<b<<endl;
 }
}
void add_path()
{
 string a;
 string b;
 cout<<"ENTER THE SOURCE STATION TO START YOUR JOURNEY: ";
 cin>>a;
 cout<<"ENTER THE DESTINATION STATION TO END YOUR JOURNEY: ";
 cin>>b;
 int n1,n2;
 n1=find_out(a);
 n2=find_out(b);
 // cout<<n1<<" "<<n2;
 if(0<=n1 && n1<=9 && 0<=n2 && n2<=9)
 {
 add(graph,n1,n2);
 cout<<endl;
 cout<<"PATH ADDED SUCCESSFULLY";
 }
 else
 {
 cout<<"INVALID STATIONS ENTERED ";
 }
}
int main()
{
 map_it();
 map_out();
 add(graph,1,2);
 add(graph,1,3);
 add(graph,1,4);
 add(graph,2,5);
 add(graph,5,8);
 add(graph,3,8);
 add(graph,4,6);
 add(graph,6,7);
 add(graph,7,8);
 add(graph,0,9);
 add(graph,0,1);
 // function call to allot all seats to true
 cout<<endl;
cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" DATA STRUCTURES AND ALGORITHMS PROJECT";
cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 string user_id;
 string password;
 cout<<endl;
 ofstream my_file("username.txt",ios::app);
 cout<<"ENTER YOUR USERID TO START: "<<endl;
 cin>>user_id;
 my_file<<user_id;
 my_file<<endl;
 my_file.close();
 cout<<"ENTER PASSWORD TO LOGIN: "<<endl;
 cin>>password;
 int choice;
 do
 {
 if(password=="abcd123")
 {
 cout<<endl;
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<"!!!!!!!!!!!!!!WELCOME TO INDIAN RAILWAYS!!!!!!!!!!!!!!!";
cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<" ";
 cout<<endl;
 int info;
 cout<<"MAIN MENU: "<<endl;
 cout<<"PRESS 1 TO LIST TRAIN DETAILS: "<<endl;
 cout<<"PRESS 2 ADD TRAIN DETAILS IN DATABASE: "<<endl;
 cout<<"PRESS 3 TO CHECK TRAINS BETWEEN STATIONS:"<<endl;
 cout<<"PRESS 4 TO TO ADD PATH BETWEEN TWO STATIONS:"<<endl;
 cout<<"PRESS 5 TO CHECK PATH BETWEEN STATIONS: "<<endl;
 cout<<"PRESS 6 TO CHECK ALL AVAILABLE ROUTES: "<<endl;
 cout<<"PRESS 7 TO SEARCH TRAIN: "<<endl;
 cout<<"PRESS 8 TO EXIT: "<<endl;
 cout<<endl;
 cout<<"KINDLY PRESS TO PROCEED FURTHER: ";
 cin>>info;
 switch(info)
 {
 case 1:
 system("cls");
train_details();
break;
 case 2:
 system("cls");
add_train();
break;
 case 3:
 system("cls");
check_trains();
break;
 case 4:
 system("cls");
 add_path();
break;
 case 5:
 system("cls");
check_path();
break;
 case 6:
 system("cls");
printgraph(graph);
break;
 case 7:
 search_train();
break;
 case 8:
 cout<<endl;
cout<<"THANK YOU FOR YOUR VISIT....INDIAN RAILWAYS HOPES FOR YOU HAPPY JOURNEY";
 exit(1);
 default:
 cout<<"THANK YOU FOR YOUR VISIT....INDIAN RAILWAYS HOPES FOR YOU HAPPY JOURNEY";
 exit(1);
 }
 }
 else
 {
 cout<<"RE-ENTER THE PASSWORD OR PRESS 0 TO EXIT "<<endl;
 cin>>password;
 }
 }while(password!="0");
 cout<<endl;
 cout<<endl;
 cout<<endl;
 cout<<endl;
 cout<<"THANK YOU "<<endl;
 return 0;
}
