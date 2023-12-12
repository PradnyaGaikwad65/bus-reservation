#include <iostream>
#include <string>
#include <fstream> 
using namespace std;
int bookTicket()
{
	 cout<<"\n ----- Reserve Your Seat ---- \n";	
    cout<<"\n ----- Available seats ---- \n";	 
     ifstream read; 
     read.open("reservation.dat");
      int seatreserve = 8;
    static int arr[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int recordFound =0; 
      if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	   while(getline(read, line)) {
	char temp = line[0];
	int index = (temp - 65);
	arr[index]=1;  
	recordFound = 1;
	}
	if(recordFound == 1)
	{
	cout<<"\n Reservation Summary :";
	char key = 'A';
	int seat = 9;
	for(int i = 0; i<=20; i++)
	{
	if(i == 0){
	if(arr[i] == 0) 
	cout<<"\n "<<key<<"-> 0"<<seat<<" - Available";
	else
	cout<<"\n "<<key<<"-> 0"<<seat<<" - Reserved";
	}
		else
	{								          	if(arr[i] == 0) 
	cout<<"\n "<<key<<"->"<<seat<<" - Available";
	else
	cout<<"\n "<<key<<"->"<<seat<<" - Reserved";
	}
	seat++; key++;
	}
           	}
			read.close();
    }
	if(recordFound == 0){
	cout<<"\n Seats Available :";
	char key = 'A';
	for(int i = 9; i<=29; i++)
	{
		if(i==9)
		cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
		else
		cout<<"\n "<<key<<" -> "<<i<<" - Available";
		key++;
	}
			}
    char choice;
   cout<<"\n\n Input your choice : ";
   cin>>choice;
     if( !(choice >= 'A' && choice <='U'))
   {
	cout<<"\n Error : Invalid Selection";
	cout<<"\n Please select correct value from menu A- U";
	cout<<"\n Press any key to continue";
	getchar();
	system("cls");
	bookTicket();
   }
     int index = (choice-65 );
   int isReserved = 1;
   if(arr[index] == 0) 
      isReserved = 0;
       if(isReserved ==1)
   {
   	cerr<<" Seat is already reserved";
   	cout<<"\n Please select other seat!!";
   	cout<<"\n Press any key to continue!!";
   	getchar();
   	system("cls");
   	bookTicket();
   }
     string name;
   cout<<"\n Enter your first name:";
   cin>>name;  
   int i=0;

   while(i<name.length())
   {
    if(name[i]>='1'&&name[i]<='9')
    {
    cout<<"ERROR--Invalid Name";
    cout<<"\nEnter name in alphabets only";
    bookTicket();
    }
    else
    {
        ofstream out;
       out.open("reservation.dat", ios::app);
	   if(out){
	   out<<choice<<":"<<name.c_str()<<"\n";
	   out.close();
	   cout<<"\n Seat reserved : "<< (choice-65) + 9 <<" successfully !!";
       break;
    }
    else
    {
    	cout<<"\n Error while saving reservation";
    }
    }
   }
cout<<"\n Press any key to continue..";
	getchar(); 
   
	return 0;		
}
int existingReservation()
{
    system("cls");
    cout<<"\n ----- Reservation Summary ---- \n";	
    ifstream read;
    read.open("reservation.dat");
     int seatreserve = 8;
     static int arr[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
     int recordFound =0; 
      if(read)
    {     
	string line;
	char key = 'A';
	int i = 9;
	        while(getline(read, line)) {
	   	   char temp = line[0];
	   	   int index = (temp - 65);
	   	   arr[index]=1;  
		   recordFound = 1;
	  }
        if(recordFound == 1)
        {
        cout<<"\n Reservation Summary:";
        char key = 'A';
        int seat = 9;
        for(int i = 0; i<=20; i++)
        {
        	if(arr[i] == 0) 
        	cout<<"\n "<<key<<"->"<<seat<<" - Available";
        	else
        	cout<<"\n "<<key<<"->"<<seat<<" - Reserved";
        	seat++;
        	key++;
        }
           	}
			read.close();
    }
    else
    {
    char key = 'A';
	for(int i = 9; i<=29; i++)
	{
	if(i==9)
	cout<<"\n "<<key<<" -> 0"<<i<<" - Available";
	else
	cout<<"\n "<<key<<" -> "<<i<<" - Available";
	key++;
	}
    }
    cout<<"\n Press any key to continue..";
    getchar(); getchar();
    return 0;	 
}
int main(int argc, char** argv) {
	while(1)
	{
		system("cls");
		cout<<"\t\t\tBus Reservation System\n";
		cout<<"----------------------------------------\n\n";
			cout<<"1. Reserve seat\n";
		cout<<"2. Check Existing Reservation\n";
		cout<<"0. Exit\n";
		int choice;
			cout<<"\n Enter you choice:";
		cin>>choice;
		switch(choice)
		{
			case 1: bookTicket(); break;
			case 2: existingReservation(); break;
			case 0: 
		        while(1)
		        {
				 system("cls");
		        	cout<<"\n Are you sure, you want to exit? y | n \n";
		        	char ex;
		        	cin>>ex;
		        	if(ex == 'y' || ex == 'Y')
		        	{
		        	    cout<<"program terminated";
		        		exit(0);
		        	}
		        	else if(ex == 'n' || ex == 'N')
                     		{
                     		 break;
                    		}
                     else{
                     	cout<<"\n Invalid choice !!!";
                     	getchar();
                     }
             	 }	break;
                   default: cout<<"\n Invalid choice. Enter again ";
                     getchar();
                 		}   		        	
	    
	}
	return 0;
}