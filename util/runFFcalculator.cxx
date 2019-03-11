#include "../src/FFcalculator_muon.cxx"
#include "../src/FFcalculator_electron.cxx"
#include "../inc/SampleHandler.h"

int main(int argc,char *argv[]){

  SampleHandler someone(argv[1]);
  someone.Loop(argv[2]);

  //SampleHandler data("datacombined");
  //SampleHandler diboson("diboson");
  //SampleHandler ssWW("ssWW");
  //SampleHandler WZ("WZ");
  //SampleHandler complement("complement");
  /*SampleHandler ttV("ttV");
  SampleHandler tV("tV");
  SampleHandler ttH("ttH");
  SampleHandler Vgam("Vgam");
  data.Loop("FFcal_2jets");
  diboson.Loop("FFcal_2jets");*/
  //WZ.Loop("FFcal_2jets");
  //ssWW.Loop("FFcal_2jets");
  //complement.Loop("FFcal_2jets");
  /*ttV.Loop("FFcal_2jets");
  tV.Loop("FFcal_2jets");
  ttH.Loop("FFcal_2jets");
  Vgam.Loop("FFcal_2jets");
  
  FFcalculator_muon(); */

  //SampleHandler data_QmisID("datacombined");
  // data_QmisID.Loop("FFcal_QmisID_2jets");
  //SampleHandler Zjets("Zjets");
  // Zjets.Loop("FFcal_2jets");
  //SampleHandler DY("DY");
   //DY.Loop("FFcal_2jets");
  //SampleHandler ttbar("ttbar");
  // ttbar.Loop("FFcal_2jets");
   
  //FFcalculator_electron();
  return 0;
}
