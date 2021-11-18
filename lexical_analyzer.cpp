/*
´Ê·¨·ÖÎöÆ÷ 
*/ 
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<set>
using namespace std;

vector< pair<int, string> > se;
int tail = 0;
string reserve[] = {"short","int","bool","long","float","double","char","using","for","while","do","continue","break",\
                   "return","void","namespace","case","auto","cout","endl"};
char ch, prech = '$';
string name;
bool flag;
int row = 1;

const int doubleplus = 31;
const int plusequal = 32;
const int Plus = 33;
const int doublesub = 34;
const int subequal = 35;
const int sub = 36;
const int multiequal = 37;
const int multi = 38;
const int divequal = 39;
const int Div = 40;
const int logicand = 41;
const int Bit_and = 42;
const int logicor = 43;
const int Bit_or = 44;
const int powequal = 45;
const int pow = 46;
const int modequal = 47;
const int mod = 48;
const int notequal = 49;
const int neg = 50;
const int leftsquare = 51;
const int rightsquare = 52;
const int leftround = 53;
const int rightround = 54;
const int leftflower = 55;
const int rightflower = 56;
const int Equal = 57;
const int grant = 58;
const int comma = 59;
const int semicolon = 60;
const int lessequal = 61;
const int Less = 62;
const int greaterequal = 63;
const int Greater = 64;
const int question = 65;
const int colon = 66;
const int singlechar = 67;
const int multichar = 68;
const int import = 69;
const int std_out = 70;
const int std_in = 71;
const int unknown = 72;
const int intnum = 100;
const int floatnum = 101;
const int scinum = 102;
const int hexnum = 103;

bool digit()
{
	return ch >= '0' && ch <= '9' ? 1 : 0;
}

bool letter()
{
	return (ch >= 'a' && ch <='z') || (ch >= 'A' && ch <= 'Z') ? 1 : 0;
}

void in(int op, int x)
{
	if(op == 0)	name += ch;
	else if(op == 1)	prech = ch;
	
	se.push_back({x, name});
}

void g()
{
	if(scanf("%c", &ch) == 1)	return ;
	cout<<"Size:"<<se.size()<<endl;
	for(auto i : se)
	{
		cout<<' '<<i.first<<' '<<i.second<<endl;
	}
	cout<<"Input end!"<<endl;
	flag = 1;
	//exit(0);
}

void cg()
{
	name += ch;
	g();
}

void sci()
{
	if(ch == '+' || ch == '-')
	{
		cg();
		
	}
	if(digit())
	{
		while(digit())
		{
			cg();
		}
		se.push_back({scinum, name});
	}
	else
	{
		cout<<ch<<"Error:"<<scinum<<endl;
	}
}

void number()
{
	while(digit())
	{
		cg();
	}
	if(ch == '.')
	{
		cg();
		if(digit())
		{
			while(digit())
			{
				cg();
			}
			if(ch == 'E' || ch == 'e')
			{
				cg();
				sci();
			}
			else
			{
				prech = ch;
				se.push_back({floatnum, name});
			}
		}
		else
		{
			cout<<ch<<"Error:"<<floatnum<<endl;
		}
	}
	else if(ch == 'E' || ch == 'e')
	{
		cg();
		sci();
	}
	else
	{
		prech = ch;
		se.push_back({intnum, name});
	}
}

void words()
{
	name = "";
	if(prech == '$') g();
	else
	{
		ch = prech;
		prech = '$';
	}
	while(ch == ' ' || ch == '\n' || ch == '\t')
	{
		if(ch == '\n')	row++;
		g();
	}
	if(letter() || ch == '_')
	{
		while(letter() || digit() || ch == '_')
		{
			cg();
		}
		prech = ch;
		int id = 0;
		for(auto i : reserve)
		{
			id++;
			if(i == name)
			{
				se.push_back({id, name});
				id = 0;
				break;
			}
		}
		if(id)
		{
			se.push_back({id, name});
		}
	}
	else if(ch == '0')
	{
		name += ch;
		g();
		if(ch == 'X' || ch == 'x')
		{
			cg();
			if(digit() || (ch >= 'a' && ch <= 'f') || (ch >='A') && ch <= 'F')
			{
				while(digit() || (ch >= 'a' && ch <= 'f') || (ch >='A') && ch <= 'F')
				{
					cg();
				}
				prech = ch;
				se.push_back({hexnum, name});
			}
			else
			{
				cout<<"Error:"<<hexnum<<endl;
			}
		}
		else if(digit())	number();
	}
	else if(digit())
	{
		number();
	}
	else if(ch == '+')
	{
		cg();
		if(ch == '+') in(0, doubleplus);
		else if(ch == '=')	in(0, plusequal);
		else	in(1, Plus);
	}
	else if(ch == '-')
	{
		cg();
		if(ch == '-') in(0, doublesub);
		else if(ch == '=')	in(0, subequal);
		else	in(1, sub);
	}
	else if(ch == '*')
	{
		cg();
		if(ch == '=') in(0, multiequal);
		else	in(1, multi);
	}
	else if(ch == '/')
	{
		cg();
		if(ch == '/')
		{
			while(ch!='\n')	cg();
		}
		else if(ch == '=')	in(0, divequal);
		else	in(1, Div);
	}
	else if(ch == '&')
	{
		cg();
		if(ch == '&')	in(0, logicand);
		else	in(1, Bit_and);
	}
	else if(ch == '|')
	{
		cg();
		if(ch == '|')	in(0, logicor);
		else in(1, Bit_or);
	}
	else if(ch == '^')
	{
		cg();
		if(ch == '=')	in(0, powequal);
		else	in(1, pow);
	}
	else if(ch == '%')
	{
		cg();
		if(ch == '=')	in(0, modequal);
		else in(1, mod);
	}
	else if(ch == '!')
	{
		cg();
		if(ch == '=')	in(0, notequal);
		else	in(1, neg);
	}
	else if(ch == '[')	in(0, leftsquare);
	else if(ch == ']')	in(0, rightsquare);
	else if(ch == '(')	in(0, leftround);
	else if(ch == ')')	in(0, rightround);
	else if(ch == '=')
	{
		cg();
		if(ch == '=')	in(0, Equal);
		else	in(1, grant);
	}
	else if(ch == ',')	in(0, comma);
	else if(ch == ';')	in(0, semicolon);
	else if(ch == '{')	in(0, leftflower);
	else if(ch == '}')	in(0, rightflower);
	else if(ch == '<')
	{
		cg();
		if(ch == '=')	in(0, lessequal);
		else if(ch == '<')	in(0, std_out);
		else	in(1, Less);
	}
	else if(ch == '>')
	{
		cg();
		if(ch == '=')	in(0, greaterequal);
		else if(ch == '>')	in(0, std_in);
		else	in(1, Greater);	
	}	
	else if(ch == '?')	in(0, question);
	else if(ch == ':')	in(0, colon);
	else if(ch == '\'')
	{
		cg();
		while(ch != '\'')	cg();
		in(0, singlechar);
	}
	else if(ch == '"')
	{
		cg();
		while(ch != '"')	cg();
		in(0, multichar);
	}
	else if(ch == '#')	in(0, import);
	else	cout<<ch<<" Error:"<<unknown<<endl;
}

int main()
{
	freopen("test.txt", "r", stdin);
	while(1)
	{
		words();
		if(flag)	break;
	}
	/*
	cout<<se.size()<<endl;
	for(auto i : se)
	{
		cout<<i.first<<' '<<i.second<<endl;
	}
	cout<<"Input end!"<<endl;
	*/
	fclose(stdin);
	return 0;
}
