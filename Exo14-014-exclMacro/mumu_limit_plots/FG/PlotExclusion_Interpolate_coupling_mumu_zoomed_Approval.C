{
  const int nm = 16;

  float mass[nm] = {40, 50, 60, 70, 80, 90, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500};
  float k_factor = 1.34;
  float xsec_alp[] = {1516, 1071.1, 607.7, 211.96, 19.07, 7.1047, 3.5618, 1.0767, 0.4594, 0.23266, 0.13127, 0.050928, 0.023214, 0.011705, 0.006332, 0.002154};
  
  float obs[nm] = {0.0425758, 0.0370795, 0.0509001, 0.111657, 0.0262207, 0.0488669,
                   0.011495, 0.00263166, 0.00212999, 0.00260005, 0.00221507,
                   0.00140472, 0.00125629, 0.00118361, 0.00128623, 0.00152084};
    
  float exp[nm] = {0.0574156, 0.0529912, 0.0694351, 0.175697, 0.0380223, 0.0555941,
		     0.0123044, 0.00419174, 0.00276877, 0.00225111, 0.00191277,
		     0.00132662, 0.00124522, 0.0011111, 0.0012705, 0.00143492};

  float p1S[nm] = {0.0873233, 0.0730822, 0.105089, 0.232616, 0.0479085, 0.076958,
                   0.0193498, 0.00462206, 0.00424861, 0.00325382, 0.00271549,
                   0.00187669, 0.0016602, 0.00156041, 0.00163533, 0.0020867};
    
    
  float m1S[nm] = {0.040251, 0.0359697, 0.044595, 0.104949, 0.0251386, 0.040716,
                   0.00951784, 0.00269897, 0.00199687, 0.00183899, 0.00140972,
                   0.00123422, 0.00111617, 0.000920956, 0.000987849, 0.00119638};
    
    
  float p2S[nm] = {0.164343, 0.0899535, 0.12442, 0.419172, 0.144857, 0.093306,
                   0.0244502, 0.00507172, 0.00464795, 0.00475965, 0.00371919,
                   0.00259428, 0.00243516, 0.00225293, 0.00223918, 0.00327969};
    
    
  float m2S[nm] = {0.0324258, 0.0330795, 0.0340581, 0.0829364, 0.0215484, 0.0381749,
                   0.00483788, 0.00206366, 0.00169605, 0.00157888, 0.00113904,
                   0.0009846, 0.00103676, 0.000757916, 0.000918716, 0.00115532};


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
    
  float OLD_CMSobs[15] = {0.002703, 0.01808, 0.03666, 0.06054, 0.09939, 0.06648, 0.04613, 0.04407, 0.04664, 0.05104, 0.08201, 0.1314, 0.2024, 0.2873, 0.4004};
  float OLD_CMSmass[15] = {50,70,75,80,85,90,95,100,105,110,130,150,170,190,210};



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
  graphs[10] = new TGraph(15, OLD_CMSmass, OLD_CMSobs);
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
  graphs[10]->SetLineStyle(10);
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
  frame->GetXaxis()->SetTitle("m_{N} (GeV/c^{2})");
  frame->GetXaxis()->SetTitleSize(0.05);
  frame->GetXaxis()->SetTitleOffset(1.05);
  //frame->GetXaxis()->SetTickLength(0.02);
  //frame->GetXaxis()->SetLabelSize(0.04);
  frame->GetXaxis()->SetRangeUser(40, 200);

  frame->GetYaxis()->SetTitle("#||{V_{#muN}}^{2}");

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
  graphs[10]->Draw("same");


  TLegend* leg = new TLegend(0.6, .20, .90, 0.5);
  leg->AddEntry("expected", "CL_{s} Expected", "l");
  leg->AddEntry(graphs[11], "CL_{s} Expected  #pm1#sigma", "f");
  leg->AddEntry(graphs[12], "CL_{s} Expected  #pm2#sigma", "f");
  leg->AddEntry("observed", "CL_{s} Observed", "l");
  leg->AddEntry("L3", "L3", "l");leg->AddEntry("DELPHI", "DELPHI", "l");
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
 // c1->GetFrame()->Draw();
  
  c1->SaveAs("excl_limit_zoomed_mm.pdf");
}
