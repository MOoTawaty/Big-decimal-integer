#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

class BigDiceInt
{
private:
      string num;

public:

      BigDiceInt (int decInt)
      {
            // string buffer that contains a sequence of characters
            stringstream ss;
            ss << decInt;
            string str = ss.str();
            num = str;
      }

      int siz()
      {
            return num.size();
      }

      void operator=(const BigDiceInt& obj)
      {
            num = obj.num;
      }


      BigDiceInt()
      {
            num = "                                         ";
      }

      BigDiceInt(string number)
      {
            num = number;
      }

      void rev()
      {
            reverse(num.begin() , num.end());
      }


      BigDiceInt operator+(BigDiceInt& obj)
      {
            BigDiceInt result;

            if(num[num.size()-1] == '-' && obj.num[obj.num.size()-1] != '-') /// /////////////////
            {
                  // Calculate lengths of both string
                  int n1 = num.length()-1 , n2 = obj.num.length();

                  ///ensure that num1 is always bigger than num2
                  int ss=1;  /// using in adding '-'
                  if(n2 > n1)
                        {swap(obj.num ,num);
                         swap(n1 ,n2);
                         ss = 0;
                         }
                  else if(n2 == n1)
                        for (int i=0; i<n1; i++)
                            if (num[i] < obj.num[i]) // number itself in case size1=size2
                                {swap(obj.num ,num);
                                  swap(n1 ,n2);
                                  ss = 0;
                                 }

                  int carry = 0;


                      /// Run loop till small string length
                      /// and subtract digit of str1 to str2
                      for (int i=0; i<n2; i++)
                      {
                          /// Do school mathematics, compute difference of
                          /// current digits

                          int sub = ((num[i]-'0')-(obj.num[i]-'0')-carry);

                          /// If subtraction is less then zero
                          /// we add then we add 10 into sub and
                          /// take carry as 1 for calculating next step
                          if (sub < 0)
                          {
                              sub = sub + 10;
                              carry = 1;
                          }
                          else
                              carry = 0;

                          result.num.push_back(sub + '0');
                      }

                          /// subtract remaining digits of larger number
                      for (int i=n2; i<n1; i++)
                      {
                          int sub = ((num[i]-'0') - carry);

                          /// if the sub value is -ve, then make it positive
                          if (sub < 0)
                          {
                              sub = sub + 10;
                              carry = 1;
                          }
                          else
                              carry = 0;

                          result.num.push_back(sub + '0');
                      }



                      ///Adding '-' minus
                      if(n2 < n1 && ss != 0)
                        {
                              result.num.push_back('-');
                         }
                        else if(n2 == n1 && ss != 0)
                              for (int i=0; i<n1; i++)
                                  if (num[i] > obj.num[i])
                                      {
                                            result.num.push_back('-');
                                            break;
                                       }

                      // reverse resultant string
                      reverse(result.num.begin(), result.num.end());
                      return result;
                      }




                        else if(num[num.size()-1] != '-' && obj.num[obj.num.size()-1] == '-')  /// /////////////////
                        {

                              /// Calculate lengths of both string
                              int n1 = num.length() , n2 = obj.num.length()-1;

                              ///ensure that num1 is biger than num2
                              int ss = 1;
                              if(n2 > n1)
                                    {swap(obj.num ,num);
                                     swap(n1 ,n2);
                                     ss = 0;
                                     }
                              else if(n2 == n1)
                                    for (int i=0; i<n1; i++)
                                        if (num[i] < obj.num[i])
                                            {swap(obj.num ,num);
                                              swap(n1 ,n2);
                                              ss = 0;
                                             }

                              int carry = 0;


                                  /// Run loop till small string length
                                  /// and subtract digit of str1 to str2
                                  for (int i=0; i<n2; i++)
                                  {
                                      /// Do school mathematics, compute difference of
                                      /// current digits

                                      int sub = ((num[i]-'0')-(obj.num[i]-'0')-carry);

                                      /// If subtraction is less then zero
                                      /// we add then we add 10 into sub and
                                      /// take carry as 1 for calculating next step
                                      if (sub < 0)
                                      {
                                          sub = sub + 10;
                                          carry = 1;
                                      }
                                      else
                                          carry = 0;

                                      result.num.push_back(sub + '0');
                                  }

                                      /// subtract remaining digits of larger number
                                  for (int i=n2; i<n1; i++)
                                  {
                                      int sub = ((num[i]-'0') - carry);

                                      /// if the sub value is -ve, then make it positive
                                      if (sub < 0)
                                      {
                                          sub = sub + 10;
                                          carry = 1;
                                      }
                                      else
                                          carry = 0;

                                      result.num.push_back(sub + '0');
                                  }


                                  ///Adding '-' minus
                                  if(n2 < n1 && ss == 0)
                                    {
                                          result.num.push_back('-');
                                     }
                                    else if(n2 == n1 && ss == 0)
                                          for (int i=0; i<n1; i++)
                                              if (num[i] > obj.num[i])
                                                  {
                                                        result.num.push_back('-');
                                                        break;
                                                   }

                                  // reverse resultant string
                                  reverse(result.num.begin(), result.num.end());
                                  return result;
                        }



                        else if(num[num.size()-1] == '-' && obj.num[obj.num.size()-1] == '-')  /// /////////////////
                        {

                              if(num.length() < obj.num.length()) ///num1 > num2
                                    swap(num , obj.num);


                              int carry = 0;
                              for(int i=0 ; i< obj.num.length() -1 ; i++){
                                      int sum = ((num[i] -48) + (obj.num[i] -48) + carry);

                                      result.num[i]=(sum%10 + '0');
                                      carry = sum/10 ;
                                  }

                              for(int j = obj.num.size()-1 ; j< num.size() -1 ; j++){
                                      int sum = ((num[j] -48) + carry);
                                      result.num[j]=(sum%10 + '0');
                                      carry = sum/10 ;
                                  }

                            if(carry)
                                result.num.push_back(carry + 48);

                            result.num.push_back('-');

                            reverse(result.num.begin() , result.num.end());

                            return result;
                        }

                        else{

                              if(num.length() < obj.num.length()) ///num1 > num2
                                    swap(num , obj.num);


                              int carry = 0;
                              for(int i=0 ; i< obj.num.length() ; i++){
                                      int sum = ((num[i] -48) + (obj.num[i] -48) + carry);

                                      result.num[i]=(sum%10 + '0');
                                      carry = sum/10 ;
                                  }

                              for(int j = obj.num.size(); j< num.size() ; j++){
                                      int sum = ((num[j] -48) + carry);
                                      result.num[j]=(sum%10 + '0');
                                      carry = sum/10 ;
                                  }

                            if(carry)
                                result.num.push_back(carry + 48);

                            reverse(result.num.begin() , result.num.end());

                            return result;

                             }

                  }


      friend ostream& operator << (ostream& out, BigDiceInt&obj);
};



ostream& operator << (ostream& out, BigDiceInt &obj)
      {
            for(int o =0 ; o< obj.num.length() ; o++)
                  out << obj.num[o];
            return out;
      }



int main()
{
      BigDiceInt result;
      string res = "";
      string num1;
      string num2;
      while(true){
            cout << "Welcome to FCI Calculator\n";
            cout << "----------------------------------------\n";
            cout << "1- Perform Addition\n";
            cout << "2- Exit\n";

            int count = 0;
            cout << "Enter UR Choice:";
            cin >> count;
            if(count == 1){
                  cout << "Number1 = ";
                  cin >> num1;
                  BigDiceInt number1(num1);
                  cout << "Number2 = ";
                  cin >> num2;
                  BigDiceInt number2(num2);

                  number1.rev();
                  number2.rev();

                  result = number1 + number2;
                  for(int i=0 ; i<result.size() ; i++){
                        if(result[i] != ' ')
                              res += result[i];
                  }
                  cout << "number1 + number2 = " << res << endl;
            }
            else
                  return 0;
      }

    return 0;
}






