#include<iostream>
#include<string>
using namespace std;
string add(string a,string b)
{
	string result ="";
	int lengthA = a.length();
	int lengthB = a.length();
	while(lengthA >0|| lengthB >0)
	{
		int digitA = lengthA>0 ? a[lengthA-1]-'0':0;
		int digitB = lengthB>0 ? b[lengthB-1] - '0':0;
		int temp =0,carry =0;
		temp = carry + digitA + digitB;
		carry = temp/10;
		temp %= 10;
		result.insert(0,to_string(temp));
		lengthA --;
		lengthB --;
	}
	return result;

}
int main(){
	char num_1[100];
	char num_2[100];
	cout<<"Enter your number1:";
	cin>>num_1;
	cout<<"Enter your number2:";
	cin>>num_2;
	cout<<add(num_1,num_2)<<endl;
	return 0;

}

