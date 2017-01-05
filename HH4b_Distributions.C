#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TLegend.h>
#include <vector>
#include <iostream>
#include <TString.h>

void HH4b_Distributions()
{

  gROOT->Macro("/home/tosciri/atlasstyle-00-03-05/AtlasStyle.C");
  gROOT->SetStyle("ATLAS");
  gROOT->ForceStyle();


    std::cout << "Starting" << std::endl;

    TH1F *h_number_jets_sig       = new TH1F ("hnumber_jets_sig" ,   ";Number of jets;Entries",     12,-0.5,11.5);
    TH1F *h_number_Bjets_sig      = new TH1F ("hnumberBjets_sig" ,   ";Number of b-jets;Entries",   7,-0.5,6.5);
    TH1F *h_PT_jets_sig           = new TH1F ("h_PT_jets_sig" ,      ";p_{T} jets [GeV];Entries",   20,0,350);
    TH1F *h_PT_Bjets_sig          = new TH1F ("hPTBjets_sig" ,       ";p_{T} b-jets [GeV];Entries", 20,0,350);
    TH1F *h_Eta_Bjets_sig         = new TH1F ("hEtaBjets_sig" ,      ";#eta b-jets ;Entries",       20,-4,4);
    TH1F *h_lead_inv_mass_sig     = new TH1F ("hLeadInvMass_sig" ,   ";M_{H}^{lead} [GeV];Entries", 125,0,350);
    TH1F *h_sub_inv_mass_sig      = new TH1F ("hSubInvMass_sig" ,    ";M_{H}^{sub} [GeV];Entries",  125,0,350);
    TH1F *h_lead_inv_mass_cut_sig = new TH1F ("hLeadInvMassCut_sig", ";M_{H}^{lead} [GeV];Entries", 125,0,350);
    TH1F *h_sub_inv_mass_cut_sig  = new TH1F ("hSubInvMassCut_sig" , ";M_{H}^{sub} [GeV];Entries",  125,0,350);
    TH1F *h_diHiggs_mass_sig      = new TH1F ("hdiHiggsMass_sig" ,   ";M_{HH} [GeV];Entries",       300,0,900);
    TH1F *h_diHiggs_pT_sig        = new TH1F ("hdiHiggsPt_sig" ,     ";p_{T}^{HH} [GeV];Entries",   40,0,400);


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


    TH1F *h_deltaEta1_sig         = new TH1F ("deltaEta1_sig" ,      ";#Delta#eta^{lead};Entries",  30,0,3);
    TH1F *h_deltaEta2_sig         = new TH1F ("deltaEta2_sig" ,      ";#Delta#eta^{sub};Entries",   30,0,3);
    TH1F *h_deltaPhi1_sig         = new TH1F ("deltaPhi1_sig" ,      ";#Delta#phi^{lead};Entries",  80,-4,4);
    TH1F *h_deltaPhi2_sig         = new TH1F ("deltaPhi2_sig" ,      ";#Delta#phi^{sub};Entries",   80,-4,4);
    TH1F *h_lead_Eta_sig          = new TH1F ("hLeadEta_sig" ,       ";#eta_{H}^{lead};Entries",    80,-4,4);
    TH1F *h_sub_Eta_sig           = new TH1F ("hSubEta_sig" ,        ";#eta_{H}^{sub};Entries",     80,-4,4);
    TH1F *h_lead_Phi_sig          = new TH1F ("hLeadPhi_sig" ,       ";#phi_{H}^{lead};Entries",    80,-4,4);
    TH1F *h_sub_Phi_sig           = new TH1F ("hSubPhi_sig" ,        ";#phi_{H}^{sub};Entries",     80,-4,4);
    TH1F *h_lead_E_sig            = new TH1F ("hLeadE_sig" ,         ";E_{H}^{lead}[GeV];Entries",  80,0,800);
    TH1F *h_sub_E_sig             = new TH1F ("hSubE_sig" ,          ";E_{H}^{sub}[GeV];Entries",   80,0,800);

    TH1F *h_deltaEta1         = new TH1F ("deltaEta1" ,      ";#Delta#eta^{lead};Entries",      30,0,3);
    TH1F *h_deltaEta2         = new TH1F ("deltaEta2" ,      ";#Delta#eta^{sub};Entries",       30,0,3);
    TH1F *h_deltaPhi1         = new TH1F ("deltaPhi1" ,      ";#Delta#phi^{lead};Entries",      80,-4,4);
    TH1F *h_deltaPhi2         = new TH1F ("deltaPhi2" ,      ";#Delta#phi^{sub};Entries",       80,-4,4);
    TH1F *h_lead_Eta          = new TH1F ("hLeadEta" ,       ";#eta_{H}^{lead};Entries",        80,-4,4);
    TH1F *h_sub_Eta           = new TH1F ("hSubEta" ,        ";#eta_{H}^{sub};Entries",         80,-4,4);
    TH1F *h_lead_Phi          = new TH1F ("hLeadPhi" ,       ";#phi_{H}^{lead};Entries",        80,-4,4);
    TH1F *h_sub_Phi           = new TH1F ("hSubPhi" ,        ";#phi_{H}^{sub};Entries",         80,-4,4);
    TH1F *h_lead_E            = new TH1F ("hLeadE" ,         ";E_{H}^{lead}[GeV];Entries",      80,0,800);
    TH1F *h_sub_E             = new TH1F ("hSubE" ,          ";E_{H}^{sub}[GeV];Entries",       80,0,800);


    std::cout << "Here 1" << std::endl;

    float sig_weight = 1.49E-02;
    std::vector<float> bkg_weight;
    bkg_weight.resize(4);
    bkg_weight[0] = 1.76E+03;
    bkg_weight[1] = 5.82E+06;
    bkg_weight[2] = 3.51E+05;
    bkg_weight[3] = 3.5E+03;
    
    std::cout << "Here 2" << std::endl;

    std::vector<std::string> bkg_file; 
    bkg_file.resize(4);
    bkg_file[0] = "HH4bSelection_out/background_4j.root";
    bkg_file[1] = "HH4bSelection_out/background_4b.root";
    bkg_file[2] = "HH4bSelection_out/background_2b2j.root";
    bkg_file[3] = "HH4bSelection_out/background_tt_bbjjjj.root";

    std::cout << "Here 3" << std::endl;

  for(int i=0; i<4; i++){//weight and add bkg processes together 
     TFile *f = new TFile(bkg_file.at(i).c_str());
     TH1F *h1 = (TH1F*)f->Get("hnumber_jets");
     h1->Scale(bkg_weight.at(i)); 
     h_number_jets->Add(h1);  

     TH1F *h2 = (TH1F*)f->Get("hnumberBjets");
     h2->Scale(bkg_weight.at(i));
     h_number_Bjets->Add(h2);

     TH1F *h3 = (TH1F*)f->Get("h_PT_jets");
     h3->Scale(bkg_weight.at(i));
     h_PT_jets->Add(h3);

     TH1F *h4 = (TH1F*)f->Get("hPTBjets");
     h4->Scale(bkg_weight.at(i));
     h_PT_Bjets->Add(h4);

     TH1F *h5 = (TH1F*)f->Get("hEtaBjets");
     h5->Scale(bkg_weight.at(i));
     h_Eta_Bjets->Add(h5);

     TH1F *h6 = (TH1F*)f->Get("hLeadInvMass");
     h6->Scale(bkg_weight.at(i));
     h_lead_inv_mass->Add(h6);

     TH1F *h7 = (TH1F*)f->Get("hSubInvMass");
     h7->Scale(bkg_weight.at(i));
     h_sub_inv_mass->Add(h7);

    /* TH1F *h8 = (TH1F*)f->Get("hLeadInvMassCut");
     h8->Scale(bkg_weight.at(i));
     hLeadInvMassCut->Add(h8);

     TH1F *h9 = (TH1F*)f->Get("hSubInvMassCut");
     h9->Scale(bkg_weight.at(i));
     hSubInvMassCut->Add(h9);
*/
     TH1F *h10 = (TH1F*)f->Get("hdiHiggsMass");
     h10->Scale(bkg_weight.at(i));
     h_diHiggs_mass->Add(h10);

     TH1F *h11 = (TH1F*)f->Get("hdiHiggsPt");
     h11->Scale(bkg_weight.at(i));
     h_diHiggs_pT->Add(h11);
    
     TH1F *h12 = (TH1F*)f->Get("deltaEta1");
     h12->Scale(bkg_weight.at(i));
     h_deltaEta1->Add(h12);

     TH1F *h13 = (TH1F*)f->Get("deltaEta2");
     h13->Scale(bkg_weight.at(i));
     h_deltaEta2->Add(h13);

     TH1F *h14 = (TH1F*)f->Get("deltaPhi1");
     h14->Scale(bkg_weight.at(i));
     h_deltaPhi1->Add(h14);

     TH1F *h15 = (TH1F*)f->Get("deltaPhi2");
     h15->Scale(bkg_weight.at(i));
     h_deltaPhi2->Add(h15);

     TH1F *h16 = (TH1F*)f->Get("hLeadPhi");
     h16->Scale(bkg_weight.at(i));
     h_lead_Phi->Add(h16);

     TH1F *h17 = (TH1F*)f->Get("hSubPhi");
     h17->Scale(bkg_weight.at(i));
     h_sub_Phi->Add(h17);

     TH1F *h18 = (TH1F*)f->Get("hLeadE");
     h18->Scale(bkg_weight.at(i));
     h_lead_E->Add(h18);

     TH1F *h19 = (TH1F*)f->Get("hSubE");
     h19->Scale(bkg_weight.at(i));
     h_sub_E->Add(h18);

  }//end loop over background files


     TFile *f_sig = new TFile("HH4bSelection_out/signal.root","READ");
     
     new TCanvas;    
     h_number_jets_sig = (TH1F*)f_sig->Get("hnumber_jets");
     h_number_jets_sig->Scale(1/(h_number_jets_sig->Integral()));
     h_number_jets_sig->SetLineColor(kRed);
     h_number_jets->Scale(1./h_number_jets->Integral());
     h_number_jets->SetLineColor(kBlue);
     h_number_jets->SetLineStyle(2);

     h_number_jets->Draw();
     h_number_jets_sig->Draw("same");

     TLegend* leg_1 = new TLegend(.7, .7, .9, .9);
     leg_1->AddEntry(h_number_jets_sig,"Signal", "lf");
     leg_1->AddEntry(h_number_jets, "Background", "lf");
     leg_1->Draw();

     new TCanvas;
     h_number_Bjets_sig = (TH1F*)f_sig->Get("hnumberBjets");
     h_number_Bjets_sig->Scale(1/(h_number_Bjets_sig->Integral()));
     h_number_Bjets_sig->SetLineColor(kRed);
     h_number_Bjets->Scale(1./h_number_Bjets->Integral());
     h_number_Bjets->SetLineColor(kBlue);
     h_number_Bjets->SetLineStyle(2);

     h_number_Bjets->Draw();
     h_number_Bjets_sig->Draw("same");

     TLegend* leg_2 = new TLegend(.7, .7, .9, .9);
     leg_2->AddEntry(h_number_Bjets_sig,"Signal", "lf");
     leg_2->AddEntry(h_number_Bjets, "Background", "lf");
     leg_2->Draw();


     TCanvas *c3 = new TCanvas("c3");
     c3->SetLogy();
     h_PT_jets_sig = (TH1F*)f_sig->Get("h_PT_jets");
     h_PT_jets_sig->Scale(1/(h_PT_jets_sig->Integral()));
     h_PT_jets_sig->SetLineColor(kRed);
     h_PT_jets->Scale(1./h_PT_jets->Integral());
     h_PT_jets->SetLineColor(kBlue);
     h_PT_jets->SetLineStyle(2);

     h_PT_jets->Draw();
     h_PT_jets_sig->Draw("same");

     TLegend* leg_3 = new TLegend(.7, .7, .9, .9);
     leg_3->AddEntry(h_PT_jets_sig,"Signal", "lf");
     leg_3->AddEntry(h_PT_jets, "Background", "lf");
     leg_3->Draw();

     TCanvas *c4 = new TCanvas("c4");
     c4->SetLogy();
     h_PT_Bjets_sig = (TH1F*)f_sig->Get("hPTBjets");
     h_PT_Bjets_sig->Scale(1/(h_PT_Bjets_sig->Integral()));
     h_PT_Bjets_sig->SetLineColor(kRed);
     h_PT_Bjets->Scale(1./h_PT_Bjets->Integral());
     h_PT_Bjets->SetLineColor(kBlue);
     h_PT_Bjets->SetLineStyle(2);

     h_PT_Bjets->Draw();
     h_PT_Bjets_sig->Draw("same");

     TLegend* leg_4 = new TLegend(.7, .7, .9, .9);
     leg_4->AddEntry(h_PT_Bjets_sig,"Signal", "lf");
     leg_4->AddEntry(h_PT_Bjets, "Background", "lf");
     leg_4->Draw();

     new TCanvas;
     h_Eta_Bjets_sig = (TH1F*)f_sig->Get("hEtaBjets");
     h_Eta_Bjets_sig->Scale(1/(h_Eta_Bjets_sig->Integral()));
     h_Eta_Bjets_sig->SetLineColor(kRed);
     h_Eta_Bjets->Scale(1./h_Eta_Bjets->Integral());
     h_Eta_Bjets->SetLineColor(kBlue);
     h_Eta_Bjets->SetLineStyle(2);

     h_Eta_Bjets_sig->Draw();
     h_Eta_Bjets->Draw("same");

     TLegend* leg_5 = new TLegend(.7, .7, .9, .9);
     leg_5->AddEntry(h_Eta_Bjets_sig,"Signal", "lf");
     leg_5->AddEntry(h_Eta_Bjets, "Background", "lf");
     leg_5->Draw();


     new TCanvas;
     h_lead_inv_mass_sig = (TH1F*)f_sig->Get("hLeadInvMass");
     h_lead_inv_mass_sig->Scale(1/(h_lead_inv_mass_sig->Integral()));
     h_lead_inv_mass_sig->SetLineColor(kRed);
     h_lead_inv_mass->Scale(1./h_lead_inv_mass->Integral());
     h_lead_inv_mass->SetLineColor(kBlue);
     h_lead_inv_mass->SetLineStyle(2);

     h_lead_inv_mass_sig->Draw();
     h_lead_inv_mass->Draw("same");

     TLegend* leg_6 = new TLegend(.7, .7, .9, .9);
     leg_6->AddEntry(h_lead_inv_mass_sig,"Signal", "lf");
     leg_6->AddEntry(h_lead_inv_mass, "Background", "lf");
     leg_6->Draw();

    new TCanvas;
     h_sub_inv_mass_sig = (TH1F*)f_sig->Get("hSubInvMass");
     h_sub_inv_mass_sig->Scale(1/(h_sub_inv_mass_sig->Integral()));
     h_sub_inv_mass_sig->SetLineColor(kRed);
     h_sub_inv_mass->Scale(1./h_sub_inv_mass->Integral());
     h_sub_inv_mass->SetLineColor(kBlue);
     h_sub_inv_mass->SetLineStyle(2);

     h_sub_inv_mass_sig->Draw();
     h_sub_inv_mass->Draw("same");

     TLegend* leg_7 = new TLegend(.7, .7, .9, .9);
     leg_7->AddEntry(h_sub_inv_mass_sig,"Signal", "lf");
     leg_7->AddEntry(h_sub_inv_mass, "Background", "lf");
     leg_7->Draw();

     TCanvas *c8 = new TCanvas("c8");
     c8->SetLogy();
     h_diHiggs_mass_sig = (TH1F*)f_sig->Get("hdiHiggsMass");
     h_diHiggs_mass_sig->Scale(1./(h_diHiggs_mass_sig->Integral()));
     h_diHiggs_mass_sig->SetLineColor(kRed);
     h_diHiggs_mass->Scale(1./h_diHiggs_mass->Integral());
     h_diHiggs_mass->SetLineColor(kBlue);
     h_diHiggs_mass->SetLineStyle(2);

     h_diHiggs_mass_sig->Draw();
     h_diHiggs_mass->Draw("same");

     TLegend* leg_10 = new TLegend(.7, .7, .9, .9);
     leg_10->AddEntry(h_diHiggs_mass_sig,"Signal", "lf");
     leg_10->AddEntry(h_diHiggs_mass, "Background", "lf");
     leg_10->Draw();

     TCanvas *c11 = new TCanvas("c11");
     c11->SetLogy();
     h_diHiggs_pT_sig = (TH1F*)f_sig->Get("hdiHiggsPt");
     h_diHiggs_pT_sig->Scale(1/(h_diHiggs_pT_sig->Integral()));
     h_diHiggs_pT_sig->SetLineColor(kRed);
     h_diHiggs_pT->Scale(1./h_diHiggs_pT->Integral());
     h_diHiggs_pT->SetLineColor(kBlue);
     h_diHiggs_pT->SetLineStyle(2);

     h_diHiggs_pT->Draw();
     h_diHiggs_pT_sig->Draw("same");

     TLegend* leg_11 = new TLegend(.7, .7, .9, .9);
     leg_11->AddEntry(h_diHiggs_pT_sig,"Signal", "lf");
     leg_11->AddEntry(h_diHiggs_pT, "Background", "lf");
     leg_11->Draw();

     TCanvas *c12 = new TCanvas("c12");
     h_deltaEta1_sig = (TH1F*)f_sig->Get("deltaEta1");
     h_deltaEta1_sig->Scale(1/(h_deltaEta1_sig->Integral()));
     h_deltaEta1_sig->SetLineColor(kRed);
     h_deltaEta1->Scale(1./h_deltaEta1->Integral());
     h_deltaEta1->SetLineColor(kBlue);
     h_deltaEta1->SetLineStyle(2);

     h_deltaEta1_sig->Draw();
     h_deltaEta1->Draw("same");

     TLegend* leg_12 = new TLegend(.7, .7, .9, .9);
     leg_12->AddEntry(h_deltaEta1_sig,"Signal", "lf");
     leg_12->AddEntry(h_deltaEta1, "Background", "lf");
     leg_12->Draw();

     TCanvas *c13 = new TCanvas("c13");
     h_deltaEta2_sig = (TH1F*)f_sig->Get("deltaEta2");
     h_deltaEta2_sig->Scale(1/(h_deltaEta2_sig->Integral()));
     h_deltaEta2_sig->SetLineColor(kRed);
     h_deltaEta2->Scale(1./h_deltaEta2->Integral());
     h_deltaEta2->SetLineColor(kBlue);
     h_deltaEta2->SetLineStyle(2);

     h_deltaEta2_sig->Draw();
     h_deltaEta2->Draw("same");

     TLegend* leg_13 = new TLegend(.7, .7, .9, .9);
     leg_13->AddEntry(h_deltaEta2_sig,"Signal", "lf");
     leg_13->AddEntry(h_deltaEta2, "Background", "lf");
     leg_13->Draw();

     TCanvas *c14 = new TCanvas("c14");
     h_deltaPhi1_sig = (TH1F*)f_sig->Get("deltaPhi1");
     h_deltaPhi1_sig->Scale(1/(h_deltaPhi1_sig->Integral()));
     h_deltaPhi1_sig->SetLineColor(kRed);
     h_deltaPhi1->Scale(1./h_deltaPhi1->Integral());
     h_deltaPhi1->SetLineColor(kBlue);
     h_deltaPhi1->SetLineStyle(2);

     h_deltaPhi1->Draw();
     h_deltaPhi1_sig->Draw("same");

     TLegend* leg_14 = new TLegend(.7, .7, .9, .9);
     leg_14->AddEntry(h_deltaPhi1_sig,"Signal", "lf");
     leg_14->AddEntry(h_deltaPhi1, "Background", "lf");
     leg_14->Draw();

     TCanvas *c15 = new TCanvas("c15");
     h_deltaPhi2_sig = (TH1F*)f_sig->Get("deltaPhi2");
     h_deltaPhi2_sig->Scale(1/(h_deltaPhi2_sig->Integral()));
     h_deltaPhi2_sig->SetLineColor(kRed);
     h_deltaPhi2->Scale(1./h_deltaPhi2->Integral());
     h_deltaPhi2->SetLineColor(kBlue);
     h_deltaPhi2->SetLineStyle(2);

     h_deltaPhi2->Draw();
     h_deltaPhi2_sig->Draw("same");

     TLegend* leg_15 = new TLegend(.7, .7, .9, .9);
     leg_15->AddEntry(h_deltaPhi2_sig,"Signal", "lf");
     leg_15->AddEntry(h_deltaPhi2, "Background", "lf");
     leg_15->Draw();


     TCanvas *c16 = new TCanvas("c16");
     h_lead_Phi_sig = (TH1F*)f_sig->Get("hLeadPhi");
     h_lead_Phi_sig->Scale(1/(h_lead_Phi_sig->Integral()));
     h_lead_Phi_sig->SetLineColor(kRed);
     h_lead_Phi->Scale(1./h_lead_Phi->Integral());
     h_lead_Phi->SetLineColor(kBlue);
     h_lead_Phi->SetLineStyle(2);

     h_lead_Phi->Draw();
     h_lead_Phi_sig->Draw("same");

     TLegend* leg_16 = new TLegend(.7, .7, .9, .9);
     leg_16->AddEntry(h_lead_Phi_sig,"Signal", "lf");
     leg_16->AddEntry(h_lead_Phi, "Background", "lf");
     leg_16->Draw();

     TCanvas *c17 = new TCanvas("c17");
     h_sub_Phi_sig = (TH1F*)f_sig->Get("hSubPhi");
     h_sub_Phi_sig->Scale(1/(h_sub_Phi_sig->Integral()));
     h_sub_Phi_sig->SetLineColor(kRed);
     h_sub_Phi->Scale(1./h_sub_Phi->Integral());
     h_sub_Phi->SetLineColor(kBlue);
     h_sub_Phi->SetLineStyle(2);

     h_sub_Phi->Draw();
     h_sub_Phi_sig->Draw("same");

     TLegend* leg_17 = new TLegend(.7, .7, .9, .9);
     leg_17->AddEntry(h_sub_Phi_sig,"Signal", "lf");
     leg_17->AddEntry(h_sub_Phi, "Background", "lf");
     leg_17->Draw();

     TCanvas *c18 = new TCanvas("c18");
     h_lead_E_sig = (TH1F*)f_sig->Get("hLeadE");
     h_lead_E_sig->Scale(1/(h_lead_E_sig->Integral()));
     h_lead_E_sig->SetLineColor(kRed);
     h_lead_E->Scale(1./h_lead_E->Integral());
     h_lead_E->SetLineColor(kBlue);
     h_lead_E->SetLineStyle(2);

     h_lead_E->Draw();
     h_lead_E_sig->Draw("same");

     TLegend* leg_18 = new TLegend(.7, .7, .9, .9);
     leg_18->AddEntry(h_lead_E_sig,"Signal", "lf");
     leg_18->AddEntry(h_lead_E, "Background", "lf");
     leg_18->Draw();

     TCanvas *c19 = new TCanvas("c19");
     h_sub_E_sig = (TH1F*)f_sig->Get("hSubE");
     h_sub_E_sig->Scale(1/(h_sub_E_sig->Integral()));
     h_sub_E_sig->SetLineColor(kRed);
     h_sub_E->Scale(1./h_sub_E->Integral());
     h_sub_E->SetLineColor(kBlue);
     h_sub_E->SetLineStyle(2);

     h_sub_E->Draw();
     h_sub_E_sig->Draw("same");

     TLegend* leg_19 = new TLegend(.7, .7, .9, .9);
     leg_19->AddEntry(h_sub_E_sig,"Signal", "lf");
     leg_19->AddEntry(h_sub_E, "Background", "lf");
     leg_19->Draw();
 /* TLatex* head = new TLatex(.885, .85, "3.6 < #eta < 4.4");

  head->SetTextColor(kBlack);
  head->SetNDC();
  head->SetTextSize(1.5/30.);
  head->SetTextAlign(32);
  head->Draw();
*/
   /*  TLegend* leg_res = new TLegend(.7, .6, .9, .8);
    // gStyle->SetLegendTextSize(0.04);
    //leg_res->SetHeader("p_{t} resolution");
     leg_res->AddEntry(h_number_jets_sig,"Signal", "lf");
     leg_res->AddEntry(h_number_jets, "Background", "lf");
     leg_res->Draw();
*/
  //c->SaveAs("Response_plots/Resolution_eta_3.6_4.4_new.pdf");

}

