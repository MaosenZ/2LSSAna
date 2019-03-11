#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"

void CutsSA_scan(){
  SetAtlasStyle();
  TFile *input_file=new TFile("output/dataMC_3jets/TMVA.nonres.root");
  TH1 *hist=(TH1*)input_file->Get("Method_Cuts/CutsSA/MVA_CutsSA_effBvsS");
 
  Int_t NbinsX=hist->GetNbinsX();
  Double_t effS[100], effB[100];
  Double_t sig[100];
  for(Int_t i=1;i<=NbinsX;i++){
      effS[i-1]=i*hist->GetBinWidth(i);
      effB[i-1]=hist->GetBinContent(i);
      sig[i-1]=effS[i-1]/sqrt(effB[i-1]);
      cout<<effS[i-1]<<": "<<sig[i-1]<<endl;
  }
    
  TGraph *c_gr=new TGraph(NbinsX,effS,sig);
  c_gr->GetXaxis()->SetTitle("effS");
  c_gr->GetYaxis()->SetTitle("effS/#sqrt{effB}");
  c_gr->Draw("");
}
