#include "../src/sigScan_HSS.C"
#include "../src/map_sort_value.cxx"
#include <map>

int main(int argc, char * argv[]){
 
  int Nsteps=20;
  TString masspoint=argv[1];
  int channel=atoi(argv[2]);
  map<Float_t,Float_t> var1_min_sigs;
  map<Float_t,Float_t> var1_max_sigs;
  map<Float_t,Float_t> var2_min_sigs;
  map<Float_t,Float_t> var2_max_sigs;
  map<Float_t,Float_t> var3_min_sigs;
  map<Float_t,Float_t> var3_max_sigs;
  map<Float_t,Float_t> var4_min_sigs;
  map<Float_t,Float_t> var4_max_sigs;
  //set initial values
  Float_t fixed_cuts_min[]={0.2,0.2,15,0}, fixed_cuts_max[]={2.5,2.5,150,300}; 
  //loop over first variable
  for(int i=0;i<Nsteps;i++){
      Float_t var=0.2+0.05*i;
      fixed_cuts_min[0]=var;
      var1_min_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }
  fixed_cuts_min[0]=map_sort_value(var1_min_sigs);

  for(int i=0;i<Nsteps;i++){
      Float_t var=2.5-0.05*i;
      fixed_cuts_max[0]=var;
      var1_max_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }     
  fixed_cuts_max[0]=map_sort_value(var1_max_sigs);
  //second
  for(int i=0;i<Nsteps;i++){
      Float_t var=0.2+0.05*i;
      fixed_cuts_min[1]=var;
      var2_min_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }     
  fixed_cuts_min[1]=map_sort_value(var2_min_sigs);

  for(int i=0;i<Nsteps;i++){
      Float_t var=2.5-0.05*i;
      fixed_cuts_max[1]=var;
      var2_max_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }     
  fixed_cuts_max[1]=map_sort_value(var2_max_sigs);
  //third
  for(int i=0;i<Nsteps;i++){
      Float_t var=15+5*i;
      fixed_cuts_min[2]=var;
      var3_min_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }     
  fixed_cuts_min[2]=map_sort_value(var3_min_sigs);

  for(int i=0;i<Nsteps;i++){
      Float_t var=150-5*i;
      fixed_cuts_max[2]=var;
      var3_max_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }     
  fixed_cuts_max[2]=map_sort_value(var3_max_sigs);
  //fourth
  for(int i=0;i<Nsteps;i++){
      Float_t var=0+5*i;
      fixed_cuts_min[3]=var;
      var4_min_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }
  fixed_cuts_min[3]=map_sort_value(var4_min_sigs);

  for(int i=0;i<40;i++){
      Float_t var=300-5*i;
      fixed_cuts_max[3]=var;
      var4_max_sigs[var]=sigScan_HSS(masspoint,channel,fixed_cuts_min,fixed_cuts_max);
  }
  fixed_cuts_max[3]=map_sort_value(var4_max_sigs);
   
  //print
  ofstream outfile;
  TString channel_name="/scratchfs/atlas/zhoums/2LSSAna_output/output/SigOpt/"+masspoint;
  if(channel==1) channel_name+="_ee";
  if(channel==2) channel_name+="_mumu";
  if(channel==3) channel_name+="_emu";
  outfile.open(channel_name+".txt",ios::trunc);

  outfile<<fixed_cuts_min[0]<<" "<<fixed_cuts_max[0]<<"\n";
  outfile<<fixed_cuts_min[1]<<" "<<fixed_cuts_max[1]<<"\n";
  outfile<<fixed_cuts_min[2]<<" "<<fixed_cuts_max[2]<<"\n";
  outfile<<fixed_cuts_min[3]<<" "<<fixed_cuts_max[3]<<"\n";
}
