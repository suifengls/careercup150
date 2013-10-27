bool cmp(string s1, string s2)
{
    return s1.size() > s2.size();
}

bool MakeWords(string word, int length, unordered_set<string> &dict)
{
    if(word.size() == 0)
	return true;
    for(int i = 1; i < word.size(); ++i)
    {
	if(i == length) // find the original word
	    return false;
	string str = word.substr(0, i);
	if(dict.count(str) > 0)
	{
	    if(MakeWords(word.substr(i), length, dict))
		return true;
	}
    }
    return false;
}

string FindWord(string words[], int n, unordered_set<string> &dict)
{
    sort(words, words+n, cmp); // sortting from longest word to shortest word
    for(int i = 0; i < n; ++i)
    {
	if(MakeWords(words[i], words[i].size(); ++i))
	   return words[i];
    }
    return NULL;
}
