//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Oct 27 14:41:53 2016 by ROOT version 5.34/34
// from TTree Tree/vars
// found on file: pt_20/miniNtuple_FFApp_datacombined.root
//////////////////////////////////////////////////////////

#ifndef ApplyCuts_h
#define ApplyCuts_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TCut.h>
// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;
class ApplyCuts {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   TCut            cutsApplied;
   Int_t           raw_number; //!absolute number of events after cuts applied
   Double_t        weighted_number; //!weighted number of events after cuts applied
   Double_t        weighted_number_antiemu;
   Double_t        weighted_number_eantimu;
   Double_t        error_statistics; //!statistic error of output numbers
   // Declaration of leaf types
   Float_t         m_ll;
   Float_t         m_jj;
   Float_t         MET;
   Float_t         pt_leadinglepton;
   Float_t         pt_sublepton;
   Float_t         pt_j1;
   Float_t         pt_j2;
   Float_t         m_jj_w;
   Float_t         m_l1jj;
   Float_t         m_all;
   Float_t         pt_sum;
   Float_t         mindR_l1j;
   Float_t         m_l1j;
   Float_t         mindR_l2j;
   Float_t         RMS;
   Float_t         m_l2j;
   Float_t         Mt;
   Double_t        weight;
   Int_t           channel;
   Int_t           category;
   Int_t           numOfjet;

   // List of branches
   TBranch        *b_m_ll;   //!
   TBranch        *b_m_jj;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_pt_leadinglepton;   //!
   TBranch        *b_pt_sublepton;   //!
   TBranch        *b_pt_j1;   //!
   TBranch        *b_pt_j2;   //!
   TBranch        *b_m_jj_w;   //!
   TBranch        *b_m_l1jj;   //!
   TBranch        *b_m_all;   //!
   TBranch        *b_pt_sum;   //!
   TBranch        *b_mindR_l1j;   //!
   TBranch        *b_m_l1j;   //!
   TBranch        *b_mindR_l2j;   //!
   TBranch        *b_RMS;   //!
   TBranch        *b_m_l2j;   //!
   TBranch        *b_Mt;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_category;   //!
   TBranch        *b_numOfjet;   //!

   ApplyCuts(TString input, TCut cuts);
   virtual ~ApplyCuts();
   virtual Int_t    Cut(Int_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#define ApplyCuts_cxx
ApplyCuts::ApplyCuts(TString input, TCut cuts) : fChain(0), raw_number(0), weighted_number(0), error_statistics(0),
 weighted_number_antiemu(0),weighted_number_eantimu(0)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   TString inputFile="output/dataMC_3jets/miniNtuple_";
   inputFile +=input;
   inputFile +=".root";
   TFile *f=new TFile(inputFile);
   TTree *tree=(TTree*)f->Get("Tree");
   cutsApplied=cuts;
   Init(tree);
}

ApplyCuts::~ApplyCuts()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t ApplyCuts::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t ApplyCuts::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void ApplyCuts::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("m_ll", &m_ll, &b_m_ll);
   fChain->SetBranchAddress("m_jj", &m_jj, &b_m_jj);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("pt_leadinglepton", &pt_leadinglepton, &b_pt_leadinglepton);
   fChain->SetBranchAddress("pt_sublepton", &pt_sublepton, &b_pt_sublepton);
   fChain->SetBranchAddress("pt_j1", &pt_j1, &b_pt_j1);
   fChain->SetBranchAddress("pt_j2", &pt_j2, &b_pt_j2);
   fChain->SetBranchAddress("m_jj_w", &m_jj_w, &b_m_jj_w);
   fChain->SetBranchAddress("m_l1jj", &m_l1jj, &b_m_l1jj);
   fChain->SetBranchAddress("m_all", &m_all, &b_m_all);
   fChain->SetBranchAddress("pt_sum", &pt_sum, &b_pt_sum);
   fChain->SetBranchAddress("mindR_l1j", &mindR_l1j, &b_mindR_l1j);
   fChain->SetBranchAddress("m_l1j", &m_l1j, &b_m_l1j);
   fChain->SetBranchAddress("mindR_l2j", &mindR_l2j, &b_mindR_l2j);
   fChain->SetBranchAddress("RMS", &RMS, &b_RMS);
   fChain->SetBranchAddress("m_l2j", &m_l2j, &b_m_l2j);
   fChain->SetBranchAddress("Mt", &Mt, &b_Mt);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("category", &category, &b_category);
   fChain->SetBranchAddress("numOfjet", &numOfjet, &b_numOfjet);
   Notify();
}

Bool_t ApplyCuts::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void ApplyCuts::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t ApplyCuts::Cut(Int_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   if(fChain->Draw("m_ll",cutsApplied,"goff", 1,entry))
      return 1;
   else 
      return -1;
}
void ApplyCuts::Loop()
{
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntries();
  Double_t err2_statistics=0;
  vector<Int_t>passed;
  for(Int_t jentry=0; jentry<nentries;jentry++) passed.push_back(Cut(jentry));
  for(Int_t jentry=0; jentry<nentries;jentry++) {
      fChain->GetEntry(jentry);
      if(passed[jentry]==1){
         raw_number++;
         weighted_number+=weight;
         if(category==22) weighted_number_antiemu+=weight;
         if(category==23) weighted_number_eantimu+=weight;
         err2_statistics+=weight*weight;
      }
  }
  error_statistics=sqrt(err2_statistics);
}
