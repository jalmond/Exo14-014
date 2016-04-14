{
  const int nm = 16;

  float mass[nm] = {40, 50, 60, 70, 80, 90, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500};
  float k_factor = 1.34;
  float xsec_alp[] = {1516, 1071.1, 607.7, 211.96, 19.07, 7.1047, 3.5618, 1.0767, 0.4594, 0.23266, 0.13127, 0.050928, 0.023214, 0.011705, 0.006332, 0.002154};

    
   
  float obs[nm] = {0.310856,0.228104,0.268764, 0.682266, 0.187104, 0.209065, 0.0521459, 0.0113648, 0.00491012, 0.00354478, 0.00278916, 0.00285184, 0.00252027, 0.00218728, 0.00201853, 0.00208477};
  
  
  float exp[nm] = {0.238636,0.171337,0.204524,0.525581,0.142802,0.15618,0.0365141,0.0110612,0.00617064,0.004475,0.00355606,0.00283105,0.00215555,0.00175336,0.00163501,0.00168907};
    
    
  float p1S[nm] = {0.351235, 0.254329, 0.311327, 0.797278, 0.207615, 0.232433, 0.0489471, 0.0167304, 0.00871603, 0.00588117, 0.00465335, 0.00414719, 0.00278791, 0.00236526, 0.00220359, 0.00227115};  
    
    
  float m1S[nm] = {0.198298, 0.145121,0.173572, 0.443052, 0.116957, 0.105343, 0.0287721, 0.00832365, 0.00464498, 0.00332421, 0.00258657, 0.00257497, 0.00164678, 0.00142935, 0.00133835, 0.00138197};
    
    
  float p2S[nm] = {0.52182, 0.385037, 0.465911, 1.15785, 0.311401, 0.295761, 0.0712261, 0.0210579, 0.0109819, 0.00779671, 0.00577657, 0.005464, 0.0038253, 0.00317962, 0.00295901, 0.0030123};
    
    
  float m2S[nm] = {0.187065, 0.138635, 0.163049, 0.418694, 0.110359, 0.0801969, 0.0217563, 0.00611633, 0.0039473, 0.00286164, 0.00205851, 0.00198529, 0.00145948, 0.00123243, 0.00115459, 0.00119434};

  for(int i=0;i<nm;i++) {
    exp[i] /= (xsec_alp[i]*k_factor);
    obs[i] /= (xsec_alp[i]*k_factor);
    cout << "obs limit at " << mass[i] << " is " << obs[i]<<endl;
    cout << "exp limit at " << mass[i] << " is " << exp[i]<<endl;
    p1S[i] /= (xsec_alp[i]*k_factor);
    m1S[i] /= (xsec_alp[i]*k_factor);
    p2S[i] /= (xsec_alp[i]*k_factor);
    m2S[i] /= (xsec_alp[i]*k_factor);
  }

  float L3[2][38];
  float DEL[2][39];
  float ATLAS[2][12];
  float CMS[2][8];
 
  L3[0][0]  = 20.75; L3[1][0]  = 1.53e-4;
  L3[0][1]  = 23.75; L3[1][1]  = 1.56e-4;
  L3[0][2]  = 26.37; L3[1][2]  = 1.59e-4;
  L3[0][3]  = 29.30; L3[1][3]  = 1.64e-4;
  L3[0][4]  = 32.54; L3[1][4]  = 1.69e-4;
  L3[0][5]  = 35.61; L3[1][5]  = 1.75e-4;
  L3[0][6]  = 39.55; L3[1][6]  = 1.84e-4;
  L3[0][7]  = 43.61; L3[1][7]  = 1.98e-4;
  L3[0][8]  = 48.45; L3[1][8]  = 2.20e-4;
  L3[0][9]  = 52.23; L3[1][9]  = 2.44e-4;
  L3[0][10] = 55.90; L3[1][10] = 2.76e-4;
  L3[0][11] = 59.82; L3[1][11] = 3.13e-4;
  L3[0][12] = 62.12; L3[1][12] = 3.50e-4;
  L3[0][13] = 64.03; L3[1][13] = 4.02e-4;
  L3[0][14] = 66.49; L3[1][14] = 4.56e-4;
  L3[0][15] = 69.05; L3[1][15] = 5.28e-4;
  L3[0][16] = 71.19; L3[1][16] = 6.49e-4;
  L3[0][17] = 72.28; L3[1][17] = 7.25e-4;
  L3[0][18] = 74.51; L3[1][18] = 8.78e-4;
  L3[0][19] = 76.24; L3[1][19] = 1.06e-3;
  L3[0][20] = 78.02; L3[1][20] = 1.35e-3;
  L3[0][21] = 79.20; L3[1][21] = 1.63e-3;
  L3[0][22] = 80.46; L3[1][22] = 2.03e-3;
  L3[0][23] = 81.71; L3[1][23] = 2.46e-3;
  L3[0][24] = 83.00; L3[1][24] = 3.23e-3;
  L3[0][25] = 84.30; L3[1][25] = 4.18e-3;
  L3[0][26] = 84.98; L3[1][26] = 5.49e-3;
  L3[0][27] = 85.67; L3[1][27] = 6.95e-3;
  L3[0][28] = 86.36; L3[1][28] = 8.80e-3;
  L3[0][29] = 87.40; L3[1][29] = 1.23e-2;
  L3[0][30] = 88.44; L3[1][30] = 1.62e-2;
  L3[0][31] = 89.17; L3[1][31] = 2.28e-2;
  L3[0][32] = 89.90; L3[1][32] = 3.03e-2;
  L3[0][33] = 90.20; L3[1][33] = 3.76e-2;
  L3[0][34] = 90.68; L3[1][34] = 4.75e-2;
  L3[0][35] = 90.72; L3[1][35] = 6.38e-2;
  L3[0][36] = 90.78; L3[1][36] = 8.69e-2;
  L3[0][37] = 90.81; L3[1][37] = 9.93e-2;

  DEL[0][0] = 10.1; DEL[1][0]   = 1.79e-5;
  DEL[0][1] = 11.2; DEL[1][1]   = 1.82e-5;
  DEL[0][2] = 12.7; DEL[1][2]   = 1.85e-5;
  DEL[0][3] = 15.1; DEL[1][3]   = 1.91e-5;
  DEL[0][4] = 17.8; DEL[1][4]   = 2.01e-5;
  DEL[0][5] = 19.8; DEL[1][5]   = 2.08e-5;
  DEL[0][6] = 21.8; DEL[1][6]   = 2.19e-5;
  DEL[0][7] = 23.5; DEL[1][7]   = 2.26e-5;
  DEL[0][8] = 25.5; DEL[1][8]   = 2.30e-5;
  DEL[0][9] = 27.4; DEL[1][9]   = 2.34e-5;
  DEL[0][10] = 29.6; DEL[1][10] = 2.37e-5;
  DEL[0][11] = 33.0; DEL[1][11] = 2.37e-5;
  DEL[0][12] = 36.0; DEL[1][12] = 2.41e-5;
  DEL[0][13] = 40.3; DEL[1][13] = 2.45e-5;
  DEL[0][14] = 44.5; DEL[1][14] = 2.53e-5;
  DEL[0][15] = 47.2; DEL[1][15] = 2.76e-5;
  DEL[0][16] = 50.7; DEL[1][16] = 3.05e-5;
  DEL[0][17] = 53.6; DEL[1][17] = 3.49e-5;
  DEL[0][18] = 56.0; DEL[1][18] = 4.07e-5;
  DEL[0][19] = 57.8; DEL[1][19] = 4.58e-5;
  DEL[0][20] = 59.4; DEL[1][20] = 5.25e-5;
  DEL[0][21] = 61.1; DEL[1][21] = 6.12e-5;
  DEL[0][22] = 62.8; DEL[1][22] = 7.25e-5;
  DEL[0][23] = 64.1; DEL[1][23] = 8.60e-5;
  DEL[0][24] = 65.6; DEL[1][24] = 1.00e-4;
  DEL[0][25] = 66.7; DEL[1][25] = 1.19e-4;
  DEL[0][26] = 67.8; DEL[1][26] = 1.41e-4;
  DEL[0][27] = 69.6; DEL[1][27] = 1.85e-4;
  DEL[0][28] = 70.8; DEL[1][28] = 2.30e-4;
  DEL[0][29] = 72.0; DEL[1][29] = 3.03e-4;
  DEL[0][30] = 73.2; DEL[1][30] = 3.84e-4;
  DEL[0][31] = 74.0; DEL[1][31] = 4.63e-4;
  DEL[0][32] = 75.2; DEL[1][32] = 5.77e-4;
  DEL[0][33] = 76.5; DEL[1][33] = 7.58e-4;
  DEL[0][34] = 76.9; DEL[1][34] = 8.98e-4;
  DEL[0][35] = 77.8; DEL[1][35] = 1.12e-3;
  DEL[0][36] = 78.2; DEL[1][36] = 1.33e-3;
  DEL[0][37] = 79.1; DEL[1][37] = 1.66e-3;
  DEL[0][38] = 79.9; DEL[1][38] = 2.03e-3;
  //  DEL[0][39] = 90.0; DEL[1][39] = 1000;
  
  ATLAS[0][0] = 100; ATLAS[1][0]   = 3.5e-3;
  ATLAS[0][1] = 110; ATLAS[1][1]   = 2.8e-3;
  ATLAS[0][2] = 120; ATLAS[1][2]   = 3.0e-3;
  ATLAS[0][3] = 140; ATLAS[1][3]   = 5.1e-3;
  ATLAS[0][4] = 160; ATLAS[1][4]   = 6.9e-3;
  ATLAS[0][5] = 180; ATLAS[1][5]   = 1.0e-2;
  ATLAS[0][6] = 200; ATLAS[1][6]   = 1.7e-2;
  ATLAS[0][7] = 240; ATLAS[1][7]   = 2.6e-2;
  ATLAS[0][8] = 280; ATLAS[1][8]   = 4.2e-2;
  ATLAS[0][9] = 300; ATLAS[1][9]   = 5.1e-2;
  ATLAS[0][10] = 400; ATLAS[1][10]   = 1.7e-1;
  ATLAS[0][11] = 500; ATLAS[1][11]   = 4.0e-1;
    
    CMS[0][0] = 50.; CMS[1][0] =0.0055;
    CMS[0][1] = 60.; CMS[1][1] =0.011;
    CMS[0][2] = 70.; CMS[1][2] =0.032;
    CMS[0][3] = 80.; CMS[1][3] =0.1;
    CMS[0][4] = 90.; CMS[1][4] =0.21;
    CMS[0][5] = 100.; CMS[1][5] =0.13;
    CMS[0][6] = 150.; CMS[1][6] =0.3;
    CMS[0][7] = 200.; CMS[1][7] =0.8;


  TGraph* graphs[14];
  graphs[0] = new TGraph(nm, mass, exp);
  graphs[1] = new TGraph(nm, mass, obs);
  graphs[2] = new TGraph(nm, mass, p1S);
  graphs[3] = new TGraph(nm, mass, m1S);
  graphs[4] = new TGraph(nm, mass, p2S);
  graphs[5] = new TGraph(nm, mass, m2S);
  graphs[7] = new TGraph(38, L3[0], L3[1]);
  graphs[8] = new TGraph(39, DEL[0], DEL[1]);
  graphs[9] = new TGraph(12, ATLAS[0], ATLAS[1]);
  graphs[10] = new TGraph(8, CMS[0], CMS[1]);
  graphs[11] = new TGraph(2*nm);
  graphs[12] = new TGraph(2*nm);

  for (int i=0; i!=nm; ++i){
    graphs[11]->SetPoint(i, mass[i], p1S[i]);
    graphs[11]->SetPoint(i+nm, mass[nm-i-1], m1S[nm-i-1]);
    graphs[12]->SetPoint(i, mass[i], p2S[i]);
    graphs[12]->SetPoint(i+nm, mass[nm-i-1], m2S[nm-i-1]);
  }

  graphs[0]->SetNameTitle("expected", "expected");
  graphs[1]->SetNameTitle("observed", "observed");
  graphs[2]->SetNameTitle("+1 Sigma", "+1 Sigma");
  graphs[3]->SetNameTitle("-1 Sigma", "-1 Sigma");
  graphs[4]->SetNameTitle("+2 Sigma", "+2 Sigma");
  graphs[5]->SetNameTitle("-2 Sigma", "-2 Sigma");
  graphs[7]->SetNameTitle("L3", "L3");
  graphs[8]->SetNameTitle("DELPHI", "DELPHI");
  graphs[9]->SetNameTitle("ATLAS", "ATLAS");
  graphs[10]->SetNameTitle("CMS 7 TeV", "CMS 7 TeV");
    
  TColor::CreateColorWheel();
  graphs[0]->SetLineColor(kBlack);
  graphs[0]->SetLineStyle(9);
  graphs[1]->SetLineColor(kBlack);
  graphs[1]->SetMarkerStyle(20);
  graphs[1]->SetMarkerSize(1);
  graphs[1]->SetMarkerColor(kBlack);
  graphs[2]->SetLineColor(kGreen);
  graphs[3]->SetLineColor(kGreen);
  graphs[4]->SetLineColor(kYellow);
  graphs[5]->SetLineColor(kYellow);
  graphs[7]->SetLineColor(kBlue);
  graphs[7]->SetLineStyle(3);
  graphs[8]->SetLineColor(kPink);
  graphs[8]->SetLineStyle(6);
  graphs[9]->SetLineColor(kAzure);
  graphs[10]->SetLineColor(kViolet-6);
  graphs[10]->SetLineStyle(7);
  graphs[11]->SetLineColor(kGreen);
  graphs[12]->SetLineColor(kYellow);

  graphs[0]->SetLineWidth(2);
  graphs[1]->SetLineWidth(2);
  graphs[7]->SetLineWidth(2);
  graphs[8]->SetLineWidth(2);
  graphs[9]->SetLineWidth(2);
  graphs[10]->SetLineWidth(2);
    
  graphs[0]->SetFillColor(kWhite);
  graphs[1]->SetFillColor(kWhite);
  graphs[7]->SetFillColor(kWhite);
  graphs[8]->SetFillColor(kWhite);
  graphs[2]->SetFillColor(kWhite);
  graphs[3]->SetFillColor(kWhite);
  graphs[4]->SetFillColor(kWhite);
  graphs[5]->SetFillColor(kWhite);
  graphs[11]->SetFillColor(kGreen);
  graphs[12]->SetFillColor(kYellow);
    
  int W = 800;
  int H = 600;
  TCanvas* c1 = new TCanvas("c1", "c1",10,10,W,H);
  int H_ref = 600;
  int W_ref = 800;
    
  // references for T, B, L, R
  float T = 0.08*H_ref;
  float B = 0.15*H_ref;
  float L = 0.17*W_ref;
  float R = 0.04*W_ref;
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetFrameFillStyle(0);
  c1->SetFrameBorderMode(0);
  c1->SetLeftMargin( L/W );
  c1->SetRightMargin( R/W );
  c1->SetTopMargin( T/H );
  c1->SetBottomMargin( B/H );
  //  c1->SetGridx();
  //c1->SetGridy();
  c1->SetTickx(1);
  c1->SetTicky(1);
    
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();
    
  gROOT->LoadMacro("CMS_lumi.C");
 // CMS_lumi( c1, 2, 0 );


  TH1 *frame = new TH1F("frame","",1000,40,600);
  frame->SetMinimum(1e-5);
  frame->SetMaximum(10);
  frame->SetDirectory(0);
  frame->SetStats(0);
  frame->GetXaxis()->SetTitle("m_{N} (GeV)");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(1.05);
  //frame->GetXaxis()->SetTickLength(0.02);
  //frame->GetXaxis()->SetLabelSize(0.04);
  frame->GetXaxis()->SetRangeUser(40, 200);
  frame->GetYaxis()->SetTitle("#||{V_{eN}}^{2}");
  frame->GetYaxis()->SetTitleSize(0.05);
  //frame->GetYaxis()->SetTitleOffset(0.95);
  //frame->GetYaxis()->SetLabelSize(0.04);
  frame->GetYaxis()->SetRangeUser(0.00001,1.0);
  frame->Draw(" ");
  c1->SetLogy();

  graphs[4]->Draw("same");
  graphs[5]->Draw("same");
  graphs[12]->Draw("fsame");
  graphs[2]->Draw("same");
  graphs[3]->Draw("same");
  graphs[11]->Draw("fsame");
  graphs[0]->Draw("same");
  graphs[1]->Draw("plsame");
  graphs[7]->Draw("same");
  graphs[8]->Draw("same");
  //  graphs[9]->Draw("same");                                                                                                                                      
  graphs[10]->Draw("same");

  TLegend* leg = new TLegend(0.6, .20, .90, 0.5);
  leg->AddEntry("expected", "CL_{s} Expected", "l");
  leg->AddEntry(graphs[11], "CL_{s} Expected  #pm1#sigma", "f");
  leg->AddEntry(graphs[12], "CL_{s} Expected  #pm2#sigma", "f");
  leg->AddEntry("observed", "CL_{s} Observed", "l");
  leg->AddEntry("L3", "L3", "l");
  leg->AddEntry("DELPHI", "DELPHI", "l");
  // leg->AddEntry("ATLAS", "ATLAS", "l");                                                                                                                        
  leg->AddEntry("CMS 7 TeV", "CMS 7 TeV", "l");
  leg->SetFillColor(kWhite);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.03);
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);

  
  leg->Draw();
  //TLatex title(70, 3, "#font[41]{CMS 2012 #sqrt{s} = 8 TeV #it{Ldt} = 19.7 fb^{-1}}");
  //title.Draw();
  CMS_lumi( c1, 2, 11 );
  c1->Update();
  c1->RedrawAxis();
  c1->SaveAs("exclusion_ee_zoom.pdf");
 // c1->GetFrame()->Draw();

}
