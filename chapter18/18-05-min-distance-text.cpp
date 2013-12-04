int minDistance(vector<string> &words, string w1, string w2)
{
    int pos1 = -words.size();
    int pos2 = -words.size();
    int minD = words.size();

    for(int i = 0; i < words.size(); ++i)
    {
	if(words[i] == w1)
	{
	    pos1 = i;
	    minD = min(minD, abs(pos1-pos2));
	}
	else if(words[i] == w2)
	{
	    pos2 = i;
	    minD = min(minD, abs(pos1-pos2));
	}
    }
    return minD;
}
	    
