#include "TFile.h"
#include "TH1.h"
#include "../inc/SampleHandler.h"
//#include "../src/FFApp.cxx"
#include "../src/DataMC.cxx"
#include "../src/count.cxx"
//int main(){
int main(int argc,char *argv[]){
 
  SampleHandler someone(argv[1]); 
  someone.Loop(argv[2]);
  /*SampleHandler data("datacombined");
  SampleHandler diboson("diboson");
  SampleHandler ttV("ttV");
  SampleHandler tV("tV");
  SampleHandler ttH("ttH");
  SampleHandler DY("DY");
  SampleHandler WW("WW");
  SampleHandler Vgam("Vgam");
  SampleHandler Zjets("Zjets");
  SampleHandler ttbar("ttbar");
  data.Loop("FFApp_2jets");
  diboson.Loop("FFApp_2jets");
  ttV.Loop("FFApp_2jets");
  tV.Loop("FFApp_2jets");
  ttH.Loop("FFApp_2jets");
  DY.Loop("FFApp_2jets");
  WW.Loop("FFApp_2jets");
  Vgam.Loop("FFApp_2jets");
  Zjets.Loop("FFApp_2jets");
  ttbar.Loop("FFApp_2jets");
  data.Loop("QmisID_2jets");
  data.Loop("FFQmis_2jets");*/
  
  /*FFApp(0);
  count();*/
  //DataMC();
  return 0;
} 
