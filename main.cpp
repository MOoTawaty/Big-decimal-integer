#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

class BigDiceInt
{
private:
      string num;
      //string res;

public:

      BigDiceInt (int decInt)
      {
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
            //num = '';
      }

      BigDiceInt(string number)
      {
            num = number;
      }

      void rev()
      {
            reverse(num.begin() , num.end());
      }

      ///
       ///
        ///
      BigDiceInt operator+(BigDiceInt& obj)
      {
            BigDiceInt result;

            if(num[num.size()-1] == '-' && obj.num[obj.num.size()-1] != '-') /// /////////////////
            {
                  cout << "*****" << endl;
                  // Calculate lengths of both string
                  int n1 = num.length()-1 , n2 = obj.num.length();

                  ///ensure that num1 is biger than num2
                  int ss=1;  /// using in adding '-'
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
                            cout << "#####" << endl;

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
                              cout << "/**<*/\n";

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

                              cout << "&&&\n";
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

      BigDiceInt b1("1230000000000000001");
      BigDiceInt b2("-30000000000000001");
      BigDiceInt b3;
      b1.rev();
      b2.rev();
      /**<  */
      cout << "Welcome to FCI Calculator\n";
      cout << "----------------------------------------\n";
      cout << "1- Perform Addition\n";
      cout << "2- Perform Subtraction\n";
      cout << "3- Exit\n";

      int count = 0;
      cout << "Enter UR Choice:";
      cin >> count;
      if(count == 1 || count == 2)
            b3 = b1 + b2;
      else
            return 0;

      cout << "num2 + num1 = " << b3 << endl;
      cout << endl;

    return 0;
}






