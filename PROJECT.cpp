#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

class student
{char name[20],add[80],email[20],tel[10],coursen[100];double fees;int test1,test2,cc;
public:int course,course2;
	void calculate();
	void assign();
	student();
	void crs();
	void input();

       void conc()//concession
       {if(test2>=200)
       cc=90;
    else if(test2>=180 && test2<=150)
	cc=70;
	else if(test2>=150 && test2<=100)
	cc=50;
       else if(test2>=100 && test2<=150)
	cc=30;
	else if(test2>=80 && test2<=100)
	cc=25;
	else
	cc=0;
	}


	void phn();
	void display()
	{clrscr(); cout<<coursen;
	cout<<"Name: "<<name<<"\nPhone No.:"<<tel<<"\nAddress: "<<add<<"\nE-mail: "<<email<<"\nCourse: "<<coursen<<endl;
	//put just  course
	cout<<"\nFees:"<<fees<<"\n\nStudent Report:\n\t%age in previous class:"<<test1<<"%"<<"\n\tMarks in scholarship test:"<<test2<<"/360"<<"\n\tscholarship offered:"<<cc<<"%";
	}
       void modify();int search(char*);
       int access2(int);

       }s;





       void student::input()
       {clrscr();
	cout<<"Enter Name of Student"<<endl;
	gets(name);
	cout<<"Enter Address"<<endl;
	gets(add);
	cout<<"Enter E-mail"<<endl;
	gets(email);
	t:
	cout<<"Enter %age in previous class(rounded of to nearest whole no.)\n";
	cin>>test1;
	if(test1<0||test1>100)
	{cout<<"\n**wrong %age input**\nEnter correct %age";
	goto t;
	}
	k:
	cout<<"\nEnter marks in scholarship test(out of 360)\n";
	cin>>test2;
	if(test2<0||test2>360)
	{cout<<"\n**wrong marks input**\nEnter correct %age";
	goto k;
	}

	phn();
	}


	void student::crs()//course  is having value as marks in scholarship
	{t:
	cout<<"Select Course:\n\n1)4 year program(9th)\n\n2)3 year program(10th)\n\n3)2 year program(11th)\n\n4)1 year program(12th)\n\n5)1 year program(12th Pass)\n\n";
	cin>>course;
	 cout<<course;
	 course2=0;
	 if(course>5||course<1)
	 {cout<<"\n**wrong choice**\n";goto t;
	 }
	 l:
	 if(course<=5&&course>=3)
	 {cout<<"\nchoose stream:\n\t1)Engineering \n\t2)Medical\n";
	 cin>>course2;
	 if(course2>2||course2<1)
	 {cout<<"\n**wrong choice**\n";goto l;
	 }
	 }
    assign();

	 }

       void student::calculate()
       {conc();
       double bfee[5]={350000,300000,225000,175000,150000};
       fees=bfee[course]*(1-(0.01*cc));

       }
       void student::assign()
       {switch(course)
       {case 1:strcpy(coursen,"4 year program(9th)");break;
	case 2:strcpy(coursen,"3 year program(10th)");break;
	case 3:strcpy(coursen,"2 year program(11th)");break;
	case 4:strcpy(coursen,"1 year program(12th)");break;
	case 5:strcpy(coursen,"1 year program(12th Pass)");break;
	default:cout<<"#######################";
	}
	if(course>=3)
	{if(course2==1)
	strcat(coursen,":Engineering");
	else
	strcat(coursen,":Medical");
	}
       /*switch(course)
       {case 1:strcpy(coursen,"4 year program(9th)");break;
	case 2:strcpy(coursen,"3 year program(10th)");break;
	case 3:strcpy(coursen,"2 year program(11th)");break;
	case 4:strcpy(coursen,"1 year program(12th)");break;
	case 5:strcpy(coursen,"1 year program(12th Pass)");break;
	default:cout<<"#######################";
	}
	if(course>=3)
	{if(course2==1)
	strcat(coursen,":Engineering");
	else
	strcat(coursen,":Medical");
	}*/
	}


       student::student()
       {int i;
       for(i=0;i<10;i++)
	 {tel[i]='\0';
	 }
       }

	void student::modify()
       {int choice;char ch;
       tk:
	cout<<"What do you wish to modify?(Enter S.no)\n";
	cout<<"1) Name: "<<name<<"\n2)Phone No):"<<tel<<"\n3)Address: "<<add<<"\n4)E-mail: "<<email<<"\n5)Course:"<<coursen<<"\n6)%age in previous class:"<<test1<<"\n7)Marks in scholarship test:"<<test2<<"/360\n\n";
	cin>>choice;
	switch(choice)
	{case 1:cout<<"Enter Name of Student"<<endl;
		gets(name);break;
	 case 2:phn();break;
	 case 3:cout<<"Enter Address"<<endl;
		gets(add);break;
	 case 4:cout<<"Enter E-mail"<<endl;
		gets(email);
	 case 5:crs();break;
	 case 6:cout<<"Enter %age in previous class(rounded of to nearest whole no.)\n";
		cin>>test1;break;
	 case 7:cout<<"Enter marks in scholarship test(out of 360)\n";
		cin>>test2;calculate();break;
	 default:cout<<"\n**wrong choice**\n";
	 }
	 clrscr();display();
	 sh:
	 cout<<"\ndo you still wish to make changes?(Y or N)\n";
	 cin>>ch;
	 if(ch=='y'||ch=='Y')
	 goto tk;
	 else if(ch=='n'||ch=='N')
	 return;

	 else
	 {cout<<"\n**wrong choice**\n";goto sh;
	 }
	}
	void student::phn()
	{int i;
	x1:
	cout<<"Enter phone number\n";
	gets(tel);
	for(i=0;i<10;i++)
	 {if(isdigit(tel[i])==0)
	 {cout<<"\n**wrong number**\nEnter correct no.\n";
	  goto x1;
	 }
	 }
	}


       int student::search(char*tel1) //constructor assigned '\0'to all elements of tel
       {int i;
	for(i=0;i<10;i++)
	 { if(tel[i]!=tel1[i])
	   break;
	 }
	if(i==10)
	return 1;
	else
	return 0;
	}


	void _phn(char tel[10])
	{int i;
	x:
	cout<<"Enter phone no.of student\n";
	gets(tel);
	for(i=0;i<10;i++)
	 {if(isdigit(tel[i])==0)
	 {cout<<"\n**wrong number**\nEnter correct no.\n";
	  goto x;
	 }
	 }
	}


