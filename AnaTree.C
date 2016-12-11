#define AnaTree_cxx
#include "AnaTree.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

#include <iostream>

void AnaTree::Loop()
{
    //   In a ROOT session, you can do:
    //      root> .L AnaTree.C
    //      root> AnaTree t
    //      root> t.GetEntry(12); // Fill t data members with entry number 12
    //      root> t.Show();       // Show values of entry 12
    //      root> t.Show(16);     // Read and show values of entry 16
    //      root> t.Loop();       // Loop on all entries
    //
    
    //     This is the loop skeleton where:
    //    jentry is the global entry number in the chain
    //    ientry is the entry number in the current Tree
    //  Note that the argument to GetEntry must be:
    //    jentry for TChain::GetEntry
    //    ientry for TTree::GetEntry and TBranch::GetEntry
    //
    //       To read only selected branches, Insert statements like:
    // METHOD1:
    //    fChain->SetBranchStatus("*",0);  // disable all branches
    //    fChain->SetBranchStatus("branchname",1);  // activate branchname
    // METHOD2: replace line
    //    fChain->GetEntry(jentry);       //read all branches
    //by  b_branchname->GetEntry(ientry); //read only this branch


    double weight = -9999;
    TString outFileName;
    TString fileName = (((TChain*)fChain)->GetFile())->GetName();
    if (fileName.Contains("pp_hh")) {
      weight = 1.45175E-02;
      outFileName = "signal.root";
    } else if(fileName.Contains("pp_4j")){
      weight = 1.44718E+07; 
      outFileName = "background_4j.root";
    } else if (fileName.Contains("pp_4b")) {
      weight = 1.74712E+03;
      outFileName = "background_4b.root";
    } else {
      std::cout << "ERROR: Can't determine weight from file name. Exiting now!" << std::endl;
      exit(0);
    }

    std::cout << "Using weight = " << weight << std::endl;

    TH1F *hDeltaR             = new TH1F ("hDeltaR" ,        ";DeltaR;Events",            100,0,1);
    TH1F *h_number_jets       = new TH1F ("hnumber_jets" ,   ";# of jets;Events",         12,0,12);
    TH1F *h_number_Bjets      = new TH1F ("hnumberBjets" ,   ";# B-jets;Events",          7,0,7);
    TH1F *h_PT_jets           = new TH1F ("h_PT_jets" ,      ";P_{t} jets [GeV];Events",  20,0,350);
    TH1F *h_PT_Bjets          = new TH1F ("hPTBjets" ,       ";P_{t} Bjets [GeV];Events", 20,0,350);
    TH1F *h_Eta_Bjets         = new TH1F ("hEtaBjets" ,      ";Eta ;Events",              20,-4,4);
    TH1F *h_lead_inv_mass     = new TH1F ("hLeadInvMass" ,   ";M_{Hlead} [GeV];Events",   125,0,350);
    TH1F *h_sub_inv_mass      = new TH1F ("hSubInvMass" ,    ";M_{Hsub} [GeV];Events",    125,0,350);
    TH1F *h_lead_inv_mass_cut = new TH1F ("hLeadInvMassCut", ";M_{Hlead} [GeV];Events",   125,0,350);
    TH1F *h_sub_inv_mass_cut  = new TH1F ("hSubInvMassCut" , ";M_{Hsub} [GeV];Events",    125,0,350);
    
    if (fChain == 0) return;
    
    Long64_t nentries = fChain->GetEntriesFast();
    
    Long64_t nbytes = 0, nb = 0;
    
    vector<TLorentzVector> vBjet; //defining TLorentz vector for storing Bjets
   
    //nentries = 100;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        
        h_number_jets->Fill(Jet_,weight);//fill the histogram with the total number of jets
        
        int nBjets = 0;
        
        for (int i=0; i<Jet_; i++){
            if(Jet_BTag[i] == 1) nBjets++;
        }
        
        h_number_Bjets->Fill(nBjets,weight);//fill the histogram with the total number of B-jets
        
        vBjet.clear();
        vBjet.resize(nBjets);
        int k=0;
        
        if(Jet_ < 4) continue; //selecting at least 4 jets (Jet_ is the length of the array containing jets)
        //cout<<"Number of selected jets=   "<<Jet_<<endl;
        //cout<<"Number of B jets=   "<<nBjets<<endl;
        if(nBjets < 4) continue; //selecting at least 4 b-tagged jets
        //if(nBjets < 4 || nBjets >4) continue;
        
        bool keepEvent;
        keepEvent = true;
        
        for (int j=0; j<Jet_; j++){
            if ((Jet_PT[j] < 40) || Jet_Eta[j] > 2.5 || Jet_Eta[j] < -2.5) {
                keepEvent = false;  //cut on PT jets REQUIREMENT:PT>=40 GeV //cut on Eta jets REQUIREMENT |eta|>2.5
            }
        }
        
        if (keepEvent == false) continue;
        
        for(int i=0; i<Jet_; i++){
            if(Jet_BTag[i] == 1){
                TLorentzVector temp1;
                temp1.SetPtEtaPhiM(Jet_PT[i],Jet_Eta[i],Jet_Phi[i],Jet_Mass[i]);
                vBjet.at(k) = temp1;
                //cout<<"Bjet number "<< k <<" with Pt = "<< vBjet.at(k).Pt()<<endl;
                k++;
            }
            
            h_PT_jets->Fill(Jet_PT[i],weight);
            
        }
        
        
        for(int j=0; j<4; j++){ //selecting the first 4 Bjets
            h_PT_Bjets->Fill(vBjet.at(j).Pt(),weight);
            h_Eta_Bjets->Fill(vBjet.at(j).Eta(),weight);
        }
        
        double invMass1, invMass2;
        int bestFirst, bestSecond=0;
        
        TLorentzVector vjetTemp1, vjetTemp2, couple1, couple2;
        double diffNew, diffOld = 1e9;
        double M_Higgs = 125.;
        
        
        
        std::cout<< "****************" << endl;
        
        
        
        int first=0; //take the first Bjet and make all the possible couples
        for(int second=1;second<4; second++){
            vjetTemp1 = vBjet.at(first) + vBjet.at(second);
            invMass1 = vjetTemp1.M();
            cout<< "Invariant Mass 1 =  "<< invMass1 << endl;
            vjetTemp2.SetPtEtaPhiM(0.,0.,0.,0.); // resetting
            for(int left=1; left<4; left++){
                if(left!= second){
                    vjetTemp2 += vBjet.at(left);
                }
            }
            invMass2 = vjetTemp2.M();
            cout<< "Invariant Mass 2 =  "<< invMass2 << endl;
            
            diffNew = abs(invMass1 - invMass2);
            
            if(diffNew < diffOld){
                diffOld = diffNew;
                bestSecond = second;
            }
            
        }
        
  
        cout<< "  Best Second = "<< bestSecond << endl;
        couple1 = vBjet.at(first) + vBjet.at(bestSecond);
        cout<< "  Best Invariant Mass 1 =  "<< couple1.M() << endl;
        
        for(int left=0; left<4; left++){
            if(left != first && left!= bestSecond){
                couple2 += vBjet.at(left);
            }
        }
        cout<< "  Best Invariant Mass 2 =  "<< couple2.M() << endl;
        TLorentzVector temp_new;
        if(couple2.M() > couple1.M()){
            temp_new=couple1;
            couple1=couple2;
            couple2=temp_new;
        }

        cout<< "    Best Invariant Mass 1 =  "<< couple1.M() << endl;
        cout<< "    Best Invariant Mass 2 =  "<< couple2.M() << endl;

        h_lead_inv_mass->Fill(couple1.M(),weight);
        h_sub_inv_mass->Fill(couple2.M(),weight);
        
        if(abs(couple1.M()-125) < 40){
            h_lead_inv_mass_cut->Fill(couple1.M(),weight);
        }
        if(abs(couple2.M()-125) < 40){
            h_sub_inv_mass_cut->Fill(couple2.M(),weight);
        }
                
    } // end loop over entries

    TFile* outFile = new TFile(outFileName, "RECREATE");
    h_number_jets->Write();
    h_number_Bjets->Write();
    h_PT_jets->Write();
    h_PT_Bjets->Write();
    h_Eta_Bjets->Write();
    h_lead_inv_mass->Write();
    h_sub_inv_mass->Write();
    h_lead_inv_mass_cut->Write();
    h_sub_inv_mass_cut->Write();

    //new TCanvas;
    TCanvas *c = new TCanvas("c");
    h_number_jets->Draw();
    c->SaveAs("Plots/Number_Jets.pdf");
    new TCanvas;
    h_number_Bjets->Draw();
    new TCanvas;
    h_PT_jets->Draw();
    new TCanvas;
    h_PT_Bjets->Draw();
    new TCanvas;
    h_Eta_Bjets->Draw();
    new TCanvas;
    h_lead_inv_mass->Draw();
    new TCanvas;
    h_sub_inv_mass->Draw();
    new TCanvas;
    h_lead_inv_mass_cut->Draw();
    new TCanvas;
    h_sub_inv_mass_cut->Draw();


     //c->SaveAs("Plots/Number_Jets.pdf");
}


//double DeltaR=0;
//DeltaR=sqrt((Jet_DeltaEta[i]*Jet_DeltaEta[i])+(Jet_DeltaPhi[i]*Jet_DeltaPhi[i]));
//hDeltaR->Fill(DeltaR);




