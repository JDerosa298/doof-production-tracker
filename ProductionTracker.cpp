/*
Program to track the number of dooflingies produced over the course of a 4 week period
written by John DeRosa
November 2017
Language: C++ (g++ target)
*/
#include <iostream> //including the needed libraries for the program
#include<algorithm>
#include<vector>
#include<numeric>
using namespace std;

int main(void)

{

  int doof=0,i=0,j=0,k=0;// creating the ints needed for iteration through for loops and storing the users input
  std::vector<int>df;// creating a container to store all the inputs into
  for(i=0;i<20;i++) // asking the user to input the production levels for 20 days
  {
   cout<<"please input the number of dooflingies made on day:"<<i+1<<endl;
   cin>>doof;
   df.push_back(doof);

   cout<<"Max:"<< *max_element(df.begin(),df.end())<<endl;// telling the user the max number of dooflingies produced in a single day up to that point

   cout<<"Min:"<< *min_element(df.begin(),df.end())<<endl;// telling the user the min number of dooflingies produced in a single day up to that point

   cout<<"average:"<< accumulate(df.begin(),df.end(),0)/df.size()<<endl;// telling the user the average number of dooflingies produced in a

  }                                                                     // day up to that day

  std::vector<int>adiff(df.size());

  adjacent_difference(df.begin(),df.end(),adiff.begin());// finding the difference in day to day production

  for(j=0;j<adiff.size();j++)
      cout<<"The difference in production between day "<<j+1<<" and day "<<j<<" is :"<<adiff[j]<<endl;// displaying the difference to the user

  std::vector<int>con(df.size());

  partial_sum(df.begin(),df.end(),con.begin());// finding the sum of all dooflingies produced unp to and including that day

  cout<<"On day 1 "<<con[0]<<" dooflingies were produced. The day before that we were not recording production levels"<<endl;// displaying the sum for day 1

  for(k=1;k<con.size();k++)//displaying the sum of all dooflingies produced up to and including that day
    cout<<"On day "<<k+1<<" "<<con[k]<<" total dooflingies were produced. The day before the total was "<<con[k-1]<<endl;

 return(0);
}

