/*void analysis(string pattern = "/data/amva4np/samples/signal/non_res_diHiggs/bbbb/Delphes_output/MG5_pp_hh_bbbb_13TeV_10M_py8_Forced/MG5_pp_hh_13TeV_10M_py8_Forced_4900000_to_5000000.root") {
*/

void analysis(string option = "signal") {
 
  string pattern;

  if(option == "signal")
      pattern = "/data/amva4np/samples/signal/non_res_diHiggs/bbbb/Delphes_output/MG5_pp_hh_bbbb_13TeV_10M_py8_Forced/MG5_pp_hh_13TeV_10M_py8_Forced_*_to_*.root";
  if(option == "bkg_4j")
      pattern = "/data/amva4np/samples/background/QCD/4j/MG5_pp_jjjj_13TeV_10M/Delphes_output/pp_4j_13TeV_10M_py8/pp_4j_13TeV_10M_py8_*_to_*.root";
  if(option == "bkg_4b")
      pattern = "/data/amva4np/samples/background/QCD/4b/MG5_pp_bbbb_13TeV_10M/Delphes_output/pp_4b_13TeV_10M_py8/pp_4b_13TeV_10M_py8_*_to_*.root";
  if(option == "bkg_2b2j")
      pattern = "/data/amva4np/samples/background/QCD/bbjj/MG5_pp_bbjj_NF4_13TeV_10M/Delphes_output/MG5_pp_bbjj_NF4_13TeV_10M_py8/MG5_pp_bbjj_NF4_13TeV_10M_py8_*_to_*.root";
  if(option == "bkg_tt_bbjjjj")
      pattern = "/data/amva4np/samples/background/ttbar/ttbar_fully_hadronic/Delphes_output/pp_tt_bbjjjj_13TeV_10M_py8/pp_tt_bbjjjj_13TeV_10M_py8_*_to_*.root";
    //string pattern_background ="genereic_to_*_.root"


  
  // Chain
  TChain *ch;
  ch = new TChain("Delphes");
  ch->Add(pattern.c_str());
  cout << "Number of files: " << ch->GetNtrees() << endl; 
 
  // Instantiate and initialise class
  AnaTree selectionTree(ch);

  // Run event selection 
  cout << "Selection is now running." << endl;
  selectionTree.Loop();
 
/*
  // Chain for the signal
  TChain *csignal;
  csignal = new TChain("Delphes");
  csignal->Add(pattern_signal.c_str());
  cout << "Number of signal files: " << csignal->GetNtrees() << endl;

  // Chain for the background
  TChain *cbckg;
  cbckg = new TChain("Delphes");
  cbckg->Add(pattern_background.c_str());
  cout << "Number of background files: " << cbckg->GetNtrees() << endl;  

  // Instantiate and initialise classes for signal and background
  AnaTree signalTree(csignal);
  AnaTree bckgTree(cbckg);

  // Run event selection on signal events
  cout << "Selection is now running on signal." << endl;
  signalTree.Loop();
  
  // Run event selection on bcknd events
  cout << "Selection is now running on background." << endl;
  bckgTree.Loop();
  
  // Plot results
  // If your class contains an histogram called pT:
  //signalTree.pT->Draw();
  //bckgTree.pT->SetLineColor(kRed);
  //bckgTree.pT->Draw("same");

*/
}
