#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<graphics.h>
#include<windows.h>
using namespace std;
void front_screen();
void gotoxy (int x, int y)
{
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void school_name(int x=49,int y=1)
{
    gotoxy(x,y);
    cout<<"ITL  PUBLIC  SCHOOL";
    y++;
    x+=1;
    gotoxy(x,y);
    cout<<"SECTOR-9, DWARKA";
    y++;
    x+=3;
    gotoxy(x,y);
    cout<<"NEW DELHI";

}
void taskbar()
{
    int x=1,y=29;
    gotoxy(x,y);
    cout<<"        Press 10 for Logout        ";
    cout<<"Press 11 for Back          ";
    cout<<"Press 12 for Help          ";
    cout<<"Press 13 for Home        ";
}
void borderx(int x,int y,int z=120,char a='#')
{
    int i;
    gotoxy(x,y);
    for(i=0;i<z;i++)
    cout<<a;
}
void bordery(int x,int y,int z=120,char a='#')
{
    int i;
    for(i=0;i<z;i++)
    {
        gotoxy(x,y++);
        cout<<a;
    }
}

class Student
{
  public : int roll_no,clss,m1[6],m2[6],m3[6],m4[6],m5[6],fee,d,m,y;
  long long int mobile_no;
   char name[40],fname[40],mname[40],id[40],password[40],address[100],email[40],syllabus[5][200],assignment[5][2000];
   public :
	    void login_as_student(int x=49,int y=12)
	    {
	        system("cls");
	        char login[40];
	        int i;
	        static int counter=0;
	        if(counter>0)
            {
                gotoxy(40,19);
                cout<<"Login ID or password is incorrect! ";
                gotoxy(52,20);
                cout<<"Try again...";
            }
	        school_name();
	        borderx(0,7);
	        borderx(0,25);
	        gotoxy(40,y-1);
	        cout<<"* YOU HAVE CHOSEN LOGIN AS STUDENT *";
	        y+=3;
	        gotoxy(x,y);
	        cout<<"Enter login id : ";
	        y++;
	        gotoxy(x,y);
	        cout<<"Enter password : ";
	        x+=18;
	        y--;
	        gotoxy(x,y);
	        cin>>login;
	        y++;
	        gotoxy(x,y);
	        cin>>password;
	        Student e;
	        ifstream fin;
	        fin.open("Student.dat",ios::binary);
	        if(fin.good())
            {
                x-=18;
                y+=2;
                while(!fin.eof())
                {
                    fin.read((char *)&e,sizeof(e));
                    if((!(strcmp((const char *)e.id,(const char *)login)))&&(!(strcmp((const char *)e.password,(const char *)password))))
                    {
                        y+=2;
                        gotoxy(40,y-1);
                        cout<<"                                     ";
                        gotoxy(x,y);
                        cout<<"Login Successful :) ";
                        assigning_data(e);
                        fin.close();
                        delay(1500);
                        counter=0;
                        system("cls");
                        menu_for_student();
                        return;
                    }
                }
            }
            else
            {
                gotoxy(x,y);
                cout<<"Student file is not opened ";
                gotoxy(0,26);
                exit(0);
            }
            counter++;
            login_as_student();
	    }
        void assigning_data(Student e)
	    {
	        int i;
	        strcpy(this->address,e.address);
	        strcpy(this->email,e.email);
            strcpy(this->id,e.id);
	        strcpy(this->fname,e.fname);
	        strcpy(this->mname,e.mname);
	        strcpy(this->name,e.name);
	        strcpy(this->password,e.password);
	        this->fee=e.fee;
	        this->clss=e.clss;
	        this->roll_no=e.roll_no;
	        this->mobile_no=e.mobile_no;
	        this->d=e.d;
	        this->m=e.m;
	        this->y=e.y;
	        for(i=0;i<6;i++)
            {
                this->m1[i]=e.m1[i];
                this->m2[i]=e.m2[i];
                this->m3[i]=e.m3[i];
                this->m4[i]=e.m4[i];
                this->m5[i]=e.m5[i];
           }
            for(i=0;i<5;i++)
                strcpy(this->syllabus[i],e.syllabus[i]);
            for(i=0;i<5;i++)
                strcpy(this->assignment[i],e.assignment[i]);
	    }
	    void menu_for_student(int x=47,int y=7)
	    {
	        int choice;
	        school_name();
	        taskbar();
	        borderx(0,4,120,'_');
	        borderx(0,27,120,'_');
	        gotoxy(x,y-1);
	        cout<<"Welcome! "<<name;
	        y=y+2;
	        gotoxy(0,y);
	        cout<<" 1. PRESS 1 to see your full details."<<endl<<endl;
	        cout<<" 2. PRESS 2 to see your result."<<endl<<endl;
	        cout<<" 3. PRESS 3 to see your pending assignments."<<endl<<endl;
	        cout<<" 4. PRESS 4 to see your fee status."<<endl<<endl;
	        cout<<" 5. PRESS 5 to see your syllabus."<<endl<<endl;
	        cout<<" 6. PRESS 6 to change your password."<<endl<<endl<<endl<<endl;
	        cout<<" For any further query please PRESS 7 to see contact details."<<endl<<endl<<endl;
	        cout<<" ENTER YOUR CHOICE HERE : ";
	        gotoxy(26,y+=17);
	        cin>>choice;
            switch(choice)
            {
                case 1 : system("cls");
                        showing_details();
                        break;
                case 2 :system("cls");
                        showing_result();
                        break;
                case 3:system("cls");
                        show_pending_assignment();
                        break;
                case 4 :system("cls");
                        show_fee_status();
                        break;
                case 5 :system("cls");
                        show_syllabus();
                        break;
                case 6 :system("cls");
                        changing_password();
                        break;
                case 10 :system("cls");
                         front_screen();
                         break;
                case 11 :system("cls");
                         menu_for_student();
                         break;
                case 12  :
                case 7   :help();
                         system("cls");
                         menu_for_student();
                         break;
                case 13 :system("cls");
                         menu_for_student();
                         break;
                default : system("cls");
                          gotoxy(0,y+=12);
                          cout<<"ENTER A VALID ENTERY!";
                          menu_for_student();
            }
	    }
	    void showing_details(int x=39,int y=6)
	    {
	        int choice;
	        int i;
	        school_name();
	        taskbar();
	        borderx(0,5,120,'-');
	        borderx(0,27,120,'-');
	        gotoxy(52,6);
	        cout<<"* DETAILS *";
	        gotoxy(x,y+=2);
            cout<<"NAME                :         ";
            for(i=0;i<strlen(name);i++)
                putchar(toupper(name[i]));
            gotoxy(x,y+=2);
            cout<<"FATHER NAME         :         ";
            for(i=0;i<strlen(fname);i++)
                putchar(toupper(fname[i]));
            gotoxy(x,y+=2);
            cout<<"MOTHER NAME         :         ";
            for(i=0;i<strlen(mname);i++)
                putchar(toupper(mname[i]));
            gotoxy(x,y+=2);
            cout<<"DATE OF BIRTH       :         "<<d<<"/"<<m<<"/"<<y;
            gotoxy(x,y+=2);
            cout<<"CLASS               :         "<<clss;
            gotoxy(x,y+=2);
            cout<<"ROLL NUMBER         :         "<<roll_no;
            gotoxy(x,y+=2);
            cout<<"MOBILE NUMBER       :         "<<mobile_no;
            gotoxy(x,y+=2);
            cout<<"EMAIL               :         ";
            for(i=0;i<strlen(email);i++)
                putchar(toupper(email[i]));
            gotoxy(x,y+=2);
            cout<<"ADDRESS             :         ";
            for(int counter=1,i=0;i<strlen(address);i++)
            {
                if(counter==51)
                {
                    for(counter=0;counter<68;counter++)
                        cout<<" ";
                    counter=0;
                }
                putchar(toupper(address[i]));
                counter++;
            }
            gotoxy(35,y+=2);
            cout<<"ENTER YOUR CHOCE HERE : ";
            cin>>choice;
            switch(choice)
	        {
	            case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_student();
                          break;
                case 12 : help();
                          system("cls");
                          showing_details();
                          break;
                case 13 : system("cls");
                          menu_for_student();
                          break;
                default : system("cls");
                          showing_details();
            }
	    }
	    void showing_result(int x=48,int y=6)
	    {
	        int i,j;
            school_name();
            borderx(0,5);
            borderx(0,27);
            gotoxy(48,28);
            cout<<"Press any key to go back ";
            gotoxy(x,y++);
            cout<<"*     SHOWING RESULT      *";
            gotoxy(x+4,y++);
            cout<<"NAME : "<<name;
            gotoxy(x+4,y++);
            cout<<"Class : "<<clss;
            for(y=9,x=1;y<24;y+=2)
                borderx(x,y,118,'_');
            bordery(0,10,14,'|');
            bordery(118,10,14,'|');
            for(y=10,x=18;x<104;x+=17)
                bordery(x,y,14,'|');
            x=3;
            y=8;
            gotoxy(x,y+=2);
            cout<<"  SUBJECTS  ";
            gotoxy(x,y+=2);
            cout<<"  ENGLISH  ";
            gotoxy(x,y+=2);
            cout<<"  PHYSICS  ";
            gotoxy(x,y+=2);
            cout<<"  CHEMISTRY  ";
            gotoxy(x,y+=2);
            cout<<"  MATHS  ";
            gotoxy(x,y+=2);
            cout<<"  COMP.SC. ";
            gotoxy(--x,y+=2);
            cout<<"TOTAL PERCENTAGE";
            x=8;
            y=10;
            gotoxy(x+=17,y);
            cout<<"CT 1";
            gotoxy(x+=17,y);
            cout<<"CT 2";
            gotoxy(x+=15,y);
            cout<<"MID TERM";
            gotoxy(x+=19,y);
            cout<<"CT 3";
            gotoxy(x+=17,y);
            cout<<"CT 4";
            gotoxy(x+=13,y);
            cout<<"FINAL TERM";
            x=26;
            y=12;
            for(i=0;i<6;i++,x+=17)
            {
                gotoxy(x,y);
                cout<<m1[i];
            }
            x=26;
            y+=2;
            for(i=0;i<6;i++,x+=17)
            {
                gotoxy(x,y);
                cout<<m2[i];
            }
            x=26;
            y+=2;
            for(i=0;i<6;i++,x+=17)
            {
                gotoxy(x,y);
                cout<<m3[i];
            }
            x=26;
            y+=2;
            for(i=0;i<6;i++,x+=17)
            {
                gotoxy(x,y);
                cout<<m4[i];
            }
            x=26;
            y+=2;
            for(i=0;i<6;i++,x+=17)
            {
                gotoxy(x,y);
                cout<<m5[i];
            }
            x=26;
            y+=2;
            gotoxy(x,y);
            cout<<(m1[0]+m2[0]+m3[0]+m4[0]+m5[0])/5;
            x+=17;
            gotoxy(x,y);
            cout<<(m1[1]+m2[1]+m3[1]+m4[1]+m5[1])/5;
            x+=17;
            gotoxy(x,y);
            cout<<(m1[2]+m2[2]+m3[2]+m4[2]+m5[2])/5;
            x+=17;
            gotoxy(x,y);
            cout<<(m1[3]+m2[3]+m3[3]+m4[3]+m5[3])/5;
            x+=17;
            gotoxy(x,y);
            cout<<(m1[4]+m2[4]+m3[4]+m4[4]+m5[4])/5;
            x+=17;
            gotoxy(x,y);
            cout<<(m1[5]+m2[5]+m3[5]+m4[5]+m5[5])/5;
            gotoxy(52,y+=3);
            cout<<"OVERALL PERCENTAGE : "<<(float)((((m1[0]+m2[0]+m3[0]+m4[0]+m5[0])/5)+((m1[1]+m2[1]+m3[1]+m4[1]+m5[1])/5)+((m1[2]+m2[2]+m3[2]+m4[2]+m5[2])/5)+((m1[3]+m2[3]+m3[3]+m4[3]+m5[3])/5)+((m1[4]+m2[4]+m3[4]+m4[4]+m5[4])/5)+((m1[5]+m2[5]+m3[5]+m4[5]+m5[5])/5))/6);
            _getch();
            system("cls");
            menu_for_student();
	    }
	    void show_pending_assignment(int x=48,int y=8)
	    {
	        int choice;
	        school_name();
	        taskbar();
	        borderx(0,7);
	        borderx(0,26);
            gotoxy(52,9);
            cout<<"* ASSIGNMENT *";
            gotoxy(1,12);
            cout<<"Press 1 to see Physics assignment ";
            gotoxy(1,14);
            cout<<"Press 2 to see Chemistry assignment ";
            gotoxy(1,16);
            cout<<"Press 3 to see Maths assignment ";
            gotoxy(1,18);
            cout<<"Press 4 to see English assignment ";
            gotoxy(1,20);
            cout<<"Press 5 to see Computer Science assignment ";
            gotoxy(1,22);
            cout<<"Enter your choice here : ";
            cin>>choice;
            switch(choice)
            {
                case 1 :
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* PHYSICS ASSIGNMENT *";
                            gotoxy(0,11);
                            cout<<assignment[0];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_pending_assignment();

                        break;
                case 2 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* CHEMISTRY ASSIGNMENT *";
                            gotoxy(0,11);
                            cout<<assignment[1];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_pending_assignment();
                        }
                        break;
                case 3 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* MATHS ASSIGNMENT *";
                            gotoxy(0,11);
                            cout<<assignment[2];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_pending_assignment();
                        }
                        break;
                case 4 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* ENGLISH ASSIGNMENT *";
                            gotoxy(0,11);
                            cout<<assignment[3];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_pending_assignment();
                        }
                        break;
                case 5 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* COPUTER SCIENCE ASSIGNMENT *";
                            gotoxy(0,11);
                            cout<<assignment[4];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_pending_assignment();
                        }
                        break;
                case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_student();
                          break;
                case 12 : help();
                          system("cls");
                          show_pending_assignment();
                          break;
                case 13 : system("cls");
                          menu_for_student();
                          break;
                default : system("cls");
                          gotoxy(1,24);
                          cout<<"Enter a valid entry ";
                          show_pending_assignment();

            }
	    }
	    void show_fee_status(int x=52,int y=10)
	    {
	        int choice;
            school_name();
            taskbar();
            borderx(0,7);
            borderx(0,27);
            gotoxy(x,y);
            cout<<"FEE STATUS";
            x-=20;
            y+=4;
            gotoxy(x,y);
            cout<<"Pending fee : "<<fee;
            gotoxy(x,y+=2);
            cout<<"Enter your choice here : ";
            gotoxy(x+=24,y);
            cin>>choice;
            switch(choice)
	        {
	            case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_student();
                          break;
                case 12 : help();
                          system("cls");
                          show_fee_status();
                          break;
                case 13 : system("cls");
                          menu_for_student();
                          break;
                default : system("cls");
                          gotoxy(x-=24,y+=2);
                          cout<<"Enter a valid entry ";
                          show_fee_status();

	        }
	    }
	    void show_syllabus()
	    {
	        int choice;
	        school_name();
	        taskbar();
	        borderx(0,7);
	        borderx(0,26);
            gotoxy(52,9);
            cout<<"* SYLLABUS *";
            gotoxy(1,12);
            cout<<"Press 1 to see Physics syllabus ";
            gotoxy(1,14);
            cout<<"Press 2 to see Chemistry syllabus ";
            gotoxy(1,16);
            cout<<"Press 3 to see Maths syllabus ";
            gotoxy(1,18);
            cout<<"Press 4 to see English syllabus ";
            gotoxy(1,20);
            cout<<"Press 5 to see Computer Science syllabus ";
            gotoxy(1,22);
            cout<<"Enter your choice here : ";
            cin>>choice;
            switch(choice)
            {
                case 1 :
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* PHYSICS SYLLABUS *";
                            gotoxy(0,11);
                            puts(syllabus[0]);
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_syllabus();

                        break;
                case 2 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* CHEMISTRY SYLLABUS *";
                            gotoxy(0,11);
                            cout<<syllabus[1];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_syllabus();
                        }
                        break;
                case 3 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* MATHS SYLLABUS *";
                            gotoxy(0,11);
                            cout<<syllabus[2];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_syllabus();
                        }
                        break;
                case 4 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* ENGLISH SYLLABUS *";
                            gotoxy(0,11);
                            cout<<syllabus[3];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_syllabus();
                        }
                        break;
                case 5 :{
                            system("cls");
                            school_name();
                            borderx(0,7);
                            borderx(0,27);
                            gotoxy(48,9);
                            cout<<"* COPUTER SCIENCE SYLLABUS *";
                            gotoxy(0,11);
                            cout<<syllabus[4];
                            gotoxy(50,28);
                            cout<<"Press any key to go back ";
                            _getch();
                            system("cls");
                            show_syllabus();
                        }
                        break;
                case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_student();
                          break;
                case 12 : help();
                          system("cls");
                          show_syllabus();
                          break;
                case 13 : system("cls");
                          menu_for_student();
                          break;
                default : system("cls");
                          gotoxy(1,24);
                          cout<<"Enter a valid entry ";
                          show_syllabus();

            }
	    }
	    void changing_password(int x=52,int y=9)
	    {
	        int choice;
	        char p1[40],p2[40],p[40];
            school_name();
            taskbar();
            borderx(0,7,120,'~');
            borderx(0,26,120,'~');
            gotoxy(x,y);
            cout<<"* CHANGING PASSWORD * ";
            gotoxy(x-=28,y+=2);
            cout<<"Enter current password  :   ";
            gotoxy(x,y+=2);
            cout<<"Enter new password      :   ";
            gotoxy(x,y+=2);
            cout<<"Re enter new password   :   ";
            y=9;
            gotoxy(x+=27,y+=2);
            cin>>p;
            gotoxy(x,y+=2);
            cin>>p1;
            gotoxy(x,y+=2);
            cin>>p2;
            y++;
            if(strcmp(password,p))
            {
                system("cls");
                gotoxy(x-=27,y+=2);
                cout<<"YOUR NEW AND OLD PASSWORD DOESN'T MATCH!";
                changing_password();
            }
            else if(strcmp(p1,p2))
            {
                system("cls");
                gotoxy(x-=27,y+=3);
                cout<<"YOUR NEW PASSWORD AND CONFIRMATION PASSWORD DOESN'T MATCH!";
                changing_password();
            }
            else
            {
                Student s,e;
                ifstream fin;
                fin.open("Student.dat",ios::binary);
                ofstream fout;
                fout.open("TEMP.dat",ios::binary | ios::trunc);
                while(!fin.eof())
                {
                    fin.read((char *)&e,sizeof(e));
                    if(roll_no!=e.roll_no)
                        fout.write((char *)&e,sizeof(e));
                    else
                    {
                        strcpy(s.password,p1);
                         int i;
	                     strcpy(s.address,e.address);
                         strcpy(s.email,e.email);
                         strcpy(s.id,e.id);
	                     strcpy(s.fname,e.fname);
	                     strcpy(s.mname,e.mname);
	                     strcpy(s.name,e.name);
	                     s.fee=e.fee;
	                     s.clss=e.clss;
	                     s.roll_no=e.roll_no;
	                     s.mobile_no=e.mobile_no;
	                     s.d=e.d;
	                     s.m=e.m;
	                     s.y=e.y;
	                     for(i=0;i<6;i++)
                         {
                             s.m1[i]=e.m1[i];
                             s.m2[i]=e.m2[i];
                             s.m3[i]=e.m3[i];
                             s.m4[i]=e.m4[i];
                             s.m5[i]=e.m5[i];
                        }
                         for(i=0;i<5;i++)
                             strcpy(s.syllabus[i],e.syllabus[i]);
                         for(i=0;i<5;i++)
                             strcpy(s.assignment[i],e.assignment[i]);

                        fout.write((char *)&s,sizeof(s));
                    }
                }
                fin.close();
                fout.close();
                remove("Student.dat");
                rename("TEMP.dat","Student.dat");
                gotoxy(x-27,y+=3);
                cout<<"                                                            ";
                gotoxy(x-27,--y);
                cout<<"   YOUR PASSWORD HAS BEEN CHANGED                           ";
                strcpy(password,p1);
                delay(1500);
                system("cls");
                menu_for_student();
            }
        }
	    void help(int x=52,int y=8)
	    {
            system("cls");
            school_name();
            borderx(0,7);
            borderx(0,27);
            gotoxy(x,y);
            cout<<"* HELP *";
            y+=2;
            x-=20;
            gotoxy(0,y);
            cout<<"------------If you are facing some problem or if find something wrong in details then please contact school-------------";
            y+=4;
            x+=17;
            gotoxy(x,y);
            cout<<" CONTACT DETAILS ";
            x-=15;
            y+=2;
            gotoxy(x,y++);
            cout<<"Helpline Number : 9910245785 ";
            gotoxy(x,y++);
            cout<<"                  9910245788 ";
            gotoxy(x,y+=1);
            cout<<"Email address   : itlpschool@yahoo.com ";
            y+=3;
            gotoxy(x,y);
            cout<<"To go back press any key ";
            _getch();
	    }
};

