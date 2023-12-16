#include <iostream>
#include <cstring>
#include <string>
using namespace std;

enum select
{
    Available_Rooms = 1,
    Room_Booking,
    Total,
    Booking_Details,
    Save_Details,
    Exit
};

struct Room
{
    string name;
    int availability;
    // int price;
};

void Show_Menu_Rooms()
{
    cout << "<---------Hotel Booking System---------->" << endl;
    cout << "Choose one of the options below" << endl;
    cout << "1) Available Rooms" << endl;
    cout << "2) Book a room" << endl;
    cout << "3) Check Out" << endl;
    cout << "4) View Booking details" << endl;
    cout << "5) View Total earnings" << endl;
    cout << "6) Save Booking Details" << endl;
    cout << "7) Exit" << endl;
}

void Show_Available_Rooms(char room_types[][50],Room standard_rooms[], Room Suites[], Room Luxuary_Rooms[])
{
    int ch;
    cout<<endl;
    cout << "Following are the types of rooms , choose any one to see the availability:" << endl;
    
    //Standard Rooms,Suites,Luxuary Rooms
    
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << ") " << room_types[i] << endl;
    }

    cin >> ch;
    --ch;
    cout<<endl;
    
    if (ch >= 0 && ch < 3)
    {
        
        cout << "Available rooms in " << room_types[ch] << ":" << endl;
        cout<<endl;
        cout << "Room Type\t\tAvailability\tPrice (per night)" << endl;
        cout << "---------------------------------------------------------" << endl;
        
        // Display available rooms based on selected category
        switch (ch)
        {
       
        case 0:
        {
           
            // Standard Rooms:  Single Seater, Double Seater, Family Rooms and their prices

            for (int i = 0, c = 50; i < 3; i++, c = c + 50)
            {
                cout << i + 1 << ") " << standard_rooms[i].name << "\t\t" << standard_rooms[i].availability << "\t\t" << c << "$" << endl;
            }
            
            cout<<endl;
            break;
        }

           // Suites:    Standard Suites, Executive Suites, Luxuary Suites and their prices
        
        case 1:
        {
            for (int i = 0, c = 100; i < 3; i++, c = c + 100)
            {
                cout << i + 1 << ") " << Suites[i].name << "\t\t" << Suites[i].availability << "\t\t" << c << "$" << endl;
            }
           
            cout<<endl;
            break;
        }

          //Luxuary Rooms: Deluxe Rooms , Royal Rooms and their prices

        case 2:
        {
            for (int i = 1, c = 350; i < 3; i++, c = c + 150)
            {
                cout << i << ") " << Luxuary_Rooms[i-1].name << "\t\t" << Luxuary_Rooms[i-1].availability << "\t\t" << c << "$" << endl;
            }
            cout<<endl;
            break;
        }
         
         //Choice invalid

        default:
        {
            cout << "Invalid option" << endl;
            cout << "Try again" << endl;
            break;
        }
        }
    }
}

void Book_Rooms(const char room_types[][50],Room standard_rooms[], Room Suites[], Room Luxuary_Rooms[])
{
    
    int ch,room_select,t_rooms;
    cout << "Choose the type of room(Standard Rooms,Suites,Luxuary Rooms)" << endl;
    cin>>ch;
    ch--;
    cout<<endl;
    
    if(ch>=0 && ch<3){
         
         cout<<"Selected Room_Type is: "<<room_types[ch]<<endl;         
         cout<<"Now, book any type of "<<room_types[ch]<<" from the following"<<endl;
         
        //Single Seater,Double Seater, Family Rooms and its availability

         if(ch==0){
            for(int i=0;i<3;i++){
                cout<<i+1<<")"<<standard_rooms[i].name<<" "<<standard_rooms[i].availability<<endl;
            }}
         
         //Standard Suite, Executive Suite, Honey Moon Suite and its availability
         
         if(ch==1){
             for(int i=0;i<3;i++){
                cout<<i+1<<")"<<Suites[i].name<<"\t"<< Suites[i].availability<<endl;
            }
         }         
         
        //Deluxe Rooms, Royal Rooms and its availability

         if(ch==2){
            for(int i=1;i<3;i++){
                cout<<i<<")"<<Luxuary_Rooms[i-1].name<<"\t"<< Luxuary_Rooms[i-1].availability<<endl;
            }
         }}
     
     cin>>room_select;
     --room_select;
     
     switch (room_select)
        {
            case 0:
            {
    
                 if (standard_rooms[room_select].availability > 0)  {
                        
                 standard_rooms[room_select].availability--;
                 cout<<endl;
                 cout << "Booking successful! " << standard_rooms[room_select].name << " has been booked." << endl;
                 cout<<endl;
                 
                    }
                   
                    else{
                       
                        cout<<endl;
                        cout << "Sorry, this room is not available for booking." << endl;
                    
                        }
              break;
                }
            
          case 1:
          {
            
            if(Suites[room_select].availability>0){
               
               Suites[room_select].availability--;
               cout<<endl;
               cout << "Booking successful! " << Suites[room_select].name << " has been booked." << endl;
               cout<<endl;
            }
                    
            else{
                
                    cout<<endl;
                    cout << "Sorry, this room is not available for booking." << endl;
                    cout<<endl;
                
                }
          break;
          }
        case 2:
        {
          
          if(Luxuary_Rooms[room_select].availability>0) {
           
            cout<<endl;
            Luxuary_Rooms[room_select].availability--;
            cout<<"Room Booked Successfully"<<Luxuary_Rooms[room_select].name<<"has been booked";
            cout<<endl;
         
          }
        
        else{
              cout<<endl;
              cout << "Sorry, this room is not available for booking." << endl;
              cout<<endl;           
            }
         break;
        }
    
        }
}


int main()
{
    
    Room standard_rooms[] = {{"Single Seater", 100}, {"Double Seater", 150}, {"Family Rooms  ", 250}};
    Room Suites[]         = {{"Standard Suite", 70}, {"Executive Suite", 110}, {"Honey Moon Suite", 120}};
    Room Luxuary_Rooms[]  = {{"Deluxe Rooms", 50}, {"Royal Room", 50}};
    
    char room_types[3][50];
    strcpy(room_types[0], "Standard Room");
    strcpy(room_types[1], "Suites");
    strcpy(room_types[2], "Luxury Rooms");

    int choice;

    do
    {
        Show_Menu_Rooms();
        cout << "Enter a choice ranging from 1--7: ";
        cin >> choice;

        switch ((choice))
        {
        case Available_Rooms:
        {
         Show_Available_Rooms(room_types,standard_rooms,Suites,Luxuary_Rooms);
        }  
            break;

        case Room_Booking:
        {
            Book_Rooms(room_types,standard_rooms,Suites,Luxuary_Rooms);
        }
            break;

        default:
        return 0;
        }

    } while (choice != 7);
    return 0;
}
