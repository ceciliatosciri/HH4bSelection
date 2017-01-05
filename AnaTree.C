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

    bool _verbose = false;

    double weight = -9999;
    TString outFileName;
    TString fileName = (((TChain*)fChain)->GetFile())->GetName();
    if (fileName.Contains("pp_hh")) {
      weight = 1.45175E-02;
      outFileName = "signal.root";
      std::cout << "Running selection on SIGNAL." << std::endl;
    } else if(fileName.Contains("pp_jjjj")){
      weight = 1.44718E+07; 
      outFileName = "background_4j.root";
      std::cout << "Running selection on BACKGROUND 4j." << std::endl;
    } else if (fileName.Contains("pp_bbbb")) {
      weight = 1.74712E+03;
      outFileName = "background_4b.root";
      std::cout << "Running selection on BACKGROUND 4b." << std::endl;
    } else if (fileName.Contains("pp_bbjj")) {
      weight = 4.25359E+05;
      outFileName = "background_2b2j.root";
      std::cout << "Running selection on BACKGROUND 2b2j." << std::endl;
    } else if (fileName.Contains("pp_tt_bbjjjj")) {
      weight = 2.04390E+02;
      outFileName = "background_tt_bbjjjj.root";
      std::cout << "Running selection on BACKGROUND tt_bbjjjj." << std::endl;
    }
    else {
      std::cout << "ERROR: Can't determine weight from file name. Exiting now!" << std::endl;
      exit(0);
    }

    std::cout << "WARNING! Overwriting weight. Weight will now be 1." << std::endl;
    weight = 1.;

    std::cout << "Using weight = " << weight << std::endl;

    TH1F *hDeltaR             = new TH1F ("hDeltaR" ,        ";DeltaR;Events",              100,0,1);
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
    TH1F *h_diHiggs_mass_cut  = new TH1F ("hdiHiggsMassCut" ,";M_{HH} [GeV];Entries",       300,0,900);
    TH1F *h_diHiggs_pT_cut    = new TH1F ("hdiHiggsPtCut" ,  ";p_{T}^{HH} [GeV];Entries",   40,0,400);
    TH1F *h_deltaEta1         = new TH1F ("deltaEta1" ,      ";#Delta#eta      ;Entries",   30,0,3);
    TH1F *h_deltaEta2         = new TH1F ("deltaEta2" ,      ";#Delta#eta      ;Entries",   30,0,3);
    TH1F *h_deltaPhi1         = new TH1F ("deltaPhi1" ,      ";#Delta#phi      ;Entries",   80,-4,4);
    TH1F *h_deltaPhi2         = new TH1F ("deltaPhi2" ,      ";#Delta#phi      ;Entries",   80,-4,4);
    TH1F *h_lead_Eta          = new TH1F ("hLeadEta" ,       ";#eta            ;Entries",   80,-4,4);
    TH1F *h_sub_Eta           = new TH1F ("hSubEta" ,        ";#eta            ;Entries",   80,-4,4);
    TH1F *h_lead_Phi          = new TH1F ("hLeadPhi" ,       ";#phi            ;Entries",   80,-4,4);
    TH1F *h_sub_Phi           = new TH1F ("hSubPhi" ,        ";#phi            ;Entries",   80,-4,4);
    TH1F *h_lead_E            = new TH1F ("hLeadE" ,         ";E [GeV]         ;Entries",   80,0,800);
    TH1F *h_sub_E             = new TH1F ("hSubE" ,          ";E [GeV]         ;Entries",   80,0,800);



    if (fChain == 0) return;
    
    Long64_t nentries = fChain->GetEntriesFast();
    
    Long64_t nbytes = 0, nb = 0;
    
    vector<TLorentzVector> vBjet; //defining TLorentz vector for storing Bjets
   
    //nentries = 100005;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        Long64_t ientry = LoadTree(jentry);
        if (ientry < 0) break;
        nb = fChain->GetEntry(jentry);   nbytes += nb;
        // if (Cut(ientry) < 0) continue;
       
        if (jentry % 10000 == 0) std::cout << "On entry " << jentry << std::endl;
 
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
        
        
        for(int i=0; i<Jet_; i++){
	    TLorentzVector temp1;
            if(Jet_BTag[i] == 1 && Jet_PT[i] > 40 && Jet_Eta[i] < 2.5 && Jet_Eta[i] > -2.5){
                //cut on PT jets REQUIREMENT:PT>=40 GeV //cut on Eta jets REQUIREMENT |eta|>2.5
                temp1.SetPtEtaPhiM(Jet_PT[i],Jet_Eta[i],Jet_Phi[i],Jet_Mass[i]);
                vBjet.at(k) = temp1;
                //cout<<"Bjet number "<< k <<" with Pt = "<< vBjet.at(k).Pt()<<endl;
                k++;
            }
            
            h_PT_jets->Fill(Jet_PT[i],weight);
            
        }
        
        //cout<<"Bjet number passing cuts   "<< k <<endl;
        if (k<4) {
          //cout<< "Not enough b jets!      "<<endl;
          continue;
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
        
        
        
        if (_verbose) std::cout<< "****************" << endl;
        
        
        
        int first=0; //take the first b jet and make all the possible couples
        for(int second=1;second<4; second++){
            vjetTemp1 = vBjet.at(first) + vBjet.at(second);
            invMass1 = vjetTemp1.M();
            if (_verbose) cout<< "Invariant Mass 1 =  "<< invMass1 << endl;
            vjetTemp2.SetPtEtaPhiM(0.,0.,0.,0.); // resetting
            for(int left=1; left<4; left++){
                if(left!= second){
                    vjetTemp2 += vBjet.at(left);
                }
            }
            invMass2 = vjetTemp2.M();
            if (_verbose) cout<< "Invariant Mass 2 =  "<< invMass2 << endl;
            
            diffNew = abs(invMass1 - invMass2);
            
            if(diffNew < diffOld){
                diffOld = diffNew;
                bestSecond = second;
            }
            
        }
          
        std::vector<TLorentzVector> couple1Bjets;
        std::vector<TLorentzVector> couple2Bjets;
        couple1Bjets.resize(2);
        couple2Bjets.resize(2);

        if (_verbose) cout<< "  Best Second = "<< bestSecond << endl;
        couple1 = vBjet.at(first) + vBjet.at(bestSecond);
        couple1Bjets.at(0) = vBjet.at(first);
        couple1Bjets.at(1) = vBjet.at(bestSecond);
        if (_verbose) cout<< "  Best Invariant Mass 1 =  "<< couple1.M() << endl;
        
        int index = 0;
        for(int left=0; left<4; left++){
            if(left != first && left!= bestSecond){
                couple2 += vBjet.at(left);
                couple2Bjets.at(index) = vBjet.at(left);
                index++;
            }
        }
        if (_verbose) cout<< "  Best Invariant Mass 2 =  "<< couple2.M() << endl;

        // Ordering
        TLorentzVector temp_new;
        std::vector<TLorentzVector> temp_v;
        if(couple2.M() > couple1.M()){
            temp_new=couple1;
            couple1=couple2;
            couple2=temp_new;

            temp_v = couple1Bjets;
            couple1Bjets = couple2Bjets;
            couple2Bjets = temp_v;
        }

        if (_verbose) cout<< "    Best Invariant Mass 1 =  "<< couple1.M() << endl;
        if (_verbose) cout<< "    Best Invariant Mass 2 =  "<< couple2.M() << endl;

        h_lead_inv_mass->Fill(couple1.M(),weight);
        h_sub_inv_mass->Fill(couple2.M(),weight);
        h_diHiggs_mass->Fill((couple1+couple2).M(),weight);
        h_diHiggs_pT->Fill((couple1+couple2).Pt(),weight);  
 
        if((abs(couple1.M()-125) < 40) && (abs(couple2.M()-125) < 40)){
            h_lead_inv_mass_cut->Fill(couple1.M(),weight);
            h_sub_inv_mass_cut->Fill(couple2.M(),weight);
            h_diHiggs_mass_cut->Fill((couple1+couple2).M(),weight);
            h_diHiggs_pT_cut->Fill((couple1+couple2).Pt(),weight);
	  
            h_lead_Eta->Fill(couple1.Eta(),weight);
            h_sub_Eta->Fill(couple2.Eta(),weight);
            h_lead_Phi->Fill(couple1.Phi(),weight);
            h_sub_Phi->Fill(couple2.Phi(),weight);
            h_lead_E->Fill(couple1.E(),weight);
            h_sub_E->Fill(couple2.E(),weight);

            double deltaEta = abs( (couple1Bjets.at(0)).Eta() - (couple1Bjets.at(1)).Eta() );
            h_deltaEta1->Fill(deltaEta,weight);
            deltaEta = abs( (couple2Bjets.at(0)).Eta() - (couple2Bjets.at(1)).Eta() );
            h_deltaEta2->Fill(deltaEta,weight);

            double deltaPhi = couple1Bjets.at(0).DeltaPhi( couple1Bjets.at(1) );
            h_deltaPhi1->Fill(deltaPhi,weight);
            deltaPhi = couple2Bjets.at(0).DeltaPhi( couple2Bjets.at(1) );
            h_deltaPhi2->Fill(deltaPhi,weight);


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
    h_diHiggs_mass->Write();
    h_diHiggs_pT->Write();
    h_diHiggs_mass_cut->Write();
    h_diHiggs_pT_cut->Write();
    h_deltaEta1->Write();
    h_deltaEta2->Write();
    h_deltaPhi1->Write();
    h_deltaPhi2->Write();
    h_lead_Eta->Write();
    h_sub_Eta->Write();
    h_lead_Phi->Write();
    h_sub_Phi->Write();
    h_lead_E->Write();
    h_sub_E->Write();

    /*
    TCanvas *c1 = new TCanvas("c1");
    h_number_jets->Draw();
    c1->SaveAs("Plots/Number_Jets.pdf");
    TCanvas *c2 = new TCanvas("c2");
    h_number_Bjets->Draw();
    c2->SaveAs("Plots/Number_bJets.pdf");
    TCanvas *c3 = new TCanvas("c3");
    h_PT_jets->Draw();
    c3->SaveAs("Plots/Pt_Jets.pdf");
    TCanvas *c4 = new TCanvas("c4");
    h_PT_Bjets->Draw();
    c4->SaveAs("Plots/Pt_bJets.pdf");
    TCanvas *c5 = new TCanvas("c5");
    h_Eta_Bjets->Draw();
    c5->SaveAs("Plots/Eta_bJets.pdf");
    TCanvas *c6 = new TCanvas("c6");
    h_lead_inv_mass->Draw();
    c6->SaveAs("Plots/Lead_invMass.pdf");
    TCanvas *c7 = new TCanvas("c7");
    h_sub_inv_mass->Draw();
    c7->SaveAs("Plots/Sub_invMass.pdf");
    TCanvas *c8 = new TCanvas("c8");
    h_lead_inv_mass_cut->Draw();
    c8->SaveAs("Plots/Lead_invMass_cut.pdf");
    TCanvas *c9 = new TCanvas("c9");
    h_sub_inv_mass_cut->Draw();
    c9->SaveAs("Plots/Sub_invMass_cut.pdf");
    TCanvas *c10 = new TCanvas("c10");
    h_diHiggs_mass->Draw();
    c10->SaveAs("Plots/diHiggs_mass.pdf");
    TCanvas *c11 = new TCanvas("c11");
    h_diHiggs_pT->Draw();
    c11->SaveAs("Plots/diHiggs_Pt.pdf");
*/
     //c->SaveAs("Plots/Number_Jets.pdf");
}


//double DeltaR=0;
//DeltaR=sqrt((Jet_DeltaEta[i]*Jet_DeltaEta[i])+(Jet_DeltaPhi[i]*Jet_DeltaPhi[i]));
//hDeltaR->Fill(DeltaR);




