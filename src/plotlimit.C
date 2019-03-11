#include<map>
#include "../../atlasstyle-00-03-05/AtlasStyle.C"
#include "../../atlasstyle-00-03-05/AtlasUtils.C"

int plotlimit(){

  SetAtlasStyle();

  int point = 0;

  //double ratio = 2.27e-03*0.2152*2;
  double ratio = 1.0;

  const int nmass = 4;
  double  mass[nmass]      = {260, 300, 400, 500};
//ee

 /* double P2S[nmass]      = { 169.54 *ratio,120.57*ratio, 47.98*ratio,21.70*ratio}; 
  double P1S[nmass]      = { 130.83 *ratio,93.509*ratio, 35.93*ratio,15.10*ratio};  
  double N1S[nmass]      = { 73.898 *ratio,52.968*ratio, 19.47*ratio,7.538*ratio};  
  double N2S[nmass]      = { 55.045 *ratio,39.454*ratio, 14.50*ratio,5.615*ratio}; 
  double Median[nmass]   = { 102.55 *ratio,73.509*ratio, 27.02*ratio,10.46*ratio}; 
  double Observed[nmass] = { 102.53 *ratio,73.492*ratio, 27.03*ratio,10.46*ratio}; */
//mumu

 /* double P2S[nmass]      = {  91.84*ratio, 98.67*ratio,  32.56*ratio, 15.04*ratio}; 
  double P1S[nmass]      = {  74.13*ratio, 84.61*ratio,  25.99*ratio, 11.38*ratio};  
  double N1S[nmass]      = {  43.89*ratio, 52.51*ratio,  15.31*ratio, 6.380*ratio};  
  double N2S[nmass]      = {  32.69*ratio, 39.11*ratio,  11.40*ratio, 4.752*ratio}; 
  double Median[nmass]   = {  60.91*ratio, 72.88*ratio,  21.25*ratio, 8.854*ratio}; 
  double Observed[nmass] = {  60.95*ratio, 73.04*ratio,  21.26*ratio, 8.852*ratio};*/
//emu
  double P2S[nmass]      = {  36.01*ratio,  32.75*ratio,12.44*ratio,6.40*ratio}; 
  double P1S[nmass]      = {  27.30*ratio,  25.14*ratio, 9.21*ratio,4.58*ratio};  
  double N1S[nmass]      = {  14.57*ratio,  13.43*ratio, 4.77*ratio,2.32*ratio};  
  double N2S[nmass]      = {  10.85*ratio,  10.01*ratio, 3.56*ratio,1.73*ratio}; 
  double Median[nmass]   = {  20.22*ratio,18.64*ratio,  6.63*ratio, 3.22*ratio}; 
  double Observed[nmass] = {  20.22*ratio,18.64*ratio,  6.63*ratio, 3.22*ratio};
//2LSS combined 

/*  double P2S[nmass]      = {59.01*ratio,48.99*ratio,16.14*ratio,7.08*ratio}; 
  double P1S[nmass]      = {47.20*ratio,39.17*ratio,12.33*ratio,5.25*ratio}; 
  double N1S[nmass]      = {26.57*ratio,22.06*ratio,6.599*ratio,2.71*ratio};  
  double N2S[nmass]      = {19.79*ratio,16.43*ratio,4.915*ratio,2.02*ratio}; 
  double Median[nmass]   = {36.88*ratio,30.62*ratio,9.158*ratio,3.76*ratio}; 
  double Observed[nmass] = {36.89*ratio,30.60*ratio,9.158*ratio,3.76*ratio};*/
//2LSS 11111111111

  /*double P2S[nmass]      = {  54.3722*ratio,51.9077*ratio,  17.2126*ratio, 7.06297*ratio}; 
  double P1S[nmass]      = {  42.8802*ratio,40.3319*ratio,  13.3401*ratio, 5.12206*ratio};  
  double N1S[nmass]      = {  23.5721*ratio,21.0617*ratio,  7.18093*ratio, 2.64248*ratio};  
  double N2S[nmass]      = {  17.5584*ratio,15.6884*ratio,  5.34892*ratio, 1.96833*ratio}; 
  double Median[nmass]   = {  32.7138*ratio,29.2298*ratio,  9.96582*ratio, 3.66728*ratio}; 
  double Observed[nmass] = {  32.7043*ratio,29.2277*ratio,  9.96551*ratio, 3.66783*ratio};*/

  cout<<52.4217*ratio <<endl;
  cout<<35.6533*ratio <<endl;
  cout<<17.5188*ratio <<endl;
  cout<<13.0493*ratio <<endl;
  cout<<24.3128*ratio <<endl;
  cout<<47.696 *ratio <<endl;
  cout<<"************"<<endl;
  cout<<44.0818*ratio <<endl;
  cout<<30.1268*ratio <<endl;
  cout<<14.8491*ratio <<endl;
  cout<<11.0608*ratio <<endl;
  cout<<20.6079*ratio <<endl;
  cout<<40.3283*ratio <<endl;
  cout<<"************"<<endl;
  cout<<31.7669*ratio <<endl;
  cout<<21.8675*ratio <<endl;
  cout<<10.8185*ratio <<endl;
  cout<<8.05843*ratio <<endl;
  cout<<15.0141*ratio <<endl;
  cout<<29.2886*ratio <<endl;
  cout<<"************"<<endl;
  cout<<26.5864*ratio <<endl;
  cout<<18.4326*ratio <<endl;
  cout<<9.16121*ratio <<endl;
  cout<<6.82398*ratio <<endl;
  cout<<12.7141*ratio <<endl;
  cout<<24.722 *ratio <<endl;
  /////////////////////////////////////////////////////////////////////////////////////
  // c'est parti
  /////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////////////
  // plotting
  /////////////////////////////////////////////////////////////////////////////////////

  // convert PS NS
  double band_p2s[nmass]; double band_p1s[nmass];
  double band_n1s[nmass]; double band_n2s[nmass];
  double aux_xerr[nmass];
  for( int ipts=0; ipts<nmass; ++ipts ){
    band_p2s[ipts] = fabs(P2S[ipts] - Median[ipts]);
    band_p1s[ipts] = fabs(P1S[ipts] - Median[ipts]);
    band_n1s[ipts] = fabs(N1S[ipts] - Median[ipts]);
    band_n2s[ipts] = fabs(N2S[ipts] - Median[ipts]);
	aux_xerr[ipts] = 0;
  }
  // check on points to be drawn
  cout << "checking ++ + central - --" << endl;
  for( int idraw=0; idraw<nmass; idraw++){
    cout << "@ x=" << mass[idraw] << " ++ " << band_p2s[idraw] << " + " << band_p1s[idraw]
    << " " << Median[idraw]
    << " - " << band_n1s[idraw] << " -- " << band_n2s[idraw] << endl;
  }
 
  // some fast codes for plotting
  const double lX1 = 5.48994974874371766e-01;
  const double lY1 = 5.20979020979020935e-01;
  const double lX2 = 9.04522613065326664e-01;
  const double lY2 = 8.12937062937062915e-01;
  //TLegend * Leg = new TLegend( lX1, lY1, lX2, lY2 );
  TLegend * Leg = new TLegend( 0.65 , 0.62 , 0.9 , 0.92 );
  Leg->SetTextSize(0.045);

  // comb
  TGraph *likelihd_limit_exp = new TGraph( nmass, mass, Median );
  likelihd_limit_exp->SetLineColor(kBlack);
  likelihd_limit_exp->SetLineWidth(2);
  likelihd_limit_exp->SetLineStyle(2);
  likelihd_limit_exp->GetHistogram()->GetYaxis()->SetRangeUser(0 , 20.);
  // Obs
  TGraph *likelihd_limit_obs = new TGraph( nmass, mass, Observed );
  likelihd_limit_obs->SetLineColor(kBlack);
  likelihd_limit_obs->SetLineWidth(2);
  //likelihd_limit_obs->SetLineStyle(2);
  likelihd_limit_obs->SetMarkerStyle(20);
  likelihd_limit_obs->SetMarkerColor(kBlack);
  likelihd_limit_obs->GetHistogram()->GetYaxis()->SetRangeUser(0 , 20.);

  // following only comb bands
  TGraphAsymmErrors *likelihd_limit_1sigma = new TGraphAsymmErrors( nmass, mass, Median, aux_xerr, aux_xerr, band_n1s, band_p1s );
  // !!! limit +1 sigma, exclusion goes down!!!
  likelihd_limit_1sigma->SetFillColor(kGreen);
  likelihd_limit_1sigma->SetLineColor(kGreen);
  likelihd_limit_1sigma->GetHistogram()->GetYaxis()->SetRangeUser(0 , 20.);

  TGraphAsymmErrors *likelihd_limit_2sigma = new TGraphAsymmErrors( nmass, mass, Median, aux_xerr, aux_xerr, band_n2s, band_p2s );
  likelihd_limit_2sigma->SetFillColor(kYellow);
  likelihd_limit_2sigma->SetLineColor(kYellow);
  likelihd_limit_2sigma->GetHistogram()->GetYaxis()->SetRangeUser(0 , 20.);

  Leg->AddEntry( likelihd_limit_obs, "Observed", "LP");
  Leg->AddEntry( likelihd_limit_exp, "Expected", "L");
  Leg->AddEntry( likelihd_limit_1sigma , "#pm 1#sigma expected" , "F");
  Leg->AddEntry( likelihd_limit_2sigma , "#pm 2#sigma expected" , "F");

  //TMultiGraph *likelihd_limit = new TMultiGraph("upper limits"," ; m_{x} [GeV]; #sigma(gg#rightarrow X) #times BR(X #rightarrow hh #rightarrow WW^{*}#gamma#gamma) [pb]");
  TMultiGraph *likelihd_limit = new TMultiGraph("upper limits",";m_{x} [GeV];#sigma(gg#rightarrow X) #times BR(X #rightarrow hh) [pb]");
  likelihd_limit->Add(likelihd_limit_2sigma,"E3");
  likelihd_limit->Add(likelihd_limit_1sigma,"E3");
  likelihd_limit->Add(likelihd_limit_exp, "L");
  //likelihd_limit->Add(likelihd_limit_obs, "LP");

  TString cName = "HhhLimitSetting";
  TCanvas *c1 = new TCanvas( cName , cName, 800 , 600 );
//  TCanvas *c1 = new TCanvas( cName , cName, 1000 , 1000 );
  gPad->Update();
  gPad->SetLogy();
  //gPad->SetGrid();

  likelihd_limit->SetMaximum(1000); // 
  likelihd_limit->SetMinimum(1);
  likelihd_limit->Draw("AC"); // AC
  Leg->SetFillColor(0);
  Leg->SetLineColor(0);
  Leg->Draw("same");

  ATLAS_LABEL(0.22, 0.85 );//  myText( 0.35, 0.85, 1, "Internal");
  myText( 0.35, 0.85, 1, "Internal");
  myText( 0.22, 0.75 , 1, "#sqrt{s} = 13 TeV,");
  myText( 0.42, 0.75 , 1, "36.5 fb^{-1}");
  // going public
/*
  myText( 0.32,0.85, 1, "#sqrt{s} = 13 TeV,");
  myText( 0.50,0.85, 1, "3.2 fb^{-1}"); 
*/
  c1->SaveAs("limit_2LSS.pdf");
  //c1->SaveAs("limit1-pre_mumu.eps");
  //c1->SaveAs("limit1-pre_mumu.png");

  return 0;

}
