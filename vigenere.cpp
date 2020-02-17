#include <iostream>
#include <string>
using namespace std;

string keygen(string message, string keyword)
{

  string word;

  //We take a key string, and map to the entire message
  unsigned int j = 0;
  for (unsigned int i = 0; i < message.length(); i++)
  {
    if (message[i] == ' '){
      //word[j] = ' ';
      word += ' ';
      j++;
    }
    else if (j < keyword.length())
    {
      //word[i] = keyword[j];
      word += keyword[j];
      j++;
    }
    else
    {
      j = 0;
      //word[i] = keyword[j];
      word += keyword[j];
      j++;
    }
  }
  return word;
}

string encrypt(string message, string word){
  string cipherText;
  int x;

  for(unsigned int i=0;i<message.length();i++){
    if(message[i]!=' '){
      x=(message[i]+word[i])%26;

      x+='A';
    }
    else
      x = ' ';

      cipherText.push_back(x);
  }

  return cipherText;
}

string decrypt(string cipherText, string word){
  string PlainText;
  int x;

  for(unsigned int i=0;i<cipherText.length();i++){
    if(cipherText[i]!=' '){
      x=(cipherText[i]-word[i])%26;

      while(x<0)
        x+=26;
        
      x+='A';
    }
    else
      x = ' ';

      PlainText.push_back(x);
  }

  return PlainText;
}

int main(){
  string msg, key, cipher;

  cout<<"Enter message: ";
  getline(cin,msg);

  cout<<"\nEnter key:";
  getline(cin,key);

  for(unsigned int i=0;i<msg.length();i++)
    msg[i]=toupper(msg[i]);
  
  for(unsigned int i=0;i<key.length();i++)
    key[i]=toupper(key[i]);

  string keyword = keygen(msg, key);
  cout<<"\nKey Expansion: "<<keyword;
  cipher = encrypt(msg,key);
  cout<<"\nEncrypted message: "<<cipher;

  cout<<"\n\nDecrypted message: "<<decrypt(cipher,key);
  return 0;
}
