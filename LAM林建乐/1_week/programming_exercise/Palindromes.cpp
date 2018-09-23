#include <iostream>
#include <string>

using namespace std;
int match(string str)
{
	int m,n1 = str.size(),n2, O;
	n2=n1/2;
	//cout << n1 << n2;
	for(m=0; m<n2 && str[m]==str[n1-m-1]; m++)
	{}
	if(m == n2) //match
	{
		O=0;
	}
	else //not match
	{	
		O=1;
	}
	//cout << O << m << '\n';
	return O;
}

int main()
{
	//Input Part
	string strs[10];
	int i=0, i1=0, i2=0;
	getline(cin,strs[0]);
	if (strs[0].size() != 0)
	{
		for(i=1 ; i<10 && strs[i-1].size() != 0; i++)
		{
			getline(cin,strs[i]);
		}
	
	}
	//Recognition Part
	int m,n1,n2,r1,r2;
	string adj;
	for(i1=0; i1<10 && strs[i1].size() != 0; i1++) //traversal every strings
	{
		n1=strs[i1].size();
		n2=n1/2;
		r1=match(strs[i1]);
		adj=strs[i1];
		for(i2=0; i2<n1; i2++ ) //adjust the letters
		{
			if(adj[i2]=='3')
			{
				adj[i2] = 'E';
			}
			else if(adj[i2]=='L')
			{		
				adj[i2] = 'J';
			}
			else if(adj[i2]=='2')
			{
				adj[i2] = 'S';
			}
			else if(adj[i2]=='5')
			{
				adj[i2] = 'Z';
			}
			else if(adj[i2]=='0')
			{
				adj[i2] = 'O';
			}
			else if(i2 != n2 && (adj[i2]=='B'||adj[i2]=='C'||adj[i2]=='D'||adj[i2]=='F'||adj[i2]=='G'||adj[i2]=='K'||adj[i2]=='N'||adj[i2]=='P'||adj[i2]=='Q'||adj[i2]=='R'||adj[i2]=='4'||adj[i2]=='6'||adj[i2]=='7'||adj[i2]=='9'))
			{
				adj.erase(adj.begin()+i2);
				i2--;
			}
		}
		r2=match(adj);
		if(adj.size() != strs[i1].size())
		{
			r2=1;
		}
		//cout << r2 << adj << '\n';
		if(r1==0 && n1%2==0)
		{
			if(r2==0)
			{
				cout << strs[i1] << " -- is a mirrored palindrome." << '\n' << '\n';
			}
			else
			{
				cout << strs[i1] << " -- is a regular palindrome." << '\n' << '\n';
			}
		}
		if(r1==0 && n1%2==1)
		{
			if((adj[n2]=='A'||adj[n2]=='H'||adj[n2]=='I'||adj[n2]=='M'||adj[n2]=='O'||adj[n2]=='T'||adj[n2]=='U'||adj[n2]=='V'||adj[n2]=='W'||adj[n2]=='X'||adj[n2]=='Y'||adj[n2]=='8') && r2==0)
			{
				cout << strs[i1] << " -- is a mirrored palindrome." << '\n' << '\n';
			}
			else
			{
				cout << strs[i1] << " -- is a regular palindrome." << '\n' << '\n';
			}
		}
		if(r1==1 && n1%2==0)
		{
			if(r2==0)
			{
				cout << strs[i1] << " -- is a mirrored string." << '\n' << '\n';
			}
			else
			{
				cout << strs[i1] << " -- is not a palindrome." << '\n' << '\n';
			}
		}
		if(r1==1 && n1%2==1)
		{
			if((adj[n2]=='A'||adj[n2]=='H'||adj[n2]=='I'||adj[n2]=='M'||adj[n2]=='O'||adj[n2]=='T'||adj[n2]=='U'||adj[n2]=='V'||adj[n2]=='W'||adj[n2]=='X'||adj[n2]=='Y'||adj[n2]=='8') && r2==0)
			{
				cout << strs[i1] << " -- is a mirrored string." << '\n' << '\n';
			}
			else
			{
				cout << strs[i1] << " -- is not a palindrome." << '\n' << '\n';
			}
		}
	}
	return 0;
}	
