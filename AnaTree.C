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
    
    TH1F *hDeltaR = new TH1F ("hDeltaR" , ";DeltaR;Events", 100,0,1);
    TH1F *h_number_jets = new TH1F ("hnumber_jets" , ";# of jets;Events", 12,0,12);
    TH1F *h_number_Bjets = new TH1F ("hnumberBjets" , ";# B-jets;Events", 7,0,7);
    TH1F *h_PT_jets = new TH1F ("h_PT_jets" , ";P_{t} jets [GeV];Events", 20,0,350);
    TH1F *h_PT_Bjets = new TH1F ("hPTBjets" , ";P_{t} Bjets [GeV];Events", 20,0,350);
    TH1F *h_Eta_Bjets = new TH1F ("hEtaBjets" , ";Eta ;Events", 20,-4,4);
    TH1F *h_inv_mass = new TH1F ("hInvMass" , ";M_{H} [GeV];Events", 20,0,350);
    TH1F *h_inv_mass_cut = new TH1F ("hInvMassCut" , ";M_{H} [GeV];Events", 50,0,200);
    
    if (fChain == 0) return;
    
    Long64_t nentries = fChain->GetEntriesFast();
    
    Long64_t nbytes = 0, nb = 0;
    
    vector<TLorentzVector> vBjet; //defining TLorentz vector for storing Bjets
    
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
        
        h_number_jets->Fill(Jet_);//fill the histogram with the total number of jets
        
        int nBjets = 0;
        
        for (int i=0; i<Jet_; i++){
            if(Jet_BTag[i] == 1) nBjets++;
        }
        
        h_number_Bjets->Fill(nBjets);//fill the histogram with the total number of B-jets
        
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
                //cout<<"Bjet number  "<< k <<"with Pt=  "<< vBjet.at(k).Pt()<<endl;
                k++;
            }
            
            h_PT_jets->Fill(Jet_PT[i]);
            
        }
        
        
        for(int j=0; j<4; j++){ //selecting the first 4 Bjets
            h_PT_Bjets->Fill(vBjet.at(j).Pt());
            h_Eta_Bjets->Fill(vBjet.at(j).Eta());
        }
        
        int total_charge = 0;
        double invMass1, invMass2;
        int bestFirst, bestSecond;
        
        TLorentzVector vjetTemp1, vjetTemp2, couple1, couple2;
        double diffNew, diffOld = 1e9;
        double M_Higgs = 125.;
        
        
        
        std::cout<< "****************" << endl;
        
        
        
        int first=0; //take the first Bjet and make all the possible couples
        for(int second=1;second<4; second++){
            vjetTemp1 = vBjet.at(first) + vBjet.at(second);
            invMass1 = vjetTemp1.M();
            cout<< "Invariant Mass 1 =  "<< invMass1 << endl;
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
        
  
        cout<< "Best Second=  "<< bestSecond << endl;
        couple1 = vBjet.at(first) + vBjet.at(bestSecond);
        cout<< " Best Invariant Mass 1 =  "<< couple1.M() << endl;
        
        for(int left=0; left<4; left++){
            if(left != first && left!= bestSecond){
                couple2 += vBjet.at(left);
            }
        }
        cout<< "Best Invariant Mass 2 =  "<< couple2.M() << endl;
        
        h_inv_mass->Fill(couple1.M());
        h_inv_mass->Fill(couple2.M());
        
        if(abs(couple1.M()-125) < 40){
            h_inv_mass_cut->Fill(couple1.M());
        }
        if(abs(couple2.M()-125) < 40){
            h_inv_mass_cut->Fill(couple2.M());
        }
        
        
        
    }
    new TCanvas;
    h_number_jets->Draw();
    new TCanvas;
    h_number_Bjets->Draw();
    new TCanvas;
    h_PT_jets->Draw();
    new TCanvas;
    h_PT_Bjets->Draw();
    new TCanvas;
    h_Eta_Bjets->Draw();
    new TCanvas;
    h_inv_mass->Draw();
    new TCanvas;
    h_inv_mass_cut->Draw();
    
}


//double DeltaR=0;
//DeltaR=sqrt((Jet_DeltaEta[i]*Jet_DeltaEta[i])+(Jet_DeltaPhi[i]*Jet_DeltaPhi[i]));
//hDeltaR->Fill(DeltaR);




