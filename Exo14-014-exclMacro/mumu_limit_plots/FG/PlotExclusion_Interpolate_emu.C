{
  const int nm = 16;

  float mass[nm] = {40, 50, 60, 70, 80, 90, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500};
  float k_factor = 1.34;
  float xsec_alp[] = {1516, 1071.1, 607.7, 211.96, 19.07, 7.1047, 3.5618, 1.0767, 0.4594, 0.23266, 0.13127, 0.050928, 0.023214, 0.011705, 0.006332, 0.002154};

  float obs[nm] = {0.123202, 0.101995, 0.125287, 0.258251, 0.0826738, 0.179483, 0.0412158, 0.00913354, 0.00436214, 0.00306767, 0.00250089, 0.00164996, 0.00127597, 0.00123356, 0.00131563, 0.00155301};
  
  
  float exp[nm] = {0.108259, 0.0900631, 0.111571, 0.23304, 0.061659, 0.120314, 0.0319436, 0.00692258, 0.00337134, 0.00230301,0.00168981, 0.00121986, 0.00081592, 0.00080119, 0.000757812, 0.00091941};
      
  float p1S[nm] = {0.148432, 0.124234, 0.151827, 0.306071, 0.0867451, 0.163012, 0.0455286, 0.00948668, 0.00475911, 0.00335595, 0.00254371, 0.00163901, 0.00115981, 0.00106232, 0.00109535, 0.00131511};
    
  float m1S[nm] = {0.0793156, 0.0661083, 0.0805779, 0.164962, 0.0546913, 0.0894428, 0.0253081, 0.00489114, 0.00259169, 0.00193355, 0.00108481, 0.000965242, 0.000599964, 0.000575212, 0.000588913, 0.000706466};
    
  float p2S[nm] = {0.195969, 0.163133, 0.19256, 0.406607, 0.112571, 0.216986, 0.0558666, 0.0127319, 0.00604918, 0.00454807, 0.00321592, 0.00217701, 0.00160765, 0.00153116, 0.00152504, 0.00184514};
  
  float m2S[nm] = {0.0749667, 0.0628797, 0.0761882, 0.153977, 0.0525152, 0.0740002, 0.0173917, 0.00401824, 0.00209572, 0.00133376, 0.00101957, 0.000563282, 0.000532986, 0.000527587, 0.000558357, 0.000672443};

  for(int i=0;i<nm;i++) {
      exp[i] /= (xsec_alp[i]*k_factor);
      obs[i] /= (xsec_alp[i]*k_factor);
      cout << "limit at " << mass[i] << " is " << obs[i]<<endl;
      p1S[i] /= (xsec_alp[i]*k_factor);
      m1S[i] /= (xsec_alp[i]*k_factor);
      p2S[i] /= (xsec_alp[i]*k_factor);
      m2S[i] /= (xsec_alp[i]*k_factor);
  }

  float L3[2][38];
  float DEL[2][39];
  float ATLAS[2][12];
  float CMS[2][8];
 

  TGraph* graphs[14];
  graphs[0] = new TGraph(nm, mass, exp);
  graphs[1] = new TGraph(nm, mass, obs);
  graphs[2] = new TGraph(nm, mass, p1S);
  graphs[3] = new TGraph(nm, mass, m1S);
  graphs[4] = new TGraph(nm, mass, p2S);
  graphs[5] = new TGraph(nm, mass, m2S);
  graphs[7] = new TGraph(2*nm);
  graphs[8] = new TGraph(2*nm);

  for (int i=0; i!=nm; ++i){
    graphs[7]->SetPoint(i, mass[i], p1S[i]);
    graphs[7]->SetPoint(i+nm, mass[nm-i-1], m1S[nm-i-1]);
    graphs[8]->SetPoint(i, mass[i], p2S[i]);
    graphs[8]->SetPoint(i+nm, mass[nm-i-1], m2S[nm-i-1]);
  }

  graphs[0]->SetNameTitle("expected", "expected");
  graphs[1]->SetNameTitle("observed", "observed");
  graphs[2]->SetNameTitle("+1 Sigma", "+1 Sigma");
  graphs[3]->SetNameTitle("-1 Sigma", "-1 Sigma");
  graphs[4]->SetNameTitle("+2 Sigma", "+2 Sigma");
  graphs[5]->SetNameTitle("-2 Sigma", "-2 Sigma");
  
    
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
  graphs[7]->SetLineColor(kGreen);
  graphs[8]->SetLineColor(kYellow);
  
  graphs[0]->SetLineWidth(2);
  graphs[1]->SetLineWidth(2);
    
  graphs[0]->SetFillColor(kWhite);
  graphs[1]->SetFillColor(kWhite);
  graphs[7]->SetFillColor(kGreen);
  graphs[8]->SetFillColor(kYellow);
    
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
  c1->SetTickx(0);
  c1->SetTicky(0);

    
  gROOT->LoadMacro("tdrstyle.C");
  setTDRStyle();
    
  gROOT->LoadMacro("CMS_lumi.C");
 // CMS_lumi( c1, 2, 0 );


  TH1 *frame = new TH1F("frame","",1000,40,600);
  frame->SetMinimum(1e-5);
  frame->SetMaximum(10);
  frame->SetDirectory(0);
  frame->SetStats(0);
  frame->GetXaxis()->SetTitle("m_{N} (GeV)/c^{2}");
  //frame->GetXaxis()->SetTitleSize(0.045);
  frame->GetXaxis()->SetTitleOffset(1.05);
  //frame->GetXaxis()->SetTickLength(0.02);
  //frame->GetXaxis()->SetLabelSize(0.04);
  frame->GetXaxis()->SetRangeUser(40, 500);
  frame->GetYaxis()->SetTitle("#||{V_{eN}}#||{V_{#muN}}");
  //frame->GetYaxis()->SetTitleSize(0.045);
  //frame->GetYaxis()->SetTitleOffset(0.95);
  //frame->GetYaxis()->SetLabelSize(0.04);
  frame->GetYaxis()->SetRangeUser(0.00001,1.0);
  frame->Draw(" ");
  c1->SetLogy();

  graphs[4]->Draw("same");
  graphs[5]->Draw("same");
  graphs[8]->Draw("fsame");
  graphs[2]->Draw("same");
  graphs[3]->Draw("same");
  graphs[7]->Draw("fsame");
  graphs[0]->Draw("same");
  graphs[1]->Draw("plsame");


  TLegend* leg = new TLegend(0.6, .20, .90, 0.45);
  leg->AddEntry("expected", "CL_{s} Expected", "l");
  leg->AddEntry(graphs[7], "CL_{s} Expected #pm1#sigma", "f");
  leg->AddEntry(graphs[8], "CL_{s} Expected #pm2#sigma", "f");
  leg->AddEntry("observed", "CL_{s} Observed", "l");
  leg->SetFillColor(kWhite);
  leg->SetTextFont(42);
  
  leg->Draw();
  //TLatex title(70, 3, "#font[41]{CMS 2012 #sqrt{s} = 8 TeV #it{Ldt} = 19.7 fb^{-1}}");
  //title.Draw();
  CMS_lumi( c1, 2, 11 );
  c1->Update();
  c1->RedrawAxis();
 // c1->GetFrame()->Draw();

}
