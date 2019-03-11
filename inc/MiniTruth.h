//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Nov 12 09:00:27 2017 by ROOT version 5.34/18
// from TTree tree/tree
// found on file: /publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/4W2LSS/m500_Pythia8/data-myOutput/m500_Pythia8.root
//////////////////////////////////////////////////////////

#ifndef MiniTruth_h
#define MiniTruth_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <iostream>
// Header file for the classes stored in the TTree if any.
#include <vector>
#include <cmath>
// Fixed size dimensions of array or collections stored in the TTree if any.
using namespace std;
class MiniTruth {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain
   TString         masspoint;
   TString         variation;
   // Declaration of leaf types
   Float_t         m_ll_ljj;
   Float_t         m_l2j;
   Float_t         m_l3j;
   Float_t         m_l1jj;
   Float_t         deltaR_12;
   Float_t         deltaR_23;
   Float_t         m_lll;
   Float_t         m_ll;
   Float_t         m_all;
   Float_t         m_l3jj;
   Float_t         m_12;
   Float_t         mindR_l3j;
   Float_t         mindR_l1j;
   Float_t         mindR_l2j;
   Float_t         weight;
   vector<float>   *weights;
   Float_t         sumw0;
   Float_t         sumwmax;
   Int_t           numOfjet;
   Float_t         channel;

   // List of branches
   TBranch        *b_m_ll_ljj;   //!
   TBranch        *b_m_l2j;   //!
   TBranch        *b_m_l3j;   //!
   TBranch        *b_m_l1jj;   //!
   TBranch        *b_deltaR_12;   //!
   TBranch        *b_deltaR_23;   //!
   TBranch        *b_m_lll;   //!
   TBranch        *b_m_ll;   //!
   TBranch        *b_m_all;   //!
   TBranch        *b_m_l3jj;   //!
   TBranch        *b_m_12;   //!
   TBranch        *b_mindR_l3j;   //!
   TBranch        *b_mindR_l1j;   //!
   TBranch        *b_mindR_l2j;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_weights;   //!
   TBranch        *b_sumw0;   //!
   TBranch        *b_sumwmax;   //!
   TBranch        *b_numOfjet;   //!
   TBranch        *b_channel;   //!

   MiniTruth(TString input, TString invariation);
   virtual ~MiniTruth();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     getSumwgts(Float_t evts[6],TString config);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef MiniTruth_cxx
MiniTruth::MiniTruth(TString input, TString invariation) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   TChain *chain=new TChain("tree");
   TString inputPath="/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/4W2LSS/";
   inputPath += input;
   inputPath += "_";
   inputPath += invariation;
   inputPath += "/data-myOutput/";
   inputPath += input+"_"+invariation+".root";
   chain->Add(inputPath);
   //chain->Add("/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/4W2LSS/m300_Pythia8/data-myOutput/m300_Pythia8.root");
//         f = new TFile("/publicfs/atlas/atlasnew/higgs/hgg/zhoums/4W/v27.01/4W2LSS/m500_Pythia8/data-myOutput/m500_Pythia8.root");
   masspoint=input;
   if(input=="m260") masspoint="mH260";
   if(input=="m300") masspoint="mH300";
   if(input=="m400") masspoint="mH400";
   if(input=="m500") masspoint="mH500";
   variation=invariation;
   Init(chain);
}

MiniTruth::~MiniTruth()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t MiniTruth::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t MiniTruth::LoadTree(Long64_t entry)
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

void MiniTruth::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   weights = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("m_ll_ljj", &m_ll_ljj, &b_m_ll_ljj);
   fChain->SetBranchAddress("m_l2j", &m_l2j, &b_m_l2j);
   fChain->SetBranchAddress("m_l3j", &m_l3j, &b_m_l3j);
   fChain->SetBranchAddress("m_l1jj", &m_l1jj, &b_m_l1jj);
   fChain->SetBranchAddress("deltaR_12", &deltaR_12, &b_deltaR_12);
   fChain->SetBranchAddress("deltaR_23", &deltaR_23, &b_deltaR_23);
   fChain->SetBranchAddress("m_lll", &m_lll, &b_m_lll);
   fChain->SetBranchAddress("m_ll", &m_ll, &b_m_ll);
   fChain->SetBranchAddress("m_all", &m_all, &b_m_all);
   fChain->SetBranchAddress("m_l3jj", &m_l3jj, &b_m_l3jj);
   fChain->SetBranchAddress("m_12", &m_12, &b_m_12);
   fChain->SetBranchAddress("mindR_l3j", &mindR_l3j, &b_mindR_l3j);
   fChain->SetBranchAddress("mindR_l1j", &mindR_l1j, &b_mindR_l1j);
   fChain->SetBranchAddress("mindR_l2j", &mindR_l2j, &b_mindR_l2j);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("weights", &weights, &b_weights);
   fChain->SetBranchAddress("sumw0", &sumw0, &b_sumw0);
   fChain->SetBranchAddress("sumwmax", &sumwmax, &b_sumwmax);
   fChain->SetBranchAddress("numOfjet", &numOfjet, &b_numOfjet);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   Notify();
}

Bool_t MiniTruth::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void MiniTruth::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t MiniTruth::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef MiniTruth_cxx
