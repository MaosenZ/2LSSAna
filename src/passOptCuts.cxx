#include<iostream>
#include<fstream>
bool passOptCuts(TString masspoint,TString input_channel,float dR_l1j, float dR_l2j,float m_ll,float m_l1jj,float m_all){
  //to read cut values
  Float_t fixed_cuts_min[4],fixed_cuts_max[4];
  string inputCutsFile="output/SigOpt/";
  inputCutsFile+=masspoint; inputCutsFile+="_";
  if(input_channel=="ee")inputCutsFile+="ee.txt";
  if(input_channel=="mumu") inputCutsFile+="mumu.txt";
  if(input_channel=="emu")inputCutsFile+="emu.txt";
  ifstream ff_file(inputCutsFile.c_str(),ifstream::in);
  string line;
  int k=0;
  while(getline(ff_file,line)){
     const char* readline=line.c_str();
     float lower_cut,higher_cut;
     sscanf(readline,"%f %f",&lower_cut,&higher_cut);
     fixed_cuts_min[k]=lower_cut;
     fixed_cuts_max[k]=higher_cut;
     k++;
     //cout<<lower_cut<<" "<<higher_cut<<endl;
  }
  //to judge 
  //if(masspoint=="mH260" || masspoint=="mH300"){
  if(masspoint=="mH260" || masspoint=="mH300" || masspoint=="mH400"){// for interpolation
     //dR_l1j m_ll m_l1jj m_all
     if(dR_l1j>fixed_cuts_min[0] && dR_l1j<fixed_cuts_max[0] &&
        m_ll>fixed_cuts_min[1] && m_ll<fixed_cuts_max[1] &&
        m_l1jj>fixed_cuts_min[2] && m_l1jj<fixed_cuts_max[2] &&
        m_all>fixed_cuts_min[3] && m_all<fixed_cuts_max[3]) return true;
     else return false;
  }
  //if(masspoint=="mH400" || masspoint=="mH500" || masspoint=="nonres"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"){
  if(masspoint=="mH500" || masspoint=="nonres"||masspoint=="H280_S135"||masspoint=="H300_S135"||masspoint=="H320_S135"||masspoint=="H340_S135"||masspoint=="H340_S145"||masspoint=="H340_S155"||masspoint=="H340_S165"){//for interpo
    //dR_l2j dR_l1j m_ll m_l1jj
     if(dR_l2j>fixed_cuts_min[0] && dR_l2j<fixed_cuts_max[0] &&
        dR_l1j>fixed_cuts_min[1] && dR_l1j<fixed_cuts_max[1] &&
        m_ll>fixed_cuts_min[2] && m_ll<fixed_cuts_max[2] &&
        m_l1jj>fixed_cuts_min[3] && m_l1jj<fixed_cuts_max[3]) return true;
     else return false;
  }
  
  return false;
}
