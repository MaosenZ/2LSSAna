#ifndef READFF_CXX
#define READFF_CXX
#include<iostream>

using namespace std;
void readFF(float &ff_ele,float &ff_mu,TString config){
  string ff_file_name;
  if(config.Contains("FFApp")||config.Contains("FFQmis")){
     if(config.Contains("2jets")) ff_file_name="output/ff_1jets.txt";
     if(config.Contains("3jets")) ff_file_name="output/ff_2jets.txt";
     ifstream ff_file(ff_file_name.c_str(),ifstream::in);
     string line;
     while(getline(ff_file,line)){
        const char* readline=line.c_str();
        char dsid[100];float tmp_val;
        sscanf(readline,"%s %f",dsid,&tmp_val);
        string name(dsid);
        if(name=="ff_ele")ff_ele=tmp_val;
        if(name=="ff_mu")ff_mu=tmp_val;
     }
  }
}
#endif
