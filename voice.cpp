#include<iostream.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
#include<stdio.h>
#include<string>
#include<process.h>
#include<time.h>
#include<fstream>
using namespace std;
class fst
{   char str[100];
	 public:
    void tis()
    { time_t ttime = time(0);
		char* dt = ctime(&ttime);
		cout<<dt;
    }
    void welc()
    { fstream file;
    	cout<<"\nEnter song name:-\t";
    	gets(str);
      cout<<"\t\t\t";
      time_t ttime = time(0);
      char* dt = ctime(&ttime);
    	string s="https://www.youtube.com/results?search_query=";
    	string r=s+str;
      file.open("History.txt",ios::out|ios::app);
		file<<"\n"<<dt<<"\t\t\t\t"<<r<<"\n";
      file.close();
    	ShellExecute(NULL,"open",r.c_str(),NULL,NULL,SW_SHOWNORMAL);
    }
};
class scnd: public fst
{   char ch;
	 public:
    void delay(unsigned int mseconds)
		{
      	clock_t goal = mseconds + clock();
    		while (goal > clock());
		}
    void rep()
	 {
    	 char k;
       LOOP2:cout<<"\nYou back Sir. Please type y to continue\t\t";
   	 cin>>k;
       cout<<"\t\t\t";
       tis();
       if(k=='Y'||k=='y')
   	 {
   		char h;
      	LOOP:PlaySound(TEXT("voicebooking-speech1.wav"),NULL,SND_SYNC);
    		cout<<"\n(Y/N)\t\t";
         cin>>ch;
    		if(ch=='y'||ch=='Y')
    		{
    			PlaySound(TEXT("voicebooking-speech3.wav"),NULL,SND_SYNC);
      	   welc();
            goto LOOP2;
         }
      	else
      	{
         	PlaySound(TEXT("voicebooking-speech5.wav"),NULL,SND_SYNC);
            cout<<"\n(Y/N)\t\t";
   			cin>>h;
            if(h=='y'||h=='Y')
         	{
            	char ch;
               ifstream file;
               file.open("History.txt");

               while ( !file.eof())
               {	file.get(ch);
                	cout<<ch;
               }
            }
            else
            {
            	PlaySound(TEXT("voicebooking-speech2.wav"),NULL,SND_SYNC);
            	cout<<"\nEnd Time:-\t\t";
            	tis();
            	delay(4000);
    				exit(0);
    			}
       	}
       }
       else
       {
       	PlaySound(TEXT("voicebooking-speech4.wav"),NULL,SND_SYNC);
         goto LOOP2;
       }
	}

};
int main()
{
   fstream file;
   scnd f;
   cout<<"********************WELCOME********************\n";
   PlaySound(TEXT("voicebooking-speech.wav"),NULL,SND_SYNC);
   cout<<"Start at:- \t\t";
   f.tis();
   f.welc();
   f.rep();

   getch();
   return 0;
}
