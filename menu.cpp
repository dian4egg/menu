// menu.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include  <string>
#include <vector>
#include <fstream>
using namespace std;
string s[]={"0","1","2","3","4","5","6","7","8","9"};
string a[]={"1.rabota c failami","2.Prosmotr","3.redactor","4.dobavlenie","5.ydalenie"};
string a1[]={"1.zapis","2.4tenie"};
string a3[]={"1.ddd","2.fff","3.ggg"};
string a4[]={"1.pervim","2.po kluchu"};
string a5[]={"1.vvv","2.ddd","3.zzz","4.lll"};
string b[]={"1.da","0.net"};
int vv=0;int j=0;int z=0;
struct nod{
	string node;
	nod *next;
	nod *prew;
};
class list{
	private: 
		nod *first;
	public:
		list(){
			first=NULL;
		}
		void add(string nodu);
		void show();
		void addfirst();
		void addkluch();
		void write();
		void read(list h);
};
void list::read(list h){
	system("cls");
	string S;
	ifstream in;
	in.open("out.txt");
	while(!in.eof()){
		getline(in,S);
		add(S);
	}
	cout<<"Yspex!";
	getch();
}
void list::write(){
	system("cls");
	if(first==NULL)
	{cout<<"spisok empty";}
	else{
	ofstream out;
	out.open("out.txt");
	nod *write=first;
	do{
		out<<write->node;
			if(write->prew!=NULL){
				out<<endl;
			}
		write=write->prew;
	}while(write!=NULL);
	out.close();
	cout<<"zapican B out.txt";
	}
	getch();
}
void list::addkluch(){system("cls");
	if(first==NULL){
		cout<<"add first element ";
	}
	else{
	int key;
	int j=0;
	nod *kluch=first;
	do{j++;kluch=kluch->prew;}while(kluch!=NULL);
	cout<<"vvedite kluch ot 1 do "<<j<<endl;
	cin>>key;
	kluch=first;
	if(key==j){
		for(int i=1;i<=key-1;i++){
			kluch=kluch->prew;
		}
	}
	else{
		for(int i=1;i<=key-1;i++){
			kluch=kluch->prew;
		}
	}
	cout<<"vedite slovo"<<endl;
	string nodu;
	cin>>nodu;
	nod *dr= new nod;
	dr->node=nodu;
	if(key==j){
		dr->prew=NULL;
		kluch->prew=dr;
		dr->next=kluch;
	}
	else{	
		dr->next=kluch;
		dr->prew=kluch->prew;
		kluch->prew=dr;
	}
	cout<<"Ycpex!";
	}
	getch();
}
void list::addfirst(){system("cls");
	cout<<"vvedite element spiska"<<endl;
	string nodu;
	cin>>nodu;
	add(nodu);
	cout<<"ycpex!";
	getch();

}
void list::add(string nodu){
		nod * dr= new nod;
		if(first!=NULL){first->next=dr;}
		dr->node=nodu;
		dr->next=NULL;
		dr->prew=first;
		first=dr;
}
void list::show(){system("cls");
int rr=1;
	if(first==NULL){
		cout<<"empty"<<endl;
	}
	else{
	nod *show=first;
	do{cout << rr << ") ";
	rr++;
		cout<<show->node<<endl;
		show=show->prew;
	}while(show!=NULL);
	}
	getch();
}
void func(){system("cls");
cout<<"call function";j=10;
getch();
}
list h;
int men( string menu[], int k)
{int f=0;
int max=7;
vector <int> raz;
	for(int i=0;i<k;i++){
		f=menu[i].length();
		if(f>max){max=f;}
	}
	for(int i=0;i<k;i++){
		raz.push_back(max-menu[i].length());
	}
	int exit1;
	int k1;
	int st=0; 
    int code; 
	int zz=0;
	string gg;
	do {	if(j==0 && a[0]==menu[0]){st=vv;}
			if(j==10){st=z;}
			system("cls"); 
			if(b[0]!=menu[0]){st=(st+k+1)%(k+1);}
			if(b[0]==menu[0]){cout<<"vi yvereni chto xotite viiti?"<<endl; if(zz==0){ st=1;}zz+=1;st=(st+k)%(k);}
			
			if(a[0]!=menu[0] && b[0]!=menu[0]){cout<<"----"<< a[vv]<<"----"<<endl;}
			for(int i=0;i<k;i++){
				if (st==i){cout<<"* "<<menu[i];
					for(int t=0;t<raz[i];t++){
						cout<<" ";
					}
					cout<<"*"<<endl;
				}
				else{cout<<"  "<<menu[i]<<endl;}
			}
			if(a[0]==menu[0]){
				if(st==k){cout<<"* 0.vihod";
					for(int t=0;t<max-7;t++){
						cout<<" ";
					}
					cout<<"*"<<endl;
				}
				else{cout<<"  0.vihod"<<endl;}
			}
			if(a[0]!=menu[0] && b[0]!=menu[0] ){
					if(st==k){cout<<"* 0.nazad";
						for(int t=0;t<max-7;t++){
						cout<<" ";
					}
					cout<<"*"<<endl;
						}
					else{cout<<"  0.nazad"<<endl;}
				}
            code=getch(); 
			if(a[0]!=menu[0]){
				if(code==27){int k=sizeof(a) / sizeof(a[0]);men(a,k);} 
			}
			if(a[0]==menu[0]){
				if(code==27){vv=5;
					int k1=sizeof(b) / sizeof(b[0]);men(b,k1);
				}
			}
			for(int i=0;i<k+1;i++){
				gg=code;          // присваивание к заданной цифра
				if(gg==s[i]){ st=i-1;}
			}
            if (code==224){
				code=getch();
                if (code==80) st++; 
                if (code==72) st--; 
            }
			j++;
	}while(code!=13);
	j=0;
	if(menu[0]==a[0]){
		L:switch(st){
			case 0:vv=st;k1=sizeof(a1) / sizeof(a1[0]); men(a1,k1);break;
			case 1:vv=st;z=st;h.show();k1=sizeof(a) / sizeof(a[0]); men(a,k1);break;
			case 2:vv=st;k1=sizeof(a3) / sizeof(a3[0]); men(a3,k1);break;
			case 3:vv=st;k1=sizeof(a4) / sizeof(a4[0]); men(a4,k1);break;
			case 4:vv=st;k1=sizeof(a5) / sizeof(a5[0]); men(a5,k1);break;
		  }
		if( st==k){vv=5;int k=sizeof(b) / sizeof(b[0]);men(b,k);}
	}
	else{
		switch(vv){
			case 0:if (st==0){st=vv;h.write();goto L;}
				   if (st==1){st=vv;h.read(h);goto L;}
			case 2:
				for(int i=0;i<k;i++){
					if (st==i){z=st;st=vv;func();goto L;}
				}
			case 3:if (st==0){st=vv;h.addfirst();goto L;}
				   if (st==1){st=vv;h.addkluch();goto L;}
			case 4:
				for(int i=0;i<k;i++){
					if (st==i){z=st;st=vv;func();goto L;}
				}
			case 5:if(st==0){exit(0);}
				   if(st==1){int k=sizeof(a) / sizeof(a[0]);men(a,k);}
		}
		if( st==k){
			int k=sizeof(a) / sizeof(a[0]);men(a,k);
		}
	}

	return 0;
}
int main()
	{
	//h.add("mama");
	//h.add("papa");
	int k=sizeof(a) / sizeof(a[0]);
	int st=men(a,k);
	system("cls");
	system("pause");
}
 
 

