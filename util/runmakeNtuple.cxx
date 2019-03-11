#include "../inc/SampleHandler.h"
#include "../src/GHTBCs.cxx"
int main(int argc,char *argv[])
//int main()
{
  SampleHandler data(argv[1]);
  //SampleHandler nonres("nonres");
  /*SampleHandler H260("mH260"); 
  SampleHandler H300("mH300");
  SampleHandler H400("mH400");
  SampleHandler H500("mH500");*/
  /*SampleHandler diboson("diboson");
  SampleHandler ttV("ttV");
  SampleHandler tV("tV");
  SampleHandler ttH("ttH");
  SampleHandler Vgam("Vgam");*/
  //SampleHandler complement("complement");
  /*SampleHandler Zjets("Zjets");
  SampleHandler DY("DY");
  SampleHandler ttbar("ttbar");*/
  /*SampleHandler H280_S135("H280_S135");
  SampleHandler H300_S135("H300_S135"); 
  SampleHandler H320_S135("H320_S135");
  SampleHandler H340_S135("H340_S135");
  SampleHandler H340_S145("H340_S145");
  SampleHandler H340_S155("H340_S155");
  SampleHandler H340_S165("H340_S165");*/
  /*SampleHandler ssWW("ssWW");
  SampleHandler ttW("ttW");
  SampleHandler ttZ("ttZ");
  SampleHandler tZ("tZ");
  SampleHandler WW("WW");
  SampleHandler WZ("WZ");
  SampleHandler ZZ("ZZ");*/

  //std selection
  //data.makeNtuple("nominal_2jets");
  //nonres.makeNtuple("nominal_2jets","preselection");  
  /*H260.makeNtuple("nominal_2jets","preselection");  
  H300.makeNtuple("nominal_2jets","preselection");  
  H400.makeNtuple("nominal_2jets","preselection");  
  H500.makeNtuple("nominal_2jets","preselection");*/
  /*ssWW.makeNtuple("nominal_2jets","preselection");
  ttW.makeNtuple("nominal_2jets","preselection");
  ttZ.makeNtuple("nominal_2jets","preselection");
  tZ.makeNtuple("nominal_2jets","preselection");
  WW.makeNtuple("nominal_2jets","preselection");
  WZ.makeNtuple("nominal_2jets","preselection");
  ZZ.makeNtuple("nominal_2jets","preselection");*/
  /*diboson.makeNtuple("nominal_2jets","preselection");
  ttV.makeNtuple("nominal_2jets","preselection");
  tV.makeNtuple("nominal_2jets","preselection");
  ttH.makeNtuple("nominal_2jets","preselection");
  Vgam.makeNtuple("nominal_2jets","preselection");*/
  //complement.makeNtuple("nominal_2jets","preselection");
  /*Zjets.makeNtuple("nominal_2jets");
  ttbar.makeNtuple("nominal_2jets");
  DY.makeNtuple("nominal_2jets");*/
  /*H280_S135.makeNtuple("nominal_2jets","preselection");  
  H300_S135.makeNtuple("nominal_2jets","preselection");
  H320_S135.makeNtuple("nominal_2jets","preselection");
  H340_S135.makeNtuple("nominal_2jets","preselection");
  H340_S145.makeNtuple("nominal_2jets","preselection");
  H340_S155.makeNtuple("nominal_2jets","preselection");
  H340_S165.makeNtuple("nominal_2jets","preselection");*/
  //QmisID
  //data.makeNtuple("QmisID_2jets");
  data.makeNtuple(argv[2],argv[3]);
  //FFApp
  /*data.makeNtuple("FFApp_2jets");
  diboson.makeNtuple("FFApp_2jets");
  ttV.makeNtuple("FFApp_2jets");
  tV.makeNtuple("FFApp_2jets");
  ttH.makeNtuple("FFApp_2jets");
  Vgam.makeNtuple("FFApp_2jets");
  Zjets.makeNtuple("FFApp_2jets");
  DY.makeNtuple("FFApp_2jets");
  ttbar.makeNtuple("FFApp_2jets");*/
  
  return 0;
}
