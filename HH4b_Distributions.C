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
    
  }//end loop over background files


     TFile *f_sig = new TFile("HH4bSelection_out/signal.root","READ");
     
     new TCanvas;    
     h_number_jets_sig = (TH1F*)f_sig->Get("hnumber_jets");
     h_number_jets_sig->Scale(1/(h_number_jets_sig->Integral()));
     h_number_jets_sig->SetLineColor(kRed+1);
     h_number_jets->Scale(1./h_number_jets->Integral());
     h_number_jets->SetLineColor(kBlue+1);
     h_number_jets->SetLineStyle(2);

     h_number_jets->Draw();
     h_number_jets_sig->Draw("same");

     TLegend* leg_res_1 = new TLegend(.7, .6, .9, .8);
     leg_res_1->AddEntry(h_number_jets_sig,"Signal", "lf");
     leg_res_1->AddEntry(h_number_jets, "Background", "lf");
     leg_res_1->Draw();

     new TCanvas;
     h_number_Bjets_sig = (TH1F*)f_sig->Get("hnumberBjets");
     h_number_Bjets_sig->Scale(1/(h_number_Bjets_sig->Integral()));
     h_number_Bjets_sig->SetLineColor(kRed+1);
     h_number_Bjets->Scale(1./h_number_Bjets->Integral());
     h_number_Bjets->SetLineColor(kBlue+1);
     h_number_Bjets->SetLineStyle(2);

     h_number_Bjets->Draw();
     h_number_Bjets_sig->Draw("same");

     TLegend* leg_res_2 = new TLegend(.7, .6, .9, .8);
     leg_res_2->AddEntry(h_number_Bjets_sig,"Signal", "lf");
     leg_res_2->AddEntry(h_number_Bjets, "Background", "lf");
     leg_res_2->Draw();


     new TCanvas;
     h_PT_jets_sig = (TH1F*)f_sig->Get("h_PT_jets");
     h_PT_jets_sig->Scale(1/(h_PT_jets_sig->Integral()));
     h_PT_jets_sig->SetLineColor(kRed+1);
     h_PT_jets->Scale(1./h_PT_jets->Integral());
     h_PT_jets->SetLineColor(kBlue+1);
     h_PT_jets->SetLineStyle(2);

     h_PT_jets->Draw();
     h_PT_jets_sig->Draw("same");

     TLegend* leg_res_3 = new TLegend(.7, .6, .9, .8);
     leg_res_3->AddEntry(h_PT_jets_sig,"Signal", "lf");
     leg_res_3->AddEntry(h_PT_jets, "Background", "lf");
     leg_res_3->Draw();

    new TCanvas;
     h_PT_Bjets_sig = (TH1F*)f_sig->Get("hPTBjets");
     h_PT_Bjets_sig->Scale(1/(h_PT_Bjets_sig->Integral()));
     h_PT_Bjets_sig->SetLineColor(kRed+1);
     h_PT_Bjets->Scale(1./h_PT_Bjets->Integral());
     h_PT_Bjets->SetLineColor(kBlue+1);
     h_PT_Bjets->SetLineStyle(2);

     h_PT_Bjets->Draw();
     h_PT_Bjets_sig->Draw("same");

     TLegend* leg_res_4 = new TLegend(.7, .6, .9, .8);
     leg_res_4->AddEntry(h_PT_Bjets_sig,"Signal", "lf");
     leg_res_4->AddEntry(h_PT_Bjets, "Background", "lf");
     leg_res_4->Draw();

     new TCanvas;
     h_Eta_Bjets_sig = (TH1F*)f_sig->Get("hEtaBjets");
     h_Eta_Bjets_sig->Scale(1/(h_Eta_Bjets_sig->Integral()));
     h_Eta_Bjets_sig->SetLineColor(kRed+1);
     h_Eta_Bjets->Scale(1./h_Eta_Bjets->Integral());
     h_Eta_Bjets->SetLineColor(kBlue+1);
     h_Eta_Bjets->SetLineStyle(2);

     h_Eta_Bjets_sig->Draw();
     h_Eta_Bjets->Draw("same");

     TLegend* leg_res_5 = new TLegend(.7, .6, .9, .8);
     leg_res_5->AddEntry(h_Eta_Bjets_sig,"Signal", "lf");
     leg_res_5->AddEntry(h_Eta_Bjets, "Background", "lf");
     leg_res_5->Draw();


     new TCanvas;
     h_lead_inv_mass_sig = (TH1F*)f_sig->Get("hLeadInvMass");
     h_lead_inv_mass_sig->Scale(1/(h_lead_inv_mass_sig->Integral()));
     h_lead_inv_mass_sig->SetLineColor(kRed+1);
     h_lead_inv_mass->Scale(1./h_lead_inv_mass->Integral());
     h_lead_inv_mass->SetLineColor(kBlue+1);
     h_lead_inv_mass->SetLineStyle(2);

     h_lead_inv_mass_sig->Draw();
     h_lead_inv_mass->Draw("same");

     TLegend* leg_res_6 = new TLegend(.7, .6, .9, .8);
     leg_res_6->AddEntry(h_lead_inv_mass_sig,"Signal", "lf");
     leg_res_6->AddEntry(h_lead_inv_mass, "Background", "lf");
     leg_res_6->Draw();

    new TCanvas;
     h_sub_inv_mass_sig = (TH1F*)f_sig->Get("hSubInvMass");
     h_sub_inv_mass_sig->Scale(1/(h_sub_inv_mass_sig->Integral()));
     h_sub_inv_mass_sig->SetLineColor(kRed+1);
     h_sub_inv_mass->Scale(1./h_sub_inv_mass->Integral());
     h_sub_inv_mass->SetLineColor(kBlue+1);
     h_sub_inv_mass->SetLineStyle(2);

     h_sub_inv_mass_sig->Draw();
     h_sub_inv_mass->Draw("same");

     TLegend* leg_res_7 = new TLegend(.7, .6, .9, .8);
     leg_res_7->AddEntry(h_sub_inv_mass_sig,"Signal", "lf");
     leg_res_7->AddEntry(h_sub_inv_mass, "Background", "lf");
     leg_res_7->Draw();

    new TCanvas;
     h_diHiggs_mass_sig = (TH1F*)f_sig->Get("hdiHiggsMass");
     h_diHiggs_mass_sig->Scale(1/(h_diHiggs_mass_sig->Integral()));
     h_diHiggs_mass_sig->SetLineColor(kRed+1);
     h_diHiggs_mass->Scale(1./h_diHiggs_mass->Integral());
     h_diHiggs_mass->SetLineColor(kBlue+1);
     h_diHiggs_mass->SetLineStyle(2);

     h_diHiggs_mass_sig->Draw();
     h_diHiggs_mass->Draw("same");

     TLegend* leg_res_10 = new TLegend(.7, .6, .9, .8);
     leg_res_10->AddEntry(h_diHiggs_mass_sig,"Signal", "lf");
     leg_res_10->AddEntry(h_diHiggs_mass, "Background", "lf");
     leg_res_10->Draw();

   new TCanvas;
     h_diHiggs_pT_sig = (TH1F*)f_sig->Get("hdiHiggsPt");
     h_diHiggs_pT_sig->Scale(1/(h_diHiggs_pT_sig->Integral()));
     h_diHiggs_pT_sig->SetLineColor(kRed+1);
     h_diHiggs_pT->Scale(1./h_diHiggs_pT->Integral());
     h_diHiggs_pT->SetLineColor(kBlue+1);
     h_diHiggs_pT->SetLineStyle(2);

     h_diHiggs_pT->Draw();
     h_diHiggs_pT_sig->Draw("same");

     TLegend* leg_res_11 = new TLegend(.7, .6, .9, .8);
     leg_res_11->AddEntry(h_diHiggs_pT_sig,"Signal", "lf");
     leg_res_11->AddEntry(h_diHiggs_pT, "Background", "lf");
     leg_res_11->Draw();


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

