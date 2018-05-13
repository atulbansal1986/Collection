#include <bits/stdc++.h>

using namespace std;

constexpr double p = 0.51;

constexpr size_t ITER = 1e7;

constexpr size_t MOD = 1e6;

struct iBetter
{
	double wealth{100.0};
	virtual void process(bool success)
	{
		double bet_amount = this->getBetAmount();
		if (success)
			wealth += bet_amount;
		else
			wealth -= bet_amount;	

		if (wealth < 0.0)
			wealth = 0;
	}
	virtual double getBetAmount() = 0;
	virtual string name() = 0;
};


struct KellyBetter : public iBetter
{
	double getBetAmount() override
	{
		return wealth * (2*p -1);
	}
	string name() override { return "Kelly"; }
};

struct FixedSizeBetter : public iBetter
{
	double getBetAmount() override
	{
		return min(10.0 , wealth);
	}
	string name() override { return "Fixed"; }
};



int main()
{
	assert(0 <= p && p <= 1.0);
	std::srand(static_cast<uint32_t>(std::time(0)));
	
	std::vector<iBetter*> betters;

	KellyBetter b1; betters.push_back(&b1);
	FixedSizeBetter b2; betters.push_back(&b2);

	for (size_t i=0; i< ITER; ++i)
	{
		size_t random_variable = std::rand() % MOD + 1;
		if (random_variable <= (p * MOD))
		{
			for (auto it : betters)
				it->process(true);
		}
		else
		{
			for (auto it : betters)
				it->process(false);
		}
	}

	for (auto it: betters)
		cout << it->name() << " wealth = " << it->wealth << endl;

	return 0;
}