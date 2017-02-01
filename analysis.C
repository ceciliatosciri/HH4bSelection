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
 
}
