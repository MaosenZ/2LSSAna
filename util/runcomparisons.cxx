#include "../inc/SampleHandler.h"
#include "../src/comparisons.cxx"
#include "../src/FFApp.cxx"

int main(){
  
//  SampleHandler  data15_201("data15_201");
  SampleHandler  diboson("diboson");
  SampleHandler  ttV("ttV");
  SampleHandler  ttH("ttH");
  SampleHandler  tV("tV");
  SampleHandler  Wjets("Wjets");
  SampleHandler  Zjets("Zjets");
  SampleHandler  ttbar("ttbar");
  SampleHandler  data("datacombined");

//  data15_201.cutflow();
  data.FFApp(3);
  diboson.FFApp(3);
  ttV.FFApp(3);
  ttH.FFApp(3);
  tV.FFApp(3);
  Wjets.FFApp(3);
  Zjets.FFApp(3);
  ttbar.FFApp(3);
  data.FFApp(3);
  data.Loop_QmisID(3);
  FFApp(0);

  diboson.cutflow(3);
  ttV.cutflow(3);
  ttH.cutflow(3);
  tV.cutflow(3);
  SampleHandler nonres("nonres");SampleHandler H260("mH260");  SampleHandler  H300("mH300"); SampleHandler  H400("mH400"); SampleHandler H500("mH500");
  nonres.cutflow(3); H260.cutflow(3); H300.cutflow(3); H400.cutflow(3); H500.cutflow(3);
  comparisons();
}
