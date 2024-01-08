void print_histos()
{
	
	TFile *ff = new TFile("histograms.root"); //Try not to use pointers.

	// Get size i.e. get number of histograms
	int num_of_hists = ff->GetListOfKeys()->GetSize();

	int i = 0;
	TCanvas *c = new TCanvas("c_test","c_test", 1800,600);
	if (num_of_hists > 4 )
	{
		c->Divide(4,num_of_hists/4+1);
	}
	else	c->Divide(num_of_hists, 1);
	TH1F *hh[num_of_hists];

	for (TKey *key : ROOT::RangeStaticCast<TKey *>(*ff->GetListOfKeys()))
	{
		hh[i] = (TH1F *)ff->Get(key->GetName());
		c->cd(i+1);
		hh[i]->Draw();
		i++;
	}
}
