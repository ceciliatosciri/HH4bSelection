void compileAndLoadLibs(){

  gROOT->ProcessLine(".L AnaTree.C+");

  //const char* path = "/Users/ceciliamac/AMVA4NP/selection/HH4bSelection";
  const char* path = ".";
  if ( path ) {
    TString libs = gSystem->GetDynamicPath();
    libs += ":";
    libs += path;
    //libs += "/lib";
    gSystem->SetDynamicPath(libs.Data());
    gSystem->Load("AnaTree_C.so");
    std::cout << "Libraries loaded." << std::endl;
  }
}
