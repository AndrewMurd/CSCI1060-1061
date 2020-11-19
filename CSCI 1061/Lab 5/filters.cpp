//Andrew Murdoch
//CSCI 1061U
//filters.cpp
//2019-03-10

#include <iostream>
#include <algorithm>

using namespace std;

//Base Class
class Filter
{
protected:
  string _name;

public:
  Filter() {}
  //Initilize name of filter
  Filter(const string &name) : _name(name) {}
  virtual ~Filter() {}
  //apply filter to string
  virtual string apply(const string &input) = 0;
  //return name of filter
  virtual string get_name() { return _name; }
};

class Capitalize : public Filter
{
protected:
  string _name = "Capitalize";

public:
  Capitalize() {}
  Capitalize(const string &name) : _name(name) {}
  ~Capitalize() {}

  string apply(const string &input)
  {
    string str = input;
    for (int i = 0; i < str.length(); i++)
    {
      //convert chars to upper case
      str[i] = toupper(str[i]);
    }
    return str;
  }

  string get_name() { return _name; }
};

class CapitalizeFirstLetter : public Filter
{
protected:
  string _name = "CapitalizeFirstLetter";

public:
  CapitalizeFirstLetter() {}
  CapitalizeFirstLetter(const string &name) : _name(name) {}
  ~CapitalizeFirstLetter(){};

  string apply(const string &input)
  {
    string str = input;
    //Convert first char of string to upper case
    str[0] = toupper(str[0]);
    return str;
  }

  string get_name() { return _name; }
};

class CapitalizeFirstLetterOfEveryWord : public Filter
{
protected:
  string _name = "CapitalizeFirstLetterOfEveryWord";

public:
  CapitalizeFirstLetterOfEveryWord() {}
  CapitalizeFirstLetterOfEveryWord(const string &name) : _name(name) {}
  ~CapitalizeFirstLetterOfEveryWord(){};

  string apply(const string &input)
  {
    string str = input;
    str[0] = toupper(str[0]);
    for (int i = 0; i < str.length(); i++)
    {
      //if loop reaches space meaning new word convert next char to upper case 
      if (str[i] == ' ')
      {
        str[i + 1] = toupper(str[i + 1]);
      }
    }
    return str;
  }

  string get_name() { return _name; }
};

class Obenglobish : public Filter
{
protected:
  string _name = "Obenglobish";

public:
  Obenglobish() {}
  Obenglobish(const string &name) : _name(name) {}
  ~Obenglobish(){};

  string apply(const string &input)
  {
    string str = "";
    for (int i = 0; i < input.length(); i++) {
      char c = input[i];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
      {
        if (c == 'e' && i == input.length() -1)
        {
          str += c;
        }
        else
        {
          char x = input[i - 1];
          if(i != 0 && x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') 
          {
            str += c;
          } 
          else 
          {
            str = str + "ob" + c;
          }  
        }
      }
      else str += c;
    }
    return str;
  }

  string get_name() { return _name; }
};

class ReverseString : public Filter
{
protected:
  string _name = "ReverseString";

public:
  ReverseString() {}
  ReverseString(const string &name) : _name(name) {}
  ~ReverseString(){};

  string apply(const string &input)
  {
    string str = input;
    int n = str.length();
    for (int i = 0; i < n / 2; i++)
    {
      //use swap fucntion to reverse string
      swap(str[i], str[n - i - 1]); 
    }
    return str;
  }

  string get_name() { return _name; }
};

class ToSmall : public Filter
{
protected:
  string _name = "ToSmall";

public:
  ToSmall() {}
  ToSmall(const string &name) : _name(name) {}
  ~ToSmall(){};

  string apply(const string &input)
  {
    string str = input;
    for (int i = 0; i < str.length(); i++)
    {
      //convert string to lower case
      str[i] = tolower(str[i]);
    }
    return str;
  }

  string get_name() { return _name; }
};

class Randomize : public Filter
{
protected:
  string _name = "Randomize";

public:
  Randomize() {}
  Randomize(const string &name) : _name(name) {}
  ~Randomize(){};

  string apply(const string &input)
  {
    srand(time(NULL));
    string str = "";
    char temp[input.length()];
    //fill array with spaces
    fill_n(temp, input.length(), ' ');
    for (int i = 0; i < input.length(); i++)
    {
      int x = rand() % input.length();
      for (int j = 0; j < input.length(); j++)
      {
        //if loop finds a open spot in array place character there
        if (temp[x + j] == ' ')
        {
          temp[x + j] = input[i];
          break;
        }
      }
    }
    //create string
    for (int i = 0; i < input.length(); i++)
    {
      str += temp[i];
    }
    return str;
  }

  string get_name() { return _name; }
};

int main()
{
  const int num_filters = 7;
  Filter *filters[num_filters];

  filters[0] = new Capitalize();
  filters[1] = new CapitalizeFirstLetter();
  filters[2] = new CapitalizeFirstLetterOfEveryWord();
  filters[3] = new Obenglobish();
  filters[4] = new ReverseString();
  filters[5] = new ToSmall();
  filters[6] = new Randomize();

  string input;
  cout << "Enter string: ";
  getline(cin, input);

  cout << "Input string: " << input << endl;
  for (int i = 0; i < num_filters; ++i)
  {
    cout << "Filter name:  " << filters[i]->get_name() << endl;
    cout << "Output:       " << filters[i]->apply(input) << endl;
  }

  for (int i = 0; i < num_filters; ++i)
    delete filters[i];

  return 0;
}