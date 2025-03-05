#pragma once
namespace stuff
{
struct Stats
{
	int m_healthPoints;
	int m_Talk;
	int m_Love;
	int m_Party;
	int m_Skill;
};

struct Traits
{
	int m_Sexy;
	int m_Beauty;
	int m_Cute;
	int m_Funny;
};

}

class StatsAndTraits
{
public:
	std::vector<int> m_stats;
	std::vector<int> m_traits;
	std::vector<std::string> m_statNames = { "Talk", "Love", "Party", "Skill" };
	std::vector<std::string> m_traitNames = { "Sexy", "Beauty", "Cute", "Funny" };
};
