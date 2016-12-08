void analysis(string pattern_signal = "/Users/ceciliamac/AMVA4NP/selection/MG5_pp_hh_13TeV_10M_py8_Forced_4900000_to_5000000.root", string pattern_background = "/Users/ceciliamac/AMVA4NP/selection/pp_4b_13TeV_10M_py8_1100000_to_1200000.root") {
  
    //string pattern_background ="genereic_to_*_.root"
    
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


}
