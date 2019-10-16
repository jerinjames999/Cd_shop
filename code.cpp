#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>


class cd
{
    char name[80];
    char type[80];
    float size;
    float rate;
    char lang[80];
    char dev[80];
    int year;
    int stock;

    public:
    void del();
    void purchase();
    void sale();
    void rental();
    void showdata();
    void view();
    void modi();
    void graph();
    void ret();
    void rent();
    void pass();
};


void line()
{
    cout<<"\n";
    cout<<"********************************************************************************";
}
void cd::rent()
{
    int ch;
    cd c;
    clrscr();
    cout<<"\n\n\t\t\tRENTAL CENTER"
    <<"\n\n\t\tENTER CHOICE : "
    <<"\n\n\t\t1.RENT CD"
    <<"\n\n\t\t2.RETURN CD \t";
    cin>>ch;
    switch(ch)
    {
        case 1: c.rental();
                break;
        case 2: c.ret();
                break;
        default:
                cout<<"\n\n\n\n\n\n\t\t\tINVALID CHOICE";
    }
}
void cd::showdata()
{
    cout<<"\n NAME OF THE CD :"<<name
    <<"\n TYPE OF THE CD :"<<type
    <<"\n SIZE OF THE CD :"<<size
    <<"\n RATE OF THE CD :"<<rate
    <<"\n LANGUAGE OF THE CD :"<<lang
    <<"\n DEVELOPERS OF THE CD :"<<dev
    <<"\n YEAR OF RELEASE :"<<year
    <<"\n STOCK AVAILABLE :"<<stock
    <<"\n\n";
}
void cd::ret()
{
    cd c8;
    long pos;
    char til[80];
    int flag=0,no,i=0;
    clrscr();
    cout<<"\n\t\t\t\tRETURN"
    <<"\n\n\n\tENTER THE TITLE YOU WANT TO RETURN : ";
    gets(til);
    fstream out("cds.dat",ios::binary|ios::in|ios::out);
    out.seekg(0,ios::end);
    int size=out.tellg();
    int n=size/sizeof(cd);
    out.seekg(0);
    while(!out.eof() && i<n)
    {
        i++;
        pos=out.tellg();
        out.read((char*)&c8,sizeof(c8));
        if(strcmpi(c8.name,til)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"\n\n\n\tENTER THE NO OF COPIES TO BE RETURNED : ";
        cin>>no;
        c8.stock=c8.stock+no;
        out.seekp(pos);
        out.write((char*)&c8,sizeof(c8));
    }
    else
    {
        cout<<"\n\n\n\nTITLE NOT FOUND!";
    }
    out.close();
}
void cd::pass()
{
    int i;
    char choi;
    char password[]="password",passw[80],ch;
    do
    {
        clrscr();
        i=0;
        ch='a';
        line();
        cout<<"\n\t\t\t\tLOGIN";
        line();
        cout<<"\n\tWELCOME USER,"
        <<"\n\n\n\tENTER PASSWORD : ";
        while(ch!=13)
        {
            if(ch!=13)
            {
                ch=getch();
                passw[i]=ch;
            }
            if(ch==8)
            {
                if(i>0)
                {
                    cout<<"\b \b";
                    i--;
                }
            }
            else
            {
                cout<<"*";
                i++;
            }
        }
        passw[i-1]='\0';
        if(strcmp(passw,password)!=0)
        {
            clrscr();
            cout<<"\n\n\n\n\t\t\tACCES DENIED";
            cout<<"\n\n\n\nDO YOU WANT TO TRY AGAIN?(y/n)";
            cin>>choi;
            if(choi=='n'||choi=='N')
                exit(0);
        }
        else
        break;
    }while(choi=='y'||choi=='Y');
}
void cd::graph()
{
    int x,y,i,maxx,maxy;
    int g=DETECT,d;
    initgraph(&g,&d,"c:\\tc\\bgi\\");
    cleardevice();
    x=getmaxx()/2;
    y=getmaxy()/2;
    int c=10,m=HORIZ_DIR,t=3;
    settextstyle(c,m,t);
    maxx = getmaxx();
    maxy = getmaxy();
    setbkcolor(RED);
    for(int h=500; h>499 ; h--)
    {
        cleardevice();
        setcolor(WHITE);
        line(0,100,3000,100);
        floodfill(0,0 , getmaxcolor());
        setcolor(rand());
        for(int u=0;u<6;u++)
        {
            line(u,1000,u,0);
            line(0,u,1000,u);
            line(1000,478-u,1,478-u);
            line(639-u,1,639-u,1000);
        }
        setcolor(0);
        outtextxy(h-250,30,"CdVeRsE");
        delay(10);
        setcolor(WHITE);
        delay(10);
        int i=90;
        outtextxy(30,i,"MADE BY:-");
        outtextxy(30,i+30,"ABHISHEK ANISH");
        outtextxy(30,i+60,"AKSHAJ SUNIL");
        outtextxy(30,i+90,"ARJUN BJ");
        outtextxy(30,i+120,"JERIN JAMES");
        outtextxy(30,i+150,"JERIN J SHAJI");
        outtextxy(30,i+180,"NANDU SURESH");
        delay(10);
        for( i=0;i<30;i++)
        {
            circle(h,y,i);
            delay(100);
        }
        setcolor(rand());
        for(int j=30;j<60;j++)
        {
            circle(h,y,j);
            delay(50);
        }
        setcolor(rand());
        for(int k=60;k<90;k++)
        {
            circle(h,y,k);
            delay(10);
        }
        setcolor(rand());
        for(int l=90;l<120;l++)
        {
            circle(h,y,l);
            delay(10);
        }
        setcolor(rand());
        for(int p=90;p<120;p++)
        {
            circle(h,y,l);
            delay(10);
        }
        setcolor(rand());
        for(int o=90;o<120;o++)
        {
            circle(h,y,o);
            delay(10);
        }
    }
    settextstyle(GOTHIC_FONT,HORIZ_DIR,1);
    setcolor(WHITE);
    outtextxy(30,400,"PRESS ANY KEY TO CONTINUE");
    getch();
    closegraph();
}
void cd::del()
{
    clrscr();
    int flag=0;
    cd c8;
    int count=0;
    char name[80],ch;
    fstream inout("cds.dat",ios::in|ios::out|ios::binary);
    inout.seekg(0,ios::end);
    int size =inout.tellg();
    int records=size/sizeof(cd);
    fstream inout_temp("temp.dat",ios::out|ios::noreplace|ios::binary);
    inout.seekg(0,ios::beg);
    line();
    cout<<"\n\t\t\tDELETE";
    line();
    cout<<"\n\n\n\n\tENTER THE TITLE TO BE DELETED\t";
    gets(name);
    int i=0;
    while(!inout.eof() && i<records)
        while(inout&&count<=(records-1))
        {
            inout.read((char*)&c8,sizeof(c8));
            i++;
            count++;
            if((strcmpi(c8.name,name)==0) )
            {
                flag=1;
                c8.showdata();
            }
            if(!(strcmpi(c8.name,name)==0) )
            {
                inout_temp.write((char*)&c8,sizeof(c8));
            }
        }
    if(flag==0)
    {
        cout<<"\n\t\t\tTITLE NOT FOUND";
    }
    else
    {
        cout<<"\n\n\t\tARE YOU SURE?(y/n) : ";
        cin>>ch;
        if(ch=='y'||ch=='Y')
        {
            cout<<"\n\t\t \a\a RECORD DELETED...............";
            inout.close();
            inout_temp.close();
            remove("cds.dat");
            rename("temp.dat","cds.dat");
        }
    }
}
void cd::modi()
{
    clrscr();
    int flag=0;
    fstream in("cds.dat",ios::out|ios::in|ios::binary);
    cd c10;
    long pos;
    char til1[80];
    line();
    cout<<"\n\t\t\tMODIFY";
    line();
    cout<<"\n\tENTER THE TITLE TO MODIFY\t";
    gets(til1);
    while(!in.eof())
    {
        pos=in.tellg();
        in.read((char*)&c10,sizeof(c10));
        if(strcmpi(til1,c10.name)==0)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\n\tENTERED TITLE NOT FOUND"; 
    }
    else if(flag==1)
    {
        int ch=0;
        while(ch!=9)
        {
            clrscr();
            line();
            c10.showdata();
            line();
            cout<<"\n\t\t\t\tMODIFY BY"
            <<"\n\t1.NAME"
            <<"\n\t2.TYPE"
            <<"\n\t3.SIZE"
            <<"\n\t4.RATE"
            <<"\n\t5.LANGUAGE"
            <<"\n\t6.DEVELOPER"
            <<"\n\t7.YEAR"
            <<"\n\t8.STOCK"
            <<"\n\t9.EXIT";
            cout<<"\n\tENTER THE CHOICE ";
            cin>>ch;
            int s;
            switch(ch)
            {
                case 1: cout<<"\n\tENTER NEW TITLE: ";
                        gets(c10.name);
                        break;
                case 2: cout<<"\n\tENTER NEW TYPE : ";
                        gets(c10.type);
                        break;
                case 3: cout<<"\n\tENTER THE NEW SIZE :";
                        cin>>c10.size;
                        break;
                case 4: cout<<"\n\tENTER THE NEW RATE :";
                        cin>>c10.rate;
                        break;
                case 5: cout<<"\n\tENTER NEW LANGUAGE:";
                        gets(c10.lang);
                        break;
                case 6: cout<<"\n\tENTER NEW DEVELOPER :";
                        gets(c10.dev);
                        break;
                case 7: cout<<"\n\tENTER NEW YEAR :";
                        cin>>c10.year;
                        break;
                case 8: cout<<"\n\tENTER NEW STOCK :";
                        cin>>c10.stock;
                        break;
                case 9: in.seekp(pos);
                        in.write((char*)&c10,sizeof(c10));
                        in.close();
                        break;
                default:
                        clrscr();
                        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tINVALID CHOICE!\n\n\t\t\t\tTRY AGAIN!";
            }
        }
    }
}
void cd::sale()
{
    clrscr();
    char sdev[80],sname[80];
    int chi,flag=0;
    float total;
    long pos;
    cd c3;
    line();
    cout<<"\n\t\t\t\tSALE";
    line();
    cout<<"\n\t1.TITLES"
    <<"\n\t2.DEVELOPERS"
    <<"\n\n\tENTER YOUR CHOICE\t";
    cin>>chi;
    fstream in("cds.dat",ios::out|ios::in|ios::binary);
    switch(chi)
    {
        case 1: cout<<"\n\tENTER THE TITLE\t\t";
                gets(sname);
                while(!in.eof())
                {
                    pos=in.tellg();
                    in.read((char*)&c3,sizeof(c3));
                    if(strcmpi(sname,c3.name)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    if(c3.stock==0)
                    {
                        cout<<"\nOUT OF STOCK";
                        in.close();
                    }
                    else
                    {
                        c3.showdata();
                        cout<<"\nENTER OF NUMBER TO BE SOLD: ";
                        int no;
                        cin>>no;
                        if(no>c3.stock)
                            cout<<"\n\tTHE ENTERED NUMBER OF CDS ARE NOT AVAILABLE";
                        else
                        {
                            c3.stock=c3.stock-no;
                            in.seekp(pos);
                            in.write((char*)&c3,sizeof(c3));
                            total=no*c3.rate;
                            clrscr();
                            line();
                            cout<<"\t\t\t\tBILL";
                            line();
                            cout<<"\n\t NAME OF THE CD :"<<c3.name;
                            cout<<"\n\t TYPE OF THE CD :"<<c3.type;
                            cout<<"\n\t SIZE OF THE CD :"<<c3.size;
                            cout<<"\n\t RATE OF THE CD :"<<c3.rate;
                            cout<<"\n\t LANGUAGE OF THE CD :"<<c3.lang;
                            cout<<"\n\t DEVELOPERS OF THE CD :"<<c3.dev;
                            cout<<"\n\t YEAR OF RELEASE :"<<c3.year;
                            line();
                            cout<<"\n\t TOTAL PRICE :"<<total;
                            line();
                            in.close();
                        }
                    }
                }
                if(flag==0)
                {
                    cout<<"\n\t\t\tTITLE NOT FOUND";
                }
                else
                {
                    in.close();
                }
                break;
        case 2: cout<<"\n\tENTER DEVELOPER TO BE SEARCHED\t";
                gets(sdev);
                while(!in.eof())
                {
                    pos=in.tellg();
                    in.read((char*)&c3,sizeof(c3));
                    if(strcmpi(sdev,c3.dev)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    if(c3.stock==0)
                        cout<<"\nOUT OF STOCK";
                    else
                    {
                        c3.showdata();
                        cout<<"\n\tENTER NUMBER TO BE SOLD: ";
                        int no;
                        cin>>no;
                        if(no>c3.stock)
                        {
                            cout<<"\n\tTHE ENTERED NUMBER OF CDS ARE NOT AVAILABLE";
                            in.close();
                        }
                        else
                        {
                            c3.stock=c3.stock-no;
                            in.seekp(pos);
                            in.write((char*)&c3,sizeof(c3));
                            total=no*c3.rate;
                            clrscr();
                            line();
                            cout<<"\t\t\t\tBILL";
                            line();
                            cout<<"\n\t NAME OF THE CD :"<<c3.name;
                            cout<<"\n\t TYPE OF THE CD :"<<c3.type;
                            cout<<"\n\t SIZE OF THE CD :"<<c3.size;
                            cout<<"\n\t RATE OF THE CD :"<<c3.rate;
                            cout<<"\n\t LANGUAGE OF THE CD :"<<c3.lang;
                            cout<<"\n\t DEVELOPERS OF THE CD :"<<c3.dev;
                            cout<<"\n\t YEAR OF RELEASE :"<<c3.year;
                            line();
                            cout<<"\n\t TOTAL PRICE :"<<total;
                            line();
                            in.close();
                        }
                    }
                    break;
                }
                else
                {
                    cout<<"\n\t\t\tTITLE NOT FOUND";
                    in.close();
                    break;
                }
                break;
        default:
                clrscr();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tINVALID CHOICE!\n\n\t\t\t\tTRY AGAIN!";
    }
}
void cd::rental()
{
    clrscr();
    int pos;
    int choi;
    int no;
    char ch;
    char sdev[80],sname[80];
    int chi,flag=0;float total;
    cd c4;
    line();
    cout<<"\n\t\t\t RENTAL CORNER";
    line();
    cout<<"\n\n\n\n\t RENT BY"
    <<"\n\t1.TITLES"
    <<"\n\t2.DEVELOPERS"
    <<"\n\n\tENTER YOUR CHOICE\t";
    cin>>chi;
    fstream in("cds.dat",ios::in|ios::out|ios::binary);
    switch(chi)
    {
        case 1: cout<<"\n\tENTER THE TITLE\t";
                gets(sname);
                while(!in.eof())
                {
                    pos=in.tellg();
                    in.read((char*)&c4,sizeof(c4));
                    if(strcmpi(sname,c4.name)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==1)
                {
                    if(c4.stock==0)
                    {
                        cout<<"\nOUT OF STOCK";
                        in.close();
                    }
                    else
                    {
                        c4.showdata();
                        flag=2;
                        cout<<"\n\tENTER THE NUMBER TO BE RENTED: ";
                        int no;
                        cin>>no;
                        if(no>c4.stock)
                            cout<<"\n\tTHE ENTERED NUMBER OF CDS ARE NOT AVAILABLE";
                        else
                        {
                            c4.stock=c4.stock-no;
                            in.seekp(pos);
                            in.write((char*)&c4,sizeof(c4));
                            in.close();
                        }
                    }
                }
                else
                {
                    cout<<"\n\t\t\tENTERED TITLE NOT FOUND";
                    in.close();
                }
                break;
        case 2: cout<<"\n\tENTER DEVELOPER TO BE SEARCHED\t";
                gets(sdev);
                while(!in.eof())
                {
                    pos=in.tellg();
                    in.read((char*)&c4,sizeof(c4));
                    if(strcmpi(sdev,c4.dev)==0)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    cout<<"\n\t\tENTERED TITLE NOT FOUND";
                }
                else if(flag==1)
                {
                    if(c4.stock==0)
                        cout<<"\n\tOUT OF STOCK";
                    else
                    {
                        c4.showdata();
                        cout<<"\n\tENTER NUMBER OF CDS TO BE RENTED: ";
                        cin>>no;
                        if(no>c4.stock)
                        {
                            cout<<"\n\tTHE ENTERED NUMBER OF CDS ARE NOT AVAILABLE";
                            in.close();
                        }
                        else
                        {
                            flag=2;
                            c4.stock=c4.stock-no;
                            in.seekp(pos);
                            in.write((char*)&c4,sizeof(c4));
                            in.close();
                        }
                    }
                    break;
                }
                else
                {
                in.close();
                break;
                }
                break;
        default:
                clrscr();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tINVALID CHOICE!\n\n\t\t\t\tTRY AGAIN!";
    }
    if(c4.stock!=0&&flag==2)
    {
        cout<<"\n\t CD IS AVAILABLE";
        c4.showdata();
        float c=c4.rate*0.05;
        cout<<"\n\n\tRENTAL RATE PER DAY PER CD IS Rs. ";
        cout<<c;
        cout<<"\n\tENTER NUMBER OF DAYS ";
        int days;
        cin>>days;
        clrscr();
        float tc=(c*days*no);
        cout<<"\n\t\tTOTAL COST FOR "
        <<days<<" DAYS IS "
        <<(c*days);
        cout<<"\n\t\t THANK YOU FOR RENTING WITH US... "
        <<"\n\t\t VISIT AGAIN";
    }
}
void cd::view()
{ 
    ifstream inv("cds.dat",ios::binary);
    clrscr();
    int size,no,i=0,j=0;
    line();
    cout<<"\n\t\t\tVIEW";
    line();
    cout<<"\n\n\n\n\t\t\t1.BY YEAR"
    <<"\n\n\n\n\t\t\t2.BY RATE(Rs)"
    <<"\n\n\n\n\t\t\t3.BY LANGUAGE"
    <<"\n\n\n\n\t\t\t4.ALL";
    cout<<"\n\n\n\n\t\t\t\tENTER CHOICE : ";
    int c;
    cd c5;
    cin>>c;
    clrscr();
    switch(c)
    {
        clrscr();
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tVIEW\n\n\n";
        case 1: cout<<"\n\tENTER YEAR TO BE SEARCHED : ";
                int ye;
                cin>>ye;
                inv.seekg(0,ios::end);
                size=inv.tellg();
                no=size/sizeof(cd);
                inv.seekg(0);
                while(!inv.eof() && i<no)
                {
                    i++;
                    if(j%2==0)
                    {
                        j++;
                        cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                        getch();
                        clrscr();
                    }
                    inv.read((char*)&c5,sizeof(c5));
                    if(c5.year==ye)
                    {
                        c5.showdata();
                    }
                }
                if(j==0)
                {
                    cout<<"\n\n\t\tCD NOT FOUND";
                    break;
                }
                break;
        case 2: int ch;
                cout<<"\nCHOOSE REQUIRED RANGE"
                <<"\n\n\t\t1.Rs100 & BELOW"
                <<"\n\n\t\t2.Rs100-Rs200"
                <<"\n\n\t\t3.Rs200-Rs500"
                <<"\n\n\t\t4.Rs500-Rs1000"
                <<"\n\n\t\t5.Rs1000-Rs5000"
                <<"\n\n\t\t6.Rs 5000 & ABOVE"
                <<"\n\nENTER YOUR CHOICE\t";
                cin>>ch;
                switch(ch)
                {
                    case 1: inv.seekg(0,ios::end);
                            size=inv.tellg();
                            no=size/sizeof(cd);
                            inv.seekg(0);
                            while(!inv.eof() && i<no)
                            {
                                i++; 
                                if(j%2==0)
                                {
                                    j++;
                                    cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                                    getch();
                                    clrscr();
                                } 
                                inv.read((char*)&c5,sizeof(c5));
                                if(c5.rate<=100)
                                    c5.showdata();
                            }
                            break;
                    case 2: inv.seekg(0,ios::end);
                            size=inv.tellg();
                            no=size/sizeof(cd);
                            i=0;
                            inv.seekg(0);
                            while(!inv.eof() && i<no)
                            {
                                i++; 
                                if(j%2==0)
                                {
                                    j++;
                                    cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                                    getch();
                                    clrscr();
                                } 
                                inv.read((char*)&c5,sizeof(c5));
                                if(c5.rate>100&&c5.rate<=200)
                                    c5.showdata();
                            }
                            break;
                    case 3: inv.seekg(0,ios::end);
                            size=inv.tellg();
                            no=size/sizeof(cd);
                            i=0;
                            inv.seekg(0);
                            while(!inv.eof() && i<no)
                            {
                                i++;
                                if(j%2==0)
                                {
                                    j++;
                                    cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                                    getch();
                                    clrscr();
                                }
                                inv.read((char*)&c5,sizeof(c5));
                                if(c5.rate>200&&c5.rate<=500)
                                    c5.showdata();
                            }
                            break;
                    case 4: inv.seekg(0,ios::end);
                            size=inv.tellg();
                            no=size/sizeof(cd);
                            i=0;
                            inv.seekg(0);
                            while(!inv.eof() && i<no)
                            {
                                i++;
                                if(j%2==0)
                                {
                                    j++;
                                    cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                                    getch();
                                    clrscr();
                                }
                                inv.read((char*)&c5,sizeof(c5));
                                if(c5.rate>500&&c5.rate<=1000)
                                    c5.showdata();
                            }
                            break;
                    case 5: inv.seekg(0,ios::end);
                            size=inv.tellg();
                            no=size/sizeof(cd);
                            i=0;
                            inv.seekg(0);
                            while(!inv.eof() && i<no)
                            {
                                i++;
                                if(j%2==0)
                                {
                                    j++;
                                    cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                                    getch();
                                    clrscr();
                                }
                                inv.read((char*)&c5,sizeof(c5));
                                if(c5.rate>1000&&c5.rate<=5000)
                                    c5.showdata();
                            }
                            break;
                    case 6: inv.seekg(0,ios::end);
                            size=inv.tellg();
                            no=size/sizeof(cd);
                            i=0;
                            inv.seekg(0);
                            while(!inv.eof() && i<no)
                            {
                                i++;
                                if(i%2==0)
                                {
                                    cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                                    getch();
                                    clrscr();
                                }
                                inv.read((char*)&c5,sizeof(c5));
                                if(c5.rate>5000)
                                    c5.showdata();
                            }
                            break;
                    default:
                            clrscr();
                            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tINVALID CHOICE!\n\n\t\t\t\tTRY AGAIN!";
                }
                break;
        case 3: cout<<"\nENTER LANGUAGE:";
                char slan[80];
                gets(slan);
                int flags=0;
                inv.seekg(0,ios::end);
                size=inv.tellg();
                no=size/sizeof(cd);
                i=0;
                inv.seekg(0);
                while(!inv.eof() && i<no)
                {
                    i++;
                    if(j%2==0)
                    {
                        j++;
                        cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                        getch();
                        clrscr();
                    }
                    inv.read((char*)&c5,sizeof(c5));
                    if(strcmpi(slan,c5.lang)==0)
                    {
                        c5.showdata();
                        flags=1;
                    }
                }
                if(flags==0)
                {
                    cout<<"\nLANGUAGE NOT FOUND";
                }
                break;
        case 4: inv.seekg(0,ios::end);
                size=inv.tellg();
                no=size/sizeof(cd);
                i=0;
                inv.seekg(0);
                while(!inv.eof() && i<no)
                {
                    i++;
                    if(i%2==0)
                    {
                        cout<<"\n\n\t\tNEXT PAGE,PRESS ANY KEY";
                        getch();
                        clrscr();
                    }
                    inv.read((char*)&c5,sizeof(c5));
                    c5.showdata();
                }
                break;
        default:
                clrscr();
                cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tINVALID CHOICE!\n\n\t\t\t\tTRY AGAIN!";
            
    }
    inv.close();
}
void cd::purchase()
{
    int no;
    clrscr();
    line();
    cout<<"\n\t\t\t\tPURCHASE";
    line();
    cout<<"\n\n\n\t\t ENTER NUMBER OF CD'S ";
    cin>>no;
    for(int i=0;i<no;i++)
    { 
        cd c1; clrscr();
        line();
        cout<<"\n\t\t\t\tPURCHASE";
        line();
        ofstream out("cds.dat",ios::app|ios::binary);
        cout<<"\n\n\t\t ENTER CD DETAILS OF CD NO."<<i+1
        <<"\n\n\n\t\t ENTER TITLE : ";
        gets(c1.name);
        cout<<"\n\t\t ENTER CD TYPE : ";
        gets(c1.type);
        cout<<"\n\t\t ENTER RATE(Rs) : ";
        cin>>c1.rate;
        cout<<"\n\t\t ENTER DEVELOPERS : ";
        gets(c1.dev);
        cout<<"\n\t\t ENTER LANGUAGE : ";
        gets(c1.lang);
        cout<<"\n\t\t ENTER YEAR : ";
        cin>>c1.year;
        cout<<"\n\t\t ENTER QUANTITY OF CDS : ";
        cin>>c1.stock;
        cout<<"\n\t\t ENTER SIZE(mb) : ";
        cin>>c1.size;
        out.write((char*)&c1,sizeof(c1));
        out.close();
    }
}
void main()
{ 
    clrscr();
    char cho='n';
    int ch;
    cd c1;
    //c1.graph();
    c1.pass();
    do
    {
        clrscr();
        line();
        cout<<"\n\t\t\t\tMAIN MENU";
        line();
        cout<<"\n\n\t\t\t 1.PURCHASE"
        <<"\n\t\t\t 2.SALE"
        <<"\n\t\t\t 3.RENTAL"
        <<"\n\t\t\t 4.VIEW"
        <<"\n\t\t\t 5.DELETE"
        <<"\n\t\t\t 6.MODIFY"
        <<"\n\t\t\t 7.QUIT";
        line();
        cout<<"\n\n\n\t ENTER CHOICE :- ";
        cin>>ch;
        switch (ch)
        {
            case 1: c1.purchase();
            break;
            case 2: c1.sale();
            break;
            case 3: c1.rent();
            break;
            case 4:c1.view();
            break;
            case 5:c1.del();
            break;
            case 6:c1.modi();
            break;
            case 7:exit(0);
            default:
            clrscr();
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tINVALID CHOICE!\n\n\t\t\t\tTRY AGAIN!";
        }
        cout<<"\n\n\n\n\t\t\tDO YOU WANT TO CONTINUE?(y/n):";
        cin>>cho;
    }while(cho=='y'||cho=='Y');
}
