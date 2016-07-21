#include <iostream>
#include <vector>
#include <string>

using namespace std;
static enum candidName {Johnson, Miller, Duffy, Robinson, Sam};

class candidateInfo
{
public:
	void print() const;
	candidateInfo(string NameInput ="", int vote = 0, double votePer = 0.0);
	void setName(string name);
	void getVoted();
	void votePerCal(int sum);


private:
	string lastName;
	int VoteNm;
	double Percentage;
};

void candidateInfo::print() const
{
	cout << lastName << VoteNm << Percentage << endl;	
}

void candidateInfo::setName(string name)
{
	lastName = name;
}

void candidateInfo::getVoted()
{
	VoteNm++;
}

void candidateInfo::votePerCal(int sum)
{
	Percentage = VoteNm / sum;
}


candidateInfo::candidateInfo(string NameInput, int vote, double votePer)
{
	lastName = NameInput;
	VoteNm = vote;
	Percentage = votePer;
}


int main()
{
	vector<candidateInfo> Candidate;
	for(int i = 0; i < 5; i++){
		candidateInfo candTemp;
		string name;
		cin >> name;
		candTemp.setName(name);
		Candidate.push_back(candTemp);
	}
	int sum = 0;
	string VoteName; // cannot switch string
	while(cin >> VoteName)
	{
		switch (VoteName)
		{
			case "Johnson":
				sum++;
				Candidate[0].getVoted;
				break;
			case "Miller":
				sum++;
				Candidate[1].getVoted;
				break;
			case "Duffy":
				sum++;
				Candidate[2].getVoted;
				break;
			case "Robinson":
				sum++;
				Candidate[3].getVoted;
				break;			
			case "Sam":
				sum++;
				Candidate[4].getVoted;
				break;	

			default:
				cout << "Invalid Vote" << endl;		

		}
	}

	for(int i = 0; i < 5; i++)
	{
		Candidate[i].votePerCal(sum);
		Candidate[i].print();
	}



	return 0;
}