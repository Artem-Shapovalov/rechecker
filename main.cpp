#include <cstdio>
#include <string>
#include <list>
#include <regex>

bool help_needed(int argc, char** argv);
std::string get_regex(int argc, char** argv);
std::list<std::string> get_samples(int argc, char** argv);

int main(int argc, char** argv)
{
	if (help_needed(argc, argv))
	{
		std::printf(
		"C++ regex checker.\n"
		"Prints the results of the regex_match.\n"
		"Usage: rechecker --regex <your regex> <sample list>\n"
		"	--regex - specifies regex to check the list\n"
		"	--help  - prints this help\n"
		);
		return 0;
	}

	std::string regex = get_regex(argc, argv);

	if (regex == "")
	{
		std::printf(
		"Specify regex to process. Type rechecker --help to get help\n"
		);
	}

	std::list<std::string> samples = get_samples(argc, argv);
	if (samples.size() == 0)
	{
		std::printf(
		"Specify samples to check. Type rechecker --help to get help\n"
		);
	}
	
	std::regex re(regex);
	std::smatch match;

	for (std::string sample : samples)
	{
		bool matches = std::regex_match(sample, match, re);
		std::printf("\"%s\" %s \"%s\"\n",
			sample.c_str(),
			matches ? "match" : "not match",
			regex.c_str());

		for (size_t i = 0; i < match.size(); i++)
		{
			std::printf("	%s\n", match[i].str().c_str());
		}
	}

	return 0;
}

bool help_needed(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (std::string("--help") == argv[i])
		{
			return true;
		}
	}

	return false;
}

std::string get_regex(int argc, char** argv)
{
	for (int i = 1; i < argc; i++)
	{
		if (std::string("--regex") != argv[i]) { continue; }
		if (i + 1 >= argc) { continue; }

		return argv[i + 1];
	}

	return "";
}

std::list<std::string> get_samples(int argc, char** argv)
{
	std::list<std::string> res;

	for (int i = 1; i < argc; i++)
	{
		if (std::string("--regex") == argv[i]) { i++; continue; }
		if (std::string("--help") == argv[i]) { continue; }
		res.push_back(argv[i]);
	}

	return res;
}
