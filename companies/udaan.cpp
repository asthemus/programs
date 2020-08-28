#include <bits/stdc++.h>
using namespace std;
map<string, vector<vector<int>>> hall;

void print_screen(vector<vector<int>> screen){
     int n = screen.size();
     int m = screen[0].size();
     for(int i=1;i<n;i++){
          for(int j=1;j<m;j++)
               cout<<screen[i][j]<<" ";
          cout<<endl;
     }
}

string add_screen(string screen, int num_rows, int seats_rows, vector<int> &aisle){

     if(hall.find(screen) != hall.end())
          return "failure";
     vector<vector<int>> cons_screen(num_rows+1, vector<int> (seats_rows+1, 1));
     for(int i=1;i<=num_rows;i++)
          for(int j=0;j<aisle.size();j++)
               cons_screen[i][aisle[j]] = INT_MAX;
     hall[screen] = cons_screen;
     print_screen(hall[screen]);
     return "success";
}

string reserve_seat(string screen, int num_rows, vector<int> &seats_to_reserve){

     if(hall.find(screen) == hall.end())
          return "failure";
     int n = hall[screen].size();
     if(num_rows<=0 || num_rows>=n)
          return "failure";
     vector<int> curr_row = hall[screen][num_rows];
     int m = curr_row.size();
     for(int j=0;j<seats_to_reserve.size();j++){
          int num = seats_to_reserve[j];
          if(num<=0 || num>=m || curr_row[num] < 0)
               return "failure";
     }
     for(int j=0;j<seats_to_reserve.size();j++){
          int num = seats_to_reserve[j];
          curr_row[num] *= -1;
     }
     hall[screen][num_rows] = curr_row;
     print_screen(hall[screen]);
     return "success";
}

string get_unreserved(string screen, int num_rows){
     if(hall.find(screen) == hall.end())
          return "failure";
     int n = hall[screen].size();
     if(num_rows<=0 || num_rows>=n)
          return "failure";
     vector<int> curr_row = hall[screen][num_rows];
     for(int i=1;i<curr_row.size();i++){
          if(curr_row[i]>0)
               cout<<i<<" ";
     }
     return "success";
}

void suggest_continuous_seats(vector<vector<int>> screen, int num_rows,int num_seats, int choice){
     if()
}

int main(){
     int n;
     cin>>n;
     while(n--){
          string com, screen;
          char c;
          cin>>com>>screen;
          if(com == "add-screen"){
               int num_rows, seats_rows,temp;
               scanf("%d%d",&num_rows,&seats_rows);
               vector<int> aisle;
               while(true){
                    scanf("%d%c",&temp,&c);
                    aisle.push_back(temp);
                    if(c == '\n')
                         break;
               }
               cout<<add_screen(screen,num_rows,seats_rows,aisle)<<endl;
          }
          else if(com == "reserve-seat"){
               int num_rows,temp;
               scanf("%d",&num_rows);
               vector<int> seats_to_reserve;
               while(true){
                    scanf("%d%c",&temp,&c);
                    seats_to_reserve.push_back(temp);
                    if(c == '\n')
                         break;
               }
               cout<<reserve_seat(screen,num_rows, seats_to_reserve)<<endl;
          }
          else if(com == "get-unreserved"){
               int num_rows;
               scanf("%d",&num_rows);
               get_unreserved(screen,num_rows);
          }
          else if(com == "suggest-contiguous-seats"){
               int num_seats, num_rows, choice;
               scanf("%d%d%d",&num_seats,&num_rows, &choice);
               suggest_continuous_seats(screen,num_rows,num_seats,choice);
          }
          cout<<endl;
     }
     return 0;
}
