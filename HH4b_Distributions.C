
void HH4b_Distributions()
{
/*
  gROOT->Macro("/home/tosciri/atlasstyle-00-03-05/AtlasStyle.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();
*/

    TH1F *h_number_jets_sig       = new TH1F ("hnumber_jets" ,   ";Number of jets;Entries",     12,-0.5,11.5);
    TH1F *h_number_Bjets_sig      = new TH1F ("hnumberBjets" ,   ";Number of b-jets;Entries",   7,-0.5,6.5);
    TH1F *h_PT_jets_sig           = new TH1F ("h_PT_jets" ,      ";p_{T} jets [GeV];Entries",   20,0,350);
    TH1F *h_PT_Bjets_sig          = new TH1F ("hPTBjets" ,       ";p_{T} b-jets [GeV];Entries", 20,0,350);
    TH1F *h_Eta_Bjets_sig         = new TH1F ("hEtaBjets" ,      ";#eta b-jets ;Entries",       20,-4,4);
    TH1F *h_lead_inv_mass_sig     = new TH1F ("hLeadInvMass" ,   ";M_{H}^{lead} [GeV];Entries", 125,0,350);
    TH1F *h_sub_inv_mass_sig      = new TH1F ("hSubInvMass" ,    ";M_{H}^{sub} [GeV];Entries",  125,0,350);
    TH1F *h_lead_inv_mass_cut_sig = new TH1F ("hLeadInvMassCut", ";M_{H}^{lead} [GeV];Entries", 125,0,350);
    TH1F *h_sub_inv_mass_cut_sig  = new TH1F ("hSubInvMassCut" , ";M_{H}^{sub} [GeV];Entries",  125,0,350);
    TH1F *h_diHiggs_mass_sig      = new TH1F ("hdiHiggsMass" ,   ";M_{HH} [GeV];Entries",       300,0,900);
    TH1F *h_diHiggs_pT_sig        = new TH1F ("hdiHiggsPt" ,     ";p_{T}^{HH} [GeV];Entries",   40,0,400);


    TH1F *h_number_jets       = new TH1F ("hnumber_jets" ,   ";Number of jets;Entries",     12,-0.5,11.5);
    TH1F *h_number_Bjets      = new TH1F ("hnumberBjets" ,   ";Number of b-jets;Entries",   7,-0.5,6.5);
    TH1F *h_PT_jets           = new TH1F ("h_PT_jets" ,      ";p_{T} jets [GeV];Entries",   20,0,350);
    TH1F *h_PT_Bjets          = new TH1F ("hPTBjets" ,       ";p_{T} b-jets [GeV];Entries", 20,0,350);
    TH1F *h_Eta_Bjets         = new TH1F ("hEtaBjets" ,      ";#eta b-jets ;Entries",       20,-4,4);
    TH1F *h_lead_inv_mass     = new TH1F ("hLeadInvMass" ,   ";M_{H}^{lead} [GeV];Entries", 125,0,350);
    TH1F *h_sub_inv_mass      = new TH1F ("hSubInvMass" ,    ";M_{H}^{sub} [GeV];Entries",  125,0,350);
    TH1F *h_lead_inv_mass_cut = new TH1F ("hLeadInvMassCut", ";M_{H}^{lead} [GeV];Entries", 125,0,350);
    TH1F *h_sub_inv_mass_cut  = new TH1F ("hSubInvMassCut" , ";M_{H}^{sub} [GeV];Entries",  125,0,350);
    TH1F *h_diHiggs_mass      = new TH1F ("hdiHiggsMass" ,   ";M_{HH} [GeV];Entries",       300,0,900);
    TH1F *h_diHiggs_pT        = new TH1F ("hdiHiggsPt" ,     ";p_{T}^{HH} [GeV];Entries",   40,0,400);

    float sig_weight = 1.49E-02;

    std::vector<TString>  bkg_file = {"HH4bSelection_out/background_4j.root","HH4bSelection_out/background_4b.root","HH4bSelection_out/background_2b2j.root","HH4bSelection_out/background_tt_bbjjjj.root"};
    std::vector<float>  bkg_weight = {"1.76E+03","5.82E+06","3.51E+05","3.5E+03"};


  for(int i=0; i<4; i++){
     TFile *f = new TFile(bkg_file[i]);
     TH1D *h = (TH1F*)f.Get("hnumber_jets");
     h->Scale(bkg_weight[i]); 
     h_number_jets->Add(h);      
  }//end loop over background files


     TFile *f_sig = new TFile("signal.root");
     h_number_jets_sig->(TH1F*)f_sig.Get("hnumber_jets");
     h_number_jets_sig->Scale(1/(h_number_jets_sig->Integral()));

     TCanvas *c = new TCanvas("c"); 
     h_number_jets_sig->SetLineColor(kRed+1);

     h_number_jets->SetLineColor(kBlue+1);
     h_number_jets->SetLineStyle(2);

     h_number_jets_sig->Draw();
     h_number_jets->Draw("same");
  //h_B->Draw("E1 same");
  
 /* TLatex* head = new TLatex(.885, .85, "3.6 < #eta < 4.4");

  head->SetTextColor(kBlack);
  head->SetNDC();
  head->SetTextSize(1.5/30.);
  head->SetTextAlign(32);
  head->Draw();
*/
     TLegend* leg_res = new TLegend(.7, .6, .9, .8);
     gStyle->SetLegendTextSize(0.04);
    //leg_res->SetHeader("p_{t} resolution");
     leg_res->AddEntry(h_number_jets_sig,"Signal", "lf");
     leg_res->AddEntry(h_number_jets, "Background", "lf");
     leg_res->Draw();

  //c->SaveAs("Response_plots/Resolution_eta_3.6_4.4_new.pdf");

}