class Teacher : protected Student
{
    char user_id[40],user_password[40];
    public :
         void login_as_teacher(int x=49,int y=12)
	    {
	        system("cls");
            char login[40],password[40];
	        int i;
	        static int counter=0;
	        if(counter)
            {
                gotoxy(40,19);
                cout<<"Login ID or password is incorrect! ";
                gotoxy(52,20);
                cout<<"Try again...";
            }
	        school_name();
	        borderx(0,7);
	        borderx(0,25);
	        gotoxy(40,y);
	        cout<<"* YOU HAVE CHOSEN LOGIN AS TEACHER *";
	        y+=3;
	        gotoxy(x,y);
	        cout<<"Enter login id : ";
	        y++;
	        gotoxy(x,y);
	        cout<<"Enter password : ";
	        x+=18;
	        y--;
	        gotoxy(x,y);
	        cin>>login;
	        y++;
	        gotoxy(x,y);
	        cin>>password;
	        Teacher e;
	        ifstream fin;
	        fin.open("Teacher.dat",ios::binary);
	        if(fin.good())
            {
                x-=18;
                y+=2;
                while(!fin.eof())
                {
                    fin.read((char *)&e,sizeof(e));
                    if((!(strcmp((const char *)e.user_id,(const char *)login)))&&(!(strcmp((const char *)e.user_password,(const char *)password))))
                    {
                        y+=2;
                        gotoxy(40,y-1);
                        cout<<"                                     ";
                        gotoxy(x,y);
                        cout<<"Login Successful :) ";
                        fin.close();
                        delay(1500);
                        system("cls");
                        counter=0;
                        strcpy(this->user_password,e.user_password);
                        strcpy(this->user_id,e.user_id);
                        menu_for_teacher();
                        return;
                    }
                }
            }
            else
            {
                gotoxy(49,19);
                cout<<"Teacher file is not opened ";
                gotoxy(0,26);
                exit(0);
            }
            counter++;
            login_as_teacher();
	    }
	    void menu_for_teacher(int x=47,int y=5)
	    {
	        int choice;
	        school_name();
	        taskbar();
	        borderx(0,4,120,'_');
	        borderx(0,27,120,'_');
	        gotoxy(x,y);
	        cout<<"        Welcome! ";
	        y=y+2;
	        gotoxy(0,y);
	        cout<<" 1. PRESS 1 to modify full details of any student."<<endl<<endl;
	        cout<<" 2. PRESS 2 to modify result."<<endl<<endl;
	        cout<<" 3. PRESS 3 to add a new student."<<endl<<endl;
	        cout<<" 4. PRESS 4 to modify pending assignments."<<endl<<endl;
	        cout<<" 5. PRESS 5 to modify fee status."<<endl<<endl;
	        cout<<" 6. PRESS 6 to remove a student."<<endl<<endl;
	        cout<<" 7. PRESS 7 to modify syllabus."<<endl<<endl;
	        cout<<" 8. PRESS 8 to change your password."<<endl<<endl<<endl;
	        cout<<" For any further query please PRESS 9 to see contact details."<<endl<<endl;
	        cout<<" ENTER YOUR CHOICE HERE : ";
	        gotoxy(26,y+=19);
	        cin>>choice;
            switch(choice)
            {
                case 1 : system("cls");
                        modifing_details();
                        break;
                case 2 :system("cls");
                        modifing_result();
                        break;
                case 3 :system("cls");
                        add_a_student();
                        break;
                case 4 :system("cls");
                        modifing_assignmnets();
                        break;
                case 5 :system("cls");
                        modify_fee_status();
                        break;
                case 6 :system("cls");
                        remove_a_student();
                        break;
                case 7 :system("cls");
                        modifing_syllabus();
                        break;
                case 8 :system("cls");
                        changing_password_for_teacher();
                        break;
                case 10 :system("cls");
                         front_screen();
                         break;
                case 11 :system("cls");
                         menu_for_teacher();
                         break;
                case 12  :
                case 9   :help();
                         system("cls");
                         menu_for_teacher();
                         break;
                case 13 :system("cls");
                         menu_for_teacher();
                         break;
                default : system("cls");
                          gotoxy(0,y+=12);
                          cout<<"ENTER A VALID ENTERY!";
                          menu_for_teacher();
            }
	    }
	    void changing_password_for_teacher(int x=52,int y=9)
	    {
	        int choice;
	        char p1[40],p2[40],p[40];
            school_name();
            taskbar();
            borderx(0,7,120,'~');
            borderx(0,26,120,'~');
            gotoxy(x,y);
            cout<<"* CHANGING PASSWORD * ";
            gotoxy(x-=28,y+=2);
            cout<<"Enter current password  :   ";
            gotoxy(x,y+=2);
            cout<<"Enter new password      :   ";
            gotoxy(x,y+=2);
            cout<<"Re enter new password   :   ";
            y=9;
            gotoxy(x+=27,y+=2);
            cin>>p;
            gotoxy(x,y+=2);
            cin>>p1;
            gotoxy(x,y+=2);
            cin>>p2;
            y++;
            if(strcmp(user_password,p))
            {
                system("cls");
                gotoxy(x-27,y+=2);
                cout<<"YOUR NEW AND OLD PASSWORD DOESN'T MATCH!";
                changing_password_for_teacher();
            }
            else if(strcmp(p1,p2))
            {
                system("cls");
                gotoxy(x-=27,y+=3);
                cout<<"YOUR NEW PASSWORD AND CONFIRMATION PASSWORD DOESN'T MATCH!";
                changing_password_for_teacher();
            }
            else
            {
                remove("Teacher.dat");
                ofstream fout;
                fout.open("Teacher.dat",ios::binary);
                Teacher t;
                strcpy(t.user_id,user_id);
                strcpy(t.user_password,p1);
                fout.write((char *)&t,sizeof(t));
                fout.close();
                gotoxy(x-30,y+=3);
                cout<<"                                                            ";
                gotoxy(x-30,--y);
                cout<<"   YOUR PASSWORD HAS BEEN CHANGED                           ";
                strcpy(password,p1);
                delay(1500);
                system("cls");
                menu_for_teacher();
            }
	    }
        void add_a_student(int x=47,int y=9)
	    {
	        int choice;
	        school_name();
	        taskbar();
	        borderx(0,7);
	        borderx(0,27);
	        gotoxy(x,y);
	        cout<<"* ADDING A NEW STUDENT *";
	        gotoxy(30,17);
	        cout<<"Enter 1 to add a new student else use taskbar : ";
	        cin>>choice;
	        switch(choice)
            {
                case 1 :{ int i;
                         system("cls");
                         school_name();
                         borderx(0,5);
                         borderx(0,27);
                         Student e,s;
                         x=39;
                         y=6;
                         gotoxy(49,6);
	                              cout<<"* ADDING A NEW STUDENT *";
	                              gotoxy(x,y+=2);
                                  cout<<"NAME                :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"FATHER NAME         :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"MOTHER NAME         :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"DATE OF BIRTH       :            /  /";
                                  gotoxy(x,y+=2);
                                  cout<<"CLASS               :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"ROLL NUMBER         :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"MOBILE NUMBER       :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"EMAIL               :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"ADDRESS             :         ";
                                  y-=18;
                                  x+=31;
                                  gets(e.name);
                                  gotoxy(x,y+=2);
                                  gets(e.name);
                                  gotoxy(x,y+=2);
                                  gets(e.fname);
                                  gotoxy(x,y+=2);
                                  gets(e.mname);
                                  gotoxy(x,y+=2);
                                  cin>>e.d;
                                  gotoxy(x+=3,y);
                                  cin>>e.m;
                                  gotoxy(x+=3,y);
                                  cin>>e.y;
                                  x=x-6;
                                  gotoxy(x,y+=2);
                                  cin>>e.clss;
                                  gotoxy(x,y+=2);
                                  cin>>e.roll_no;
                                  gotoxy(x,y+=2);
                                  cin>>e.mobile_no;
                                  gets(e.email);
                                  gotoxy(x,y+=2);
                                  gets(e.email);
                                  gotoxy(x,y+=2);
                                  gets(e.address);
                                  system("cls");
                                  x=49;
                                  y=12;
                                  school_name();
                                  borderx(0,7);
	                              borderx(0,25);
	                              gotoxy(40,8);
	                              cout<<"          * ADDING A NEW STUDENT *";
	                              y+=3;
	                              gotoxy(x,y);
	                              cout<<"Your login id  :  ID"<<e.roll_no;
	                              y++;
	                              gotoxy(x,y);
	                              cout<<"Enter password : ";
	                              x+=18;
	                              gotoxy(x,y);
	                              gets(e.password);
	                              strcpy(e.id,"ID02");
                                  for(i=0;i<6;i++)
                                  {
                                  e.m1[i]=0;
                                  e.m2[i]=0;
                                  e.m3[i]=0;
                                  e.m4[i]=0;
                                  e.m5[i]=0;
                                  }
                                  for(i=0;i<5;i++)
                                  strcpy(e.syllabus[i],"NONE");
                                  for(i=0;i<5;i++)
                                  strcpy(e.assignment[i],"NONE");
                                  ifstream fin;
                                  fin.open("Student.dat",ios::binary);
                                  while(!fin.eof())
                                  {
                                        fin.read((char *)&s,sizeof(s));
                                        if(s.roll_no==e.roll_no)
                                        {
                                            gotoxy(x-=20,y+=2);
                                            cout<<"RECORD ALREADY EXISTS ";
                                            fin.close();
                                            delay(1000);
                                            system("cls");
                                            menu_for_teacher();
                                            break;
                                        }
                                  }
                                fin.close();
                                ofstream fout;
                                fout.open("Student.dat",ios::binary | ios::app);
                                fout.write((char *)&e,sizeof(e));
                                fout.close();
                                gotoxy(x-=20,y+=2);
                                cout<<"    STUDENT HAS ADDED";
                                delay(1000);
                                system("cls");
                                menu_for_teacher();
                                break;
                         }
                case 10 :system("cls");
                         front_screen();
                         break;
                case 11 :system("cls");
                         menu_for_teacher();
                         break;
                case 12  :
                case 9   :help();
                         system("cls");
                         add_a_student();
                         break;
                case 13 :system("cls");
                         menu_for_teacher();
                         break;
                default : system("cls");
                          gotoxy(52,20);
                          cout<<"ENTER A VALID ENTERY!";
                          add_a_student();
            }

	    }
	    void remove_a_student()
	    {
	        int choice,i,counter=0;
	        school_name();
	        taskbar();
	        borderx(0,7);
	        borderx(0,27);
	        gotoxy(52,10);
	        cout<<"* REMOVING A STUDENT *";
	        gotoxy(30,17);
	        cout<<"Enter 1 to remove a student else use taskbar : ";
	        cin>>choice;
	        switch(choice)
            {
                case 1 :{
                        system("cls");
                        school_name();
                        borderx(0,7);
                        borderx(0,27);
                        gotoxy(52,9);
                        cout<<"* REMOVING A STUDENT *";
                        gotoxy(27,17);
                        cout<<"Enter roll number of the student that you want to remove : ";
                        cin>>i;
                        ifstream fin;
                        ofstream fout;
                        fin.open("Student.dat",ios::binary);
                        fout.open("Temp.dat",ios::binary | ios::trunc);
                        Student s;
                        while(!fin.eof())
                        {
                            fin.read((char *)&s,sizeof(s));
                            if(s.roll_no==i)
                                counter++;
                            else
                                fout.write((char *)&s,sizeof(s));
                        }
                        fin.close();
                        fout.close();
                        remove("Student.dat");
                        rename("Temp.dat","Student.dat");
                        gotoxy(52,20);
                        if(counter==0)
                            cout<<"Student not found!";
                        else
                            cout<<"Student has deleted!";
                        delay(1000);
                        system("cls");
                        menu_for_teacher();
                        break;
                        }
                case 10 :system("cls");
                         front_screen();
                         break;
                case 11 :system("cls");
                         menu_for_teacher();
                         break;
                case 12  :
                case 9   :help();
                         system("cls");
                         remove_a_student();
                         break;
                case 13 :system("cls");
                         menu_for_teacher();
                         break;
                default : system("cls");
                          gotoxy(50,23);
                          cout<<"ENTER A VALID ENTERY!";
                          remove_a_student();
            }

	    }
	    void modifing_details(int x=52,int y=10)
	    {
	        int choice;
	        school_name();
	        taskbar();
	        borderx(0,8);
	        borderx(0,27);
	        gotoxy(x,y);
	        cout<<"* MODIGING DETAILS *";
	        x-=30;
	        y+=4;
	        gotoxy(x,y);
	        cout<<"Enter 1 to modify details or use taskbar to navigate to other details : ";
	        cin>>choice;
	        switch(choice)
	        {
                case 1  :{ system("cls");
                          int counter=0;
                          x=39;
                          y=9;
                          int choice;
                          int i;
                          Student e,s;
	                      school_name();
	                      taskbar();
	                      borderx(0,7,120);
	                      borderx(0,26,120);
	                      gotoxy(52,9);
                          cout<<"* MODIGING DETAILS *";
	                      int roll;
	                      gotoxy(35,16);
	                      cout<<"Enter the roll number of the student : ";
	                      cin>>roll;
	                      ifstream fin;
	                      ofstream fout;
	                      fin.open("Student.dat",ios::binary);
	                      fout.open("TEMP.dat",ios::binary | ios::trunc);
	                      while(!fin.eof())
                          {
                              fin.read((char *)&e,sizeof(e));
                              if(e.roll_no!=roll)
                                  fout.write((char *)&e,sizeof(e));
                              else
                              {
                                  if(!counter)
                                  {
                                   int i;
                                  system("cls");
                                  school_name();
                                  borderx(0,5);
                                  borderx(0,27);
                                  x=39;
                                  y=6;
                                  gotoxy(49,6);
	                              cout<<"* MODIFING DETAILS *";
	                              gotoxy(x,y+=2);
                                  cout<<"NAME                :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"FATHER NAME         :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"MOTHER NAME         :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"DATE OF BIRTH       :            /  /";
                                  gotoxy(x,y+=2);
                                  cout<<"CLASS               :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"ROLL NUMBER         :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"MOBILE NUMBER       :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"EMAIL               :         ";
                                  gotoxy(x,y+=2);
                                  cout<<"ADDRESS             :         ";
                                  y-=18;
                                  x+=31;
                                  gets(s.name);
                                  gotoxy(x,y+=2);
                                  gets(s.name);
                                  gotoxy(x,y+=2);
                                  gets(s.fname);
                                  gotoxy(x,y+=2);
                                  gets(s.mname);
                                  gotoxy(x,y+=2);
                                  cin>>s.d;
                                  gotoxy(x+=3,y);
                                  cin>>s.m;
                                  gotoxy(x+=3,y);
                                  cin>>s.y;
                                  x=x-6;
                                  gotoxy(x,y+=2);
                                  cin>>s.clss;
                                  gotoxy(x,y+=2);
                                  cin>>s.roll_no;
                                  gotoxy(x,y+=2);
                                  cin>>s.mobile_no;
                                  gets(s.email);
                                  gotoxy(x,y+=2);
                                  gets(s.email);
                                  gotoxy(x,y+=2);
                                  gets(s.address);
                                  counter++;
                                  strcpy(s.id,e.id);
                                  strcpy(s.password,e.password);
                                   for(i=0;i<6;i++)
                                   {
                                        s.m1[i]=e.m1[i];
                                        s.m2[i]=e.m2[i];
                                        s.m3[i]=e.m3[i];
                                        s.m4[i]=e.m4[i];
                                        s.m5[i]=e.m5[i];
                                   }
                                   for(i=0;i<5;i++)
                                        strcpy(s.syllabus[i],e.syllabus[i]);
                                   for(i=0;i<5;i++)
                                        strcpy(s.assignment[i],e.assignment[i]);
                                    s.fee=e.fee;
                                  fout.write((char *)&s,sizeof(s));
                                  }
                              }
                        }
                          fin.close();
                          fout.close();
                          remove("Student.dat");
                          rename("TEMP.dat","Student.dat");
                          system("cls");
                          school_name();
                          taskbar();
                          borderx(0,8);
                          borderx(0,27);
                          gotoxy(52,10);
                          cout<<"* MODIGING DETAILS *";
                          gotoxy(50,16);
                          if(counter==0)
                            cout<<"RECORD NOT FOUND";
                          else
                            cout<<"DETAILS HAVE MODIFIED :) ";
                          delay(1000);
                          system("cls");
                          menu_for_teacher();}
                          break;
                case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_teacher();
                          break;
                case 12 : help();
                          system("cls");
                          modifing_details();
                          break;
                case 13 : system("cls");
                          menu_for_teacher();
                          break;
                default : system("cls");
                          gotoxy(x+=30,y+=2);
                          cout<<"Enter a valid entry :(";
                          modifing_details();
	        }
	    }
	    void modify_fee_status(int x=50,int y=10)
	    {
	        int choice;
	        school_name();
	        taskbar();
	        borderx(0,8);
	        borderx(0,27);
	        gotoxy(x,y);
	        cout<<"* MODIGING FEE STATUS *";
	        x-=25;
	        y+=7;
	        gotoxy(x,y);
	        cout<<"Enter 1 to modify fee status or use taskbar to navigate to other details : ";
	        cin>>choice;
	        switch(choice)
	        {
                case 1  :{ system("cls");

                          x=48;
                          y=15;
                          int counter=0;
                          int i;
                          Student e;
	                      school_name();
	                      taskbar();
	                      int roll;
	                      borderx(0,6);
	                      borderx(0,27);
	                      gotoxy(52,8);
	                      cout<<"* MODIFING FEE STATUS *";
	                      gotoxy(41,16);
	                      cout<<"Enter the roll number of the student : ";
	                      cin>>roll;
	                      ifstream fin;
	                      ofstream fout;
	                      fin.open("Student.dat",ios::binary);
	                      fout.open("TEMP.dat",ios::binary | ios::trunc);
	                      while(!fin.eof())
                          {
                              fin.read((char *)&e,sizeof(e));
                              if(e.roll_no!=roll)
                                  fout.write((char *)&e,sizeof(e));
                              else
                              {
                                  if(!counter)
                                  {
                                  system("cls");
                                  school_name();
                                  taskbar();
                                  borderx(0,6);
                                  borderx(0,27);
                                  gotoxy(52,8);
                                  cout<<"* MODIFING FEE STATUS *";
	                              gotoxy(x,y);
                                  cout<<"Enter fee pending : ";
                                  cin>>e.fee;
                                  fout.write((char *)&e,sizeof(e));
                                  counter++;
                                  }
                              }
                         }
                          fin.close();
                          fout.close();
                          remove("Student.dat");
                          rename("TEMP.dat","Student.dat");
                          if(counter)
                          {
                            gotoxy(50,18);
                            cout<<"FEE STATUS HAVE MODIFIED :) ";
                          }
                          else
                          {
                            gotoxy(50,18);
                            cout<<"RECORD NOT FOUND :( ";
                          }
                          delay(1000);
                          system("cls");
                          menu_for_teacher();}
                          break;
                case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_teacher();
                          break;
                case 12 : help();
                          system("cls");
                          modify_fee_status();
                          break;
                case 13 : system("cls");
                          menu_for_teacher();
                          break;
                default : system("cls");
                          gotoxy(x+=25,y+=3);
                          cout<<"Enter a valid entry :(";
                          modify_fee_status();
	    }
	    }
	    void modifing_assignmnets()
	    {
            int choice;
	        school_name();
	        taskbar();
	        borderx(0,6);
	        borderx(0,27);
	        gotoxy(52,8);
	        cout<<"* MODIGING ASSIGNMENTS *";
	        gotoxy(27,17);
	        cout<<"Enter 1 to modify assignments or use taskbar to navigate to other details : ";
	        cin>>choice;
	        switch(choice)
	        {
                case 1  :{ system("cls");
                          int i,c,counter=0;
                          Student e;
	                      school_name();
	                      taskbar();
	                      int roll;
	                      school_name();
	                      borderx(0,6);
	                      borderx(0,27);
	                      gotoxy(52,8);
                          cout<<"* MODIGING ASSIGNMENTS *";
	                      gotoxy(40,16);
	                      cout<<"Enter the roll number of the student : ";
	                      cin>>roll;
	                      ifstream fin;
	                      ofstream fout;
	                      fin.open("Student.dat",ios::binary);
	                      fout.open("TEMP.dat",ios::binary | ios::trunc);
	                      while(!fin.eof())
                          {
                              fin.read((char *)&e,sizeof(e));
                              if(e.roll_no!=roll)
                                  fout.write((char *)&e,sizeof(e));
                              else
                              {
                                  if(!counter)
                                  {
                                  counter++;
                                  system("cls");
                                  label : {
                                  school_name();
                                  taskbar();
                                  borderx(0,7);
                                  borderx(0,27);
                                  gotoxy(52,9);
                                  cout<<"* MODIGING ASSIGNMENTS *";
                                  gotoxy(0,12);
                                  cout<<"Enter 1 for Physics "<<endl<<endl;
                                  cout<<"Enter 2 for Chemistry "<<endl<<endl;
                                  cout<<"Enter 3 for Maths "<<endl<<endl;
                                  cout<<"Enter 4 for English "<<endl<<endl;
                                  cout<<"Enter 5 for Computer Science "<<endl<<endl;
                                  cout<<"Enter your choice here ";
                                  cin>>c;
                                  switch(c)
                                  {
                                      case 1 : system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the assignment ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING PHYSICS ASSIGNMENT *";
                                               gotoxy(0,12);
                                               cout<<"Enter new assignment here : ";
                                               gets(e.assignment[0]);
                                               gets(e.assignment[0]);
                                               break;
                                    case 2 :   system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the assignment ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING CHEMISTRY ASSIGNMENT *";
                                               gotoxy(0,12);
                                               cout<<"Enter new assignment here : ";
                                               gets(e.assignment[1]);
                                               gets(e.assignment[1]);
                                               break;
                                    case 3 :   system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the assignment ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING MATHS ASSIGNMENT *";
                                               gotoxy(0,12);
                                               cout<<"Enter new assignment here : ";
                                               gets(e.assignment[2]);
                                               gets(e.assignment[2]);
                                               break;
                                    case 4 :   system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the assignment ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING ENGLISH ASSIGNMENT *";
                                               gotoxy(0,12);
                                               cout<<"Enter new assignment here : ";
                                               gets(e.assignment[3]);
                                               gets(e.assignment[3]);
                                               break;
                                    case 5 : system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the assignment ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING COMPUTER SCIENCE ASSIGNMENT *";
                                               gotoxy(0,12);
                                               cout<<"Enter new assignment here : ";
                                               gets(e.assignment[4]);
                                               gets(e.assignment[4]);
                                               break;
                                    case 10 : system("cls");
                                                front_screen();
                                                break;
                                    case 11 : system("cls");
                                                modifing_assignmnets();
                                                break;
                                    case 12 : help();
                                                system("cls");
                                                goto label;
                                                break;
                                    case 13 : system("cls");
                                                menu_for_teacher();
                                                break;
                                    default : system("cls");
                                                gotoxy(0,25);
                                                cout<<"Enter a valid entry :(";
                                                goto label;
                                  }
                                  }
                                  fout.write((char *)&e,sizeof(e));
                              }
                              }
                          }
                          fin.close();
                          fout.close();
                          remove("Student.dat");
                          rename("TEMP.dat","Student.dat");
                          if(counter==0)
                          {
                            gotoxy(52,20);
                            cout<<"Student not found! ";
                            delay(1000);
                            system("cls");
                            menu_for_teacher();
                          }
                          else
                          {
                              system("cls");
                              school_name();
                              taskbar();
                              borderx(0,7);
                              borderx(0,27);
                              gotoxy(52,8);
                              cout<<"* MODIGING ASSIGNMENTS *";
                              gotoxy(52,17);
                              cout<<"ASSIGNMENT HAS MODIFIED :) ";
                              delay(1000);
                              system("cls");
                              menu_for_teacher();
                          }
                }
                          break;
                case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_teacher();
                          break;
                case 12 : help();
                          system("cls");
                          modifing_assignmnets();
                          break;
                case 13 : system("cls");
                          menu_for_teacher();
                          break;
                default : system("cls");
                          gotoxy(52,21);
                          cout<<"Enter a valid entry :(";
                          modifing_assignmnets();
	    }
	    }
	    void modifing_syllabus()
	    {
            int choice;
	        school_name();
	        taskbar();
	        borderx(0,6);
	        borderx(0,27);
	        gotoxy(52,8);
	        cout<<"* MODIGING SYLLABUS *";
	        gotoxy(27,17);
	        cout<<"Enter 1 to modify syllabus or use taskbar to navigate to other details : ";
	        cin>>choice;
	        switch(choice)
	        {
                case 1  :{ system("cls");
                          int i,c,counter=0;
                          Student e;
	                      school_name();
	                      taskbar();
	                      int roll;
	                      school_name();
	                      borderx(0,6);
	                      borderx(0,27);
	                      gotoxy(52,8);
                          cout<<"* MODIGING SYLLABUS *";
	                      gotoxy(40,16);
	                      cout<<"Enter the roll number of the student : ";
	                      cin>>roll;
	                      ifstream fin;
	                      ofstream fout;
	                      fin.open("Student.dat",ios::binary);
	                      fout.open("TEMP.dat",ios::binary | ios::trunc);
	                      while(!fin.eof())
                          {
                              fin.read((char *)&e,sizeof(e));
                              if(e.roll_no!=roll)
                                  fout.write((char *)&e,sizeof(e));
                              else
                              {
                                 if(!counter)
                                 {
                                  counter++;
                                  system("cls");
                                  labelc : {
                                  school_name();
                                  taskbar();
                                  borderx(0,7);
                                  borderx(0,27);
                                  gotoxy(52,9);
                                  cout<<"* MODIGING SYLLABUS *";
                                  gotoxy(0,12);
                                  cout<<"Enter 1 for Physics "<<endl<<endl;
                                  cout<<"Enter 2 for Chemistry "<<endl<<endl;
                                  cout<<"Enter 3 for Maths "<<endl<<endl;
                                  cout<<"Enter 4 for English "<<endl<<endl;
                                  cout<<"Enter 5 for Computer Science "<<endl<<endl;
                                  cout<<"Enter your choice here ";
                                  cin>>c;
                                  switch(c)
                                  {
                                      case 1 : system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the syllabus ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING PHYSICS SYLLABUS *";
                                               gotoxy(0,12);
                                               cout<<"Enter new syllabus here : ";
                                               gets(e.syllabus[0]);
                                               gets(e.syllabus[0]);
                                               break;
                                    case 2 :   system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the syllabus ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING CHEMISTRY SYLLABUS *";
                                               gotoxy(0,12);
                                               cout<<"Enter new syllabus here : ";
                                               gets(e.syllabus[1]);
                                               gets(e.syllabus[1]);
                                               break;
                                    case 3 :   system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the syllabus ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING MATHS SYLLABUS *";
                                               gotoxy(0,12);
                                               cout<<"Enter new syllabus here : ";
                                               gets(e.syllabus[2]);
                                               gets(e.syllabus[2]);
                                               break;
                                    case 4 :   system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the syllabus ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING ENGLISH SYLLABUS *";
                                               gotoxy(0,12);
                                               cout<<"Enter new syllabus here : ";
                                               gets(e.syllabus[3]);
                                               gets(e.syllabus[3]);
                                               break;
                                    case 5 : system("cls");
                                               school_name();
                                               gotoxy(44,28);
                                               cout<<"Pressing enter will terminate the syllabus ";
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING COMPUTER SCIENCE SYLLABUS *";
                                               gotoxy(0,12);
                                               cout<<"Enter new syllabus here : ";
                                               gets(e.syllabus[4]);
                                               gets(e.syllabus[4]);
                                               break;
                                    case 10 : system("cls");
                                                front_screen();
                                                break;
                                    case 11 : system("cls");
                                                modifing_syllabus();
                                                break;
                                    case 12 : help();
                                                system("cls");
                                                goto labelc;
                                                break;
                                    case 13 : system("cls");
                                                menu_for_teacher();
                                                break;
                                    default : system("cls");
                                                gotoxy(0,25);
                                                cout<<"Enter a valid entry :(";
                                                goto labelc;
                                  }
                                  }
                                  fout.write((char *)&e,sizeof(e));
                                 }
                              }
                          }
                          fin.close();
                          fout.close();
                          remove("Student.dat");
                          rename("TEMP.dat","Student.dat");
                          if(counter==0)
                          {
                            gotoxy(52,20);
                            cout<<"Student not found! ";
                            delay(1000);
                            system("cls");
                            menu_for_teacher();
                          }
                          else
                          {
                              system("cls");
                              school_name();
                              taskbar();
                              borderx(0,7);
                              borderx(0,27);
                              gotoxy(52,8);
                              cout<<"* MODIGING SYLLABUS *";
                              gotoxy(52,17);
                              cout<<"SYLLABUS HAS MODIFIED :) ";
                              delay(1000);
                              system("cls");
                              menu_for_teacher();
                          }
                }
                          break;
                case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_teacher();
                          break;
                case 12 : help();
                          system("cls");
                          modifing_syllabus();
                          break;
                case 13 : system("cls");
                          menu_for_teacher();
                          break;
                default : system("cls");
                          gotoxy(52,21);
                          cout<<"Enter a valid entry :(";
                          modifing_syllabus();
	    }
	    }
	    void modifing_result()
	    {
            int choice;
	        school_name();
	        taskbar();
	        borderx(0,7);
	        borderx(0,27);
	        gotoxy(52,8);
	        cout<<"* MODIGING RESULT *";
	        gotoxy(27,17);
	        cout<<"Enter 1 to modify result or use taskbar to navigate to other details : ";
	        cin>>choice;
	        switch(choice)
	        {
                case 1  :{ system("cls");
                          int i,c,counter=0;
                          Student e;
	                      school_name();
	                      taskbar();
	                      int roll;
	                      school_name();
	                      borderx(0,6);
	                      borderx(0,27);
	                      gotoxy(52,8);
                          cout<<"* MODIGING RESULT *";
	                      gotoxy(40,16);
	                      cout<<"Enter the roll number of the student : ";
	                      cin>>roll;
	                      ifstream fin;
	                      ofstream fout;
	                      fin.open("Student.dat",ios::binary);
	                      fout.open("TEMP.dat",ios::binary | ios::trunc);
	                      while(!fin.eof())
                          {
                              fin.read((char *)&e,sizeof(e));
                              if(e.roll_no!=roll)
                                  fout.write((char *)&e,sizeof(e));
                              else
                              {
                                  if(!counter)
                                  {
                                  counter++;
                                  labelc : {
                                  system("cls");
                                  school_name();
                                  taskbar();
                                  borderx(0,7);
                                  borderx(0,27);
                                  gotoxy(52,8);
                                  cout<<"* MODIGING RESULT *";
                                  gotoxy(0,12);
                                  cout<<"Enter 1 for Physics "<<endl<<endl;
                                  cout<<"Enter 2 for Chemistry "<<endl<<endl;
                                  cout<<"Enter 3 for Maths "<<endl<<endl;
                                  cout<<"Enter 4 for English "<<endl<<endl;
                                  cout<<"Enter 5 for Computer Science "<<endl<<endl;
                                  cout<<"Enter your choice here ";
                                  cin>>c;
                                  switch(c)
                                  {
                                      case 1 : system("cls");
                                               school_name();
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING PHYSICS RSEULT *";
                                               gotoxy(0,12);
                                               cout<<"Enter CT1 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT2 marks        :  "<<endl<<endl;
                                               cout<<"Enter MID TERM marks   :  "<<endl<<endl;
                                               cout<<"Enter CT3 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT4 marks        :  "<<endl<<endl;
                                               cout<<"Enter FINAL TERM marks :  "<<endl<<endl;
                                               gotoxy(25,12);
                                               cin>>e.m1[0];
                                               gotoxy(25,14);
                                               cin>>e.m1[1];
                                               gotoxy(25,16);
                                               cin>>e.m1[2];
                                               gotoxy(25,18);
                                               cin>>e.m1[3];
                                               gotoxy(25,20);
                                               cin>>e.m1[4];
                                               gotoxy(25,22);
                                               cin>>e.m1[5];
                                               gotoxy(0,24);
                                               cout<<"RESULT HAS MODIFIED ";
                                               delay(1000);
                                               break;
                                    case 2 :   system("cls");
                                               school_name();
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING CHEMISTRY RSEULT *";
                                               gotoxy(0,12);
                                               cout<<"Enter CT1 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT2 marks        :  "<<endl<<endl;
                                               cout<<"Enter MID TERM marks   :  "<<endl<<endl;
                                               cout<<"Enter CT3 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT4 marks        :  "<<endl<<endl;
                                               cout<<"Enter FINAL TERM marks :  "<<endl<<endl;
                                               gotoxy(25,12);
                                               cin>>e.m2[0];
                                               gotoxy(25,14);
                                               cin>>e.m2[1];
                                               gotoxy(25,16);
                                               cin>>e.m2[2];
                                               gotoxy(25,18);
                                               cin>>e.m2[3];
                                               gotoxy(25,20);
                                               cin>>e.m2[4];
                                               gotoxy(25,22);
                                               cin>>e.m2[5];
                                               gotoxy(0,24);
                                               cout<<"RESULT HAS MODIFIED ";
                                               delay(1000);
                                               break;
                                    case 3 :   system("cls");
                                               school_name();
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING MATHS RSEULT *";
                                               gotoxy(0,12);
                                               cout<<"Enter CT1 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT2 marks        :  "<<endl<<endl;
                                               cout<<"Enter MID TERM marks   :  "<<endl<<endl;
                                               cout<<"Enter CT3 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT4 marks        :  "<<endl<<endl;
                                               cout<<"Enter FINAL TERM marks :  "<<endl<<endl;
                                               gotoxy(25,12);
                                               cin>>e.m3[0];
                                               gotoxy(25,14);
                                               cin>>e.m3[1];
                                               gotoxy(25,16);
                                               cin>>e.m3[2];
                                               gotoxy(25,18);
                                               cin>>e.m3[3];
                                               gotoxy(25,20);
                                               cin>>e.m3[4];
                                               gotoxy(25,22);
                                               cin>>e.m3[5];
                                               gotoxy(0,24);
                                               cout<<"RESULT HAS MODIFIED ";
                                               delay(1000);
                                               break;
                                    case 4 :   system("cls");
                                               school_name();
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING ENGLISH RSEULT *";
                                               gotoxy(0,12);
                                               cout<<"Enter CT1 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT2 marks        :  "<<endl<<endl;
                                               cout<<"Enter MID TERM marks   :  "<<endl<<endl;
                                               cout<<"Enter CT3 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT4 marks        :  "<<endl<<endl;
                                               cout<<"Enter FINAL TERM marks :  "<<endl<<endl;
                                               gotoxy(25,12);
                                               cin>>e.m4[0];
                                               gotoxy(25,14);
                                               cin>>e.m4[1];
                                               gotoxy(25,16);
                                               cin>>e.m4[2];
                                               gotoxy(25,18);
                                               cin>>e.m4[3];
                                               gotoxy(25,20);
                                               cin>>e.m4[4];
                                               gotoxy(25,22);
                                               cin>>e.m4[5];
                                               gotoxy(0,24);
                                               cout<<"RESULT HAS MODIFIED ";
                                               delay(1000);
                                               break;
                                    case 5 :   system("cls");
                                               school_name();
                                               borderx(0,7);
                                               borderx(0,27);
                                               gotoxy(48,9);
                                               cout<<"* MODIGING COMPUTER SCIENCE RSEULT *";
                                               gotoxy(0,12);
                                               cout<<"Enter CT1 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT2 marks        :  "<<endl<<endl;
                                               cout<<"Enter MID TERM marks   :  "<<endl<<endl;
                                               cout<<"Enter CT3 marks        :  "<<endl<<endl;
                                               cout<<"Enter CT4 marks        :  "<<endl<<endl;
                                               cout<<"Enter FINAL TERM marks :  "<<endl<<endl;
                                               gotoxy(25,12);
                                               cin>>e.m5[0];
                                               gotoxy(25,14);
                                               cin>>e.m5[1];
                                               gotoxy(25,16);
                                               cin>>e.m5[2];
                                               gotoxy(25,18);
                                               cin>>e.m5[3];
                                               gotoxy(25,20);
                                               cin>>e.m5[4];
                                               gotoxy(25,22);
                                               cin>>e.m5[5];
                                               gotoxy(0,24);
                                               cout<<"RESULT HAS MODIFIED ";
                                               delay(1000);
                                               break;
                                    case 10 : system("cls");
                                                front_screen();
                                                break;
                                    case 11 : system("cls");
                                                modifing_syllabus();
                                                break;
                                    case 12 : help();
                                                system("cls");
                                                goto labelc;
                                                break;
                                    case 13 : system("cls");
                                                menu_for_teacher();
                                                break;
                                    default : system("cls");
                                                gotoxy(0,25);
                                                cout<<"Enter a valid entry :(";
                                                goto labelc;
                                  }
                                  }
                                  fout.write((char *)&e,sizeof(e));
                              }
                              }
                          }
                          fin.close();
                          fout.close();
                          remove("Student.dat");
                          rename("TEMP.dat","Student.dat");
                          if(counter==0)
                          {
                            gotoxy(52,20);
                            cout<<"Student not found! ";
                            delay(1000);
                            system("cls");
                            menu_for_teacher();
                          }
                          else
                          {
                              system("cls");
                              menu_for_teacher();
                          }
                }
                          break;
                case 10 : system("cls");
	                      front_screen();
                          break;
                case 11 : system("cls");
                          menu_for_teacher();
                          break;
                case 12 : help();
                          system("cls");
                          modifing_syllabus();
                          break;
                case 13 : system("cls");
                          menu_for_teacher();
                          break;
                default : system("cls");
                          gotoxy(52,21);
                          cout<<"Enter a valid entry :(";
                          modifing_syllabus();
	    }
	    }
};
void front_screen()
{
    int x=49,y=15,i,choice;
    school_name();
    borderx(0,7);
    gotoxy(x,y);
    cout<<"Hey! Welcome back ";
    x-=23;
    y++;
    gotoxy(x,y);
    cout<<"Press 1 for login as a student and 2 for login as a teacher : ";
    gotoxy(52,26);
    cout<<"ENTER 3 FOR EXIT ";
    borderx(0,25);
    x+=62;
    gotoxy(x,y);
    cin>>choice;
    switch(choice)
    {
        case 1 :{
                Student s;
                s.login_as_student();
                }
                break;
        case 2 :Teacher t;
                t.login_as_teacher();
                break;
        case 3 : gotoxy(0,27);
                exit(0);
        default : system("cls");
                    x=49;
                    y=18;
                    gotoxy(x,y);
                    cout<<"Enter a valid choice :( ";
                    front_screen();
    }
}
int main()
{
    front_screen();
}

