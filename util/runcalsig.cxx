#include "../inc/SampleHandler.h"
#include "../src/GHTBCs.cxx"
int main()
{
  SampleHandler nonres("nonres");SampleHandler H260("mH260"); SampleHandler H300("mH300");
  //SampleHandler H400("mH400"); SampleHandler H500("mH500");
  /*SampleHandler diboson("diboson");
  SampleHandler ttV("ttV");
  SampleHandler tV("tV");
  SampleHandler ttH("ttH");
  SampleHandler Wjets("Wjets");
  SampleHandler Zjets("Zjets");
  SampleHandler ttbar("ttbar");*/
  //H260.cutflow(2);    H300.cutflow(2);  H400.cutflow(2);  H500.cutflow(2);
  nonres.cutflow();//  H260.cutflow(3); H300.cutflow(3);  H400.cutflow(3);  H500.cutflow(3);
  //cout<<"H260:"<<endl;H260.real_cutflow();
  //cout<<"H300:"<<endl;H300.real_cutflow();
  //cout<<"H400:"<<endl;H400.real_cutflow();
  //cout<<"H500:"<<endl;H500.real_cutflow();
  
  //nonres.cutflow(4);//  H260.cutflow(4); H300.cutflow(4);  H400.cutflow(4);  H500.cutflow(4);
  return 0;
}

