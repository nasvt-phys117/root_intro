void print_histos_2()
{
	
	//TFile *ff = new TFile("histograms.root");
	TFile ff("histograms.root");
	// Get size i.e. get number of histograms
	int num_of_hists = ff.GetListOfKeys()->GetSize();

	// const char hists_array[num_of_hists];
	int i = 0;
	TCanvas *c = new TCanvas("c_test","c_test", 1800,600);
	c->Divide(num_of_hists, 1);
	TH1F *hh[num_of_hists];
	//const char hist_names[num_of_hists];

	for (TKey *key : ROOT::RangeStaticCast<TKey *>(*ff.GetListOfKeys()))
	{

		// std::cout << "key: " << key->GetName()
		//           << " points to an object of class: "
		//           << key->GetClassName() << std::endl;
		hh[i] = (TH1F *)ff.Get(key->GetName());
		c->cd(i+1);
		hh[i]->Draw();
        hh[i]->SetDirectory(0);
		//gPad->Update();
		i++;
	}
}
