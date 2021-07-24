#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int cvv=50,cvs=100;
class patient{
	char name[32],city[32],vacc[15],gender[6],data[35];
	int age,token;;int num=0;
	long long int id;
	public:
		int checkavailability(){
			if(cvv>0 && cvs>0){
				num=3;
				getpatientdetailsforvaccination();
				return 1;
			}
			else if(cvv>0 && cvs==0){
				num=1;
				cout<<"Only covaxine Available"<<endl;
				getpatientdetailsforvaccination();
				return 1;
			}
			else if(cvv==0 && cvs>0){
				num=2;
				cout<<"Only covishield Available"<<endl;
				getpatientdetailsforvaccination();
				return 1;
			}
			else{
				return 0;
			}
		}
		void getpatientdetailsforvaccination(){
			ofstream fout;
			fout.open("C:\\Users\\tkart\\Desktop\\personal\\project.txt",ios::app);
			cout<<"Enter your name : ";
			cin>>name;
	
			cout<<"Enter your age : ";
			cin>>age;
	
			cout<<"Enter your gender : ";
			cin>>gender;
			
			cout<<"City : ";
			cin>>city;
			if(num==3){
				cout<<"Vaccine : ";
				cin>>vacc;
			}
			else if(num==1){
			//	vacc="covaxine";
			}
			else if(num==2){
				//vacc="covishield";
			}
			if(!strcmp(vacc,"covishield")){
				cvs--;
			}
			else{
				cvv--;
			}
			cout<<"Enter the Token No : ";
			cin>>token;
			cout<<"Enter Your Aadhar No : ";
			cin>>id;
			fout<<name<<" "<<age<<" "<<gender<<" "<<city<<" "<<vacc<<" "<<id<<endl;
			fout.close();
		}
		void vaccineavailable() {
			cout<<"Covaxine : "<<cvv<<endl;
			cout<<"Covishield : "<<cvs<<endl;
		}
		void vaccinatedpersondetails(){
			ifstream fin;
			fin.open("C:\\Users\\tkart\\Desktop\\personal\\project.txt");
			while(fin){
				fin>>data;
				cout<<"Name : "<<data<<endl;
				fin>>data;
				cout<<"Age : "<<data<<endl;
				fin>>data;
				cout<<"Gender : "<<data<<endl;
				fin>>data;
				cout<<"City : "<<data<<endl;
				fin>>data;
				cout<<"Vaccine : "<<data<<endl;
				fin>>data;
				cout<<"Token No : "<<data<<endl;
				fin>>data;
				cout<<"Aadhar No : "<<data<<endl;
			}
			fin.close();
		}
		void seconddose(char date[]){
			char vaccine[20];
			cout<<"Enter the vaccine name : ";
			cin>>vaccine;
			int d=(date[0]-48)*10+(date[1]-48);
			int m=(date[3]-48)*10+(date[4]-48);
			int y=(date[6]-48)*1000+(date[7]-48)*100+(date[8]-48)*10+(date[9]-48);
			if(!strcmp(vaccine,"covaxine")){
				if(m==12){
					m+=1;
					m=m%12;
					y++;
				}
				else{
					m++;
				}
			}
			else{
				if(m>9){
					m+=3;
					m=m%12;
					y++;
				}
				else{
					m+=3;
				}
			}
			cout<<"Second Dose Date : ";
			cout<<d<<'-'<<m<<'-'<<y<<endl;
		}
		int login(char user[],char pass[]){
			ifstream fin;char line[40],name[32];strcpy(name,user);
			fin.open("C:\\Users\\tkart\\Desktop\\personal\\login.txt");
			while(!fin.eof()){
				fin.getline(line,40);
				if(!strcmp(line,strcat(user,pass))){
					fin.close();
					cout<<"Welcome "<<name<<endl;
					return 1;
				}
			}
			fin.close();
			cout<<"Invalid credentials"<<endl;
			return 0;
		}
		void signup(){
			char user[15],pass[15];
			cout<<"Enter username (less than 15 characters) : ";
			cin>>user;
			cout<<endl;
			cout<<"Enter password (less than 15 characters) : ";
			cin>>pass;
			cout<<endl;
			ofstream fout;
			fout.open("C:\\Users\\tkart\\Desktop\\personal\\login.txt",ios::app);
			fout<<user<<pass;
			fout.close();
		}
};
int main(){
	patient p[150];int o;char pr,date[10];int i=0,avail,flag,c=3;
	char username[15],pass[15];
	cout<<"******************VACCINE MANAGEMENT SYSTEM****************** "<<endl;
	label:
	cout<<"Press :"<<endl;
	cout<<"1. Vaccine Registration"<<"			"<<"2. Vaccine Available"<<endl;
	cout<<"3. Vaccinated person Details"<<"		"<<"4.Second Dose Date "<<endl;
	cout<<"5. User login"<<"					"<<"6. User signup "<<endl;
	cin>>o;
	if(o==1){
		avail=p[i].checkavailability();
		if(avail==0){
			cout<<"Sorry No stack Available right now :-("<<endl;
		}
		else{
			cout<<"Registration successful :-)"<<endl;
			i++;
		}
	}
	else if(o==2){
		p[i].vaccineavailable();
	}
	else if(o==3){
		p[i].vaccinatedpersondetails();
	}
	else if(o==4){
		cout<<"********** Second Dose Date *************"<<endl;
		cout<<"Enter the 1st vaccination Date (dd-mm-yyyy) : ";
		cin>>date;
		p[i].seconddose(date);
	}
	else if(o==5){
		cout<<"************User Login**************"<<endl;
		label1:
		cout<<"username		: ";
		cin>>username;
		cout<<endl<<"password		: ";
		cin>>pass;
		flag=p[i].login(username,pass);
		if(flag==0){
			c--;
			if(c!=0)
				goto label1;
		}
		
	}
	else if(o==6){
		p[i].signup();
	}
	cout<<"Do you want to continue press Y";
	cin>>pr;
	if(pr=='Y'||pr=='y'){
		goto label;
	}
	else{
		cout<<"********* Thank You ********";
	}
	
		
		
		
	
	return 0;
		
}