void main()
{clrscr();
int choice,flag,c,c2,i,j; char t[10],ch;fstream f;
cout<<"\t\t\tVIDYAMANDIR CLASSES\n\n\n";
ppp:
 cout<<"Choose:\n\t1)Admission\n\t2)Search for a students details\n\t3)Cancellation of Admission\n\t4)Modify details\n\t5)Student details for particular course\n\t6)Exit\n";
 cin>>choice;
 switch(choice)
 {case 1:{f.open("record.dat",ios::binary|ios::app);


	s.crs();s.input();s.calculate();
	f.write((char*)&s,sizeof(s));f.close();
   }
	break;
  case 2:{f.open("record.dat",ios::binary|ios::in);
	_phn(t);
	cout<<endl<<endl;
	f.seekg(0);
	 while(f.read((char*)&s,sizeof(s)))
    {if(s.search(t)==1)
	  {clrscr();s.display();flag=1;break;
	  }

	 }
	 f.close();
	 if(flag!=1)
	 cout<<"\n**no match found**\n";
	 }
    break;
  case 3:{int k,a,_1;ofstream fout;
	_phn(t);flag=0;
	cout<<endl<<endl;
	f.open("record.dat",ios::binary|ios::in);
	fout.open("temp.dat",ios::binary|ios::out);
	fout.seekp(0);
	while(f.read((char*)&s,sizeof(s)))
    {if(s.search(t)==1)
      {flag++;cout<<"\tDELETED";
      continue;
    }
    else
    fout.write((char*)&s,sizeof(s));
    }
    fout.close();
    f.close();
	remove("record.dat");
	rename("temp.dat","record.dat");

	if(flag==0)
	{
	    cout<<"NO MATCH FOUND\n";
	}

   }
	break;














	 /*for(i=0;s[i].access(4,0)!='\0';i++)
	 {if(s[i].search(t)==1)
	  {for(k=0,j=0;k<=n;j++)
	   { if(k==i)
	     continue;
	     for(_1=0;_1<6;_1++)
	     {for(a=0;s[j].access(_1,a)!='\0';a++)
	     s[k].in(_1,a,s[j].access(_1,a));
	     s[k].in(_1,a,'\0');
	     }
	     s[k].in(s[j].access());
	     for(_1=1;_1<3;_1++)
	     {s[k].in(_1,s[j].access(_1));
	     s[k].in2(_1,s[j].access2(_1));
	     }
	    k++;
	  }
	flag=1;break;
	}
	}
	if(flag!=1)
	 cout<<"\n**no match found**\n";

	 break;
*/

  case 4:{_phn(t);cout<<endl<<endl;f.open("record.dat",ios::binary|ios::in|ios::out);
    f.seekg(0);
	 while(f.read((char*)&s,sizeof(s)))
	 {if(s.search(t)==1)
	  {s.modify();
	  f.seekp(-1*sizeof(s),ios::cur);
	  f.write((char*)&s,sizeof(s));
	  flag=1;
	  break;
	  }
	 }
	 if(flag!=1)
	 cout<<"\n**no match found**\n";
	 f.close();
    }
	 break;
  case 5:{m:
	clrscr();
	cout<<"Select Course:\n\n1)4 year program(9th)\n\n2)3 year program(10th)\n\n3)2 year program(11th)\n\n4)1 year program(12th)\n\n5)1 year program(12th Pass)\n\n";
	 cin>>c;c2=0;
	 if(c>5||c<1)
	 {cout<<"\n**wrong choice**\n";goto m;
	 }
	 if(c<=5&&c>=3)
	 {o:
	 cout<<"choose stream:\n\t1)Engineering\n\t2)Medical\n";
	 cin>>c2;
	 if(c2>2||c2<1)
	 {cout<<"\n**wrong choice**\n";goto o;
	 }
	 }
	clrscr();f.open("record.dat",ios::binary|ios::in);
	f.seekg(0);
	 cout<<"student details are as follows \n\n";
	  while(f.read((char*)&s,sizeof(s)))
	  { if(s.course==c && s.course2==c2)
	     {clrscr();s.display();
	     cout<<"\n\n";
	     }
	  }
	  f.close();
     }
	  break;
  case 6:return;
  case 7:f.open("record.dat",ios::binary|ios::in);
 f.seekg(0);
	 while(f.read((char*)&s,sizeof(s)))
	 {s.display();
	 }
	 f.close();
	 break;
  case 8:remove("record.dat");break;
  default:cout<<"\n**wrong choice**\n";
  }
	 cout<<"\ndo you wish to continue?(Y or N)\n";
	 cin>>ch;
	 if(ch=='y'||ch=='Y')
	 {clrscr();goto ppp;}
	 else if(ch=='n'||ch=='N')
	 return;
	 else
	 cout<<"\n**wrong choice**\n";
	 getch();
}
